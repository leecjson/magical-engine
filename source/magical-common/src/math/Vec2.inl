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

inline bool Vec2::operator==( const Vec2& v ) const
{
	return magicalFloatEquals( x, v.x ) && magicalFloatEquals( y, v.y );
}

inline bool Vec2::operator!=( const Vec2& v ) const
{
	return !( operator==( v ) );
}

inline bool Vec2::isEquals( const Vec2& v ) const
{
	return magicalFloatEquals( x, v.x ) && magicalFloatEquals( y, v.y );
}

inline bool Vec2::isZero( void ) const
{
	return magicalFloatIsZero( x ) && magicalFloatIsZero( y );
}

inline bool Vec2::isOne( void ) const
{
	return magicalFloatEquals( x, 1.0f ) && magicalFloatEquals( y, 1.0f );
}

inline bool Vec2::isNormalize( void ) const
{
	float n = x * x + y * y;
	return magicalFloatEquals( n, 1.0f );
}

inline Vec2 Vec2::operator+( float a ) const
{
	return Vec2( x + a, y + a );
}

inline Vec2 Vec2::operator+( const Vec2& v ) const
{
	return Vec2( x + v.x, y + v.y );
}

inline Vec2 Vec2::operator-( float a ) const
{
	return Vec2( x - a, y - a );
}

inline Vec2 Vec2::operator-( const Vec2& v ) const
{
	return Vec2( x - v.x, y - v.y );
}

inline Vec2 Vec2::operator*( float a ) const
{
	return Vec2( x * a, y * a );
}

inline Vec2 Vec2::operator*( const Vec2& v ) const
{
	return Vec2( x * v.x, y * v.y );
}

inline Vec2 Vec2::operator/( float a ) const
{
	magicalAssert( !magicalFloatIsZero( a ), "division by 0.f" );
	return Vec2( x / a, y / a );
}

inline Vec2 Vec2::operator/( const Vec2& v ) const
{
	magicalAssert( !magicalFloatIsZero( v.x ) && !magicalFloatIsZero( v.y ), "division by 0.f" );
	return Vec2( x / v.x, y / v.y );
}

inline Vec2& Vec2::operator+=( float a )
{
	x += a;
	y += a;
	return *this;
}

inline Vec2& Vec2::operator+=( const Vec2& v )
{
	x += v.x;
	y += v.y;
	return *this;
}

inline Vec2& Vec2::operator-=( float a )
{
	x -= a;
	y -= a;
	return *this;
}

inline Vec2& Vec2::operator-=( const Vec2& v )
{
	x -= v.x;
	y -= v.y;
	return *this;
}

inline Vec2& Vec2::operator*=( float a )
{
	x *= a;
	y *= a;
	return *this;
}

inline Vec2& Vec2::operator*=( const Vec2& v )
{
	x *= v.x;
	y *= v.y;
	return *this;
}

inline Vec2& Vec2::operator/=( float a )
{
	magicalAssert( !magicalFloatIsZero( a ), "division by 0.f" );
	x /= a;
	y /= a;
	return *this;
}

inline Vec2& Vec2::operator/=( const Vec2& v )
{
	magicalAssert( !magicalFloatIsZero( v.x ) && !magicalFloatIsZero( v.y ), "division by 0.f" );
	x /= v.x;
	y /= v.y;
	return *this;
}

inline Vec2& Vec2::operator=( const Vec2& v )
{
	x = v.x;
	y = v.y;
	return *this;
}

inline Vec2 Vec2::add( float a ) const
{
	return Vec2( x + a, y + a );
}

inline Vec2 Vec2::add( const Vec2& v ) const
{
	return Vec2( x + v.x, y + v.y );
}

inline Vec2 Vec2::sub( float a ) const
{
	return Vec2( x - a, y - a );
}

inline Vec2 Vec2::sub( const Vec2& v ) const
{
	return Vec2( x - v.x, y - v.y );
}

inline Vec2 Vec2::mul( float a ) const
{
	return Vec2( x * a, y * a );
}

inline Vec2 Vec2::mul( const Vec2& v ) const
{
	return Vec2( x * v.x, y * v.y );
}

inline Vec2 Vec2::div( float a ) const
{
	magicalAssert( !magicalFloatIsZero( a ), "division by 0.f" );
	return Vec2( x / a, y / a );
}

inline Vec2 Vec2::div( const Vec2& v ) const
{
	magicalAssert( !magicalFloatIsZero( v.x ) && !magicalFloatIsZero( v.y ), "division by 0.f" );
	return Vec2( x / v.x, y / v.y );
}

inline void Vec2::addfill( float a )
{
	x += a;
	y += a;
}

inline void Vec2::addfill( const Vec2& v )
{
	x += v.x;
	y += v.y;
}

inline void Vec2::subfill( float a )
{
	x -= a;
	y -= a;
}

