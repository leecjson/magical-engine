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

static bool s_last_error = false;
static char s_last_error_info[kMaxErrLength] = {0};

struct timeval g_tv_ticking;

#ifdef MAG_DEBUG
bool g_is_observing = false;
int  g_observer_construct_count = 0;
int  g_observer_destruct_count = 0;
#endif

#ifdef MAG_DEBUG

MAGAPI void magicalLogImpl( const char* str )
{
#ifdef MAG_WIN32
    OutputDebugStringA(str);
    OutputDebugStringA("\n");
	printf("%s\n", str);
#endif
#ifdef MAG_ANDROID
#endif
#ifdef MAG_IOS
#endif
#ifdef MAG_LINUX
#endif
#ifdef MAG_MAC
#endif
}

MAGAPI void magicalLogFormatImpl( const char* format, ... )
{
	char buf[kMaxLogLength];

	va_list args;
	va_start(args, format);
	vsnprintf(buf, kMaxLogLength, format, args);
	va_end(args);

	magicalLogImpl(buf);
}

#endif

#ifdef MAG_DEBUG

MAGAPI void magicalReportImpl( int level, const char* str, const char* function, int line )
{
	char   buf[ kMaxLogLength ];
#ifdef MAG_WIN32
	struct tm tm_now;
	time_t now;
#endif
#ifdef MAG_ANDROID
#endif
#ifdef MAG_IOS
#endif
#ifdef MAG_LINUX
#endif
#ifdef MAG_MAC
#endif

#ifdef MAG_WIN32
	time( &now );
	tm_now = *localtime( &now );
	switch( level )
	{
	case MAG_REPORT_DEBUG:
		sprintf(buf, "[Report-Debug %02d/%02d %02d:%02d:%02d]: %s",
			tm_now.tm_mon + 1,
			tm_now.tm_mday,
			tm_now.tm_hour,
			tm_now.tm_min,
			tm_now.tm_sec,
			str);
		break;
	case MAG_REPORT_ERROR:
		sprintf(buf, "[Report-Error %02d/%02d %02d:%02d:%02d]: %s  ( %s:%d )",
			tm_now.tm_mon + 1,
			tm_now.tm_mday,
			tm_now.tm_hour,
			tm_now.tm_min,
			tm_now.tm_sec,
			str,
			function, 
			line);
		break;
	}
    OutputDebugStringA(buf);
    OutputDebugStringA("\n");
	printf("%s\n", buf);
#endif
#ifdef MAG_ANDROID
#endif
#ifdef MAG_IOS
#endif
#ifdef MAG_LINUX
#endif
#ifdef MAG_MAC
#endif
}

#endif

MAGAPI bool magicalIsError( void )
{
	return s_last_error;
}

MAGAPI void magicalIgnoreLastError( void )
{
	s_last_error = false;
}

MAGAPI const char* magicalSetLastErrorInfo( const char* info )
{
	strcpy(s_last_error_info, info);
	s_last_error = true;

	return magicalGetLastErrorInfo();
}

MAGAPI const char* magicalGetLastErrorInfo( void )
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

#ifdef MAG_WIN32

extern "C" int gettimeofday( struct timeval* tv, struct timezone* tz )
{
	LARGE_INTEGER time, freq;
	if( tv != NULL )
    {
        QueryPerformanceFrequency( &freq );
        QueryPerformanceCounter( &time );
        tv->tv_sec  = (long)( time.QuadPart / freq.QuadPart );
        tv->tv_usec = (long)( time.QuadPart * 1000000.0 / freq.QuadPart - tv->tv_sec * 1000000.0 );
    }
	return 0;
}

#endif

MAGAPI_USER void magicalGetTimeOfDay( struct timeval* tv, struct timezone* tz )
{
	if( gettimeofday(tv, tz) != 0 )
	{
		magicalSetLastErrorInfo("gettimeofday(tv, tz) return != 0");
		magicalReportLastError();
	}
}

MAGAPI_USER void magicalBeginTicking( void )
{
	magicalGetTimeOfDay(&g_tv_ticking, NULL);
}

MAGAPI_USER float magicalEndTicking( void )
{
	float  result;
	struct timeval tv_now;
	magicalGetTimeOfDay(&tv_now, NULL);
	result = (tv_now.tv_sec - g_tv_ticking.tv_sec) +  (tv_now.tv_usec - g_tv_ticking.tv_usec) / 1000000.0f;
	result = MAX(0.0f, result);
	return result;
}

