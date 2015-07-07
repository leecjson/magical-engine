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

inline Vector2::Vector2( float v ) : x( v ), y( v )
{
	
}

inline Vector2::Vector2( float x, float y ) : x( x ), y( y )
{
	
}

inline Vector2::Vector2( const Vector2& v ) : x( v.x ), y( v.y )
{
	
}

inline Vector2::Vector2( void )
{
	
}

inline Vector2::operator float*( void )
{
	return (float*) this;
}

inline Vector2::operator const float*( void ) const
{
	return (const float*) this;
}

inline bool Vector2::operator==( const Vector2& v ) const
{
	return equals( v );
}

inline bool Vector2::operator!=( const Vector2& v ) const
{
	return equals( v ) == false;
}

inline float& Vector2::operator[]( size_t i ) const
{
	debugassert( 0 <= i && i <= 1, "index out of range" );

	return ((float*)this)[i];
}

inline Vector2& Vector2::operator=( float v )
{
	x = v; y = v; return *this;
}

inline Vector2& Vector2::operator=( const Vector2& v )
{
	x = v.x; y = v.y; return *this;
}

inline Vector2 Vector2::operator+( void ) const
{
	return *this;
}

inline Vector2 Vector2::operator+( float a ) const
{
	return Vector2( x + a, y + a );
}

inline Vector2 Vector2::operator+( const Vector2& v ) const
{
	return Vector2( x + v.x, y + v.y );
}

inline Vector2 Vector2::operator-( void ) const
{
	return Vector2( -x, -y );
}

inline Vector2 Vector2::operator-( float a ) const
{
	return Vector2( x - a, y - a );
}

inline Vector2 Vector2::operator-( const Vector2& v ) const
{
	return Vector2( x - v.x, y - v.y );
}

inline Vector2 Vector2::operator*( float a ) const
{
	return Vector2( x * a, y * a );
}

inline Vector2 Vector2::operator*( const Vector2& v ) const
{
	return Vector2( x * v.x, y * v.y );
}

inline Vector2 Vector2::operator/( float a ) const
{
	return Vector2( x / a, y / a );
}

inline Vector2 Vector2::operator/( const Vector2& v ) const
{
	return Vector2( x / v.x, y / v.y );
}

inline Vector2& Vector2::operator+=( float a )
{
	x += a; y += a; return *this;
}

inline Vector2& Vector2::operator+=( const Vector2& v )
{
	x += v.x; y += v.y; return *this;
}

inline Vector2& Vector2::operator-=( float a )
{
	x -= a; y -= a; return *this;
}

inline Vector2& Vector2::operator-=( const Vector2& v )
{
	x -= v.x; y -= v.y; return *this;
}

inline Vector2& Vector2::operator*=( float a )
{
	x *= a; y *= a; return *this;
}

inline Vector2& Vector2::operator*=( const Vector2& v )
{
	x *= v.x; y *= v.y; return *this;
}

inline Vector2& Vector2::operator/=( float a )
{
	x /= a; y /= a; return *this;
}

inline Vector2& Vector2::operator/=( const Vector2& v )
{
	x /= v.x; y /= v.y; return *this;
}

inline void Vector2::add( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	out.x = v1.x + v2.x;
	out.y = v1.y + v2.y;
}

inline void Vector2::sub( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	out.x = v1.x - v2.x;
	out.y = v1.y - v2.y;
}

inline void Vector2::mul( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	out.x = v1.x * v2.x;
	out.y = v1.y * v2.y;
}

inline void Vector2::div( Vector2& out, const Vector2& v1, const Vector2& v2 )
{
	out.x = v1.x / v2.x;
	out.y = v1.y / v2.y;
}

inline void Vector2::addScalar( Vector2& out, const Vector2& v, float a )
{
	out.x = v.x + a;
	out.y = v.y + a;
}

inline void Vector2::subScalar( Vector2& out, const Vector2& v, float a )
{
	out.x = v.x - a;
	out.y = v.y - a;
}

inline void Vector2::mulScalar( Vector2& out, const Vector2& v, float a )
{
	out.x = v.x * a;
	out.y = v.y * a;
}

inline void Vector2::divScalar( Vector2& out, const Vector2& v, float a )
{
	out.x = v.x / a;
	out.y = v.y / a;
}

inline Vector2 Vector2::add( const Vector2& v1, const Vector2& v2 )
{
	return Vector2( v1.x + v2.x, v1.y + v2.y );
}

inline Vector2 Vector2::sub( const Vector2& v1, const Vector2& v2 )
{
	return Vector2( v1.x - v2.x, v1.y - v2.y );
}

inline Vector2 Vector2::mul( const Vector2& v1, const Vector2& v2 )
{
	return Vector2( v1.x * v2.x, v1.y * v2.y );
}

inline Vector2 Vector2::div( const Vector2& v1, const Vector2& v2 )
{
	return Vector2( v1.x / v2.x, v1.y / v2.y );
}

inline Vector2 Vector2::addScalar( const Vector2& v, float a )
{
	return Vector2( v.x + a, v.y + a );
}

inline Vector2 Vector2::subScalar( const Vector2& v, float a )
{
	return Vector2( v.x - a, v.y - a );
}

inline Vector2 Vector2::mulScalar( const Vector2& v, float a )
{
	return Vector2( v.x * a, v.y * a );
}

inline Vector2 Vector2::divScalar( const Vector2& v, float a )
{
	return Vector2( v.x / a, v.y / a );
}

inline void Vector2::add( const Vector2& v )
{
	x += v.x; y += v.y;
}

inline void Vector2::sub( const Vector2& v )
{
	x -= v.x; y -= v.y;
}

