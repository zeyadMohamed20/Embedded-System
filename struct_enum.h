/*
 ***********************************************************************************************************
@file     struct_enum.h
@brief    This file defines the struct and enum for timer
@version  V1.00
@date     11. May 2022
@team     Integration Team
Copyright (C) 2022. All rights reserved.
*************************************************************************************************************
*/

#ifndef STRUCT_ENUM_H
#define STRUCT_ENUM_H

#include "standard_types.h"

typedef enum state
{
	POPCORN 	= 	'A',
	BEAF,
	CHICKEN,  	
	SET_TIME,
	CHOOSE_MISSION,
	INVALID_MISSION,
	SET_KILO,
	VALID_WEIGHT,
	INVALID_WEIGHT,
  CLEAR_DIGIT,
  INVALID_TIME,
  COOKING,
  PAUSE,
  DOOR_OPENED,
  FINISH_COOKING,
  CANCEL_COOKING
}state;

typedef enum unit
{
	SECOND,
	MILLI_SECOND,
	MICRO_SECOND
}unit;
typedef struct time
{
	uint32_t currentTime;
  unit timeUnit;
}time;
#endif
