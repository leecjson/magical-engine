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

inline Vec2 Vec2::operator+( float rhs ) const 
{
	return Vec2( x + rhs, y + rhs );
}

inline Vec2 Vec2::operator+( const Vec2& rhs ) const
{
	return Vec2( x + rhs.x, y + rhs.y );
}

inline Vec2 Vec2::operator-( float rhs ) const
{
	return Vec2( x - rhs, y - rhs );
}

inline Vec2 Vec2::operator-( const Vec2& rhs ) const
{
	return Vec2( x - rhs.x, y - rhs.y );
}

inline Vec2 Vec2::operator*( float rhs ) const
{
	return Vec2( x * rhs, y * rhs );
}

inline Vec2 Vec2::operator*( const Vec2& rhs ) const
{
	return Vec2( x * rhs.x, y * rhs.y );
}

inline Vec2 Vec2::operator/( float rhs ) const
{
	magicalAssert( rhs, "division by 0.f" );
	return Vec2( x / rhs, y / rhs );
}

inline Vec2 Vec2::operator/( const Vec2& rhs ) const
{
	magicalAssert( rhs.x && rhs.y, "division by 0.f" );
	return Vec2( x / rhs.x, y / rhs.y );
}

inline Vec2& Vec2::operator=( const Vec2& rhs )
{
	x = rhs.x;
	y = rhs.y;
}

inline Vec2& Vec2::operator+=( const Vec2& rhs )
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

inline Vec2& Vec2::operator+=( float rhs )
{
	x += rhs;
	y += rhs;
	return *this;
}

inline Vec2& Vec2::operator-=( const Vec2& rhs )
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

inline Vec2& Vec2::operator-=( float rhs )
{
	x -= rhs;
	y -= rhs;
	return *this;
}

inline Vec2& Vec2::operator*=( const Vec2& rhs )
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

inline Vec2& Vec2::operator*=( float rhs )
{
	x *= rhs;
	y *= rhs;
	return *this;
}

inline Vec2& Vec2::operator/=( const Vec2& rhs )
{
	magicalAssert( rhs.x && rhs.y, "division by 0.f" );
	x /= rhs.x;
	y /= rhs.y;
	return *this;
}

inline Vec2& Vec2::operator/=( float rhs )
{
	magicalAssert( rhs, "division by 0.f" );
	x /= rhs;
	y /= rhs;
	return *this;
}

inline bool Vec2::operator==( const Vec2& rhs ) const
{
	return x == rhs.x && y == rhs.y;
}

inline bool Vec2::operator!=( const Vec2& rhs ) const
{
	return x != rhs.x || y != rhs.y;
}

inline bool Vec2::isZero( void ) const
{
	return x == 0.0f && y == 0.0f;
}

inline Vec2 Vec2::copy( void ) const
{
	return Vec2( *this );
}

inline void Vec2::fill( float rx, float ry )
{
	x = rx;
	y = ry;
}

inline void Vec2::fill( const float* rhs )
{
	x = rhs[0];
	y = rhs[1];
}

inline void Vec2::fill( const Vec2& rhs )
{
	x = rhs.x;
	y = rhs.y;
}

inline void Vec2::fillZero( void )
{
	x = 0.0f;
	y = 0.0f;
}

inline void Vec2::clamp( const Vec2& min, const Vec2& max )
{
	magicalAssert( !( min.x > max.x || min.y > max.y ), "Invaild operate!" );

	// Clamp the x value.
	if( x < min.x )
		x = min.x;
	if( x > max.x )
		x = max.x;

	// Clamp the y value.
	if( y < min.y )
		y = min.y;
	if( y > max.y )
		y = max.y;
}

inline float Vec2::distance( const Vec2& v ) const
{
	float dx = v.x - x;
	float dy = v.y - y;

	return sqrt( dx * dx + dy * dy );
}

inline float Vec2::distanceSq( const Vec2& v ) const
{
	float dx = v.x - x;
	float dy = v.y - y;
	return dx * dx + dy * dy;
}

inline float Vec2::length( void ) const
{
	return sqrt( x * x + y * y );
}

inline float Vec2::lengthSq( void ) const
{
	return x * x + y * y;
}

inline float Vec2::dot( const Vec2& v ) const
{
	return x * v.x + y * v.y;
}

inline float Vec2::angle( void ) const
{
	return atan2f(y, x);
}

