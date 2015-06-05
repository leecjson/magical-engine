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
#include "System.h"
#ifdef MAGICAL_WIN32
#include <windows.h>
#endif

NAMESPACE_MAGICAL

char System::storage[ StorageSize ] = { 0 };

std::wstring System::utf8ToUnicode( const std::string& str )
{
#ifdef MAGICAL_WIN32
	std::wstring result;

	int size = ::MultiByteToWideChar( CP_UTF8, 0, str.c_str(), -1, NULL, 0 );
	MAGICAL_ASSERT( size != ERROR_NO_UNICODE_TRANSLATION && size != 0, "Invalid utf-8 sequence!" );

	size_t dst_size = sizeof( wchar_t ) * size;
	wchar_t* dst = ( wchar_t* ) ::malloc( dst_size );
	::memset( dst, 0, dst_size );

	int convert_size = ::MultiByteToWideChar( CP_UTF8, 0, str.c_str(), -1, dst, size );
	MAGICAL_ASSERT( convert_size == size, "La falla!" );

	result = dst;
	::free( dst );
	return result;
#endif
}

std::wstring System::ansiToUnicode( const std::string& str )
{
#ifdef MAGICAL_WIN32
	std::wstring result;

	int size = ::MultiByteToWideChar( CP_ACP, 0, str.c_str(), -1, NULL, 0 );
	MAGICAL_ASSERT( size != ERROR_NO_UNICODE_TRANSLATION && size != 0, "Invalid conversion!" );

	size_t dst_size = sizeof( wchar_t )* size;
	wchar_t* dst = ( wchar_t* ) ::malloc( dst_size );
	::memset( dst, 0, dst_size );

	int convert_size = ::MultiByteToWideChar( CP_ACP, 0, str.c_str(), -1, dst, size );
	MAGICAL_ASSERT( convert_size == size, "La falla!" );

	result = dst;
	::free( dst );
	return result;
#endif
}

std::string System::unicodeToUtf8( const std::wstring& str )
{
#ifdef MAGICAL_WIN32
	std::string result;

	int size = ::WideCharToMultiByte( CP_UTF8, 0, str.c_str(), -1, NULL, 0, NULL, NULL );
	MAGICAL_ASSERT( size != ERROR_NO_UNICODE_TRANSLATION && size != 0, "Invalid conversion!" );

	size_t dst_size = sizeof( char ) * size;
	char* dst = ( char* ) ::malloc( dst_size );
	::memset( dst, 0, dst_size );

	int convert_size = ::WideCharToMultiByte( CP_UTF8, 0, str.c_str(), -1, dst, size, NULL, NULL );
	MAGICAL_ASSERT( convert_size == size, "La falla!" );

	result = dst;
	::free( dst );
	return result;
#endif
}

std::string System::unicodeToAnsi( const std::wstring& str )
{
#ifdef MAGICAL_WIN32
	std::string result;

	int size = ::WideCharToMultiByte( CP_OEMCP, 0, str.c_str(), -1, NULL, 0, NULL, NULL );
	MAGICAL_ASSERT( size != ERROR_NO_UNICODE_TRANSLATION && size != 0, "Invalid conversion!" );

	size_t dst_size = sizeof( char ) * size;
	char* dst = ( char* ) ::malloc( dst_size );
	::memset( dst, 0, dst_size );

	int convert_size = ::WideCharToMultiByte( CP_OEMCP, 0, str.c_str(), -1, dst, size, NULL, NULL );
	MAGICAL_ASSERT( convert_size == size, "La falla!" );

	result = dst;
	::free( dst );
	return result;
#endif
}

std::string System::utf8ToAnsi( const std::string& str )
{
	return unicodeToAnsi( utf8ToUnicode( str ) );
}

std::string System::ansiToUtf8( const std::string& str )
{
	return unicodeToUtf8( ansiToUnicode( str ) );
}

NAMESPACE_END