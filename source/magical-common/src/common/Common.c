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

/*
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	typedef struct _SYSTEMTIME {
		WORD wYear;
		WORD wMonth;
		WORD wDayOfWeek;
		WORD wDay;
		WORD wHour;
		WORD wMinute;
		WORD wSecond;
		WORD wMilliseconds;
	} SYSTEMTIME;
#endif

/// time_t转SYSTEMTIME
SYSTEMTIME Time_tToSystemTime(time_t t);
/// SYSTEMTIME转time_t
time_t SystemTimeToTime_t(const SYSTEMTIME& st);
/// 获取格式时间
string FormatTimeSecond(int time);
/// 获取月份天数
int GetDayth(int nYear, int nMonth);

/// time_t转SYSTEMTIME
SYSTEMTIME Time_tToSystemTime(time_t t)
{
	tm temptm = *localtime(&t);

	SYSTEMTIME st = {1900 + temptm.tm_year, 
		1 + temptm.tm_mon, 
		temptm.tm_wday, 
		temptm.tm_mday, 
		temptm.tm_hour, 
		temptm.tm_min, 
		temptm.tm_sec, 
		0};

	return st;
}

/// SYSTEMTIME转time_t
time_t SystemTimeToTime_t(const SYSTEMTIME& st)
{
	tm temptm = {st.wSecond, 
		st.wMinute, 
		st.wHour, 
		st.wDay, 
		st.wMonth - 1, 
		st.wYear - 1900, 
		st.wDayOfWeek, 
		0, 
		-1};

	return mktime(&temptm);
}

/// 获取格式时间
string FormatTimeSecond(int time)
{
	WORD wHour=0;WORD wMinute=0;WORD wSecond=0;
	char strTemp[64] = "";

	wHour = time/3600;
	wMinute = (time - wHour * 3600) / 60;
	wSecond = time%60;

	sprintf(strTemp, "%02d:%02d:%02d", wHour, wMinute, wSecond);

	return strTemp;
}

/// 获取月份天数
int GetDayth(int nYear, int nMonth)
{
	if (((nMonth==2)&&(nYear%4==0)&&(nYear%100!=0))||((nMonth==2)&&(nYear%400==0)))
		return 29;
	else if(nMonth==2)
		return 28;
	else if((nMonth==1)||(nMonth==3)||(nMonth==5)||(nMonth==7)||(nMonth==8)||(nMonth==10)||(nMonth==12))
		return 31;
	else if(nMonth!=2)
		return 30;
}
*/

static const int kMaxLogLength = 1024 * 16;

static int s_last_error = false;
static char* s_last_error_info = NULL;
static struct timeval s_tv_timer;

MAGAPI_USER void magicalLogImpl( const char* str )
{
#ifdef MAG_WIN32
    OutputDebugStringA(str);
    OutputDebugStringA("\n");
	printf("%s\n", str);
#endif
}

MAGAPI void magicalReportImpl( const char* str, const char* function, int line )
{
	if( function && line > 0 )
	{	
		magicalGetCurrentTime(

		char buf[kMaxLogLength];
		sprintf(buf, "%s (%s:%d)", str, function, line);
		magicalLog(buf);
	}
	else
	{
		magicalLog(str);
	}
}

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

MAGAPI_USER int magicalGetCurrentTime( struct timeval* tv, struct timezone* tz )
{
	if( gettimeofday(tv, tz) != 0 )
	{
		magicalSetLastErrorInfo("[magical-error]: gettimeofday error");
		magicalReportLastError();
		return false;
	}
	return true;
}

MAGAPI void magicalBeginTimer( void )
{
	magicalGetCurrentTime(&s_tv_timer, NULL);
}

MAGAPI float magicalEndTimer( void )
{
	static struct timeval tv_now;
	float  result;

	if( magicalGetCurrentTime(&tv_now, NULL) == false )
		return 0.0f;

	result = (tv_now.tv_sec - s_tv_timer.tv_sec) + (tv_now.tv_usec - s_tv_timer.tv_usec) / 1000000.0f;
	result = MAX(0.0f, result);

	return result;
}