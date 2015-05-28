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

const Plane Plane::Invalid = Plane( 0.0f, 0.0f, 0.0f, 0.0f );
const Plane Plane::NormalX = Plane( 1.0f, 0.0f, 0.0f, 0.0f );
const Plane Plane::NormalY = Plane( 0.0f, 1.0f, 0.0f, 0.0f );
const Plane Plane::NormalZ = Plane( 0.0f, 0.0f, 1.0f, 0.0f );

void Plane::setPoints( const Vector3& a, const Vector3& b, const Vector3& c )
{
	Vector3 n, e3, e1;
	
	e3.x = b.x - a.x;
	e3.y = b.y - a.y;
	e3.z = b.z - a.z;

	e1.x = c.x - b.x;
	e1.y = c.y - b.y;
	e1.z = c.z - b.z;

	Vector3::cross( n, e3, e1 );
	debugassert( !n.isZero(), "invaild operate!" );
	Vector3::normalize( n, n );

	x = n.x;
	y = n.y;
	z = n.z;
	d = a.x * n.x + a.y * n.y + a.z * n.z;
}

void Plane::setNormalPoint( const Vector3& normal, const Vector3& a )
{
	Vector3 nn;
	Vector3::normalize( nn, normal );

	x = nn.x;
	y = nn.y;
	z = nn.z;
	d = a.x * nn.x + a.y * nn.y + a.z * nn.z;
}

void Plane::setNormalDistance( const Vector3& normal, float d )
{
	Vector3 nn;
	Vector3::normalize( nn, normal );

	x = nn.x;
	y = nn.y;
	z = nn.z;
	this->d = d;
}

void Plane::normalize( Plane& out, const Plane& plane )
{
	out.x = plane.x;
	out.y = plane.y;
	out.z = plane.z;
	out.d = plane.d;

	float n = plane.x * plane.x + plane.y * plane.y + plane.z * plane.z;
	if( Math::isAlmostEqual( n, 1.0f, Math::VectorEpsilon ) )
		return;

	n = sqrtf( n );
	if( Math::isAlmostZero( n, Math::VectorEpsilon ) )
		return;

	n = 1.0f / n;
	out.x *= n;
	out.y *= n;
	out.z *= n;
	out.d *= n;
}

void Plane::closest( Vector3& out, const Plane& plane, const Vector3& point )
{
	Vector3 scale_n;
	float distance = plane.d - plane.x * point.x + plane.y * point.y + plane.z * point.z;
	
	Vector3::scale( scale_n, plane.normal, distance );
	Vector3::add( out, point, scale_n );
}

Plane::Classification Plane::classify( const Vector3& point ) const
{
	float distance = x * point.x + y * point.y + z * point.z - d;

	if( distance > Math::VectorEpsilon )
		return Plane::Classification::Front;

	if( distance < -Math::VectorEpsilon )
		return Plane::Classification::Behind;

	return Plane::Classification::OnPlane;
}

Plane::Classification Plane::classify( const Box& box ) const
{
	float min_d, max_d;

	if( x > 0.0f )
	{
		min_d = x * box.min.x;
		max_d = x * box.max.x;
	}
	else
	{
		min_d = x * box.max.x;
		max_d = x * box.min.x;
	}

	if( y > 0.0f )
	{
		min_d += y * box.min.y;
		max_d += y * box.max.y;
	}
	else
	{
		min_d += y * box.max.y;
		max_d += y * box.min.y;
	}

	if( z > 0.0f )
	{
		min_d += z * box.min.z;
		max_d += z * box.max.z;
	}
	else
	{
		min_d += z * box.max.z;
		max_d += z * box.min.z;
	}

	if( min_d >= d ) {
		return Plane::Classification::Front;
	}

	if( max_d <= d ) {
		return Plane::Classification::Behind;
	}

	return Plane::Classification::OnPlane;
}

Plane::Classification Plane::classify( const Sphere& sphere ) const
{
	float distance = x * sphere.x + y * sphere.y + z * sphere.z - d;

	if( distance >= sphere.r )
		return Plane::Classification::Front;

	if( distance <= -sphere.r )
		return Plane::Classification::Behind;

	return Plane::Classification::OnPlane;
}

bool Plane::intersects( const Plane& plane ) const
{
	if( normal.equals( plane.normal ) || normal.equals( -plane.normal ) )
	{
		return Math::isAlmostEqual( d, plane.d, Math::VectorEpsilon );
	}
	else
	{
		return true;
	}
}