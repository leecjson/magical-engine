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
	return 
		magicalFltEqual( x, v.x ) &&
		magicalFltEqual( y, v.y ) &&
		magicalFltEqual( z, v.z ) &&
		magicalFltEqual( w, v.w );
}

inline bool Vec4::operator!=( const Vec4& v ) const
{
	return !( operator==( v ) );
}

inline bool Vec4::isEquals( const Vec4& v ) const
{
	return 
		magicalFltEqual( x, v.x ) &&
		magicalFltEqual( y, v.y ) &&
		magicalFltEqual( z, v.z ) &&
		magicalFltEqual( w, v.w );
}

inline bool Vec4::isZero( void ) const
{
	return 
		magicalFltIsZero( x ) &&
		magicalFltIsZero( y ) &&
		magicalFltIsZero( z ) &&
		magicalFltIsZero( w );
}

inline bool Vec4::isOne( void ) const
{
	return 
		magicalFltEqual( x, 1.0f ) &&
		magicalFltEqual( y, 1.0f ) &&
		magicalFltEqual( z, 1.0f ) &&
		magicalFltEqual( w, 1.0f );
}

inline bool Vec4::isNormalize( void ) const
{
	float n = x * x + y * y + z * z + w * w;
	return magicalFltEqual( n, 1.0f );
}

inline Vec4 Vec4::operator+( float a ) const
{
	return Vec4( x + a, y + a, z + a, w + a );
}

inline Vec4 Vec4::operator+( const Vec4& v ) const
{
	return Vec4( x + v.x, y + v.y, z + v.z, w + v.w );
}

inline Vec4 Vec4::operator-( float a ) const
{
	return Vec4( x - a, y - a, z - a, w - a );
}

inline Vec4 Vec4::operator-( const Vec4& v ) const
{
	return Vec4( x - v.x, y - v.y, z - v.z, w - v.w );
}

inline Vec4 Vec4::operator*( float a ) const
{
	return Vec4( x * a, y * a, z * a, w * a );
}

inline Vec4 Vec4::operator*( const Vec4& v ) const
{
	return Vec4( x * v.x, y * v.y, z * v.z, w * v.w );
}

inline Vec4 Vec4::operator/( float a ) const
{
	magicalAssert( !magicalFltIsZero( a ), "division by 0.f" );
	return Vec4( x / a, y / a, z / a, w / a );
}

inline Vec4 Vec4::operator/( const Vec4& v ) const
{
	magicalAssert( 
		!magicalFltIsZero( v.x ) &&
		!magicalFltIsZero( v.y ) &&
		!magicalFltIsZero( v.z ) &&
		!magicalFltIsZero( v.w ), "division by 0.f" );
	return Vec4( x / v.x, y / v.y, z / v.z, w / v.w );
}

inline Vec4& Vec4::operator+=( float a )
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

inline Vec4& Vec4::operator-=( float a )
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

inline Vec4& Vec4::operator*=( float a )
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

inline Vec4& Vec4::operator/=( float a )
{
	magicalAssert( !magicalFltIsZero( a ), "division by 0.f" );
	x /= a;
	y /= a;
	z /= a;
	w /= a;
	return *this;
}

