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
#ifndef __C_SPHERE_H__
#define __C_SPHERE_H__

#include "cUtility.h"

#pragma pack( push )
#pragma pack( 4 )
typedef struct cSphere3 {
	float x;
	float y;
	float z;
	float r;
} cSphere3;
#pragma pack( pop )

#include "cRay3.h"
#include "cAABB3.h"
#include "cPlane3.h"
#include "cVector3.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalSphere3Equals( const cSphere3* sp1, const cSphere3* sp2 );
MAGICALAPI_MATH cBool magicalSphere3IsZero( const cSphere3* sp );
MAGICALAPI_MATH cBool magicalSphere3IsOne( const cSphere3* sp );

MAGICALAPI_MATH void magicalSphere3Fill( cSphere3* out, float x, float y, float z, float r );
MAGICALAPI_MATH void magicalSphere3Copy( cSphere3* out, const cSphere3* sp );
MAGICALAPI_MATH void magicalSphere3SetCenterAndRadius( cSphere3* out, const cVector3* center, float r );
MAGICALAPI_MATH void magicalSphere3SetZero( cSphere3* out );
MAGICALAPI_MATH void magicalSphere3SetOne( cSphere3* out );

MAGICALAPI_MATH cBool magicalSphere3Intersects( const cSphere3* sp1, const cSphere3* sp2 );
MAGICALAPI_MATH cBool magicalSphere3IntersectsAABB3( const cSphere3* sp, const cAABB3* aabb );
MAGICALAPI_MATH cBool magicalSphere3IntersectsPlane3( const cSphere3* sp, const cPlane3* p );
MAGICALAPI_MATH void magicalSphere3IntersectsRay3( cRayIntersectResult* out, const cSphere3* sp, const cRay3* r3, cBool discard_inside );

MAGICALAPI_MATH cBool magicalSphere3ContainsPoint( const cSphere3* sp, const cVector3* point );

#ifdef __cplusplus
}
#endif

#endif //__C_SPHERE_H__