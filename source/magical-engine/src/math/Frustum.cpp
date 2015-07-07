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
#include "MathUtils.h"

NAMESPACE_MAGICAL

struct Vector2;
struct Vector3;
struct Vector4;
struct Rotater;
struct Quaternion;
struct Matrix3x3;
struct Matrix4x4;

struct Ray;
struct Box;
struct Plane;
struct Sphere;

NAMESPACE_END

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Rotater.h"
#include "Quaternion.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"

#include "Vector2.inl"
#include "Vector3.inl"
#include "Vector4.inl"
#include "Rotater.inl"
#include "Quaternion.inl"
#include "Matrix3x3.inl"
#include "Matrix4x4.inl"

#include "Ray.h"
#include "Box.h"
#include "Plane.h"
#include "Sphere.h"
#include "Frustum.h"

#include "Ray.inl"
#include "Box.inl"
#include "Plane.inl"
#include "Sphere.inl"
#include "Frustum.inl"

NAMESPACE_MAGICAL

const Frustum Frustum::Invalid = Frustum( Plane::Invalid, Plane::Invalid, Plane::Invalid, Plane::Invalid, Plane::Invalid, Plane::Invalid );

void Frustum::extract( const Matrix4x4& m )
{
	left.x = m.m14 + m.m11;
	left.y = m.m24 + m.m21;
	left.z = m.m34 + m.m31;
	left.d = m.m44 + m.m41;
	left.normalize();

	right.x = m.m14 - m.m11;
	right.y = m.m24 - m.m21;
	right.z = m.m34 - m.m31;
	right.d = m.m44 - m.m41;
	right.normalize();

	bottom.x = m.m14 + m.m12;
	bottom.y = m.m24 + m.m22;
	bottom.z = m.m34 + m.m32;
	bottom.d = m.m44 + m.m42;
	bottom.normalize();

	top.x = m.m14 - m.m12;
	top.y = m.m24 - m.m22;
	top.z = m.m34 - m.m32;
	top.d = m.m44 - m.m42;
	top.normalize();

	near.x = m.m14 + m.m13;
	near.y = m.m24 + m.m23; 
	near.z = m.m34 + m.m33;
	near.d = m.m44 + m.m43;
	near.normalize();

	far.x = m.m14 - m.m13;
	far.y = m.m24 - m.m23; 
	far.z = m.m34 - m.m33;
	far.d = m.m44 - m.m43;
	far.normalize();
}

bool Frustum::containsBox( const Box& box ) const
{
	Vector3 nearpoint;

	nearpoint.x = left.x < 0 ? box.max.x : box.min.x;
	nearpoint.y = left.y < 0 ? box.max.y : box.min.y;
	nearpoint.z = left.z < 0 ? box.max.z : box.min.z;

	if( left.classify( nearpoint ) == Plane::Classification::Front )
		return false;

	nearpoint.x = right.x < 0 ? box.max.x : box.min.x;
	nearpoint.y = right.y < 0 ? box.max.y : box.min.y;
	nearpoint.z = right.z < 0 ? box.max.z : box.min.z;

	if( right.classify( nearpoint ) == Plane::Classification::Front )
		return false;

	nearpoint.x = top.x < 0 ? box.max.x : box.min.x;
	nearpoint.y = top.y < 0 ? box.max.y : box.min.y;
	nearpoint.z = top.z < 0 ? box.max.z : box.min.z;

	if( top.classify( nearpoint ) == Plane::Classification::Front )
		return false;

	nearpoint.x = bottom.x < 0 ? box.max.x : box.min.x;
	nearpoint.y = bottom.y < 0 ? box.max.y : box.min.y;
	nearpoint.z = bottom.z < 0 ? box.max.z : box.min.z;

	if( bottom.classify( nearpoint ) == Plane::Classification::Front )
		return false;

	nearpoint.x = near.x < 0 ? box.max.x : box.min.x;
	nearpoint.y = near.y < 0 ? box.max.y : box.min.y;
	nearpoint.z = near.z < 0 ? box.max.z : box.min.z;

	if( near.classify( nearpoint ) == Plane::Classification::Front )
		return false;

	nearpoint.x = far.x < 0 ? box.max.x : box.min.x;
	nearpoint.y = far.y < 0 ? box.max.y : box.min.y;
	nearpoint.z = far.z < 0 ? box.max.z : box.min.z;

	if( far.classify( nearpoint ) == Plane::Classification::Front )
		return false;

	return true;
}

NAMESPACE_END