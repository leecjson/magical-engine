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
#include "LogSystem.h"

#include <windows.h>

static void win32Log( const char* title, const char* msg );

void Log::init( void )
{
	
}

void Log::delc( void )
{
	
}

void Log::D( const char* msg )
{
	if( msg == nullptr )
		return;

	win32Log( kLogChannelDebugTitle, msg );
}

void Log::E( const char* msg )
{
	if( msg == nullptr )
		return;

	win32Log( kLogChannelErrorTitle, msg );
}

static void win32Log( const char* title, const char* msg )
{
	static char buff[ kMaxBufferLength ];

	tm tm_now;
	time_t now;
	time( &now );
	tm_now = *localtime( &now );

	std::sprintf( buff, "[%s %02d/%02d %02d:%02d:%02d]: %s",
		title,
		tm_now.tm_mon + 1,
		tm_now.tm_mday,
		tm_now.tm_hour,
		tm_now.tm_min,
		tm_now.tm_sec,
		msg );

	OutputDebugStringA( buff );
	OutputDebugStringA( "\n" );
	printf( "%s\n", buff );
}