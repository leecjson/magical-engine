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
#ifndef __LOG_STREAM_H__
#define __LOG_STREAM_H__

#include "magical-macros.h"
#include "Common.h"
#include <functional>

NAMESPACE_MAGICAL

class LogStream
{
public:
	LogStream( void );
	~LogStream( void );

public:
	LogStream& operator<<( const char* rhs );
	LogStream& operator<<( const string& rhs );
	LogStream& operator<<( float rhs );
	LogStream& operator<<( double rhs );
	LogStream& operator<<( long double rhs );
	LogStream& operator<<( int rhs );
	LogStream& operator<<( short rhs );
	LogStream& operator<<( long rhs );
	LogStream& operator<<( long long rhs );
	LogStream& operator<<( char rhs );
	LogStream& operator<<( bool rhs );

protected:
	std::stringstream m_stream;
	std::function<void(const std::string&)> m_delegate;
};

NAMESPACE_END

#endif //__LOG_STREAM_H__