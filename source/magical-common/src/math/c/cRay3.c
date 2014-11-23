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
#ifndef __C_AABB3_H__
#define __C_AABB3_H__

#include "../MathMacros.h"

#include "cVec3.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef float cAABB[6];

MAGICALAPI_MATH void magicalAABB3FillScalars( cAABB out,
	const float min_x, const float min_y, const float min_z,
	const float max_x, const float max_y, const float max_z );
MAGICALAPI_MATH void magicalAABB3Fill( cAABB out, const cAABB aabb );
MAGICALAPI_MATH void magicalAABB3FillVec3( cAABB out, const cVec3 min, const cVec3 max );

MAGICALAPI_MATH void magicalAABB3ExpandScalars( cAABB out, const cAABB aabb, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalAABB3Expand( cAABB out, const cAABB aabb, const cVec3 v );
MAGICALAPI_MATH void magicalAABB3Merge( cAABB out, const cAABB aabb1, const cAABB aabb2 );
MAGICALAPI_MATH void magicalAABB3Center( cVec3 out, const cAABB aabb );

MAGICALAPI_MATH float magicalAABB3Size( const cAABB aabb );
MAGICALAPI_MATH float magicalAABB3DiameterX( const cAABB aabb );
MAGICALAPI_MATH float magicalAABB3DiameterY( const cAABB aabb );
MAGICALAPI_MATH float magicalAABB3DiameterZ( const cAABB aabb );

MAGICALAPI_MATH cBool magicalAABB3Intersects( const cAABB aabb1, const cAABB aabb2 );
//MAGICALAPI_MATH cBool magicalAABB3IntersectsPlane(const C3DPlane* plane,int type);
//MAGICALAPI_MATH cBool magicalAABB3IntersectsSphere(  )
MAGICALAPI_MATH cBool magicalAABB3ContainsPoint( const cAABB aabb, const cVec3 point );





#ifdef __cplusplus
}
#endif

#endif //__C_AABB3_H__