/*
 **************************************************************************************************************************
@file     util.c
@brief    This file defines all utility functions which help us in the project
@version  V1.00
@date     17. May 2022
@team     integration Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/
// include librarys
#include "util.h"
#include "../standard_types.h"
#include "../external.h"

uint8_t count_digits(uint32_t number)
{
	if(number == 0)
	{
		return 1;
	}
	else
	{
		uint8_t count = 0;
		while(number!=0)
		{
			number = number/10;
			count++;
		}
		return count;
	}
}

char* integer_to_string(uint32_t number)
{
	const uint8_t size = count_digits(number);
	static char string[10];
	uint8_t i;
	string[size] = '\0';
	for(i = 0;i<size;i++)
	{
		string[size-i-1] = (number%10) + 48;
		number/=10;
	}
	return string;
}

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

void clear_time_array(void)
{
	uint8_t i;
	for(i = 0; i < 5; i++)
	{
		if(i == 2)
			timeArray[i] = ':';
		else
			timeArray[i]='0';
	}
}
