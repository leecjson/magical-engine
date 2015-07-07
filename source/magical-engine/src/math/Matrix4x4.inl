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
NAMESPACE_MAGICAL

inline Matrix4x4::Matrix4x4( const Quaternion& q )
{
	setRotation( q );
}

inline Matrix4x4::Matrix4x4( float m ) :
	m11(    m ), m12( 0.0f ), m13( 0.0f ), m14( 0.0f ),
	m21( 0.0f ), m22(    m ), m23( 0.0f ), m24( 0.0f ),
	m31( 0.0f ), m32( 0.0f ), m33(    m ), m34( 0.0f ),
	m41( 0.0f ), m42( 0.0f ), m43( 0.0f ), m44(    m )
{
	
}

inline Matrix4x4::Matrix4x4( float m11, float m22, float m33, float m44 ) :
	m11(  m11 ), m12( 0.0f ), m13( 0.0f ), m14( 0.0f ),
	m21( 0.0f ), m22(  m22 ), m23( 0.0f ), m24( 0.0f ),
	m31( 0.0f ), m32( 0.0f ), m33(  m33 ), m34( 0.0f ),
	m41( 0.0f ), m42( 0.0f ), m43( 0.0f ), m44(  m44 )
{
	
}

inline Matrix4x4::Matrix4x4( const Vector3& t, const Quaternion& r, const Vector3& s )
{
	setTrs( t, r, s );
}

inline Matrix4x4::Matrix4x4( const Matrix4x4& m ) :
	m11( m.m11 ), m12( m.m12 ), m13( m.m13 ), m14( m.m14 ),
	m21( m.m21 ), m22( m.m22 ), m23( m.m23 ), m24( m.m24 ),
	m31( m.m31 ), m32( m.m32 ), m33( m.m33 ), m34( m.m34 ),
	m41( m.m41 ), m42( m.m42 ), m43( m.m43 ), m44( m.m44 )
{
	
}

inline Matrix4x4::Matrix4x4( void )
{
	
}

inline bool Matrix4x4::operator==( const Matrix4x4& m ) const
{
	return equals( m );
}

inline bool Matrix4x4::operator!=( const Matrix4x4& m ) const
{
	return equals( m ) == false;
}

inline float& Matrix4x4::operator[]( size_t i ) const
{
	debugassert( 0 <= i && i <= 15, "index out of range" );

	return ((float*)this)[i];
}

inline Matrix4x4& Matrix4x4::operator=( float m )
{
	m11 =    m; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
	m21 = 0.0f; m22 =    m; m23 = 0.0f; m24 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 =    m; m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 =    m;
}

inline Matrix4x4& Matrix4x4::operator=( const Matrix4x4& m )
{
	m11 = m.m11; m12 = m.m12; m13 = m.m13; m14 = m.m14;
	m21 = m.m21; m22 = m.m22; m23 = m.m23; m24 = m.m24;
	m31 = m.m31; m32 = m.m32; m33 = m.m33; m34 = m.m34;
	m41 = m.m41; m42 = m.m42; m43 = m.m43; m44 = m.m44;
	return *this;
}

inline Matrix4x4 Matrix4x4::operator+( float a ) const
{
	Matrix4x4 dst;
	Matrix4x4::addScalar( dst, *this, a );
	return dst;
}

inline Matrix4x4 Matrix4x4::operator+( const Matrix4x4& m ) const
{
	Matrix4x4 dst;
	Matrix4x4::add( dst, *this, m );
	return dst;
}

inline Matrix4x4 Matrix4x4::operator-( float a ) const
{
	Matrix4x4 dst;
	Matrix4x4::subScalar( dst, *this, a );
	return dst;
}

inline Matrix4x4 Matrix4x4::operator-( const Matrix4x4& m ) const
{
	Matrix4x4 dst;
	Matrix4x4::sub( dst, *this, m );
	return dst;
}

inline Matrix4x4 Matrix4x4::operator*( float a ) const
{
	Matrix4x4 dst;
	Matrix4x4::mulScalar( dst, *this, a );
	return dst;
}

inline Matrix4x4 Matrix4x4::operator*( const Matrix4x4& m ) const
{
	Matrix4x4 dst;
	Matrix4x4::mul( dst, *this, m );
	return dst;
}

inline Matrix4x4& Matrix4x4::operator+=( float a )
{
	Matrix4x4::addScalar( *this, *this, a );
	return *this;
}

inline Matrix4x4& Matrix4x4::operator+=( const Matrix4x4& m )
{
	Matrix4x4::add( *this, *this, m );
	return *this;
}

inline Matrix4x4& Matrix4x4::operator-=( float a )
{
	Matrix4x4::subScalar( *this, *this, a );
	return *this;
}

inline Matrix4x4& Matrix4x4::operator-=( const Matrix4x4& m )
{
	Matrix4x4::sub( *this, *this, m );
	return *this;
}

inline Matrix4x4& Matrix4x4::operator*=( float a )
{
	Matrix4x4::mulScalar( *this, *this, a );
	return *this;
}

inline Matrix4x4& Matrix4x4::operator*=( const Matrix4x4& m )
{
	Matrix4x4::mul( *this, *this, m );
	return *this;
}

