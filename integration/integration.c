/*
 **************************************************************************************************************************
@file     integration.c
@brief    This file defines functions which integrate tools,LCD,keypad and all possible states 
@version  V1.00
@date     15. May 2022
@team     Integration Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/
// include librarys
#include "integration.h"
#include "../lcd/lcd.h"
#include "../keypad/keypad.h"

void choose_mission(void)
{
  int mission;
	lcd_display("Choose Mission:");
	mission = KeyPad_Get_Input();
	if(mission)
	{
		switch (mission)
		{
		case POPCORN:
			popcorn();
			break;
		case BEAF:
			beaf();
			break;
		case CHICKEN:
			chicken();
			break;
		case SET_TIME:
			set_time();
			break;
		default:
			invalid_mission();
			break;
		}
	}
}

void invalid_mission(void)
{
}

void popcorn(void)
{
	lcd_display("Popcorn");
}

void beaf(void)
{
}

void chicken(void)
{
}

void set_time(void)
{
}
