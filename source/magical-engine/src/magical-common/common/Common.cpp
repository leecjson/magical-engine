/******************************************************************************
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
#include "Common.h"
/*
platform include
*/
#ifdef MAGICAL_WIN32
#include <windows.h>
#endif

char g_buffer[ kMaxBufferLength ];

static bool s_last_error = false;
static char s_last_error_info[ kMaxBufferLength ];

#ifdef MAGICAL_DEBUG
bool g_is_observing = false;
int g_observer_move_construct_count = 0;
int g_observer_copy_construct_count = 0;
int g_observer_construct_count = 0;
int g_observer_destruct_count = 0;
#endif

MAGICALAPI bool magicalIsError( void )
{
	return s_last_error;
}

MAGICALAPI void magicalIgnoreLastError( void )
{
	s_last_error = false;
}

MAGICALAPI void magicalSetLastErrorInfo( const char* info, const char* func, int line )
{
	if( info == nullptr )
		return;

	if( func )
	{
		sprintf( s_last_error_info, "%s %s:%d", info, func, line );
	}
	else
	{
		strcpy( s_last_error_info, info );
	}

	s_last_error = true;
}

MAGICALAPI const char* magicalGetLastErrorInfo( void )
{
	if( strlen(s_last_error_info) > 0 )
	{
		return s_last_error_info;
	}
	else
	{
		return "none";
	}
}

#ifdef MAGICAL_WIN32
MAGICALAPI void magicalMessageBox( const char* msg, const char* title )
{
	MessageBoxA( nullptr, msg, title, MB_OK );
}
#endif