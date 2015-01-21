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

NS_MAGICAL_BEGIN

static std::string _s_assets_path;

void Assets::Init( void )
{
	Assets::SetDefaultAssetsPath();
	magicalReturnIfError();
}

void Assets::Delc( void )
{
	
}

void Assets::SetDefaultAssetsPath( void )
{
	GetCurrentDirectoryA( kBufferLen, magicalGetBuffer() );
	std::string current = magicalGetBuffer();
	if( current.empty() )
	{
		magicalSetLastErrorA( "result of GetCurrentDirectoryA is empty." );
		magicalLogLastError();
		return;
	}
	_s_assets_path = FileUtils::ToUnixPath( current.c_str() );
	_s_assets_path += "/";
}

void Assets::SetAssetsPath( const char* path )
{
	magicalAssert( path, "should not be nullptr." );
	std::string unix_path = FileUtils::ToUnixPath( path );
	magicalAssert( FileUtils::IsAbsPath( unix_path.c_str() ), "should be absolute path." );

	if( unix_path.length() > 0 && unix_path.back() != '/' )
		unix_path += "/";

	_s_assets_path = unix_path;
}

std::string Assets::GetAssetsPath( void )
{
	return _s_assets_path;
}

std::string Assets::GetAssetsAbsFilename( const char* file )
{
	magicalAssert( file, "should not be nullptr." );
	if( FileUtils::IsAbsPath( file ) )
		return file;

	std::string unix_path = FileUtils::ToUnixPath( file );
	std::string abs_path = _s_assets_path + unix_path;
	return abs_path;
}

bool Assets::IsFileExist( const char* file )
{
	magicalAssert( file, "should not be nullptr." );

	std::string file_path = FileUtils::ToUnixPath( file );
	if( FileUtils::IsAbsPath( file_path.c_str() ) == false )
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

Ptr<Data> Assets::GetFileData( const char* file )
{
	magicalAssert( file, "should not be nullptr." );

	std::string abs_path = GetAssetsAbsFilename( file );
	magicalAssert( !abs_path.empty(), StringUtils::Format<512>( "get assets file data failed! file(%s) doesn't exist.", file ).c_str() );

	FILE* fp = fopen( abs_path.c_str(), "rb" );
	if( fp == nullptr )
	{
		magicalSetLastErrorA( StringUtils::Format<512>( "get assets file data failed! file(%s).", file ).c_str() );
		magicalLogLastError();
		return nullptr;
	}

	size_t size, read_size = 0;
	fseek( fp, 0, SEEK_END );
	size = (size_t) ftell( fp );
	fseek( fp, 0, SEEK_SET );

	Ptr<Data> data = Data::Create( size + 1 );
	read_size = fread( data->cPtr(), sizeof( char ), size, fp );
	data->Realloc( read_size + 1 );
	data->cPtr()[ read_size ] = 0;
	fclose( fp );

	return data;
}

NS_MAGICAL_END