inline void Matrix4x4::add( Matrix4x4& dst, const Matrix4x4& m1, const Matrix4x4& m2 )
{
	dst.m11 = m1.m11 + m2.m11; dst.m12 = m1.m12 + m2.m12; dst.m13 = m1.m13 + m2.m13; dst.m14 = m1.m14 + m2.m14;
	dst.m21 = m1.m21 + m2.m21; dst.m22 = m1.m22 + m2.m22; dst.m23 = m1.m23 + m2.m23; dst.m24 = m1.m24 + m2.m24;
	dst.m31 = m1.m31 + m2.m31; dst.m32 = m1.m32 + m2.m32; dst.m33 = m1.m33 + m2.m33; dst.m34 = m1.m34 + m2.m34;
	dst.m41 = m1.m41 + m2.m41; dst.m42 = m1.m42 + m2.m42; dst.m43 = m1.m43 + m2.m43; dst.m44 = m1.m44 + m2.m44;
}

inline void Matrix4x4::sub( Matrix4x4& dst, const Matrix4x4& m1, const Matrix4x4& m2 )
{
	dst.m11 = m1.m11 - m2.m11; dst.m12 = m1.m12 - m2.m12; dst.m13 = m1.m13 - m2.m13; dst.m14 = m1.m14 - m2.m14;
	dst.m21 = m1.m21 - m2.m21; dst.m22 = m1.m22 - m2.m22; dst.m23 = m1.m23 - m2.m23; dst.m24 = m1.m24 - m2.m24;
	dst.m31 = m1.m31 - m2.m31; dst.m32 = m1.m32 - m2.m32; dst.m33 = m1.m33 - m2.m33; dst.m34 = m1.m34 - m2.m34;
	dst.m41 = m1.m41 - m2.m41; dst.m42 = m1.m42 - m2.m42; dst.m43 = m1.m43 - m2.m43; dst.m44 = m1.m44 - m2.m44;
}

inline void Matrix4x4::addScalar( Matrix4x4& dst, const Matrix4x4& m, float a )
{
	dst.m11 = m.m11 + a; dst.m12 = m.m12 + a; dst.m13 = m.m13 + a; dst.m14 = m.m14 + a;
	dst.m21 = m.m21 + a; dst.m22 = m.m22 + a; dst.m23 = m.m23 + a; dst.m24 = m.m24 + a;
	dst.m31 = m.m31 + a; dst.m32 = m.m32 + a; dst.m33 = m.m33 + a; dst.m34 = m.m34 + a;
	dst.m41 = m.m41 + a; dst.m42 = m.m42 + a; dst.m43 = m.m43 + a; dst.m44 = m.m44 + a;
}

inline void Matrix4x4::subScalar( Matrix4x4& dst, const Matrix4x4& m, float a )
{
	dst.m11 = m.m11 - a; dst.m12 = m.m12 - a; dst.m13 = m.m13 - a; dst.m14 = m.m14 - a;
	dst.m21 = m.m21 - a; dst.m22 = m.m22 - a; dst.m23 = m.m23 - a; dst.m24 = m.m24 - a;
	dst.m31 = m.m31 - a; dst.m32 = m.m32 - a; dst.m33 = m.m33 - a; dst.m34 = m.m34 - a;
	dst.m41 = m.m41 - a; dst.m42 = m.m42 - a; dst.m43 = m.m43 - a; dst.m44 = m.m44 - a;
}

inline void Matrix4x4::mulScalar( Matrix4x4& dst, const Matrix4x4& m, float a )
{
	dst.m11 = m.m11 * a; dst.m12 = m.m12 * a; dst.m13 = m.m13 * a; dst.m14 = m.m14 * a;
	dst.m21 = m.m21 * a; dst.m22 = m.m22 * a; dst.m23 = m.m23 * a; dst.m24 = m.m24 * a;
	dst.m31 = m.m31 * a; dst.m32 = m.m32 * a; dst.m33 = m.m33 * a; dst.m34 = m.m34 * a;
	dst.m41 = m.m41 * a; dst.m42 = m.m42 * a; dst.m43 = m.m43 * a; dst.m44 = m.m44 * a;
}

inline Matrix4x4 Matrix4x4::add( const Matrix4x4& m1, const Matrix4x4& m2 )
{
	Matrix4x4 dst;
	Matrix4x4::add( dst, m1, m2 );
	return dst;
}

inline Matrix4x4 Matrix4x4::sub( const Matrix4x4& m1, const Matrix4x4& m2 )
{
	Matrix4x4 dst;
	Matrix4x4::sub( dst, m1, m2 );
	return dst;
}

inline Matrix4x4 Matrix4x4::mul( const Matrix4x4& m1, const Matrix4x4& m2 )
{
	Matrix4x4 dst;
	Matrix4x4::mul( dst, m1, m2 );
	return dst;
}

inline Matrix4x4 Matrix4x4::mul3x4( const Matrix4x4& m1, const Matrix4x4& m2 )
{
	Matrix4x4 dst;
	Matrix4x4::mul3x4( dst, m1, m2 );
	return dst;
}

