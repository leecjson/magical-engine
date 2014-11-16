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
	return magicalVec2Equals( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline bool Vec2::operator!=( const Vec2& v ) const
{
	return !magicalVec2Equals( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline bool Vec2::isEquals( const Vec2& v ) const
{
	return magicalVec2Equals( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline bool Vec2::isZero( void ) const
{
	return magicalVec2IsZero( TOFLOAT( this ) );
}

inline bool Vec2::isOne( void ) const
{
	return magicalVec2IsOne( TOFLOAT( this ) );
}

inline bool Vec2::isNormalize( void ) const
{
	return magicalVec2IsNormalize( TOFLOAT( this ) );
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
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	return Vec2( x / a, y / a );
}

inline Vec2 Vec2::operator/( const Vec2& v ) const
{
	magicalMathAssert( !magicalFltIsZero( v.x ) && !magicalFltIsZero( v.y ), "division by 0.f" );

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
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	x /= a;
	y /= a;
	return *this;
}

inline Vec2& Vec2::operator/=( const Vec2& v )
{
	magicalMathAssert( !magicalFltIsZero( v.x ) && !magicalFltIsZero( v.y ), "division by 0.f" );

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
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	return Vec2( x / a, y / a );
}

inline Vec2 Vec2::div( const Vec2& v ) const
{
	magicalMathAssert( !magicalFltIsZero( v.x ) && !magicalFltIsZero( v.y ), "division by 0.f" );

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
	magicalMathAssert( !magicalFltIsZero( a ), "division by 0.f" );

	x /= a;
	y /= a;
}

inline void Vec2::divfill( const Vec2& v )
{
	magicalMathAssert( !magicalFltIsZero( v.x ) && !magicalFltIsZero( v.y ), "division by 0.f" );

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
	return magicalVec2Dot( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline float Vec2::distanceBetween( const Vec2& v ) const
{
	return magicalVec2DistanceBetween( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline float Vec2::distanceBetweenSq( const Vec2& v ) const
{
	return magicalVec2DistanceBetweenSq( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline float Vec2::length( void ) const
{
	return magicalVec2Length( TOFLOAT( this ) );
}

inline float Vec2::lengthSq( void ) const
{
	return magicalVec2LengthSq( TOFLOAT( this ) );
}

inline float Vec2::angleBetween( const Vec2& v ) const
{
	return magicalVec2AngleBetween( TOFLOAT( this ), TOFLOAT( &v ) );
}

inline Vec2 Vec2::clamp( const Vec2& min, const Vec2& max ) const
{
	Vec2 ret;
	magicalVec2Clamp( TOFLOAT( &ret ), TOFLOAT( this ), TOFLOAT( &min ), TOFLOAT( &max ) );
	return ret;
}

inline void Vec2::fillClamp( const Vec2& min, const Vec2& max )
{
	magicalVec2Clamp( TOFLOAT( this ), TOFLOAT( this ), TOFLOAT( &min ), TOFLOAT( &max ) );
}

inline Vec2 Vec2::negate( void ) const
{
	Vec2 ret;
	magicalVec2Negate( TOFLOAT( &ret ), TOFLOAT( this ) );
	return ret;
}

inline void Vec2::fillNegate( void )
{
	magicalVec2Negate( TOFLOAT( this ), TOFLOAT( this ) );
}

inline Vec2 Vec2::normalize( void ) const
{
	Vec2 ret;
	magicalVec2Normalize( TOFLOAT( &ret ), TOFLOAT( this ) );
	return ret;
}

inline void Vec2::fillNormalize( void )
{
	magicalVec2Normalize( TOFLOAT( this ), TOFLOAT( this ) );
}

inline Vec2 Vec2::rotate( const Vec2& point, float angle ) const
{
	Vec2 ret;
	magicalVec2Rotate( TOFLOAT( &ret ), TOFLOAT( this ), TOFLOAT( &point ), angle );
	return ret;
}

inline void Vec2::fillRotate( const Vec2& point, float angle )
{
	magicalVec2Rotate( TOFLOAT( this ), TOFLOAT( this ), TOFLOAT( &point ), angle );
}

inline Vec2 Vec2::scale( float s ) const
{
	Vec2 ret;
	magicalVec2Scale( TOFLOAT( &ret ), TOFLOAT( this ), s );
	return ret;
}

inline void Vec2::fillScale( float s )
{
	magicalVec2Scale( TOFLOAT( this ), TOFLOAT( this ), s );
}

inline Vec2 Vec2::midPointBetween( const Vec2& point ) const
{
	Vec2 ret;
	magicalVec2MidPointBetween( TOFLOAT( &ret ), TOFLOAT( this ), TOFLOAT( &point ) );
	return ret;
}

inline void Vec2::project( Vec2& h, Vec2& v, const Vec2& n ) const
{
	magicalVec2Project( TOFLOAT( &h ), TOFLOAT( &v ), TOFLOAT( this ), TOFLOAT( &n ) );
}

inline void MathVec2::add( Vec2& out, const Vec2& v, float a )
{
	magicalVec2AddScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec2::add( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	magicalVec2Add( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec2::sub( Vec2& out, const Vec2& v, float a )
{
	magicalVec2SubScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec2::sub( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	magicalVec2Sub( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec2::mul( Vec2& out, const Vec2& v, float a )
{
	magicalVec2MulScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec2::mul( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	magicalVec2Mul( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec2::div( Vec2& out, const Vec2& v, float a )
{
	magicalVec2DivScalar( TOFLOAT( &out ), TOFLOAT( &v ), a );
}

inline void MathVec2::div( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	magicalVec2Div( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}

inline void MathVec2::clamp( Vec2& out, const Vec2& v, const Vec2& min, const Vec2& max )
{
	magicalVec2Clamp( TOFLOAT( &out ), TOFLOAT( &v ), TOFLOAT( &min ), TOFLOAT( &max ) );
}

inline void MathVec2::negate( Vec2& out, const Vec2& v )
{
	magicalVec2Negate( TOFLOAT( &out ), TOFLOAT( &v ) );
}

inline void MathVec2::normalize( Vec2& out, const Vec2& v )
{
	magicalVec2Normalize( TOFLOAT( &out ), TOFLOAT( &v ) );
}

inline void MathVec2::rotate( Vec2& out, const Vec2& v, const Vec2& point, float angle )
{
	magicalVec2Rotate( TOFLOAT( &out ), TOFLOAT( &v ), TOFLOAT( &point ), angle );
}

inline void MathVec2::scale( Vec2& out, const Vec2& v, float s )
{
	magicalVec2Scale( TOFLOAT( &out ), TOFLOAT( &v ), s );
}

inline void MathVec2::midPointBetween( Vec2& out, const Vec2& v1, const Vec2& v2 )
{
	magicalVec2MidPointBetween( TOFLOAT( &out ), TOFLOAT( &v1 ), TOFLOAT( &v2 ) );
}