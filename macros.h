/*
 ***********************************************************************************************************
@file     macros.h
@brief    This file defines registers location in the memory instead of hexa mask, and defines constant macros
@version  V1.00
@date     9. May 2022
@team     All Teams
Copyright (C) 2022. All rights reserved.
*************************************************************************************************************
*/

#ifndef MACROS_H
#define MACROS_H

//****************************NVIC Registers*********************************************************
#define NVIC_ST_CTRL_R          (*((volatile uint32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile uint32_t *)0xE000E018))

//****************************GPIO Register Control*************************************************
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_PRGPIO_R         (*((volatile uint32_t *)0x400FEA08))
//**************************************************************************************************

//**************************************************************************************************
#define GPIO_LOCK_KEY 0x4C4F434B // Unlocks the GPIO_CR register
//**********************************************************************************************

//************************************* GPIO registers (PORTA)****************************************
#define GPIO_PORTA_DATA_BITS_R  ((volatile unsigned long *)0x40004000)
#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_IS_R         (*((volatile unsigned long *)0x40004404))
#define GPIO_PORTA_IBE_R        (*((volatile unsigned long *)0x40004408))
#define GPIO_PORTA_IEV_R        (*((volatile unsigned long *)0x4000440C))
#define GPIO_PORTA_IM_R         (*((volatile unsigned long *)0x40004410))
#define GPIO_PORTA_RIS_R        (*((volatile unsigned long *)0x40004414))
#define GPIO_PORTA_MIS_R        (*((volatile unsigned long *)0x40004418))
#define GPIO_PORTA_ICR_R        (*((volatile unsigned long *)0x4000441C))
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_DR2R_R       (*((volatile unsigned long *)0x40004500))
#define GPIO_PORTA_DR4R_R       (*((volatile unsigned long *)0x40004504))
#define GPIO_PORTA_DR8R_R       (*((volatile unsigned long *)0x40004508))
#define GPIO_PORTA_ODR_R        (*((volatile unsigned long *)0x4000450C))
#define GPIO_PORTA_PUR_R        (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTA_PDR_R        (*((volatile unsigned long *)0x40004514))
#define GPIO_PORTA_SLR_R        (*((volatile unsigned long *)0x40004518))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_LOCK_R       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_R         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))
#define GPIO_PORTA_ADCCTL_R     (*((volatile unsigned long *)0x40004530))
#define GPIO_PORTA_DMACTL_R     (*((volatile unsigned long *)0x40004534))
//***************************************************************************************************

//********************************GPIO registers (PORTB)*********************************************
#define GPIO_PORTB_DATA_BITS_R  ((volatile unsigned long *)0x40005000)
#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_IS_R         (*((volatile unsigned long *)0x40005404))
#define GPIO_PORTB_IBE_R        (*((volatile unsigned long *)0x40005408))
#define GPIO_PORTB_IEV_R        (*((volatile unsigned long *)0x4000540C))
#define GPIO_PORTB_IM_R         (*((volatile unsigned long *)0x40005410))
#define GPIO_PORTB_RIS_R        (*((volatile unsigned long *)0x40005414))
#define GPIO_PORTB_MIS_R        (*((volatile unsigned long *)0x40005418))
#define GPIO_PORTB_ICR_R        (*((volatile unsigned long *)0x4000541C))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_DR2R_R       (*((volatile unsigned long *)0x40005500))
#define GPIO_PORTB_DR4R_R       (*((volatile unsigned long *)0x40005504))
#define GPIO_PORTB_DR8R_R       (*((volatile unsigned long *)0x40005508))
#define GPIO_PORTB_ODR_R        (*((volatile unsigned long *)0x4000550C))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_PDR_R        (*((volatile unsigned long *)0x40005514))
#define GPIO_PORTB_SLR_R        (*((volatile unsigned long *)0x40005518))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_R       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))
#define GPIO_PORTB_ADCCTL_R     (*((volatile unsigned long *)0x40005530))
#define GPIO_PORTB_DMACTL_R     (*((volatile unsigned long *)0x40005534))
//***************************************************************************************************

