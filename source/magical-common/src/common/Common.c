﻿/******************************************************************************
The MIT License (MIT)

Copyright (c) 2014 Jason.lee

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/
#include "PlatformMacros.h"
#include "Common.h"

#include <stdlib.h>
#include <string.h>

int   s_last_error = false;
char* s_last_error_info = NULL;

MAGAPI int maigcalIsError( void )
{
	return s_last_error;
}

MAGAPI void magicalIgnoreLastError( void )
{
	s_last_error = false;
}

MAGAPI const char* magicalSetLastErrorInfo( const char* info )
{
	if( s_last_error_info )
	{
		free(s_last_error_info);
	}

	s_last_error_info = (char*) malloc(strlen(info) + 1);
	strcpy(s_last_error_info, info);

	s_last_error = true;

	return magicalGetLastErrorInfo();
}

MAGAPI const char* magicalGetLastErrorInfo( void )
{
	if( s_last_error_info )
	{
		return s_last_error_info;
	}
	else
	{
		return "none";
	}
}