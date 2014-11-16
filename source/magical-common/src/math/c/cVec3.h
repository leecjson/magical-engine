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
#ifndef __C_VEC3_H__
#define __C_VEC3_H__

#include "../MathMacros.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef float cVec3[3];

MAGICALAPI_MATH cBoolean magicalVec3Equals( const cVec3 v1, const cVec3 v2 );
MAGICALAPI_MATH cBoolean magicalVec3IsZero( const cVec3 v );
MAGICALAPI_MATH cBoolean magicalVec3IsOne( const cVec3 v );
MAGICALAPI_MATH cBoolean magicalVec3IsNormalize( const cVec3 v );

MAGICALAPI_MATH void magicalVec3Fill( cVec3 out, float x, float y, float z );
MAGICALAPI_MATH void magicalVec3FillBy( cVec3 out, const cVec3 v );
MAGICALAPI_MATH void magicalVec3FillZero( cVec3 out );
MAGICALAPI_MATH void magicalVec3FillOne( cVec3 out );

MAGICALAPI_MATH void magicalVec3AddScalar( cVec3 out, const cVec3 v, float a );
MAGICALAPI_MATH void magicalVec3Add( cVec3 out, const cVec3 v1, const cVec3 v2 );
MAGICALAPI_MATH void magicalVec3SubScalar( cVec3 out, const cVec3 v, float a );
MAGICALAPI_MATH void magicalVec3Sub( cVec3 out, const cVec3 v1, const cVec3 v2 );
MAGICALAPI_MATH void magicalVec3MulScalar( cVec3 out, const cVec3 v, float a );
MAGICALAPI_MATH void magicalVec3Mul( cVec3 out, const cVec3 v1, const cVec3 v2 );
MAGICALAPI_MATH void magicalVec3DivScalar( cVec3 out, const cVec3 v, float a );
MAGICALAPI_MATH void magicalVec3Div( cVec3 out, const cVec3 v1, const cVec3 v2 );

MAGICALAPI_MATH float magicalVec3Dot( const cVec3 v1, const cVec3 v2 );
MAGICALAPI_MATH float magicalVec3DistanceBetween( const cVec3 v1, const cVec3 v2 );
MAGICALAPI_MATH float magicalVec3DistanceBetweenSq( const cVec3 v1, const cVec3 v2 );
MAGICALAPI_MATH float magicalVec3Length( const cVec3 v );
MAGICALAPI_MATH float magicalVec3LengthSq( const cVec3 v );
MAGICALAPI_MATH float magicalVec3AngleBetween( const cVec3 v1, const cVec3 v2 );

MAGICALAPI_MATH void magicalVec3Cross( cVec3 out, const cVec3 v1, const cVec3 v2 );
MAGICALAPI_MATH void magicalVec3Clamp( cVec3 out, const cVec3 v, const cVec3 min, const cVec3 max );
MAGICALAPI_MATH void magicalVec3Negate( cVec3 out, const cVec3 v );
MAGICALAPI_MATH void magicalVec3Normalize( cVec3 out, const cVec3 v );
MAGICALAPI_MATH void magicalVec3Scale( cVec3 out, const cVec3 v, float s );
MAGICALAPI_MATH void magicalVec3MidPointBetween( cVec3 out, const cVec3 v1, const cVec3 v2 );
MAGICALAPI_MATH void magicalVec3Project( cVec3 out_h, cVec3 out_v, const cVec3 p, const cVec3 n );

#ifdef __cplusplus
}
#endif

#endif //__C_VEC3_H__