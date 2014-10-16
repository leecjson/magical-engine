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
	magicalAssert( !magicalFloatIsZero( rhs ), "division by 0.f" );
	return Vec4( x / rhs, y / rhs, z / rhs, w / rhs );
}

inline Vec4 Vec4::operator/( const Vec4& rhs ) const
{
	magicalAssert( 
		!magicalFloatIsZero( rhs.x ) &&
		!magicalFloatIsZero( rhs.y ) &&
		!magicalFloatIsZero( rhs.z ) &&
		!magicalFloatIsZero( rhs.w ), "division by 0.f" );
	return Vec4( x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w );
}

inline Vec4& Vec4::operator=( const Vec4& rhs )
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;
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
	magicalAssert( 
		!magicalFloatIsZero( rhs.x ) &&
		!magicalFloatIsZero( rhs.y ) &&
		!magicalFloatIsZero( rhs.z ) &&
		!magicalFloatIsZero( rhs.w ), "division by 0.f" );
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	w /= rhs.w;
	return *this;
}

inline Vec4& Vec4::operator/=( float rhs )
{
	magicalAssert( !magicalFloatIsZero( rhs ), "division by 0.f" );
	x /= rhs;
	y /= rhs;
	z /= rhs;
	w /= rhs;
	return *this;
}

inline bool Vec4::operator==( const Vec4& rhs ) const
{
	return 
		magicalFloatEquals( x, rhs.x ) &&
		magicalFloatEquals( y, rhs.y ) &&
		magicalFloatEquals( z, rhs.z ) &&
		magicalFloatEquals( w, rhs.w );
}

inline bool Vec4::operator!=( const Vec4& rhs ) const
{
	return !( operator==( rhs ) );
}

inline bool Vec4::isZero( void ) const
{
	return 
		magicalFloatIsZero( x ) &&
		magicalFloatIsZero( y ) &&
		magicalFloatIsZero( z ) &&
		magicalFloatIsZero( w );
}

inline bool Vec4::isOne( void ) const
{
	return 
		magicalFloatEquals( x, 1.0f ) &&
		magicalFloatEquals( y, 1.0f ) &&
		magicalFloatEquals( z, 1.0f ) &&
		magicalFloatEquals( w, 1.0f );
}

inline void Vec4::fill( float rx, float ry, float rz, float rw )
{
	x = rx;
	y = ry;
	z = rz;
	w = rw;
}

inline void Vec4::fill( const float* rhs )
{
	x = rhs[0];
	y = rhs[1];
	z = rhs[2];
	w = rhs[3];
}

inline void Vec4::fill( const Vec4& rhs )
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;
}

