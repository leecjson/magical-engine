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

inline Vec3& Vec3::operator=( const Vec3& rhs )
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
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

inline bool Vec3::operator==( const Vec3& rhs ) const
{
	return x == rhs.x && y == rhs.y && z == rhs.z;
}

inline bool Vec3::operator!=( const Vec3& rhs ) const
{
	return x != rhs.x || y != rhs.y || z != rhs.z;
}

inline bool Vec3::isZero( void ) const
{
	return x == 0.0f && y == 0.0f && z == 0.0f;
}

inline void Vec3::fill( float rx, float ry, float rz )
{
	x = rx;
	y = ry;
	z = rz;
}

inline void Vec3::fill( const Vec3& rhs )
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
}

inline void Vec3::fill( const float* rhs )
{
	magicalAssert( rhs, "should not be nullptr" );

	x = rhs[0];
	y = rhs[1];
	z = rhs[2];
}

inline void Vec3::fillZero( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

inline Vec3 Vec3::copy( void ) const
{
	return Vec3( *this );
}

inline void Vec3::clamp( const Vec3& min, const Vec3& max )
{
	magicalAssert( !(min.x > max.x || min.y > max.y || min.z > max.z), "Invaild operate!" );

	if( x < min.x )
		x = min.x;
	if( x > max.x )
		x = max.x;

	if( y < min.y )
		y = min.y;
	if( y > max.y )
		y = max.y;

	if( z < min.z )
		z = min.z;
	if( z > max.z )
		z = max.z;
}

inline void Vec3::cross( const Vec3& v )
{
	float rx = ( y * v.z ) - ( z * v.y );
	float ry = ( z * v.x ) - ( x * v.z );
	float rz = ( x * v.y ) - ( y * v.x );

	x = rx;
	y = ry;
	z = rz;
}

inline void Vec3::negate( void )
{
	x = -x;
    y = -y;
    z = -z;
}

inline void Vec3::normalize( void )
{
	float n = x * x + y * y + z * z;
	// already normalized.
	if( n == 1.0f )
		return;

	n = sqrt( n );
	// too close to zero.
	if( n < MATH_TOLERANCE )
		return;

	n = 1.0f / n;
	x *= n;
	y *= n;
	z *= n;
}

inline void Vec3::scale( float scalar )
{
	x *= scalar;
    y *= scalar;
    z *= scalar;
}

inline float Vec3::angle( const Vec3& v ) const
{
	float dx = y * v.z - z * v.y;
	float dy = z * v.x - x * v.z;
	float dz = x * v.y - y * v.x;

	return atan2f( sqrt(dx * dx + dy * dy + dz * dz) + MATH_FLOAT_SMALL, Mathv3::dot(*this, v) );
}
	
inline float Vec3::dot( const Vec3& v ) const
{
	return x * v.x + y * v.y + z * v.z;
}

inline float Vec3::distance( const Vec3& v ) const
{
	float dx = v.x - x;
	float dy = v.y - y;
	float dz = v.z - z;

	return sqrt( dx * dx + dy * dy + dz * dz );
}

inline float Vec3::distanceSq( const Vec3& v ) const
{
	float dx = v.x - x;
    float dy = v.y - y;
    float dz = v.z - z;

    return dx * dx + dy * dy + dz * dz;
}

inline float Vec3::length( void ) const
{
	return sqrt( x * x + y * y + z * z );
}

inline float Vec3::lengthSq( void ) const
{
	return ( x * x + y * y + z * z );
}


inline Vec3 Mathv3::add( const Vec3& v1, const Vec3& v2 )
{
	return v1 + v2;
}

inline Vec3 Mathv3::add( const Vec3& v1, float rhs )
{
	return v1 + rhs;
}

inline Vec3 Mathv3::sub( const Vec3& v1, const Vec3& v2 )
{
	return v1 - v2;
}

inline Vec3 Mathv3::sub( const Vec3& v1, float rhs )
{
	return v1 - rhs;
}

inline Vec3 Mathv3::mul( const Vec3& v1, const Vec3& v2 )
{
	return v1 * v2;
}

inline Vec3 Mathv3::mul( const Vec3& v1, float rhs )
{
	return v1 * rhs;
}

inline Vec3 Mathv3::div( const Vec3& v1, const Vec3& v2 )
{
	return v1 / v2;
}

inline Vec3 Mathv3::div( const Vec3& v1, float rhs )
{
	return v1 / rhs;
}

inline bool Mathv3::equals( const Vec3& v1, const Vec3& v2 )
{
	return v1 == v2;
}

inline Vec3 Mathv3::fill( float rx, float ry, float rz )
{
	return Vec3( rx, ry, rz );
}

inline Vec3 Mathv3::fill( const Vec3& rhs )
{
	return Vec3( rhs );
}

inline Vec3 Mathv3::fill( const float* rhs )
{
	return Vec3( rhs );
}

inline Vec3 Mathv3::fillZero( void )
{
	return Vec3( 0.0f, 0.0f, 0.0f );
}

inline Vec3 Mathv3::copy( const Vec3 rhs )
{
	return Vec3( rhs );
}

inline Vec3 Mathv3::clamp( const Vec3& v, const Vec3& min, const Vec3& max )
{
	Vec3 ret = v;
	ret.clamp( min, max );
	return ret;
}

inline Vec3 Mathv3::cross( const Vec3& v1, const Vec3& v2 )
{
	Vec3 ret = v1;
	ret.cross( v2 );
	return ret;
}

inline Vec3 Mathv3::negate( const Vec3& v )
{
	Vec3 ret = v;
	ret.negate();
	return ret;
}

inline Vec3 Mathv3::normalize( const Vec3& v )
{
	Vec3 ret = v;
	ret.normalize();
	return ret;
}

inline Vec3 Mathv3::scale( const Vec3& v, float scalar )
{
	Vec3 ret = v;
	ret.scale( scalar );
	return ret;
}

inline float Mathv3::angle( const Vec3& v1, const Vec3& v2 )
{
	return v1.angle( v2 );
}

inline float Mathv3::dot( const Vec3& v1, const Vec3& v2 )
{
	return v1.dot( v2 );
}

inline float Mathv3::distance( const Vec3& v1, const Vec3& v2 )
{
	return v1.distance( v2 );
}

inline float Mathv3::distanceSq( const Vec3& v1, const Vec3& v2 )
{
	return v1.distanceSq( v2 );
}

inline float Mathv3::length( const Vec3& v )
{
	return v.length();
}

inline float Mathv3::lengthSq( const Vec3& v )
{
	return v.length();
}
