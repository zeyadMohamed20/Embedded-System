/*
 ***********************************************************************************************************
@file     standard_types.h
@brief    This file renames the standard data types in c by adding the size to their names
@version  V1.00
@date     7. May 2022
@team     Integration Team
Copyright (C) 2022. All rights reserved.
*************************************************************************************************************
*/

#ifndef STANDARD_TYPES_H
#define STANDARD_TYPES_H

/* exact-width signed integer types */
typedef signed             char int8_t;
typedef signed short       int int16_t;
typedef signed             int int32_t;
typedef signed         __int64 int64_t;

    /* exact-width unsigned integer types */
typedef unsigned           char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;
 
#endif