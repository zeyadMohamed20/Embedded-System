#include "integration/integration.h"

//Global variables

void SystemInit()
{
}
int main()
{
	microwave_init();
	while (1)
	{
		choose_mission();
		cooking();
	}
}