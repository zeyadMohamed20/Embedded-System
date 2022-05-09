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
// GPIO Register Control
//
//*****************************************************************************
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_PRGPIO_R         (*((volatile uint32_t *)0x400FEA08))

//*****************************************************************************
//
// GPIO registers (PORT C)
//
//*****************************************************************************
	// Addresses
#define GPIO_PORTC_DATA_R       (*((volatile uint32_t *)0x400063FC))
#define GPIO_PORTC_DIR_R        (*((volatile uint32_t *)0x40006400))
#define GPIO_PORTC_AFSEL_R      (*((volatile uint32_t *)0x40006420))
#define GPIO_PORTC_DEN_R        (*((volatile uint32_t *)0x4000651C))
#define GPIO_PORTC_CR_R         (*((volatile uint32_t *)0x40006524))
#define GPIO_PORTC_AMSEL_R      (*((volatile uint32_t *)0x40006528))
#define GPIO_PORTC_PCTL_R       (*((volatile uint32_t *)0x4000652C))
#define GPIO_PORTC_PDR_R        (*((volatile uint32_t *)0x40006514))
	// Constant
#define GPIO_PORTC_PIN4_7				0xF0   // pin 4 to 7 
#define GPIO_PORTC_PCTL_PIN4_7	0xFFFF0000   // PCTL for pin 4 to 7 

//*****************************************************************************
//
// GPIO registers (PORT D)
//
//*****************************************************************************
	// Addresses
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
#define GPIO_PORTD_PIN0_3				0x0F   // pin 0 to 3 
#define GPIO_PORTD_PCTL_PIN0_3	0x0000FFFF   // PCTL for pin 0 to 3 

//*****************************************************************************
//
// Constant Macros
//
//*****************************************************************************
#define KEYPAD_FIRST_ROW					0x10	// order of First pin in PortC, that represent Rows 
#define KEYPAD_FIRST_COLUMN				0x01	// order of First pin in PortD, that represent Columns

#define KEYPAD_ROW_START_INDEX		0			// start index of Row
#define KEYPAD_ROW_LAST_INDEX			4			// start index of Row
#define KEYPAD_COLUMN_START_INDEX	0			// start index of Column
#define KEYPAD_COLUMN_LAST_INDEX	4			// start index of Column

#endif
