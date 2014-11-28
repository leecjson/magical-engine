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

inline Vec3 Vec3::fromVec2( const Vec2& v )
{
	return Vec3( v );
}

inline Vec3 Vec3::fromVec4( const Vec4& v )
{
	return Vec3( v );
}

inline bool Vec3::operator==( const Vec3& v ) const
{
	return magicalVec3Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vec3::operator!=( const Vec3& v ) const
{
	return !magicalVec3Equals( tofpointer( this ), tofpointer( &v ) );
}

inline Vec3 Vec3::operator+( const float a ) const
{
	return Vec3( x + a, y + a, z + a );
}

inline Vec3 Vec3::operator+( const Vec3& v ) const
{
	return Vec3( x + v.x, y + v.y, z + v.z );
}

inline Vec3 Vec3::operator-( const float a ) const
{
	return Vec3( x - a, y - a, z - a );
}

inline Vec3 Vec3::operator-( const Vec3& v ) const
{
	return Vec3( x - v.x, y - v.y, z - v.z );
}

inline Vec3 Vec3::operator*( const Mat4& m ) const
{
	Vec3 ret;
	magicalVec3MulMat4( tofpointer( &ret ), tofpointer( this ), m.m );
	return ret;
}

inline Vec3 Vec3::operator*( const float a ) const
{
	return Vec3( x * a, y * a, z * a );
}

inline Vec3 Vec3::operator*( const Vec3& v ) const
{
	return Vec3( x * v.x, y * v.y, z * v.z );
}

inline Vec3 Vec3::operator/( const float a ) const
{
	Vec3 ret;
	magicalVec3DivScalar( tofpointer( &ret ), tofpointer( this ), a );
	return ret;
}

inline Vec3 Vec3::operator/( const Vec3& v ) const
{
	Vec3 ret;
	magicalVec3Div( tofpointer( &ret ), tofpointer( this ), tofpointer( &v ) );
	return ret;
}

inline Vec3& Vec3::operator+=( const float a )
{
	x += a; y += a; z += a;
	return *this;
}

inline Vec3& Vec3::operator+=( const Vec3& v )
{
	x += v.x; y += v.y; z += v.z;
	return *this;
}

inline Vec3& Vec3::operator-=( const float a )
{
	x -= a; y -= a; z -= a;
	return *this;
}

inline Vec3& Vec3::operator-=( const Vec3& v )
{
	x -= v.x; y -= v.y; z -= v.z;
	return *this;
}

inline Vec3& Vec3::operator*=( const Mat4& m )
{
	magicalVec3MulMat4( tofpointer( this ), tofpointer( this ), m.m );
	return *this;
}

inline Vec3& Vec3::operator*=( const float a )
{
	x *= a; y *= a; z *= a;
	return *this;
}

inline Vec3& Vec3::operator*=( const Vec3& v )
{
	x *= v.x; y *= v.y; z *= v.z;
	return *this;
}

inline Vec3& Vec3::operator/=( const float a )
{
	magicalVec3DivScalar( tofpointer( this ), tofpointer( this ), a );
	return *this;
}

inline Vec3& Vec3::operator/=( const Vec3& v )
{
	magicalVec3Div( tofpointer( this ), tofpointer( this ), tofpointer( &v ) );
	return *this;
}

inline Vec3& Vec3::operator=( const Vec3& v )
{
	x = v.x; y = v.y; z = v.z;
	return *this;
}

inline void Vec3::add( Vec3& out, const Vec3& v, const float a )
{
	magicalVec3AddScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec3::add( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3Add( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec3::sub( Vec3& out, const Vec3& v, const float a )
{
	magicalVec3SubScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec3::sub( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3Sub( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec3::mul( Vec3& out, const Vec3& v, const Mat4& m )
{
	magicalVec3MulMat4( tofpointer( &out ), tofpointer( &v ), m.m );
}

inline void Vec3::mul( Vec3& out, const Vec3& v, const float a )
{
	magicalVec3MulScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec3::mul( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3Mul( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec3::div( Vec3& out, const Vec3& v, const float a )
{
	magicalVec3DivScalar( tofpointer( &out ), tofpointer( &v ), a );
}

inline void Vec3::div( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3Div( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline bool Vec3::isEquals( const Vec3& v ) const
{
	return magicalVec3Equals( tofpointer( this ), tofpointer( &v ) );
}

inline bool Vec3::isZero( void ) const
{
	return magicalVec3IsZero( tofpointer( this ) );
}

inline bool Vec3::isOne( void ) const
{
	return magicalVec3IsOne( tofpointer( this ) );
}

inline bool Vec3::isNormalize( void ) const
{
	return magicalVec3IsNormalize( tofpointer( this ) );
}

inline void Vec3::fill( const Vec3& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
}

inline void Vec3::fill( const float x, const float y, const float z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

inline void Vec3::fillZero( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

inline void Vec3::fillOne( void )
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
}

inline void Vec3::fillVec2( const Vec2& v )
{
	x = v.x;
	y = v.y;
	z = 0.0f;
}

inline void Vec3::fillVec4( const Vec4& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
}

inline void Vec3::cross( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3Cross( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec3::clamp( Vec3& out, const Vec3& v, const Vec3& min, const Vec3& max )
{
	magicalVec3Clamp( tofpointer( &out ), tofpointer( &v ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vec3::negate( Vec3& out, const Vec3& v )
{
	magicalVec3Negate( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vec3::normalize( Vec3& out, const Vec3& v )
{
	magicalVec3Normalize( tofpointer( &out ), tofpointer( &v ) );
}

inline void Vec3::scale( Vec3& out, const Vec3& v, const float s )
{
	magicalVec3Scale( tofpointer( &out ), tofpointer( &v ), s );
}

inline void Vec3::midPointBetween( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3MidPointBetween( tofpointer( &out ), tofpointer( &v1 ), tofpointer( &v2 ) );
}

inline void Vec3::cross( const Vec3& v )
{
	magicalVec3Cross( tofpointer( this ), tofpointer( this ), tofpointer( &v ) );
}

inline void Vec3::clamp( const Vec3& min, const Vec3& max )
{
	magicalVec3Clamp( tofpointer( this ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
}

inline void Vec3::negate( void )
{
	magicalVec3Negate( tofpointer( this ), tofpointer( this ) );
}

inline void Vec3::normalize( void )
{
	magicalVec3Normalize( tofpointer( this ), tofpointer( this ) );
}

inline void Vec3::scale( const float s )
{
	magicalVec3Scale( tofpointer( this ), tofpointer( this ), s );
}

inline void Vec3::midPointBetween( const Vec3& point )
{
	magicalVec3MidPointBetween( tofpointer( this ), tofpointer( this ), tofpointer( &point ) );
}

inline void Vec3::project( Vec3& h, Vec3& v, const Vec3& n ) const
{
	magicalVec3Project( tofpointer( &h ), tofpointer( &v ), tofpointer( this ), tofpointer( &n ) );
}

inline Vec3 Vec3::getCross( const Vec3& v ) const
{
	Vec3 ret;
	magicalVec3Cross( tofpointer( &ret ), tofpointer( this ), tofpointer( &v ) );
	return ret;
}

inline Vec3 Vec3::getClamp( const Vec3& min, const Vec3& max ) const
{
	Vec3 ret;
	magicalVec3Clamp( tofpointer( &ret ), tofpointer( this ), tofpointer( &min ), tofpointer( &max ) );
	return ret;
}

inline Vec3 Vec3::getNegate( void ) const
{
	Vec3 ret;
	magicalVec3Negate( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vec3 Vec3::getNormalize( void ) const
{
	Vec3 ret;
	magicalVec3Normalize( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vec3 Vec3::getScale( const float s ) const
{
	Vec3 ret;
	magicalVec3Scale( tofpointer( &ret ), tofpointer( this ), s );
	return ret;
}

inline Vec3 Vec3::getMidPointBetween( const Vec3& point ) const
{
	Vec3 ret;
	magicalVec3MidPointBetween( tofpointer( &ret ), tofpointer( this ), tofpointer( &point ) );
	return ret;
}

inline float Vec3::dot( const Vec3& v ) const
{
	return magicalVec3Dot( tofpointer( this ), tofpointer( &v ) );
}

inline float Vec3::distanceBetween( const Vec3& v ) const
{
	return magicalVec3DistanceBetween( tofpointer( this ), tofpointer( &v ) );
}

inline float Vec3::distanceBetweenSq( const Vec3& v ) const
{
	return magicalVec3DistanceBetweenSq( tofpointer( this ), tofpointer( &v ) );
}

inline float Vec3::length( void ) const
{
	return magicalVec3Length( tofpointer( this ) );
}

inline float Vec3::lengthSq( void ) const
{
	return magicalVec3LengthSq( tofpointer( this ) );
}

inline float Vec3::angleBetween( const Vec3& v ) const
{
	return magicalVec3AngleBetween( tofpointer( this ), tofpointer( &v ) );
}