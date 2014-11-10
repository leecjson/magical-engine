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
	return 
		magicalFltEqual( x, v.x ) &&
		magicalFltEqual( y, v.y ) &&
		magicalFltEqual( z, v.z );
}

inline bool Vec3::operator!=( const Vec3& v ) const
{
	return !( operator==( v ) );
}

inline bool Vec3::isEquals( const Vec3& v ) const
{
	return 
		magicalFltEqual( x, v.x ) &&
		magicalFltEqual( y, v.y ) &&
		magicalFltEqual( z, v.z );
}

inline bool Vec3::isZero( void ) const
{
	return 
		magicalFltIsZero( x ) &&
		magicalFltIsZero( y ) &&
		magicalFltIsZero( z );
}

inline bool Vec3::isOne( void ) const
{
	return 
		magicalFltEqual( x, 1.0f ) &&
		magicalFltEqual( y, 1.0f ) &&
		magicalFltEqual( z, 1.0f );
}

inline bool Vec3::isNormalize( void ) const
{
	float n = x * x + y * y + z * z;
	return magicalFltEqual( n, 1.0f );
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
	magicalAssert( !magicalFltIsZero( a ), "division by 0.f" );
	return Vec3( x / a, y / a, z / a );
}

inline Vec3 Vec3::operator/( const Vec3& v ) const
{
	magicalAssert( 
		!magicalFltIsZero( v.x ) &&
		!magicalFltIsZero( v.y ) && 
		!magicalFltIsZero( v.z ), "division by 0.f" );
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
	magicalAssert( !magicalFltIsZero( a ), "division by 0.f" );
	x /= a;
	y /= a;
	z /= a;
	return *this;
}

inline Vec3& Vec3::operator/=( const Vec3& v )
{
	magicalAssert( 
		!magicalFltIsZero( v.x ) &&
		!magicalFltIsZero( v.y ) && 
		!magicalFltIsZero( v.z ), "division by 0.f" );
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
	magicalAssert( !magicalFltIsZero( a ), "division by 0.f" );
	return Vec3( x / a, y / a, z / a );
}

inline Vec3 Vec3::div( const Vec3& v ) const
{
	magicalAssert( 
		!magicalFltIsZero( v.x ) &&
		!magicalFltIsZero( v.y ) && 
		!magicalFltIsZero( v.z ), "division by 0.f" );
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
	magicalAssert( !magicalFltIsZero( a ), "division by 0.f" );
	x /= a;
	y /= a;
	z /= a;
}

inline void Vec3::divfill( const Vec3& v )
{
	magicalAssert( 
		!magicalFltIsZero( v.x ) &&
		!magicalFltIsZero( v.y ) && 
		!magicalFltIsZero( v.z ), "division by 0.f" );
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
	return x * v.x + y * v.y + z * v.z;
}

inline float Vec3::distanceBetween( const Vec3& v ) const
{
	float dx = v.x - x;
	float dy = v.y - y;
	float dz = v.z - z;

	return sqrt( dx * dx + dy * dy + dz * dz );
}

inline float Vec3::distanceBetweenSq( const Vec3& v ) const
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
	return x * x + y * y + z * z;
}

inline float Vec3::angleBetween( const Vec3& v ) const
{
	float dx = y * v.z - z * v.y;
	float dy = z * v.x - x * v.z;
	float dz = x * v.y - y * v.x;

	return atan2f( sqrt( dx * dx + dy * dy + dz * dz ) + FLT_MIN, dot( v ) );
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

inline void Vec3::clamp( const Vec3& min, const Vec3& max )
{
	magicalAssert( !( min.x > max.x || min.y > max.y || min.z > max.z ), "Invaild operate!" );

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

inline void Vec3::negate( void )
{
	x = -x;
    y = -y;
    z = -z;
}

inline void Vec3::normalize( void )
{
	float n = x * x + y * y + z * z;
	if( magicalFltEqual( n, 1.0f ) )
		return;

	n = sqrt( n );
	if( magicalFltIsZero( n ) )
		return;

	n = 1.0f / n;
	x *= n;
	y *= n;
	z *= n;
}

inline Vec3 Vec3::getCross( const Vec3& v ) const
{
	Vec3 ret( *this );
	ret.cross( v );
	return ret;
}

inline Vec3 Vec3::getClamp( const Vec3& min, const Vec3& max ) const
{
	Vec3 ret( *this );
	ret.clamp( min, max );
	return ret;
}

inline Vec3 Vec3::getNegate( void ) const
{
	Vec3 ret( *this );
	ret.negate();
	return ret;
}

inline Vec3 Vec3::getNormalize( void ) const
{
	Vec3 ret( *this );
	ret.normalize();
	return ret;
}

inline void MathVec3::add( Vec3& out, const Vec3& v, float a )
{
	out = v + a;
}

inline void MathVec3::add( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	out = v1 + v2;
}

inline void MathVec3::sub( Vec3& out, const Vec3& v, float a )
{
	out = v - a;
}

inline void MathVec3::sub( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	out = v1 - v2;
}

inline void MathVec3::mul( Vec3& out, const Vec3& v, float a )
{
	out = v * a;
}

inline void MathVec3::mul( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	out = v1 * v2;
}

inline void MathVec3::div( Vec3& out, const Vec3& v, float a )
{
	out = v / a;
}

inline void MathVec3::div( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	out = v1 / v2;
}

inline void MathVec3::cross( Vec3& out, const Vec3& v1, const Vec3& v2 )
{
	out = v1.getCross( v2 );
}

inline void MathVec3::clamp( Vec3& out, const Vec3& v, const Vec3& min, const Vec3& max )
{
	out = v.getClamp( min, max );
}

inline void MathVec3::negate( Vec3& out, const Vec3& v )
{
	out = v.getNegate();
}

inline void MathVec3::normalize( Vec3& out, const Vec3& v )
{
	out = v.getNormalize();
}