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

NS_MAGICAL_BEGIN

static char s_buffer[ kBufferLen ];
static FILE* s_debug_file = nullptr;
static FILE* s_warning_file = nullptr;
static FILE* s_error_file = nullptr;

void Log::init( void )
{
	string dir, name;
	char buff[ MAX_PATH ];
	memset( buff, 0, MAX_PATH );

	GetModuleFileNameA( nullptr, buff, MAX_PATH );
	dir = FileUtils::toUnixPath( buff );
	dir = dir.substr( 0, dir.find_last_of( "/" ) + 1 );

	name = dir + DEBUG_LOG_FILE;
	s_debug_file = fopen( name.c_str(), "w" );
	if( s_debug_file == nullptr )
	{
		magicalFormat( "open file(%s) failed!", DEBUG_LOG_FILE );
		magicalSetLastErrorA( magicalGetBuffer() );
		magicalLogLastError();
		return;
	}

	name = dir + WARNING_LOG_FILE;
	s_warning_file = fopen( name.c_str(), "w" );
	if( s_warning_file == nullptr )
	{
		magicalFormat( "open file(%s) failed!", WARNING_LOG_FILE );
		magicalSetLastErrorA( magicalGetBuffer() );
		magicalLogLastError();
		return;
	}

	name = dir + ERROR_LOG_FILE;
	s_error_file = fopen( name.c_str(), "w" );
	if( s_error_file == nullptr )
	{
		magicalFormat( "open file(%s) failed!", ERROR_LOG_FILE );
		magicalSetLastErrorA( magicalGetBuffer() );
		magicalLogLastError();
		return;
	}
}

void Log::delc( void )
{
	fclose( s_debug_file );
	fclose( s_warning_file );
	fclose( s_error_file );
	s_debug_file = nullptr;
	s_warning_file = nullptr;
	s_error_file = nullptr;
}

void Log::write( int level, const char* txt )
{
	if( !txt || !(*txt) ) 
		return;

#ifdef MAGICAL_DEBUG
	sprintf( s_buffer, "%s", txt );
	OutputDebugStringA( s_buffer );
	printf( "%s", s_buffer );
#endif

	switch( level )
	{
	case Debug:
		fprintf( s_debug_file, "%s", txt );
		fflush( s_debug_file );
		break;
	case Warning:
		fprintf( s_warning_file, "%s", txt );
		fflush( s_warning_file );
		break;
	case Error:
		fprintf( s_error_file, "%s", txt );
		fflush( s_error_file );
		break;
	default:
		magicalAssert( false, "Invalid!" );
		break;
	}
}

void Log::writeLine( int level, const char* txt )
{
	if( !txt || !(*txt) ) 
		return;

#ifdef MAGICAL_DEBUG
	sprintf( s_buffer, "%s", txt );
	OutputDebugStringA( s_buffer );
	OutputDebugStringA( "\n" );
	printf( "%s\n", s_buffer );
#endif

	switch( level )
	{
	case Debug:
		fprintf( s_debug_file, "%s\n", txt );
		fflush( s_debug_file );
		break;
	case Warning:
		fprintf( s_warning_file, "%s\n", txt );
		fflush( s_warning_file );
		break;
	case Error:
		fprintf( s_error_file, "%s\n", txt );
		fflush( s_error_file );
		break;
	default:
		magicalAssert( false, "Invalid!" );
		break;
	}
}

NS_MAGICAL_END