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
#include "Log.h"
#include "Utils.h"
#include <windows.h>

NAMESPACE_MAGICAL

static char _buffer[ MAGICAL_LOG_MAX_LENGTH ];
static FILE* _debug_file = nullptr;
static FILE* _warning_file = nullptr;
static FILE* _error_file = nullptr;

void Log::init( void )
{
	string dir, name;
	char buff[ MAX_PATH ] = { 0 };

	GetModuleFileNameA( nullptr, buff, MAX_PATH );
	dir = FileUtils::toUnixPath( buff );
	dir = dir.substr( 0, dir.find_last_of( "/" ) + 1 );

	name = dir + MAGICAL_LOG_DEBUG_FILE;
	_debug_file = fopen( name.c_str(), "w" );
	if( _debug_file == nullptr )
	{
		MAGICAL_SET_LAST_ERROR( System::format( "open file(%s) failed!", MAGICAL_LOG_DEBUG_FILE ).c_str() );
		MAGICAL_LOG_LAST_ERROR();
		return;
	}

	name = dir + MAGICAL_LOG_WARNING_FILE;
	_warning_file = fopen( name.c_str(), "w" );
	if( _warning_file == nullptr )
	{
		MAGICAL_SET_LAST_ERROR( System::format( "open file(%s) failed!", MAGICAL_LOG_WARNING_FILE ).c_str() );
		MAGICAL_LOG_LAST_ERROR();
		return;
	}

	name = dir + MAGICAL_LOG_ERROR_FILE;
	_error_file = fopen( name.c_str(), "w" );
	if( _error_file == nullptr )
	{
		MAGICAL_SET_LAST_ERROR( System::format( "open file(%s) failed!", MAGICAL_LOG_ERROR_FILE ).c_str() );
		MAGICAL_LOG_LAST_ERROR();
		return;
	}
}

void Log::delc( void )
{
	fclose( _debug_file );
	fclose( _warning_file );
	fclose( _error_file );
}

void Log::write( Level level, const char* text )
{
	if( !text || *text == 0 ) 
		return;

#ifdef MAGICAL_DEBUG
	wstring wtext = System::utf8ToUnicode( text );
	string asnitext = System::unicodeToAnsi( wtext );

	OutputDebugStringW( wtext.c_str() );
	printf( "%s", asnitext.c_str() );
#endif

	switch( level )
	{
	case Debug:
		fprintf( _debug_file, "%s", text );
		fflush( _debug_file );
		break;
	case Warning:
		fprintf( _warning_file, "%s", text );
		fflush( _warning_file );
		break;
	case Error:
		fprintf( _error_file, "%s", text );
		fflush( _error_file );
		break;
	default:
		MAGICAL_ASSERT( false, "Invalid!" );
		break;
	}
}

void Log::writeLine( Level level, const char* text )
{
	if( !text ) return;

#ifdef MAGICAL_DEBUG
	wstring wtext = System::utf8ToUnicode( text );
	string asnitext = System::unicodeToAnsi( wtext );

	OutputDebugStringW( wtext.c_str() );
	OutputDebugStringW( L"\n" );
	printf( "%s\n", asnitext.c_str() );
#endif

	switch( level )
	{
	case Debug:
		fprintf( _debug_file, "%s\n", text );
		fflush( _debug_file );
		break;
	case Warning:
		fprintf( _warning_file, "%s\n", text );
		fflush( _warning_file );
		break;
	case Error:
		fprintf( _error_file, "%s\n", text );
		fflush( _error_file );
		break;
	default:
		MAGICAL_ASSERT( false, "Invalid!" );
		break;
	}
}

NAMESPACE_END