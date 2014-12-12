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

//inline void Matrix4::fill(
//	const float rm11, const float rm12, const float rm13, const float rm14,
//	const float rm21, const float rm22, const float rm23, const float rm24,
//	const float rm31, const float rm32, const float rm33, const float rm34,
//	const float rm41, const float rm42, const float rm43, const float rm44 )
//{
//	/*magicalMatrix4FillScalars(
//		tofpointer( this ),
//		rm11, rm12, rm13, rm14,
//		rm21, rm22, rm23, rm24,
//		rm31, rm32, rm33, rm34,
//		rm41, rm42, rm43, rm44
//		);*/
//}

inline Matrix4 Matrix4::fromIdentity( void )
{
	return Matrix4::Identity;
}

inline Matrix4 Matrix4::fromZero( void )
{
	return Matrix4::Zero;
}

inline void Matrix4::mulScalar( Matrix4& out, const Matrix4& m, const float a )
{
	magicalMatrix4MulScalar( tofpointer( &out ), tofpointer( &m ), a );
}

inline void Matrix4::mul( Matrix4& out, const Matrix4& m1, const Matrix4& m2 )
{
	magicalMatrix4Mul( tofpointer( &out ), tofpointer( &m1 ), tofpointer( &m2 ) );
}

inline void Matrix4::translate( Matrix4& out, const Matrix4& m, const float x, const float y, const float z )
{
	magicalMatrix4Translate( tofpointer( &out ), tofpointer( &m ), x, y, z );
}

inline void Matrix4::translate( Matrix4& out, const Matrix4& m, const Vector3& t )
{
	magicalMatrix4TranslateVector( tofpointer( &out ), tofpointer( &m ), tofpointer( &t ) );
}

inline void Matrix4::scale( Matrix4& out, const Matrix4& m, const float x, const float y, const float z )
{
	magicalMatrix4Scale( tofpointer( &out ), tofpointer( &m ), x, y, z );
}

inline void Matrix4::scale( Matrix4& out, const Matrix4& m, const Vector3& s )
{
	magicalMatrix4ScaleVector( tofpointer( &out ), tofpointer( &m ), tofpointer( &s ) );
}

inline void Matrix4::rotateX( Matrix4& out, const Matrix4& m, const float angle )
{
	magicalMatrix4RotateX( tofpointer( &out ), tofpointer( &m ), angle );
}

inline void Matrix4::rotateY( Matrix4& out, const Matrix4& m, const float angle )
{
	magicalMatrix4RotateY( tofpointer( &out ), tofpointer( &m ), angle );
}

inline void Matrix4::rotateZ( Matrix4& out, const Matrix4& m, const float angle )
{
	magicalMatrix4RotateZ( tofpointer( &out ), tofpointer( &m ), angle );
}

inline void Matrix4::rotateAxisA( Matrix4& out, const Matrix4& m, const Vector3& axis, const float angle )
{
	AxisA aa( axis, angle );
	magicalMatrix4RotateAxisA( tofpointer( &out ), tofpointer( &m ), tofpointer( &aa ) );
}

inline void Matrix4::rotateAxisA( Matrix4& out, const Matrix4& m, const AxisA& aa )
{
	magicalMatrix4RotateAxisA( tofpointer( &out ), tofpointer( &m ), tofpointer( &aa ) );
}

inline void Matrix4::rotateEulerA( Matrix4& out, const Matrix4& m, const float yaw, const float pitch, const float roll )
{
	EulerA ea( yaw, pitch, roll );
	magicalMatrix4RotateEulerA( tofpointer( &out ), tofpointer( &m ), tofpointer( &ea ) );
}

inline void Matrix4::rotateEulerA( Matrix4& out, const Matrix4& m, const EulerA& ea )
{
	magicalMatrix4RotateEulerA( tofpointer( &out ), tofpointer( &m ), tofpointer( &ea ) );
}

inline void Matrix4::rotateQuaternion( Matrix4& out, const Matrix4& m, const Quaternion& q )
{
	magicalMatrix4RotateQuaternion( tofpointer( &out ), tofpointer( &m ), tofpointer( &q ) );
}

