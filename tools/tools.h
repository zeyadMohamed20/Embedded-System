#ifndef TOOLS_H
#define TOOLS_H
//buzzer a3//
//push button a2//
//leds f1 f2 f3//
//SW2 F0//
//SW1 F4//
void enable_portf_and_a();//enable ports f and port a
void portf(); //initiallizing port f
void porta();//initiallizing port a
void GPIOF_Handler(); //interrupt SW1 , SW2//
void GPIOA_Handler(); //interrupt push button//
void leds_on();
void leds_off();
void buzzer_on();
void buzzer_off();	
void leds_blink(uint8_t NumberOfBlink,uint8_t OnDelay,uint32_t delayTimeOn,uint8_t OffDelay,uint32_t delayTimeOff);
#endif // !TOOLS_H