//************************************GPIO registers (PORT D)*****************************************
#define GPIO_PORTD_LOCK_R       (*((volatile uint32_t *)0x40007520))
#define GPIO_PORTD_DATA_R       (*((volatile uint32_t *)0x400073FC))
#define GPIO_PORTD_DIR_R        (*((volatile uint32_t *)0x40007400))
#define GPIO_PORTD_AFSEL_R      (*((volatile uint32_t *)0x40007420))
#define GPIO_PORTD_PUR_R        (*((volatile uint32_t *)0x40007510))
#define GPIO_PORTD_PDR_R        (*((volatile uint32_t *)0x40007514))
#define GPIO_PORTD_DEN_R        (*((volatile uint32_t *)0x4000751C))
#define GPIO_PORTD_CR_R         (*((volatile uint32_t *)0x40007524))
#define GPIO_PORTD_AMSEL_R      (*((volatile uint32_t *)0x40007528))
#define GPIO_PORTD_PCTL_R       (*((volatile uint32_t *)0x4000752C))
//******************************************************************************************************

//**********************************GPIO registers (PORT E)*********************************************************
#define GPIO_PORTE_DATA_R       (*((volatile uint32_t *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile uint32_t *)0x40024400))
#define GPIO_PORTE_AFSEL_R      (*((volatile uint32_t *)0x40024420))
#define GPIO_PORTE_PDR_R        (*((volatile uint32_t *)0x40024514))
#define GPIO_PORTE_DEN_R        (*((volatile uint32_t *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile uint32_t *)0x40024520))
#define GPIO_PORTE_CR_R         (*((volatile uint32_t *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile uint32_t *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile uint32_t *)0x4002452C))
//*******************************************************************************************************************

//********************************GPIO registers (PORTF)*********************************************************
#define GPIO_PORTF_DATA_R       (*((volatile uint32_t *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile uint32_t *)0x40025400))
#define GPIO_PORTF_MIS_R        (*((volatile uint32_t *)0x40025418))
#define GPIO_PORTF_ICR_R        (*((volatile uint32_t *)0x4002541C))
#define GPIO_PORTF_AFSEL_R      (*((volatile uint32_t *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile uint32_t *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile uint32_t *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile uint32_t *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile uint32_t *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile uint32_t *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile uint32_t *)0x4002552C))
//*****************************************************************************************************************

//***********************************GPIO Constant Macros******************************************************
#define GPIO_PORTD_PIN0_3				0x0F   // pin 0 to 3 
#define GPIO_PORTD_PCTL_PIN0_3	0x0000FFFF   // PCTL for pin 0 to 3 
//*************************************************************************************************************

//************************************************GPIO Constant Macros************************************************
#define GPIO_PORTE_PIN1_4				0x1E   // pin 4 to 7 
#define GPIO_PORTE_PCTL_PIN1_4	0x000FFFF0   // PCTL for pin 4 to 7
//*********************************************************************************************************************

//*************************************Constant Macros*********************************************************************
#define KEYPAD_FIRST_ROW					0x01	// order of First pin in PortD, that represent Rows 
#define KEYPAD_FIRST_COLUMN				0x10	// order of First pin in PortC, that represent Columns
#define KEYPAD_ROW_START_INDEX		0x00	// start index of Row
#define KEYPAD_ROW_LAST_INDEX			0x04	// start index of Row
#define KEYPAD_COLUMN_START_INDEX	0x00	// start index of Column
#define KEYPAD_COLUMN_LAST_INDEX	0x04	// start index of Column
//************************************************************************************************************************

//******************************* Timer Constant Macros ******************************************************************
#define CLEAR_VALUE 0
#define ENABLE_TIMER 5
#define ONE_COUNT_TIME 62.5 *power(10,-9);
#define COUNTS_1SEC  16000000-1
#define COUNTS_1MS  16000-1
#define COUNTS_1MICROSEC  16-1
#define INITIAL_VALUE 0
#define COUNT_FLAG_BIT (1 << 16)
//********************************************************************************************************************
#endif