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

void Init_Ports(void);
void Init_PortC(void);
void Init_PortD(void);
char KeyPad_Get_Input(void);

#endif
