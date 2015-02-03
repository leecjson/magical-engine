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
#ifndef __C_VECTOR2_H__
#define __C_VECTOR2_H__

#include "../cUtility.h"

#pragma pack( push )
#pragma pack( 4 )
typedef struct cVector2 {
	float x;
	float y;
} cVector2;
#pragma pack( pop )

#include "cVector3.h"
#include "cVector4.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalVector2Equals( const cVector2* v1, const cVector2* v2 );
MAGICALAPI_MATH cBool magicalVector2IsZero( const cVector2* v );
MAGICALAPI_MATH cBool magicalVector2IsOne( const cVector2* v );
MAGICALAPI_MATH cBool magicalVector2IsNormalized( const cVector2* v );

MAGICALAPI_MATH void magicalVector2Fill( cVector2* out, float x, float y );
MAGICALAPI_MATH void magicalVector2Copy( cVector2* out, const cVector2* v );
MAGICALAPI_MATH void magicalVector2SetZero( cVector2* out );
MAGICALAPI_MATH void magicalVector2SetOne( cVector2* out );

MAGICALAPI_MATH void magicalVector2FromVector3( cVector2* out, const cVector3* v );
MAGICALAPI_MATH void magicalVector2FromVector4( cVector2* out, const cVector4* v );

MAGICALAPI_MATH void magicalVector2AddScalar( cVector2* out, const cVector2* v, float a );
MAGICALAPI_MATH void magicalVector2Add( cVector2* out, const cVector2* v1, const cVector2* v2 );
MAGICALAPI_MATH void magicalVector2SubScalar( cVector2* out, const cVector2* v, float a );
MAGICALAPI_MATH void magicalVector2Sub( cVector2* out, const cVector2* v1, const cVector2* v2 );
MAGICALAPI_MATH void magicalVector2MulScalar( cVector2* out, const cVector2* v, float a );
MAGICALAPI_MATH void magicalVector2Mul( cVector2* out, const cVector2* v1, const cVector2* v2 );
MAGICALAPI_MATH void magicalVector2DivScalar( cVector2* out, const cVector2* v, float a );
MAGICALAPI_MATH void magicalVector2Div( cVector2* out, const cVector2* v1, const cVector2* v2 );

MAGICALAPI_MATH float magicalVector2Dot( const cVector2* v1, const cVector2* v2 );
MAGICALAPI_MATH float magicalVector2Cross( const cVector2* v1, const cVector2* v2 );
MAGICALAPI_MATH float magicalVector2DistanceBetween( const cVector2* v1, const cVector2* v2 );
MAGICALAPI_MATH float magicalVector2DistanceBetweenSq( const cVector2* v1, const cVector2* v2 );
MAGICALAPI_MATH float magicalVector2Length( const cVector2* v );
MAGICALAPI_MATH float magicalVector2LengthSq( const cVector2* v );
MAGICALAPI_MATH float magicalVector2AngleBetween( const cVector2* v1, const cVector2* v2 );

MAGICALAPI_MATH void magicalVector2Clamp( cVector2* out, const cVector2* v, const cVector2* min, const cVector2* max );
MAGICALAPI_MATH void magicalVector2Negate( cVector2* out, const cVector2* v );
MAGICALAPI_MATH void magicalVector2Normalize( cVector2* out, const cVector2* v );
MAGICALAPI_MATH void magicalVector2Rotate( cVector2* out, const cVector2* v, float a );
MAGICALAPI_MATH void magicalVector2Scale( cVector2* out, const cVector2* v, float s );
MAGICALAPI_MATH void magicalVector2MidPointBetween( cVector2* out, const cVector2* v1, const cVector2* v2 );
MAGICALAPI_MATH void magicalVector2Project( cVector2* out, const cVector2* p, const cVector2* n );

#ifdef __cplusplus
}
#endif

#endif //__C_VECTOR2_H__