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

inline Vec2 Vec2::fromVec3( const Vec3& v )
{
	return Vec2( v );
}

inline Vec2 Vec2::fromVec4( const Vec4& v )
{
	return Vec2( v );
}

inline void Vec2::add( Vec2& out, const Vec2& v, const float a )
{
	magicalVec2AddScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec2::add( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	magicalVec2Add( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec2::sub( Vec2& out, const Vec2& v, const float a )
{
	magicalVec2SubScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec2::sub( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	magicalVec2Sub( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec2::mul( Vec2& out, const Vec2& v, const float a )
{
	magicalVec2MulScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec2::mul( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	magicalVec2Mul( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec2::div( Vec2& out, const Vec2& v, const float a )
{
	magicalVec2DivScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec2::div( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	magicalVec2Div( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec2::clamp( Vec2& out, const Vec2& v, const Vec2& min, const Vec2& max )
{
	magicalVec2Clamp( tofpointer( &out ), tofpointer( &v ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vec2::negate( Vec2& out, const Vec2& v )
{
	magicalVec2Negate( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vec2::normalize( Vec2& out, const Vec2& v )
{
	magicalVec2Normalize( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vec2::rotate( Vec2& out, const Vec2& v, const float angle )
{
	magicalVec2Rotate( tofpointer( &out ), tofpointer( &v ), angle );
}

inline void Vec2::scale( Vec2& out, const Vec2& v, const float s )
{
	magicalVec2Scale( tofpointer( &out ), tofpointer( &v ), s );
}

inline void Vec2::midPointBetween( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	magicalVec2MidPointBetween( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline bool Vec2::operator==( const Vec2& v ) const
{
	return magicalVec2Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vec2::operator!=( const Vec2& v ) const
{
	return !magicalVec2Equals( tofpointer( this ), tofpointer( &v ) );
}

inline Vec2 Vec2::operator+( const float a ) const
{
	return Vec2( x + a, y + a );
}

inline Vec2 Vec2::operator+( const Vec2& v ) const
{
	return Vec2( x + v.x, y + v.y );
}

inline Vec2 Vec2::operator-( const float a ) const
{
	return Vec2( x - a, y - a );
}

inline Vec2 Vec2::operator-( const Vec2& v ) const
{
	return Vec2( x - v.x, y - v.y );
}

inline Vec2 Vec2::operator*( const float a ) const
{
	return Vec2( x * a, y * a );
}

inline Vec2 Vec2::operator*( const Vec2& v ) const
{
	return Vec2( x * v.x, y * v.y );
}

inline Vec2 Vec2::operator/( const float a ) const
{
	Vec2 ret;
	magicalVec2DivScalar( tofpointer( &ret ), tofpointer( this ), a );
	return ret;
}

inline Vec2 Vec2::operator/( const Vec2& v ) const
{
	Vec2 ret;
	magicalVec2Div( tofpointer( &ret ), tofpointer( this ), tofpointer( &v ) );
	return ret;
}

inline Vec2& Vec2::operator+=( const float a )
{
	x += a; y += a;
	return *this;
}

inline Vec2& Vec2::operator+=( const Vec2& v )
{
	x += v.x; y += v.y;
	return *this;
}

inline Vec2& Vec2::operator-=( const float a )
{
	x -= a; y -= a;
	return *this;
}

inline Vec2& Vec2::operator-=( const Vec2& v )
{
	x -= v.x; y -= v.y;
	return *this;
}

inline Vec2& Vec2::operator*=( const float a )
{
	x *= a; y *= a;
	return *this;
}

inline Vec2& Vec2::operator*=( const Vec2& v )
{
	x *= v.x; y *= v.y;
	return *this;
}

inline Vec2& Vec2::operator/=( const float a )
{
	magicalVec2DivScalar( tofpointer( this ), tofpointer( this ), a );
	return *this;
}

inline Vec2& Vec2::operator/=( const Vec2& v )
{
	magicalVec2Div( tofpointer( this ), tofpointer( this ), tofpointer( &v ) );
	return *this;
}

inline Vec2& Vec2::operator=( const Vec2& v )
{
	x = v.x; y = v.y;
	return *this;
}

inline bool Vec2::isEquals( const Vec2& v ) const
{
	return magicalVec2Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vec2::isZero( void ) const
{
	return magicalVec2IsZero( tofpointer( this ) );
}

inline bool Vec2::isOne( void ) const
{
	return magicalVec2IsOne( tofpointer( this ) );
}

inline bool Vec2::isNormalize( void ) const
{
	return magicalVec2IsNormalize( tofpointer( this ) );
}

inline void Vec2::fill( const Vec2& v )
{
	x = v.x; y = v.y;
}

inline void Vec2::fill( const float x, const float y )
{
	this->x = x; 
	this->y = y;
}

inline void Vec2::fillZero( void )
{
	x = 0.0f; y = 0.0f;
}

inline void Vec2::fillOne( void )
{
	x = 1.0f; y = 1.0f;
}

inline void Vec2::fillVec3( const Vec3& v )
{
	x = v.x; y = v.y;
}

inline void Vec2::fillVec4( const Vec3& v )
{
	x = v.x; y = v.y;
}

inline void Vec2::clamp( const Vec2& min, const Vec2& max )
{
	magicalVec2Clamp( tofpointer( this ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vec2::negate( void )
{
	magicalVec2Negate( tofpointer( this ), tofpointer( this ) );
}

inline void Vec2::normalize( void )
{
	magicalVec2Normalize( tofpointer( this ), tofpointer( this ) );
}

inline void Vec2::rotate( const float angle )
{
	magicalVec2Rotate( tofpointer( this ), tofpointer( this ), angle );
}

inline void Vec2::scale( const float s )
{
	magicalVec2Scale( tofpointer( this ), tofpointer( this ), s );
}

inline void Vec2::midPointBetween( const Vec2& point )
{
	magicalVec2MidPointBetween( tofpointer( this ), tofpointer( this ), tofpointer( &point ) );
}

inline void Vec2::project( Vec2& h, Vec2& v, const Vec2& n ) const
{
	magicalVec2Project( tofpointer( &h ), tofpointer( &v ), tofpointer( this ), tofpointer( &n ) );
}

inline Vec2 Vec2::getClamp( const Vec2& min, const Vec2& max ) const
{
	Vec2 ret;
	magicalVec2Clamp( tofpointer( &ret ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
	return ret;
}

inline Vec2 Vec2::getNegate( void ) const
{
	Vec2 ret;
	magicalVec2Negate( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vec2 Vec2::getNormalize( void ) const
{
	Vec2 ret;
	magicalVec2Normalize( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vec2 Vec2::getRotate( const float angle ) const
{
	Vec2 ret;
	magicalVec2Rotate( tofpointer( &ret ), tofpointer( this ), angle );
	return ret;
}

inline Vec2 Vec2::getScale( const float s ) const
{
	Vec2 ret;
	magicalVec2Scale( tofpointer( &ret ), tofpointer( this ), s );
	return ret;
}

inline Vec2 Vec2::getMidPointBetween( const Vec2& point ) const
{
	Vec2 ret;
	magicalVec2MidPointBetween( tofpointer( &ret ), tofpointer( this ), tofpointer( &point ) );
	return ret;
}

inline float Vec2::dot( const Vec2& v ) const
{
	return magicalVec2Dot( tofpointer( this ), tofpointer( &v ) );
}

inline float Vec2::distanceBetween( const Vec2& v ) const
{
	return magicalVec2DistanceBetween( tofpointer( this ), tofpointer( &v ) );
}

inline float Vec2::distanceBetweenSq( const Vec2& v ) const
{
	return magicalVec2DistanceBetweenSq( tofpointer( this ), tofpointer( &v ) );
}

inline float Vec2::length( void ) const
{
	return magicalVec2Length( tofpointer( this ) );
}

inline float Vec2::lengthSq( void ) const
{
	return magicalVec2LengthSq( tofpointer( this ) );
}

inline float Vec2::angleBetween( const Vec2& v ) const
{
	return magicalVec2AngleBetween( tofpointer( this ), tofpointer( &v ) );
}