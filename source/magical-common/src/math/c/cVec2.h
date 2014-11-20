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
#ifndef __C_VEC2_H__
#define __C_VEC2_H__

#include "../MathMacros.h"

typedef float cVec2[2];

#include "cVec3.h"
#include "cVec4.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBoolean magicalVec2Equals( const cVec2 v1, const cVec2 v2 );
MAGICALAPI_MATH cBoolean magicalVec2IsZero( const cVec2 v );
MAGICALAPI_MATH cBoolean magicalVec2IsOne( const cVec2 v );
MAGICALAPI_MATH cBoolean magicalVec2IsNormalize( const cVec2 v );

MAGICALAPI_MATH void magicalVec2FillScalars( cVec2 out, const float x, const float y );
MAGICALAPI_MATH void magicalVec2FillZero( cVec2 out );
MAGICALAPI_MATH void magicalVec2FillOne( cVec2 out );
MAGICALAPI_MATH void magicalVec2Fill( cVec2 out, const cVec2 v );

MAGICALAPI_MATH void magicalVec2FromVec3( cVec2 out, const cVec3 v );
MAGICALAPI_MATH void magicalVec2FromVec4( cVec2 out, const cVec4 v );

MAGICALAPI_MATH void magicalVec2AddScalar( cVec2 out, const cVec2 v, const float a );
MAGICALAPI_MATH void magicalVec2Add( cVec2 out, const cVec2 v1, const cVec2 v2 );
MAGICALAPI_MATH void magicalVec2SubScalar( cVec2 out, const cVec2 v, const float a );
MAGICALAPI_MATH void magicalVec2Sub( cVec2 out, const cVec2 v1, const cVec2 v2 );
MAGICALAPI_MATH void magicalVec2MulScalar( cVec2 out, const cVec2 v, const float a );
MAGICALAPI_MATH void magicalVec2Mul( cVec2 out, const cVec2 v1, const cVec2 v2 );
MAGICALAPI_MATH void magicalVec2DivScalar( cVec2 out, const cVec2 v, const float a );
MAGICALAPI_MATH void magicalVec2Div( cVec2 out, const cVec2 v1, const cVec2 v2 );

MAGICALAPI_MATH float magicalVec2Dot( const cVec2 v1, const cVec2 v2 );
MAGICALAPI_MATH float magicalVec2DistanceBetween( const cVec2 v1, const cVec2 v2 );
MAGICALAPI_MATH float magicalVec2DistanceBetweenSq( const cVec2 v1, const cVec2 v2 );
MAGICALAPI_MATH float magicalVec2Length( const cVec2 v );
MAGICALAPI_MATH float magicalVec2LengthSq( const cVec2 v );
MAGICALAPI_MATH float magicalVec2AngleBetween( const cVec2 v1, const cVec2 v2 );

MAGICALAPI_MATH void magicalVec2Clamp( cVec2 out, const cVec2 v, const cVec2 min, const cVec2 max );
MAGICALAPI_MATH void magicalVec2Negate( cVec2 out, const cVec2 v );
MAGICALAPI_MATH void magicalVec2Normalize( cVec2 out, const cVec2 v );
MAGICALAPI_MATH void magicalVec2Rotate( cVec2 out, const cVec2 v, const cVec2 point, const float angle );
MAGICALAPI_MATH void magicalVec2Scale( cVec2 out, const cVec2 v, const float s );
MAGICALAPI_MATH void magicalVec2MidPointBetween( cVec2 out, const cVec2 v1, const cVec2 v2 );
MAGICALAPI_MATH void magicalVec2Project( cVec2 out_h, cVec2 out_v, const cVec2 p, const cVec2 n );

#ifdef __cplusplus
}
#endif

#endif //__C_VEC2_H__