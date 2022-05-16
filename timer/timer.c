/*
 **************************************************************************************************************************
@file     time.c
@brief    This file defines the bodies of functions which set the delay and timer functions using systick timer
@version  V1.00
@date     11. May 2022
@team     Integration Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/
// include librarys
#include "timer.h"
#include "../macros.h"
#include "../standard_types.h"
#include "../struct_enum.h"

time timer;

double power(uint16_t base, int8_t exp)
{
	double result = 1;
	uint8_t isPositive = exp >= 0 ? 1 : (exp *= -1, 0);

	while (exp)
	{
		if (exp & 1)
			result = result * base;
		exp = exp >> 1;
		base = base * base;
	}
	if (isPositive)
		return result;
	else
		return 1 / result;
}

void timer_init(void)
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

void delay(unit choice, uint32_t delayTime)
{
	uint32_t i;
	for (i = INITIAL_VALUE; i < delayTime; i++)
	{
		switch (choice)
		{
		case SECOND:
			delay_unit_time(COUNTS_1SEC);
			timer.timeUnit = SECOND;
			break;
		case MILLI_SECOND:
			delay_unit_time(COUNTS_1MS);
			timer.timeUnit = MILLI_SECOND;
			break;
		case MICRO_SECOND:
			delay_unit_time(COUNTS_1MICROSEC);
			timer.timeUnit = MICRO_SECOND;
			break;
		default:
			delay_unit_time(COUNTS_1MS);
			timer.timeUnit = MILLI_SECOND;
			break;
		}
	}
}
time pause(void)
{
	timer.currentTime = NVIC_ST_CURRENT_R;
	timer_init();
	return timer;
}


void resume(void)
{
	delay(timer.timeUnit, timer.currentTime);
}
