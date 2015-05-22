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
#include "Assets.h"
#include "Utils.h"
#include <windows.h>

NAMESPACE_MAGICAL

static std::string _search_path;

void Assets::init( void )
{
	Assets::setDefaultSearchPath();
	MAGICAL_RETURN_IF_ERROR();
}

void Assets::delc( void )
{

}

void Assets::setDefaultSearchPath( void )
{
	char directory[ 2048 ] = { 0 };
	GetCurrentDirectoryA( 2048, directory );
	if( strlen( directory ) == 0 )
	{
		MAGICAL_SET_LAST_ERROR_A( "result of GetCurrentDirectoryA is empty." );
		MAGICAL_LOG_LAST_ERROR();
		return;
	}
	_search_path = FileUtils::toUnixPath( directory );
	_search_path += "/";
}

void Assets::setSearchPath( const char* path )
{
	MAGICAL_ASSERT( path, "should not be nullptr." );
	std::string unix_path = FileUtils::toUnixPath( path );
	MAGICAL_ASSERT( FileUtils::isAbsPath( unix_path.c_str() ), "should be absolute path." );

	if( unix_path.length() > 0 && unix_path.back() != '/' )
		unix_path += "/";

	_search_path = unix_path;
}

std::string Assets::getSearchPath( void )
{
	return _search_path;
}

std::string Assets::getAbsFilename( const char* file )
{
	MAGICAL_ASSERT( file, "should not be nullptr." );
	if( FileUtils::isAbsPath( file ) )
		return file;

	std::string unix_path = FileUtils::toUnixPath( file );
	std::string abs_path = _search_path + unix_path;
	return abs_path;
}

bool Assets::isFileExist( const char* file )
{
	MAGICAL_ASSERT( file, "should not be nullptr." );

	std::string file_path = FileUtils::toUnixPath( file );
	if( FileUtils::isAbsPath( file_path.c_str() ) == false )
	{
		std::string abs_path = _search_path + file_path;
		int ret = GetFileAttributesA( abs_path.c_str() );
		if( ret != -1 )
		{
			return true;
		}
	}
	else
	{
		return GetFileAttributesA( file_path.c_str() ) != -1 ? true : false;
	}

	return false;
}

Ptr<Data> Assets::loadFile( const char* file )
{
	MAGICAL_ASSERT( file, "should not be nullptr." );

	std::string abs_path = getAbsFilename( file );
	MAGICAL_ASSERT( !abs_path.empty(), System::format<512>( "get assets file data failed! file(%s) doesn't exist.", file ).c_str() );

	FILE* fp = fopen( abs_path.c_str(), "rb" );
	if( fp == nullptr )
	{
		MAGICAL_SET_LAST_ERROR_A( System::format<512>( "get assets file data failed! file(%s).", file ).c_str() );
		MAGICAL_LOG_LAST_ERROR();
		return nullptr;
	}

	size_t size, read_size = 0;
	fseek( fp, 0, SEEK_END );
	size = (size_t) ftell( fp );
	fseek( fp, 0, SEEK_SET );

	Ptr<Data> data = Data::create( size + 1 );
	read_size = fread( data->cPtr(), sizeof( char ), size, fp );
	data->realloc( read_size + 1 );
	data->cPtr()[ read_size ] = 0;
	fclose( fp );

	return data;
}

NAMESPACE_END