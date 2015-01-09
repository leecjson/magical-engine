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
#include "AssetsSystem.h"
#include "Utils.h"
#include "Array.h"
#include "Map.h"

#include <windows.h>

static std::string _s_assets_path;

void Assets::init( void )
{
	resetAssetsPath();
	magicalReturnIfError();
}

void Assets::delc( void )
{

}

void Assets::resetAssetsPath( void )
{
	GetCurrentDirectoryA( kBufferLen, magicalBuffer );

	if( strlen( magicalBuffer ) == 0 )
	{
		magicalSetLastErrorInfoB( "result of GetCurrentDirectoryA is empty." );
		magicalLogLastError();
		return;
	}

	_s_assets_path = FileUtils::toUnixStylePath( magicalBuffer );
	_s_assets_path.append( "/" );
}

void Assets::setAssetsPath( const char* path )
{
	magicalAssert( path, "should not be nullptr." );

	std::string unix_path = FileUtils::toUnixStylePath( path );
	magicalAssert( FileUtils::isAbsolutePath( unix_path.c_str() ), "should be absolute path." );

	if( unix_path.length() > 0 && unix_path[unix_path.length() - 1] != '/' )
	{
		unix_path += "/";
	}

	_s_assets_path = unix_path;
}

std::string Assets::getAssetsPath( void )
{
	return _s_assets_path;
}

std::string Assets::getAssetsAbsoluteFilename( const char* file_name )
{
	magicalAssert( file_name, "should not be nullptr." );

	if( FileUtils::isAbsolutePath( file_name ) )
	{
		return file_name;
	}

	std::string unix_path = FileUtils::toUnixStylePath( file_name );
	std::string abs_path = _s_assets_path + unix_path;

	return abs_path;
}

bool Assets::isAssetsFileExist( const char* file_name )
{
	magicalAssert( file_name, "should not be nullptr." );

	std::string file_path = FileUtils::toUnixStylePath( file_name );
	if( FileUtils::isAbsolutePath( file_path.c_str() ) == false )
	{
		std::string abs_path = _s_assets_path + file_path;
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

Shared<Data> Assets::getAssetsFileData( const char* file_name )
{
	magicalAssert( file_name, "should not be nullptr." );

	std::string abs_path = getAssetsAbsoluteFilename( file_name );
	magicalAssert( !abs_path.empty(), StringUtils::format<512>( "get assets file data failed! file(%s) doesn't exist.", file_name ).c_str() );

	FILE* fp = fopen( abs_path.c_str(), "rb" );
	if( fp == nullptr )
	{
		magicalSetLastErrorInfoB( StringUtils::format<512>( "get assets file data failed! file(%s).", file_name ).c_str() );
		magicalLogLastError();
		return nullptr;
	}

	size_t size, read_size = 0;
	fseek( fp, 0, SEEK_END );
	size = (size_t)ftell( fp );
	fseek( fp, 0, SEEK_SET );

	Shared<Data> data = Data::create();
	data->malloc( size + 1 );

	read_size = fread( data->ptr(), sizeof( char ), size, fp );
	data->realloc( read_size + 1 );
	data->ptr()[ read_size ] = 0;
	fclose( fp );

	return data;
}