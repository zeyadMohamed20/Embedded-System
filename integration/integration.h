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
#include "../struct_enum.h"

//********** Functions Prototype ***************
void microwave_init(void);   			// Initializes all the components in the microwave including lcd,keypad,tools 
void choose_mission(void);   			// Enables the user to choose the mission(A,B,C,D)
void invalid_mission(void); 			// The action for validation of the user's input in mission choosing 
void popcorn(void);         			// Mission 'A'
void beaf(void);            			// Mission 'B'
void chicken(void);        				// Mission 'C'
void set_time(void);       				// Mission 'D'  
void set_kilo(void);       				// Enables the user to set the weight of the food
void valid_weight(void);					// The action for validation of food weight
void invalid_weight(void);    		// The action for invalidation of food weight
void cooking(void);								// Cooking time 
void calc_time(void);							// Calculates the total time according to the weight entered
void display_time(void);					// Displays the time in the form --> 00:00
void finish_cooking(void);				// Notifys the user to take the food from microwave
void cancel_cooking(void);				// Cancel cooking operation
void pause(void);									// Pause the cooking operation
void resume(void);								// Resume the cooking operation
void door_opened(void);						// If the door is opened execute this function
void invalid_time(void);					// If the time entered is invalid
//*******************************************************
#endif
