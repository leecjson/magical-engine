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

#include "PlatformMacros.h"
#include "LogSystem.h"

#include <assert.h>

/*
general macros
*/
#ifndef MIN
#define MIN(a,b) (((a) > (b)) ? (b) : (a))
#endif
#ifndef MAX
#define MAX(a,b) (((a) < (b)) ? (b) : (a))
#endif

#define kMaxLogLength (1024 * 50)
#define kMaxErrLength (1024)

/*
general error signal
*/
MAGAPI bool magicalIsError( void );
MAGAPI void magicalIgnoreLastError( void );
MAGAPI void magicalSetLastErrorInfo( const char* info );
MAGAPI const char* magicalGetLastErrorInfo( void );

/*
assert function
*/
#ifdef MAG_DEBUG
#define magicalAssert( __con, __msg ) do {                    \
	if( !(__con) ) {                                          \
		magicalSetLastErrorInfo( "Assert " ##__msg );         \
		magicalLogLastError();                                \
		assert(0);                                            \
	}                                                         \
	} while(0)
#else
#define magicalAssert( __con, __msg )
#endif

/*
win32 gettimeofday
*/
#ifdef MAG_WIN32
#include <WinSock2.h>
#endif
#ifdef MAG_WIN32
extern "C" int gettimeofday( struct timeval* tv, struct timezone* tz );
#endif
MAGAPI void magicalGetTimeOfDay( struct timeval* tv, struct timezone* tz );

//MAGAPI_USER void magicalBeginTicking( void );
//MAGAPI_USER float magicalEndTicking( void );
//
//#ifndef MAG_DEBUG
//#define magicalBeginTickingAndReport()
//#define magicalEndTickingAndReport()
//#else
//#define magicalBeginTickingAndReport() do {                             \
//	magicalReport("Begin Ticking : --------");                          \
//	magicalBeginTicking();                                              \
//	} while(0)                                                          
//#define magicalEndTickingAndReport() do {                               \
//	char __bf[ 256 ];                                                   \
//	sprintf( __bf, "Ended Ticking : %.6f", magicalEndTicking() );       \
//	magicalReport( __bf );                                              \
//	} while(0)
//#endif

/*
object observer
*/
//#ifdef MAG_DEBUG
//extern bool g_is_observing;
//extern int  g_observer_construct_count;
//extern int  g_observer_destruct_count;
//#endif
//
//#ifdef MAG_DEBUG
//#define magicalBeginObserveObjectAndReport() do {                                      \
//	if( g_is_observing ) break;                                                        \
//	magicalReport( "Begin Observe Object : ----------------------------" );            \
//	g_is_observing = true;                                                             \
//	g_observer_construct_count = 0;                                                    \
//	g_observer_destruct_count  = 0;                                                    \
//	} while(0)
//#define magicalEndObserveObjectAndReport() do {                                        \
//	if(! g_is_observing ) break;                                                       \
//	char __tmbf[256];                                                                  \
//	sprintf( __tmbf, "Ended Observe Object : Construct = %d Destruct = %d",            \
//	g_observer_construct_count,                                                        \
//	g_observer_destruct_count );                                                       \
//	g_is_observing = false;                                                            \
//	magicalReport( __tmbf );                                                           \
//	} while(0)
//#define magicalObjectConstruct() do {                                                  \
//	if( g_is_observing ) ++ g_observer_construct_count;                                \
//	} while(0)
//#define magicalObjectDestruct() do {                                                   \
//	if( g_is_observing ) ++ g_observer_destruct_count;                                 \
//	} while(0)
//#else
//#define magicalBeginObserveObjectAndReport()
//#define magicalEndObserveObjectAndReport()
//#define magicalObjectConstruct()
//#define magicalObjectDestruct()
//#endif

#endif //__COMMON_H__