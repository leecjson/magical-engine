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
#ifndef __C_UTILITY_H__
#define __C_UTILITY_H__

#include <math.h>
#include <float.h>
#include <assert.h>
#include <stdlib.h>

#ifndef MAGICAL_ENGINE
	typedef unsigned char cBool;
	#ifndef cTrue
		#define cTrue 1
	#endif
	#ifndef cFalse
		#define cFalse 0
	#endif
#else
	#include "PlatformMacros.h"
#endif

#ifndef MAGICALAPI_MATH
	#define MAGICALAPI_MATH
#endif

#ifndef MAGICAL_DEBUG
	#define debugassert( con, msg )
#else
	#define debugassert( con, msg ) do{ \
		if( !( con ) ) {                \
			assert( ( con ) && msg );   \
		}}  while( 0 )
#endif

#define kPI 3.14159265358979323846f
#define k2PI 6.28318530717958647692f
#define kPIOver2 1.57079632679489661923f
#define kPIOver180 0.01745329251994329576f
#define k1OverPI 0.31830988618379067153f
#define k1Over2PI 0.15915494309189533576f
#define k180OverPI 57.2957795130823208768f
#define kNumberEpsilon 1.0e-007f
#define kQuaternionEpsilon 1.0e-006f
#define kVectorEpsilon 1.0e-005f
#define kRadianEpsilon 1.0e-005f
#define kDegreeEpsilon 1.0e-004f

#define magicalAlmostEqual( a, b, e ) ( fabs( (a) - (b) ) < e )
#define magicalAlmostZero( a, e ) ( fabs(a) < e )
#define magicalDegToRad( a ) ( (a) * kPIOver180 )
#define magicalRadToDeg( a ) ( (a) * k180OverPI )

/*-----------------------------------------------------------------------------*\
 * 在某些平台上，同时计算sin与cos更有效率 done
 *
 * s 返回sin(theta)
 * c 返回cos(theta)
 * theta 弧度
 *-----------------------------------------------------------------------------*/
__inline void magicalSinCos( float* s, float* c, float theta )
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
__inline float magicalSafeAcos( float theta )
{
	if( theta <= -1.0f ) 
		return kPI;
	if( theta >= 1.0f ) 
		return 0.0f;

	return acosf( theta );
}

/*-----------------------------------------------------------------------------*\
 * 转换c到-pi与pi之间 done
 *
 * c 弧度值
 * return 转换到-pi与pi之间的值
 *-----------------------------------------------------------------------------*/
__inline float magicalCorrectToPI( float theta )
{
	theta += kPI;
	theta -= floorf( theta * k1Over2PI ) * k2PI;
	theta -= kPI;
	return theta;
}

#endif //__C_UTILITY_H__