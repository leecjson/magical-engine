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

///*
//platform include
//*/
//#ifdef MAGICAL_WIN32
//#include <Windows.h>
//#endif

/*
c include
*/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <float.h>
#include <stdarg.h>

/*
c++ include
*/
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <exception>

#include "LogSystem.h"


#define kBufferLen 1024 * 100

/*
buffer macros
*/
extern char g_buffer[];

#define magicalBuffer g_buffer
#define magicalFormat( __format, ... ) sprintf( magicalBuffer, __format, ##__VA_ARGS__ )

/*
func macros
*/
#define magicalSafeFree( __var ) do{ if( __var ) free( __var ); } while(0)
#define magicalSafeFreeNull( __var ) do{ if( __var ) free( __var ); __var == nullptr; } while(0)
#define magicalSafeDelete( __var ) do{ if( __var ) delete __var; } while(0)
#define magicalSafeDeleteNull( __var ) do{ if( __var ) delete __var; __var == nullptr; } while(0)
#define magicalSafeDeleteArray( __var ) do{ if( __var ) delete[] __var; } while(0)
#define magicalSafeDeleteArrayNull( __var ) do{ if( __var ) delete[] __var; __var = nullptr; } while(0)
#define magicalSafeRetain( __var ) do{ if( __var ) __var->retain(); } while(0)
#define magicalSafeRelease( __var ) do{ if( __var ) __var->release(); } while(0)
#define magicalSafeReleaseNull( __var ) do{ if( __var ){ __var->release(); __var = nullptr; } } while(0)

/*
error macros
*/
MAGICALAPI bool magicalIsError( void );
MAGICALAPI void magicalIgnoreLastError( void );
MAGICALAPI void magicalSetLastErrorInfo( const char* info, const char* func = nullptr, int line = 0 );
#define magicalSetLastErrorInfoB( __info ) magicalSetLastErrorInfo( __info, __FUNCTION__, __LINE__ )
MAGICALAPI const char* magicalGetLastErrorInfo( void );
//#define magicalShowLastError() do { if( magicalIsError() ) magicalMessageBox( magicalGetLastErrorInfo(), "Error" ); } while(0)
MAGICALAPI void magicalShowLastError( void );
#define magicalReturnIfError() do{ if( magicalIsError() ) return; } while(0)
#define magicalReturnVarIfError( __var ) do{ if( magicalIsError() ) return __var; } while(0)

/*
messagebox macros, multi-platform implement
*/
MAGICALAPI void magicalMessageBox( const char* msg, const char* title );
#ifndef MAGICAL_DEBUG
#define magicalDebugMessageBox( __msg, __title )
#else
#define magicalDebugMessageBox( __msg, __title ) magicalMessageBox( __msg, __title )
#endif

/*
asserts macros
*/
MAGICALAPI void magicalLocalAssert( const char* exp, const char* msg, const char* file, int line );
#define magicalLocalAssertB( __exp, __msg ) magicalLocalAssert( __exp, __msg, __FILE__, __LINE__ )
#ifndef MAGICAL_DEBUG
#define magicalAssert( __con, __msg )
#else
#define magicalAssert( __con, __msg ) do{                     \
	if( !( __con ) ) {                                        \
		magicalSetLastErrorInfoB( __msg );                    \
		magicalLogLastError();                                \
		magicalLocalAssertB( #__con, __msg );                 \
	}                                                         \
	} while(0)
#endif

/*
timer macros
*/
MAGICALAPI_USER bool magicalIsTimerStarted( void );
MAGICALAPI_USER void magicalStartTimer( void );
MAGICALAPI_USER double magicalEndTimer( void );

/*
objects lift listener macros, only work on debug protocol
*/
//#define kEngineObjectsListener 1
//#define kCustomObjectsListener 2
//
//#ifndef MAGICAL_DEBUG
//#define magicalStartObjectsListener( listener )
//#define magicalEndObjectsListener( listener )
//#define magicalIsObjectsListenerStarted( listener ) false
//#define magicalObjectConstruct()
//#define magicalObjectDestruct()
//#define magicalGetObjectsConstructCount( listener ) 0
//#define magicalGetObjectsDestructCount( listener ) 0
//#else
//MAGICALAPI void magicalStartObjectsListener( int listener );
//MAGICALAPI void magicalEndObjectsListener( int listener );
//MAGICALAPI bool magicalIsObjectsListenerStarted( int listener );
//MAGICALAPI void magicalObjectConstruct( void );
//MAGICALAPI void magicalObjectDestruct( void );
//MAGICALAPI int magicalGetObjectsConstructCount( int listener );
//MAGICALAPI int magicalGetObjectsDestructCount( int listener );
//#endif

//struct Color4F
//{
//public:
//	float r;
//	float g;
//	float b;
//	float a;
//};
//
//struct Color4B
//{
//public:
//	uint8_t r;
//	uint8_t g;
//	uint8_t b;
//	uint8_t a;
//};

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