#ifndef DIO_config
#define DIO_config

#define DIO_PIN0_DIR IN
#define DIO_PIN1_DIR OUT
#define DIO_PIN2_DIR OUT
#define DIO_PIN3_DIR OUT
#define DIO_PIN4_DIR OUT
#define DIO_PIN5_DIR IN
#define DIO_PIN6_DIR OUT
#define DIO_PIN7_DIR OUT



#define DIO_PIN8_DIR  OUT
#define DIO_PIN9_DIR  OUT
#define DIO_PIN10_DIR OUT
#define DIO_PIN11_DIR OUT
#define DIO_PIN12_DIR OUT
#define DIO_PIN13_DIR OUT
#define DIO_PIN14_DIR OUT
#define DIO_PIN15_DIR OUT


#define DIO_PIN16_DIR OUT
#define DIO_PIN17_DIR OUT
#define DIO_PIN18_DIR OUT
#define DIO_PIN19_DIR OUT
#define DIO_PIN20_DIR OUT
#define DIO_PIN21_DIR OUT
#define DIO_PIN22_DIR OUT
#define DIO_PIN23_DIR OUT


#define DIO_PIN24_DIR OUT
#define DIO_PIN25_DIR OUT
#define DIO_PIN26_DIR OUT
#define DIO_PIN27_DIR OUT
#define DIO_PIN28_DIR OUT
#define DIO_PIN29_DIR OUT
#define DIO_PIN30_DIR OUT
#define DIO_PIN31_DIR OUT

#define PORTA (*(volatile u8*)(0x3B))
#define PORTB (*(volatile u8*)(0x38))
#define PORTC (*(volatile u8*)(0x35))
#define PORTD (*(volatile u8*)(0x32))

#define DDRA (*(volatile u8*)(0x3A))
#define DDRB (*(volatile u8*)(0x37))
#define DDRC (*(volatile u8*)(0x34))
#define DDRD (*(volatile u8*)(0x31))

#define PINA (*(volatile u8*)(0x39))
#define PINB (*(volatile u8*)(0x36))
#define PINC (*(volatile u8*)(0x33))
#define PIND (*(volatile u8*)(0x30))

#endif
