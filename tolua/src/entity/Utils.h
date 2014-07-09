#ifndef __UTILS_H__
#define __UTILS_H__

#include <vector>
#include <string>

class Utils
{
public:
	static bool isAbsolutePath( const char* path );
	static std::string getPathWithUnixStyle( const char* path );
	static std::string getDefaultSearchPath( void );
	static bool isFileExist( const char* file_name );
	static char* getFileData( const char* file_name );
	
};

#endif //__UTILS_H__