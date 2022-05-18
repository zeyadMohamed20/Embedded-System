/*
 **************************************************************************************************************************
@file     util.h
@brief    This file defines all utility functions which help us in the project
@version  V1.00
@date     17. May 2022
@team     integration Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/
#ifndef UTIL_H
#define UTIL_H
#include"../standard_types.h"

//************************** Functions Prototype ***************************************************************************
double power(uint16_t base, int8_t exp);
uint8_t count_digits(uint32_t number);
char* integer_to_string(uint32_t number);
void clear_time_array(void);
//***************************************************************************************************************************
#endif
