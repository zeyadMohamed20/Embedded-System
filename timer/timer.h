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
#ifndef TIME_H
#define TIME_H

#include "../standard_types.h"
#include "../struct_enum.h"

//********** Functions Prototype ***************
void timer_init(void);
void delay_unit_time(uint32_t counts);
void delay(unit choice, uint32_t delayTime);
time pause(void);
void resume(void);
//**********************************************
#endif
