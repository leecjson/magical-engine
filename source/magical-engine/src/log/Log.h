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
#ifndef __LOG_H__
#define __LOG_H__

#include "magical-macros.h"
#include "Common.h"

#define MAGICAL_LOGD( text ) ::magical::Log::writeLine( ::magical::Log::Debug, text )
#define MAGICAL_LOGW( text ) ::magical::Log::writeLine( ::magical::Log::Warning, text )
#define MAGICAL_LOGE( text ) ::magical::Log::writeLine( ::magical::Log::Error, text )

#ifndef MAGICAL_DEBUG
#define MAGICAL_DEBUG_LOGD( text )
#define MAGICAL_DEBUG_LOGW( text )
#define MAGICAL_DEBUG_LOGE( text )
#else
#define MAGICAL_DEBUG_LOGD( text ) MAGICAL_LOGD( text )
#define MAGICAL_DEBUG_LOGW( text ) MAGICAL_LOGW( text )
#define MAGICAL_DEBUG_LOGE( text ) MAGICAL_LOGE( text )
#endif

#define MAGICAL_LOG_MAX_LENGTH 1024*128
#define MAGICAL_LOG_DEBUG_FILE "magical-Log-debug.log"
#define MAGICAL_LOG_WARNING_FILE "magical-Log-warning.log"
#define MAGICAL_LOG_ERROR_FILE "magical-Log-error.log"

NAMESPACE_MAGICAL

class Log 
{ 
public:
	enum Level : int
	{
		Debug = 0,
		Warning = 1,
		Error = 2,
	};

public:
	static void init( void );
	static void delc( void );
	
public:
	static void write( Level level, const char* text );
	static void writeLine( Level level, const char* text );
};

NAMESPACE_END

#endif //__LOG_H__