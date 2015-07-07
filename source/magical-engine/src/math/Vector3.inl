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
NAMESPACE_MAGICAL

inline Vector3::Vector3( const Vector2& v ) 
: x( v.x ), y( v.y ), z( 0.0f )
{

}

inline Vector3::Vector3( float v ) 
: x( v ), y( v ), z( v )
{
	
}

inline Vector3::Vector3( float x, float y, float z ) 
: x( x ), y( y ), z( z )
{
	
}

inline Vector3::Vector3( const Vector3& v ) 
: x( v.x ), y( v.y ), z( v.z )
{
	
}

inline Vector3::Vector3( void )
{
	
}

inline bool Vector3::operator==( const Vector3& v ) const
{
	return equals( v );
}

inline bool Vector3::operator!=( const Vector3& v ) const
{
	return equals( v ) == false;
}

inline float& Vector3::operator[]( size_t i ) const
{
	debugassert( 0 <= i && i <= 2, "index out of range" );

	return ((float*)this)[i];
}

inline Vector3& Vector3::operator=( float v )
{
	x = v; y = v; z = v; return *this;
}

inline Vector3& Vector3::operator=( const Vector3& v )
{
	x = v.x; y = v.y; z = v.z; return *this;
}

inline Vector3 Vector3::operator+( void ) const
{
	return *this;
}

inline Vector3 Vector3::operator+( float a ) const
{
	return Vector3( x + a, y + a, z + a );
}

inline Vector3 Vector3::operator+( const Vector3& v ) const
{
	return Vector3( x + v.x, y + v.y, z + v.z );
}

inline Vector3 Vector3::operator-( void ) const
{
	return Vector3( -x, -y, -z );
}

inline Vector3 Vector3::operator-( float a ) const
{
	return Vector3( x - a, y - a, z - a );
}

inline Vector3 Vector3::operator-( const Vector3& v ) const
{
	return Vector3( x - v.x, y - v.y, z - v.z );
}

inline Vector3 Vector3::operator*( const Matrix3x3& m ) const
{
	Vector3 dst; 
	Vector3::mul3x3( dst, *this, m ); 
	return dst;
}

inline Vector3 Vector3::operator*( const Matrix4x4& m ) const
{
	Vector3 dst; 
	Vector3::mul4x4( dst, *this, m );
	return dst;
}

inline Vector3 Vector3::operator*( float a ) const
{
	return Vector3( x * a, y * a, z * a );
}

inline Vector3 Vector3::operator*( const Vector3& v ) const
{
	return Vector3( x * v.x, y * v.y, z * v.z );
}

inline Vector3 Vector3::operator/( float a ) const
{
	return Vector3( x / a, y / a, z / a );
}

inline Vector3 Vector3::operator/( const Vector3& v ) const
{
	return Vector3( x / v.x, y / v.y, z / v.z );
}

inline Vector3& Vector3::operator+=( float a )
{
	x += a; y += a; z += a; return *this;
}

inline Vector3& Vector3::operator+=( const Vector3& v )
{
	x += v.x; y += v.y; z += v.z; return *this;
}

inline Vector3& Vector3::operator-=( float a )
{
	x -= a; y -= a; z -= a; return *this;
}

inline Vector3& Vector3::operator-=( const Vector3& v )
{
	x -= v.x; y -= v.y; z -= v.z; return *this;
}

inline Vector3& Vector3::operator*=( const Matrix3x3& m )
{
	Vector3::mul3x3( *this, *this, m );
	return *this;
}

inline Vector3& Vector3::operator*=( const Matrix4x4& m )
{
	Vector3::mul4x4( *this, *this, m );
	return *this;
}

inline Vector3& Vector3::operator*=( float a )
{
	x *= a; y *= a; z *= a; return *this;
}

inline Vector3& Vector3::operator*=( const Vector3& v )
{
	x *= v.x; y *= v.y; z *= v.z; return *this;
}

inline Vector3& Vector3::operator/=( float a )
{
	x /= a; y /= a; z /= a; return *this;
}

inline Vector3& Vector3::operator/=( const Vector3& v )
{
	x /= v.x; y /= v.y; z /= v.z; return *this;
}

inline void Vector3::add( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	out.x = v1.x + v2.x;
	out.y = v1.y + v2.y;
	out.z = v1.z + v2.z;
}

inline void Vector3::sub( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	out.x = v1.x - v2.x;
	out.y = v1.y - v2.y;
	out.z = v1.z - v2.z;
}

inline void Vector3::mul( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	out.x = v1.x * v2.x;
	out.y = v1.y * v2.y;
	out.z = v1.z * v2.z;
}

