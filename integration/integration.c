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
static char missionChoice;				// To store the mission 'A' or 'B' or 'C' or 'D'
uint32_t timeMin;									// To store the minutes
uint32_t timeSec;									// To store the total time in seconds	
char timeArray[] = "00:00";				// Each index is used to store the digit entered in each time 
char weight;											// To store the weight entered in set kilo state

void microwave_init(void)
{
	lcd_init(); 		//lcd initialization ports
	keypad_init();  //keypad initialization ports
	tools_init(); 	// tools initialization ports
}

void choose_mission(void)
{ 
	lcd_clear();
	lcd_display("Choose Mission:");
	missionChoice = keypad_get_input(); //To store mission choice entered by keypad
	lcd_display(&missionChoice);				// Print character that user choosed
	delay(MILLI_SECOND, 200);						//For safty not to enter the same character chosen as a kilo value (Invalid input)
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
	choose_mission();
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
	uint8_t i,j;			// Use i,j in nested for loop		
	// Print "Cooking Time" then ask the user to to enter the time from right to left
	lcd_clear();
	lcd_display("Cooking Time");
	lcd_setposition(2, 7);
	lcd_display(timeArray);
	//Enter a value in field 11 on LCD
	for(i = 1; i < 5; i++)
	{
		lcd_shiftL(1);
		for(j = 1; j < 5; j++)
		{
			if(j == 3)
				timeArray[j-2] = timeArray[j];
			else if(j == 2)
				continue;
			else
					timeArray[j-1] = timeArray[j];
		}
		timeArray[j-1]= keypad_get_input();
		lcd_setposition(2,7);
		lcd_display(timeArray);
	}
}

void set_kilo(void)
{
	weight = keypad_get_input(); //Store user's input from keypad in weight variable
	lcd_data(weight); //print weight on the screen
	//Case of weight validation
	if(weight >= '1' && weight <= '9')
	{
		valid_weight();
	}
	else //Case of weight invalidation
	{
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
}

void valid_weight()
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

void calc_time()
{
	// The time depends on the mission
  switch(missionChoice)
  {
    case POPCORN:
    timeSec = 60;						// Total time in seconds = 60
		timeMin = 1;						//Total time in minutes = 1
    break;
    case BEAF:
    timeSec = (weight - '0') * BEAF_SECONDS_PER_KILO;			// timeSec = weight * 0.5 * 60 
		timeMin = (timeSec / 60);						// Store Minutes in timeMin variable 
    break;
    case CHICKEN:
    timeSec = (weight - '0') * CHICKEN_SECONDS_PER_KILO;	// timeSec = weight * 0.2 * 60 
		timeMin = (timeSec / 60);						// Store Minutes in timeMin variable
    break;
  }
}

void display_time(void)
{
	// Divide the timer into four timers as follows	
	uint8_t timer1, timer2, timer3, timer4;
	// timer1	 timer2		 timer3	timer4
	//	 0       0    :    0       0

	if(missionChoice == POPCORN || missionChoice == BEAF || missionChoice == CHICKEN)
	{
		timer1 = timeMin / 10;							// Tens of Minutes
		timer2 = timeMin % 10;							// Ones of Minutes
		timer3 = (timeSec % 60) / 10;				// Tens of Seconds
		timer4 = (timeSec % 60) %10;				// Ones of Seconds
	}
	else if(missionChoice == SET_TIME)
	{
		timer1 = timeArray[0] - '0';				// Tens of Minutes
		timer2 = timeArray[1] - '0';				// Ones of Minutes
		timer3 = timeArray[3] - '0';				// Tens of Seconds
		timer4 = timeArray[4] - '0';				// Ones of Seconds
	}
	lcd_clear();			//Clear LCD
	timer4 += 1;			//Increment timer4 by one only one time before the do-while loop
	
	// Display the time remaining
	do
	{
		lcd_setposition(2, 7);		//Set the cursor in the middle of LCD 
		
		timer4 -= 1;							//Decrement timer4 in the first
		//Note if timer1,2,3,4 = 0 - 1 --> they will be 255 as they are unsigned integers
		if(timer4 == 255)	timer4 = 9;	//If timer4 = 0 - 1 = 255 --> reset timer4 to 9
		if(timer4 == 9)	timer3 -= 1;	//If timer4 = 9 --> decrement timer3 by one
		if(timer3 == 255)	timer3 = 5;	//If timer3 = 0 - 1 = 255 --> reset timer3 to 5
		if(timer3 == 5 && timer4 == 9 && timer2 != 0)	timer2 -= 1;	//if seconds on LCD = 59 and timer2 != 0 --> decrement timer2 by one
		if(timer2 == 255) timer2 = 9;	//If timer2 = 0 - 1 = 255 --> reset timer2 to 9
		if(timer2 == 9)	timer1 -= 1;	//If timer2 = 9 --> decrement timer1 by one
		
		delay(SECOND, 1);				//To wait one second on LCD
		
		//Display Timer on LCD in the form 00:00
		lcd_display(integer_to_string(timer1));
		lcd_display(integer_to_string(timer2));
		lcd_display(":");
		lcd_display(integer_to_string(timer3));
		lcd_display(integer_to_string(timer4));
		
	}while((timer1 != 0 || timer2 != 0 || timer3 != 0 || timer4 != 0)); //Exit if all timers = 0
}

void cooking()
{
	leds_on();
	calc_time();		// Calculate the time according to number of kilos entered
	display_time();
}

void finish_cooking(void)
{
	// LEDs, LCD blink three times with buzzer
	uint8_t i;
	for (i = 0 ;i < BLINK_FINISH_COOKING; i++)
	{
		leds_on();
		buzzer_on();
		lcd_blink("00:00");
		lcd_clear();
		delay(MILLI_SECOND,DELAY_FINISH_COOKING);
		leds_off();
		buzzer_off();
		lcd_blink("00:00");
		lcd_clear();
		delay(MILLI_SECOND,DELAY_FINISH_COOKING);
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