inline Matrix4x4 Matrix4x4::addScalar( const Matrix4x4& m, float a )
{
	Matrix4x4 dst;
	Matrix4x4::addScalar( dst, m, a );
	return dst;
}

inline Matrix4x4 Matrix4x4::subScalar( const Matrix4x4& m, float a )
{
	Matrix4x4 dst;
	Matrix4x4::subScalar( dst, m, a );
	return dst;
}

inline Matrix4x4 Matrix4x4::mulScalar( const Matrix4x4& m, float a )
{
	Matrix4x4 dst;
	Matrix4x4::mulScalar( dst, m, a );
	return dst;
}

inline void Matrix4x4::add( const Matrix4x4& m )
{
	Matrix4x4::add( *this, *this, m );
}

inline void Matrix4x4::sub( const Matrix4x4& m )
{
	Matrix4x4::sub( *this, *this, m );
}

inline void Matrix4x4::mul( const Matrix4x4& m )
{
	Matrix4x4::mul( *this, *this, m );
}

inline void Matrix4x4::mul3x4( const Matrix4x4& m )
{
	Matrix4x4::mul3x4( *this, *this, m );
}

inline void Matrix4x4::addScalar( float a )
{
	Matrix4x4::addScalar( *this, *this, a );
}

inline void Matrix4x4::subScalar( float a )
{
	Matrix4x4::subScalar( *this, *this, a );
}

inline void Matrix4x4::mulScalar( float a )
{
	Matrix4x4::mulScalar( *this, *this, a );
}

inline void Matrix4x4::setZero( void )
{
	m11 = 0.0f; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
	m21 = 0.0f; m22 = 0.0f; m23 = 0.0f; m24 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 0.0f; m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = 0.0f;
}

inline void Matrix4x4::setIdentity( void )
{
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f; m24 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f; m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = 1.0f;
}

inline void Matrix4x4::set( const Matrix4x4& m )
{
	m11 = m.m11; m12 = m.m12; m13 = m.m13; m14 = m.m14;
	m21 = m.m21; m22 = m.m22; m23 = m.m23; m24 = m.m24;
	m31 = m.m31; m32 = m.m32; m33 = m.m33; m34 = m.m34;
	m41 = m.m41; m42 = m.m42; m43 = m.m43; m44 = m.m44;
}

inline void Matrix4x4::set( float m )
{
	m11 =    m; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
	m21 = 0.0f; m22 =    m; m23 = 0.0f; m24 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 =    m; m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 =    m;
}

inline Matrix4x4 createLookAt( const Vector3& eye, const Vector3& target, const Vector3& up )
{
	Matrix4x4 dst;
	dst.setLookAt( eye, target, up );
	return dst;
}

inline Matrix4x4 createPerspective( float fov, float aspect, float znear, float zfar )
{
	Matrix4x4 dst;
	dst.setPerspective( fov, aspect, znear, zfar );
	return dst;
}

inline Matrix4x4 createOrtho( float left, float right, float bottom, float top, float znear, float zfar )
{
	Matrix4x4 dst;
	dst.setOrtho( left, right, bottom, top, znear, zfar );
	return dst;
}

inline Matrix4x4 createTrs( const Vector3& t, const Quaternion& r, const Vector3& s )
{
	Matrix4x4 dst;
	dst.setTrs( t, r, s );
	return dst;
}

inline Matrix4x4 createTranslation( const Vector3& t )
{
	Matrix4x4 dst;
	dst.setTranslation( t );
	return dst;
}

inline Matrix4x4 createScale( const Vector3& s )
{
	Matrix4x4 dst;
	dst.setScale( s );
	return dst;
}

inline Matrix4x4 createRotation( const Quaternion& q )
{
	Matrix4x4 dst;
	dst.setRotation( q );
	return dst;
}

inline Matrix4x4 createRotationX( float a )
{
	Matrix4x4 dst;
	dst.setRotationX( a );
	return dst;
}

inline Matrix4x4 createRotationY( float a )
{
	Matrix4x4 dst;
	dst.setRotationY( a );
	return dst;
}

inline Matrix4x4 createRotationZ( float a )
{
	Matrix4x4 dst;
	dst.setRotationZ( a );
	return dst;
}

inline Matrix4x4 Matrix4x4::inverse( const Matrix4x4& m )
{
	Matrix4x4 dst;
	Matrix4x4::inverse( dst, m );
	return dst;
}

inline Matrix4x4 Matrix4x4::transpose( const Matrix4x4& m )
{
	Matrix4x4 dst;
	Matrix4x4::transpose( dst, m );
	return dst;
}

inline Matrix4x4 Matrix4x4::negate( const Matrix4x4& m )
{
	Matrix4x4 dst;
	Matrix4x4::negate( dst, m );
	return dst;
}

inline void Matrix4x4::inverse( void )
{
	Matrix4x4::inverse( *this, *this );
}

inline void Matrix4x4::transpose( void )
{
	Matrix4x4::transpose( *this, *this );
}

inline void Matrix4x4::negate( void )
{
	Matrix4x4::negate( *this, *this );
}

NAMESPACE_END