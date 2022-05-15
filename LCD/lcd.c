#include "lcd.h"

void lcd_cmd(char command)
{
	GPIO_PORTA_DATA_R &= ~0xE0;
	GPIO_PORTB_DATA_R=command;
	GPIO_PORTA_DATA_R|=0x80;
	delay(1,100);
	GPIO_PORTA_DATA_R &= ~0xE0;
}

void lcd_data(char data)
{
	GPIO_PORTA_DATA_R |= 0x20;
	GPIO_PORTB_DATA_R = data;
	GPIO_PORTA_DATA_R|=0x80;
	delay(1,5);
	GPIO_PORTA_DATA_R &= ~0x80;
}

void lcd_init(void)
{
    SYSCTL_RCGCGPIO_R |= 0x03;
	while( (SYSCTL_PRGPIO_R & 0x03) == 0)
	{
	}
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= 0xE0;
	GPIO_PORTA_AFSEL_R = 0;
	GPIO_PORTA_PCTL_R =0;
	GPIO_PORTA_AMSEL_R =0;
	GPIO_PORTA_DEN_R |= 0xE0;
	GPIO_PORTA_DIR_R |= 0xE0;
	
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= 0xFF;
	GPIO_PORTB_DEN_R |= 0xFF;
	GPIO_PORTB_DIR_R |= 0xFF;

	lcd_cmd(0x01);
	delay(1,2);	
	lcd_cmd(0x38);
	lcd_cmd(0x06);
	lcd_cmd(0x0E);
	lcd_cmd(0x0F);
	lcd_cmd(0x30);
}

void lcd_clear(void)
{
	delay(1,100);
	lcd_cmd(0x01);
}

void lcd_secline(void)
{
	delay(1,100);
	lcd_cmd(0xc0);
}

void lcd_display(char *str){
	uint8_t i =0;
	while(str[i] != '\0')
	{
		lcd_data(str[i]);
		str++;
	}
}


void lcd_setposition(uint16_t row, uint16_t col)
{
uint16_t position;
	
switch(row)
{	
		case 1:
			lcd_cmd(0x08);
			delay(1,100);
			position = (col-1)+0x80 ;
			lcd_cmd(position);		
			break;		
	    case 2:
			delay(1,100);
			lcd_secline();
			position = (col-1) +0xc0;
			delay(1,100); 
			lcd_cmd(position);
			break;
	}
}

void lcd_shiftR(uint32_t shift)
{
	uint32_t i = 0;
	while(i < shift)
	{
		delay(1, 700);	 
		lcd_cmd(0x14);
		i++;
	}
}

void lcd_shiftL(uint32_t shift)
{
	uint32_t i = 0;
	while(i < shift)
	{
		delay(1, 700);	 
		lcd_cmd(0x10);
		i++;
	}
}

void lcd_blink(char *str)
{
	uint8_t i = 0;
	lcd_clear();
	delay(1,200);
	while(str[i] != '\0')
	{
		lcd_data(str[i]);
		str++;
	}
	delay(1, 200);	
}