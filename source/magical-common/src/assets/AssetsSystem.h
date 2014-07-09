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
#ifndef __ASSETS_SYSTEM_H__
#define __ASSETS_SYSTEM_H__

#include "PlatformMacros.h"

#include <vector>
#include <string>
#include <unordered_map>

<<<<<<< HEAD:source/magical-common/src/file/FileSystem.h
class FileSystem
=======
#include "PlatformMacros.h"
#include "Object.h"
#include "Data.h"

class AssetsSystem
>>>>>>> origin/master:source/magical-common/src/assets/AssetsSystem.h
{
public:
	static void init( void );
	static void delc( void );

public:
<<<<<<< HEAD:source/magical-common/src/file/FileSystem.h
	static void addSearchPath( const std::string& path );
	static void removeSearchPath( const std::string& path );
	static bool isAbsolutePath( const std::string& path );
	static bool isFileExist( const std::string& file );
	static const std::string toAbsolutePath( const std::string& path );
	static const std::vector<std::string>& getSearchPaths( void );
	//static unsigned char* getFileData()
=======
	static void addSearchPath( const char* path );
	static void removeSearchPath( const char* path );
	static void clearSearchPath( void );
	static bool isAssetsFileExist( const char* file_name );
	static Data getAssetsFile( const char* file_name );
>>>>>>> origin/master:source/magical-common/src/assets/AssetsSystem.h
	
};

#endif //__ASSETS_SYSTEM_H__
