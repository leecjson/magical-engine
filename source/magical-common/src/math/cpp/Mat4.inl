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
		m,
		rm11, rm12, rm13, rm14,
		rm21, rm22, rm23, rm24,
		rm31, rm32, rm33, rm34,
		rm41, rm42, rm43, rm44 
	);
}

inline bool Mat4::operator==( const Mat4& mat ) const
{
	return magicalMat4Equals( m, mat.m );
}

inline bool Mat4::operator!=( const Mat4& mat ) const
{
	return !magicalMat4Equals( m, mat.m );
}

inline bool Mat4::isIdentity( void ) const
{
	return magicalMat4IsIdentity( m );
}

inline bool Mat4::isEquals( const Mat4& mat ) const
{
	return magicalMat4Equals( m, mat.m );
}

inline Mat4 Mat4::operator*( const float a ) const
{
	Mat4 ret;
	magicalMat4MulScalar( ret.m, m, a );
	return ret;
}

inline Mat4 Mat4::operator*( const Mat4& mat ) const
{
	Mat4 ret;
	magicalMat4Mul( ret.m, m, mat.m );
	return ret;
}

inline Mat4& Mat4::operator*=( const float a )
{
	magicalMat4MulScalar( m, m, a );
	return *this;
}

inline Mat4& Mat4::operator*=( const Mat4& mat )
{
	magicalMat4Mul( m, m, mat.m );
	return *this;
}

inline Mat4& Mat4::operator=( const Mat4& mat )
{
	magicalMat4Fill( m, mat.m );
	return *this;
}

inline Mat4 Mat4::mul( const float a ) const
{
	Mat4 ret;
	magicalMat4MulScalar( ret.m, m, a );
	return ret;
}

inline Mat4 Mat4::mul( const Mat4& mat ) const
{
	Mat4 ret;
	magicalMat4Mul( ret.m, m, mat.m );
	return ret;
}

inline void Mat4::mulfill( const float a )
{
	magicalMat4MulScalar( m, m, a );
}

inline void Mat4::mulfill( const Mat4& mat )
{
	magicalMat4Mul( m, m, mat.m );
}

inline Vec3 Mat4::transformVec3( const Vec3& v ) const
{
	Vec3 ret;
	magicalMat4TransformVec3( TOFLOAT( &ret ), m, TOFLOAT( &v ) );
	return ret;
}

inline Vec4 Mat4::transformVec4( const Vec4& v ) const
{
	Vec4 ret;
	magicalMat4TransformVec4( TOFLOAT( &ret ), m, TOFLOAT( &v ) );
	return ret;
}

inline void Mat4::fill( const float* mat )
{
	magicalMat4FillVector( m, mat );
}

inline void Mat4::fill( const Mat4& mat )
{
	magicalMat4Fill( m, mat.m );
}

inline void Mat4::fillIdentity( void )
{
	magicalMat4FillIdentity( m );
}

inline void Mat4::fillTranslation( const float x, const float y, const float z )
{
	magicalMat4FillTranslation( m, x, y, z );
}

inline void Mat4::fillTranslation( const Vec3& t )
{
	magicalMat4FillTranslationVector( m, TOFLOAT( &t ) );
}

inline void Mat4::fillScaling( const float x, const float y, const float z )
{
	magicalMat4FillScaling( m, x, y, z );
}

inline void Mat4::fillScaling( const Vec3& s )
{
    magicalMat4FillScalingVector( m, TOFLOAT( &s ) );
}

inline void Mat4::fillRotationX( const float angle )
{
	magicalMat4FillRotationX( m, angle );
}

inline void Mat4::fillRotationY( const float angle )
{
	magicalMat4FillRotationY( m, angle );
}

inline void Mat4::fillRotationZ( const float angle )
{
	magicalMat4FillRotationZ( m, angle );
}

inline void Mat4::fillRotationPitchYawRoll( const float pitch, const float yaw, const float roll )
{
	magicalMat4FillRotationPitchYawRoll( m, pitch, yaw, roll );
}

