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
#include "interrupt.h"
#include "../macros.h"

void sw1_interrupt_init(void)
{
	GPIO_PORTF_IS_R  &= ~(1<<4);
  GPIO_PORTF_IBE_R &= ~(1<<4);
	GPIO_PORTF_IEV_R &= ~(1<<4);
	GPIO_PORTF_ICR_R |=  (1<<4);
	GPIO_PORTF_IM_R  |=  (1<<4);
	NVIC_PRI17_R      = (NVIC_PRI17_R & 0xFF00FFFF)|0x00A00000;
  NVIC_EN0_R       |=  (1<<30);
  __enable_irq();	
}

void sw2_interrupt_init(void)
{
}
