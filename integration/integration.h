#ifndef INTEGRATION_H
#define INTEGRATION_H

typedef enum mission
{
	POPCORN,
	BEAF,
	CHICKEN,
	SET_TIME
}mission;

void choose_mission();
void invalid_mission();
void popcorn();
void beaf();
void chicken();
void set_time();

#endif


