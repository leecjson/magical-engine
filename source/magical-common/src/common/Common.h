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
c include
*/
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstdint>
#include <cfloat>
#include <cstdarg>

/*
c++ include
*/
#include <string>
#include <algorithm>
#include <functional>

#include "PlatformMacros.h"
#include "LogSystem.h"

/*
general macros
*/
#define kMaxBufferLength 1024 * 100

extern char g_buffer[];
#define magicalBuffer g_buffer
#define magicalFormat( __format, ... ) std::sprintf( magicalBuffer, __format, ##__VA_ARGS__ )

#define magicalSafeFree( __var ) do{ if( __var ) std::free( __var ); } while(0)
#define magicalSafeFreeNull( __var ) do{ if( __var ) std::free( __var ); __var == nullptr; } while(0)
#define magicalSafeDelete( __var ) do{ if( __var ) delete __var; } while(0)
#define magicalSafeDeleteNull( __var ) do{ if( __var ) delete __var; __var == nullptr; } while(0)
#define magicalSafeDeleteArray( __var ) do{ if( __var ) delete[] __var; } while(0)
#define magicalSafeDeleteArrayNull( __var ) do{ if( __var ) delete[] __var; __var = nullptr; } while(0)
#define magicalSafeRetain( __var ) do{ if( __var ) __var->retain(); } while(0)
#define magicalSafeRelease( __var ) do{ if( __var ) __var->release(); } while(0)
#define magicalSafeReleaseNull( __var ) do{ if( __var ){ __var->release(); __var = nullptr; } } while(0)

/*
error
*/
MAGAPI bool magicalIsError( void );
MAGAPI void magicalIgnoreLastError( void );
MAGAPI void magicalSetLastErrorInfo( const char* info, const char* func = nullptr, int line = 0 );
#define magicalSetLastErrorInfoAt( __info ) magicalSetLastErrorInfo( __info, __FUNCTION__, __LINE__ )
MAGAPI const char* magicalGetLastErrorInfo( void );

#define magicalReturnIfError() do{ if( magicalIsError() ) return; } while(0)
#define magicalReturnVarIfError( __var ) do{ if( magicalIsError() ) return __var; } while(0)
#define magicalShowLastError() do { if( magicalIsError() ) magicalMessageBox( magicalGetLastErrorInfo(), "Error" ); } while(0)

//#ifndef MAG_DEBUG
//#define magicalDebugReturnIfError()
//#define magicalDebugReturnVarIfError( __var );
//#define magicalDebugShowLastError()
//#else
//#define magicalDebugReturnIfError() magicalReturnIfError()
//#define magicalDebugReturnVarIfError( __var ) magicalReturnVarIfError( __var )
//#define magicalDebugShowLastError() magicalShowLastError()
//#endif

/*
message box
*/
MAGAPI void magicalMessageBox( const char* msg, const char* title );

#ifndef MAG_DEBUG
#define magicalDebugMessageBox( __msg, __title )
#else
#define magicalDebugMessageBox( __msg, __title ) magicalMessageBox( __msg, __title )
#endif

/*
assert function
*/
#ifdef MAG_DEBUG
#define magicalAssert( __con, __msg ) do{                     \
	if( !(__con) ) {                                          \
		magicalSetLastErrorInfoAt( __msg );                   \
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
	magicalLog( "Begin Ticking : --------" );                           \
	TimeUtils::beginTicking();                                          \
	} while(0)                                                          
#define magicalEndTicking() do {                                        \
	magicalFormat( "Ended Ticking : %.6f", TimeUtils::endTicking() );   \
	magicalLog( magicalBuffer );                                        \
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
#define magicalBeginObserve() do {                                                                 \
	if( g_is_observing ) break;                                                                    \
	Log::D( "Begin Observe : ------------------------------------------------" );                  \
	g_is_observing = true;                                                                         \
	g_observer_construct_count = 0;                                                                \
	g_observer_destruct_count  = 0;                                                                \
	g_observer_move_construct_count = 0;                                                           \
	g_observer_copy_construct_count = 0;                                                           \
	} while(0)
#define magicalEndObserve() do {                                                                   \
	if(! g_is_observing ) break;                                                                   \
	char __tmbf[256];                                                                              \
	sprintf( __tmbf, "Ended Observe : "                                                            \
	"Construct = %d Move = %d Copy = %d Destruct = %d",                                            \
	g_observer_construct_count,                                                                    \
	g_observer_move_construct_count,                                                               \
	g_observer_copy_construct_count,                                                               \
	g_observer_destruct_count );                                                                   \
	g_is_observing = false;                                                                        \
	Log::D( __tmbf );                                                                              \
	} while(0)
#define magicalRefConstruct() do {                                                                 \
	if( g_is_observing ) ++ g_observer_construct_count;                                            \
	} while(0)
#define magicalRefMove() do {                                                                      \
	if( g_is_observing ) ++ g_observer_move_construct_count;                                       \
	} while(0)
#define magicalRefCopy() do {                                                                      \
	if( g_is_observing ) ++ g_observer_copy_construct_count;                                       \
	} while(0)
#define magicalRefDestruct() do {                                                                  \
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

struct Color4F
{
public:
	float r;
	float g;
	float b;
	float a;
};

struct Color4B
{
public:
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

//Color kColorRed = { 1.0f, 0.0f, 0.0f, 1.0f };                   // 红
//Color kColorGreen = { 0.0f, 1.0f, 0.0f, 1.0f };                 // 绿
//Color kColorBlue = { 0.0f, 0.0f, 1.0f, 1.0f };                  // 蓝
//Color kColorWhite = { 1.0f, 1.0f, 1.0f, 1.0f };                 // 白
//Color kColorBlack = { 0.0f, 0.0f, 0.0f, 1.0f };                 // 黑
//Color kColorYello = { 1.0f, 1.0f, 0.0f, 1.0f };                 // 黄
//Color kColoMagenta = { 1.0f, 0.0f, 1.0f, 1.0f };                // 洋红
//Color kColorCyan = { 0.0f, 1.0f, 1.0f, 1.0f };                  // 青
//Color kColorDarkGray = { 0.25f, 0.25f, 0.25f, 1.0f };           // 深灰
//Color kColorLightGray = { 0.75f, 0.75f, 0.75f, 1.0f };          // 浅灰
//Color kColorBrown = { 0.6f, 0.4f, 0.12f, 1.0f };                // 褐
//Color kColorOrange = { 0.98f, 0.625f, 0.12f, 1.0f };            // 南瓜橙
//Color kColorPink = { 0.98f, 0.04f, 0.7f, 1.0f };				 // 粉红
//Color kColorPurple = { 0.6f, 0.4f, 0.7f, 1.0f };                // 紫

#endif //__COMMON_H__