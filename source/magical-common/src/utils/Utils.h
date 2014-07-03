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
#ifndef __UTILS_H__
#define __UTILS_H__

#include "PlatformMacros.h"
#include "Common.h"

#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <string>
#include <memory>

class StringUtils
{
public:
	template< int __size >
	static inline std::string format( const char* format, ... )
	{
		char buf[ __size ];
		va_list args;
		va_start( args, format );
		vsnprintf( buf, __size, format, args );
		va_end( args );
		return std::move( std::string(buf) );
	}
};

class TimeUtils
{
public:
	static int64_t getCurrentMicrosecTime();
};

#endif //__UTILS_H__