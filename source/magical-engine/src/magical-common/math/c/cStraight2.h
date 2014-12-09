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
#ifndef __C_STRAIGHT2_H__
#define __C_STRAIGHT2_H__

#include "cUtility.h"

typedef float cStraight2[3];

#include "cVector2.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalStraight2Equals( const cStraight2 st1, const cStraight2 st2 );
MAGICALAPI_MATH cBool magicalStraight2IsZero( const cStraight2 st );

MAGICALAPI_MATH void magicalStraight2FillPointAndNormal( cStraight2 out, const cVector2 p, const cVector2 n );
MAGICALAPI_MATH void magicalStraight2FillNormalAndDistance( cStraight2 out, const cVector2 n, const float d );
MAGICALAPI_MATH void magicalStraight2FillScalars( cStraight2 out, const float x, const float y, const float d );
MAGICALAPI_MATH void magicalStraight2FillZero( cStraight2 out );
MAGICALAPI_MATH void magicalStraight2Fill( cStraight2 out, const cStraight2 st );

MAGICALAPI_MATH int magicalStraight2ClassifyPoint( const cStraight2 st, const cVec3 point );
MAGICALAPI_MATH int magicalStraight2ClassifyStraight2( const cStraight2 st1, const cStraight2 st2 );

MAGICALAPI_MATH cBool magicalStraight2Intersects( const cStraight2 st1, const cStraight2 st2 );

MAGICALAPI_MATH cBool magicalStraight2ContainsPoint( const cStraight2 st, const cVec3 point );


#ifdef __cplusplus
}
#endif

#endif //__C_STRAIGHT2_H__