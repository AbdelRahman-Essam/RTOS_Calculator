/*
 * KEYPAD_LCD_PASS.c
 *
 * Created: 3/2020
 *  Author: Ahmed Gamal
 */ 

#define F_CPU 8000000
#define LED		24
#include "avr/io.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "util/delay.h"
#include "lcd_4bit.h"
#include "utils.h"
#include "DIO_int.h"
#include "std_types.h"
#include "KeyPad_int.h"


void vApplicationIdleHook( void );
int toint(char str[]);
void tostring(char str[], int num);
void Task1(void * pvParameters);
void Task2(void * pvParameters);
void Task3(void * pvParameters);
void Task4(void * pvParameters);
void Task5(void * pvParameters);
void LCD_DisplayPattern(void);
void calculator(void);
void LED_Pattern(void * pvParameters);


xTaskHandle handle_task1;	
xTaskHandle handle_task2;
xTaskHandle handle_task3;
xTaskHandle handle_task4;
xTaskHandle handle_task5;
xTaskHandle handle_LED;
xSemaphoreHandle handle_sem1;


int x = 0,res=0;
char pressed_number = 0;
char old_value =255,v=0;
char op =0,c1=0,state=0,t=1,last_op=0;
char num[16];
char result[16];
char num2[16];


int main( void )
{
	lcd_init();
	DDRA = 0xFF;
	DDRD = 0x0F;
	DDRC = 0x01;
	PORTD = 0xFF;
	xTaskCreate( Task1, "Task1_Name", 100, NULL, 1, &handle_task1);
	xTaskCreate( Task2, "Task2_Name", 100, NULL, 1, &handle_task2);
	xTaskCreate( Task3, "Task3_Name", 100, NULL, 1, &handle_task3);
	xTaskCreate( Task4, "Task4_Name", 100, NULL, 1, &handle_task4);
	xTaskCreate( Task5, "Task5_Name", 100, NULL, 1, &handle_task5);
	vSemaphoreCreateBinary(handle_sem1);
	vTaskStartScheduler();	
	return 0;
}
void vApplicationIdleHook( void ){
	if(x++ == 1000){
		PORTA ^= 0xFF;
		_delay_ms(500);	
		x = 0;
	}
}
void LED_Pattern(void * pvParameters)
{
	int yled = xTaskGetTickCount();
	while(1)
	{
		vTaskDelayUntil(&yled,25);
		

	}
}
void Task5(void * pvParameters)
{
	int counter =0;
	int y5=xTaskGetTickCount();
	while (1)
	{
		vTaskDelayUntil(&y5,100);
		/*check if key pressed and start timer 
		if key pressed the timer will reset
		and if time == 10 s  it  will make some function
		*/
		counter++;
		if ((pressed_number!=255)|(KeyPad_u8GetPressedKey()!=255))
		{
			counter=0;
		}
		if (counter>=100)
		{//blinking led
			lcd_clrScreen();
			lcd_dispString("NO Pressed");
			DIO_voidSetPin(LED,1);
			PORTC = 0x01;
			xTaskCreate( LED_Pattern, "Task_Name", 100, NULL, 1, &handle_LED);
		}
		
	}
}
void Task1(void * pvParameters)
{
	int y = xTaskGetTickCount();
	while(1)
	{
		vTaskDelayUntil(&y,20);
		//LCD_Display_KP();
		pressed_number = KeyPad_u8GetPressedKey();	
		calculator();
	}			
}
void LCD_Display_KP(void)
{
	
	
		if (pressed_number!=old_value)
		{
			old_value=pressed_number;
			if(pressed_number != 255)
			{
			
			}				
		}
		if (pressed_number==13)
		{
			lcd_clrScreen();
		}
	
}
void Task2(void * pvParameters)
{
	char v[]="Welcome";
	int i=0;
	int y1 = xTaskGetTickCount();
		while(i<3)
		{
		vTaskDelayUntil(&y1,20);
		for (int i1=0;i1<10;i1++)
		{
			lcd_disp_string_xy(v,0,i1);
			_delay_ms(25);
			lcd_clrScreen();
		}
		for (int i2=11;i2>=0;i2--)
		{
			lcd_disp_string_xy(v,0,i2);
			_delay_ms(25);
			lcd_clrScreen();
		}
		i++;
		}
		i=0;
		while(1)
		{
		vTaskDelayUntil(&y1,20);
		lcd_dispString("Press any key");
		lcd_disp_string_xy("to continue",1,0);
		_delay_ms(500);
		lcd_clrScreen();
		_delay_ms(250);
		i++;
		}
		vTaskDelete(handle_task2);
}
void Task3(void * pvParameters)
{
xSemaphoreTake(handle_sem1,portMAX_DELAY);
	while(1)
	{
		xSemaphoreTake(handle_sem1,portMAX_DELAY);
		vTaskDelete(handle_task2);
		vTaskDelete(handle_task3);
		vTaskDelete(handle_task4);
	}
}
void Task4(void * pvParameters)
{
	while(1)
	{
	int p=KeyPad_u8GetPressedKey();
	if (p!=255)
	{
		xSemaphoreGive(handle_sem1);
	}
	}	
}
void calculator(void)
{
	while (t)
	{
		for (int k=0;k<16;k++ )
	{
		num[k]=0;
		result[k]=0;
		num2[k]=0;
	}
	t=0;
	}
		if (pressed_number!=old_value)
		{
			old_value=pressed_number;
			if(pressed_number != 255)
			{
				if ((pressed_number=='+')|(pressed_number=='-')|(pressed_number=='*')|(pressed_number=='%'))
				{
					state=1;
					v=1;
					op=pressed_number;
				}
				else if (pressed_number==13)
				{
					lcd_clrScreen();
					c1=0;
					state=0;
					op=0;
					res=0;
					for (int k=0;k<16;k++ )
					{
						num[k]=0;
						result[k]=0;
						num2[k]=0;
					}
					lcd_displayChar('0');
				}
				if ((pressed_number=='0')|(pressed_number=='1')|(pressed_number=='2')|(pressed_number=='3')|(pressed_number=='4')|(pressed_number=='5')|(pressed_number=='6')|(pressed_number=='7')|(pressed_number=='8')|(pressed_number=='9'))
				{
					if (state==0)
					{
					lcd_displayChar(pressed_number);
					num[c1]=pressed_number;
					c1++;
					}
					else if (state==1)
					{
						if (v)
						{
							c1=0;
							lcd_clrScreen();
							v=0;
						}
					lcd_displayChar(pressed_number);
					num2[c1]=pressed_number;
					c1++;
					}
					

				}
		if (pressed_number=='=')
		{			int m,n=0;
					m=toint(num);
					n=toint(num2);
					switch (op)
					{
						case '+':
						{	
						res=m+n;
						}
						break;
						case '-':
						{
						res=m-n;
						}
						break;
						case '*':
						{
						res=m*n;
						}
						break;	
						case'%':
						{
						res=m/n;
						}												
						break;
					}
			tostring(result,res);
			tostring(num,res);
			lcd_clrScreen();
			lcd_dispString(result);
		}
				
				
				
				
			
			}				
	}
}
void tostring(char str[], int num)
{
    int i, rem, len = 0, n;
 
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}
 
int toint(char str[])
{
    int len = strlen(str);
    int i, num = 0;
 
    for (i = 0; i < len; i++)
    {
        num = num + ((str[len - (i + 1)] - '0') * pow(10, i));
    }
 
   return num;
}