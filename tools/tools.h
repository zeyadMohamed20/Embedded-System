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

#include"../standard_types.h"
#include"../timer/struct_enum.h"

//********** Functions Prototype ***************
void enable_portf_and_a(void);//enable ports f and port a
void portf(void); //initiallizing port f
void porta(void);//initiallizing port a
void GPIOF_Handler(void); //interrupt SW1 , SW2//
void GPIOA_Handler(void); //interrupt push button//
void leds_on(void);
void leds_off(void);
void buzzer_on(void);
void buzzer_off(void);	
void leds_blink(uint8_t NumberOfBlink,unit OnDelay,uint32_t delayTimeOn,unit OffDelay,uint32_t delayTimeOff);
//*************************************************************************************************************************************
#endif // !TOOLS_H