inline void Vector3::div( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	out.x = v1.x / v2.x;
	out.y = v1.y / v2.y;
	out.z = v1.z / v2.z;
}

inline void Vector3::addScalar( Vector3& out, const Vector3& v, float a )
{
	out.x = v.x + a;
	out.y = v.y + a;
	out.z = v.z + a;
}

inline void Vector3::subScalar( Vector3& out, const Vector3& v, float a )
{
	out.x = v.x - a;
	out.y = v.y - a;
	out.z = v.z - a;
}

inline void Vector3::mulScalar( Vector3& out, const Vector3& v, float a )
{
	out.x = v.x * a;
	out.y = v.y * a;
	out.z = v.z * a;
}

inline void Vector3::divScalar( Vector3& out, const Vector3& v, float a )
{
	out.x = v.x / a;
	out.y = v.y / a;
	out.z = v.z / a;
}

inline Vector3 Vector3::add( const Vector3& v1, const Vector3& v2 )
{
	return Vector3( v1.x + v2.x, v1.y + v2.y, v1.z + v2.z );
}

inline Vector3 Vector3::sub( const Vector3& v1, const Vector3& v2 )
{
	return Vector3( v1.x - v2.x, v1.y - v2.y, v1.z - v2.z );
}

inline Vector3 Vector3::mul( const Vector3& v1, const Vector3& v2 )
{
	return Vector3( v1.x * v2.x, v1.y * v2.y, v1.z * v2.z );
}

inline Vector3 Vector3::div( const Vector3& v1, const Vector3& v2 )
{
	return Vector3( v1.x / v2.x, v1.y / v2.y, v1.z / v2.z );
}

inline Vector3 Vector3::addScalar( const Vector3& v, float a )
{
	return Vector3( v.x + a, v.y + a, v.z + a );
}

inline Vector3 Vector3::subScalar( const Vector3& v, float a )
{
	return Vector3( v.x - a, v.y - a, v.z - a );
}

inline Vector3 Vector3::mulScalar( const Vector3& v, float a )
{
	return Vector3( v.x * a, v.y * a, v.z * a );
}

inline Vector3 Vector3::divScalar( const Vector3& v, float a )
{
	return Vector3( v.x / a, v.y / a, v.z / a );
}

inline Vector3 Vector3::mul3x3( const Vector3& v, const Matrix3x3& m )
{
	Vector3 dst; 
	Vector3::mul3x3( dst, v, m );
	return dst;
}

inline Vector3 Vector3::mul4x4( const Vector3& v, const Matrix4x4& m )
{
	Vector3 dst; 
	Vector3::mul4x4( dst, v, m );
	return dst;
}

inline void Vector3::add( const Vector3& v )
{
	x += v.x; y += v.y; z += v.z;
}

inline void Vector3::sub( const Vector3& v )
{
	x -= v.x; y -= v.y; z -= v.z;
}

inline void Vector3::mul( const Vector3& v )
{
	x *= v.x; y *= v.y; z *= v.z;
}

inline void Vector3::div( const Vector3& v )
{
	x /= v.x; y /= v.y; z /= v.z;
}

inline void Vector3::addScalar( float a )
{
	x += a; y += a; z += a;
}

inline void Vector3::subScalar( float a )
{
	x -= a; y -= a; z -= a;
}

inline void Vector3::mulScalar( float a )
{
	x *= a; y *= a; z *= a;
}

inline void Vector3::divScalar( float a )
{
	x /= a; y /= a; z /= a;
}

inline void Vector3::mul3x3( const Matrix3x3& m )
{
	Vector3::mul3x3( *this, *this, m );
}

inline void Vector3::mul4x4( const Matrix4x4& m )
{
	Vector3::mul4x4( *this, *this, m );
}

