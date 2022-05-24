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
#include "../interrupt/interrupt.h"
#include "../keypad/keypad.h"
#include "../lcd/lcd.h"
#include "../tools/tools.h"
#include "../timer/timer.h"
#include "../struct_enum.h"
#include "../macros.h"
#include "../utility/util.h"

//Global variables
volatile char currentState;		// To store the current state like (Cookig, invalid weight, beaf, etc..)
volatile char timeArray[] = "00:00";				// Each index is used to store the digit entered in each time
volatile uint8_t interruptFlag;			
volatile uint8_t switch1Press;

static char missionChoice;		// To store the mission 'A' or 'B' or 'C' or 'D' 
static uint32_t timeMin;									// To store the minutes
static uint32_t timeSec;									// To store the total time in seconds	
static char weight;
static uint8_t endProgram;

void microwave_init(void)
{
	lcd_init(); 		//lcd initialization ports
	keypad_init();  //keypad initialization ports
	tools_init(); 	// tools initialization ports
	interrupt_init(); //Interrupt initialization registers
	variables_init();
}

void variables_init(void)
{
	currentState = CHOOSE_MISSION;		
	interruptFlag = 0;
	switch1Press = 0;
	missionChoice = '\0';		
	timeMin = 0;									
	timeSec = 0;									
	weight = 0;
	endProgram = 0;
}


void choose_mission(void)
{ 
	variables_init();
	currentState = CHOOSE_MISSION;
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
				currentState = INVALID_MISSION;
				invalid_mission();
				break;
		}
	}while(currentState == INVALID_MISSION);
}

void invalid_mission(void)
{
	currentState = INVALID_MISSION;
	//Print invalid input for 2 sec on LCD
	lcd_clear();
	lcd_display("Invalid Input");
	delay(SECOND,2);
	choose_mission();
}

void popcorn(void)
{
	missionChoice = POPCORN;
	currentState = POPCORN;
	//Print "popcorn" for 2 sec on LCD
	lcd_clear();
	lcd_display("Popcorn");
	delay(SECOND,2);
	cooking();
}

void beaf(void)
{
	missionChoice = BEAF;
	currentState = BEAF;
	//Print "Beef Weight" then ask the user about weight
	lcd_clear();
	lcd_display("Beef Weight:");
	set_kilo();
	cooking();
}

void chicken(void)
{
	missionChoice = CHICKEN;
	currentState = CHICKEN;
	//Print "Chicken Weight:" then ask the user about weight
	lcd_clear();
	lcd_display("Chicken Weight:");
	set_kilo();
	cooking();
}

void set_kilo(void)
{
	currentState = SET_KILO;
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
	currentState = VALID_WEIGHT;
	//Clear the display then print the weight value entered by the user for 2 seconds
	lcd_clear();
	lcd_display("Weight Value:");
	lcd_display(&weight);
	delay(SECOND,2);
}

void invalid_weight(void)
{
	currentState = INVALID_WEIGHT;
	//Print error for 2 seconds
	lcd_clear();
	lcd_display("Err");
	delay(SECOND,2);
}

void set_time_init()
{
// Print "Cooking Time" then ask the user to to enter the time from right to left
	lcd_clear();
	lcd_display("Cooking Time");
	clear_time_array();
	lcd_setposition(2,7);
	lcd_display(timeArray);
}

void set_time(void)
{
	uint8_t i = 1, j;// Use i,j in nested for loop
	char input;
	currentState = SET_TIME;
	
	// Print "Cooking Time" then ask the user to to enter the time from right to left
	lcd_clear();
	lcd_display("Cooking Time");
	clear_time_array();
	lcd_setposition(2,7);
	lcd_display(timeArray);
	//Enter a value in field 11 on LCD
	do
	{
		lcd_shiftL(1);
		input = keypad_get_input();
		
		if((GPIO_PORTF_DATA_R & 0x01) == 0) // If Sw2 pressed
			break;			// Exit from the loop

		if(i == 2)
		{
			timeArray[3]=timeArray[4];
		}
		else if(i == 3)
		{
			timeArray[1]=timeArray[3];
			timeArray[3]=timeArray[4];
		}
		else if(i == 4)
		{
			timeArray[0]=timeArray[1];
			timeArray[1]=timeArray[3];
			timeArray[3]=timeArray[4];
		}

		else if(i > 4)				
		{
			i = 1;
			set_time_init();
		}

		if(interruptFlag)
		{
			interruptFlag = 0;
		}
		timeArray[4] = input;
		lcd_setposition(2,7);
		lcd_display(timeArray);
		i++;
	}while((GPIO_PORTF_DATA_R & (1 << 0)) == 1);	// stay in the loop until sw2 pressed
	cooking();		
}



