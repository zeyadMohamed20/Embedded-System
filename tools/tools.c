/*
 **************************************************************************************************************************
@file     tools.c
@brief    This file defines the bodies of functions which defines and configure tools like LEDS,Buzer 
@version  V1.00
@date     11. May 2022
@team     tools Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/
// include librarys
#include "tools.h"
#include "../macros.h"
#include "../timer/timer.h"
#include "../standard_types.h"
#include "../struct_enum.h"

void tools_init(void)
{
	SYSCTL_RCGCGPIO_R |=0x21;
	while((SYSCTL_PRGPIO_R &0x21) == 0);
	portF_initialization();
	portA_initialization();
}
//initiallization port f//
void portF_initialization(void)
{
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x1F;
	GPIO_PORTF_AMSEL_R |= 0;
	GPIO_PORTF_PCTL_R |= 0;
	GPIO_PORTF_AFSEL_R |= 0;
	GPIO_PORTF_DIR_R |= 0x1E;
	GPIO_PORTF_DEN_R |= 0x1F;
	GPIO_PORTF_PUR_R |= 0x11;
	GPIO_PORTF_ICR_R |= (1<<4)|(1<<0);
}
//initiallization port a	
void portA_initialization(void)
{
	GPIO_PORTA_LOCK_R = 0x4C4F434B;
	GPIO_PORTA_CR_R |= 0x1F;
	GPIO_PORTA_AMSEL_R |= 0;
	GPIO_PORTA_PCTL_R |= 0;
	GPIO_PORTA_AFSEL_R |= 0;
	GPIO_PORTA_DIR_R |= 0x1E;
	GPIO_PORTA_DEN_R |= 0x1F;
	GPIO_PORTA_PUR_R |= 0x11;
	GPIO_PORTA_ICR_R |= (1 << 2);
}


//usage of Push button as Interrupt//

void GPIOA_Handler(void)
{ /* if ((GPIO_PORTA_MIS_R&0x04)!=0x04)
	pause();
	GPIO_PORTA_ICR_R  |= 0x04;
	*/
}

//usage of SW1 and SW2 buttons as interrupt//
void GPIOF_Handler(void)
{
/*	   //SW2 is pushed for 1st time and start cooking and leds turn on//
      if ((GPIO_PORTF_MIS_R &0x11)==0x01)
	  {
					leds_on();	
					//SW1 is pushed for 1st time and pause cooking//
					if ((GPIO_PORTF_MIS_R &0X11)==0X11)
					{
						//pause();
						//SW1 is pushed for 2nd time and stop cooking and leds turn off//
						if((GPIO_PORTF_MIS_R & 0x11)==0x01)
						{
						lcd_clear();
						leds_off();	
						GPIO_PORTF_ICR_R  |= (1<<0);
						}
						//SW2 is pushed for 2nd time after 1st time of SW1 is pushed which resume cooking after pause cooking//
						else if((GPIO_PORTF_MIS_R &0x11)==0x10)
						{
								//resume();
								leds_on();
								GPIO_PORTF_ICR_R |= (1<<4);
						}
					}
	  }
		*/
}
//turn on leds//
void leds_on(void)
{
		GPIO_PORTF_DATA_R=0X0E;
}
//turn off leds//
void leds_off(void)
{
	GPIO_PORTF_DATA_R^=0X0E;
}
//turn on buzzer//
void buzzer_on(void)
{
	GPIO_PORTA_DATA_R=0x08;
}
//turn off buzzer//
void buzzer_off(void)
{
	GPIO_PORTA_DATA_R^=0X08;
}


