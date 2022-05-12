#ifndef TOOLS_H
#define TOOLS_H
#include "../macros.h"
#include "../standards_types.h"
//buzzer a3//
//push button a2//
//leds f1 f2 f3//
//SW2 F0//
//SW1 F4//
void ENABLE_PORTF_AND_A();//enable ports f and port a
void PORTF(); //initiallizing port f
void PORTA();//initiallizing port a
void GPIOF_Handler(void); //interrupt SW1 , SW2//
void GPIOA_Handler(void); //interrupt push button//
void Leds_On();
void Leds_Off();
void Buzzer_On();
void Buzeer_off();	
void Leds_Blink(uint8_t NumberOfBlink,uint8_t OnDelay,uint32_t delayTimeOn,uint8_t OffDelay,uint32_t delayTimeOff);
#endif // !TOOLS_H
