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
#ifndef __C_RAY3_H__
#define __C_RAY3_H__

#include "cUtility.h"

#pragma pack( push )
#pragma pack( 4 )
typedef struct cRay3 {
	float ox;
	float oy;
	float oz;
	float dx;
	float dy;
	float dz;
} cRay3;
#pragma pack( pop )

#pragma pack( push )
#pragma pack( 4 )
typedef struct cRayIntersectResult {
	cBool b;
	float t;
} cRayIntersectResult;
#pragma pack( pop )

#include "cVector3.h"
#include "cAABB3.h"
#include "cSphere3.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH cBool magicalRay3Equals( const cRay3* r31, const cRay3* r32 );
MAGICALAPI_MATH cBool magicalRay3IsZero( const cRay3* r3 );

MAGICALAPI_MATH void magicalRay3Fill( cRay3* out, float ox, float oy, float oz, float dx, float dy, float dz );
MAGICALAPI_MATH void magicalRay3Copy( cRay3* out, const cRay3* r3 );
MAGICALAPI_MATH void magicalRay3SetOriginToEnd( cRay3* out, const cVector3* origin, const cVector3* end );
MAGICALAPI_MATH void magicalRay3SetOriginAndDirection( cRay3* out, const cVector3* origin, const cVector3* direction );
MAGICALAPI_MATH void magicalRay3SetZero( cRay3* out );

MAGICALAPI_MATH void magicalRay3GetOrigin( cVector3* out, const cRay3* r3 );
MAGICALAPI_MATH void magicalRay3GetDirection( cVector3* out, const cRay3* r3 );
MAGICALAPI_MATH void magicalRay3SetOrigin( cRay3* out, const cVector3* origin );
MAGICALAPI_MATH void magicalRay3SetDirection( cRay3* out, const cVector3* direction );

MAGICALAPI_MATH void magicalRay3IntersectsPlane3( cRayIntersectResult* out, const cRay3* r3, const cPlane3* p, cBool discard_inside );
MAGICALAPI_MATH void magicalRay3IntersectsAABB3( cRayIntersectResult* out, const cRay3* r3, const cAABB3* aabb, cBool discard_inside );
MAGICALAPI_MATH void magicalRay3IntersectsSphere3( cRayIntersectResult* out, const cRay3* r3, const cSphere3* sp, cBool discard_inside );

#ifdef __cplusplus
}
#endif

#endif //__C_RAY3_H__