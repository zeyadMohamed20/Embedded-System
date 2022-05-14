#include "../macros.h"
#include "../timer/timer.h"
#include "tools.h"
#include"../LCD/lcd.h"
//buzzer a3//
//push button a2//
//leds f1 f2 f3//
//SW2 F0//
//SW1 F4//
//enable port f and port a//
void enable_portf_and_a()
	{
	SYSCTL_RCGCGPIO_R |=0x21;
	}
//initiallization port f//
	void portf(){
		GPIO_PORTF_LOCK_R= 0x4C4F434B;
GPIO_PORTF_CR_R=0x1F;
	GPIO_PORTF_AMSEL_R=0;
	GPIO_PORTF_PCTL_R=0;
	GPIO_PORTF_AFSEL_R=0;
	GPIO_PORTF_DIR_R=0x1E;
	GPIO_PORTF_DEN_R=0x1F;
	GPIO_PORTF_PUR_R=0x11;
	GPIO_PORTF_ICR_R |= (1<<4)|(1<<0);
}
//initiallization port a	
void porta()
{
GPIO_PORTA_LOCK_R= 0x4C4F434B;
GPIO_PORTA_CR_R=0x1F;
	GPIO_PORTA_AMSEL_R=0;
	GPIO_PORTA_PCTL_R=0;
	GPIO_PORTA_AFSEL_R=0;
	GPIO_PORTA_DIR_R=0x1E;
	GPIO_PORTA_DEN_R=0x1F;
	GPIO_PORTA_PUR_R=0x11;
	GPIO_PORTA_ICR_R |= (1<<2);
}
//usage of Push button as Interrupt//
void GPIOA_Handler(void)
{  if ((GPIO_PORTA_MIS_R&0x04)!=0x04)
	pause();
	GPIO_PORTA_ICR_R  |= 0x04;
}
//usage of SW1 and SW2 buttons as interrupt//
void GPIOF_Handler(void){
	   //SW2 is pushed for 1st time and start cooking and leds turn on//
      if ((GPIO_PORTF_MIS_R &0x11)==0x01)
	      {
					leds_on();	
					//SW1 is pushed for 1st time and pause cooking//
					if ((GPIO_PORTF_MIS_R &0X11)==0X11)
					{
						pause();
						//SW1 is pushed for 2nd time and stop cooking and leds turn off//
					if((GPIO_PORTF_MIS_R & 0x11)==0x01)
        {
					lcd_clear();
					leds_off();	
					GPIO_PORTF_ICR_R  |= (1<<0);
        }
				//SW2 is pushed for 2nd time after 1st time of SW1 is pushed which resume cooking after pause cooking//
				else if((GPIO_PORTF_MIS_R &0x11)==0x10)
                {
									resume();
									leds_on();
									GPIO_PORTF_ICR_R |= (1<<4);
								}
			}
		}
	}
//turn on leds//
void leds_on()
	{
		GPIO_PORTF_DATA_R=0X0E;
}
//turn off leds//
void leds_off()
{
	GPIO_PORTF_DATA_R^=0X0E;
}
//turn on buzzer//
void buzzer_on()
{
	GPIO_PORTA_DATA_R=0x08;
}
//turn off buzzer//
void buzeer_off()
{
	GPIO_PORTA_DATA_R^=0X08;
}
//determine time of leds blinking//
void leds_blink(uint8_t NumberOfBlink,uint8_t OnDelay,uint32_t delayTimeOn,uint8_t OffDelay,uint32_t delayTimeOff)
{
	uint8_t i;
for (i=0;i<NumberOfBlink;i++)
{
leds_on();
delay(OnDelay,delayTimeOn);
leds_off();
delay(OffDelay,delayTimeOff); 	
}
}
