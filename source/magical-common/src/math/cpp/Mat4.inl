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
	float rm11, float rm12, float rm13, float rm14,
	float rm21, float rm22, float rm23, float rm24,
	float rm31, float rm32, float rm33, float rm34,
	float rm41, float rm42, float rm43, float rm44 )
{
	m11 = rm11; m12 = rm12; m13 = rm13; m14 = rm14;
	m21 = rm21; m22 = rm22; m23 = rm23; m24 = rm24;
	m31 = rm31; m32 = rm32; m33 = rm33; m34 = rm34;
	m41 = rm41; m42 = rm42; m43 = rm43; m44 = rm44;
}

inline bool Mat4::operator==( const Mat4& mat ) const
{
	return memcmp( mat.m, m, MAGICAL_MAT4_SIZE ) == 0;
}

inline bool Mat4::operator!=( const Mat4& mat ) const
{
	return !( operator==( mat ) );
}

inline bool Mat4::isIdentity( void ) const
{
	return memcmp( Identity.m, m, MAGICAL_MAT4_SIZE ) == 0;
}

inline bool Mat4::isEquals( const Mat4& mat ) const
{
	return memcmp( mat.m, m, MAGICAL_MAT4_SIZE ) == 0;
}

inline Mat4 Mat4::operator+( float a ) const
{
	return add( a );
}

inline Mat4 Mat4::operator+( const Mat4& mat ) const
{
	return add( mat );
}

inline Mat4 Mat4::operator-( float a ) const
{
	return sub( a );
}

inline Mat4 Mat4::operator-( const Mat4& mat ) const
{
	return sub( mat );
}

inline Mat4 Mat4::operator*( float a ) const
{
	return mul( a );
}

inline Mat4 Mat4::operator*( const Mat4& mat ) const
{
	return mul( mat );
}

inline Mat4& Mat4::operator+=( float a )
{
	addfill( a );
	return *this;
}

inline Mat4& Mat4::operator+=( const Mat4& mat )
{
	addfill( mat );
	return *this;
}

inline Mat4& Mat4::operator-=( float a )
{
	subfill( a );
	return *this;
}

inline Mat4& Mat4::operator-=( const Mat4& mat )
{
	subfill( mat );
	return *this;
}

inline Mat4& Mat4::operator*=( float a )
{
	mulfill( a );
	return *this;
}

inline Mat4& Mat4::operator*=( const Mat4& mat )
{
	mulfill( mat );
	return *this;
}

inline Mat4& Mat4::operator=( const Mat4& mat )
{
	memcpy( m, mat.m, MAGICAL_MAT4_SIZE );
	return *this;
}

inline void Mat4::fill( const float* m )
{
	magicalAssert( m, "should not be nullptr" );
	memcpy( this->m, m, MAGICAL_MAT4_SIZE );
}

inline void Mat4::fill( const Mat4& mat )
{
	memcpy( m, mat.m, MAGICAL_MAT4_SIZE );
}

inline void Mat4::fillZero( void )
{
	memset( m, 0, MAGICAL_MAT4_SIZE );
}

inline void Mat4::fillIdentity( void )
{
	memcpy( m, Identity.m, MAGICAL_MAT4_SIZE );
}

inline void Mat4::fillTranslation( float x, float y, float z )
{
	fillIdentity();

    m41 = x;
    m42 = y;
    m43 = z;
}

inline void Mat4::fillTranslation( const Vec3& t )
{
	fillIdentity();

	m41 = t.x;
	m42 = t.y;
	m43 = t.z;
}

inline void Mat4::fillRotationX( float rad )
{
	fillIdentity();

	float c = magicalCosf( rad );
	float s = magicalSinf( rad );

	m22 = c;
	m23 = s;
	m32 = -s;
	m33 = c;
}

inline void Mat4::fillRotationY( float rad )
{
	fillIdentity();

	float c = magicalCosf( rad );
	float s = magicalSinf( rad );

	m11 = c;
	m13 = -s;
	m31 = s;
	m33 = c;
}

