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
#include "Common.h"
#include "Data.h"

class Assets
{
public:
	static void init( void );
	static void delc( void );

public:
	/* ------------------------------------------------------------------------- *\
	 * 重置资源路径为默认路径
	\* ------------------------------------------------------------------------- */
	static void resetAssetsPath( void );

	/* ------------------------------------------------------------------------- *\
	 * 设置资源的默认搜索路径，必须是以绝对路径格式传入
	\* ------------------------------------------------------------------------- */
	static void setAssetsPath( const char* path );

	/* ------------------------------------------------------------------------- *\
	 * 获取资源路径
	\* ------------------------------------------------------------------------- */
	static std::string getAssetsPath( void );

	/* ------------------------------------------------------------------------- *\
	 * 通过一个文件名或相对路径，获取与资源路径组合后的绝对文件路径
	\* ------------------------------------------------------------------------- */
	static std::string getAssetsAbsoluteFilename( const char* file_name );
	
	/* ------------------------------------------------------------------------- *\
	 * 检测某个资源路径下的文件是否存在
	\* ------------------------------------------------------------------------- */
	static bool isAssetsFileExist( const char* file_name );

	/* ------------------------------------------------------------------------- *\
	 * 获取资源路径下某个文件的数据
	\* ------------------------------------------------------------------------- */
	static Shared<Data> getAssetsFileData( const char* file_name );
};

#endif //__ASSETS_SYSTEM_H__