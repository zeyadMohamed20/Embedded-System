#include "macros.h"
void SystemInit();
void ENABLE_PORTF_AND_A();//enable ports f and port a
void PORTF(); //initiallizing port f
void PORTA();//initiallizing port a
void Finish();//cooking is finished
void GPIOF_Handler(void);
void GPIOA_Handler(void);