inline void Vec4::fillZero( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

inline Vec4 Vec4::copy( void ) const
{
	return *this;
}

inline float Vec4::angle( const Vec4& rhs ) const
{
	float dx = w * rhs.x - x * rhs.w - y * rhs.z + z * rhs.y;
	float dy = w * rhs.y - y * rhs.w - z * rhs.x + x * rhs.z;
	float dz = w * rhs.z - z * rhs.w - x * rhs.y + y * rhs.x;

	return atan2f( sqrt( dx * dx + dy * dy + dz * dz ) + MATH_FLOAT_SMALL, dot( rhs ) );
}

inline void Vec4::clamp( const Vec4& min, const Vec4& max )
{
	magicalAssert( !( min.x > max.x || min.y > max.y || min.z > max.z || min.w > max.w ), "" );

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

	if( w < min.w )
		w = min.w;
	if( w > max.w )
		w = max.w;
}

inline float Vec4::dot( const Vec4& v ) const
{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}

inline float Vec4::distance( const Vec4& v ) const
{
	float dx = v.x - x;
	float dy = v.y - y;
	float dz = v.z - z;
	float dw = v.w - w;

	return sqrt( dx * dx + dy * dy + dz * dz + dw * dw );
}

inline float Vec4::distanceSq( const Vec4& v ) const
{
	float dx = v.x - x;
	float dy = v.y - y;
	float dz = v.z - z;
	float dw = v.w - w;

	return ( dx * dx + dy * dy + dz * dz + dw * dw );
}

inline float Vec4::length( void ) const
{
	return sqrt( x * x + y * y + z * z + w * w );
}

inline float Vec4::lengthSq( void ) const
{
	return ( x * x + y * y + z * z + w * w );
}

inline void Vec4::negate( void )
{
	x = -x;
    y = -y;
    z = -z;
    w = -w;
}

inline void Vec4::normalize( void )
{
	float n = x * x + y * y + z * z + w * w;
	// Already normalized.
	if( magicalFloatEquals( n, 1.0f ) )
		return;

	n = sqrt( n );
	// Too close to zero.
	if( n < FLT_EPSILON )
		return;

	n = 1.0f / n;
	x *= n;
	y *= n;
	z *= n;
	w *= n;
}


inline Vec4 MathVec4::add( const Vec4& lhs, float rhs )
{
	return lhs + rhs;
}

inline Vec4 MathVec4::add( const Vec4& lhs, const Vec4& rhs )
{
	return lhs + rhs;
}

inline Vec4 MathVec4::sub( const Vec4& lhs, float rhs )
{
	return lhs - rhs;
}

inline Vec4 MathVec4::sub( const Vec4& lhs, const Vec4& rhs )
{
	return lhs - rhs;
}

inline Vec4 MathVec4::mul( const Vec4& lhs, float rhs )
{
	return lhs * rhs;
}

inline Vec4 MathVec4::mul( const Vec4& lhs, const Vec4& rhs )
{
	return lhs * rhs;
}

inline Vec4 MathVec4::div( const Vec4& lhs, float rhs )
{
	return lhs / rhs;
}

inline Vec4 MathVec4::div( const Vec4& lhs, const Vec4& rhs )
{
	return lhs / rhs;
}

inline bool MathVec4::equals( const Vec4& v1, const Vec4& v2 )
{
	return v1 == v2;
}

inline bool MathVec4::isZero( const Vec4& v )
{
	return v.isZero();
}

inline bool MathVec4::isOne( const Vec4& v )
{
	return v.isOne();
}

inline Vec4 MathVec4::copy( const Vec4& v )
{
	return v;
}

inline Vec4 MathVec4::fill( float rx, float ry, float rz, float rw )
{
	return Vec4( rx, ry, rz, rw );
}

inline Vec4 MathVec4::fill( const Vec4& rhs )
{
	return Vec4( rhs );
}

inline Vec4 MathVec4::fillZero( void )
{
	return Vec4::ZERO;
}

inline Vec4 MathVec4::fillOne( void )
{
	return Vec4::ONE;
}

inline Vec4 MathVec4::negate( const Vec4& v )
{
	Vec4 ret( v );
	ret.negate();
	return ret;
}

inline Vec4 MathVec4::normalize( const Vec4& v )
{
	Vec4 ret( v );
	ret.normalize();
	return ret;
}

inline Vec4 MathVec4::clamp( const Vec4& v, const Vec4& min, const Vec4& max )
{
	Vec4 ret( v );
	ret.clamp( min, max );
	return ret;
}

inline float MathVec4::angle( const Vec4& v, const Vec4& rhs )
{
	return v.angle( rhs );
}

inline float MathVec4::dot( const Vec4& v1, const Vec4& v2 )
{
	return v1.dot( v2 );
}

inline float MathVec4::distance( const Vec4& v1, const Vec4& v2 )
{
	return v1.distance( v2 );
}

inline float MathVec4::distanceSq( const Vec4& v1, const Vec4& v2 )
{
	return v1.distanceSq( v2 );
}

inline float MathVec4::length( const Vec4& v )
{
	return v.length();
}

inline float MathVec4::lengthSq( const Vec4& v )
{
	return v.lengthSq();
}