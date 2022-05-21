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

// Initialize switch 1
void sw1_interrupt_init(void)
{
	GPIO_PORTF_IS_R  &= ~(1<<4);	// make sw1 edge sensitive
	GPIO_PORTF_IBE_R &= ~(1<<4);	// Trigger is controlled bt IEV
	GPIO_PORTF_IEV_R &= ~(1<<4);	// Falling edge trigger
	GPIO_PORTF_ICR_R |=  (1<<4);	// Clear any prior interrupt
	GPIO_PORTF_IM_R  |=  (1<<4);	// unmask interrupt
	NVIC_PRI7_R      = (NVIC_PRI7_R & 0xFF00FFFF)|0x00A00000;	// priority = 3
	NVIC_EN0_R       |=  (1 << 30);	// Enable interrupt in port_F
	__enable_irq();					// Enable global interrupt
}
// Initialize switch 2
void sw2_interrupt_init(void)
{
	GPIO_PORTF_IS_R  &= ~(1<<0);	// make sw2 edge sensitive
	GPIO_PORTF_IBE_R &= ~(1<<0);	// Trigger is controlled bt IEV
	GPIO_PORTF_IEV_R &= ~(1<<0);	// Falling edge trigger
	GPIO_PORTF_ICR_R |=  (1<<0);	// Clear any prior interrupt
	GPIO_PORTF_IM_R  |=  (1<<0);	// unmask interrupt
	NVIC_PRI7_R      = (NVIC_PRI7_R & 0xFF00FFFF)|0x00400000;	// priority = 2
	NVIC_EN0_R		 |=  (1 << 30);	// Enable interrupt in port_F
	__enable_irq();					// Enable global interrupt
}

void sw3_interrupt_init(void)
{
	GPIO_PORTA_IS_R  |=  (1<<2);	// make sw3 edge sensitive
	GPIO_PORTA_IBE_R |=  (1<<2);	// Trigger is controlled bt IEV
	GPIO_PORTA_IEV_R &= ~(1<<2);	// Falling edge trigger
	GPIO_PORTA_ICR_R |=  (1<<2);	// Clear any prior interrupt
	GPIO_PORTA_IM_R  |=  (1<<2);	// unmask interrupt
	NVIC_PRI0_R       = (NVIC_PRI0_R & 0xFFFFFF00)|0x00000020;	// priority = 2
	NVIC_EN0_R       |=  (1 << 0);	// Enable interrupt in port_A
	__enable_irq();					// Enable global interrupt
}

// Initialize all switches
void interrupt_init(void)
{
	sw1_interrupt_init();
	sw2_interrupt_init();
	sw3_interrupt_init();
}	


void GPIOF_Handler(void)
{
	if(GPIO_PORTF_MIS_R & (1 << 4))
	{
		if(currentState == SET_TIME)
		{
			interruptFlag = 1;
		}
		// If sw1 pressed during cooking state --> pause cooking
		if((currentState == COOKING || currentState == DOOR_OPENED || currentState == PAUSE) && (switch1Press == 0 || switch1Press == 1))	
		{
			pause();
		}	
		// If sw1 pressed during pause state --> cancel cooking
		if(currentState == PAUSE && switch1Press == 2)
		{
			cancel_cooking();
			GPIO_PORTF_ICR_R |=  0x11;	//Clear interrupt
		}
	}
	// If sw2 pressed --> resume
	if(GPIO_PORTF_MIS_R & (1 << 0))		
	{
		if(currentState == PAUSE)
		{
			resume();
			GPIO_PORTF_ICR_R |=  0x11;	//Clear interrupt
		}
		if(currentState == SET_TIME)
		{
			if(VALID_TIME)
			{
				GPIO_PORTF_ICR_R |=  0x11;	//Clear interrupt
				//cooking();	
			}
			else
			{
				clear_time_array();
				invalid_time();
			}
		}
	}
	if(currentState != PAUSE)
			GPIO_PORTF_ICR_R |=  0x11;	//Clear interrupt
}

void GPIOA_Handler(void)
{
	if(GPIO_PORTA_MIS_R & (1 << 2))
	{
		if(currentState == COOKING || currentState == DOOR_OPENED || currentState == PAUSE)
			door_opened();
	}	
	if(currentState != PAUSE && currentState != COOKING)
			GPIO_PORTA_ICR_R |=  0x11;	//Clear interrupt
}