inline void Vector2::mul( const Vector2& v )
{
	x *= v.x; y *= v.y;
}

inline void Vector2::div( const Vector2& v )
{
	x /= v.x; y /= v.y;
}

inline void Vector2::addScalar( float a )
{
	x += a; y += a;
}

inline void Vector2::subScalar( float a )
{
	x -= a; y -= a;
}

inline void Vector2::mulScalar( float a )
{
	x *= a; y *= a;
}

inline void Vector2::divScalar( float a )
{
	x /= a; y /= a;
}

inline bool Vector2::equals( const Vector2& v ) const
{
	return
		Math::isAlmostEqual( x, v.x, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( y, v.y, Math::VectorEpsilon );
}

inline bool Vector2::isZero( void ) const
{
	return
		Math::isAlmostZero( x, Math::VectorEpsilon ) &&
		Math::isAlmostZero( y, Math::VectorEpsilon );
}

inline bool Vector2::isOne( void ) const
{
	return
		Math::isAlmostEqual( x, 1.0f, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( y, 1.0f, Math::VectorEpsilon );
}

inline void Vector2::setZero( void )
{
	x = 0.0f; y = 0.0f;
}

inline void Vector2::setOne( void )
{
	x = 1.0f; y = 1.0f;
}

inline void Vector2::set( const Vector2& v )
{
	x = v.x; y = v.y;
}

inline void Vector2::set( float x, float y )
{
	this->x = x; this->y = y;
}

inline Vector2 Vector2::clamp( const Vector2& v, const Vector2& min, const Vector2& max )
{
	Vector2 dst;
	Vector2::clamp( dst, v, min, max );
	return dst;
}

inline Vector2 Vector2::negate( const Vector2& v )
{
	Vector2 dst;
	Vector2::negate( dst, v );
	return dst;
}

inline Vector2 Vector2::normalize( const Vector2& v )
{
	Vector2 dst;
	Vector2::normalize( dst, v );
	return dst;	
}

inline Vector2 Vector2::rotate( const Vector2& v, float a )
{
	Vector2 dst;
	Vector2::rotate( dst, v, a );
	return dst;
}

inline Vector2 Vector2::scale( const Vector2& v, float s )
{
	Vector2 dst;
	Vector2::scale( dst, v, s );
	return dst;
}

inline Vector2 Vector2::midPointBetween( const Vector2& v1, const Vector2& v2 )
{
	Vector2 dst;
	Vector2::midPointBetween( dst, v1, v2 );
	return dst;
}

inline Vector2 Vector2::project( const Vector2& v, const Vector2& n )
{
	Vector2 dst;
	Vector2::project( dst, v, n );
	return dst;
}

inline Vector2 Vector2::lerp( const Vector2& v1, const Vector2& v2, float t )
{
	Vector2 dst;
	Vector2::lerp( dst, v1, v2, t );
	return dst;
}

inline void Vector2::clamp( const Vector2& min, const Vector2& max )
{
	Vector2::clamp( *this, *this, min, max );
}

inline void Vector2::negate( void )
{
	Vector2::negate( *this, *this );
}

inline void Vector2::normalize( void )
{
	Vector2::normalize( *this, *this );
}

inline void Vector2::rotate( float a )
{
	Vector2::rotate( *this, *this, a );
}

inline void Vector2::scale( float s )
{
	Vector2::scale( *this, *this, s );
}

inline Vector2 Vector2::midPointBetween( const Vector2& v ) const
{
	return Vector2::midPointBetween( *this, v );
}

inline Vector2 Vector2::project( const Vector2& n ) const
{
	return Vector2::project( *this, n );
}

inline Vector2 Vector2::lerp( const Vector2& v, float t ) const
{
	return Vector2::lerp( *this, v, t );
}

inline float Vector2::dot( const Vector2& v1, const Vector2& v2 )
{
	return v1.x * v2.x + v1.y * v2.y;
}

inline float Vector2::cross( const Vector2& v1, const Vector2& v2 )
{
	return v1.x * v2.y - v1.y * v2.x;
}

inline float Vector2::distance( const Vector2& v1, const Vector2& v2 )
{
	float dx = v2.x - v1.x;
	float dy = v2.y - v1.y;

	return sqrtf( dx * dx + dy * dy );
}

inline float Vector2::distanceSq( const Vector2& v1, const Vector2& v2 )
{
	float dx = v2.x - v1.x;
	float dy = v2.y - v1.y;

	return dx * dx + dy * dy;
}

inline float Vector2::length( const Vector2& v )
{
	return sqrtf( v.x * v.x + v.y * v.y );
}

inline float Vector2::lengthSq( const Vector2& v )
{
	return v.x * v.x + v.y * v.y;
}

inline float Vector2::angle( const Vector2& v1, const Vector2& v2 )
{
	debugassert( !v1.isZero() && !v2.isZero(), "invaild operate!" );

	return Math::safeAcos( Vector2::dot( v1, v2 ) / ( v1.length() * v2.length() ) );
}

inline float Vector2::dot( const Vector2& v ) const
{
	return Vector2::dot( *this, v );
}

inline float Vector2::cross( const Vector2& v ) const
{
	return Vector2::cross( *this, v );
}

inline float Vector2::distance( const Vector2& v ) const
{
	return Vector2::distance( *this, v );
}

inline float Vector2::distanceSq( const Vector2& v ) const
{
	return Vector2::distanceSq( *this, v );
}

inline float Vector2::length( void ) const
{
	return Vector2::length( *this );
}

inline float Vector2::lengthSq( void ) const
{
	return Vector2::lengthSq( *this );
}

inline float Vector2::angle( const Vector2& v ) const
{
	return Vector2::angle( *this, v );
}

NAMESPACE_END