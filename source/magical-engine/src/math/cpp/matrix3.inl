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

NS_MAGICAL_BEGIN

inline Matrix3 Matrix3::createIdentity( void )
{
	return Matrix3::Identity;
}

inline Matrix3 Matrix3::createZero( void )
{
	return Matrix3::Zero;
}

inline Matrix3 Matrix3::createLookAt( const Vector3& eye, const Vector3& target, const Vector3& up )
{
	Matrix3 ret;
	magicalMatrix3SetLookAt( &ret, &eye, &target, &up );
	return ret;
}

inline Matrix3 Matrix3::createRotationX( float angle )
{
	Matrix3 ret;
	magicalMatrix3SetRotationX( &ret, angle );
	return ret;
}

inline Matrix3 Matrix3::createRotationY( float angle )
{
	Matrix3 ret;
	magicalMatrix3SetRotationY( &ret, angle );
	return ret;
}

inline Matrix3 Matrix3::createRotationZ( float angle )
{
	Matrix3 ret;
	magicalMatrix3SetRotationZ( &ret, angle );
	return ret;
}

inline Matrix3 Matrix3::createFromQuaternion( const Quaternion& q )
{
	Matrix3 ret;
	magicalMatrix3FromQuaternion( &ret, &q );
	return ret;
}

inline Matrix3 Matrix3::createFromAxisAngle( const Vector3& axis, float angle )
{
	Matrix3 ret;
	AxisAngle aa( axis, angle );
	magicalMatrix3FromAxisAngle( &ret, &aa );
	return ret;
}

inline Matrix3 Matrix3::createFromAxisAngle( const AxisAngle& aa )
{
	Matrix3 ret;
	magicalMatrix3FromAxisAngle( &ret, &aa );
	return ret;
}

inline Matrix3 Matrix3::createFromEulerAngles( float yaw, float pitch, float roll )
{
	Matrix3 ret;
	EulerAngles ea( yaw, pitch, roll );
	magicalMatrix3FromEulerAngles( &ret, &ea );
	return ret;
}

inline Matrix3 Matrix3::createFromEulerAngles( const EulerAngles& ea )
{
	Matrix3 ret;
	magicalMatrix3FromEulerAngles( &ret, &ea );
	return ret;
}

inline bool Matrix3::equals( const Matrix3& m ) const
{
	return magicalMatrix3Equals( this, &m );
}

inline bool Matrix3::isZero( void ) const
{
	return magicalMatrix3IsZero( this );
}

inline bool Matrix3::isIdentity( void ) const
{
	return magicalMatrix3IsIdentity( this );
}

inline bool Matrix3::operator==( const Matrix3& m ) const
{
	return magicalMatrix3Equals( this, &m );
}

inline bool Matrix3::operator!=( const Matrix3& m ) const
{
	return !magicalMatrix3Equals( this, &m );
}

inline float& Matrix3::operator[]( size_t i ) const
{
#ifdef MAGICAL_DEBUG
	assert( 0 <= i && i <= 8 && "index out of range" );
#endif
	return ((float*)this)[i];
}

inline Matrix3 Matrix3::operator*( float a ) const
{
	Matrix3 ret;
	magicalMatrix3MulScalar( &ret, this, a );
	return ret;
}

inline Matrix3 Matrix3::operator*( const Matrix3& m ) const
{
	Matrix3 ret;
	magicalMatrix3Mul( &ret, this, &m );
	return ret;
}

inline Matrix3& Matrix3::operator*=( float a )
{
	magicalMatrix3MulScalar( this, this, a );
	return *this;
}

inline Matrix3& Matrix3::operator*=( const Matrix3& m )
{
	magicalMatrix3Mul( this, this, &m );
	return *this;
}

inline Matrix3& Matrix3::operator=( const Matrix3& m )
{
	magicalMatrix3Copy( this, &m );
	return *this;
}

inline void Matrix3::set( const Matrix3& m )
{
	magicalMatrix3Copy( this, &m );
}

inline void Matrix3::setIdentity( void )
{
	magicalMatrix3SetIdentity( this );
}

inline void Matrix3::setZero( void )
{
	magicalMatrix3SetZero( this );
}

inline void Matrix3::setLookAt( const Vector3& eye, const Vector3& target, const Vector3& up )
{
	magicalMatrix3SetLookAt( this, &eye, &target, &up );
}

inline void Matrix3::setRotationX( float angle )
{
	magicalMatrix3SetRotationX( this, angle );
}

