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

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <ctime>
#include <cmath>

#include <algorithm>
#include <string>

#include "PlatformMacros.h"
#include "LogSystem.h"

/*
general macros
*/
//#ifndef MIN
//#define MIN(a, b) (((a) > (b)) ? (b) : (a))
//#endif
//#ifndef MAX
//#define MAX(a, b) (((a) < (b)) ? (b) : (a))
//#endif

#define kMaxLogLength  ( 1024 * 50 )
#define kMaxErrLength  ( 1024 )
#define kMaxPathLength ( 1024 )

#define magicalReturnIfError() do{ if( magicalIsError() ) return; } while(0)

#define magicalSafeFree( __var ) do{ if( __var ) ::free( __var ); } while(0)
#define magicalSafeFreeNull( __var ) do{ if( __var ) ::free( __var ); __var == nullptr; } while(0)
#define magicalSafeDelete( __var ) do{ if( __var ) delete __var; } while(0)
#define magicalSafeDeleteNull( __var ) do{ if( __var ) delete __var; __var == nullptr; } while(0)
#define magicalSafeDeleteArray( __var ) do{ if( __var ) delete[] __var; } while(0)
#define magicalSafeDeleteArrayNull( __var ) do{ if( __var ) delete[] __var; __var = nullptr; } while(0)
#define magicalSafeRetain( __var ) do{ if( __var ) __var->retain(); } while(0)
#define magicalSafeRelease( __var ) do{ if( __var ) __var->release(); } while(0)
#define magicalSafeReleaseNull( __var ) do{ if( __var ){ __var->release(); __var = nullptr; } } while(0)

/*
general
*/
MAGAPI bool magicalIsError( void );
MAGAPI void magicalIgnoreLastError( void );
MAGAPI void magicalSetLastErrorInfo( const char* info );
MAGAPI const char* magicalGetLastErrorInfo( void );

/*
assert function
*/
#ifdef MAG_DEBUG
#define magicalAssert( __con, __msg ) do{                     \
	if( !(__con) ) {                                          \
		magicalSetLastErrorInfo( __msg );                     \
		magicalLogLastError();                                \
		assert( __con );                                      \
	}                                                         \
	} while(0)
#else
#define magicalAssert( __con, __msg )
#endif

/*
time function
*/
#ifndef MAG_DEBUG
#define magicalBeginTicking()
#define magicalEndTicking()
#else
#define magicalBeginTicking() do {                                      \
	magicalLog("Begin Ticking : --------");                             \
	TimeUtils::beginTicking();                                          \
	} while(0)                                                          
#define magicalEndTicking() do {                                        \
	char __bf[ 256 ];                                                   \
	sprintf( __bf, "Ended Ticking : %.6f", TimeUtils::endTicking() );   \
	magicalLog( __bf );                                                 \
	} while(0)
#endif

/*
reference observer
*/
#ifdef MAG_DEBUG
extern bool g_is_observing;
extern int g_observer_move_construct_count;
extern int g_observer_copy_construct_count;
extern int g_observer_construct_count;
extern int g_observer_destruct_count;
#endif

#ifdef MAG_DEBUG
#define magicalBeginObserve() do {                                                           \
	if( g_is_observing ) break;                                                                    \
	magicalLog( "Begin Observe : ------------------------------------------------" );       \
	g_is_observing = true;                                                                         \
	g_observer_construct_count = 0;                                                                \
	g_observer_destruct_count  = 0;                                                                \
	g_observer_move_construct_count = 0;                                                           \
	g_observer_copy_construct_count = 0;                                                           \
	} while(0)
#define magicalEndObserve() do {                                                             \
	if(! g_is_observing ) break;                                                                   \
	char __tmbf[256];                                                                              \
	sprintf( __tmbf, "Ended Observe : "                                                     \
	"Construct = %d Move = %d Copy = %d Destruct = %d",                                            \
	g_observer_construct_count,                                                                    \
	g_observer_move_construct_count,                                                               \
	g_observer_copy_construct_count,                                                               \
	g_observer_destruct_count );                                                                   \
	g_is_observing = false;                                                                        \
	magicalLog( __tmbf );                                                                          \
	} while(0)
#define magicalRefConstruct() do {                                                              \
	if( g_is_observing ) ++ g_observer_construct_count;                                            \
	} while(0)
#define magicalRefMove() do {                                                                   \
	if( g_is_observing ) ++ g_observer_move_construct_count;                                       \
	} while(0)
#define magicalRefCopy() do {                                                                   \
	if( g_is_observing ) ++ g_observer_copy_construct_count;                                       \
	} while(0)
#define magicalRefDestruct() do {                                                               \
	if( g_is_observing ) ++ g_observer_destruct_count;                                             \
	} while(0)
#else
#define magicalBeginObserve()
#define magicalEndObserve()
#define magicalRefConstruct()
#define magicalRefMove()
#define magicalRefCopy()
#define magicalRefDestruct()
#endif

#endif //__COMMON_H__