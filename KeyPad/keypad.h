/*
 ***********************************************************************************************************
@file     keypad.h
@brief    This file set Prototype Functions of KeyPad like initializations and Key_Search
@version  V1.00
@date     9. May 2022
@team     Keypad Team
Copyright (C) 2022. All rights reserved.
*************************************************************************************************************
*/

#ifndef KEYPAD_H
#define KEYPAD_H

//********** Functions Prototype ***************
// initializing ports and pins needed by keypad
void keypad_init(void); 
// initiallizing port C
void portE_init(void);
// initiallizing port D
void portD_init(void);
// return value of corresponding pressed key
char keypad_get_input(void);
//**********************************************
#endif
