/*
 **************************************************************************************************************************
@file     lcd.h
@brief    This file defines the bodies of functions which defines the driver of lcd
@version  V1.00
@date     12. May 2022
@team     LCD Team
Copyright (C) 2022. All rights reserved.
******************************************************************************************************************************
*/

#ifndef LCD_H
#define LCD_H

#include "../standard_types.h"

//********** Functions Prototype ***************
void lcd_init(void);
void portA_init(void);
void portB_init(void);
void command_init(void);
void lcd_cmd(char command);
void lcd_data(char data);
void lcd_clear(void);
void lcd_secline(void);
void lcd_display(volatile char *str);
void lcd_setposition(uint16_t row,uint16_t col);
void lcd_shiftR(uint32_t shift);
void lcd_shiftL(uint32_t shift);
void lcd_blink(char *str);

//**********************************************
#endif
