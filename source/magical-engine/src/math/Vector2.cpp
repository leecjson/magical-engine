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
#include "Vector2.h"
#include "Vector2.inl"

const Vector2 Vector2::Zero = Vector2( 0.0f, 0.0f );
const Vector2 Vector2::One = Vector2( 1.0f, 1.0f );
const Vector2 Vector2::UnitX = Vector2( 1.0f, 0.0f );
const Vector2 Vector2::UnitY = Vector2( 0.0f, 1.0f );
const Vector2 Vector2::Right = Vector2( 1.0f, 0.0f );
const Vector2 Vector2::Left = Vector2( -1.0f, 0.0f );
const Vector2 Vector2::Up = Vector2( 0.0f, 1.0f );
const Vector2 Vector2::Down = Vector2( 0.0f, -1.0f );

void Vector2::clamp( Vector2& out, const Vector2& v, const Vector2& min, const Vector2& max )
{
	debugassert( min.x <= max.x && min.y <= max.y, "invaild operate!" );

	out.x = v.x;
	out.y = v.y;

	if( out.x < min.x ) out.x = min.x;
	if( out.x > max.x ) out.x = max.x;
	if( out.y < min.y ) out.y = min.y;
	if( out.y > max.y ) out.y = max.y;
}

void Vector2::negate( Vector2& out, const Vector2& v )
{
	out.x = -v.x;
	out.y = -v.y;
}

void Vector2::normalize( Vector2& out, const Vector2& v )
{
	out.x = v.x;
	out.y = v.y;

	float n = v.x * v.x + v.y * v.y;
	if( Math::isAlmostEqual( n, 1.0f, Math::VectorEpsilon ) )
		return;

	n = sqrtf( n );
	if( Math::isAlmostZero( n, Math::VectorEpsilon ) )
		return;

	n = 1.0f / n;
	out.x *= n;
	out.y *= n;
}

void Vector2::rotate( Vector2& out, const Vector2& v, float a )
{
	float s = sinf( a );
	float c = cosf( a );

	float rx = v.x * c - v.y * s;
	float ry = v.x * s + v.y * c;

	out.x = rx;
	out.y = ry;
}

void Vector2::scale( Vector2& out, const Vector2& v, float s )
{
	out.x = v.x * s;
	out.y = v.y * s;
}

void Vector2::midPointBetween( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	out.x = ( v1.x + v2.x ) * 0.5f;
	out.y = ( v1.y + v2.y ) * 0.5f;
}

void Vector2::project( Vector2& out, const Vector2& v, const Vector2& n )
{
	Vector2 normalize;
	debugassert( !n.isZero(), "Invalid operate!" );
	
	Vector2::normalize( normalize, n );
	float d = Vector2::dot( v, normalize );

	out.x = normalize.x * d;
	out.y = normalize.y * d;
}

void Vector2::lerp( Vector2& out, const Vector2& v1, const Vector2& v2, float t )
{
	if( t >= 1.0f )
	{
		out = v2;
	}
	else if( t <= 0.0f )
	{
		out = v1;
	}
	else
	{
		Vector2 v1_to_v2 = v2 - v1;
		Vector2::scale( v1_to_v2, v1_to_v2, t );

		out = Vector2::add( v1, v1_to_v2 );
	}
}