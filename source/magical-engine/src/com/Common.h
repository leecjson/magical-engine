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

#include "magical-macros.h"

#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <sstream>

NS_MAGICAL_BEGIN
using ::std::string;
using ::std::stringstream;
NS_MAGICAL_END

#include "LogSystem.h"

/*
macros
*/
NS_MAGICAL_BEGIN
//#ifdef MAX
//#undef MAX
//#endif
template< class T >
inline const T& cmax( const T& a, const T& b ){ return a > b ? a : b; }

//#ifdef MIN
//#undef MIN
//#endif
template< class T >
inline const T& cmin( const T& a, const T& b ){ return a < b ? a : b; }
NS_MAGICAL_END


/*
buffer macros
*/
#define kBufferLen 1024 * 128
NS_MAGICAL_BEGIN
extern char commonbuf[];
NS_MAGICAL_END
#define magicalGetBuffer() ::magical::commonbuf
#define magicalFormat( fmt, ... ) ::sprintf( ::magical::commonbuf, fmt, ##__VA_ARGS__ )

/*
func macros
*/
#define magicalSafeFree( var ) do{ if( var ) ::free( var ); } while(0)
#define magicalSafeFreeNull( var ) do{ if( var ) ::free( var ); var = nullptr; } while(0)
#define magicalSafeDelete( var ) do{ if( var ) delete var; } while(0)
#define magicalSafeDeleteNull( var ) do{ if( var ) delete var; var = nullptr; } while(0)
#define magicalSafeDeleteArray( var ) do{ if( var ) delete[] var; } while(0)
#define magicalSafeDeleteArrayNull( var ) do{ if( var ) delete[] var; var = nullptr; } while(0)
#define magicalSafeRetain( var ) do{ if( var ) var->retain(); } while(0)
#define magicalSafeRelease( var ) do{ if( var ) var->release(); } while(0)
#define magicalSafeReleaseNull( var ) do{ if( var ){ var->release(); var = nullptr; } } while(0)
#define magicalSafeAssign( lvar, rvar ) do{ if( rvar ) rvar->retain(); if( lvar ) lvar->release(); lvar = rvar; } while(0)
#define magicalSafeMove( lvar, rvar ) do{ magicalAssert( lvar != rvar, "Invalid move operate" ); if( lvar ) lvar->release(); lvar = rvar; } while(0)
#define magicalSafeMoveNull( lvar, rvar ) do{ magicalAssert( lvar != rvar, "Invalid move operate" ); if( lvar ) lvar->release(); lvar = rvar; rvar = nullptr; } while(0)

/*
error macros
*/
MAGICALAPI bool magicalIsError( void );
MAGICALAPI void magicalIgnoreLastError( void );
MAGICALAPI void magicalSetLastError( const char* info, const char* file = nullptr, int line = 0 );
#define magicalSetLastErrorA( info ) magicalSetLastError( info, __FILE__, __LINE__ )
MAGICALAPI const char* magicalGetLastErrorInfo( void );
MAGICALAPI void magicalShowLastError( void );
MAGICALAPI void magicalLogLastError( void );
MAGICALAPI void magicalLogLastErrorWithoutNewLine( void );
#define magicalReturnIfError() do{ if( magicalIsError() ) return; } while(0)
#define magicalReturnVarIfError( var ) do{ if( magicalIsError() ) return var; } while(0)

/*
messagebox macros, multi-platform implement
*/
MAGICALAPI void magicalMessageBox( const char* msg, const char* title );
#ifndef MAGICAL_DEBUG
#define magicalDebugMessageBox( msg, title )
#else
#define magicalDebugMessageBox( msg, title ) magicalMessageBox( msg, title )
#endif

/*
asserts macros
*/
MAGICALAPI void magicalLocalAssert( const char* exp, const char* msg, const char* file, int line );
#define magicalLocalAssertA( exp, msg ) magicalLocalAssert( exp, msg, __FILE__, __LINE__ )
#ifndef MAGICAL_DEBUG
#define magicalAssert( exp, msg )
#else
#define magicalAssert( exp, msg ) do {                    \
	if( !( exp ) ) {                                      \
		magicalSetLastErrorA( msg );                      \
		magicalLogLastError();                            \
		magicalLocalAssertA( #exp, msg );                 \
	}                                                     \
	} while(0)
#endif

/*
timer macros
*/
MAGICALAPI bool magicalIsTimerStarted( void );
MAGICALAPI void magicalStartTimer( void );
MAGICALAPI double magicalEndTimer( void );

/*
objects lift listener macros, only work on debug protocol
*/
#define kEngineObjectsListener 1
#define kCustomObjectsListener 2

#ifndef MAGICAL_DEBUG
#define magicalStartObjectsListener( listener )
#define magicalEndObjectsListener( listener )
#define magicalIsObjectsListenerStarted( listener ) false
#define magicalObjectConstruct()
#define magicalObjectDestruct()
#define magicalGetObjectsConstructCount( listener ) 0
#define magicalGetObjectsDestructCount( listener ) 0
#else
MAGICALAPI void magicalStartObjectsListener( int listener );
MAGICALAPI void magicalEndObjectsListener( int listener );
MAGICALAPI bool magicalIsObjectsListenerStarted( int listener );
MAGICALAPI void magicalObjectConstruct( void );
MAGICALAPI void magicalObjectDestruct( void );
MAGICALAPI int magicalGetObjectsConstructCount( int listener );
MAGICALAPI int magicalGetObjectsDestructCount( int listener );
#endif

/*
size and rect
*/
NS_MAGICAL_BEGIN

struct Size
{
public:
	float w;
	float h;
	static const Size Zero;

	Size( float w, float h ){ this->w = w; this->h = h; }
};

struct Rect
{
public:
	float x;
	float y;
	float w;
	float h;
	static const Rect Zero;

	Rect( float x, float y, float w, float h ){ this->x = x; this->y = y; this->w = w; this->h = h; }
};

struct Color4f
{
public:
	float r;
	float g;
	float b;
	float a;
	static const Color4f Red;                  // 红
	static const Color4f Green;                // 绿
	static const Color4f Blue;                 // 蓝
	static const Color4f White;                // 白
	static const Color4f Black;                // 黑
	static const Color4f Yello;                // 黄
	static const Color4f Magenta;              // 洋红
	static const Color4f Cyan;                 // 青
	static const Color4f DarkGray;             // 深灰
	static const Color4f LightGray;            // 浅灰
	static const Color4f Brown;                // 褐
	static const Color4f Orange;               // 南瓜橙
	static const Color4f Pink;                 // 粉红
	static const Color4f Purple;               // 紫

	Color4f( float r, float g, float b, float a ){ this->r = r; this->g = g; this->b = b; this->a = a; }
};

NS_MAGICAL_END

#endif //__COMMON_H__