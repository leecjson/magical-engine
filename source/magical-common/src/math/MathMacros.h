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
#ifndef __MATH_MACROS_H__
#define __MATH_MACROS_H__

#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>

#ifndef MAGICAL_ENGINE
#define MAGICAL_MATH_CACHED_POOL_ENABLE 0
#else
#define MAGICAL_MATH_CACHED_POOL_ENABLE 1
#endif

#ifndef MAGICALAPI_MATH
#define MAGICALAPI_MATH
#endif

#ifndef MAGICAL_DEBUG
#define magicalMathAssert( __con, __msg )
#else
#ifndef magicalMathAssert
#define magicalMathAssert( __con, __msg ) do{                 \
	if( !( __con ) ) {                                        \
		assert( ( __con ) && __msg );                         \
	}                                                         \
	} while(0)
#endif
#endif

typedef unsigned char cBoolean;
#define TOFLOAT( __a ) ( (float*)( __a ) )

/*
 constant macros
 */
#define MAGICAL_DBL_PI 3.14159265358979323846
#define MAGICAL_DBL_2PI 6.28318530717958647692
#define MAGICAL_DBL_HALF_PI 1.57079632679489661923

#define MAGICAL_FLT_PI 3.14159265358979323846f
#define MAGICAL_FLT_2PI 6.28318530717958647692f
#define MAGICAL_FLT_HALF_PI 1.57079632679489661923f
#define MAGICAL_FLT_EPSILON 0.000001f

#define MAGICAL_MAT4_SIZE sizeof(float) * 0xF

/*
 matrix4x4 macros
 */
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

/*
 function macros
 */
#define magicalMax( __x, __y ) ( ( __x ) > ( __y ) ? ( __x ) : ( __y ) )
#define magicalMin( __x, __y ) ( ( __x ) < ( __y ) ? ( __x ) : ( __y ) )

#define magicalFltEqual( __x, __y ) ( fabsf( ( __x ) - ( __y ) ) < MAGICAL_FLT_EPSILON )
#define magicalFltIsZero( __x ) ( fabsf( __x ) < MAGICAL_FLT_EPSILON )

#define magicalDegToRad( __x ) ( ( __x ) * 0.0174532925f )
#define magicalRadToDeg( __x ) ( ( __x ) * 57.29577951f )

#define magicalCosf( __x ) cosf( ( __x ) )
#define magicalSinf( __x ) sinf( ( __x ) )
#define magicalTanf( __x ) tanf( ( __x ) )

__inline void magicalSinfCosf( float* s, float* c, float theta )
{
	*s = magicalSinf( theta );
	*c = magicalCosf( theta );
}

__inline float magicalAcosf( float c )
{
	if( c <= -1.0f ) 
		return MAGICAL_FLT_PI;
	if( c >= 1.0f ) 
		return 0.0f;

	return acosf( c );
}


#endif //__MATH_MACROS_H__