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

inline Matrix4 Matrix4::createIdentity( void )
{
	return Matrix4::Identity;
}

inline Matrix4 Matrix4::createZero( void )
{
	return Matrix4::Zero;
}

inline Matrix4 Matrix4::createLookAt( const Vector3& eye, const Vector3& target, const Vector3& up )
{
	Matrix4 ret;
	magicalMatrix4SetLookAt( &ret, &eye, &target, &up );
	return ret;
}

inline Matrix4 Matrix4::createPerspective( float fov, float aspect, float znear, float zfar )
{
	Matrix4 ret;
	magicalMatrix4SetPerspective( &ret, fov, aspect, znear, zfar );
	return ret;
}

inline Matrix4 Matrix4::createOrth( float left, float right, float bottom, float top, float znear, float zfar )
{
	Matrix4 ret;
	magicalMatrix4SetOrth( &ret, left, right, top, bottom, znear, zfar );
	return ret;
}

inline Matrix4 Matrix4::createTRS( const Vector3& t, const Quaternion& r, const Vector3& s )
{
	Matrix4 ret;
	magicalMatrix4SetTRS( &ret, &t, &r, &s );
	return ret;
}

inline Matrix4 Matrix4::createTranslation( const Vector3& t )
{
	Matrix4 ret;
	magicalMatrix4SetTranslation( &ret, &t );
	return ret;
}

inline Matrix4 Matrix4::createTranslation( float x, float y, float z )
{
	Matrix4 ret;
	Vector3 t( x, y, z );
	magicalMatrix4SetTranslation( &ret, &t );
	return ret;
}

inline Matrix4 Matrix4::createScale( const Vector3& s )
{
	Matrix4 ret;
	magicalMatrix4SetScale( &ret, &s );
	return ret;
}

inline Matrix4 Matrix4::createScale( float x, float y, float z )
{
	Matrix4 ret;
	Vector3 s( x, y, z );
	magicalMatrix4SetScale( &ret, &s );
	return ret;
}

inline Matrix4 Matrix4::createScale( float s )
{
	Matrix4 ret;
	Vector3 ss( s, s, s );
	magicalMatrix4SetScale( &ret, &ss );
	return ret;
}

inline Matrix4 Matrix4::createRotationX( float angle )
{
	Matrix4 ret;
	magicalMatrix4SetRotationX( &ret, angle );
	return ret;
}

inline Matrix4 Matrix4::createRotationY( float angle )
{
	Matrix4 ret;
	magicalMatrix4SetRotationY( &ret, angle );
	return ret;
}

inline Matrix4 Matrix4::createRotationZ( float angle )
{
	Matrix4 ret;
	magicalMatrix4SetRotationZ( &ret, angle );
	return ret;
}

inline Matrix4 Matrix4::createRotationQuaternion( const Quaternion& q )
{
	Matrix4 ret;
	magicalMatrix4SetRotationQuaternion( &ret, &q );
	return ret;
}

inline Matrix4 Matrix4::createRotationAxisAngle( const Vector3& axis, float angle )
{
	Matrix4 ret;
	AxisAngle aa( axis, angle );
	magicalMatrix4SetRotationAxisAngle( &ret, &aa );
	return ret;
}

inline Matrix4 Matrix4::createRotationAxisAngle( const AxisAngle& aa )
{
	Matrix4 ret;
	magicalMatrix4SetRotationAxisAngle( &ret, &aa );
	return ret;
}

inline Matrix4 Matrix4::createRotationEulerAngles( float yaw, float pitch, float roll )
{
	Matrix4 ret;
	EulerAngles ea( yaw, pitch, roll );
	magicalMatrix4SetRotationEulerAngles( &ret, &ea );
	return ret;
}

inline Matrix4 Matrix4::createRotationEulerAngles( const EulerAngles& ea )
{
	Matrix4 ret;
	magicalMatrix4SetRotationEulerAngles( &ret, &ea );
	return ret;
}

