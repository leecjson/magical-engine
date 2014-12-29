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

inline Quaternion Quaternion::createIdentity( void )
{
	return Quaternion::Identity;
}

inline Quaternion Quaternion::createZero( void )
{
	return Quaternion::Zero;
}

inline Quaternion Quaternion::createRotationX( float angle )
{
	Quaternion ret;
	magicalQuaternionSetRotationX( &ret, angle );
	return ret;
}

inline Quaternion Quaternion::createRotationY( float angle )
{
	Quaternion ret;
	magicalQuaternionSetRotationY( &ret, angle );
	return ret;
}

inline Quaternion Quaternion::createRotationZ( float angle )
{
	Quaternion ret;
	magicalQuaternionSetRotationZ( &ret, angle );
	return ret;
}

inline Quaternion Quaternion::createFromAxisAngle( const AxisAngle& aa )
{
	Quaternion ret;
	magicalQuaternionFromAxisAngle( &ret, &aa );
	return ret;
}

inline Quaternion Quaternion::createFromAxisAngle( const Vector3& axis, float angle )
{
	Quaternion ret;
	magicalQuaternionFromAxisAngle( &ret, &AxisAngle( axis, angle ) );
	return ret;
}

inline Quaternion Quaternion::createFromEulerAngles( const EulerAngles& ea )
{
	Quaternion ret;
	magicalQuaternionFromEulerAngles( &ret, &ea );
	return ret;
}

inline Quaternion Quaternion::createFromEulerAngles( float yaw, float pitch, float roll )
{
	Quaternion ret;
	magicalQuaternionFromEulerAngles( &ret, &EulerAngles( yaw, pitch, roll ) );
	return ret;
}

inline void Quaternion::add( Quaternion& out, const Quaternion& q1, const Quaternion& q2 )
{
	magicalQuaternionAdd( &out, &q1, &q2 );
}

inline void Quaternion::sub( Quaternion& out, const Quaternion& q1, const Quaternion& q2 )
{
	magicalQuaternionSub( &out, &q1, &q2 );
}

inline void Quaternion::mul( Quaternion& out, const Quaternion& q1, const Quaternion& q2 )
{
	magicalQuaternionMul( &out, &q1, &q2 );
}

inline void Quaternion::mulVector3( Vector3& out, const Quaternion& q, const Vector3& v )
{
	magicalQuaternionMulVector3( &out, &q, &v );
}

inline void Quaternion::mulScalar( Quaternion& out, const Quaternion& q, float a )
{
	magicalQuaternionMulScalar( &out, &q, a );
}

inline void Quaternion::normalize( Quaternion& out, const Quaternion& q )
{
	magicalQuaternionNormalize( &out, &q );
}

inline void Quaternion::conjugate( Quaternion& out, const Quaternion& q )
{
	magicalQuaternionConjugate( &out, &q );
}

inline void Quaternion::negate( Quaternion& out, const Quaternion& q )
{
	magicalQuaternionNegate( &out, &q );
}

inline void Quaternion::inverse( Quaternion& out, const Quaternion& q )
{
	magicalQuaternionInverse( &out, &q );
}

inline bool Quaternion::equals( const Quaternion& q ) const
{
	return magicalQuaternionEquals( this, &q );
}

inline bool Quaternion::isIdentity( void ) const
{
	return magicalQuaternionIsIdentity( this );
}

inline bool Quaternion::isZero( void ) const
{
	return magicalQuaternionIsZero( this );
}

inline bool Quaternion::isNormalized( void ) const
{
	return magicalQuaternionIsNormalized( this );
}

inline bool Quaternion::operator==( const Quaternion& q ) const
{
	return magicalQuaternionEquals( this, &q );
}

inline bool Quaternion::operator!=( const Quaternion& q ) const
{
	return !magicalQuaternionEquals( this, &q );
}

inline float& Quaternion::operator[]( const unsigned int i ) const
{
#ifdef MAGICAL_DEBUG
	assert( 0 <= i && i <= 3 && "index out of range" );
#endif
	return ((float*)this)[i];
}

inline Quaternion Quaternion::operator+( const Quaternion& q ) const
{
	return Quaternion( x + q.x, y + q.y, z + q.z, w + q.w );
}

inline Quaternion Quaternion::operator-( const Quaternion& q ) const
{
	return Quaternion( x - q.x, y - q.y, z - q.z, w - q.w );
}