inline void Matrix4::getUpVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetUpVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Matrix4::getDownVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetDownVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Matrix4::getLeftVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetLeftVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Matrix4::getRightVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetRightVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Matrix4::getForwardVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetForwardVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Matrix4::getBackVector( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetBackVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Matrix4::getTranslation( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetTranslation( tofpointer( &out ), tofpointer( &m ) );
}

inline void Matrix4::getScale( Vector3& out, const Matrix4& m )
{
	magicalMatrix4GetScale( tofpointer( &out ), tofpointer( &m ) );
}

inline void Matrix4::getRotationQuaternion( Quaternion& out, const Matrix4& m )
{
	magicalMatrix4GetRotationQuaternion( tofpointer( &out ), tofpointer( &m ) );
}

inline bool Matrix4::inverse( Matrix4& out, const Matrix4& m )
{
	return magicalMatrix4Inverse( tofpointer( &out ), tofpointer( &m ) );
}

inline void Matrix4::transpose( Matrix4& out, const Matrix4& m )
{
	magicalMatrix4Transpose( tofpointer( &out ), tofpointer( &m ) );
}

inline void Matrix4::negate( Matrix4& out, const Matrix4& m )
{
	magicalMatrix4Negate( tofpointer( &out ), tofpointer( &m ) );
}

inline bool Matrix4::equals( const Matrix4& m ) const
{
	return magicalMatrix4Equals( tofpointer( this ), tofpointer( &m ) );
}

inline bool Matrix4::isIdentity( void ) const
{
	return magicalMatrix4IsIdentity( tofpointer( this ) );
}

inline void Matrix4::fill( const float* m )
{
	magicalMatrix4Fill( tofpointer( this ), m );
}

inline void Matrix4::fill( const Matrix4& m )
{
	magicalMatrix4Fill( tofpointer( this ), tofpointer( &m ) );
}

inline void Matrix4::fillIdentity( void )
{
	magicalMatrix4FillIdentity( tofpointer( this ) );
}

inline void Matrix4::fillTranslation( const float x, const float y, const float z )
{
	magicalMatrix4FillTranslation( tofpointer( this ), x, y, z );
}

inline void Matrix4::fillTranslation( const Vector3& t )
{
	magicalMatrix4FillTranslationVector( tofpointer( this ), tofpointer( &t ) );
}

inline void Matrix4::fillScale( const float x, const float y, const float z )
{
	magicalMatrix4FillScale( tofpointer( this ), x, y, z );
}

inline void Matrix4::fillScale( const Vector3& s )
{
    magicalMatrix4FillScaleVector( tofpointer( this ), tofpointer( &s ) );
}

inline void Matrix4::fillRotationX( const float angle )
{
	magicalMatrix4FillRotationX( tofpointer( this ), angle );
}

inline void Matrix4::fillRotationY( const float angle )
{
	magicalMatrix4FillRotationY( tofpointer( this ), angle );
}

inline void Matrix4::fillRotationZ( const float angle )
{
	magicalMatrix4FillRotationZ( tofpointer( this ), angle );
}

inline void Matrix4::fillRotationAxisA( const Vector3& axis, const float angle )
{
	AxisA aa( axis, angle );
	magicalMatrix4FillRotationAxisA( tofpointer( this ), tofpointer( &aa ) );
}

inline void Matrix4::fillRotationAxisA( const AxisA& aa )
{
	magicalMatrix4FillRotationAxisA( tofpointer( this ), tofpointer( &aa ) );
}

inline void Matrix4::fillRotationEulerA( const float yaw, const float pitch, const float roll )
{
	EulerA ea( yaw, pitch, roll );
	magicalMatrix4FillRotationEulerA( tofpointer( this ), tofpointer( &ea ) );
}

inline void Matrix4::fillRotationEulerA( const EulerA& ea )
{
	magicalMatrix4FillRotationEulerA( tofpointer( this ), tofpointer( &ea ) );
}

inline void Matrix4::fillRotationQuaternion( const Quaternion& q )
{
	magicalMatrix4FillRotationQuaternion( tofpointer( this ), tofpointer( &q ) );
}

inline void Matrix4::fillLookAt( const Vector3& eye, const Vector3& target, const Vector3& up )
{
	magicalMatrix4FillLookAt( tofpointer( this ), tofpointer( &eye ), tofpointer( &target ), tofpointer( &up ) );
}

inline void Matrix4::fillPerspective( const float fov, const float aspect, const float znear, const float zfar )
{
	magicalMatrix4FillPerspective( tofpointer( this ), fov, aspect, znear, zfar );
}

inline void Matrix4::fillOrthographic( const float left, const float right, const float bottom, const float top, const float near, const float far )
{
	magicalMatrix4FillOrthographic( tofpointer( this ), left, right, bottom, top, near, far );
}

inline bool Matrix4::operator==( const Matrix4& m ) const
{
	return magicalMatrix4Equals( tofpointer( this ), tofpointer( &m ) );
}

inline bool Matrix4::operator!=( const Matrix4& m ) const
{
	return !magicalMatrix4Equals( tofpointer( this ), tofpointer( &m ) );
}

inline Matrix4 Matrix4::operator*( const float a ) const
{
	Matrix4 ret;
	magicalMatrix4MulScalar( tofpointer( &ret ), tofpointer( this ), a );
	return ret;
}

inline float Matrix4::operator[]( const unsigned int i ) const
{
#if MAGICAL_DEBUG
	assert( 0 <= i && i <= 15 && "index out of range" );
#endif
	return ((float*)this)[i];
}

inline Matrix4 Matrix4::operator*( const Matrix4& m ) const
{
	Matrix4 ret;
	magicalMatrix4Mul( tofpointer( &ret ), tofpointer( this ), tofpointer( &m ) );
	return ret;
}

inline Matrix4& Matrix4::operator*=( const float a )
{
	magicalMatrix4MulScalar( tofpointer( this ), tofpointer( this ), a );
	return *this;
}

inline Matrix4& Matrix4::operator*=( const Matrix4& m )
{
	magicalMatrix4Mul( tofpointer( this ), tofpointer( this ), tofpointer( &m ) );
	return *this;
}

inline Matrix4& Matrix4::operator=( const Matrix4& m )
{
	magicalMatrix4Fill( tofpointer( this ), tofpointer( &m ) );
	return *this;
}

inline void Matrix4::translate( const float x, const float y, const float z )
{
	magicalMatrix4Translate( tofpointer( this ), tofpointer( this ), x, y, z );
}

inline void Matrix4::translate( const Vector3& t )
{
	magicalMatrix4TranslateVector( tofpointer( this ), tofpointer( this ), tofpointer( &t ) );
}

inline void Matrix4::scale( const float x, const float y, const float z )
{
	magicalMatrix4Scale( tofpointer( this ), tofpointer( this ), x, y, z );
}

inline void Matrix4::scale( const Vector3& s )
{
	magicalMatrix4ScaleVector( tofpointer( this ), tofpointer( this ), tofpointer( &s ) );
}

inline void Matrix4::rotateX( const float angle )
{
	magicalMatrix4RotateX( tofpointer( this ), tofpointer( this ), angle );
}

inline void Matrix4::rotateY( const float angle )
{
	magicalMatrix4RotateY( tofpointer( this ), tofpointer( this ), angle );
}

inline void Matrix4::rotateZ( const float angle )
{
	magicalMatrix4RotateZ( tofpointer( this ), tofpointer( this ), angle );
}

inline void Matrix4::rotateAxisA( const Vector3& axis, const float angle )
{
	AxisA aa( axis, angle );
	magicalMatrix4RotateAxisA( tofpointer( this ), tofpointer( this ), tofpointer( &aa ) );
}

inline void Matrix4::rotateAxisA( const AxisA& aa )
{
	magicalMatrix4RotateAxisA( tofpointer( this ), tofpointer( this ), tofpointer( &aa ) );
}

inline void Matrix4::rotateEulerA( const float yaw, const float pitch, const float roll )
{
	EulerA ea( yaw, pitch, roll );
	magicalMatrix4RotateEulerA( tofpointer( this ), tofpointer( this ), tofpointer( &ea ) );
}

inline void Matrix4::rotateEulerA( const EulerA& ea )
{
	magicalMatrix4RotateEulerA( tofpointer( this ), tofpointer( this ), tofpointer( &ea ) );
}

inline void Matrix4::rotateQuaternion( const Quaternion& q )
{
	magicalMatrix4RotateQuaternion( tofpointer( this ), tofpointer( this ), tofpointer( &q ) );
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

inline void Matrix4::setTranslation( const float x, const float y, const float z )
{
	magicalMatrix4SetTranslation( tofpointer( this ), x, y, z );
}

inline Vector3 Matrix4::getTranslation( void ) const
{
	Vector3 ret;
	magicalMatrix4GetTranslation( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vector3 Matrix4::getScale( void ) const
{
	Vector3 ret;
	magicalMatrix4GetScale( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Quaternion Matrix4::getRotationQuaternion( void ) const
{
	Quaternion ret;
	magicalMatrix4GetRotationQuaternion( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline bool Matrix4::inverse( void )
{
	return magicalMatrix4Inverse( tofpointer( this ), tofpointer( this ) );
}

inline void Matrix4::transpose( void )
{
	magicalMatrix4Transpose( tofpointer( this ), tofpointer( this ) );
}

inline void Matrix4::negate( void )
{
	magicalMatrix4Negate( tofpointer( this ), tofpointer( this ) );
}

inline bool Matrix4::getInversed( Matrix4& out ) const
{
	return magicalMatrix4Inverse( tofpointer( &out ), tofpointer( this ) );
}

inline Matrix4 Matrix4::getTransposed( void ) const
{
	Matrix4 ret;
	magicalMatrix4Transpose( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Matrix4 Matrix4::getNegated( void ) const
{
	Matrix4 ret;
	magicalMatrix4Negate( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline float Matrix4::determinant( void ) const
{
	return magicalMatrix4Determinant( tofpointer( this ) );
}