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

struct Vector2;
struct Vector3;
struct Vector4;
struct Rotater;
struct Quaternion;
struct Matrix3x3;
struct Matrix4x4;

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

struct Ray;
struct Box;
struct Plane;
struct Sphere;

#include "Ray.h"
#include "Box.h"
#include "Plane.h"
#include "Sphere.h"

#include "Ray.inl"
#include "Box.inl"
#include "Plane.inl"
#include "Sphere.inl"

const Sphere Sphere::One = Sphere( 0.0f, 0.0f, 0.0f, 1.0f );
const Sphere Sphere::Invalid = Sphere( 0.0f, 0.0f, 0.0f, -1.0f );

void Sphere::scale( Sphere& out, const Sphere& sphere, float s )
{
	out.x = sphere.x;
	out.y = sphere.y;
	out.z = sphere.z;
	out.r = sphere.r * s;
}

void Sphere::merge( Sphere& out, const Sphere& sphere1, const Sphere& sphere2 )
{
	Vector3 mid = Vector3::midPointBetween( sphere1.center, sphere2.center );
	float distance = Vector3::distance( sphere1.center, sphere2.center );

	out.center = mid;
	out.r = ( distance + sphere1.r + sphere2.r ) * 0.5f;
}

void Sphere::closest( Vector3& out, const Sphere& sphere, const Vector3& v )
{
	Vector3 v_to_center = v - sphere.center;
	v_to_center.normalize();
	v_to_center.scale( sphere.r );

	out = sphere.center + v_to_center;
}