inline void Mat4::fillRotationZ( float rad )
{
	fillIdentity();

	float c = magicalCosf( rad );
	float s = magicalSinf( rad );

	m11 = c;
	m12 = s;
	m21 = -s;
	m22 = c;
}

inline void Mat4::fillScale( float x, float y, float z )
{
	fillIdentity();

    m11 = x;
    m22 = y;
    m33 = z;
}

inline void Mat4::fillScale( const Vec3& s )
{
    fillIdentity();

	m11 = s.x;
	m22 = s.y;
    m33 = s.z;
}

inline void Mat4::translate( float x, float y, float z )
{
	Mat4 dst;
	dst.fillTranslation( x, y, z );
	mulfill( dst );
}

inline void Mat4::translate( const Vec3& t )
{
	Mat4 dst;
	dst.fillTranslation( t );
	mulfill( dst );
}

inline void Mat4::rotateX( float angle )
{
	Mat4 dst;
	dst.fillRotationX( angle );
	mulfill( dst );
}

inline void Mat4::rotateY( float angle )
{
	Mat4 dst;
	dst.fillRotationY( angle );
	mulfill( dst );
}

inline void Mat4::rotateZ( float angle )
{
	Mat4 dst;
	dst.fillRotationZ( angle );
	mulfill( dst );
}

inline void Mat4::rotate( const Quaternion& r )
{
	Mat4 dst;
	dst.fillRotation( r );
	mulfill( dst );
}

inline void Mat4::rotate( const Vec3& axis, float angle )
{
	Mat4 dst;
	dst.fillRotation( axis, angle );
	mulfill( dst );
}

inline void Mat4::scale( float s )
{
	Mat4 dst;
	dst.fillScale( s, s, s );
	mulfill( dst );
}

inline void Mat4::scale( float x, float y, float z )
{
	Mat4 dst;
	dst.fillScale( x, y, z );
	mulfill( dst );
}

inline void Mat4::scale( const Vec3& s )
{
	Mat4 dst;
	dst.fillScale( s );
	mulfill( dst );
}

inline Mat4 Mat4::getTranspose( void ) const
{
	Mat4 dst( *this );
	dst.transpose();
	return dst;
}

inline Mat4 Mat4::getNegate( void ) const
{
	Mat4 dst( *this );
	dst.negate();
	return dst;
}

inline Mat4 Mat4::getTranslate( float x, float y, float z ) const
{
	Mat4 dst( *this );
	dst.translate( x, y, z );
	return dst;
}

inline Mat4 Mat4::getTranslate( const Vec3& t ) const
{
	Mat4 dst( *this );
	dst.translate( t );
	return dst;
}

inline Mat4 Mat4::getRotateX( float angle ) const
{
	Mat4 dst( *this );
	dst.rotateX( angle );
	return dst;
}

inline Mat4 Mat4::getRotateY( float angle ) const
{
	Mat4 dst( *this );
	dst.rotateY( angle );
	return dst;
}

inline Mat4 Mat4::getRotateZ( float angle ) const
{
	Mat4 dst( *this );
	dst.rotateZ( angle );
	return dst;
}

inline Mat4 Mat4::getRotate( const Quaternion& r ) const
{
	Mat4 dst( *this );
	dst.rotate( r );
	return dst;
}

inline Mat4 Mat4::getRotate( const Vec3& axis, float angle ) const
{
	Mat4 dst( *this );
	dst.rotate( axis, angle );
	return dst;
}

inline Mat4 Mat4::getScale( float s ) const
{
	Mat4 dst( *this );
	dst.scale( s );
	return dst;
}

inline Mat4 Mat4::getScale( float x, float y, float z ) const
{
	Mat4 dst( *this );
	dst.scale( x, y, z );
	return dst;
}

