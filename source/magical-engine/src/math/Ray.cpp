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

const Ray Ray::Invalid = Ray( Vector3::Zero, Vector3::Zero );

bool Ray::intersects( float& distance, const Plane& plane, bool discard_inside ) const
{
	Plane::Classification cp = plane.classify( origin );
	if( cp == Plane::Classification::OnPlane )
	{
		distance = 0.0f;
		return !discard_inside;
	}

	float dn = Vector3::dot( direction, plane.normal );
	if( Math::isAlmostZero( dn, Math::VectorEpsilon ) == false )
	{
		if( ( cp == Plane::Classification::Front && dn < -Math::VectorEpsilon ) || ( cp == Plane::Classification::Behind && dn > Math::VectorEpsilon ) )
		{
			distance = ( plane.d - Vector3::dot( origin, plane.normal ) ) / dn; 
			return true;
		}
	}

	distance = 0.0f;
	return false;
}

bool Ray::intersects( float& distance, const Box& box, bool discard_inside ) const
{
	float t;
	Vector3 p;

	if( ox >= box.min.x &&
		oy >= box.min.y &&
		oz >= box.min.z &&
		ox <= box.max.x &&
		oy <= box.max.y &&
		oz <= box.max.z )
	{
		distance = 0.0f;
		return !discard_inside;
	}

	if( Math::isAlmostZero( dx, Math::VectorEpsilon ) == false )
	{
		if( dx > 0.0f )
		{
			t = ( box.min.x - ox ) / dx;
		}
		else
		{
			t = ( box.max.x - ox ) / dx;
		}

		if( t > 0.0f )
		{
			p.x = ox + dx * t;
			p.y = oy + dy * t;
			p.z = oz + dz * t;

			if( p.y >= box.min.y && p.y <= box.max.y &&
				p.z >= box.min.z && p.z <= box.max.z )
			{
				distance = t;
				return true;
			}
		}
	}

	if( Math::isAlmostZero( dy, Math::VectorEpsilon ) == false )
	{
		if( dy > 0.0f )
		{
			t = ( box.min.y - oy ) / dy;
		}
		else
		{
			t = ( box.max.y - oy ) / dy;
		}

		if( t > 0.0f )
		{
			p.x = ox + dx * t;
			p.y = oy + dy * t;
			p.z = oz + dz * t;

			if( p.z >= box.min.z && p.z <= box.max.z &&
				p.x >= box.min.x && p.x <= box.max.x )
			{
				distance = t;
				return true;
			}
		}
	}

	if( Math::isAlmostZero( dz, Math::VectorEpsilon ) == false )
	{
		if( dz > 0.0f )
		{
			t = ( box.min.z - oz ) / dz;
		}
		else
		{
			t = ( box.max.z - oz ) / dz;
		}

		if( t > 0.0f )
		{
			p.x = ox + dx * t;
			p.y = oy + dy * t;
			p.z = oz + dz * t;

			if( p.x >= box.min.x && p.x <= box.max.x &&
				p.y >= box.min.y && p.y <= box.max.y )
			{
				distance = t;
				return true;
			}
				
		}
	}
	
	distance = 0.0f;
	return false;
}

bool Ray::intersects( float& distance, const Sphere& sphere, bool discard_inside ) const
{
	float a, esq, f, fsq, rsq;
	Vector3 e = Vector3::sub( sphere.center, origin );
	
	rsq = sphere.r * sphere.r;
	esq = Vector3::lengthSq( e );
	if( esq < rsq )
	{
		distance = 0.0f;
		return !discard_inside;
	}

	a = Vector3::dot( e, direction );
	fsq = rsq - esq + a * a;
	if( fsq <= 0.0f )
	{
		distance = 0.0f;
		return false;
	}

	f = sqrtf( fsq );
	distance = a - f;
	return true;
}