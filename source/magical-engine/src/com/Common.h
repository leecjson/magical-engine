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

NAMESPACE_MAGICAL
using ::std::string;
using ::std::wstring;
using ::std::stringstream;
NAMESPACE_END

#include "Log.h"
#include "Utils.h"
#include "System.h"

#define SAFE_FREE( var ) do{ if( var ) ::free( var ); } while(0)
#define SAFE_FREE_NULL( var ) do{ if( var ) ::free( var ); var = nullptr; } while(0)
#define SAFE_DELETE( var ) do{ if( var ) delete var; } while(0)
#define SAFE_DELETE_NULL( var ) do{ if( var ) delete var; var = nullptr; } while(0)
#define SAFE_DELETE_ARRAY( var ) do{ if( var ) delete[] var; } while(0)
#define SAFE_DELETE_ARRAY_NULL( var ) do{ if( var ) delete[] var; var = nullptr; } while(0)
#define SAFE_RETAIN( var ) do{ if( var ) var->retain(); } while(0)
#define SAFE_RELEASE( var ) do{ if( var ) var->release(); } while(0)
#define SAFE_RELEASE_NULL( var ) do{ if( var ){ var->release(); var = nullptr; } } while(0)
#define SAFE_ASSIGN( lvar, rvar ) do{ if( rvar ) rvar->retain(); if( lvar ) lvar->release(); lvar = rvar; } while(0)
#define SAFE_MOVE( lvar, rvar ) do{ MAGICAL_ASSERT( lvar != rvar, "Invalid move operate" ); if( lvar ) lvar->release(); lvar = rvar; } while(0)
#define SAFE_MOVE_NULL( lvar, rvar ) do{ MAGICAL_ASSERT( lvar != rvar, "Invalid move operate" ); if( lvar ) lvar->release(); lvar = rvar; rvar = nullptr; } while(0)

/*
stl function
*/
#define MAGICAL_CALLBACK( sel, obj, ... ) std::bind( sel, obj, ##__VA_ARGS__ )
#define MAGICAL_CALLBACK_1( sel, obj, ... ) std::bind( sel, obj, std::placeholders::_1, ##__VA_ARGS__ )
#define MAGICAL_CALLBACK_2( sel, obj, ... ) std::bind( sel, obj, std::placeholders::_1, std::placeholders::_2, ##__VA_ARGS__ )
#define MAGICAL_CALLBACK_3( sel, obj, ... ) std::bind( sel, obj, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, ##__VA_ARGS__ )

/*
error macros
*/
#define MAGICAL_ERROR_MAX_LENGTH 1024*128
MAGICALAPI bool MAGICAL_IS_ERROR( void );
MAGICALAPI void MAGICAL_IGNORE_LAST_ERROR( void );
MAGICALAPI void MAGICAL_SET_LAST_ERROR_IMPL( const char* info, const char* file = nullptr, int line = 0 );
#define MAGICAL_SET_LAST_ERROR( info ) MAGICAL_SET_LAST_ERROR_IMPL( info, __FILE__, __LINE__ )
MAGICALAPI const char* MAGICAL_GET_LAST_ERROR_INFO( void );
MAGICALAPI void MAGICAL_SHOW_LAST_ERROR( void );
MAGICALAPI void MAGICAL_LOG_LAST_ERROR( bool newline = true );
#define MAGICAL_RETURN_IF_ERROR() do{ if( MAGICAL_IS_ERROR() ) return; } while(0)
#define MAGICAL_RETURN_EXP_IF_ERROR( exp ) do{ if( MAGICAL_IS_ERROR() ) return exp; } while(0)

/*
messagebox macros, multi-platform implement
*/
NAMESPACE_MAGICAL
class MessageBox
{
	public: static void show( const char* msg, const char* title );
};
NAMESPACE_END

/*
asserts macros
*/
MAGICALAPI void MAGICAL_ASSERT_IMPL( const char* exp, const char* msg, const char* file, int line );
#ifndef MAGICAL_DEBUG
#define MAGICAL_ASSERT( exp, msg )
#else
#define MAGICAL_ASSERT( exp, msg ) do {                        \
	if( !( exp ) ) {                                           \
		MAGICAL_SET_LAST_ERROR( msg );                         \
		MAGICAL_LOG_LAST_ERROR();                              \
		MAGICAL_ASSERT_IMPL( #exp, msg, __FILE__, __LINE__ );  \
	}                                                          \
	} while(0)
#endif


/*
timer macros
*/
//MAGICALAPI bool magicalIsTimerStarted( void );
//MAGICALAPI void magicalStartTimer( void );
//MAGICALAPI double magicalEndTimer( void );

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

#endif //__COMMON_H__