inline Vec4& Vec4::operator/=( const Vec4& v )
{
	magicalAssert( 
		!magicalFltIsZero( v.x ) &&
		!magicalFltIsZero( v.y ) &&
		!magicalFltIsZero( v.z ) &&
		!magicalFltIsZero( v.w ), "division by 0.f" );
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

inline Vec4 Vec4::add( float a ) const
{
	return Vec4( x + a, y + a, z + a, w + a );
}

inline Vec4 Vec4::add( const Vec4& v ) const
{
	return Vec4( x + v.x, y + v.y, z + v.z, w + v.w );
}

inline Vec4 Vec4::sub( float a ) const
{
	return Vec4( x - a, y - a, z - a, w - a );
}

inline Vec4 Vec4::sub( const Vec4& v ) const
{
	return Vec4( x - v.x, y - v.y, z - v.z, w - v.w );
}

inline Vec4 Vec4::mul( float a ) const
{
	return Vec4( x * a, y * a, z * a, w * a );
}

inline Vec4 Vec4::mul( const Vec4& v ) const
{
	return Vec4( x * v.x, y * v.y, z * v.z, w * v.w );
}

inline Vec4 Vec4::div( float a ) const
{
	magicalAssert( !magicalFltIsZero( a ), "division by 0.f" );
	return Vec4( x / a, y / a, z / a, w / a );
}

inline Vec4 Vec4::div( const Vec4& v ) const
{
	magicalAssert( 
		!magicalFltIsZero( v.x ) &&
		!magicalFltIsZero( v.y ) &&
		!magicalFltIsZero( v.z ) &&
		!magicalFltIsZero( v.w ), "division by 0.f" );
	return Vec4( x / v.x, y / v.y, z / v.z, w / v.w );
}

inline void Vec4::addfill( float a )
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

inline void Vec4::subfill( float a )
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

inline void Vec4::mulfill( float a )
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

inline void Vec4::divfill( float a )
{
	magicalAssert( !magicalFltIsZero( a ), "division by 0.f" );
	x /= a;
	y /= a;
	z /= a;
	w /= a;
}

inline void Vec4::divfill( const Vec4& v )
{
	magicalAssert( 
		!magicalFltIsZero( v.x ) &&
		!magicalFltIsZero( v.y ) &&
		!magicalFltIsZero( v.z ) &&
		!magicalFltIsZero( v.w ), "division by 0.f" );
	x /= v.x;
	y /= v.y;
	z /= v.z;
	w /= v.w;
}

inline void Vec4::fill( float x, float y, float z, float w )
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

	return dx * dx + dy * dy + dz * dz + dw * dw;
}

inline float Vec4::length( void ) const
{
	return sqrt( x * x + y * y + z * z + w * w );
}

inline float Vec4::lengthSq( void ) const
{
	return x * x + y * y + z * z + w * w;
}

inline float Vec4::angleBetween( const Vec4& v ) const
{
	float dx = w * v.x - x * v.w - y * v.z + z * v.y;
	float dy = w * v.y - y * v.w - z * v.x + x * v.z;
	float dz = w * v.z - z * v.w - x * v.y + y * v.x;

	return atan2f( sqrt( dx * dx + dy * dy + dz * dz ) + FLT_MIN, dot( v ) );
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
	if( magicalFltEqual( n, 1.0f ) )
		return;

	n = sqrt( n );
	if( magicalFltIsZero( n ) )
		return;

	n = 1.0f / n;
	x *= n;
	y *= n;
	z *= n;
	w *= n;
}

inline Vec4 Vec4::getClamp( const Vec4& min, const Vec4& max ) const
{
	Vec4 ret( *this );
	ret.clamp( min, max );
	return ret;
}

inline Vec4 Vec4::getNegate( void ) const
{
	Vec4 ret( *this );
	ret.negate();
	return ret;
}

inline Vec4 Vec4::getNormalize( void ) const
{
	Vec4 ret( *this );
	ret.normalize();
	return ret;
}

inline void MathVec4::add( Vec4& out, const Vec4& v, float a )
{
	out = v + a;
}

inline void MathVec4::add( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	out = v1 + v2;
}

inline void MathVec4::sub( Vec4& out, const Vec4& v, float a )
{
	out = v - a;
}

inline void MathVec4::sub( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	out = v1 - v2;
}

inline void MathVec4::mul( Vec4& out, const Vec4& v, float a )
{
	out = v * a;
}

inline void MathVec4::mul( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	out = v1 * v2;
}

inline void MathVec4::div( Vec4& out, const Vec4& v, float a )
{
	out = v / a;
}

inline void MathVec4::div( Vec4& out, const Vec4& v1, const Vec4& v2 )
{
	out = v1 / v2;
}

inline void MathVec4::clamp( Vec4& out, const Vec4& v, const Vec4& min, const Vec4& max )
{
	out = v.getClamp( min, max );
}

inline void MathVec4::negate( Vec4& out, const Vec4& v )
{
	out = v.getNegate();
}

inline void MathVec4::normalize( Vec4& out, const Vec4& v )
{
	out = v.getNormalize();
}