inline bool Matrix4::equals( const Matrix4& m ) const
{
	return magicalMatrix4Equals( this, &m );
}

inline bool Matrix4::isZero( void ) const
{
	return magicalMatrix4IsZero( this );
}

inline bool Matrix4::isIdentity( void ) const
{
	return magicalMatrix4IsIdentity( this );
}

inline bool Matrix4::operator==( const Matrix4& m ) const
{
	return magicalMatrix4Equals( this, &m );
}

inline bool Matrix4::operator!=( const Matrix4& m ) const
{
	return !magicalMatrix4Equals( this, &m );
}

inline float& Matrix4::operator[]( size_t i ) const
{
#ifdef MAGICAL_DEBUG
	assert( 0 <= i && i <= 15 && "index out of range" );
#endif
	return ((float*)this)[i];
}

inline Matrix4 Matrix4::operator*( float a ) const
{
	Matrix4 ret;
	magicalMatrix4MulScalar( &ret, this, a );
	return ret;
}

inline Matrix4 Matrix4::operator*( const Matrix4& m ) const
{
	Matrix4 ret;
	magicalMatrix4Mul( &ret, this, &m );
	return ret;
}

inline Matrix4& Matrix4::operator*=( float a )
{
	magicalMatrix4MulScalar( this, this, a );
	return *this;
}

inline Matrix4& Matrix4::operator*=( const Matrix4& m )
{
	magicalMatrix4Mul( this, this, &m );
	return *this;
}

inline Matrix4& Matrix4::operator=( const Matrix4& m )
{
	magicalMatrix4Copy( this, &m );
	return *this;
}

inline void Matrix4::set( const Matrix4& m )
{
	magicalMatrix4Copy( this, &m );
}

inline void Matrix4::setIdentity( void )
{
	magicalMatrix4SetIdentity( this );
}

inline void Matrix4::setZero( void )
{
	magicalMatrix4SetZero( this );
}

inline void Matrix4::setLookAt( const Vector3& eye, const Vector3& target, const Vector3& up )
{
	magicalMatrix4SetLookAt( this, &eye, &target, &up );
}

inline void Matrix4::setPerspective( float fov, float aspect, float znear, float zfar )
{
	magicalMatrix4SetPerspective( this, fov, aspect, znear, zfar );
}

inline void Matrix4::setOrth( float left, float right, float bottom, float top, float znear, float zfar )
{
	magicalMatrix4SetOrth( this, left, right, bottom, top, znear, zfar );
}

inline void Matrix4::setTRS( const Vector3& t, const Quaternion& r, const Vector3& s )
{
	magicalMatrix4SetTRS( this, &t, &r, &s );
}

inline void Matrix4::setTranslation( float x, float y, float z )
{
	Vector3 t( x, y, z );
	magicalMatrix4SetTranslation( this, &t );
}

inline void Matrix4::setTranslation( const Vector3& t )
{
	magicalMatrix4SetTranslation( this, &t );
}

inline void Matrix4::setScale( float x, float y, float z )
{
	Vector3 s( x, y, z );
	magicalMatrix4SetScale( this, &s );
}

inline void Matrix4::setScale( const Vector3& s )
{
    magicalMatrix4SetScale( this, &s );
}

inline void Matrix4::setScale( float s )
{
	Vector3 ss( s, s, s );
	magicalMatrix4SetScale( this, &ss );
}

inline void Matrix4::setRotationX( float angle )
{
	magicalMatrix4SetRotationX( this, angle );
}

inline void Matrix4::setRotationY( float angle )
{
	magicalMatrix4SetRotationY( this, angle );
}

inline void Matrix4::setRotationZ( float angle )
{
	magicalMatrix4SetRotationZ( this, angle );
}

inline void Matrix4::setRotationQuaternion( const Quaternion& q )
{
	magicalMatrix4SetRotationQuaternion( this, &q );
}

