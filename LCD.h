#include"macros.h"
#include"standard_types.h"

//********** Functions Prototype ***************
void SystemInit(void);
void timer(uint32_t milliSeconds);
void delay(uint32_t milliSeconds);
void lcd_cmd(char command);
void lcd_data(char data);
void lcd_init(void);
void lcd_clear(void);
void lcd_secline(void);
void lcd_display(char *str);
void lcd_setposition(uint16_t row,uint16_t col);

//**********************************************

