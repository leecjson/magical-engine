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

Matrix3::Matrix3( float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33 )
{
	magicalMatrix3Fill( this, m11, m12, m13, m21, m22, m23, m31, m32, m33 );
}

Matrix3::Matrix3( const Matrix3& m )
{
	magicalMatrix3Copy( this, &m );
}

Matrix3::Matrix3( void )
{
	magicalMatrix3SetIdentity( this );
}

inline Matrix3 Matrix3::createIdentity( void )
{
	return Matrix3::Identity;
}

inline Matrix3 Matrix3::createZero( void )
{
	return Matrix3::Zero;
}

inline void Matrix3::mulScalar( Matrix3& out, const Matrix3& m, float a )
{
	magicalMatrix3MulScalar( &out, &m, a );
}

inline void Matrix3::mul( Matrix3& out, const Matrix3& m1, const Matrix3& m2 )
{
	magicalMatrix3Mul( &out, &m1, &m2 );
}

inline void Matrix3::getUpVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetUpVector( &out, &m );
}

inline void Matrix3::getDownVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetDownVector( &out, &m );
}

inline void Matrix3::getLeftVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetLeftVector( &out, &m );
}

inline void Matrix3::getRightVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetRightVector( &out, &m );
}

inline void Matrix3::getForwardVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetForwardVector( &out, &m );
}

inline void Matrix3::getBackVector( Vector3& out, const Matrix3& m )
{
	magicalMatrix3GetBackVector( &out, &m );
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

inline float& Matrix3::operator[]( const unsigned int i ) const
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

inline void Matrix3::fromRotationX( float angle )
{
	magicalMatrix3FromRotationX( this, angle );
}

inline void Matrix3::fromRotationY( float angle )
{
	magicalMatrix3FromRotationY( this, angle );
}

inline void Matrix3::fromRotationZ( float angle )
{
	magicalMatrix3FromRotationZ( this, angle );
}

inline void Matrix3::fromAxisAngle( const Vector3& axis, float angle )
{
	magicalMatrix3FromAxisAngle( this, &AxisAngle( axis, angle ) );
}

inline void Matrix3::fromAxisAngle( const AxisAngle& aa )
{
	magicalMatrix3FromAxisAngle( this, &aa );
}

inline void Matrix3::fromEulerAngles( float yaw, float pitch, float roll )
{
	magicalMatrix3FromEulerAngles( this, &EulerAngles( yaw, pitch, roll ) );
}

inline void Matrix3::fromEulerAngles( const EulerAngles& ea )
{
	magicalMatrix3FromEulerAngles( this, &ea );
}

inline void Matrix3::fromQuaternion( const Quaternion& q )
{
	magicalMatrix3FromQuaternion( this, &q );
}

inline Quaternion Matrix3::toQuaternion( void )
{
	Quaternion ret;
	magicalMatrix3ToQuaternion( &ret, this );
	return ret;
}

NS_MAGICAL_END