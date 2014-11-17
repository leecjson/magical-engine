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

inline bool Vec4::operator==( const Vec4& v ) const
{
	return magicalVec4Equals( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline bool Vec4::operator!=( const Vec4& v ) const
{
	return !magicalVec4Equals( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline bool Vec4::isEquals( const Vec4& v ) const
{
	return magicalVec4Equals( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline bool Vec4::isZero( void ) const
{
	return magicalVec4IsZero( TOFLOAT( this ) );
}

inline bool Vec4::isOne( void ) const
{
	return magicalVec4IsOne( TOFLOAT( this ) );
}

inline bool Vec4::isNormalize( void ) const
{
	return magicalVec4IsNormalize( TOFLOAT( this ) );
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
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	return Vec4( x / a, y / a, z / a, w / a );
}

inline Vec4 Vec4::operator/( const Vec4& v ) const
{
	magicalMathAssert( !magicalVec4IsZero( TOFLOAT( &v ) ), "division by 0.f" );

	return Vec4( x / v.x, y / v.y, z / v.z, w / v.w );
}

inline Vec4& Vec4::operator+=( const float a )
{
	x += a;
	y += a;
	z += a;
	w += a;
	return *this;
}

inline Vec4& Vec4::operator+=( const Vec4& v )
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

inline Vec4& Vec4::operator-=( const float a )
{
	x -= a;
	y -= a;
	z -= a;
	w -= a;
	return *this;
}

inline Vec4& Vec4::operator-=( const Vec4& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

inline Vec4& Vec4::operator*=( const float a )
{
	x *= a;
	y *= a;
	z *= a;
	w *= a;
	return *this;
}

inline Vec4& Vec4::operator*=( const Vec4& v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
	return *this;
}

inline Vec4& Vec4::operator/=( const float a )
{
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	x /= a;
	y /= a;
	z /= a;
	w /= a;
	return *this;
}

inline Vec4& Vec4::operator/=( const Vec4& v )
{
	magicalMathAssert( !magicalVec4IsZero( TOFLOAT( &v ) ), "division by 0.f" );

	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;
	return *this;
}

inline Vec4& Vec4::operator=( const Vec4& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}

inline Vec4 Vec4::add( const float a ) const
{
	return Vec4( x + a, y + a, z + a, w + a );
}

inline Vec4 Vec4::add( const Vec4& v ) const
{
	return Vec4( x + v.x, y + v.y, z + v.z, w + v.w );
}

inline Vec4 Vec4::sub( const float a ) const
{
	return Vec4( x - a, y - a, z - a, w - a );
}

inline Vec4 Vec4::sub( const Vec4& v ) const
{
	return Vec4( x - v.x, y - v.y, z - v.z, w - v.w );
}

inline Vec4 Vec4::mul( const float a ) const
{
	return Vec4( x * a, y * a, z * a, w * a );
}

inline Vec4 Vec4::mul( const Vec4& v ) const
{
	return Vec4( x * v.x, y * v.y, z * v.z, w * v.w );
}

inline Vec4 Vec4::div( const float a ) const
{
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	return Vec4( x / a, y / a, z / a, w / a );
}

inline Vec4 Vec4::div( const Vec4& v ) const
{
	magicalMathAssert( !magicalVec4IsZero( TOFLOAT( &v ) ), "division by 0.f" );

	return Vec4( x / v.x, y / v.y, z / v.z, w / v.w );
}

inline void Vec4::addfill( const float a )
{
	x += a;
	y += a;
	z += a;
	w += a;
}

inline void Vec4::addfill( const Vec4& v )
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}

inline void Vec4::subfill( const float a )
{
	x -= a;
	y -= a;
	z -= a;
	w -= a;
}

inline void Vec4::subfill( const Vec4& v )
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}

inline void Vec4::mulfill( const float a )
{
	x *= a;
	y *= a;
	z *= a;
	w *= a;
}

inline void Vec4::mulfill( const Vec4& v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	w *= v.w;
}

inline void Vec4::divfill( const float a )
{
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	x /= a;
	y /= a;
	z /= a;
	w /= a;
}

inline void Vec4::divfill( const Vec4& v )
{
	magicalMathAssert( !magicalVec4IsZero( TOFLOAT( &v ) ), "division by 0.f" );

	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;
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

inline float Vec4::dot( const Vec4& v ) const
{
	return magicalVec4Dot( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline float Vec4::distanceBetween( const Vec4& v ) const
{
	return magicalVec4DistanceBetween( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline float Vec4::distanceBetweenSq( const Vec4& v ) const
{
	return magicalVec4DistanceBetweenSq( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline float Vec4::length( void ) const
{
	return magicalVec4Length( TOFLOAT( this ) );
}

inline float Vec4::lengthSq( void ) const
{
	return magicalVec4LengthSq( TOFLOAT( this ) );
}

inline float Vec4::angleBetween( const Vec4& v ) const
{
	return magicalVec4AngleBetween( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline Vec4 Vec4::clamp( const Vec4& min, const Vec4& max ) const
{
	Vec4 ret;
	magicalVec4Clamp( TOFLOAT( &ret ), TOFLOAT( this ), TOFLOAT( &min ), TOFLOAT( &max ) );
	return ret;
}

inline void Vec4::fillClamp( const Vec4& min, const Vec4& max )
{
	magicalVec4Clamp( TOFLOAT( this ), TOFLOAT( this ), TOFLOAT( &min ), TOFLOAT( &max ) );
}

inline Vec4 Vec4::negate( void ) const
{
	Vec4 ret;
	magicalVec4Negate( TOFLOAT( &ret ), TOFLOAT( this ) );
	return ret;
}

inline void Vec4::fillNegate( void )
{
	magicalVec4Negate( TOFLOAT( this ), TOFLOAT( this ) );
}

inline Vec4 Vec4::normalize( void ) const
{
	Vec4 ret;
	magicalVec4Normalize( TOFLOAT( &ret ), TOFLOAT( this ) );
	return ret;
}

inline void Vec4::fillNormalize( void )
{
	magicalVec4Normalize( TOFLOAT( this ), TOFLOAT( this ) );
}

inline Vec4 Vec4::scale( const float s ) const
{
	Vec4 ret;
	magicalVec4Scale( TOFLOAT( &ret ), TOFLOAT( this ), s );
	return ret;
}

inline void Vec4::fillScale( const float s )
{
	magicalVec4Scale( TOFLOAT( this ), TOFLOAT( this ), s );
}

inline Vec4 Vec4::midPointBetween( const Vec4& point ) const
{
	Vec4 ret;
	magicalVec4MidPointBetween( TOFLOAT( &ret ), TOFLOAT( this ), TOFLOAT( &point ) );
	return ret;
}

inline void Vec4::project( Vec4& h, Vec4& v, const Vec4& n ) const
{
	magicalVec4Project( TOFLOAT( &h ), TOFLOAT( &v ), TOFLOAT( this ), TOFLOAT( &n ) );
}

inline void MathVec4::add( Vec4& out, const Vec4& v, const float a )
{
	magicalVec4AddScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec4::add( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	magicalVec4Add( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec4::sub( Vec4& out, const Vec4& v, const float a )
{
	magicalVec4SubScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec4::sub( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	magicalVec4Sub( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec4::mul( Vec4& out, const Vec4& v, const float a )
{
	magicalVec4MulScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec4::mul( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	magicalVec4Mul( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec4::div( Vec4& out, const Vec4& v, const float a )
{
	magicalVec4DivScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec4::div( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	magicalVec4Div( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec4::clamp( Vec4& out, const Vec4& v, const Vec4& min, const Vec4& max )
{
	magicalVec4Clamp( TOFLOAT( &out ), TOFLOAT( &v ), TOFLOAT( &min ), TOFLOAT( &max ) );
}

inline void MathVec4::negate( Vec4& out, const Vec4& v )
{
	magicalVec4Negate( TOFLOAT( &out ), TOFLOAT( &v ) );
}

inline void MathVec4::normalize( Vec4& out, const Vec4& v )
{
	magicalVec4Normalize( TOFLOAT( &out ), TOFLOAT( &v ) );
}

inline void MathVec4::scale( Vec4& out, const Vec4& v, const float s )
{
	magicalVec4Scale( TOFLOAT( &out ), TOFLOAT( &v ), s );
}

inline void MathVec4::midPointBetween( Vec4& out, const Vec4& v1, const Vec4& v2  )
{
	magicalVec4MidPointBetween( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}