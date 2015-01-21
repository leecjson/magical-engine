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
#include "LogSystem.h"
#include "Utils.h"
#include <windows.h>

#define MAGICAL_LOG_DEBUG "DEBUG"
#define MAGICAL_LOG_ERROR "ERROR"

NS_MAGICAL_BEGIN

static char s_buffer[ kBufferLen ];
static FILE* s_output_file = nullptr;

void Log::init( void )
{
	std::string dir, name;
	char buff[ MAX_PATH ];
	std::memset( buff, 0, MAX_PATH );

	GetModuleFileNameA( NULL, buff, MAX_PATH );
	dir = FileUtils::toUnixPath( buff );
	dir = dir.substr( 0, dir.find_last_of( "/" ) );

	name = dir + "/magical-log.log";
	s_output_file = fopen( name.c_str(), "w" );
	if( s_output_file == nullptr )
	{
		magicalSetLastErrorA( "open file(debug.log) failed!" );
		magicalLogLastError();
	}
}

void Log::delc( void )
{
	fclose( s_output_file );
	s_output_file = nullptr;
}

void Log::write( const char* txt )
{
#ifdef MAGICAL_DEBUG
	magicalAssert( txt, "should not be nullptr." );
#else
	if( !txt ) return;
#endif

#ifdef MAGICAL_DEBUG
	sprintf( s_buffer, "%s", txt );

	OutputDebugStringA( s_buffer );
	OutputDebugStringA( "\n" );
	printf( "%s\n", s_buffer );
#endif

	if( s_output_file )
	{
		fprintf( s_output_file, "%s\n", txt );
		fflush( s_output_file );
	}
}

NS_MAGICAL_END

void magicalLogLastError( void )
{
	char temp[ kBufferLen ];
	const char* last_error = magicalGetLastErrorInfo();
	
	sprintf( temp, "[%s]: %s", MAGICAL_LOG_ERROR, last_error );
	magicalLog( temp );
}