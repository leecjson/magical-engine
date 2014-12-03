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

inline void Mat4::fill(
	const float rm11, const float rm12, const float rm13, const float rm14,
	const float rm21, const float rm22, const float rm23, const float rm24,
	const float rm31, const float rm32, const float rm33, const float rm34,
	const float rm41, const float rm42, const float rm43, const float rm44 )
{
	magicalMat4FillScalars(
		tofpointer( this ),
		rm11, rm12, rm13, rm14,
		rm21, rm22, rm23, rm24,
		rm31, rm32, rm33, rm34,
		rm41, rm42, rm43, rm44
		);
}

inline void Mat4::mul( Mat4& out, const Mat4& m, const float a )
{
	magicalMat4MulScalar( tofpointer( &out ), tofpointer( &m ), a );
}

inline void Mat4::mul( Mat4& out, const Mat4& m1, const Mat4& m2 )
{
	magicalMat4Mul( tofpointer( &out ), tofpointer( &m1 ), tofpointer( &m2 ) );
}

inline void Mat4::translate( Mat4& out, const Mat4& m, const float x, const float y, const float z )
{
	magicalMat4Translate( tofpointer( &out ), tofpointer( &m ), x, y, z );
}

inline void Mat4::translate( Mat4& out, const Mat4& m, const Vec3& t )
{
	magicalMat4TranslateVector( tofpointer( &out ), tofpointer( &m ), tofpointer( &t ) );
}

inline void Mat4::scale( Mat4& out, const Mat4& m, const float x, const float y, const float z )
{
	magicalMat4Scale( tofpointer( &out ), tofpointer( &m ), x, y, z );
}

inline void Mat4::scale( Mat4& out, const Mat4& m, const Vec3& s )
{
	magicalMat4ScaleVector( tofpointer( &out ), tofpointer( &m ), tofpointer( &s ) );
}

inline void Mat4::rotateX( Mat4& out, const Mat4& m, const float angle )
{
	magicalMat4RotateX( tofpointer( &out ), tofpointer( &m ), angle );
}

inline void Mat4::rotateY( Mat4& out, const Mat4& m, const float angle )
{
	magicalMat4RotateY( tofpointer( &out ), tofpointer( &m ), angle );
}

inline void Mat4::rotateZ( Mat4& out, const Mat4& m, const float angle )
{
	magicalMat4RotateZ( tofpointer( &out ), tofpointer( &m ), angle );
}

inline void Mat4::rotateQuaternion( Mat4& out, const Mat4& m, const Quaternion& q )
{
	magicalMat4RotateQuaternion( tofpointer( &out ), tofpointer( &m ), tofpointer( &q ) );
}

inline void Mat4::rotateEulerAngles( Mat4& out, const Mat4& m, const float yaw, const float pitch, const float roll )
{
	magicalMat4RotateEulerYawPitchRoll( tofpointer( &out ), tofpointer( &m ), yaw, pitch, roll );
}

inline void Mat4::rotateEulerAngles( Mat4& out, const Mat4& m, const EulerAngles& ea )
{
	magicalMat4RotateEulerAngles( tofpointer( &out ), tofpointer( &m ), tofpointer( &ea ) );
}

inline void Mat4::rotateAxisAngle( Mat4& out, const Mat4& m, const Vec3& axis, const float angle )
{
	magicalMat4RotateAxisAngleScalar( tofpointer( &out ), tofpointer( &m ), tofpointer( &axis ), angle );
}

inline void Mat4::rotateAxisAngle( Mat4& out, const Mat4& m, const AxisAngle& aa )
{
	magicalMat4RotateAxisAngle( tofpointer( &out ), tofpointer( &m ), tofpointer( &aa ) );
}

