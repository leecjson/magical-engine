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
#ifndef __PLATFORM_MACROS_H__
#define __PLATFORM_MACROS_H__

/*
MAGICAL_WIN32
MAG_ANDROID
MAG_IOS
MAG_LINUX
MAG_MAC
*/
#ifdef _WIN32
#define MAGICAL_WIN32
#define MAGICAL_PLATFORM "Win32"
#endif

#if !defined( __cplusplus )
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif
#endif

#if !defined( MAGICALAPI )
#define MAGICALAPI extern
#endif
#if !defined( MAGICALAPI_USER )
#define MAGICALAPI_USER extern
#endif

#endif //__PLATFORM_MACROS_H__