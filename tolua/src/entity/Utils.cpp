#include "Utils.h"
#include <windows.h>
#include <processenv.h>
#include <string.h>
#include <stdlib.h>
#include <string>

bool Utils::isAbsolutePath( const char* path )
{
#ifdef _WIN32
	if( strlen( path ) > 2
		&& ((path[0] >= 'a' && path[0] <= 'z') 
		|| ( path[0] >= 'A' && path[0] <= 'Z'))
		&& ( path[1] == ':') )
	{
		return true;
	}
	return false;
#endif
}

std::string Utils::getPathWithUnixStyle( const char* path )
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
    return std::move( ret );
}

std::string Utils::getDefaultSearchPath( void )
{
#ifdef _WIN32
	char buf[1024] = {0};
	GetCurrentDirectoryA( sizeof(buf)-1, buf );

	std::string ret = Utils::getPathWithUnixStyle( buf );
	ret.append( "/" );
	return std::move( ret );
#endif
}

bool Utils::isFileExist( const char* file_name )
{
#ifdef _WIN32
	std::string file_path = Utils::getPathWithUnixStyle( file_name );
	if( isAbsolutePath( file_path.c_str() ) == false )
	{
		std::string abs_path = getDefaultSearchPath() + file_path;
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
#endif
}

char* Utils::getFileData( const char* file_name )
{
	std::string abs_path;
	if( isAbsolutePath(file_name) )
	{
		abs_path = file_name;
	}
	else
	{
		abs_path = getDefaultSearchPath() + file_name;
	}

	if( isFileExist(abs_path.c_str()) == false )
	{
		printf("%s", "file does not exist!");
		return nullptr;
	}
	
	FILE* fp = fopen( abs_path.c_str(), "rb" );
	if( fp == nullptr )
	{
		printf("%s", "get file data failed! file(%s)", file_name);
		return nullptr;
	}

	size_t size = 0;
	fseek( fp, 0, SEEK_END );
	size = (size_t) ftell( fp );
	fseek( fp, 0, SEEK_SET );

	char* data = (char*) malloc( size + 1 );
	size_t read_size = fread( data, sizeof(char), size, fp );
	data[read_size] = '\0';

	fclose( fp );
	
	return data;
}