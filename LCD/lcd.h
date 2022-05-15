#ifndef LCD_H
#define LCD_H

#include"../standard_types.h"
#include"../macros.h"
<<<<<<< HEAD

//********** Functions Prototype ***************
void SystemInit(void);
void timer(uint32_t milliSeconds);
void delay(uint32_t milliSeconds);
=======
#include"../timer/timer.h"
#include"../tools/tools.h"

//********** Functions Prototype ***************
void SystemInit(void);
>>>>>>> testing
void lcd_cmd(char command);
void lcd_data(char data);
void lcd_init(void);
void lcd_clear(void);
void lcd_secline(void);
void lcd_display(char *str);
void lcd_setposition(uint16_t row,uint16_t col);
void lcd_shiftR(uint32_t shift);
void lcd_shiftL(uint32_t shift);
<<<<<<< HEAD
//**********************************************

#endif
=======
void lcd_blink(char *str);
//**********************************************

#endif
>>>>>>> testing
