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
#ifndef __C_VEC4_H__
#define __C_VEC4_H__

#include "../MathMacros.h"

typedef float cVec4[4];

#include "cVec2.h"
#include "cVec3.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBoolean magicalVec4Equals( const cVec4 v1, const cVec4 v2 );
MAGICALAPI_MATH cBoolean magicalVec4IsZero( const cVec4 v );
MAGICALAPI_MATH cBoolean magicalVec4IsOne( const cVec4 v );
MAGICALAPI_MATH cBoolean magicalVec4IsNormalize( const cVec4 v );

MAGICALAPI_MATH void magicalVec4FillScalars( cVec4 out, const float x, const float y, const float z, const float w );
MAGICALAPI_MATH void magicalVec4FillZero( cVec4 out );
MAGICALAPI_MATH void magicalVec4FillOne( cVec4 out );
MAGICALAPI_MATH void magicalVec4Fill( cVec4 out, const cVec4 v );

MAGICALAPI_MATH void magicalVec4FromVec2( cVec4 out, const cVec2 v );
MAGICALAPI_MATH void magicalVec4FromVec3( cVec4 out, const cVec3 v );

MAGICALAPI_MATH void magicalVec4AddScalar( cVec4 out, const cVec4 v, const float a );
MAGICALAPI_MATH void magicalVec4Add( cVec4 out, const cVec4 v1, const cVec4 v2 );
MAGICALAPI_MATH void magicalVec4SubScalar( cVec4 out, const cVec4 v, const float a );
MAGICALAPI_MATH void magicalVec4Sub( cVec4 out, const cVec4 v1, const cVec4 v2 );
MAGICALAPI_MATH void magicalVec4MulScalar( cVec4 out, const cVec4 v, const float a );
MAGICALAPI_MATH void magicalVec4Mul( cVec4 out, const cVec4 v1, const cVec4 v2 );
MAGICALAPI_MATH void magicalVec4DivScalar( cVec4 out, const cVec4 v, const float a );
MAGICALAPI_MATH void magicalVec4Div( cVec4 out, const cVec4 v1, const cVec4 v2 );

MAGICALAPI_MATH float magicalVec4Dot( const cVec4 v1, const cVec4 v2 );
MAGICALAPI_MATH float magicalVec4DistanceBetween( const cVec4 v1, const cVec4 v2 );
MAGICALAPI_MATH float magicalVec4DistanceBetweenSq( const cVec4 v1, const cVec4 v2 );
MAGICALAPI_MATH float magicalVec4Length( const cVec4 v );
MAGICALAPI_MATH float magicalVec4LengthSq( const cVec4 v );
MAGICALAPI_MATH float magicalVec4AngleBetween( const cVec4 v1, const cVec4 v2 );

MAGICALAPI_MATH void magicalVec4Clamp( cVec4 out, const cVec4 v, const cVec4 min, const cVec4 max );
MAGICALAPI_MATH void magicalVec4Negate( cVec4 out, const cVec4 v );
MAGICALAPI_MATH void magicalVec4Normalize( cVec4 out, const cVec4 v );
MAGICALAPI_MATH void magicalVec4Scale( cVec4 out, const cVec4 v, const float s );
MAGICALAPI_MATH void magicalVec4MidPointBetween( cVec4 out, const cVec4 v1, const cVec4 v2 );
MAGICALAPI_MATH void magicalVec4Project( cVec4 out_h, cVec4 out_v, const cVec4 p, const cVec4 n );

#ifdef __cplusplus
}
#endif

#endif //__C_VEC4_H__