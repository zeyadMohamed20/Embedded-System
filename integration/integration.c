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
#include "../keypad/keypad.h"
#include "../lcd/lcd.h"
#include "../tools/tools.h"
#include "../timer/timer.h"
#include "../timer/struct_enum.h"


void microwave_init(void)
{
	lcd_init(); //lcd initialization ports
	keypad_init(); //keypad initialization ports
	tools_init(); // tools initialization ports
}

void choose_mission(void)
{
  char mission; 
	lcd_display("Choose Mission:");
	mission = keypad_get_input(); //To store mission choice entered by keypad
	
	/*
	  if the user enters -> 'A' then exexute popcorn mission
	                        'B' then execute beaf mission
	                        'C' then execute chickem mission
	                        'D' then exexute set time mission
	                        anything else then this is invalid input
	*/
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

void invalid_mission(void)
{
	//Print invalid input for 2 sec on LCD
	lcd_display("Invalid Input");
	delay(SECOND,2);
}

void popcorn(void)
{
	//Print popcorn for 2 sec on LCD
	lcd_display("Popcorn");
	delay(SECOND,2);
}

void beaf(void)
{
	//Print Beef weight then ask the user about weight
	lcd_display("Beef Weight: ");
	set_kilo();
}

void chicken(void)
{
	//Print Chicken weight then ask the user about weight
	lcd_display("Chicken Weight:");
	set_kilo();
}

void set_time(void)
{
}

void set_kilo(void)
{
	char weight = keypad_get_input(); //Store user's input from keypad in weight variable
	lcd_data(weight); //print weight on the screen
	
	//Case of weight validation
	if(weight>='1' && weight <='9')
	{
		valid_weight(weight);
	}
	else //Case of weight invalidation
	{
		invalid_weight();
		set_kilo(); //Call the same function again until a valid weight is entered
	}
}

void valid_weight(char weight)
{
	//Clear the display then print the weight value entered by the user for 2 seconds
	lcd_clear();
	lcd_display("Weight Value:");
	lcd_data(weight);
	delay(SECOND,2);
}

void invalid_weight()
{
	//Print error for 2 seconds
	lcd_display("Err");
	delay(SECOND,2);
}
