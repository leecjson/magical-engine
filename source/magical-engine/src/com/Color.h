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
#ifndef __COLOR_H__
#define __COLOR_H__

#include "magical-macros.h"
#include <stdint.h>

NAMESPACE_MAGICAL

struct Color4f
{
	float r;
	float g;
	float b;
	float a;

public:
	static const Color4f Red;        // 红
	static const Color4f Green;      // 绿
	static const Color4f Blue;       // 蓝
	static const Color4f White;      // 白
	static const Color4f Black;      // 黑
	static const Color4f Yello;      // 黄
	static const Color4f Magenta;    // 洋红
	static const Color4f Cyan;       // 青
	static const Color4f DarkGray;   // 深灰
	static const Color4f LightGray;  // 浅灰
	static const Color4f Brown;      // 褐
	static const Color4f Orange;     // 南瓜橙
	static const Color4f Pink;       // 粉红
	static const Color4f Purple;     // 紫

public:
	inline Color4f( float r, float g, float b, float a ) : r( r ), g( g ), b( b ), a( a ) { }
	inline Color4f( void ) { }
};

struct Color4b
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

public:
	static const Color4b Red;        // 红
	static const Color4b Green;      // 绿
	static const Color4b Blue;       // 蓝
	static const Color4b White;      // 白
	static const Color4b Black;      // 黑
	static const Color4b Yello;      // 黄
	static const Color4b Magenta;    // 洋红
	static const Color4b Cyan;       // 青
	static const Color4b DarkGray;   // 深灰
	static const Color4b LightGray;  // 浅灰
	static const Color4b Brown;      // 褐
	static const Color4b Orange;     // 南瓜橙
	static const Color4b Pink;       // 粉红
	static const Color4b Purple;     // 紫

public:
	inline Color4b( uint8_t r, uint8_t g, uint8_t b, uint8_t a ) : r( r ), g( g ), b( b ), a( a ) { }
	inline Color4b( void ) { }
};

NAMESPACE_END

#endif //__COLOR_H__