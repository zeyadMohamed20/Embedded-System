#include "integration/integration.h"
#include "lcd/lcd.h"
#include "timer/timer.h"
void SystemInit()
{
}
int main()
{
	microwave_init();
	
	choose_mission();
	cooking();
	while (1)
	{
		
	}
}