/*
 ***********************************************************************************************************
@file     standard_types.h
@brief    This file defines registers location in the memory instead of hexa mask, and defines constant macros
@version  V1.00
@date     7. May 2022
@team     Integration Team
Copyright (C) 2022. All rights reserved.
*************************************************************************************************************
*/

#ifndef MACROS_H
#define MACROS_H

//*****************************************************************************
//
// Systick Timer registers 
//
//*****************************************************************************
#define NVIC_ST_CTRL_R          (*((volatile uint32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile uint32_t *)0xE000E018))	
//*****************************************************************************
//
// GPIO registers (PORTF)
//
//*****************************************************************************
#define GPIO_PORTF_DATA_R       (*((volatile uint32_t *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile uint32_t *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile uint32_t *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile uint32_t *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile uint32_t *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile uint32_t *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile uint32_t *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile uint32_t *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile uint32_t *)0x4002552C))
//*****************************************************************************
//
// Constant Macros
//
//*****************************************************************************
#define INITIAL_VALUE 0
#define ENABLE_TIMER 5
#define COUNTS_1SEC  16000000-1
#define COUNTS_1MS  16000-1
#define COUNTS_1MICROSEC  16-1
//**************************************************************************************************************

#endif