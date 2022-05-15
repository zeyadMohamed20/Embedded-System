/*
 ***********************************************************************************************************
@file     time.h
@brief    This file sets the delay and timer functions using systick timer
@version  V1.00
<<<<<<< HEAD
@date     9. May 2022
=======
@date     7. May 2022
>>>>>>> testing
@team     Integration Team
Copyright (C) 2022. All rights reserved.
*************************************************************************************************************
*/

<<<<<<< HEAD
#ifndef TIME_H
#define TIME_H

#include"../standard_types.h"

void timer_init();
void delay_unit_time(uint32_t counts);
void delay(uint8_t choice, uint32_t delayTime);
uint32_t pause();
void resume();
double power(uint16_t base, int8_t exp);

#endif
=======
#include "../standard_types.h"



#ifndef TIME_H
#define TIME_H

void timer_init();
void delay_unit_time(uint32_t counts);
void delay(uint8_t choice, uint32_t delayTime);
void pause();
void resume();

#endif
>>>>>>> testing