inline void Mat4::getUpVector( Vec3& out, const Mat4& m )
{
	magicalMat4GetUpVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Mat4::getDownVector( Vec3& out, const Mat4& m )
{
	magicalMat4GetDownVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Mat4::getLeftVector( Vec3& out, const Mat4& m )
{
	magicalMat4GetLeftVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Mat4::getRightVector( Vec3& out, const Mat4& m )
{
	magicalMat4GetRightVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Mat4::getForwardVector( Vec3& out, const Mat4& m )
{
	magicalMat4GetForwardVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Mat4::getBackVector( Vec3& out, const Mat4& m )
{
	magicalMat4GetBackVector( tofpointer( &out ), tofpointer( &m ) );
}

inline void Mat4::getTranslation( Vec3& out, const Mat4& m )
{
	magicalMat4GetTranslation( tofpointer( &out ), tofpointer( &m ) );
}

inline void Mat4::getScale( Vec3& out, const Mat4& m )
{
	magicalMat4GetScale( tofpointer( &out ), tofpointer( &m ) );
}

inline void Mat4::getRotationQuaternion( Quaternion& out, const Mat4& m )
{
	magicalMat4GetRotationQuaternion( tofpointer( &out ), tofpointer( &m ) );
}

inline bool Mat4::inverse( Mat4& out, const Mat4& m )
{
	return magicalMat4Inverse( tofpointer( &out ), tofpointer( &m ) );
}

inline void Mat4::transpose( Mat4& out, const Mat4& m )
{
	magicalMat4Transpose( tofpointer( &out ), tofpointer( &m ) );
}

inline void Mat4::negate( Mat4& out, const Mat4& m )
{
	magicalMat4Negate( tofpointer( &out ), tofpointer( &m ) );
}

inline bool Mat4::operator==( const Mat4& m ) const
{
	return magicalMat4Equals( tofpointer( this ), tofpointer( &m ) );
}

inline bool Mat4::operator!=( const Mat4& m ) const
{
	return !magicalMat4Equals( tofpointer( this ), tofpointer( &m ) );
}

inline Mat4 Mat4::operator*( const float a ) const
{
	Mat4 ret;
	magicalMat4MulScalar( tofpointer( &ret ), tofpointer( this ), a );
	return ret;
}

inline Mat4 Mat4::operator*( const Mat4& m ) const
{
	Mat4 ret;
	magicalMat4Mul( tofpointer( &ret ), tofpointer( this ), tofpointer( &m ) );
	return ret;
}

inline Mat4& Mat4::operator*=( const float a )
{
	magicalMat4MulScalar( tofpointer( this ), tofpointer( this ), a );
	return *this;
}

inline Mat4& Mat4::operator*=( const Mat4& m )
{
	magicalMat4Mul( tofpointer( this ), tofpointer( this ), tofpointer( &m ) );
	return *this;
}

inline Mat4& Mat4::operator=( const Mat4& m )
{
	magicalMat4Fill( tofpointer( this ), tofpointer( &m ) );
	return *this;
}

inline bool Mat4::isEquals( const Mat4& m ) const
{
	return magicalMat4Equals( tofpointer( this ), tofpointer( &m ) );
}

inline bool Mat4::isIdentity( void ) const
{
	return magicalMat4IsIdentity( tofpointer( this ) );
}

inline void Mat4::fill( const float* m )
{
	magicalMat4FillVector( tofpointer( this ), m );
}

inline void Mat4::fill( const Mat4& m )
{
	magicalMat4Fill( tofpointer( this ), tofpointer( &m ) );
}

inline void Mat4::fillIdentity( void )
{
	magicalMat4FillIdentity( tofpointer( this ) );
}

inline void Mat4::fillTranslation( const float x, const float y, const float z )
{
	magicalMat4FillTranslation( tofpointer( this ), x, y, z );
}

inline void Mat4::fillTranslation( const Vec3& t )
{
	magicalMat4FillTranslationVector( tofpointer( this ), tofpointer( &t ) );
}

inline void Mat4::fillScale( const float x, const float y, const float z )
{
	magicalMat4FillScale( tofpointer( this ), x, y, z );
}

inline void Mat4::fillScale( const Vec3& s )
{
    magicalMat4FillScaleVector( tofpointer( this ), tofpointer( &s ) );
}

inline void Mat4::fillRotationX( const float angle )
{
	magicalMat4FillRotationX( tofpointer( this ), angle );
}

inline void Mat4::fillRotationY( const float angle )
{
	magicalMat4FillRotationY( tofpointer( this ), angle );
}

inline void Mat4::fillRotationZ( const float angle )
{
	magicalMat4FillRotationZ( tofpointer( this ), angle );
}

inline void Mat4::fillRotationQuaternion( const Quaternion& q )
{
	magicalMat4FillRotationQuaternion( tofpointer( this ), tofpointer( &q ) );
}

inline void Mat4::fillRotationEulerAngles( const float yaw, const float pitch, const float roll )
{
	magicalMat4FillRotationEulerYawPitchRoll( tofpointer( this ), yaw, pitch, roll );
}

inline void Mat4::fillRotationEulerAngles( const EulerAngles& ea )
{
	magicalMat4FillRotationEulerAngles( tofpointer( this ), tofpointer( &ea ) );
}

inline void Mat4::fillRotationAxisAngle( const Vec3& axis, const float angle )
{
	magicalMat4FillRotationAxisAngleScalar( tofpointer( this ), tofpointer( &axis ), angle );
}

inline void Mat4::fillRotationAxisAngle( const AxisAngle& aa )
{
	magicalMat4FillRotationAxisAngle( tofpointer( this ), tofpointer( &aa ) );
}

inline void Mat4::fillLookAt( const Vec3& eye, const Vec3& target, const Vec3& up )
{
	magicalMat4FillLookAt( tofpointer( this ), tofpointer( &eye ), tofpointer( &target ), tofpointer( &up ) );
}

inline void Mat4::fillPerspective( const float fov, const float aspect, const float znear, const float zfar )
{
	magicalMat4FillPerspective( tofpointer( this ), fov, aspect, znear, zfar );
}

inline void Mat4::fillOrthographic( const float left, const float right, const float bottom, const float top, const float near, const float far )
{
	magicalMat4FillOrthographic( tofpointer( this ), left, right, bottom, top, near, far );
}

inline void Mat4::translate( const float x, const float y, const float z )
{
	magicalMat4Translate( tofpointer( this ), tofpointer( this ), x, y, z );
}

inline void Mat4::translate( const Vec3& t )
{
	magicalMat4TranslateVector( tofpointer( this ), tofpointer( this ), tofpointer( &t ) );
}

inline void Mat4::scale( const float x, const float y, const float z )
{
	magicalMat4Scale( tofpointer( this ), tofpointer( this ), x, y, z );
}

inline void Mat4::scale( const Vec3& s )
{
	magicalMat4ScaleVector( tofpointer( this ), tofpointer( this ), tofpointer( &s ) );
}

inline void Mat4::rotateX( const float angle )
{
	magicalMat4RotateX( tofpointer( this ), tofpointer( this ), angle );
}

inline void Mat4::rotateY( const float angle )
{
	magicalMat4RotateY( tofpointer( this ), tofpointer( this ), angle );
}

inline void Mat4::rotateZ( const float angle )
{
	magicalMat4RotateZ( tofpointer( this ), tofpointer( this ), angle );
}

inline void Mat4::rotateQuaternion( const Quaternion& q )
{
	magicalMat4RotateQuaternion( tofpointer( this ), tofpointer( this ), tofpointer( &q ) );
}

inline void Mat4::rotateEulerAngles( const float yaw, const float pitch, const float roll )
{
	magicalMat4RotateEulerYawPitchRoll( tofpointer( this ), tofpointer( this ), yaw, pitch, roll );
}

inline void Mat4::rotateEulerAngles( const EulerAngles& ea )
{
	magicalMat4RotateEulerAngles( tofpointer( this ), tofpointer( this ), tofpointer( &ea ) );
}

inline void Mat4::rotateAxisAngle( const Vec3& axis, const float angle )
{
	magicalMat4RotateAxisAngleScalar( tofpointer( this ), tofpointer( this ), tofpointer( &axis ), angle );
}

inline void Mat4::rotateAxisAngle( const AxisAngle& aa )
{
	magicalMat4RotateAxisAngle( tofpointer( this ), tofpointer( this ), tofpointer( &aa ) );
}

inline Vec3 Mat4::getUpVector( void ) const
{
	return Vec3( m21, m22, m23 );
}

inline Vec3 Mat4::getDownVector( void ) const
{
	return Vec3( -m21, -m22, -m23 );
}

inline Vec3 Mat4::getLeftVector( void ) const
{
	return Vec3( -m11, -m12, -m13 );
}

inline Vec3 Mat4::getRightVector( void ) const
{
	return Vec3( m11, m12, m13 );
}

inline Vec3 Mat4::getForwardVector( void ) const
{
	return Vec3( -m31, -m32, -m33 );
}

inline Vec3 Mat4::getBackVector( void ) const
{
	return Vec3( m31, m32, m33 );
}

inline void Mat4::setTranslation( const float x, const float y, const float z )
{
	magicalMat4SetTranslation( tofpointer( this ), x, y, z );
}

inline Vec3 Mat4::getTranslation( void ) const
{
	Vec3 ret;
	magicalMat4GetTranslation( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Vec3 Mat4::getScale( void ) const
{
	Vec3 ret;
	magicalMat4GetScale( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Quaternion Mat4::getRotationQuaternion( void ) const
{
	Quaternion ret;
	magicalMat4GetRotationQuaternion( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline bool Mat4::inverse( void )
{
	return magicalMat4Inverse( tofpointer( this ), tofpointer( this ) );
}

inline void Mat4::transpose( void )
{
	magicalMat4Transpose( tofpointer( this ), tofpointer( this ) );
}

inline void Mat4::negate( void )
{
	magicalMat4Negate( tofpointer( this ), tofpointer( this ) );
}

inline bool Mat4::getInverse( Mat4& out ) const
{
	return magicalMat4Inverse( tofpointer( &out ), tofpointer( this ) );
}

inline Mat4 Mat4::getTanspose( void ) const
{
	Mat4 ret;
	magicalMat4Transpose( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline Mat4 Mat4::getNegate( void ) const
{
	Mat4 ret;
	magicalMat4Negate( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline float Mat4::determinant( void ) const
{
	return magicalMat4Determinant( tofpointer( this ) );
}