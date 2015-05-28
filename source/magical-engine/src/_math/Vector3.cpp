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

const Vector3 Vector3::Zero = Vector3( 0.0f, 0.0f, 0.0f );
const Vector3 Vector3::One = Vector3( 1.0f, 1.0f, 1.0f );
const Vector3 Vector3::UnitX = Vector3( 1.0f, 0.0f, 0.0f );
const Vector3 Vector3::UnitY = Vector3( 0.0f, 1.0f, 0.0f );
const Vector3 Vector3::UnitZ = Vector3( 0.0f, 0.0f, 1.0f );
const Vector3 Vector3::Up = Vector3( 0.0f, 1.0f, 0.0f );
const Vector3 Vector3::Down = Vector3( 0.0f, -1.0f, 0.0f );
const Vector3 Vector3::Right = Vector3( 1.0f, 0.0f, 0.0f );
const Vector3 Vector3::Left = Vector3( -1.0f, 0.0f, 0.0f );
const Vector3 Vector3::Forward = Vector3( 0.0f, 0.0f, 1.0f );
const Vector3 Vector3::Back = Vector3( 0.0f, 0.0f, -1.0f );

void Vector3::mulMatrix3x3( Vector3& out, const Vector3& v, const Matrix3x3& m )
{
	Vector3 dst;

	dst.x = v.x * m.m11 + v.y * m.m21 + v.z * m.m31;
	dst.y = v.x * m.m12 + v.y * m.m22 + v.z * m.m32;
	dst.z = v.x * m.m13 + v.y * m.m23 + v.z * m.m33;

	out.x = dst.x;
	out.y = dst.y;
	out.z = dst.z;
}

void Vector3::mulMatrix4x4( Vector3& out, const Vector3& v, const Matrix4x4& m )
{
	Vector3 dst;

	dst.x = v.x * m.m11 + v.y * m.m21 + v.z * m.m31 + m.m41;
	dst.y = v.x * m.m12 + v.y * m.m22 + v.z * m.m32 + m.m42;
	dst.z = v.x * m.m13 + v.y * m.m23 + v.z * m.m33 + m.m43;

	out.x = dst.x;
	out.y = dst.y;
	out.z = dst.z;
}

void Vector3::clamp( Vector3& out, const Vector3& v, const Vector3& min, const Vector3& max )
{
	debugassert( min.x <= max.x && min.y <= max.y && min.z <= max.z, "invaild operate!" );

	out.x = v.x;
	out.y = v.y;
	out.z = v.z;

	if( out.x < min.x ) out.x = min.x;
	if( out.x > max.x ) out.x = max.x;
	if( out.y < min.y ) out.y = min.y;
	if( out.y > max.y ) out.y = max.y;
	if( out.z < min.z ) out.z = min.z;
	if( out.z > max.z ) out.z = max.z;
}

void Vector3::negate( Vector3& out, const Vector3& v )
{
	out.x = -v.x;
	out.y = -v.y;
	out.z = -v.z;
}

void Vector3::normalize( Vector3& out, const Vector3& v )
{
	out.x = v.x;
	out.y = v.y;
	out.z = v.z;

	float n = v.x * v.x + v.y * v.y + v.z * v.z;
	if( Math::isAlmostEqual( n, 1.0f, Math::VectorEpsilon ) )
		return;

	n = sqrtf( n );
	if( Math::isAlmostZero( n, Math::VectorEpsilon ) )
		return;

	n = 1.0f / n;
	out.x *= n;
	out.y *= n;
	out.z *= n;
}

void Vector3::scale( Vector3& out, const Vector3& v, float s )
{
	out.x = v.x * s;
	out.y = v.y * s;
	out.z = v.z * s;
}

void Vector3::cross( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	float rx = v1.y * v2.z - v1.z * v2.y;
	float ry = v1.z * v2.x - v1.x * v2.z;
	float rz = v1.x * v2.y - v1.y * v2.x;

	out.x = rx;
	out.y = ry;
	out.z = rz;
}

void Vector3::midPointBetween( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	out.x = ( v1.x + v2.x ) * 0.5f;
	out.y = ( v1.y + v2.y ) * 0.5f;
	out.z = ( v1.z + v2.z ) * 0.5f;
}

void Vector3::project( Vector3& out, const Vector3& v, const Vector3& n )
{
	Vector3 normalize;
	debugassert( !n.isZero(), "invaild operate!" );
	
	Vector3::normalize( normalize, n );
	float d = Vector3::dot( v, normalize );

	out.x = normalize.x * d;
	out.y = normalize.y * d;
	out.z = normalize.z * d;
}