inline void Mat4::fillRotationQuaternion( const Quaternion& r )
{
	magicalMat4FillRotationQuaternion( m, TOFLOAT( &r ) );
}

inline void Mat4::fillRotationAxisAngle( const Vec3& axis, const float angle )
{
	magicalMat4FillRotationAxisAngle( m, TOFLOAT( &axis ), angle );
}

inline void Mat4::fillLookAt( const Vec3& eye, const Vec3& target, const Vec3& up )
{
	magicalMat4FillLookAt( m, TOFLOAT( &eye ), TOFLOAT( &target ), TOFLOAT( &up ) );
}

inline void Mat4::fillPerspective( const float fov, const float aspect, const float znear, const float zfar )
{
	magicalMat4FillPerspective( m, fov, aspect, znear, zfar );
}

inline void Mat4::fillOrthographic( const float left, const float right, const float bottom, const float top, const float near, const float far )
{
	magicalMat4FillOrthographic( m, left, right, bottom, top, near, far );
}

inline void Mat4::translate( const float x, const float y, const float z )
{
	magicalMat4Translate( m, m, x, y, z );
}

inline void Mat4::translate( const Vec3& t )
{
	magicalMat4TranslateVector( m, m, TOFLOAT( &t ) );
}

inline void Mat4::scale( const float x, const float y, const float z )
{
	magicalMat4Scale( m, m, x, y, z );
}

inline void Mat4::scale( const Vec3& s )
{
	magicalMat4ScaleVector( m, m, TOFLOAT( &s ) );
}

inline void Mat4::rotateX( const float angle )
{
	magicalMat4RotateX( m, m, angle );
}

inline void Mat4::rotateY( const float angle )
{
	magicalMat4RotateY( m, m, angle );
}

inline void Mat4::rotateZ( const float angle )
{
	magicalMat4RotateZ( m, m, angle );
}

inline void Mat4::rotatePitchYawRoll( const float pitch, const float yaw, const float roll )
{
	magicalMat4RotatePitchYawRoll( m, m, pitch, yaw, roll );
}

inline void Mat4::rotateQuaternion( const Quaternion& r )
{
	magicalMat4RotateQuaternion( m, m, TOFLOAT( &r ) );
}

inline void Mat4::rotateAxisAngle( const Vec3& axis, const float angle )
{
	magicalMat4RotateAxisAngle( m, m, TOFLOAT( &axis ), angle );
}

inline float Mat4::determinant( void ) const
{
	return magicalMat4Determinant( m );
}

inline bool Mat4::inverse( Mat4& out ) const
{
	return magicalMat4Inverse( out.m, m );
}

inline Mat4 Mat4::transpose( void ) const
{
	Mat4 dst;
	magicalMat4Transpose( dst.m, m );
	return dst;
}

inline void Mat4::fillTranspose( void )
{
	magicalMat4Transpose( m, m );
}

inline Mat4 Mat4::negate( void ) const
{
	Mat4 dst;
	magicalMat4Negate( dst.m, m );
	return dst;
}

