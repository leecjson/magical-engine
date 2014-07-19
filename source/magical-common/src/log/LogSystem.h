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
#ifndef __LOG_SYSTEM_H__
#define __LOG_SYSTEM_H__

#include "PlatformMacros.h"
#include "Common.h"

#ifndef MAG_DEBUG
#define magicalLog( __msg )
#define magicalLogD( __msg )
#define magicalLogE( __msg )
#define magicalLogLastError()
#else
#define magicalLog( __msg ) Log::I( __msg )
#define magicalLogD( __msg ) Log::D( __msg )
#define magicalLogE( __msg ) Log::E( __msg )
#define magicalLogLastError() Log::E( magicalGetLastErrorInfo() )
#endif

class Log
{
public:
	static void init( void );
	static void delc( void );

public:
	static void I( const char* msg );
	static void D( const char* msg );
	static void E( const char* msg );
};

#endif  //__LOG_SYSTEM_H__