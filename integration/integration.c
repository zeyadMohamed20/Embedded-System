#include "integration.h"
#include "../lcd/lcd.h"
#include "../keypad/keypad.h"

void choose_mission()
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

void invalid_mission()
{
}

void popcorn()
{
	lcd_display("Popcorn");
}

void beaf()
{
}

void chicken()
{
}

void set_time()
{
}
