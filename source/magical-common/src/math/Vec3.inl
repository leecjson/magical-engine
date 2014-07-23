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

inline Vec3 Vec3::operator+( float rhs ) const
{
	return Vec3( x + rhs, y + rhs, z + rhs );
}

inline Vec3 Vec3::operator+( const Vec3& rhs ) const
{
	return Vec3( x + rhs.x, y + rhs.y, z + rhs.z );
}

inline Vec3 Vec3::operator-( float rhs ) const
{
	return Vec3( x - rhs, y - rhs, z - rhs );
}

inline Vec3 Vec3::operator-( const Vec3& rhs ) const
{
	return Vec3( x - rhs.x, y - rhs.y, z - rhs.z );
}

inline Vec3 Vec3::operator*( float rhs ) const
{
	return Vec3( x * rhs, y * rhs, z * rhs );
}

inline Vec3 Vec3::operator*( const Vec3& rhs ) const
{
	return Vec3( x * rhs.x, y * rhs.y, z * rhs.z );
}

inline Vec3 Vec3::operator/( float rhs ) const
{
	magicalAssert( rhs, "division by 0.f" );
	return Vec3( x / rhs, y / rhs, z / rhs );
}

inline Vec3 Vec3::operator/( const Vec3& rhs ) const
{
	magicalAssert( rhs.x && rhs.y && rhs.z, "division by 0.f" );
	return Vec3( x / rhs.x, y / rhs.y, z / rhs.z );
}

inline Vec3& Vec3::operator+=( const Vec3& rhs )
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

inline Vec3& Vec3::operator+=( float rhs )
{
	x += rhs;
	y += rhs;
	z += rhs;
	return *this;
}

inline Vec3& Vec3::operator-=( const Vec3& rhs )
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

inline Vec3& Vec3::operator-=( float rhs )
{
	x -= rhs;
	y -= rhs;
	z -= rhs;
	return *this;
}

inline Vec3& Vec3::operator*=( const Vec3& rhs )
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

inline Vec3& Vec3::operator*=( float rhs )
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

inline Vec3& Vec3::operator/=( const Vec3& rhs )
{
	magicalAssert( rhs.x && rhs.y && rhs.z, "division by 0.f" );
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	return *this;
}

inline Vec3& Vec3::operator/=( float rhs )
{
	magicalAssert( rhs, "division by 0.f" );
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

inline bool Vec3::operator==( const Vec3& rhs )
{
	return kmVec3AreEqual( this, &rhs ) != 0;
}

inline bool Vec3::operator!=( const Vec3& rhs )
{
	return kmVec3AreEqual( this, &rhs ) == 0;
}

inline bool Vec3::isZero( void )
{
	return x == 0.0f && y == 0.0f && z == 0.0f;
}

inline Vec3 Vec3::fill( float x, float y, float z )
{
	Vec3 result;
	kmVec3Fill( &result, x, y, z );
	return result;
}

inline float Vec3::length( const Vec3& v )
{
	return kmVec3Length( &v );
}

inline float Vec3::lengthSq( const Vec3& v )
{
	return kmVec3LengthSq( &v );
}

inline Vec3 Vec3::lerp( const Vec3& v1, const Vec3& v2, const float t )
{
	Vec3 result;
	kmVec3Lerp( &result, &v1, &v2, t );
	return result;
}

inline Vec3 Vec3::normalize( const Vec3& v )
{
	Vec3 result;
	kmVec3Normalize( &result, &v );
	return result;
}

inline Vec3 Vec3::cross( const Vec3& v1, const Vec3& v2 )
{
	Vec3 result;
	kmVec3Cross( &result, &v1, &v2 );
	return result;
}

inline float Vec3::dot( const Vec3& v1, const Vec3& v2 )
{
	return kmVec3Dot( &v1, &v2 );
}

inline Vec3 Vec3::multiplyMat3( const Vec3& v, const Mat3& m )
{
	Vec3 result;
	kmVec3MultiplyMat3( &result, &v, &m );
	return result;
}

inline Vec3 Vec3::multiplyMat4( const Vec3& v, const Mat4& m )
{
	Vec3 result;
	kmVec3MultiplyMat4( &result, &v, &m );
	return result;
}

inline Vec3 Vec3::transform( const Vec3& v, const Mat4& m )
{
	Vec3 result;
	kmVec3Transform( &result, &v, &m );
	return result;
}

inline Vec3 Vec3::transformNormal( const Vec3& v, const Mat4& m )
{
	Vec3 result;
	kmVec3TransformNormal( &result, &v, &m );
	return result;
}

inline Vec3 Vec3::transformCoord( const Vec3& v, const Mat4& m )
{
	Vec3 result;
	kmVec3TransformCoord( &result, &v, &m );
	return result;
}

inline Vec3 Vec3::scale( const Vec3& v, const float s )
{
	Vec3 result;
	kmVec3Scale( &result, &v, s );
	return result;
}

inline Vec3 Vec3::inverseTransform( const Vec3& v, const Mat4& m )
{
	Vec3 result;
	kmVec3InverseTransform( &result, &v, &m );
	return result;
}

inline Vec3 Vec3::inverseTransformNormal( const Vec3& v, const Mat4& m )
{
	Vec3 result;
	kmVec3InverseTransformNormal( &result, &v, &m );
	return result;
}

inline Vec3 Vec3::getHorizontalAngle( const Vec3& v )
{
	Vec3 result;
	kmVec3GetHorizontalAngle( &result, &v );
	return result;
}

inline Vec3 Vec3::rotationToDirection( const Vec3& v, const Vec3& forwards )
{
	Vec3 result;
	kmVec3RotationToDirection( &result, &v, &forwards );
	return result;
}

static inline Vec3 operator*( const float lhs, const Vec3& rhs )
{
	return rhs * lhs;
}