inline void Vec2::negate( void )
{
	x = -x;
	y = -y;
}

inline void Vec2::normalize( void )
{
	float n = x * x + y * y;
	// Already normalized.
	if( n == 1.0f )
		return;

	n = sqrt( n );
	// Too close to zero.
	if( n < MATH_TOLERANCE )
		return;

	n = 1.0f / n;
	x *= n;
	y *= n;
}

inline void Vec2::rotate( const Vec2& point, float angle )
{
	double sinAngle = sin( angle );
	double cosAngle = cos( angle );

	if( point.isZero() )
	{
		float tempX = x * cosAngle - y * sinAngle;
		y = y * cosAngle + x * sinAngle;
		x = tempX;
	}
	else
	{
		float tempX = x - point.x;
		float tempY = y - point.y;

		x = tempX * cosAngle - tempY * sinAngle + point.x;
		y = tempY * cosAngle + tempX * sinAngle + point.y;
	}
}

inline void Vec2::middle( const Vec2& rhs )
{
	Vec2 ret = Vec2( ( x + rhs.x ) / 2.0f, ( y + rhs.y ) / 2.0f );
	x = ret.x;
	y = ret.y;
}

inline Vec2 Mathv2::add( const Vec2& v1, const Vec2& v2 )
{
	return v1 + v2;
}

inline Vec2 Mathv2::add( const Vec2& v1, float rhs )
{
	return v1 + rhs;
}

inline Vec2 Mathv2::sub( const Vec2& v1, const Vec2& v2 )
{
	return v1 - v2;
}

inline Vec2 Mathv2::sub( const Vec2& v1, float rhs )
{
	return v1 - rhs;
}

inline Vec2 Mathv2::mul( const Vec2& v1, const Vec2& v2 )
{
	return v1 * v2;
}

inline Vec2 Mathv2::mul( const Vec2& v1, float rhs )
{
	return v1 * rhs;
}

inline Vec2 Mathv2::div( const Vec2& v1, const Vec2& v2 )
{
	return v1 / v2;
}

inline Vec2 Mathv2::div( const Vec2& v1, float rhs )
{
	return v1 / rhs;
}

inline bool Mathv2::equals( const Vec2& v1, const Vec2& v2 )
{
	return v1 == v2;
}

inline Vec2 Mathv2::copy( const Vec2& rhs )
{
	return Vec2( rhs );
}

inline Vec2 Mathv2::fill( float rx, float ry )
{
	return Vec2( rx, ry );
}

inline Vec2 Mathv2::fill( const float* rhs )
{
	return Vec2( rhs );
}

inline Vec2 Mathv2::fill( const Vec2& rhs )
{
	return Vec2( rhs );
}

inline Vec2 Mathv2::fillZero( void )
{
	return Vec2::ZERO;
}

inline Vec2 Mathv2::clamp( const Vec2& lhs, const Vec2& min, const Vec2& max )
{
	Vec2 ret( lhs );
	ret.clamp( min, max );
	return ret;
}

inline float Mathv2::distance( const Vec2& lhs, const Vec2& v )
{
	return lhs.distance( v );
}

inline float Mathv2::distanceSq( const Vec2& lhs, const Vec2& v )
{
	return lhs.distanceSq( v );
}

inline float Mathv2::length( const Vec2& lhs )
{
	return lhs.length();
}

inline float Mathv2::lengthSq( const Vec2& lhs )
{
	return lhs.lengthSq();
}

inline float Mathv2::dot( const Vec2& lhs, const Vec2& v )
{
	return lhs.dot( v );
}

inline float Mathv2::angle( const Vec2& v )
{
	return v.angle();
}

inline Vec2 Mathv2::negate( const Vec2& v )
{
	Vec2 ret( v );
	ret.negate();
	return ret;
}

inline Vec2 Mathv2::normalize( const Vec2& v )
{
	Vec2 ret( v );
	ret.normalize();
	return ret;
}

inline Vec2 Mathv2::rotate( const Vec2& lhs, const Vec2& point, float angle )
{
	Vec2 ret( lhs );
	ret.rotate( point, angle );
	return ret;
}

inline Vec2 Mathv2::middle( const Vec2& lhs, const Vec2& rhs )
{
	Vec2 ret( lhs );
	ret.middle( rhs );
	return ret;
}