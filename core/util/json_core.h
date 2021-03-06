/*©mit**************************************************************************
*                                                                              *
* This file is part of FRIEND UNIFYING PLATFORM.                               *
* Copyright 2014-2017 Friend Software Labs AS                                  *
*                                                                              *
* Permission is hereby granted, free of charge, to any person obtaining a copy *
* of this software and associated documentation files (the "Software"), to     *
* deal in the Software without restriction, including without limitation the   *
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  *
* sell copies of the Software, and to permit persons to whom the Software is   *
* furnished to do so, subject to the following conditions:                     *
*                                                                              *
* The above copyright notice and this permission notice shall be included in   *
* all copies or substantial portions of the Software.                          *
*                                                                              *
* This program is distributed in the hope that it will be useful,              *
* but WITHOUT ANY WARRANTY; without even the implied warranty of               *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                 *
* MIT License for more details.                                                *
*                                                                              *
*****************************************************************************©*/
#ifndef __UTIL_JSON_H__
#define __UTIL_JSON_H__

#define JSON_TYPE_NONE       0x00000000
#define JSON_TYPE_ARRAY      0x00000001
#define JSON_TYPE_OBJECT     0x00000002
#define JSON_TYPE_VALUE      0x00000004

#define JSON_TYPE_FBOOL       0x00000008
#define JSON_TYPE_NULL       0x00000010
#define JSON_TYPE_NUMBER     0x00000020
#define JSON_TYPE_STRING     0x00000040
#define JSON_TYPE_ERROR      0x00000080

#define JSON_TYPE_COLON      0x00000100
#define JSON_TYPE_COMMA      0x00000200
#define JSON_TYPE_ARRAY_END  0x00000400
#define JSON_TYPE_OBJECT_END 0x00000800

#define JSON_TYPE_ARRAY_LIST 0x00001000

#define JSON_ERROR_NONE                 0
#define JSON_ERROR_INVALID_LITERAL_NAME 1
#define JSON_ERROR_UNEXPECTED_CHARACTER 2

#define JSON_NESTED_SIZE 50

//
//
//

typedef struct JSONError
{
	unsigned char error;
	unsigned int line;
	unsigned int column;
} JSONError;

//
//
//

typedef struct JSONArray
{
	List* first;
	List* last;
} JSONArray;

//
//
//

typedef struct JSONData
{
	unsigned int type;
	unsigned int size;
	void* data;
} JSONData;

//
//
//

void JSONFree( JSONData* document );

//
//
//

JSONData* JSONParse( char* str, unsigned int length );

#endif