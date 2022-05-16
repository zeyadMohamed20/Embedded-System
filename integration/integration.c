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
#include "../struct_enum.h"
#include "../macros.h"

//Global variables
static char missionChoice;		// To store the mission 'A' or 'B' or 'C' or 'D'
int timeMin;									// To store the minutes
int timeSec;									// To store the total time in seconds
int weight;										// To store number of kilos that the user enters


void microwave_init(void)
{
	lcd_init(); 		//lcd initialization ports
	keypad_init();  //keypad initialization ports
	tools_init(); 	// tools initialization ports
}

void choose_mission(void)
{ 
	lcd_display("Choose Mission:");
	missionChoice = keypad_get_input(); //To store mission choice entered by keypad
	lcd_display(&missionChoice);				// Print character that user choosed
	/*
	  if the user enters -> 'A' then exexute popcorn mission
	                        'B' then execute beaf mission
	                        'C' then execute chickem mission
	                        'D' then exexute set time mission
	                        anything else then this is invalid input
	*/
	// Stay in do-while-loop until the user enters a valid choice
	do
	{
		switch (missionChoice)
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
				missionChoice = INVALID_MISSION;
				invalid_mission();
				break;
		}
	}while(missionChoice == INVALID_MISSION);
}

void invalid_mission(void)
{
	//Print invalid input for 2 sec on LCD
	lcd_clear();
	lcd_display("Invalid Input");
	delay(SECOND,2);
}

void popcorn(void)
{
	//Print "popcorn" for 2 sec on LCD
	lcd_clear();
	lcd_display("Popcorn");
	delay(SECOND,2);
}

void beaf(void)
{
	//Print "Beef Weight" then ask the user about weight
	lcd_clear();
	lcd_display("Beef Weight:");
	set_kilo();
}

void chicken(void)
{
	//Print "Chicken Weight:" then ask the user about weight
	lcd_clear();
	lcd_display("Chicken Weight:");
	set_kilo();
}

void set_time(void)
{
	char digit7, digit8, digit10, digit11;		//Each variable is to store the digit entered in each time 
	// Print "Cooking Time" then ask the user to to enter the time from right to left
	lcd_clear();
	lcd_display("Cooking Time");
	lcd_setposition(2, 7);
	lcd_display("00:00");
	//Enter a value in digit 11 on LCD
	lcd_setposition(2, 11);
	digit7 = keypad_get_input();
	lcd_display(&digit7);
	//Enter a value in digit 10 on LCD
	lcd_setposition(2, 10);
	digit8 = keypad_get_input();
	lcd_display(&digit8);
	//Enter a value in digit 8 on LCD
	lcd_setposition(2, 8);
	digit10 = keypad_get_input();
	lcd_display(&digit10);
	//Enter a value in digit 7 on LCD
	lcd_setposition(2, 7);
	digit11 = keypad_get_input();
	lcd_display(&digit11);
}

void set_kilo(void)
{
	char weight, checkWeight;	// weight to store number of kilos, checkWeight to store if weight is valid or not
	//Stay in do-while-loop until the user enters a vaild weight (1 -> 9)
	do
	{
		weight = keypad_get_input(); //Store user's input from keypad in weight variable
		lcd_display(&weight); //print weight on the screen
		if(weight < '1' || weight > '9')
		{
			checkWeight = INVALID_WEIGHT;
			invalid_weight();
			switch(missionChoice)
			{
				case BEAF:
					beaf();
					break;
				case CHICKEN:
					chicken();
					break;
			}
		}
		else
		{
			checkWeight = VALID_WEIGHT;
			valid_weight(weight);
		}
	}while(checkWeight == INVALID_WEIGHT);
}

void valid_weight(char weight)
{
	//Clear the display then print the weight value entered by the user for 2 seconds
	lcd_clear();
	lcd_display("Weight Value:");
	lcd_display(&weight);
	delay(SECOND,2);
}

void invalid_weight(void)
{
	//Print error for 2 seconds
	lcd_clear();
	lcd_display("Err");
	delay(SECOND,2);
}

void calc_time(void)
{
	// The time depends on the mission
  switch(missionChoice)
  {
    case POPCORN:
    timeSec = 60;
    break;
    case BEAF:
    timeSec = (weight - '0') * BEAF_SECONDS_PER_KILO;			// timeSec = weight * 0.5 * 60 
		timeMin = timeSec % 60;						// Store Minutes in timeMin variable
    break;
    case CHICKEN:
    timeSec = (weight - '0') * CHICKEN_SECONDS_PER_KILO;	// timeSec = weight * 0.2 * 60 
		timeMin = timeSec % 60;						// Store Minutes in timeMin variable
    break;
  }
}

void display_time(void)
{
	lcd_secline();
  delay(MILLI_SECOND, 10);
	lcd_setposition(2, 7);
	delay(SECOND, 2);
}

void cooking(void)
{
	leds_on();
	calc_time();
	display_time();
}
