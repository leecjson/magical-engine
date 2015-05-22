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
#ifndef __MAGICAL_MACROS_H__
#define __MAGICAL_MACROS_H__

#if defined( _WIN32 )
#define MAGICAL_WIN32 1
#define MAGICAL_PLATFORM "WIN32"
#define MAGICAL_TARGET MAGICAL_WIN32
#elif defined( ANDROID )
#define MAGICAL_ANDROID 2
#define MAGICAL_PLATFORM "ANDROID"
#define MAGICAL_TARGET MAGICAL_ANDROID
#elif defined( IOS )
#define MAGICAL_IOS 3
#define MAGICAL_PLATFORM "IOS"
#define MAGICAL_TARGET MAGICAL_IOS
#elif defined( MAC )
#define MAGICAL_MACOS 4
#define MAGICAL_PLATFORM "MAC-OS"
#define MAGICAL_TARGET MAGICAL_MACOS
#endif

#if !defined( MAGICALAPI )
#define MAGICALAPI
#endif

#if !defined( NAMESPACE_MAGICAL ) \
	&& !defined( NAMESPACE_END )
#define NAMESPACE_MAGICAL \
	namespace magical {
#define NAMESPACE_END \
	}
#endif

#if !defined( USING_NS_MAGICAL )
#define USING_NS_MAGICAL \
	using namespace magical
#endif

#if defined( MAGICAL_WIN32 )
#pragma execution_character_set( "utf-8" )
#endif

#endif //__MAGICAL_MACROS_H__