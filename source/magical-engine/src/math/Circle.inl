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

inline Circle::Circle( float x, float y, float r ) 
: x( x ), y( y ), r( r )
{
	
}

inline Circle::Circle( const Vector2& center, float r ) 
: center( center ), r( r )
{
	
}

inline Circle::Circle( const Circle& circle ) 
: x( circle.x ), y( circle.y ), r( r )
{
	
}

inline Circle::Circle( void ) 
{
	
}

inline bool Circle::operator==( const Circle& circle ) const
{
	return equals( circle );
}

inline bool Circle::operator!=( const Circle& circle ) const
{
	return equals( circle ) == false;
}

inline Circle& Circle::operator=( const Circle& circle )
{
	x = circle.x;
	y = circle.y;
	r = circle.r;
	return *this;
}

inline bool Circle::equals( const Circle& circle ) const
{
	return
		Math::isAlmostEqual( x, circle.x, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( y, circle.y, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( r, circle.r, Math::VectorEpsilon );
}

inline bool Circle::isValid( void ) const
{
	return r >= Math::VectorEpsilon;
}

inline void Circle::set( const Circle& circle )
{
	x = circle.x;
	y = circle.y;
	r = circle.r;
}

inline void Circle::set( const Vector2& center, float r )
{
	this->center = center;
	this->r = r;
}

inline void Circle::set( float x, float y, float z, float r )
{
	this->x = x;
	this->y = y;
	this->r = r;
}

inline Circle Circle::scale( const Circle& circle, float s )
{
	return Circle( circle.x, circle.y, circle.r * s );
}

inline Circle Circle::merge( const Circle& circle1, const Circle& circle2 )
{
	Circle dst;
	Circle::merge( dst, circle1, circle2 );
	return dst;
}

inline void Circle::scale( float s )
{
	r *= s;
}

inline void Circle::merge( const Circle& circle )
{
	Circle::merge( *this, *this, circle );
}

inline Vector2 Circle::closest( const Vector2& v )
{
	Vector2 dst;
	Circle::closest( dst, *this, v );
	return dst;
}

inline bool Circle::containsPoint( const Vector2& point ) const
{
	float dx = point.x - x;
	float dy = point.y - y;

	return dx * dx + dy * dy <= r;
}