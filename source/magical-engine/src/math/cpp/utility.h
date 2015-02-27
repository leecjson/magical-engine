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
#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "c/c-utility.h"

#if !defined( NS_MAGICAL_BEGIN )
#define NS_MAGICAL_BEGIN namespace magical {
#endif
#if !defined( NS_MAGICAL_END )
#define NS_MAGICAL_END }
#endif

#if defined MAGICAL_ENGINE
#ifndef MAGICAL_MATH_CACHED_POOL_ENABLE
#define MAGICAL_MATH_CACHED_POOL_ENABLE 1
#endif
#else
#ifndef MAGICAL_MATH_CACHED_POOL_ENABLE
#define MAGICAL_MATH_CACHED_POOL_ENABLE 0
#endif
#endif

#define FORWARD_DECLARE            \
	struct AABB2;                  \
	struct AABB3;                  \
	struct AxisAngle;              \
	struct EulerAngles;            \
	struct Frustum;                \
	struct Line2;                  \
	struct Matrix3;                \
	struct Matrix4;                \
	struct OBB2;                   \
	struct OBB3;                   \
	struct Plane;                  \
	struct Quaternion;             \
	struct Ray2;                   \
	struct Ray3;                   \
	struct Sphere;                 \
	struct Vector2;                \
	struct Vector3;                \
	struct Vector4;

#endif //__UTILITY_H__