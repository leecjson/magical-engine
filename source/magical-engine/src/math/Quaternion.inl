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

inline Quaternion::Quaternion( float x, float y, float z, float w ) 
: x( x ), y( y ), z( z ), w( w )
{
	
}

inline Quaternion::Quaternion( const Matrix3x3& m )
{
	setRotation( m );
}

inline Quaternion::Quaternion( const Rotater& ea )
{
	setRotation( ea );
}

inline Quaternion::Quaternion( const Vector3& axis, float angle )
{
	setRotation( axis, angle );
}

inline Quaternion::Quaternion( const Quaternion& q ) 
: x( q.x ), y( q.y ), z( q.z ), w( q.w )
{
	
}

inline Quaternion::Quaternion( void )
{

}

inline bool Quaternion::operator==( const Quaternion& q ) const
{
	return equals( q );
}

inline bool Quaternion::operator!=( const Quaternion& q ) const
{
	return equals( q ) == false;
}

inline Quaternion& Quaternion::operator=( const Quaternion& q )
{
	x = q.x;
	y = q.y;
	z = q.z;
	w = q.w;
	return *this;
}

inline Quaternion Quaternion::operator+( void ) const
{
	return *this;
}

inline Quaternion Quaternion::operator+( const Quaternion& q ) const
{
	return Quaternion( x + q.x, y + q.y, z + q.z, w + q.w );
}

inline Quaternion Quaternion::operator-( void ) const
{
	return Quaternion( -x, -y, -z, -w );
}

inline Quaternion Quaternion::operator-( const Quaternion& q ) const
{
	return Quaternion( x - q.x, y - q.y, z - q.z, w - q.w );
}

inline Quaternion Quaternion::operator*( float a ) const
{
	return Quaternion( x * a, y * a, z * a, w * a );
}

inline Quaternion Quaternion::operator*( const Quaternion& q ) const
{
	Quaternion dst;
	Quaternion::mul( dst, *this, q );
	return dst;
}

inline Vector3 Quaternion::operator*( const Vector3& v ) const
{
	Vector3 dst;
	Quaternion::mulVector3( dst, *this, v );
	return dst;
}

inline Quaternion& Quaternion::operator+=( const Quaternion& q )
{
	x += q.x;
	y += q.y;
	z += q.z;
	w += q.w;
	return *this;
}

inline Quaternion& Quaternion::operator-=( const Quaternion& q )
{
	x -= q.x;
	y -= q.y;
	z -= q.z;
	w -= q.w;
	return *this;
}

inline Quaternion& Quaternion::operator*=( float a )
{
	x *= a;
	y *= a;
	z *= a;
	w *= a;
	return *this;
}

inline Quaternion& Quaternion::operator*=( const Quaternion& q )
{
	Quaternion::mul( *this, *this, q );
	return *this;
}

inline void Quaternion::add( Quaternion& out, const Quaternion& q1, const Quaternion& q2 )
{
	out.x = q1.x + q2.x;
	out.y = q1.y + q2.y;
	out.z = q1.z + q2.z;
	out.w = q1.w + q2.w;
}

inline void Quaternion::sub( Quaternion& out, const Quaternion& q1, const Quaternion& q2 )
{
	out.x = q1.x - q2.x;
	out.y = q1.y - q2.y;
	out.z = q1.z - q2.z;
	out.w = q1.w - q2.w;
}

inline void Quaternion::mulScalar( Quaternion& out, const Quaternion& q, float a )
{
	out.x = q.x * a;
	out.y = q.y * a;
	out.z = q.z * a;
	out.w = q.w * a;
}

inline Quaternion Quaternion::add( const Quaternion& q1, const Quaternion& q2 )
{
	return Quaternion( q1.x + q2.x, q1.y + q2.y, q1.z + q2.z, q1.w + q2.w );
}

inline Quaternion Quaternion::sub( const Quaternion& q1, const Quaternion& q2 )
{
	return Quaternion( q1.x - q2.x, q1.y - q2.y, q1.z - q2.z, q1.w - q2.w );
}

inline Quaternion Quaternion::mul( const Quaternion& q1, const Quaternion& q2 )
{
	Quaternion dst;
	Quaternion::mul( dst, q1, q2 );
	return dst;
}

inline Quaternion Quaternion::mulScalar( const Quaternion& q, float a )
{
	return Quaternion( q.x * a, q.y * a, q.z * a, q.w * a );
}

inline Vector3 Quaternion::mulVector3( const Quaternion& q, const Vector3& v )
{
	Vector3 dst;
	Quaternion::mulVector3( dst, q, v );
	return dst;
}

inline void Quaternion::add( const Quaternion& q )
{
	x += q.x;
	y += q.y;
	z += q.z;
	w += q.w;
}

