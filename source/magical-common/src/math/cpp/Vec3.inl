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

inline bool Vec3::operator==( const Vec3& v ) const
{
	return magicalVec3Equals( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline bool Vec3::operator!=( const Vec3& v ) const
{
	return !magicalVec3Equals( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline bool Vec3::isEquals( const Vec3& v ) const
{
	return magicalVec3Equals( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline bool Vec3::isZero( void ) const
{
	return magicalVec3IsZero( TOFLOAT( this ) );
}

inline bool Vec3::isOne( void ) const
{
	return magicalVec3IsOne( TOFLOAT( this ) );
}

inline bool Vec3::isNormalize( void ) const
{
	return magicalVec3IsNormalize( TOFLOAT( this ) );
}

inline Vec3 Vec3::operator+( float a ) const
{
	return Vec3( x + a, y + a, z + a );
}

inline Vec3 Vec3::operator+( const Vec3& v ) const
{
	return Vec3( x + v.x, y + v.y, z + v.z );
}

inline Vec3 Vec3::operator-( float a ) const
{
	return Vec3( x - a, y - a, z - a );
}

inline Vec3 Vec3::operator-( const Vec3& v ) const
{
	return Vec3( x - v.x, y - v.y, z - v.z );
}

inline Vec3 Vec3::operator*( float a ) const
{
	return Vec3( x * a, y * a, z * a );
}

inline Vec3 Vec3::operator*( const Vec3& v ) const
{
	return Vec3( x * v.x, y * v.y, z * v.z );
}

inline Vec3 Vec3::operator/( float a ) const
{
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	return Vec3( x / a, y / a, z / a );
}

inline Vec3 Vec3::operator/( const Vec3& v ) const
{
	magicalMathAssert( !magicalVec3IsZero( TOFLOAT( &v ) ), "division by 0.f" );

	return Vec3( x / v.x, y / v.y, z / v.z );
}

inline Vec3& Vec3::operator+=( float a )
{
	x += a;
	y += a;
	z += a;
	return *this;
}

inline Vec3& Vec3::operator+=( const Vec3& v )
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

inline Vec3& Vec3::operator-=( float a )
{
	x -= a;
	y -= a;
	z -= a;
	return *this;
}

inline Vec3& Vec3::operator-=( const Vec3& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

inline Vec3& Vec3::operator*=( float a )
{
	x *= a;
	y *= a;
	z *= a;
	return *this;
}

inline Vec3& Vec3::operator*=( const Vec3& v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

inline Vec3& Vec3::operator/=( float a )
{
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	x /= a;
	y /= a;
	z /= a;
	return *this;
}

inline Vec3& Vec3::operator/=( const Vec3& v )
{
	magicalMathAssert( !magicalVec3IsZero( TOFLOAT( &v ) ), "division by 0.f" );

	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

inline Vec3& Vec3::operator=( const Vec3& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

inline Vec3 Vec3::add( float a ) const
{
	return Vec3( x + a, y + a, z + a );
}

inline Vec3 Vec3::add( const Vec3& v ) const
{
	return Vec3( x + v.x, y + v.y, z + v.z );
}

inline Vec3 Vec3::sub( float a ) const
{
	return Vec3( x - a, y - a, z - a );
}

inline Vec3 Vec3::sub( const Vec3& v ) const
{
	return Vec3( x - v.x, y - v.y, z - v.z );
}

inline Vec3 Vec3::mul( float a ) const
{
	return Vec3( x * a, y * a, z * a );
}

inline Vec3 Vec3::mul( const Vec3& v ) const
{
	return Vec3( x * v.x, y * v.y, z * v.z );
}

inline Vec3 Vec3::div( float a ) const
{
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	return Vec3( x / a, y / a, z / a );
}

inline Vec3 Vec3::div( const Vec3& v ) const
{
	magicalMathAssert( !magicalVec3IsZero( TOFLOAT( &v ) ), "division by 0.f" );

	return Vec3( x / v.x, y / v.y, z / v.z );
}

inline void Vec3::addfill( float a )
{
	x += a;
	y += a;
	z += a;
}

inline void Vec3::addfill( const Vec3& v )
{
	x += v.x;
	y += v.y;
	z += v.z;
}

inline void Vec3::subfill( float a )
{
	x -= a;
	y -= a;
	z -= a;
}

inline void Vec3::subfill( const Vec3& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

inline void Vec3::mulfill( float a )
{
	x *= a;
	y *= a;
	z *= a;
}

inline void Vec3::mulfill( const Vec3& v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
}

inline void Vec3::divfill( float a )
{
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	x /= a;
	y /= a;
	z /= a;
}

inline void Vec3::divfill( const Vec3& v )
{
	magicalMathAssert( !magicalVec3IsZero( TOFLOAT( &v ) ), "division by 0.f" );

	x /= v.x;
	y /= v.y;
	z /= v.z;
}

inline void Vec3::fill( float x, float y, float z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

inline void Vec3::fill( const Vec3& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
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

inline float Vec3::dot( const Vec3& v ) const
{
	return magicalVec3Dot( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline float Vec3::distanceBetween( const Vec3& v ) const
{
	return magicalVec3DistanceBetween( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline float Vec3::distanceBetweenSq( const Vec3& v ) const
{
	return magicalVec3DistanceBetweenSq( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline float Vec3::length( void ) const
{
	return magicalVec3Length( TOFLOAT( this ) );
}

inline float Vec3::lengthSq( void ) const
{
	return magicalVec3LengthSq( TOFLOAT( this ) );
}

inline float Vec3::angleBetween( const Vec3& v ) const
{
	return magicalVec3AngleBetween( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline Vec3 Vec3::cross( const Vec3& v ) const
{
	Vec3 ret;
	magicalVec3Cross( TOFLOAT( &ret ), TOFLOAT( this ), TOFLOAT( &v ) );
	return ret;
}

inline void Vec3::fillCross( const Vec3& v )
{
	magicalVec3Cross( TOFLOAT( this ), TOFLOAT( this ), TOFLOAT( &v ) );
}

inline Vec3 Vec3::clamp( const Vec3& min, const Vec3& max ) const
{
	Vec3 ret;
	magicalVec3Clamp( TOFLOAT( &ret ), TOFLOAT( this ), TOFLOAT( &min ), TOFLOAT( &max ) );
	return ret;
}

inline void Vec3::fillClamp( const Vec3& min, const Vec3& max )
{
	magicalVec3Clamp( TOFLOAT( this ), TOFLOAT( this ), TOFLOAT( &min ), TOFLOAT( &max ) );
}

inline Vec3 Vec3::negate( void ) const
{
	Vec3 ret;
	magicalVec3Negate( TOFLOAT( &ret ), TOFLOAT( this ) );
	return ret;
}

inline void Vec3::fillNegate( void )
{
	magicalVec3Negate( TOFLOAT( this ), TOFLOAT( this ) );
}

inline Vec3 Vec3::normalize( void ) const
{
	Vec3 ret;
	magicalVec3Normalize( TOFLOAT( &ret ), TOFLOAT( this ) );
	return ret;
}

inline void Vec3::fillNormalize( void )
{
	magicalVec3Normalize( TOFLOAT( this ), TOFLOAT( this ) );
}

inline Vec3 Vec3::scale( float s ) const
{
	Vec3 ret;
	magicalVec3Scale( TOFLOAT( &ret ), TOFLOAT( this ), s );
	return ret;
}

inline void Vec3::fillScale( float s )
{
	magicalVec3Scale( TOFLOAT( this ), TOFLOAT( this ), s );
}

inline Vec3 Vec3::midPointBetween( const Vec3& point ) const
{
	Vec3 ret;
	magicalVec3MidPointBetween( TOFLOAT( &ret ), TOFLOAT( this ), TOFLOAT( &point ) );
	return ret;
}

inline void Vec3::project( Vec3& h, Vec3& v, const Vec3& n ) const
{
	magicalVec3Project( TOFLOAT( &h ), TOFLOAT( &v ), TOFLOAT( this ), TOFLOAT( &n ) );
}

inline void MathVec3::add( Vec3& out, const Vec3& v, float a )
{
	magicalVec3AddScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec3::add( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3Add( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec3::sub( Vec3& out, const Vec3& v, float a )
{
	magicalVec3SubScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec3::sub( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3Sub( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec3::mul( Vec3& out, const Vec3& v, float a )
{
	magicalVec3MulScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec3::mul( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3Mul( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec3::div( Vec3& out, const Vec3& v, float a )
{
	magicalVec3DivScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec3::div( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3Div( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec3::cross( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3Cross( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec3::clamp( Vec3& out, const Vec3& v, const Vec3& min, const Vec3& max )
{
	magicalVec3Clamp( TOFLOAT( &out ), TOFLOAT( &v ), TOFLOAT( &min ), TOFLOAT( &max ) );
}

inline void MathVec3::negate( Vec3& out, const Vec3& v )
{
	magicalVec3Negate( TOFLOAT( &out ), TOFLOAT( &v ) );
}

inline void MathVec3::normalize( Vec3& out, const Vec3& v )
{
	magicalVec3Normalize( TOFLOAT( &out ), TOFLOAT( &v ) );
}

inline void MathVec3::scale( Vec3& out, const Vec3& v, float s )
{
	magicalVec3Scale( TOFLOAT( &out ), TOFLOAT( &v ), s );
}

inline void MathVec3::midPointBetween( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	magicalVec3MidPointBetween( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}