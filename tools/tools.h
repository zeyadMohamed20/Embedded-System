/*
 **************************************************************************************************************************
@file     tools.h
@brief    This file defines the bodies of functions which defines and configure tools like LEDS,Buzer 
@version  V1.00
@date     11. May 2022
@team     tools Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/

#ifndef TOOLS_H
#define TOOLS_H

#include "../standard_types.h"
#include "../struct_enum.h"

//********** Functions Prototype ***************
void tools_init(void);//enable ports f and port a
void portF_initialization(void); //initiallizing port f
void portA_initialization(void);//initiallizing port a
//void sw1_interrupt_initialization(void); //initialization interrupt registers of sw1
//void sw2_interrupt_initialization(void); //initialization interrupt registers of sw2
//void GPIOF_Handler(void); //interrupt SW1 , SW2//
//void GPIOA_Handler(void); //interrupt push button//
void leds_on(void);
void leds_off(void);
void buzzer_on(void);
void buzzer_off(void);	
void leds_buzzer_blink(uint8_t numberOfBlink,unit onDelay,uint32_t delayTimeOn,unit offDelay,uint32_t delayTimeOff);
//*************************************************************************************************************************************
#endif // !TOOLS_H