inline Quaternion Quaternion::operator*( float a ) const
{
	return Quaternion( x * a, y * a, z * a, w * a );
}

inline Vector3 Quaternion::operator*( const Vector3& v ) const
{
	Vector3 ret;
	magicalQuaternionMulVector3( &ret, this, &v );
	return ret;
}

inline Quaternion Quaternion::operator*( const Quaternion& q ) const
{
	Quaternion ret;
	magicalQuaternionMul( &ret, this, &q );
	return ret;
}

inline Quaternion& Quaternion::operator+=( const Quaternion& q )
{
	w += q.w; x += q.x; y += q.y; z += q.z;
	return *this;
}

inline Quaternion& Quaternion::operator-=( const Quaternion& q )
{
	w -= q.w; x -= q.x; y -= q.y; z -= q.z;
	return *this;
}

inline Quaternion& Quaternion::operator*=( float a )
{
	x *= a; y *= a; z *= a; w *= a;
	return *this;
}

inline Quaternion& Quaternion::operator*=( const Quaternion& q )
{
	magicalQuaternionMul( this, this, &q );
	return *this;
}

inline Quaternion& Quaternion::operator=( const Quaternion& q )
{
	x = q.x; y = q.y; z = q.z; w = q.w;
	return *this;
}

inline void Quaternion::set( const Quaternion& r )
{
	x = r.x; y = r.y; z = r.z; w = r.w;
}

inline void Quaternion::setIdentity( void )
{
	x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f;
}

inline void Quaternion::setZero( void )
{
	x = 0.0f; y = 0.0f; z = 0.0f; w = 0.0f;
}

inline void Quaternion::setScalars( float x, float y, float z, float w )
{
	this->x = x; this->y = y; this->z = z; this->w = w;
}

inline void Quaternion::setRotationX( float angle )
{
	magicalQuaternionSetRotationX( this, angle );
}

inline void Quaternion::setRotationY( float angle )
{
	magicalQuaternionSetRotationY( this, angle );
}

inline void Quaternion::setRotationZ( float angle )
{
	magicalQuaternionSetRotationZ( this, angle );
}

inline void Quaternion::fromAxisAngle( const AxisAngle& aa )
{
	magicalQuaternionFromAxisAngle( this, &aa );
}

inline void Quaternion::fromAxisAngle( const Vector3& axis, float angle )
{
	magicalQuaternionFromAxisAngle( this, &AxisAngle( axis, angle ) );
}

inline AxisAngle Quaternion::toAxisAngle( void ) const
{
	AxisAngle aa;
	magicalQuaternionToAxisAngle( &aa, this );
	return aa;
}

inline void Quaternion::fromEulerAngles( const EulerAngles& ea )
{
	magicalQuaternionFromEulerAngles( this, &ea );
}

inline void Quaternion::fromEulerAngles( float yaw, float pitch, float roll )
{
	magicalQuaternionFromEulerAngles( this, &EulerAngles( yaw, pitch, roll ) );
}

inline EulerAngles Quaternion::toEulerAngles( void ) const
{
	EulerAngles ea;
	magicalQuaternionToEulerAngles( &ea, this );
	return ea;
}

inline void Quaternion::normalize( void )
{
	magicalQuaternionNormalize( this, this );
}

inline void Quaternion::conjugate( void )
{
	magicalQuaternionConjugate( this, this );
}

inline void Quaternion::negate( void )
{
	magicalQuaternionNegate( this, this );
}

inline void Quaternion::inverse( void )
{
	magicalQuaternionInverse( this, this );
}

inline Quaternion Quaternion::getNormalized( void ) const
{
	Quaternion ret;
	magicalQuaternionNormalize( &ret, this );
	return ret;
}

inline Quaternion Quaternion::getConjugated( void ) const
{
	Quaternion ret;
	magicalQuaternionConjugate( &ret, this );
	return ret;
}

inline Quaternion Quaternion::getNegated( void ) const
{
	Quaternion ret;
	magicalQuaternionNegate( &ret, this );
	return ret;
}

inline Quaternion Quaternion::getInversed( void ) const
{
	Quaternion ret;
	magicalQuaternionInverse( &ret, this );
	return ret;
}

inline float Quaternion::dot( const Quaternion& q ) const
{
	return magicalQuaternionDot( this, &q );
}

inline float Quaternion::length( void ) const
{
	return magicalQuaternionLength( this );
}

inline float Quaternion::lengthSq( void ) const
{
	return magicalQuaternionLengthSq( this );
}