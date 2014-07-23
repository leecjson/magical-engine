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
	return kmVec2AreEqual( this, &rhs ) != 0;
}

inline bool Vec2::operator!=( const Vec2& rhs ) const
{
	return kmVec2AreEqual( this, &rhs ) == 0;
}

inline bool Vec2::isZero( void ) const
{
	return x == 0.0f && y == 0.0f;
}

inline Vec2 Vec2::fill( float x, float y )
{
	return Vec2( x, y );
}

inline float Vec2::length( const Vec2& v )
{
	return kmVec2Length( &v );
}

inline float Vec2::lengthSq( const Vec2& v )
{
	return kmVec2LengthSq( &v );
}

inline Vec2 Vec2::normalize( const Vec2& v )
{
	Vec2 result;
	kmVec2Normalize( &result, &v );
	return result;
}

inline Vec2 Vec2::lerp( const Vec2& v1, const Vec2& v2, float t )
{
	Vec2 result;
	kmVec2Lerp( &result, &v1, &v2, t );
	return result;
}

inline float Vec2::dot( const Vec2& v1, const Vec2& v2 )
{
	return kmVec2Dot( &v1, &v2 );
}

inline float Vec2::cross( const Vec2& v1, const Vec2& v2 )
{
	return kmVec2Cross( &v1, &v2 );
}

inline Vec2 Vec2::transform( const Vec2& v, const Mat3& m )
{
	Vec2 result;
	kmVec2Transform( &result, &v, &m );
	return result;
}

inline Vec2 Vec2::transformCoord( const Vec2& v, const Mat3& m )
{
	Vec2 result;
	kmVec2TransformCoord( &result, &v, &m );
	return result;
}

inline Vec2 Vec2::scale( const Vec2& v, const float s )
{
	Vec2 result;
	kmVec2Scale( &result, &v, s );
	return result;
}

inline Vec2 Vec2::rotateBy( const Vec2& v, const float degrees, const Vec2& center )
{
	Vec2 result;
	kmVec2RotateBy( &result, &v, degrees, &center );
	return result;
}

inline float Vec2::degreesBetween( const Vec2& v1, const Vec2& v2 )
{
	return kmVec2DegreesBetween( &v1, &v2 );
}

inline float Vec2::distanceBetween( const Vec2& v1, const Vec2& v2 )
{
	return kmVec2DistanceBetween( &v1, &v2 );
}

inline Vec2 Vec2::midPointBetween( const Vec2& v1, const Vec2& v2 )
{
	Vec2 result;
	kmVec2MidPointBetween( &result, &v1, &v2 );
	return result;
}

static inline Vec2 operator*( const float lhs, const Vec2& rhs )
{
	return rhs * lhs;
}

static inline Vec2 operator*( const kmMat3& lhs, const Vec2& rhs )
{
	Vec2 result;
	kmVec2Transform( &result, &rhs, &lhs );
	return result;
};