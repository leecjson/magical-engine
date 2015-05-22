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
#ifndef __C_VECTOR4_H__
#define __C_VECTOR4_H__

#include "c-utility.h"

#pragma pack( push )
#pragma pack( 4 )
typedef struct cVector4 {
	float x;
	float y;
	float z;
	float w;
} cVector4;
#pragma pack( pop )

#include "c-vector2.h"
#include "c-vector3.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalVector4Equals( const cVector4* v1, const cVector4* v2 );
MAGICALAPI_MATH cBool magicalVector4IsZero( const cVector4* v );
MAGICALAPI_MATH cBool magicalVector4IsOne( const cVector4* v );
MAGICALAPI_MATH cBool magicalVector4IsNormalized( const cVector4* v );

MAGICALAPI_MATH void magicalVector4Fill( cVector4* out, float x, float y, float z, float w );
MAGICALAPI_MATH void magicalVector4Copy( cVector4* out, const cVector4* v );
MAGICALAPI_MATH void magicalVector4SetZero( cVector4* out );
MAGICALAPI_MATH void magicalVector4SetOne( cVector4* out );
MAGICALAPI_MATH void magicalVector4FromVector2( cVector4* out, const cVector2* v );
MAGICALAPI_MATH void magicalVector4FromVector3( cVector4* out, const cVector3* v );

MAGICALAPI_MATH void magicalVector4AddScalar( cVector4* out, const cVector4* v, float a );
MAGICALAPI_MATH void magicalVector4Add( cVector4* out, const cVector4* v1, const cVector4* v2 );
MAGICALAPI_MATH void magicalVector4SubScalar( cVector4* out, const cVector4* v, float a );
MAGICALAPI_MATH void magicalVector4Sub( cVector4* out, const cVector4* v1, const cVector4* v2 );
MAGICALAPI_MATH void magicalVector4MulScalar( cVector4* out, const cVector4* v, float a );
MAGICALAPI_MATH void magicalVector4Mul( cVector4* out, const cVector4* v1, const cVector4* v2 );
MAGICALAPI_MATH void magicalVector4DivScalar( cVector4* out, const cVector4* v, float a );
MAGICALAPI_MATH void magicalVector4Div( cVector4* out, const cVector4* v1, const cVector4* v2 );

MAGICALAPI_MATH float magicalVector4Dot( const cVector4* v1, const cVector4* v2 );
MAGICALAPI_MATH float magicalVector4DistanceBetween( const cVector4* v1, const cVector4* v2 );
MAGICALAPI_MATH float magicalVector4DistanceBetweenSq( const cVector4* v1, const cVector4* v2 );
MAGICALAPI_MATH float magicalVector4Length( const cVector4* v );
MAGICALAPI_MATH float magicalVector4LengthSq( const cVector4* v );
MAGICALAPI_MATH float magicalVector4AngleBetween( const cVector4* v1, const cVector4* v2 );

MAGICALAPI_MATH void magicalVector4Clamp( cVector4* out, const cVector4* v, const cVector4* min, const cVector4* max );
MAGICALAPI_MATH void magicalVector4Negate( cVector4* out, const cVector4* v );
MAGICALAPI_MATH void magicalVector4Normalize( cVector4* out, const cVector4* v );
MAGICALAPI_MATH void magicalVector4Scale( cVector4* out, const cVector4* v, float s );
MAGICALAPI_MATH void magicalVector4MidPointBetween( cVector4* out, const cVector4* v1, const cVector4* v2 );
MAGICALAPI_MATH void magicalVector4Project( cVector4* out, const cVector4* p, const cVector4* n );

#ifdef __cplusplus
}
#endif

#endif //__C_VECTOR4_H__