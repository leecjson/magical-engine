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

#include <string>

#include "PlatformMacros.h"
#include "LogSystem.h"

/*
general macros
*/
#ifndef MIN
#define MIN(a, b) (((a) > (b)) ? (b) : (a))
#endif
#ifndef MAX
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
#endif

#define kMaxLogLength  ( 1024 * 50 )
#define kMaxErrLength  ( 1024 )
#define kMaxPathLength ( 512 )

/*
general
*/
MAGAPI bool magicalIsError( void );
MAGAPI void magicalIgnoreLastError( void );
MAGAPI void magicalSetLastErrorInfo( const char* info );
MAGAPI const char* magicalGetLastErrorInfo( void );

#define magicalReturnIfError() if( magicalIsError() ) return
#define magicalFree( __var ) magicalAssert( __var, "free nullptr at " ##__FUNCTION__ ); ::free( __var )
#define magicalDelete( __var ) magicalAssert( __var, "delete nullptr at " ##__FUNCTION__ ); delete __var
#define magicalDeleteArray( __var ) magicalAssert( __var, "delete[] nullptr at " ##__FUNCTION__ ); delete[] __var

/*
assert function
*/
#ifdef MAG_DEBUG
#define magicalAssert( __con, __msg ) do {                    \
	if( !(__con) ) {                                          \
		magicalSetLastErrorInfo( __msg );                     \
		magicalLogLastError();                                \
		assert(0);                                            \
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
object observer
*/
#ifdef MAG_DEBUG
extern bool g_is_observing;
extern int g_observer_move_construct_count;
extern int g_observer_copy_construct_count;
extern int g_observer_construct_count;
extern int g_observer_destruct_count;
#endif

#ifdef MAG_DEBUG
#define magicalBeginObserveObject() do {                                                           \
	if( g_is_observing ) break;                                                                    \
	magicalLog( "Begin Observe Object : ------------------------------------------------" );       \
	g_is_observing = true;                                                                         \
	g_observer_construct_count = 0;                                                                \
	g_observer_destruct_count  = 0;                                                                \
	g_observer_move_construct_count = 0;                                                           \
	g_observer_copy_construct_count = 0;                                                           \
	} while(0)
#define magicalEndObserveObject() do {                                                             \
	if(! g_is_observing ) break;                                                                   \
	char __tmbf[256];                                                                              \
	sprintf( __tmbf, "Ended Observe Object : "                                                     \
	"Construct = %d Move = %d Copy = %d Destruct = %d",                                            \
	g_observer_construct_count,                                                                    \
	g_observer_move_construct_count,                                                               \
	g_observer_copy_construct_count,                                                               \
	g_observer_destruct_count );                                                                   \
	g_is_observing = false;                                                                        \
	magicalLog( __tmbf );                                                                          \
	} while(0)
#define magicalObjectConstruct() do {                                                              \
	if( g_is_observing ) ++ g_observer_construct_count;                                            \
	} while(0)
#define magicalObjectMove() do {                                                                   \
	if( g_is_observing ) ++ g_observer_move_construct_count;                                       \
	} while(0)
#define magicalObjectCopy() do {                                                                   \
	if( g_is_observing ) ++ g_observer_copy_construct_count;                                       \
	} while(0)
#define magicalObjectDestruct() do {                                                               \
	if( g_is_observing ) ++ g_observer_destruct_count;                                             \
	} while(0)
#else
#define magicalBeginObserveObject()
#define magicalEndObserveObject()
#define magicalObjectConstruct()
#define magicalObjectMove()
#define magicalObjectCopy()
#define magicalObjectDestruct()
#endif

#endif //__COMMON_H__