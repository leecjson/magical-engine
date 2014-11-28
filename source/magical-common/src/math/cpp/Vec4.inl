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

inline Vec4 Vec4::fromVec2( const Vec2& v )
{
	return Vec4( v );
}

inline Vec4 Vec4::fromVec3( const Vec3& v )
{
	return Vec4( v );
}

inline bool Vec4::operator==( const Vec4& v ) const
{
	return magicalVec4Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vec4::operator!=( const Vec4& v ) const
{
	return !magicalVec4Equals( tofpointer( this ), tofpointer( &v ) );
}

inline Vec4 Vec4::operator+( const float a ) const
{
	return Vec4( x + a, y + a, z + a, w + a );
}

inline Vec4 Vec4::operator+( const Vec4& v ) const
{
	return Vec4( x + v.x, y + v.y, z + v.z, w + v.w );
}

inline Vec4 Vec4::operator-( const float a ) const
{
	return Vec4( x - a, y - a, z - a, w - a );
}

inline Vec4 Vec4::operator-( const Vec4& v ) const
{
	return Vec4( x - v.x, y - v.y, z - v.z, w - v.w );
}

inline Vec4 Vec4::operator*( const Mat4& m ) const
{
	Vec4 ret;
	magicalVec4MulMat4( tofpointer( &ret ), tofpointer( this ), m.m );
	return ret;
}

inline Vec4 Vec4::operator*( const float a ) const
{
	return Vec4( x * a, y * a, z * a, w * a );
}

inline Vec4 Vec4::operator*( const Vec4& v ) const
{
	return Vec4( x * v.x, y * v.y, z * v.z, w * v.w );
}

inline Vec4 Vec4::operator/( const float a ) const
{
	Vec4 ret;
	magicalVec4DivScalar( tofpointer( &ret ), tofpointer( this ), a );
	return ret;
}

inline Vec4 Vec4::operator/( const Vec4& v ) const
{
	Vec4 ret;
	magicalVec4Div( tofpointer( &ret ), tofpointer( this ), tofpointer( &v ) );
	return ret;
}

inline Vec4& Vec4::operator+=( const float a )
{
	x += a; y += a; z += a; w += a;
	return *this;
}

inline Vec4& Vec4::operator+=( const Vec4& v )
{
	x += v.x; y += v.y; z += v.z; w += v.w;
	return *this;
}

inline Vec4& Vec4::operator-=( const float a )
{
	x -= a; y -= a; z -= a; w -= a;
	return *this;
}

inline Vec4& Vec4::operator-=( const Vec4& v )
{
	x -= v.x; y -= v.y; z -= v.z; w -= v.w;
	return *this;
}

inline Vec4& Vec4::operator*=( const Mat4& m )
{
	magicalVec4MulMat4( tofpointer( this ), tofpointer( this ), m.m );
	return *this;
}

inline Vec4& Vec4::operator*=( const float a )
{
	x *= a; y *= a; z *= a; w *= a;
	return *this;
}

inline Vec4& Vec4::operator*=( const Vec4& v )
{
	x *= v.x; y *= v.y; z *= v.z; w *= v.w;
	return *this;
}

inline Vec4& Vec4::operator/=( const float a )
{
	magicalVec4DivScalar( tofpointer( this ), tofpointer( this ), a );
	return *this;
}

inline Vec4& Vec4::operator/=( const Vec4& v )
{
	magicalVec4Div( tofpointer( this ), tofpointer( this ), tofpointer( &v ) );
	return *this;
}

inline Vec4& Vec4::operator=( const Vec4& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void Vec4::add( Vec4& out, const Vec4& v, const float a )
{
	magicalVec4AddScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec4::add( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	magicalVec4Add( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec4::sub( Vec4& out, const Vec4& v, const float a )
{
	magicalVec4SubScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec4::sub( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	magicalVec4Sub( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec4::mul( Vec4& out, const Vec4& v, const Mat4& m )
{
	magicalVec4MulMat4( tofpointer( &out ), tofpointer( &v ), m.m );
}

inline void Vec4::mul( Vec4& out, const Vec4& v, const float a )
{
	magicalVec4MulScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec4::mul( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	magicalVec4Mul( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec4::div( Vec4& out, const Vec4& v, const float a )
{
	magicalVec4DivScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec4::div( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	magicalVec4Div( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline bool Vec4::isEquals( const Vec4& v ) const
{
	return magicalVec4Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vec4::isZero( void ) const
{
	return magicalVec4IsZero( tofpointer( this ) );
}

inline bool Vec4::isOne( void ) const
{
	return magicalVec4IsOne( tofpointer( this ) );
}

inline bool Vec4::isNormalize( void ) const
{
	return magicalVec4IsNormalize( tofpointer( this ) );
}

inline void Vec4::fill( const float x, const float y, const float z, const float w )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

inline void Vec4::fill( const Vec4& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline void Vec4::fillZero( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

inline void Vec4::fillOne( void )
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
	w = 1.0f;
}

inline void Vec4::fillVec2( const Vec2& v )
{
	x = v.x;
	y = v.y;
	z = 0.0f;
	w = 0.0f;
}

inline void Vec4::fillVec3( const Vec3& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = 0.0f;
}

inline void Vec4::clamp( Vec4& out, const Vec4& v, const Vec4& min, const Vec4& max )
{
	magicalVec4Clamp( tofpointer( &out ), tofpointer( &v ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vec4::negate( Vec4& out, const Vec4& v )
{
	magicalVec4Negate( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vec4::normalize( Vec4& out, const Vec4& v )
{
	magicalVec4Normalize( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vec4::scale( Vec4& out, const Vec4& v, const float s )
{
	magicalVec4Scale( tofpointer( &out ), tofpointer( &v ), s );
}

inline void Vec4::midPointBetween( Vec4& out, const Vec4& v1, const Vec4& v2  )
{
	magicalVec4MidPointBetween( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec4::clamp( const Vec4& min, const Vec4& max )
{
	magicalVec4Clamp( tofpointer( this ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vec4::negate( void )
{
	magicalVec4Negate( tofpointer( this ), tofpointer( this ) );
}

inline void Vec4::normalize( void )
{
	magicalVec4Normalize( tofpointer( this ), tofpointer( this ) );
}

inline void Vec4::scale( const float s )
{
	magicalVec4Scale( tofpointer( this ), tofpointer( this ), s );
}

inline void Vec4::midPointBetween( const Vec4& point )
{
	magicalVec4MidPointBetween( tofpointer( this ), tofpointer( this ), tofpointer( &point ) );
}

inline void Vec4::project( Vec4& h, Vec4& v, const Vec4& n ) const
{
	magicalVec4Project( tofpointer( &h ), tofpointer( &v ), tofpointer( this ), tofpointer( &n ) );
}

inline Vec4 Vec4::getClamp( const Vec4& min, const Vec4& max ) const
{
	Vec4 ret;
	magicalVec4Clamp( tofpointer( &ret ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
	return ret;
}

inline Vec4 Vec4::getNegate( void ) const
{
	Vec4 ret;
	magicalVec4Negate( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vec4 Vec4::getNormalize( void ) const
{
	Vec4 ret;
	magicalVec4Normalize( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vec4 Vec4::getScale( const float s ) const
{
	Vec4 ret;
	magicalVec4Scale( tofpointer( &ret ), tofpointer( this ), s );
	return ret;
}

inline Vec4 Vec4::getMidPointBetween( const Vec4& point ) const
{
	Vec4 ret;
	magicalVec4MidPointBetween( tofpointer( &ret ), tofpointer( this ), tofpointer( &point ) );
	return ret;
}

inline float Vec4::dot( const Vec4& v ) const
{
	return magicalVec4Dot( tofpointer( this ), tofpointer( &v ) );
}

inline float Vec4::distanceBetween( const Vec4& v ) const
{
	return magicalVec4DistanceBetween( tofpointer( this ), tofpointer( &v ) );
}

inline float Vec4::distanceBetweenSq( const Vec4& v ) const
{
	return magicalVec4DistanceBetweenSq( tofpointer( this ), tofpointer( &v ) );
}

inline float Vec4::length( void ) const
{
	return magicalVec4Length( tofpointer( this ) );
}

inline float Vec4::lengthSq( void ) const
{
	return magicalVec4LengthSq( tofpointer( this ) );
}

inline float Vec4::angleBetween( const Vec4& v ) const
{
	return magicalVec4AngleBetween( tofpointer( this ), tofpointer( &v ) );
}