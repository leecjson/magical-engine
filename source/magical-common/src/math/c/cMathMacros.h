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
#ifndef __C_MATH_MACROS_H__
#define __C_MATH_MACROS_H__

#include <math.h>
#include <float.h>
#include <assert.h>
#include <stdlib.h>

#if defined MAGICAL_ENGINE
#include "PlatformMacros.h"
#else
typedef unsigned char cBool;
#define cTrue  1
#define cFalse 0
#endif

#ifndef MAGICALAPI_MATH
#define MAGICALAPI_MATH
#endif

//#ifndef MAGICAL_ENGINE
//#define MAGICAL_MATH_CACHED_POOL_ENABLE 0
//#else
//#define MAGICAL_MATH_CACHED_POOL_ENABLE 1
//#define TOFLOAT( __a ) ( (float*)( __a ) )
//#endif

#define MAGICAL_MATH_EPSILON 0.00001f
#define MAGICAL_MATH_PI 3.14159265358979323846f
#define MAGICAL_MATH_2PI 6.28318530717958647692f
#define MAGICAL_MATH_PI_OVER_2 1.57079632679489661923f
#define MAGICAL_MATH_PI_OVER_180 0.01745329251994329576f
#define MAGICAL_MATH_1_OVER_PI 0.31830988618379067153f
#define MAGICAL_MATH_1_OVER_2PI 0.15915494309189533576f
#define MAGICAL_MATH_180_OVER_PI 57.2957795130823208768f

#define magicalAlmostEqual( a, b ) ( fabs( (a) - (b) ) < MAGICAL_MATH_EPSILON )
#define magicalAlmostZero( a ) ( fabs(a) < MAGICAL_MATH_EPSILON )
#define magicalDegToRad( a ) ( (a) * MAGICAL_MATH_PI_OVER_180 )
#define magicalRadToDeg( a ) ( (a) * MAGICAL_MATH_180_OVER_PI )

/*-----------------------------------------------------------------------------*\
 * 在某些平台上，同时计算sin与cos更有效率 done
 *
 * s 返回sin(theta)
 * c 返回cos(theta)
 * theta 弧度
 *-----------------------------------------------------------------------------*/
__inline void magicalSinCos( float* s, float* c, const float theta )
{
	*s = sinf( theta );
	*c = cosf( theta );
}

/*-----------------------------------------------------------------------------*\
 * 安全的反余弦函数 done
 *
 * c 余弦值
 * return theta
 *-----------------------------------------------------------------------------*/
__inline float magicalSafeAcos( const float c )
{
	if( c <= -1.0f ) 
		return MAGICAL_MATH_PI;
	if( c >= 1.0f ) 
		return 0.0f;

	return acosf( c );
}

/*-----------------------------------------------------------------------------*\
 * 转换c到-pi与pi之间 done
 *
 * c 弧度值
 * return 转换到-pi与pi之间的值
 *-----------------------------------------------------------------------------*/
__inline float magicalCorrectToPI( float c )
{
	c += MAGICAL_MATH_PI;
	c -= floorf( c * MAGICAL_MATH_1_OVER_2PI ) * MAGICAL_MATH_2PI;
	c -= MAGICAL_MATH_PI;
	return c;
}

#if defined MAGICAL_DEBUG
#define debugassert( con, msg ) do{ \
	if( !( con ) ) {                \
		assert( ( con ) && msg );   \
	}}  while( 0 )
#else
#define debugassert( con, msg )
#endif

/* Vec2 Vec3 Vec4 Plane3 Sphere3 */

#define _x [0x0]
#define _y [0x1]
#define _z [0x2]
#define _w [0x3]
#define _d [0x3]
#define _r [0x3]

/* Ray3 */
#define _o_x [0x0]
#define _o_y [0x1]
#define _o_z [0x2]
#define _d_x [0x3]
#define _d_y [0x4]
#define _d_z [0x5]

/* EulerAngles */

#define _yaw [0x0]
#define _pitch [0x1]
#define _roll [0x2]

/* AABB3 */

#define _min_x [0x0]
#define _min_y [0x1]
#define _min_z [0x2]
#define _max_x [0x3]
#define _max_y [0x4]
#define _max_z [0x5]

/* Mat4 */

#define _m11 [0x0]
#define _m12 [0x1]
#define _m13 [0x2]
#define _m14 [0x3]
#define _m21 [0x4]
#define _m22 [0x5]
#define _m23 [0x6]
#define _m24 [0x7]
#define _m31 [0x8]
#define _m32 [0x9]
#define _m33 [0xA]
#define _m34 [0xB]
#define _m41 [0xC]
#define _m42 [0xD]
#define _m43 [0xE]
#define _m44 [0xF]

//typedef enum Plane3Classification {
//	kInFrontOfPlane = 1,
//	kOnPlane = 0,
//	kBehindPlane = -1,
//} Plane3Classification;


#endif //__C_MATH_MACROS_H__