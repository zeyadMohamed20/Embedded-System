/*
 **************************************************************************************************************************
@file     integration.h
@brief    This file defines functions which integrate tools,LCD,keypad and all possible states 
@version  V1.00
@date     15. May 2022
@team     integration Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/
#ifndef INTEGRATION_H
#define INTEGRATION_H

typedef enum state
{
	POPCORN 	= 	'A',
	BEAF,
	CHICKEN,  	
	SET_TIME,
	INVALID_MISSION,
	INVALID_WEIGHT,
	VALID_WEIGHT
}state;

//********** Functions Prototype ***************
void microwave_init(void);   			// Initializes all the components in the microwave including lcd,keypad,tools 
void choose_mission(void);   			// Enables the user to choose the mission(A,B,C,D)
void invalid_mission(void); 			// The action for validation of the user's input in mission choosing 
void popcorn(void);         			// Mission 'A'
void beaf(void);            			// Mission 'B'
void chicken(void);        				// Mission 'C'
void set_time(void);       				// Mission 'D'  
void set_kilo(void);       				// Enables the user to set the weight of the food
void valid_weight(char weight);		// The action for validation of food weight
void invalid_weight(void);    		// The action for invalidation of food weight
void cooking(void);								// Cooking time 
void calc_time(void);							// To calc the total time according to the weight entered
void display_time(void);					// To display time in the form --> 00:00
//*******************************************************
#endif
