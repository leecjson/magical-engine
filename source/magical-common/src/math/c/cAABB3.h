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

#include "cMathMacros.h"

typedef float cAABB3[6];

#include "cVec3.h"
#include "cPlane3.h"
#include "cMat4.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalAABB3IsEmpty( const cAABB3 aabb );

MAGICALAPI_MATH void magicalAABB3FillScalars( cAABB3 out, const float min_x, const float min_y, const float min_z, const float max_x, const float max_y, const float max_z );
MAGICALAPI_MATH void magicalAABB3FillBox( cAABB3 out, const cVec3 center, const float width, const float height, const float depth );
MAGICALAPI_MATH void magicalAABB3FillEmpty( cAABB3 out );
MAGICALAPI_MATH void magicalAABB3Fill( cAABB3 out, const cAABB3 aabb );

MAGICALAPI_MATH void magicalAABB3FromVec3( cAABB3 out, const cVec3 min, const cVec3 max );

MAGICALAPI_MATH void magicalAABB3ExtendScalars( cAABB3 out, const cAABB3 aabb, const float x, const float y, const float z );
MAGICALAPI_MATH void magicalAABB3Extend( cAABB3 out, const cAABB3 aabb, const cVec3 v );
MAGICALAPI_MATH void magicalAABB3Merge( cAABB3 out, const cAABB3 aabb1, const cAABB3 aabb2 );
MAGICALAPI_MATH void magicalAABB3Center( cVec3 out, const cAABB3 aabb );

MAGICALAPI_MATH float magicalAABB3Size( const cAABB3 aabb );
MAGICALAPI_MATH float magicalAABB3DiameterX( const cAABB3 aabb );
MAGICALAPI_MATH float magicalAABB3DiameterY( const cAABB3 aabb );
MAGICALAPI_MATH float magicalAABB3DiameterZ( const cAABB3 aabb );

MAGICALAPI_MATH void magicalAABB3NearestPoint( cVec3 out, const cAABB3 aabb, const cVec3 point );
MAGICALAPI_MATH void magicalAABB3Transform( cAABB3 out, const cAABB3 aabb, const cMat4 m );

MAGICALAPI_MATH cBool magicalAABB3Intersects( const cAABB3 aabb1, const cAABB3 aabb2 );
MAGICALAPI_MATH cBool magicalAABB3IntersectsPlane3( const cAABB3 aabb, const cPlane3 p );
MAGICALAPI_MATH cBool magicalAABB3IntersectsSphere3( const cAABB3 aabb, const cSphere3 sp );

MAGICALAPI_MATH cBool magicalAABB3GetIntersectsAABB3( cAABB3 out, const cAABB3 aabb1, const cAABB3 aabb2 );

MAGICALAPI_MATH cBool magicalAABB3ContainsPoint( const cAABB3 aabb, const cVec3 point );





#ifdef __cplusplus
}
#endif

#endif //__C_AABB3_H__