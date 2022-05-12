#include "../macros.h"
#include "../timer/timer.h"
#include "tools.h"
//buzzer a3//
//push button a2//
//leds f1 f2 f3//
//SW2 F0//
//SW1 F4//
//enable port f and port a//
void ENABLE_PORTF_AND_A()
	{
	SYSCTL_RCGCGPIO_R |=0x21;
	}
//initiallization port f//
	void PORTF(){
		GPIO_PORTF_LOCK_R= 0x4C4F434B;
GPIO_PORTF_CR_R=0x1F;
	GPIO_PORTF_AMSEL_R=0;
	GPIO_PORTF_PCTL_R=0;
	GPIO_PORTF_AFSEL_R=0;
	GPIO_PORTF_DIR_R=0x1E;
	GPIO_PORTF_DEN_R=0x1F;
	GPIO_PORTF_PUR_R=0x11;
	GPIOF->ICR |= (1<<4)|(1<<0);
}
//initiallization port a	
void portA()
{
GPIO_PORTA_LOCK_R= 0x4C4F434B;
GPIO_PORTA_CR_R=0x1F;
	GPIO_PORTA_AMSEL_R=0;
	GPIO_PORTA_PCTL_R=0;
	GPIO_PORTA_AFSEL_R=0;
	GPIO_PORTA_DIR_R=0x1E;
	GPIO_PORTA_DEN_R=0x1F;
	GPIO_PORTA_PUR_R=0x11;
	GPIOA->ICR |= (1<<2);
}
//usage of Push button//
void GPIOA_Handler(void)
{  if ((GPIOA->MIS&0x04)!=0x04)
	pause();
	GPIOA->ICR |= 0x04;
}
//usage of SW1 and SW2 buttons//
void GPIOF_Handler(void){
	   //SW2 is pushed for 1st time and start cooking and leds turn on//
      if ((GPIOF->MIS&0x11)==0x01)
	      {
					Leds_On();	
					//SW1 is pushed for 1st time and pause cooking//
					if ((GPIOF->MIS&0X11)==0X11)
					{
						pause();
						//SW1 is pushed for 2nd time and stop cooking and leds turn off//
					if((GPIOF->MIS&0x11)==0x01)
        {
					lcd_clear();
					Leds_Off();	
					GPIOF->ICR |= (1<<0);
        }
				//SW2 is pushed for 2nd time after 1st time of SW1 is pushed which resume cooking after pause cooking//
				else if((GPIOF->MIS&0x11)==0x10)
                {
									resume();
									Leds_On();
									GPIOF->ICR |= (1<<4);
								}
			}
		}
	}
//turn on leds//
void Leds_On()
	{
		GPIO_PORTF_DATA_R=0X0E;
}
//turn off leds//
void Leds_Off()
{
	GPIO_PORTF_DATA_R^=0X0E;
}
//turn on buzzer//
void Buzzer_On()
{
	GPIO_PORTA_DATA_R=0x08;
}
//turn off buzzer//
void Buzeer_off()
{
	GPIO_PORTA_DATA_R^=0X08;
}
//determine time of leds blinking//
void Leds_Blink(uint8_t NumberOfBlink,uint8_t OnDelay,uint32_t delayTimeOn,uint8_t OffDelay,uint32_t delayTimeOff)
{
for (uint8_t i=0;i<NumberOfBlink;i++)
{
Leds_On();
delay(Ondelay,delayTimeOn);
Leds_Off();
delay(Offdelay,delayTimeOff); 	
}
}
