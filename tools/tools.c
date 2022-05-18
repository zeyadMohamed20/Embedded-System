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
	//GPIO
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x1F;
	GPIO_PORTF_AMSEL_R &= ~0x1F;
	GPIO_PORTF_PCTL_R &= ~0x1F;
	GPIO_PORTF_AFSEL_R &= ~0x1F;
	GPIO_PORTF_DIR_R |= 0x0E;
	GPIO_PORTF_DEN_R |= 0x1F;
	GPIO_PORTF_PUR_R |= 0x11;
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
}

//usage of Push button as Interrupt//
/*void GPIOA_Handler(void)
{ 
	if((GPIO_PORTA_MIS_R & 0x04) != 0x04)
	pause();
	GPIO_PORTA_ICR_R |= 0x04;
}

//usage of SW1 and SW2 buttons as interrupt//
void GPIOF_Handler(void)
{
	if(GPIO_PORTF_MIS_R & 0x01)  //check if interrupt causes by PF4/SW2
	{
		leds_on();
		GPIO_PORTA_ICR_R |= 0x01;
	}
	if(GPIO_PORTF_MIS_R & 0x10) 	//check if interrupt causes by PF4/SW1
  {   
		leds_off();
		GPIO_PORTA_ICR_R |= 0x10;
  }
}*/

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


