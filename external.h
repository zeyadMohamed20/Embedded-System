/*
 **************************************************************************************************************************
@file     external.h
@brief    This file defines the external variables used in the project 
@version  V1.00
@date     17. May 2022
@team     integration team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/

#ifndef EXTERNAL_H
#define EXTERNAL_H

#include "standard_types.h"

//************************** External Variables *****************************************************************************
volatile extern char currentState;		// To store the mission 'A' or 'B' or 'C' or 'D'
volatile extern char timeArray[];				// Each index is used to store the digit entered in each time
volatile extern uint8_t interruptFlag;
volatile extern uint8_t switch1Press;

#endif
