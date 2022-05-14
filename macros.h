/*
 ***********************************************************************************************************
@file     macros.h
@brief    This file defines registers location in the memory instead of hexa mask, and defines constant macros
@version  V1.00
@date     9. May 2022
@team     Integration Team
Copyright (C) 2022. All rights reserved.
*************************************************************************************************************
*/

#ifndef MACROS_H
#define MACROS_H

//*****************************************************************************
//
// GPIO Register Control
//
//*****************************************************************************
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_PRGPIO_R         (*((volatile uint32_t *)0x400FEA08))
#define GPIO_LOCK_KEY           0x4C4F434B  // Unlocks the GPIO_CR register

//*****************************************************************************
//
// GPIO registers (PORT C)
//
//*****************************************************************************
	// Addresses
//#define GPIO_PORTC_LOCK_R       (*((volatile uint32_t *)0x40006520))
//#define GPIO_PORTC_DATA_R       (*((volatile uint32_t *)0x400063FC))
//#define GPIO_PORTC_DIR_R        (*((volatile uint32_t *)0x40006400))
//#define GPIO_PORTC_AFSEL_R      (*((volatile uint32_t *)0x40006420))
//#define GPIO_PORTC_DEN_R        (*((volatile uint32_t *)0x4000651C))
//#define GPIO_PORTC_CR_R         (*((volatile uint32_t *)0x40006524))
//#define GPIO_PORTC_AMSEL_R      (*((volatile uint32_t *)0x40006528))
//#define GPIO_PORTC_PCTL_R       (*((volatile uint32_t *)0x4000652C))
//#define GPIO_PORTC_PDR_R        (*((volatile uint32_t *)0x40006514))
//	// Constant
//#define GPIO_PORTC_PIN4_7				0xF0   // pin 4 to 7 
//#define GPIO_PORTC_PCTL_PIN4_7	0xFFFF0000   // PCTL for pin 4 to 7 

//*****************************************************************************
//
// GPIO registers (PORT D)
//
//*****************************************************************************
	// Addresses
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
	// Constants
#define GPIO_PORTD_PIN0_3				0xF   // pin 0 to 3 
#define GPIO_PORTD_PCTL_PIN0_3	0x0000FFFF   // PCTL for pin 0 to 3 
//*****************************************************************************
//
// GPIO registers (PORT E)
//
//*****************************************************************************
	// Registers
#define GPIO_PORTE_DATA_R       (*((volatile uint32_t *)0x400243FC))
#define GPIO_PORTE_DIR_R        (*((volatile uint32_t *)0x40024400))
#define GPIO_PORTE_AFSEL_R      (*((volatile uint32_t *)0x40024420))
#define GPIO_PORTE_PDR_R        (*((volatile uint32_t *)0x40024514))
#define GPIO_PORTE_DEN_R        (*((volatile uint32_t *)0x4002451C))
#define GPIO_PORTE_LOCK_R       (*((volatile uint32_t *)0x40024520))
#define GPIO_PORTE_CR_R         (*((volatile uint32_t *)0x40024524))
#define GPIO_PORTE_AMSEL_R      (*((volatile uint32_t *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile uint32_t *)0x4002452C))
	// Constants
#define GPIO_PORTE_PIN1_4				0x1E   // pin 4 to 7 
#define GPIO_PORTE_PCTL_PIN1_4	0x000FFFF0   // PCTL for pin 4 to 7

//*****************************************************************************
//
// Constant Macros
//
//*****************************************************************************

#define KEYPAD_FIRST_ROW					0x01	// order of First pin in PortD, that represent Rows 
#define KEYPAD_FIRST_COLUMN				0x02	// order of First pin in PortE, that represent Columns
#define KEYPAD_ROW_START_INDEX		0x00	// start index of Row
#define KEYPAD_ROW_LAST_INDEX			0x04	// start index of Row
#define KEYPAD_COLUMN_START_INDEX	0x00	// start index of Column
#define KEYPAD_COLUMN_LAST_INDEX	0x04	// start index of Column



#endif