inline void Matrix3::setRotationY( float angle )
{
	magicalMatrix3SetRotationY( this, angle );
}

inline void Matrix3::setRotationZ( float angle )
{
	magicalMatrix3SetRotationZ( this, angle );
}

inline void Matrix3::fromQuaternion( const Quaternion& q )
{
	magicalMatrix3FromQuaternion( this, &q );
}

inline void Matrix3::fromAxisAngle( const Vector3& axis, float angle )
{
	AxisAngle aa( axis, angle );
	magicalMatrix3FromAxisAngle( this, &aa );
}

inline void Matrix3::fromAxisAngle( const AxisAngle& aa )
{
	magicalMatrix3FromAxisAngle( this, &aa );
}

inline void Matrix3::fromEulerAngles( float yaw, float pitch, float roll )
{
	EulerAngles ea( yaw, pitch, roll );
	magicalMatrix3FromEulerAngles( this, &ea );
}

inline void Matrix3::fromEulerAngles( const EulerAngles& ea )
{
	magicalMatrix3FromEulerAngles( this, &ea );
}

inline Quaternion Matrix3::toQuaternion( void )
{
	Quaternion ret;
	magicalMatrix3ToQuaternion( &ret, this );
	return ret;
}

inline Vector3 Matrix3::getUpVector( void ) const
{
	Vector3 ret;
	magicalMatrix3GetUpVector( &ret, this );
	return ret;
}

inline Vector3 Matrix3::getDownVector( void ) const
{
	Vector3 ret;
	magicalMatrix3GetDownVector( &ret, this );
	return ret;
}

inline Vector3 Matrix3::getLeftVector( void ) const
{
	Vector3 ret;
	magicalMatrix3GetLeftVector( &ret, this );
	return ret;
}

inline Vector3 Matrix3::getRightVector( void ) const
{
	Vector3 ret;
	magicalMatrix3GetRightVector( &ret, this );
	return ret;
}

inline Vector3 Matrix3::getForwardVector( void ) const
{
	Vector3 ret;
	magicalMatrix3GetForwardVector( &ret, this );
	return ret;
}

inline Vector3 Matrix3::getBackVector( void ) const
{
	Vector3 ret;
	magicalMatrix3GetBackVector( &ret, this );
	return ret;
}

inline void Matrix3::inverse( void )
{
	magicalMatrix3Inverse( this, this );
}

inline void Matrix3::transpose( void )
{
	magicalMatrix3Transpose( this, this );
}

inline void Matrix3::negate( void )
{
	magicalMatrix3Negate( this, this );
}

inline Matrix3 Matrix3::getInversed( void ) const
{
	Matrix3 ret;
	magicalMatrix3Inverse( &ret, this );
	return ret;
}

inline Matrix3 Matrix3::getTransposed( void ) const
{
	Matrix3 ret;
	magicalMatrix3Transpose( &ret, this );
	return ret;
}

inline Matrix3 Matrix3::getNegated( void ) const
{
	Matrix3 ret;
	magicalMatrix3Negate( &ret, this );
	return ret;
}

inline float Matrix3::determinant( void ) const
{
	return magicalMatrix3Determinant( this );
}


inline void MathMatrix3::mulScalar( Matrix3& out, const Matrix3& m, float a )
{
	magicalMatrix3MulScalar( &out, &m, a );
}

inline void MathMatrix3::mul( Matrix3& out, const Matrix3& m1, const Matrix3& m2 )
{
	magicalMatrix3Mul( &out, &m1, &m2 );
}

inline void MathMatrix3::getUpVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetUpVector( &out, &m );
}

inline void MathMatrix3::getDownVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetDownVector( &out, &m );
}

inline void MathMatrix3::getLeftVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetLeftVector( &out, &m );
}

inline void MathMatrix3::getRightVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetRightVector( &out, &m );
}

inline void MathMatrix3::getForwardVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetForwardVector( &out, &m );
}

inline void MathMatrix3::getBackVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetBackVector( &out, &m );
}

inline void MathMatrix3::inverse( Matrix3& out, const Matrix3& m )
{
	magicalMatrix3Inverse( &out, &m );
}

inline void MathMatrix3::transpose( Matrix3& out, const Matrix3& m )
{
	magicalMatrix3Transpose( &out, &m );
}

inline void MathMatrix3::negate( Matrix3& out, const Matrix3& m )
{
	magicalMatrix3Negate( &out, &m );
}


NS_MAGICAL_END