#include "integration/integration.h"
#include "lcd/lcd.h"
#include "timer/timer.h"
#include "tools/tools.h"

void SystemInit()
{
}
int main()
{
	microwave_init();
	while (1)
	{	
		choose_mission();
	}
}
