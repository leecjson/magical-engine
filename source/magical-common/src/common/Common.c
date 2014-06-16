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
#include "Common.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

MAGAPI_USER void magicalLogImpl( const char* str )
{
	printf("%s", str);
}

MAGAPI void magicalReportImpl( const char* str, const char* function, int line )
{
	char buf[16 * 1024];

	if( function && line > 0 )
	{	
		sprintf(buf, "[Report.%s]: %s", MAG_PLATFORM
	}
	else
	{
		magicalLog(str);
	}
}

static int   s_last_error = false;
static char* s_last_error_info = NULL;

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

#ifdef MAG_WIN32
extern int gettimeofday( struct timeval* tv, struct timezone* tz )
{
	LARGE_INTEGER time;
	LARGE_INTEGER freq;
	if( tv )
    {
        QueryPerformanceFrequency( &freq );
        QueryPerformanceCounter( &time );
        tv->tv_sec  = (long)( time.QuadPart / freq.QuadPart );
        tv->tv_usec = (long)( time.QuadPart * 1000000.0 / freq.QuadPart - tv->tv_sec * 1000000.0 );
    }
    return 0;
}
#endif

static timeval s_tv_timer;

MAGAPI void magicalBeginTimer( void )
{
	if( magicalGetCurrentTime(&s_tv_timer, NULL) != 0 )
	{
		magicalReport(magicalSetLastErrorInfo("[magical-error]: gettimeofday error"));
		return;
	}
}

MAGAPI float magicalEndTimer( void )
{
	static timeval tv_now;

	float result;

	if( gettimeofday(&tv_now, NULL) != 0 )
	{
		magicalSetLastErrorInfo("[magical-error]: gettimeofday error");
		return 0.0f;
	}

	result = (tv_now.tv_sec - s_tv_timer.tv_sec) + (tv_now.tv_usec - s_tv_timer.tv_usec) / 1000000.0f;
	result = MAX(0, result);

	return result;
}