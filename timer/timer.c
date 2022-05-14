/*
 **************************************************************************************************************************
@file     time.c
@brief    This file defines the bodies of functions which set the delay and timer functions using systick timer
@version  V1.00
@date     7. May 2022
@team     Integration Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/


#include"../standard_types.h"
#include"../macros.h"
#include"timer.h"

/*
#include"standard_types.h"
#include"macros.h"
#include"time.h"*/


void timer_init()
{
	NVIC_ST_CTRL_R = CLEAR_VALUE;
	NVIC_ST_CURRENT_R = CLEAR_VALUE;
}

void delay_unit_time(uint32_t counts)
{
	timer_init();
	NVIC_ST_RELOAD_R = counts;
	NVIC_ST_CTRL_R = ENABLE_TIMER;
	while (!(NVIC_ST_CTRL_R & COUNT_FLAG_BIT))
	{
	}
}


void delay(uint8_t choice, uint32_t delayTime)
{
	uint32_t i;
	for (i = INITIAL_VALUE; i < delayTime; i++)
	{
		switch (choice)
		{
		case SECOND_CHOICE:
			delay_unit_time(COUNTS_1SEC);
			break;
		case MILLI_SECOND_CHOICE:
			delay_unit_time(COUNTS_1MS);
			break;
		case MICRO_SECOND_CHOICE:
			delay_unit_time(COUNTS_1MICROSEC);
			break;
		}
	}
}

void pause()
{
	
}

void resume()
{
	
	
}