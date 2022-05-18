/*
 **************************************************************************************************************************
@file     interrupt.c
@brief    This file defines the the interrupts in the whole project 
@version  V1.00
@date     17. May 2022
@team     integration team with tools Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/
// include librarys
#include "../external.h"
#include "interrupt.h"
#include "../LCD/lcd.h"
#include "../macros.h"
#include "../struct_enum.h"
#include "../timer/timer.h"
#include "../tools/tools.h"
#include "../integration/integration.h"


void interrupt_init(void)
{
	sw1_interrupt_init();
	sw2_interrupt_init();
}	

void sw1_interrupt_init(void)
{
	GPIO_PORTF_IS_R  &= ~(1<<4);
  GPIO_PORTF_IBE_R &= ~(1<<4);
	GPIO_PORTF_IEV_R &= ~(1<<4);
	GPIO_PORTF_ICR_R |=  (1<<4);
	GPIO_PORTF_IM_R  |=  (1<<4);
	NVIC_PRI7_R      = (NVIC_PRI7_R & 0xFF00FFFF)|0x00A00000;
  NVIC_EN0_R       |=  (1 << 30);
  __enable_irq();	
}

void sw2_interrupt_init(void)
{
	GPIO_PORTF_IS_R  &= ~(1<<0);
  GPIO_PORTF_IBE_R &= ~(1<<0);
	GPIO_PORTF_IEV_R &= ~(1<<0);
	GPIO_PORTF_ICR_R |=  (1<<0);
	GPIO_PORTF_IM_R  |=  (1<<0);
	NVIC_PRI7_R      = (NVIC_PRI7_R & 0xFF00FFFF)|0x00A00000;
  NVIC_EN0_R       |=  (1 << 30);
  __enable_irq();	
}

void GPIOF_Handler(void)
{
	if(GPIO_PORTF_MIS_R & (1 << 4))
	{
		if(currentState == SET_TIME)
		{
			uint8_t i;
			for(i = 0; i < 5; i++)
			{
				if(i == 2)
					timeArray[i] = ':';
				else
					timeArray[i]='0';
			}
			lcd_clear();
			lcd_display("Cooking Time");
			lcd_setposition(2, 7);
			lcd_display(timeArray);
		}
			// If sw1 pressed during cooking state --> pause cooking
			else if(currentState == COOKING)	
			{
				pause();
				GPIO_PORTF_ICR_R |= (1 << 4);		
			}	
			// If sw1 pressed during pause state --> cancel cooking
			else if(currentState == PAUSE)
			{
				cancel_cooking();
			}
		interruptFlag = 1;
		GPIO_PORTF_ICR_R |=  (1 << 4);
	}
	// If sw2 pressed --> resume
	else if(GPIO_PORTF_MIS_R & (1 << 0))		
	{
		resume();
		GPIO_PORTF_ICR_R |= (1 << 0);		
	}
}
