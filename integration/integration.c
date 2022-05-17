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
	uint8_t i;			// Use i in for loop
	char timeArray[4];		//Each index is used to store the digit entered in each time 
	// Print "Cooking Time" then ask the user to to enter the time from right to left
	lcd_clear();
	lcd_display("Cooking Time");
	lcd_setposition(2, 7);
	lcd_display("00:00");
	//Enter a value in digit 11 on LCD
	for(i = 0; i <= 5; i++)
	{
		lcd_shiftL(i);
		lcd_setposition(2, 11);
		timeArray[i] = keypad_get_input();
		lcd_display(&timeArray[i]);
// {	timeArray[0] = LCDdigit7, timeArray[1] = LCDdigit8 } --> minutes
// {	timeArray[2] = LCDdigit10, timeArray[3] = LCDdigit11 } --> seconds 
	}
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
	// Divide the timer into four timers as follows	
	// timer1	 timer2		 timer3	timer4
	//	 0       0    :    0       0

	int8_t timer1, timer2, timer3, timer4;
	timer1 = timeMin / 10;		// Tens of Minutes
	timer2 = 0;								// Ones of Minutes
	timer3 = timeSec / 10;		// Tens of Seconds
	timer4 = 0;								// Ones of Seconds
	
	lcd_clear();			//Clear LCD
	// Display the time remaining
	do
	{
		lcd_setposition(2, 7);		//Set the cursor in the middle of LCD 
		
		timer4 -= 1;
		if(timer4 == -1)	timer4 = 9;
		if(timer4 == 9)	timer3 -= 1;
		if(timer3 == -1)	timer3 = 6;
		if(timer3 == 0 && timer1 != 0)	timer2 -= 1;
		if(timer2 == -1) timer2 = 9;
		if(timer2 == 9)	timer1 -= 1;
		
		delay(SECOND, 1);
		
		lcd_display(integer_to_string(timer1));
		lcd_display(integer_to_string(timer2));
		lcd_display(":");
		lcd_display(integer_to_string(timer3));
		lcd_display(integer_to_string(timer4));
		
	}while((timer1 != 0 || timer2 != 0 || timer3 != 0 || timer4 != 0));
}

void cooking(void)
{
	leds_on();
	calc_time();
	display_time();
}

void finish_cooking(void)
{
	blink(3, MILLI_SECOND, 500, MILLI_SECOND, 500);
}

//determine time of leds blinking//
void blink(uint8_t numberOfBlink,unit onDelay,uint32_t delayTimeOn,unit offDelay,uint32_t delayTimeOff)
{
	uint8_t i;
	for (i=0 ;i < numberOfBlink; i++)
	{
		leds_on();
		buzzer_on();
		lcd_blink("00:00");
		lcd_clear();
		delay(onDelay,delayTimeOn);
		leds_off();
		buzzer_off();
		lcd_blink("00:00");
		lcd_clear();
		delay(offDelay,delayTimeOff); 	
	}
}

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
