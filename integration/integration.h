/*
 **************************************************************************************************************************
@file     integration.h
@brief    This file defines functions which integrate tools,LCD,keypad and all possible states 
@version  V1.00
@date     15. May 2022
@team     integration Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/
#ifndef INTEGRATION_H
#define INTEGRATION_H

typedef enum mission
{
	POPCORN,
	BEAF,
	CHICKEN,
	SET_TIME
}mission;

//********** Functions Prototype ***************
void choose_mission(void);
void invalid_mission(void);
void popcorn(void);
void beaf(void);
void chicken(void);
void set_time(void);
//*******************************************************
#endif