inline Mat4 Mat4::getScale( const Vec3& s ) const
{
	Mat4 dst( *this );
	dst.scale( s );
	return dst;
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

inline Vec3 Mat4::transformPoint( const Vec3& point ) const
{
	return transformVec3( point );
}

inline Vec3 Mat4::getTranslation( void ) const
{
	Vec3 translation;
	decompose( &translation, nullptr, nullptr );
	return translation;
}

inline Quaternion Mat4::getRotation( void ) const
{
	Quaternion rotation;
	decompose( nullptr, &rotation, nullptr );
	return rotation;
}

inline Vec3 Mat4::getScale( void ) const
{
	Vec3 scale;
	decompose( nullptr, nullptr, &scale );
	return scale;
}

inline bool MathMat4::getInverse( Mat4& out, const Mat4& mat )
{
	return mat.getInverse( out );
}

inline void MathMat4::translate( Mat4& out, const Mat4& mat, float x, float y, float z )
{
	Mat4 dst;
	dst.fillTranslation( x, y, z );
	mul( out, mat, dst );
}

inline void MathMat4::translate( Mat4& out, const Mat4& mat, const Vec3& t )
{
	Mat4 dst;
	dst.fillTranslation( t );
	mul( out, mat, dst );
}

inline void MathMat4::rotateX( Mat4& out, const Mat4& mat, float angle )
{
	Mat4 dst;
	dst.fillRotationX( angle );
	mul( out, mat, dst );
}

inline void MathMat4::rotateY( Mat4& out, const Mat4& mat, float angle )
{
	Mat4 dst;
	dst.fillRotationY( angle );
	mul( out, mat, dst );
}

inline void MathMat4::rotateZ( Mat4& out, const Mat4& mat, float angle )
{
	Mat4 dst;
	dst.fillRotationZ( angle );
	mul( out, mat, dst );
}

inline void MathMat4::rotate( Mat4& out, const Mat4& mat, const Quaternion& r )
{
	Mat4 dst;
	dst.fillRotation( r );
	mul( out, mat, dst );
}

inline void MathMat4::rotate( Mat4& out, const Mat4& mat, const Vec3& axis, float angle )
{
	Mat4 dst;
	dst.fillRotation( axis, angle );
	mul( out, mat, dst );
}

inline void MathMat4::scale( Mat4& out, const Mat4& mat, float s )
{
	Mat4 dst;
	dst.fillScale( s, s, s );
	mul( out, mat, dst );
}

inline void MathMat4::scale( Mat4& out, const Mat4& mat, float x, float y, float z )
{
	Mat4 dst;
	dst.fillScale( x, y, z );
	mul( out, mat, dst );
}

inline void MathMat4::scale( Mat4& out, const Mat4& mat, const Vec3& s )
{
	Mat4 dst;
	dst.fillScale( s );
	mul( out, mat, dst );
}

inline void MathMat4::getUpVector( Vec3& out, const Mat4& mat )
{
	out = mat.getUpVector();
}

inline void MathMat4::getDownVector( Vec3& out, const Mat4& mat )
{
	out = mat.getDownVector();
}

inline void MathMat4::getLeftVector( Vec3& out, const Mat4& mat )
{
	out = mat.getLeftVector();
}

inline void MathMat4::getRightVector( Vec3& out, const Mat4& mat )
{
	out = mat.getRightVector();
}

inline void MathMat4::getForwardVector( Vec3& out, const Mat4& mat )
{
	out = mat.getForwardVector();
}

inline void MathMat4::getBackVector( Vec3& out, const Mat4& mat )
{
	out = mat.getBackVector();
}

inline void MathMat4::transformPoint( Vec3& out, const Mat4& mat, const Vec3& point )
{
	out = mat.transformPoint( point );
}

inline void MathMat4::transformVec3( Vec3& out, const Mat4& mat, const Vec3& v )
{
	out = mat.transformVec3( v );
}

inline void MathMat4::transformVec4( Vec4& out, const Mat4& mat, const Vec4& v )
{
	out = mat.transformVec4( v );
}