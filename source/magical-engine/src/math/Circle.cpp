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
struct Circle;

#include "Vector2.h"
#include "Vector2.inl"

#include "Circle.h"
#include "Circle.inl"

const Circle Circle::One = Circle( 0.0f, 0.0f, 1.0f );
const Circle Circle::Invalid = Circle( 0.0f, 0.0f, -1.0f );

void Circle::scale( Circle& out, const Circle& circle, float s )
{
	out.x = circle.x;
	out.y = circle.y;
	out.r = circle.r * s;
}

void Circle::merge( Circle& out, const Circle& circle1, const Circle& circle2 )
{
	Vector2 mid = Vector2::midPointBetween( circle1.center, circle2.center );
	float distance = Vector2::distance( circle1.center, circle2.center );

	out.center = mid;
	out.r = ( distance + circle1.r + circle2.r ) * 0.5f;
}

void Circle::closest( Vector2& out, const Circle& circle, const Vector2& v )
{
	Vector2 v_to_center = v - circle.center;
	v_to_center.normalize();
	v_to_center.scale( circle.r );

	out = circle.center + v_to_center;
}

NAMESPACE_END