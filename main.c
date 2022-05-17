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
	choose_mission();
	cooking();
	finish_cooking();
	while (1)
	{
		
	}
}