inline void Vec2::subfill( const Vec2& v )
{
	x -= v.x;
	y -= v.y;
}

inline void Vec2::mulfill( float a )
{
	x *= a;
	y *= a;
}

inline void Vec2::mulfill( const Vec2& v )
{
	x *= v.x;
	y *= v.y;
}

inline void Vec2::divfill( float a )
{
	magicalAssert( !magicalFloatIsZero( a ), "division by 0.f" );
	x /= a;
	y /= a;
}

inline void Vec2::divfill( const Vec2& v )
{
	magicalAssert( !magicalFloatIsZero( v.x ) && !magicalFloatIsZero( v.y ), "division by 0.f" );
	x /= v.x;
	y /= v.y;
}

inline void Vec2::fill( float x, float y )
{
	this->x = x;
	this->y = y;
}

inline void Vec2::fill( const Vec2& v )
{
	x = v.x;
	y = v.y;
}

inline void Vec2::fillZero( void )
{
	x = 0.0f;
	y = 0.0f;
}

inline void Vec2::fillOne( void )
{
	x = 1.0f;
	y = 1.0f;
}

inline float Vec2::dot( const Vec2& v ) const
{
	return x * v.x + y * v.y;
}

inline float Vec2::distanceBetween( const Vec2& v ) const
{
	float dx = v.x - x;
	float dy = v.y - y;

	return sqrt( dx * dx + dy * dy );
}

inline float Vec2::distanceBetweenSq( const Vec2& v ) const
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

inline float Vec2::angle( void ) const
{
	return atan2f( y, x );
}

inline float Vec2::angleBetween( const Vec2& v ) const
{
	float dz = x * v.y - y * v.x;
	return atan2f( fabsf( dz ) + FLT_MIN, dot( v ) );
}

inline void Vec2::clamp( const Vec2& min, const Vec2& max )
{
	magicalAssert( !( min.x > max.x || min.y > max.y ), "Invaild operate!" );

	if( x < min.x )
		x = min.x;
	if( x > max.x )
		x = max.x;

	if( y < min.y )
		y = min.y;
	if( y > max.y )
		y = max.y;
}

inline void Vec2::negate( void )
{
	x = -x;
	y = -y;
}

inline void Vec2::normalize( void )
{
	float n = x * x + y * y;
	if( magicalFloatEquals( n, 1.0f ) )
		return;

	n = sqrt( n );
	if( magicalFloatIsZero( n ) )
		return;

	n = 1.0f / n;
	x *= n;
	y *= n;
}

inline void Vec2::rotate( const Vec2& point, float angle )
{
	double sin_angle = sin( angle );
	double cos_angle = cos( angle );

	if( point.isZero() )
	{
		float temp_x = x * cos_angle - y * sin_angle;
		y = y * cos_angle + x * sin_angle;
		x = temp_x;
	}
	else
	{
		float temp_x = x - point.x;
		float temp_y = y - point.y;

		x = temp_x * cos_angle - temp_y * sin_angle + point.x;
		y = temp_y * cos_angle + temp_x * sin_angle + point.y;
	}
}

inline Vec2 Vec2::getClamp( const Vec2& min, const Vec2& max ) const
{
	Vec2 ret( *this );
	ret.clamp( min, max );
	return ret;
}

inline Vec2 Vec2::getNegate( void ) const
{
	Vec2 ret( *this );
	ret.negate();
	return ret;
}

inline Vec2 Vec2::getNormalize( void ) const
{
	Vec2 ret( *this );
	ret.normalize();
	return ret;
}

inline Vec2 Vec2::getRotate( const Vec2& point, float angle ) const
{
	Vec2 ret( *this );
	ret.rotate( point, angle );
	return ret;
}

inline void MathVec2::add( Vec2& out, const Vec2& v, float a )
{
	out = v + a;
}

inline void MathVec2::add( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	out = v1 + v2;
}

inline void MathVec2::sub( Vec2& out, const Vec2& v, float a )
{
	out = v - a;
}

inline void MathVec2::sub( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	out = v1 - v2;
}

inline void MathVec2::mul( Vec2& out, const Vec2& v, float a )
{
	out = v * a;
}

inline void MathVec2::mul( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	out = v1 * v2;
}

inline void MathVec2::div( Vec2& out, const Vec2& v, float a )
{
	out = v / a;
}

inline void MathVec2::div( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	out = v1 / v2;
}

inline void MathVec2::clamp( Vec2& out, const Vec2& v, const Vec2& min, const Vec2& max )
{
	out = v.getClamp( min, max );
}

inline void MathVec2::negate( Vec2& out, const Vec2& v )
{
	out = v.getNegate();
}

inline void MathVec2::normalize( Vec2& out, const Vec2& v )
{
	out = v.getNormalize();
}

inline void MathVec2::rotate( Vec2& out, const Vec2& v, const Vec2& point, float angle )
{
	out = v.getRotate( point, angle );
}