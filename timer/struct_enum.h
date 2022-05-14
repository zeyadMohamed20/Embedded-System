/*
 ***********************************************************************************************************
@file     struct_enum.h
@brief    This file defunes the struct and enum for timer
@version  V1.00
@date     11. May 2022
@team     Integration Team
Copyright (C) 2022. All rights reserved.
*************************************************************************************************************
*/

#include"../macros.h"

#ifndef STRUCT_ENUM_H
#define STRUCT_ENUM_H

typedef enum unit 
{
	SECOND,
	MILLI_SECOND,
	MICRO_SECOND
}unit;
typedef struct time
{
	uint32_t currentTime = NVIC_ST_CURRENT_R;
	unit timeUnit = MILLI_SECOND;
}time;
#endif