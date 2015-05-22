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
struct Box2d;

#include "Vector2.h"
#include "Vector2.inl"

#include "Box2d.h"
#include "Box2d.inl"

const Box2d Box2d::Invalid = Box2d( Vector2::One, -Vector2::One );

bool Box2d::equals( const Box2d& box ) const
{
	return
		Math::isAlmostEqual( min.x, box.min.x, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( min.y, box.min.y, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( max.x, box.max.x, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( max.y, box.max.y, Math::VectorEpsilon );
}

bool Box2d::isValid( void ) const
{
	return
		min.x < max.x &&
		min.y < max.y;
}

void Box2d::setOriginBox( const Vector2& origin, float w, float h )
{
	min = origin;

	max.x = origin.x + w;
	max.y = origin.y + h;
}

void Box2d::setCenterBox( const Vector2& center, float w, float h )
{
	float half_width = w / 2;
	float half_height = h / 2;

	min.x = center.x - half_width;
	min.y = center.y - half_height;
	max.x = center.x + half_width;
	max.y = center.y + half_height;
}

void Box2d::scale( Box2d& out, const Box2d& box, float s )
{
	Vector2 center = box.center();

	float ws = ( box.max.x - box.min.x ) * s * 0.5f;
	float hs = ( box.max.y - box.min.y ) * s * 0.5f;

	out.min.x = center.x - ws;
	out.max.x = center.x + ws;
	out.min.y = center.y - hs;
	out.max.y = center.y + hs;
}

void Box2d::merge( Box2d& out, const Box2d& box1, const Box2d& box2 )
{
	out.min.x = Math::min( box1.min.x, box2.min.x );
	out.min.y = Math::min( box1.min.y, box2.min.y );
	out.max.x = Math::max( box1.max.x, box2.max.x );
	out.max.y = Math::max( box1.max.y, box2.max.y );
}

void Box2d::center( Vector2& out, const Box2d& box )
{
	out.x = 0.5f * ( box.min.x + box.max.x );
	out.y = 0.5f * ( box.min.y + box.max.y );
}

void Box2d::closest( Vector2& out, const Box2d& box, const Vector2& v )
{
	Vector2 dst;

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

	out.x = dst.x;
	out.y = dst.y;
}

bool Box2d::intersects( const Box2d& box ) const
{
	if( min.x > box.max.x ) return false;
	if( max.x < box.min.x ) return false;
	if( min.y > box.max.y ) return false;
	if( max.y < box.min.y ) return false;

	return true;
}

bool Box2d::containsPoint( const Vector2& point ) const
{
	return 
		point.x >= min.x &&
		point.x <= max.x &&
		point.y >= min.y &&
		point.y <= max.y;
}