void invalid_time(void)
{
	lcd_clear();
	lcd_display("Invalid Time");
	delay(SECOND, 2);
	set_time();
}

void calc_time(void)
{
	currentState = COOKING;
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
		default:					
			timeSec = timeArray[0] * 10 * 60 + timeArray[1] * 60 + timeArray[3] * 10 + timeArray[4];
			timeMin = timeArray[0] * 10 * 60 + timeArray[1] * 60;
		break;
  }
}

void display_time(void)
{
	uint8_t entryFlag = 1;
	uint8_t timer1, timer2, timer3, timer4;		//Divide timer into four digits, each variable store one digit
	// timer1	 timer2		 timer3	timer4
	//	 0       0    :    0       0
	currentState = COOKING;
	if(missionChoice == POPCORN || missionChoice == BEAF || missionChoice == CHICKEN)
	{
		timer1 = timeMin / 10;						// Tens of Minutes
		timer2 = timeMin % 10;						// Ones of Minutes
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
	
	// Display the time remaining
	do
	{
		currentState = COOKING;
		if(entryFlag == 0) timer4 -= 1;							//Decrement timer4 if the isnt in the first time 
		//Note if timer1,2,3,4 = 0 - 1 --> they will be 255 as they are unsigned integers
		if(timer4 == 255)	timer4 = 9;	//If timer4 = 0 - 1 = 255 --> reset timer4 to 9
		if(timer4 == 9 && entryFlag == 0)	timer3 -= 1;	//If timer4 = 9 --> decrement timer3 by one
		if(timer3 == 255)	timer3 = 5;	//If timer3 = 0 - 1 = 255 --> reset timer3 to 5
		if(timer3 == 5 && timer4 == 9 && entryFlag == 0)	timer2 -= 1;	//if seconds on LCD = 59 and timer2 != 0 --> decrement timer2 by one
		if(timer2 == 255) timer2 = 9;	//If timer2 = 0 - 1 = 255 --> reset timer2 to 9
		if(timer2 == 9 && timer1 != 0)	timer1 -= 1;	//If timer2 = 9 --> decrement timer1 by one
		if(entryFlag == 1) entryFlag = 0;
		
		delay(SECOND, 1);				//To wait one second on LCD
		
		//Display Timer on LCD in the form 00:00
				
		lcd_setposition(2, 7);				//Set the cursor in the middle of LCD 
		lcd_display(integer_to_string(timer1));
		lcd_display(integer_to_string(timer2));
		lcd_display(":");
		lcd_display(integer_to_string(timer3));
		lcd_display(integer_to_string(timer4));
		
		if(endProgram == 1)
			break;
		
	}while((timer1 != 0 || timer2 != 0 || timer3 != 0 || timer4 != 0)); //Exit if all timers = 0
	if(currentState != CANCEL_COOKING)
		finish_cooking();
}

void cooking(void)
{
	currentState = COOKING;
	leds_on();
	calc_time();		// Calculate the time according to number of kilos entered
	display_time();
}

void resume(void)
{			
	currentState = COOKING;	
	switch1Press = 0;
}

void pause(void)
{
	currentState = PAUSE;
	switch1Press = 1;
	leds_off();
	lcd_setposition(1, 7);
	lcd_display("Pause");
	delay(MILLI_SECOND, 200);
	leds_on();
	lcd_setposition(1, 1);
	lcd_display("                ");
	delay(MILLI_SECOND, 200);
	if((GPIO_PORTF_DATA_R & 0x10) == 0)		// If sw1 is pressed for the second time
		switch1Press = 2;
}
void finish_cooking(void)
{
	uint8_t i;
	currentState = FINISH_COOKING;
	// LEDs, LCD blink three times with buzzer
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

void cancel_cooking(void)
{
	currentState = CANCEL_COOKING;
	switch1Press = 0;
	leds_off();
	lcd_setposition(1, 5);
	lcd_display("Cancelled");
	delay(SECOND, 2);
	lcd_clear();
	endProgram = 1;
}


void door_opened(void)
{
	currentState = DOOR_OPENED;
	leds_off();
	lcd_setposition(1, 2);
	lcd_display("Close The Door");
	delay(MILLI_SECOND, 200);
	leds_on();
	lcd_setposition(1, 1);
	lcd_display("                ");
	delay(MILLI_SECOND, 400);		
}
