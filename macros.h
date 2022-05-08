/*
 ***********************************************************************************************************
@file     standard_types.h
@brief    This file defines registers location in the memory instead of hexa mask, and defines magic numbers that used in the program 
@version  V1.00
@date     7. May 2022
@team     Integration Team
Copyright (C) 2022. All rights reserved.
*************************************************************************************************************
*/

#ifndef MACROS_H
#define MACROS_H

//***************************GPIO Pins************************************************************************
#define NVIC_ST_CTRL_R          (*((volatile uint32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile uint32_t *)0xE000E018))
//*************************************************************************************************************

//*************************Constanst Macros*********************************************************************
#define INITIAL_VALUE 0
#define ENABLE_TIMER 5
#define COUNTS_1SEC  16000000-1
#define COUNTS_1MS  16000-1
#define COUNTS_1MICROSEC  16-1
//**************************************************************************************************************

#endif