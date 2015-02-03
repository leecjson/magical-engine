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

#include "../cUtility.h"

#pragma pack( push )
#pragma pack( 4 )
typedef struct cSphere {
	float x;
	float y;
	float z;
	float r;
} cSphere;
#pragma pack( pop )

#include "../c1/cVector3.h"
#include "cRay3.h"
#include "cAABB.h"
#include "cPlane.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalSphereEquals( const cSphere* sp1, const cSphere* sp2 );
MAGICALAPI_MATH cBool magicalSphereIsZero( const cSphere* sp );
MAGICALAPI_MATH cBool magicalSphereIsOne( const cSphere* sp );

MAGICALAPI_MATH void magicalSphereFill( cSphere* out, float x, float y, float z, float r );
MAGICALAPI_MATH void magicalSphereCopy( cSphere* out, const cSphere* sp );
MAGICALAPI_MATH void magicalSphereSetCenterAndRadius( cSphere* out, const cVector3* center, float r );
MAGICALAPI_MATH void magicalSphereSetZero( cSphere* out );
MAGICALAPI_MATH void magicalSphereSetOne( cSphere* out );

MAGICALAPI_MATH cBool magicalSphereIntersects( const cSphere* sp1, const cSphere* sp2 );
MAGICALAPI_MATH cBool magicalSphereIntersectsAABB( const cSphere* sp, const cAABB* aabb );
MAGICALAPI_MATH cBool magicalSphereIntersectsPlane( const cSphere* sp, const cPlane* p );
MAGICALAPI_MATH void magicalSphereIntersectsRay3( cRayIntersectResult* out, const cSphere* sp, const cRay3* r3, cBool discard_inside );

MAGICALAPI_MATH cBool magicalSphereContainsPoint( const cSphere* sp, const cVector3* point );

#ifdef __cplusplus
}
#endif

#endif //__C_SPHERE_H__