inline void Quaternion::sub( const Quaternion& q )
{
	x -= q.x;
	y -= q.y;
	z -= q.z;
	w -= q.w;
}

inline void Quaternion::mul( const Quaternion& q )
{
	Quaternion::mul( *this, *this, q );
}

inline void Quaternion::mulScalar( float a )
{
	x *= a;
	y *= a;
	z *= a;
	w *= a;
}

inline Vector3 Quaternion::mulVector3( const Vector3& v ) const
{
	Vector3 dst;
	Quaternion::mulVector3( dst, *this, v );
	return dst;
}

inline bool Quaternion::equals( const Quaternion& q ) const
{
	return
		Math::isAlmostEqual( x, q.x, Math::QuaternionEpsilon ) &&
		Math::isAlmostEqual( y, q.y, Math::QuaternionEpsilon ) &&
		Math::isAlmostEqual( z, q.z, Math::QuaternionEpsilon ) &&
		Math::isAlmostEqual( w, q.w, Math::QuaternionEpsilon );
}

inline bool Quaternion::isZero( void ) const
{
	return
		Math::isAlmostZero( x, Math::QuaternionEpsilon ) &&
		Math::isAlmostZero( y, Math::QuaternionEpsilon ) &&
		Math::isAlmostZero( z, Math::QuaternionEpsilon ) &&
		Math::isAlmostZero( w, Math::QuaternionEpsilon );
}

inline bool Quaternion::isIdentity( void ) const
{
	return
		Math::isAlmostEqual( x, 0.0f, Math::QuaternionEpsilon ) &&
		Math::isAlmostEqual( y, 0.0f, Math::QuaternionEpsilon ) &&
		Math::isAlmostEqual( z, 0.0f, Math::QuaternionEpsilon ) &&
		Math::isAlmostEqual( w, 1.0f, Math::QuaternionEpsilon );
}

inline void Quaternion::setZero( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

inline void Quaternion::setIdentity( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 1.0f;
}

inline void Quaternion::set( const Quaternion& q )
{
	x = q.x;
	y = q.y;
	z = q.z;
	w = q.w;
}

inline void Quaternion::set( float x, float y, float z, float w )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

inline Quaternion Quaternion::createRotation( const Matrix3x3& m )
{
	Quaternion dst;
	dst.setRotation( m );
	return dst;
}

inline Quaternion Quaternion::createRotation( const Rotater& ea )
{
	Quaternion dst;
	dst.setRotation( ea );
	return dst;
}

inline Quaternion Quaternion::createRotation( const Vector3& axis, float angle )
{
	Quaternion dst;
	dst.setRotation( axis, angle );
	return dst;
}

inline Quaternion Quaternion::createRotationX( float a )
{
	Quaternion dst;
	dst.setRotationX( a );
	return dst;
}

inline Quaternion Quaternion::createRotationY( float a )
{
	Quaternion dst;
	dst.setRotationY( a );
	return dst;
}

inline Quaternion Quaternion::createRotationZ( float a )
{
	Quaternion dst;
	dst.setRotationZ( a );
	return dst;
}

inline Quaternion Quaternion::normalize( const Quaternion& q )
{
	Quaternion dst;
	Quaternion::normalize( dst, q );
	return dst;
}

inline Quaternion Quaternion::conjugate( const Quaternion& q )
{
	Quaternion dst;
	Quaternion::conjugate( dst, q );
	return dst;
}

inline Quaternion Quaternion::negate( const Quaternion& q )
{
	Quaternion dst;
	Quaternion::negate( dst, q );
	return dst;
}

inline Quaternion Quaternion::inverse( const Quaternion& q )
{
	Quaternion dst;
	Quaternion::inverse( dst, q );
	return dst;
}

inline void Quaternion::normalize( void )
{
	Quaternion::normalize( *this, *this );
}

inline void Quaternion::conjugate( void )
{
	Quaternion::conjugate( *this, *this );
}

inline void Quaternion::negate( void )
{
	Quaternion::negate( *this, *this );
}

inline void Quaternion::inverse( void )
{
	Quaternion::inverse( *this, *this );
}

inline float Quaternion::dot( const Quaternion& q1, const Quaternion& q2 )
{
	return q1.w * q2.w + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z;
}

inline float Quaternion::length( const Quaternion& q )
{
	return sqrtf( q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w );
}

inline float Quaternion::lengthSq( const Quaternion& q )
{
	return q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w;
}

inline float Quaternion::dot( const Quaternion& q ) const
{
	return Quaternion::dot( *this, q );
}

inline float Quaternion::length( void ) const
{
	return Quaternion::length( *this );
}

inline float Quaternion::lengthSq( void ) const
{
	return Quaternion::lengthSq( *this );
}