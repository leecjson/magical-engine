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

#include "cMathMacros.h"

typedef float cSphere3[4];

#include "cVec3.h"
#include "cAABB3.h"
#include "cPlane3.h"

#ifdef __cplusplus
extern "C" {
#endif

MAGICALAPI_MATH void magicalSphere3FillScalars( cSphere3 out, const float x, const float y, const float z, const float r );
MAGICALAPI_MATH void magicalSphere3FillCenterAndRadius( cSphere3 out, const cVec3 center, const float r );
MAGICALAPI_MATH void magicalSphere3Fill( cSphere3 out, const cSphere3 sp );

MAGICALAPI_MATH cBool magicalSphere3Intersects( const cSphere3 sp1, const cSphere3 sp2 );
MAGICALAPI_MATH cBool magicalSphere3IntersectsAABB3( const cSphere3 sp, const cAABB3 aabb );
MAGICALAPI_MATH cBool magicalSphere3IntersectsPlane3( const cSphere3 sp, const cPlane3 p );

#ifdef __cplusplus
}
#endif

#endif //__C_SPHERE_H__