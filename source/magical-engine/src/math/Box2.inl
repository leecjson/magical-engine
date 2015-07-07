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
NAMESPACE_MAGICAL

inline Box2::Box2( const Vector2& min, const Vector2& max ) 
: min( min ), max( max )
{

}

inline Box2::Box2( const Box2& box )
: min( box.min ), max( box.max )
{

}

inline Box2::Box2( void )
{

}

inline bool Box2::operator==( const Box2& box ) const
{
	return equals( box );
}

inline bool Box2::operator!=( const Box2& box ) const
{
	return equals( box ) == false;
}

inline Box2& Box2::operator=( const Box2& box )
{
	min = box.min;
	max = box.max;
	return *this;
}

inline void Box2::set( const Vector2& min, const Vector2& max )
{
	this->min = min;
	this->max = max;
}

inline void Box2::set( const Box2& box )
{
	min = box.min;
	max = box.max;
}

inline Box2 Box2::createOriginBox( const Vector2& origin, float w, float h )
{
	Box2 dst;
	dst.setOriginBox( origin, w, h );
	return dst;
}

inline Box2 Box2::createCenterBox( const Vector2& center, float w, float h )
{
	Box2 dst;
	dst.setCenterBox( center, w, h );
	return dst;
}

inline Box2 Box2::scale( const Box2& box, float s )
{
	Box2 dst;
	Box2::scale( dst, box, s );
	return dst;
}

inline Box2 Box2::merge( const Box2& box1, const Box2& box2 )
{
	Box2 dst;
	Box2::merge( dst, box1, box2 );
	return dst;
}

inline void Box2::scale( float s )
{
	Box2::scale( *this, *this, s );
}

inline void Box2::merge( const Box2& box )
{
	Box2::merge( *this, *this, box );
}

inline Vector2 Box2::center( void ) const
{
	Vector2 dst;
	Box2::center( dst, *this );
	return dst;
}

inline Vector2 Box2::closest( const Vector2& v ) const
{
	Vector2 dst;
	Box2::closest( dst, *this, v );
	return dst;
}

inline void Box2::shrink( float w, float h )
{
	Vector2 amount( w, h );
	amount.scale( 0.5f );

	max -= amount;
	min += amount;
}

inline void Box2::shrink( float a )
{
	max -= a * 0.5f;
	min += a * 0.5f;
}

inline void Box2::expand( float w, float h )
{
	Vector2 amount( w, h );
	amount.scale( 0.5f );

	max += amount;
	min -= amount;
}

inline void Box2::expand( float a )
{
	max += a * 0.5f;
	min -= a * 0.5f;
}

inline void Box2::expandBy( const Vector2& v )
{
	if( v.x < min.x ) min.x = v.x;
	if( v.y < min.y ) min.y = v.y;
	if( v.x > max.x ) max.x = v.x;
	if( v.y > max.y ) max.y = v.y;
} 

inline float Box2::size( void ) const
{
	float x = max.x - min.x;
	float y = max.y - min.y;

	return sqrtf( x * x + y * y );
}

inline float Box2::width( void ) const
{
	return max.x - min.x;
}

inline float Box2::height( void ) const
{
	return max.y - min.y;
}

NAMESPACE_END