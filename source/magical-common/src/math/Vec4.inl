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

inline Vec4 Vec4::operator+( float rhs ) const
{
	return Vec4( x + rhs, y + rhs, z + rhs, w + rhs );
}

inline Vec4 Vec4::operator+( const Vec4& rhs ) const
{
	return Vec4( x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w );
}

inline Vec4 Vec4::operator-( float rhs ) const
{
	return Vec4( x - rhs, y - rhs, z - rhs, w - rhs );
}

inline Vec4 Vec4::operator-( const Vec4& rhs ) const
{
	return Vec4( x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w );
}

inline Vec4 Vec4::operator*( float rhs ) const
{
	return Vec4( x * rhs, y * rhs, z * rhs, w * rhs );
}

inline Vec4 Vec4::operator*( const Vec4& rhs ) const
{
	return Vec4( x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w );
}

inline Vec4 Vec4::operator/( float rhs ) const
{
	magicalAssert( rhs, "division by 0.f" );
	return Vec4( x / rhs, y / rhs, z / rhs, w / rhs );
}

inline Vec4 Vec4::operator/( const Vec4& rhs ) const
{
	magicalAssert( rhs.x && rhs.y && rhs.z && rhs.w, "division by 0.f" );
	return Vec4( x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w );
}

inline Vec4& Vec4::operator+=( const Vec4& rhs )
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}

inline Vec4& Vec4::operator+=( float rhs )
{
	x += rhs;
	y += rhs;
	z += rhs;
	w += rhs;
	return *this;
}

inline Vec4& Vec4::operator-=( const Vec4& rhs )
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return *this;
}

inline Vec4& Vec4::operator-=( float rhs )
{
	x -= rhs;
	y -= rhs;
	z -= rhs;
	w -= rhs;
	return *this;
}

inline Vec4& Vec4::operator*=( const Vec4& rhs )
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;
	return *this;
}

inline Vec4& Vec4::operator*=( float rhs )
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	w *= rhs;
	return *this;
}

inline Vec4& Vec4::operator/=( const Vec4& rhs )
{
	magicalAssert( rhs.x && rhs.y && rhs.z && rhs.w, "division by 0.f" );
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	w /= rhs.w;
	return *this;
}

inline Vec4& Vec4::operator/=( float rhs )
{
	magicalAssert( rhs, "division by 0.f" );
	x /= rhs;
	y /= rhs;
	z /= rhs;
	w /= rhs;
	return *this;
}

inline bool Vec4::operator==( const Vec4& rhs ) const
{
	return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}

inline bool Vec4::operator!=( const Vec4& rhs ) const
{
	return x != rhs.x || y != rhs.y || z != rhs.z || w != rhs.w;
}

inline bool Vec4::isZero( void ) const
{
	return x == 0.0f && y == 0.0f && z == 0.0f && w == 0.0f;
}

inline Vec4 Vec4::fill( float x, float y, float z, float w )
{
	return Vec4( x, y, z, w );
}

inline float Vec4::dot( const Vec4& v1, const Vec4& v2 )
{
	return kmVec4Dot( &v1, &v2 );
}

inline float Vec4::length( const Vec4& v )
{
	return kmVec4Length( &v );
}

inline float Vec4::lengthSq( const Vec4& v )
{
	return kmVec4LengthSq( &v );
}

inline Vec4 Vec4::lerp( const Vec4& v1, const Vec4& v2, const float t )
{
	Vec4 result;
	kmVec4Lerp( &result, &v1, &v2, t );
	return result;
}

inline Vec4 Vec4::normalize( const Vec4& v )
{
	Vec4 result;
	kmVec4Normalize( &result, &v );
	return result;
}

inline Vec4 Vec4::scale( const Vec4& v, const float s )
{
	Vec4 result;
	kmVec4Scale( &result, &v, s );
	return result;
}

inline Vec4 Vec4::multiplyMat4( const Vec4& v, const Mat4& m )
{
	Vec4 result;
	kmVec4MultiplyMat4( &result, &v, &m );
	return result;
}

const Vec4 Vec4::transform( const Vec4& v, const Mat4& m )
{
	Vec4 result;
	kmVec4Transform( &result, &v, &m );
	return result;
}

static inline Vec4 operator*( const float lhs, const Vec4& rhs )
{
	return rhs * lhs;
}