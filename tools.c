#include "Io.h"
#include "tm4c123gh6pm.h"
//buzeer a3//
//button a2//
//leds f1 f2 f3//
//SW2 F0//
//SW1 F4//
void SystemInit();
void ENABLE_PORTF_AND_A()//enable port f and port a//
	{
	SYSCTL_RCGCGPIO_R |=0x21;}
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
//cooking is finished function as buzzer turn on for three seconds and leds blink each second//
void Finish()
{
	GPIO_PORTA_DATA_R=0X08;
	GPIO_PORTF_DATA_R=0x0E;
	delay(100,1ms);
	GPIO_PORTF_DATA_R^= GPIO_PORTF_DATA_R;
	delay(100,1ms);
	GPIO_PORTF_DATA_R^= GPIO_PORTF_DATA_R;
	delay(1000,1ms);
	GPIO_PORTF_DATA_R^= GPIO_PORTF_DATA_R;
	delay(100,1ms);
	GPIO_PORTF_DATA_R^= GPIO_PORTF_DATA_R;
	delay(1000,1ms);
	GPIO_PORTF_DATA_R^= GPIO_PORTF_DATA_R;
	delay(100,1ms);
	GPIO_PORTF_DATA_R^= GPIO_PORTF_DATA_R;
	delay(1000,1ms);
	GPIO_PORTA_DATA_R=0XFF;
	GPIO_PORTF_DATA_R^=GPIO_PORTF_DATA_R;
}
//usage of Push button//
void GPIOA_Handler(void)
{  if ((GPIOA->MIS&0x04)!=0x04)
	Pause();
	GPIOA->ICR |= 0x04;
}
//usage of SW1 and SW2 buttons//
void GPIOF_Handler(void){
	   //SW2 is pushed for 1st time and start cooking and leds turn on//
      if ((GPIOF->MIS&0x11)==0x01)
	      {
					GPIO_PORTF_DATA_R=0x0E;	
					//SW1 is pushed for 1st time and pause cooking//
					if ((GPIOF->MIS&0X11)==0X11)
					{
						Pause();
						//SW1 is pushed for 2nd time and stop cooking and leds turn off//
					if((GPIOF->MIS&0x11)==0x01)
        {
					lcd_clear();
					GPIO_PORTF_DATA_R=0x00;	
					GPIOF->ICR |= (1<<0);
        }
				//SW2 is pushed for 2nd time after 1st time of SW1 is pushed which resume cooking after pause cooking//
				else if((GPIOF->MIS&0x11)==0x10)
                {
									Resume();
									Finish();
									GPIOF->ICR |= (1<<4);
								}
			}
		}
	}