inline void Mat4::fillNegate( void )
{
	magicalMat4Negate( m, m );
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

//inline Vec3 Mat4::getTranslation( void ) const
//{
//	Vec3 translation;
//	decompose( &translation, nullptr, nullptr );
//	return translation;
//}
//
//inline Quaternion Mat4::getRotation( void ) const
//{
//	Quaternion rotation;
//	decompose( nullptr, &rotation, nullptr );
//	return rotation;
//}
//
//inline Vec3 Mat4::getScale( void ) const
//{
//	Vec3 scale;
//	decompose( nullptr, nullptr, &scale );
//	return scale;
//}

inline void MathMat4::mul( Mat4& out, const Mat4& mat, const float a )
{
	magicalMat4MulScalar( out.m, mat.m, a );
}

inline void MathMat4::mul( Mat4& out, const Mat4& mat1, const Mat4& mat2 )
{
	magicalMat4Mul( out.m, mat1.m, mat2.m );
}

inline void MathMat4::transformVec3( Vec3& out, const Mat4& mat, const Vec3& v )
{
	magicalMat4TransformVec3( TOFLOAT( &out ), mat.m, TOFLOAT( &v ) );
}

inline void MathMat4::transformVec4( Vec4& out, const Mat4& mat, const Vec4& v )
{
	magicalMat4TransformVec4( TOFLOAT( &out ), mat.m, TOFLOAT( &v ) );
}

inline void MathMat4::transpose( Mat4& out, const Mat4& mat )
{
	magicalMat4Transpose( out.m, mat.m );
}

inline void MathMat4::negate( Mat4& out, const Mat4& mat )
{
	magicalMat4Negate( out.m, mat.m );
}

inline bool MathMat4::inverse( Mat4& out, const Mat4& mat )
{
	return magicalMat4Inverse( out.m, mat.m );
}

inline void MathMat4::translate( Mat4& out, const Mat4& mat, const float x, const float y, const float z )
{
	magicalMat4Translate( out.m, mat.m, x, y, z );
}

inline void MathMat4::translate( Mat4& out, const Mat4& mat, const Vec3& t )
{
	magicalMat4TranslateVector( out.m, mat.m, TOFLOAT( &t ) );
}

inline void MathMat4::scale( Mat4& out, const Mat4& mat, const float x, const float y, const float z )
{
	magicalMat4Scale( out.m, mat.m, x, y, z );
}

inline void MathMat4::scale( Mat4& out, const Mat4& mat, const Vec3& s )
{
	magicalMat4ScaleVector( out.m, mat.m, TOFLOAT( &s ) );
}

inline void MathMat4::rotateX( Mat4& out, const Mat4& mat, const float angle )
{
	magicalMat4RotateX( out.m, mat.m, angle );
}

inline void MathMat4::rotateY( Mat4& out, const Mat4& mat, const float angle )
{
	magicalMat4RotateY( out.m, mat.m, angle );
}

inline void MathMat4::rotateZ( Mat4& out, const Mat4& mat, const float angle )
{
	magicalMat4RotateZ( out.m, mat.m, angle );
}

inline void MathMat4::rotatePitchYawRoll( Mat4& out, const Mat4& mat, const float pitch, const float yaw, const float roll )
{
	magicalMat4RotatePitchYawRoll( out.m, mat.m, pitch, yaw, roll );
}

inline void MathMat4::rotateQuaternion( Mat4& out, const Mat4& mat, const Quaternion& r )
{
	magicalMat4RotateQuaternion( out.m, mat.m, TOFLOAT( &r ) );
}

inline void MathMat4::rotateAxisAngle( Mat4& out, const Mat4& mat, const Vec3& axis, const float angle )
{
	magicalMat4RotateAxisAngle( out.m, mat.m, TOFLOAT( &axis ), angle );
}

inline void MathMat4::getUpVector( Vec3& out, const Mat4& mat )
{
	magicalMat4GetUpVector( TOFLOAT( &out ), mat.m );
}

inline void MathMat4::getDownVector( Vec3& out, const Mat4& mat )
{
	magicalMat4GetDownVector( TOFLOAT( &out ), mat.m );
}

inline void MathMat4::getLeftVector( Vec3& out, const Mat4& mat )
{
	magicalMat4GetLeftVector( TOFLOAT( &out ), mat.m );
}

inline void MathMat4::getRightVector( Vec3& out, const Mat4& mat )
{
	magicalMat4GetRightVector( TOFLOAT( &out ), mat.m );
}

inline void MathMat4::getForwardVector( Vec3& out, const Mat4& mat )
{
	magicalMat4GetForwardVector( TOFLOAT( &out ), mat.m );
}

inline void MathMat4::getBackVector( Vec3& out, const Mat4& mat )
{
	magicalMat4GetBackVector( TOFLOAT( &out ), mat.m );
}