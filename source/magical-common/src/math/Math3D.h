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
#ifndef __MATH_3D_H__
#define __MATH_3D_H__

#ifdef MAGICAL_ENGINE
#include "PlatformMacros.h"
#include "Common.h"
#endif

#include <cmath>
#include <cfloat>

#ifndef MAGICAL_ENGINE
#include <cassert>
#define magicalAssert( __con, __msg ) do{                     \
	if( !(__con) ) {                                          \
		assert( __con );                                      \
	}                                                         \
	} while(0)
#endif

#define magicalFltEqual( a, b ) ( std::fabs( ( a ) - ( b ) ) < FLT_EPSILON )
#define magicalFltIsZero( a ) ( std::fabs( a ) < FLT_EPSILON )
#define magicalDegToRad( c ) ( ( c ) * 0.0174532925f )
#define magicalRadToDeg( c ) ( ( c ) * 57.29577951f )
#define kMatrix4x4Size sizeof( float ) * 0xF

#define m11 m[0x0]
#define m12 m[0x1]
#define m13 m[0x2]
#define m14 m[0x3]
#define m21 m[0x4]
#define m22 m[0x5]
#define m23 m[0x6]
#define m24 m[0x7]
#define m31 m[0x8]
#define m32 m[0x9]
#define m33 m[0xA]
#define m34 m[0xB]
#define m41 m[0xC]
#define m42 m[0xD]
#define m43 m[0xE]
#define m44 m[0xF]

#endif //__MATH_3D_H__