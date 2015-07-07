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

#include "Ray.inl"
#include "Box.inl"
#include "Plane.inl"
#include "Sphere.inl"

NAMESPACE_MAGICAL

const Box Box::Invalid = Box( Vector3::One, -Vector3::One );

bool Box::equals( const Box& box ) const
{
	return
		Math::isAlmostEqual( min.x, box.min.x, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( min.y, box.min.y, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( min.z, box.min.z, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( max.x, box.max.x, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( max.y, box.max.y, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( max.z, box.max.z, Math::VectorEpsilon );
}

bool Box::isValid( void ) const
{
	return
		min.x < max.x &&
		min.y < max.y &&
		min.z < max.z;
}

void Box::setOriginBox( const Vector3& origin, float w, float h, float d )
{
	min = origin;

	max.x = origin.x + w;
	max.y = origin.y + h;
	max.z = origin.z + d;
}

void Box::setCenterBox( const Vector3& center, float w, float h, float d )
{
	float half_width = w / 2;
	float half_height = h / 2;
	float half_depth = d / 2;

	min.x = center.x - half_width;
	min.y = center.y - half_height;
	min.z = center.z - half_depth;
	max.x = center.x + half_width;
	max.y = center.y + half_height;
	max.z = center.z + half_depth;
}

void Box::scale( Box& out, const Box& box, float s )
{
	Vector3 center = box.center();

	float ws = ( box.max.x - box.min.x ) * s * 0.5f;
	float hs = ( box.max.y - box.min.y ) * s * 0.5f;
	float ds = ( box.max.z - box.min.z ) * s * 0.5f;

	out.min.x = center.x - ws;
	out.max.x = center.x + ws;
	out.min.y = center.y - hs;
	out.max.y = center.y + hs;
	out.min.z = center.z - ds;
	out.max.z = center.z + ds;
}

void Box::merge( Box& out, const Box& box1, const Box& box2 )
{
	out.min.x = Math::min( box1.min.x, box2.min.x );
	out.min.y = Math::min( box1.min.y, box2.min.y );
	out.min.z = Math::min( box1.min.z, box2.min.z );
	out.max.x = Math::max( box1.max.x, box2.max.x );
	out.max.y = Math::max( box1.max.y, box2.max.y );
	out.max.z = Math::max( box1.max.z, box2.max.z );
}

void Box::center( Vector3& out, const Box& box )
{
	out.x = 0.5f * ( box.min.x + box.max.x );
	out.y = 0.5f * ( box.min.y + box.max.y );
	out.z = 0.5f * ( box.min.z + box.max.z );
}

void Box::closest( Vector3& out, const Box& box, const Vector3& v )
{
	Vector3 dst;

	if( v.x < box.min.x )
	{
		dst.x = box.min.x;
	}
	else if( v.x > box.max.x )
	{
		dst.x = box.max.x;
	}
	else
	{
		dst.x = v.x;
	}

	if( v.y < box.min.y )
	{
		dst.y = box.min.y;
	}
	else if( v.y > box.max.y )
	{
		dst.y = box.max.y;
	}
	else
	{
		dst.y = v.y;
	}

	if( v.z < box.min.z )
	{
		dst.z = box.min.z;
	}
	else if( v.z > box.max.z )
	{
		dst.z = box.max.z;
	}
	else
	{
		dst.z = v.z;
	}

	out.x = dst.x;
	out.y = dst.y;
	out.z = dst.z;
}

void Box::transform( Box& out, const Box& box, const Matrix4x4& m )
{
	Vector3 left_top_front( box.min.x, box.max.y, box.max.z );
	Vector3 left_bottom_front( box.min.x, box.min.y, box.max.z );
	Vector3 right_top_front( box.max.x, box.max.y, box.max.z );
	Vector3 right_bottom_front( box.max.x, box.min.y, box.max.z );
	Vector3 left_top_back( box.min.x, box.max.y, box.min.z );
	Vector3 left_bottom_back( box.min.x, box.min.y, box.min.z );
	Vector3 right_top_back( box.max.x, box.max.y, box.min.z );
	Vector3 right_bottom_back( box.max.x, box.min.y, box.min.z );

	Vector3::mul4x4( left_top_front, left_top_front, m );
	Vector3::mul4x4( left_bottom_front, left_bottom_front, m );
	Vector3::mul4x4( right_top_front, right_top_front, m );
	Vector3::mul4x4( right_bottom_front, right_bottom_front, m );
	Vector3::mul4x4( left_top_back, left_top_back, m );
	Vector3::mul4x4( left_bottom_back, left_bottom_back, m );
	Vector3::mul4x4( right_top_back, right_top_back, m );
	Vector3::mul4x4( right_bottom_back, right_bottom_back, m );

	out.set( Box::Invalid );
	out.expandBy( left_top_front );
	out.expandBy( left_bottom_front );
	out.expandBy( right_top_front );
	out.expandBy( right_bottom_front );
	out.expandBy( left_top_back );
	out.expandBy( left_bottom_back );
	out.expandBy( right_top_back );
	out.expandBy( right_bottom_back );
}

bool Box::intersects( const Box& box ) const
{
	if( min.x > box.max.x ) return false;
	if( max.x < box.min.x ) return false;
	if( min.y > box.max.y ) return false;
	if( max.y < box.min.y ) return false;
	if( min.z > box.max.z ) return false;
	if( max.z < box.min.z ) return false;

	return true;
}

bool Box::intersects( const Sphere& sphere ) const
{
	return Vector3::distanceSq( closest( sphere.center ), sphere.center ) <= ( sphere.r * sphere.r );
}

bool Box::containsPoint( const Vector3& point ) const
{
	return 
		point.x >= min.x &&
		point.x <= max.x &&
		point.y >= min.y &&
		point.y <= max.y &&
		point.z >= min.z &&
		point.z <= max.z;
}

NAMESPACE_END