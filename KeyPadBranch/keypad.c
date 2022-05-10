/*
 **************************************************************************************************************************
@file     keypad.c
@brief    This file defines the bodies of functions which set the delay and timer functions using systick timer
@version  V1.00
@date     9. May 2022
@team     Integration Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/
// include librarys
#include "keypad.h"
#include "../standard_types.h"
#include "../macros.h"
#define b 10	// order of First pin in PortC, that represent Rows 
#define a 10	// order of First pin in PortC, that represent Rows 

// initializing ports and pins needed by keypad
void Init_Keypad_Ports(void)
{
	// clocking both portC and portD
	SYSCTL_RCGCGPIO_R |= 0x0C;
	// wait until Port C & D clocking 
	while((SYSCTL_PRGPIO_R &0x0C) == 0);
	// initiallizing port C & D
	Init_PortC4_7();
	Init_PortD0_3();
}
// initiallizing port C
void Init_PortC4_7(void)
{
	GPIO_PORTC_LOCK_R		=  GPIO_LOCK_KEY;
	GPIO_PORTC_CR_R  		|= 	GPIO_PORTC_PIN4_7;
	GPIO_PORTC_PCTL_R 	&= ~GPIO_PORTC_PCTL_PIN4_7;
	GPIO_PORTC_PDR_R 		|= 	GPIO_PORTC_PIN4_7;
	GPIO_PORTC_AMSEL_R 	&= ~GPIO_PORTC_PIN4_7;
	GPIO_PORTC_AFSEL_R 	&= ~GPIO_PORTC_PIN4_7;
	GPIO_PORTC_DEN_R 		|= 	GPIO_PORTC_PIN4_7;
	GPIO_PORTC_DIR_R 		&= ~GPIO_PORTC_PIN4_7;
}
// initiallizing port D
void Init_PortD0_3()
{
	
	GPIO_PORTD_LOCK_R		=  GPIO_LOCK_KEY;
	GPIO_PORTD_CR_R 		|=  GPIO_PORTD_PIN0_3;
	GPIO_PORTD_PCTL_R 	&= ~GPIO_PORTD_PCTL_PIN0_3;
	GPIO_PORTD_AMSEL_R 	&= ~GPIO_PORTD_PIN0_3;
	GPIO_PORTD_AFSEL_R 	&= ~GPIO_PORTD_PIN0_3;
	GPIO_PORTD_DEN_R 		|=  GPIO_PORTD_PIN0_3;
	GPIO_PORTD_DIR_R 		|=  GPIO_PORTD_PIN0_3;
}


// return value of corresponding pressed key
char KeyPad_Get_Input(void)
{
																	// Col1	 Col2  Col3  Col4
	// Values of Buttons in KeyPad		  PC4   PC5   PC6		PC7 	
	 char Values[4][4] =  		 			 {{ '1' , '2' , '3' , 'A'},		// PD0 		row_0
																		{ '4' , '5' , '6' , 'B'}, 	// PD1		row_1
																		{ '7' , '8' , '9' , 'C'}, 	// PD2		row_2	
																		{ '*' , '0' , '#' , 'D'}};	// PD3		row_3	
// waiting pressing key
	while(1)
	{ // initialization the counter of row and columns
		uint8_t row;
		uint8_t column ;

		// looping and set each row high individually
		for( row = KEYPAD_ROW_START_INDEX ; row < KEYPAD_ROW_LAST_INDEX ; row++) 
		{
			// determine which row to be high in this iteration
			GPIO_PORTD_DATA_R &= ~GPIO_PORTD_PIN0_3;
			GPIO_PORTD_DATA_R |=  KEYPAD_FIRST_ROW << row;
			// with only one certain row high, looping on each column to see which one is pressed
			for( column = KEYPAD_COLUMN_START_INDEX ; column < KEYPAD_COLUMN_LAST_INDEX ; column++)
			{
				// check if a key is pressed and search the column of the pressed key 
				if((GPIO_PORTC_DATA_R & GPIO_PORTC_PIN4_7) == KEYPAD_FIRST_COLUMN << column)
				{
					// return the corresponding value of pressed key
					return Values[row][column];
				}
			}
		}
	}
}

