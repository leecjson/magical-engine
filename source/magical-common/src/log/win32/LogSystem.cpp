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
#include "PlatformMacros.h"
#include "LogSystem.h"
<<<<<<< HEAD
#include "Common.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <WinSock2.h>

#ifdef MAG_DEBUG
=======

#include "Common.h"
#include <windows.h>
>>>>>>> origin/master

static void win32Log( const char* channel, const char* msg )
{
	char buf[ kMaxLogLength ];
	struct tm tm_now;
	time_t now;

	time( &now );
	tm_now = *localtime( &now );

	sprintf(buf, "[%s %02d/%02d %02d:%02d:%02d]: %s",
		channel,
		tm_now.tm_mon + 1,
		tm_now.tm_mday,
		tm_now.tm_hour,
		tm_now.tm_min,
		tm_now.tm_sec,
		msg);

	OutputDebugStringA( buf);
    OutputDebugStringA("\n");
	printf("%s\n", buf);
}

#endif

void LogSystem::init( void )
{
	
}

void LogSystem::delc( void )
{
	
}

void LogSystem::I( const char* msg )
{
<<<<<<< HEAD
#ifdef MAG_DEBUG
	win32Log("Info ", msg);
#endif
=======
	magicalAssert( msg, "should not nullptr" );
	win32Log( "Info", msg );
>>>>>>> origin/master
}

void LogSystem::D( const char* msg )
{
<<<<<<< HEAD
#ifdef MAG_DEBUG
	win32Log("Debug", msg);
#endif
=======
	magicalAssert( msg, "should not nullptr" );
	win32Log( "Debug", msg );
>>>>>>> origin/master
}

void LogSystem::E( const char* msg )
{
<<<<<<< HEAD
#ifdef MAG_DEBUG
	win32Log("Error", msg);
#endif
=======
	magicalAssert( msg, "should not nullptr" );
	win32Log( "Error", msg );
>>>>>>> origin/master
}