inline void Matrix4::setRotationAxisAngle( const Vector3& axis, float angle )
{
	AxisAngle aa( axis, angle );
	magicalMatrix4SetRotationAxisAngle( this, &aa );
}

inline void Matrix4::setRotationAxisAngle( const AxisAngle& aa )
{
	magicalMatrix4SetRotationAxisAngle( this, &aa );
}

inline void Matrix4::setRotationEulerAngles( float yaw, float pitch, float roll )
{
	EulerAngles ea( yaw, pitch, roll );
	magicalMatrix4SetRotationEulerAngles( this, &ea );
}

inline void Matrix4::setRotationEulerAngles( const EulerAngles& ea )
{
	magicalMatrix4SetRotationEulerAngles( this, &ea );
}

inline Vector3 Matrix4::getUpVector( void ) const
{
	Vector3 ret;
	magicalMatrix4GetUpVector( &ret, this );
	return ret;
}

inline Vector3 Matrix4::getDownVector( void ) const
{
	Vector3 ret;
	magicalMatrix4GetDownVector( &ret, this );
	return ret;
}

inline Vector3 Matrix4::getLeftVector( void ) const
{
	Vector3 ret;
	magicalMatrix4GetLeftVector( &ret, this );
	return ret;
}

inline Vector3 Matrix4::getRightVector( void ) const
{
	Vector3 ret;
	magicalMatrix4GetRightVector( &ret, this );
	return ret;
}

inline Vector3 Matrix4::getForwardVector( void ) const
{
	Vector3 ret;
	magicalMatrix4GetForwardVector( &ret, this );
	return ret;
}

inline Vector3 Matrix4::getBackVector( void ) const
{
	Vector3 ret;
	magicalMatrix4GetBackVector( &ret, this );
	return ret;
}

inline void Matrix4::inverse( void )
{
	magicalMatrix4Inverse( this, this );
}

inline void Matrix4::transpose( void )
{
	magicalMatrix4Transpose( this, this );
}

inline void Matrix4::negate( void )
{
	magicalMatrix4Negate( this, this );
}

inline Matrix4 Matrix4::getInversed( void ) const
{
	Matrix4 ret;
	magicalMatrix4Inverse( &ret, this );
	return ret;
}

inline Matrix4 Matrix4::getTransposed( void ) const
{
	Matrix4 ret;
	magicalMatrix4Transpose( &ret, this );
	return ret;
}

inline Matrix4 Matrix4::getNegated( void ) const
{
	Matrix4 ret;
	magicalMatrix4Negate( &ret, this );
	return ret;
}

inline float Matrix4::determinant( void ) const
{
	return magicalMatrix4Determinant( this );
}


inline void MathMatrix4::mulScalar( Matrix4& out, const Matrix4& m, float a )
{
	magicalMatrix4MulScalar( &out, &m, a );
}

inline void MathMatrix4::mul( Matrix4& out, const Matrix4& m1, const Matrix4& m2 )
{
	magicalMatrix4Mul( &out, &m1, &m2 );
}

inline void MathMatrix4::getUpVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetUpVector( &out, &m );
}

inline void MathMatrix4::getDownVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetDownVector( &out, &m );
}

inline void MathMatrix4::getLeftVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetLeftVector( &out, &m );
}

inline void MathMatrix4::getRightVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetRightVector( &out, &m );
}

inline void MathMatrix4::getForwardVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetForwardVector( &out, &m );
}

inline void MathMatrix4::getBackVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetBackVector( &out, &m );
}

inline void MathMatrix4::inverse( Matrix4& out, const Matrix4& m )
{
	magicalMatrix4Inverse( &out, &m );
}

inline void MathMatrix4::transpose( Matrix4& out, const Matrix4& m )
{
	magicalMatrix4Transpose( &out, &m );
}

inline void MathMatrix4::negate( Matrix4& out, const Matrix4& m )
{
	magicalMatrix4Negate( &out, &m );
}

NS_MAGICAL_END