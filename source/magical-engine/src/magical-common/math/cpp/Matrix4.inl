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

inline Matrix4 Matrix4::createIdentity( void )
{
	return Matrix4::Identity;
}

inline Matrix4 Matrix4::createZero( void )
{
	return Matrix4::Zero;
}

inline void Matrix4::mulScalar( Matrix4& out, const Matrix4& m, float a )
{
	magicalMatrix4MulScalar( &out, &m, a );
}

inline void Matrix4::mul( Matrix4& out, const Matrix4& m1, const Matrix4& m2 )
{
	magicalMatrix4Mul( &out, &m1, &m2 );
}

inline void Matrix4::getUpVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetUpVector( &out, &m );
}

inline void Matrix4::getDownVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetDownVector( &out, &m );
}

inline void Matrix4::getLeftVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetLeftVector( &out, &m );
}

inline void Matrix4::getRightVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetRightVector( &out, &m );
}

inline void Matrix4::getForwardVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetForwardVector( &out, &m );
}

inline void Matrix4::getBackVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetBackVector( &out, &m );
}

inline void Matrix4::getTranslation( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetTranslation( &out, &m );
}

inline void Matrix4::getScale( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetScale( &out, &m );
}

inline void Matrix4::getRotationQuaternion( Quaternion& out, const Matrix4& m )
{
	magicalMatrix4GetRotationQuaternion( &out, &m );
}

inline bool Matrix4::inverse( Matrix4& out, const Matrix4& m )
{
	return magicalMatrix4Inverse( &out, &m );
}

inline void Matrix4::transpose( Matrix4& out, const Matrix4& m )
{
	magicalMatrix4Transpose( &out, &m );
}

inline void Matrix4::negate( Matrix4& out, const Matrix4& m )
{
	magicalMatrix4Negate( &out, &m );
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

inline float& Matrix4::operator[]( const unsigned int i ) const
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

inline void Matrix4::set( const float* m )
{
	magicalMatrix4Copy( this, (Matrix4*)m );
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

inline void Matrix4::setOrth( float left, float right, float bottom, float top, float near, float far )
{
	magicalMatrix4SetOrth( this, left, right, bottom, top, near, far );
}

inline void Matrix4::setTRS( const Vector3& t, const Quaternion& q, const Vector3& s )
{
	magicalMatrix4SetTRS( this, &t, &q, &s );
}

inline void Matrix4::makeTranslation( float x, float y, float z )
{
	magicalMatrix4MakeTranslationScalars( this, x, y, z );
}

inline void Matrix4::makeTranslation( const Vector3& t )
{
	magicalMatrix4MakeTranslation( this, &t );
}

inline void Matrix4::makeScale( float x, float y, float z )
{
	magicalMatrix4MakeScaleScalars( this, x, y, z );
}

inline void Matrix4::makeScale( const Vector3& s )
{
    magicalMatrix4MakeScale( this, &s );
}

inline void Matrix4::makeRotationX( float angle )
{
	magicalMatrix4MakeRotationX( this, angle );
}

inline void Matrix4::makeRotationY( float angle )
{
	magicalMatrix4MakeRotationY( this, angle );
}

inline void Matrix4::makeRotationZ( float angle )
{
	magicalMatrix4MakeRotationZ( this, angle );
}

inline void Matrix4::makeRotationAxisAngle( const Vector3& axis, float angle )
{
	magicalMatrix4MakeRotationAxisAngle( this, &AxisAngle( axis, angle ) );
}

inline void Matrix4::makeRotationAxisAngle( const AxisAngle& aa )
{
	magicalMatrix4MakeRotationAxisAngle( this, &aa );
}

inline void Matrix4::makeRotationEulerAngles( float yaw, float pitch, float roll )
{
	magicalMatrix4MakeRotationEulerAngles( this, &EulerAngles( yaw, pitch, roll ) );
}

inline void Matrix4::makeRotationEulerAngles( const EulerAngles& ea )
{
	magicalMatrix4MakeRotationEulerAngles( this, &ea );
}

inline void Matrix4::makeRotationQuaternion( const Quaternion& q )
{
	magicalMatrix4MakeRotationQuaternion( this, &q );
}

inline Vector3 Matrix4::getUpVector( void ) const
{
	return Vector3( m21, m22, m23 );
}

inline Vector3 Matrix4::getDownVector( void ) const
{
	return Vector3( -m21, -m22, -m23 );
}

inline Vector3 Matrix4::getLeftVector( void ) const
{
	return Vector3( -m11, -m12, -m13 );
}

inline Vector3 Matrix4::getRightVector( void ) const
{
	return Vector3( m11, m12, m13 );
}

inline Vector3 Matrix4::getForwardVector( void ) const
{
	return Vector3( -m31, -m32, -m33 );
}

inline Vector3 Matrix4::getBackVector( void ) const
{
	return Vector3( m31, m32, m33 );
}

inline void Matrix4::setTranslation( float x, float y, float z )
{
	Vector3 t( x, y, z );
	magicalMatrix4SetTranslation( this, ( &t ) );
}

inline void Matrix4::setTranslation( const Vector3& t )
{
	magicalMatrix4SetTranslation( this, ( &t ) );
}

inline Vector3 Matrix4::getTranslation( void ) const
{
	Vector3 ret;
	magicalMatrix4GetTranslation( &ret, this );
	return ret;
}

inline Vector3 Matrix4::getScale( void ) const
{
	Vector3 ret;
	magicalMatrix4GetScale( &ret, this );
	return ret;
}

inline Quaternion Matrix4::getRotationQuaternion( void ) const
{
	Quaternion ret;
	magicalMatrix4GetRotationQuaternion( &ret, this );
	return ret;
}

inline bool Matrix4::inverse( void )
{
	return magicalMatrix4Inverse( this, this );
}

inline void Matrix4::transpose( void )
{
	magicalMatrix4Transpose( this, this );
}

inline void Matrix4::negate( void )
{
	magicalMatrix4Negate( this, this );
}

inline bool Matrix4::getInversed( Matrix4& out ) const
{
	return magicalMatrix4Inverse( &out, this );
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