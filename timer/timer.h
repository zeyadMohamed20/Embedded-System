/*
 ***********************************************************************************************************
@file     time.h
@brief    This file sets the delay and timer functions using systick timer
@version  V1.00
@date     9. May 2022
@team     Integration Team
Copyright (C) 2022. All rights reserved.
*************************************************************************************************************
*/

#include"../standard_types.h"

#ifndef TIME_H
#define TIME_H

void timer_init();
void delay_unit_time(uint32_t counts);
void delay(uint8_t choice, uint32_t delayTime);
uint32_t pause();
void resume();
double power(uint16_t base, int8_t exp);

#endif