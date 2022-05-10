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
#include "../standard_types.h"

#ifndef KEYPAD_H
#define KEYPAD_H

// initializing ports and pins needed by keypad
void Init_Keypad_Ports(void); 
// initiallizing port C
void Init_PortC4_7(void);
// initiallizing port D
void Init_PortD0_3(void);
// return value of corresponding pressed key
char KeyPad_Get_Input(void);

#endif
