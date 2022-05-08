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

#include"standard_types.h"
#include"time.h"
#include"macros.h"

void timer_init()
{
	NVIC_ST_CTRL_R = INITIAL_VALUE;
	NVIC_ST_CURRENT_R = INITIAL_VALUE;
}

void delay_unit_time(uint32_t counts)
{
	timer_init();
	NVIC_ST_RELOAD_R = counts - 1;
	NVIC_ST_CTRL_R = ENABLE_TIMER;
	while(!(NVIC_ST_CTRL_R &(1 << 16)))
	{
	}
}


void delay(uint8_t choice,uint32_t delayTime)
{	
	uint32_t i;
	for(i = INITIAL_VALUE; i < delayTime; i++)
	{
		switch(choice)
		{
			case 0:
				delay_unit_time(COUNTS_1SEC);
				break;
			case 1:
				delay_unit_time(COUNTS_1MS);
				break;
			case 2:
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
