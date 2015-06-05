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
#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "magical-macros.h"
#include "Log.h"
#include "Utils.h"

NAMESPACE_MAGICAL

class System
{
public:
	static const int StorageSize = 1024 * 512;

public:
	static char storage[ StorageSize ];

public:
	template< int Len = 1024 * 128 >
	static inline string format( const char* format, ... )
	{
		char dst[ Len ];
		va_list args;
		va_start( args, format );
		vsnprintf( dst, Len, format, args );
		va_end( args );
		return dst;
	}

public:
	static std::wstring utf8ToUnicode( const std::string& str );
	static std::wstring ansiToUnicode( const std::string& str );
	static std::string unicodeToUtf8( const std::wstring& str );
	static std::string unicodeToAnsi( const std::wstring& str );
	static std::string utf8ToAnsi( const std::string& str );
	static std::string ansiToUtf8( const std::string& str );
};

NAMESPACE_END

#endif //__SYSTEM_H__