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
#include "FileSystem.h"
#include <string.h>
#include <windows.h>
#include "Common.h"
#include "Utils.h"

static std::unordered_map<std::string, std::string> s_absolute_path_cache_map;
static std::vector<std::string> s_search_path_array;
static std::string s_default_search_path;

static std::string win32ConvertPathFormatToUnixStyle( const char* path );
static std::string win32GetDefaultSearchPath( void );


void FileSystem::init( void )
{
	s_default_search_path = win32GetDefaultSearchPath();
	if( s_default_search_path.empty() )
	{
		magicalSetLastErrorInfo("default_search_path is empty, win32GetDefaultSearchPath() error");
		magicalLogLastError();
		return;
	}
	s_search_path_array.push_back( s_default_search_path );
	
}

void FileSystem::delc( void )
{
	
}

void FileSystem::addSearchPath( const char* path )
{
	magicalAssert( path, "should not nullptr" );

	std::string unix_path = win32ConvertPathFormatToUnixStyle( path );
	std::string prefix;
	if( isAbsolutePath( unix_path.c_str() ) == false )
	{
		prefix = s_default_search_path;
	}

	std::string real_path = prefix + unix_path;
	if( real_path.length() > 0 && real_path[real_path.length() - 1] != '/' )
	{
		real_path += "/";
	}
	s_search_path_array.push_back( real_path );
}

void FileSystem::removeSearchPath( const char* path )
{
	magicalAssert( path, "should not nullptr" );

	std::string unix_path = win32ConvertPathFormatToUnixStyle( path );
	auto path_itr = std::find( s_search_path_array.begin(), s_search_path_array.end(), unix_path );
	if( path_itr != s_search_path_array.end() )
	{
		s_search_path_array.erase( path_itr );
	}
}

const std::vector<std::string>& FileSystem::getSearchPaths( void )
{
	return s_search_path_array;
}

bool FileSystem::isAbsolutePath( const char* path )
{
	if( strlen( path ) > 2
		&& ((path[0] >= 'a' && path[0] <= 'z') 
		|| ( path[0] >= 'A' && path[0] <= 'Z'))
		&& ( path[1] == ':') )
	{
		return true;
	}
	return false;
}

const std::string FileSystem::toAbsolutePath( const char* path )
{
	magicalAssert( path, "should not nullptr" );

	if( isAbsolutePath(path) )
	{
		return path;
	}
	std::string unix_path = win32ConvertPathFormatToUnixStyle( path );

	auto cache_itr = s_absolute_path_cache_map.find( unix_path );
	if( cache_itr != s_absolute_path_cache_map.end() )
	{
		return cache_itr->second;
	}

	std::string abs_path;
	for( const auto& prefix : s_search_path_array )
	{
		abs_path = prefix + unix_path;
		int ret = GetFileAttributesA( abs_path.c_str() );
		if( ret != -1 )
		{
			s_absolute_path_cache_map.insert( std::make_pair(unix_path, abs_path) );
			return std::move( abs_path );
		}
	}
	return "";
}

bool FileSystem::isFileExist( const char* file )
{
	magicalAssert( file, "should not nullptr" );

	if( strlen(file) == 0 )
	{
		return false;
	}

	std::string file_path = win32ConvertPathFormatToUnixStyle( file );
	if( isAbsolutePath( file_path.c_str() ) == false )
	{
		std::string abs_path;
		for( const auto& prefix : s_search_path_array )
		{
			abs_path = prefix + file_path;
			int ret = GetFileAttributesA( abs_path.c_str() );
			if( ret != -1 )
			{
				return true;
			}
		}
	}
	else
	{
		return GetFileAttributesA( file_path.c_str() ) != -1 ? true : false;
	}

	return false;
}

//Data FileSystem::getFileData( const std::string& file_name, const std::string& mode )
//{
//	std::string abs_path = toAbsolutePath( file_name );
//	magicalAssert( abs_path.empty() == false, Utils::format<128>("Get file data failed! file(%s) doesn't exist!", file_name).c_str() );
//
//	return newData();
//}

static std::string win32ConvertPathFormatToUnixStyle( const char* path )
{
    std::string ret = path;
    int len = ret.length();
    for( int i = 0; i < len; ++i )
    {
        if( ret[i] == '\\' )
        {
            ret[i] = '/';
        }
    }
    return std::move(ret);
}

static std::string win32GetDefaultSearchPath( void )
{
	char buf[kMaxPathLength] = {0};
	GetCurrentDirectoryA( sizeof(buf)-1, buf );

	std::string ret = win32ConvertPathFormatToUnixStyle( buf );
	ret.append("/");
	return std::move(ret);
}