inline bool Vector3::equals( const Vector3& v ) const
{
	return
		Math::isAlmostEqual( x, v.x, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( y, v.y, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( z, v.z, Math::VectorEpsilon );
}

inline bool Vector3::isZero( void ) const
{
	return
		Math::isAlmostZero( x, Math::VectorEpsilon ) &&
		Math::isAlmostZero( y, Math::VectorEpsilon ) &&
		Math::isAlmostZero( z, Math::VectorEpsilon );
}

inline bool Vector3::isOne( void ) const
{
	return
		Math::isAlmostEqual( x, 1.0f, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( y, 1.0f, Math::VectorEpsilon ) &&
		Math::isAlmostEqual( z, 1.0f, Math::VectorEpsilon );
}

inline void Vector3::setZero( void )
{
	x = 0.0f; y = 0.0f; z = 0.0f;
}

inline void Vector3::setOne( void )
{
	x = 1.0f; y = 1.0f; z = 1.0f;
}

inline void Vector3::set( const Vector2& v )
{
	x = v.x; y = v.y; z = 0.0f;
}

inline void Vector3::set( const Vector3& v )
{
	x = v.x; y = v.y; z = v.z;
}

inline void Vector3::set( float x, float y, float z )
{
	this->x = x; this->y = y; this->z = z;
}

inline Vector3 Vector3::clamp( const Vector3& v, const Vector3& min, const Vector3& max )
{
	Vector3 dst;
	Vector3::clamp( dst, v, min, max );
	return dst;
}

inline Vector3 Vector3::negate( const Vector3& v )
{
	Vector3 dst;
	Vector3::negate( dst, v );
	return dst;
}

inline Vector3 Vector3::normalize( const Vector3& v )
{
	Vector3 dst;
	Vector3::normalize( dst, v );
	return dst;
}

inline Vector3 Vector3::scale( const Vector3& v, float s )
{
	Vector3 dst;
	Vector3::scale( dst, v, s );
	return dst;
}

inline Vector3 Vector3::cross( const Vector3& v1, const Vector3& v2 )
{
	Vector3 dst;
	Vector3::cross( dst, v1, v2 );
	return dst;
}

inline Vector3 Vector3::midPointBetween( const Vector3& v1, const Vector3& v2 )
{
	Vector3 dst;
	Vector3::midPointBetween( dst, v1, v2 );
	return dst;
}

inline Vector3 Vector3::project( const Vector3& v, const Vector3& n )
{
	Vector3 dst;
	Vector3::project( dst, v, n );
	return dst;
}

inline Vector3 Vector3::lerp( const Vector3& v1, const Vector3& v2, float t )
{
	Vector3 dst;
	Vector3::lerp( dst, v1, v2, t );
	return dst;
}

inline void Vector3::clamp( const Vector3& min, const Vector3& max )
{
	Vector3::clamp( *this, *this, min, max );
}

inline void Vector3::negate( void )
{
	Vector3::negate( *this, *this );
}

inline void Vector3::normalize( void )
{
	Vector3::normalize( *this, *this );
}

inline void Vector3::scale( float s )
{
	Vector3::scale( *this, *this, s );
}

inline Vector3 Vector3::cross( const Vector3& v )
{
	return Vector3::cross( *this, v );
}

inline Vector3 Vector3::midPointBetween( const Vector3& v ) const
{
	return Vector3::midPointBetween( *this, v );
}

inline Vector3 Vector3::project( const Vector3& n ) const
{
	return Vector3::project( *this, n );
}

inline Vector3 Vector3::lerp( const Vector3& v, float t ) const
{
	return Vector3::lerp( *this, v, t );
}

inline float Vector3::dot( const Vector3& v1, const Vector3& v2 )
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline float Vector3::distance( const Vector3& v1, const Vector3& v2 )
{
	float dx = v2.x - v1.x;
	float dy = v2.y - v1.y;
	float dz = v2.z - v1.z;

	return sqrtf( dx * dx + dy * dy + dz * dz );
}

inline float Vector3::distanceSq( const Vector3& v1, const Vector3& v2 )
{
	float dx = v2.x - v1.x;
	float dy = v2.y - v1.y;
	float dz = v2.z - v1.z;

	return dx * dx + dy * dy + dz * dz;
}

inline float Vector3::length( const Vector3& v )
{
	return sqrtf( v.x * v.x + v.y * v.y + v.z * v.z );
}

inline float Vector3::lengthSq( const Vector3& v )
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

inline float Vector3::angle( const Vector3& v1, const Vector3& v2 )
{
	debugassert( !v1.isZero() && !v2.isZero(), "invaild operate!" );

	return Math::safeAcos( Vector3::dot( v1, v2 ) / ( v1.length() * v2.length() ) );
}

inline float Vector3::dot( const Vector3& v ) const
{
	return Vector3::dot( *this, v );
}

inline float Vector3::distance( const Vector3& v ) const
{
	return Vector3::distance( *this, v );
}

inline float Vector3::distanceSq( const Vector3& v ) const
{
	return Vector3::distanceSq( *this, v );
}

inline float Vector3::length( void ) const
{
	return Vector3::length( *this );
}

inline float Vector3::lengthSq( void ) const
{
	return Vector3::lengthSq( *this );
}

inline float Vector3::angle( const Vector3& v ) const
{
	return Vector3::angle( *this, v );
}

NAMESPACE_END