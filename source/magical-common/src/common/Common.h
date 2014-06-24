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
#ifndef __COMMON_H__
#define __COMMON_H__

/*
c std include
*/
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
platform include
*/
#ifdef MAG_WIN32
#include <WinSock2.h>
#endif

#include "PlatformMacros.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
general macros
*/
#ifndef MIN
#define MIN(a,b) (((a) > (b)) ? (b) : (a))
#endif
#ifndef MAX
#define MAX(a,b) (((a) < (b)) ? (b) : (a))
#endif

#ifndef MAG_LENGTH
#define MAG_LENGTH
#define kMaxLogLength 1024 * 16
#define kMaxErrLength 1024
#endif

/*
log and report function
*/
#ifndef MAG_DEBUG
#define magicalLog( __str )
#define magicalLogFormat( __format, ... )
#else
#define magicalLog( __str ) magicalLogImpl( __str )
#define magicalLogFormat( __format, ... ) magicalLogFormatImpl( __format, ##__VA_ARGS__)
#endif
MAGAPI_USER void magicalLogImpl( const char* str );
MAGAPI_USER void magicalLogFormatImpl( const char* format, ... );

#define magicalTagError( __msg )  ("Error " ##__msg)
#define magicalTagAssert( __msg ) ("Assert " ##__msg)

#ifndef MAG_DEBUG
#define magicalReport( __str )
#define magicalReportLastError()
#else
#define magicalReport( __str ) magicalReportImpl( __str, __FUNCTION__, __LINE__ )
#define magicalReportLastError() magicalReportImpl( magicalGetLastErrorInfo(), __FUNCTION__, __LINE__ )
#endif
MAGAPI void magicalReportImpl( const char* str, const char* function, int line );

/*
general error signal
*/
MAGAPI int magicalIsError( void );
MAGAPI void magicalIgnoreLastError( void );
MAGAPI const char* magicalSetLastErrorInfo( const char* info );
MAGAPI const char* magicalGetLastErrorInfo( void );

/*
assert function
*/
#ifdef MAG_DEBUG
#define magicalAssert( __con, __msg ) do {                    \
	if( !(__con) ) {                                          \
		magicalSetLastErrorInfo( magicalTagAssert( __msg ) ); \
		magicalReportLastError();                             \
		assert(0);                                            \
	}                                                         \
	} while(0)
#else
#define magicalAssert( __con, __msg )
#endif

/*
time function
*/
#ifdef MAG_WIN32
extern int gettimeofday( struct timeval* tv, struct timezone* tz );
#endif
MAGAPI void magicalGetTimeOfDay( struct timeval* tv, struct timezone* tz );

#ifdef MAG_DEBUG
extern struct timeval g_tv_ticking;
#endif

#ifdef MAG_DEBUG
#define magicalBeginTicking() do {                                                \
	magicalReport( "Begin Ticking : --------" );                                  \
	magicalGetTimeOfDay(&g_tv_ticking, NULL);                                     \
	} while(0)
#define magicalEndTicking() do {                                                  \
	struct timeval __tv_now; float __result; char __tmbf[256];                    \
	magicalGetTimeOfDay(&__tv_now, NULL);                                         \
	__result = (__tv_now.tv_sec - g_tv_ticking.tv_sec) +                          \
	(__tv_now.tv_usec - g_tv_ticking.tv_usec) / 1000000.0f;                       \
	__result = MAX(0.0f, __result);                                               \
	sprintf( __tmbf, "Ended Ticking : %.6f", __result );                          \
	magicalReport( __tmbf );                                                      \
	} while(0)
#else
#define magicalBeginTicking()
#define magicalEndTicking()
#endif

/*
object observer
*/
#ifdef MAG_DEBUG
extern int g_is_observing;
extern int g_observer_construct_count;
extern int g_observer_destruct_count;
#endif

#ifdef MAG_DEBUG
#define magicalBeginObserveObject() do {                                               \
	if( g_is_observing ) break;                                                        \
	magicalReport( "Begin Observe Object : ----------------------------------" );      \
	g_is_observing = true;                                                             \
	g_observer_construct_count = 0;                                                    \
	g_observer_destruct_count  = 0;                                                    \
	} while(0)
#define magicalEndObserveObject() do {                                                 \
	if(! g_is_observing ) break;                                                       \
	char __tmbf[256];                                                                  \
	sprintf( __tmbf, "Ended Observe Object : Construct = %05d Destruct = %05d",        \
	g_observer_construct_count,                                                        \
	g_observer_destruct_count );                                                       \
	g_is_observing = false;                                                            \
	magicalReport( __tmbf );                                                           \
	} while(0)
#define magicalObjectConstruct() do {                                                  \
	if( g_is_observing ) ++ g_observer_construct_count;                                \
	} while(0)
#define magicalObjectDestruct() do {                                                   \
	if( g_is_observing ) ++ g_observer_destruct_count;                                 \
	} while(0)
#else
#define magicalBeginObserveObject()
#define magicalEndObserveObject()
#define magicalObjectConstruct()
#define magicalObjectDestruct()
#endif

#ifdef __cplusplus
}
#endif

#endif //__COMMON_H__