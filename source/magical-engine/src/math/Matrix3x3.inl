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

inline Matrix3x3::Matrix3x3( float m11, float m22, float m33 ) :
	m11(  m11 ), m12( 0.0f ), m13( 0.0f ),
	m21( 0.0f ), m22(  m22 ), m23( 0.0f ),
	m31( 0.0f ), m32( 0.0f ), m33(  m33 )
{	
	
}

inline Matrix3x3::Matrix3x3( Rotater ea )
{
	setRotation( ea );
}

inline Matrix3x3::Matrix3x3( const Vector3& axis, float angle )
{
	setRotation( axis, angle );
}

inline Matrix3x3::Matrix3x3( float m ) :
	m11(    m ), m12( 0.0f ), m13( 0.0f ),
	m21( 0.0f ), m22(    m ), m23( 0.0f ),
	m31( 0.0f ), m32( 0.0f ), m33(    m )
{
	
}

inline Matrix3x3::Matrix3x3( const Quaternion& q )
{
	setRotation( q );
}

inline Matrix3x3::Matrix3x3( const Matrix3x3& m ) :
	m11( m.m11 ), m12( m.m12 ), m13( m.m13 ),
	m21( m.m21 ), m22( m.m22 ), m23( m.m23 ),
	m31( m.m31 ), m32( m.m32 ), m33( m.m33 )
{
	
}

inline Matrix3x3::Matrix3x3( void )
{
	
}

inline bool Matrix3x3::operator==( const Matrix3x3& m ) const
{
	return equals( m );
}

inline bool Matrix3x3::operator!=( const Matrix3x3& m ) const
{
	return equals( m ) == false;
}

inline float& Matrix3x3::operator[]( size_t i ) const
{
	debugassert( 0 <= i && i <= 8, "index out of range" );

	return ((float*)this)[i];
}

inline Matrix3x3& Matrix3x3::operator=( float m )
{
	m11 =    m; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 =    m; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 =    m;
	return *this;
}

inline Matrix3x3& Matrix3x3::operator=( const Matrix3x3& m )
{
	m11 = m.m11; m12 = m.m12; m13 = m.m13;
	m21 = m.m21; m22 = m.m22; m23 = m.m23;
	m31 = m.m31; m32 = m.m32; m33 = m.m33;
	return *this;
}

inline Matrix3x3 Matrix3x3::operator+( float a ) const
{
	Matrix3x3 dst;
	Matrix3x3::addScalar( dst, *this, a );
	return dst;
}

inline Matrix3x3 Matrix3x3::operator+( const Matrix3x3& m ) const
{
	Matrix3x3 dst;
	Matrix3x3::add( dst, *this, m );
	return dst;
}

inline Matrix3x3 Matrix3x3::operator-( float a ) const
{
	Matrix3x3 dst;
	Matrix3x3::subScalar( dst, *this, a );
	return dst;
}

inline Matrix3x3 Matrix3x3::operator-( const Matrix3x3& m ) const
{
	Matrix3x3 dst;
	Matrix3x3::sub( dst, *this, m );
	return dst;
}

inline Matrix3x3 Matrix3x3::operator*( float a ) const
{
	Matrix3x3 dst;
	Matrix3x3::mulScalar( dst, *this, a );
	return dst;
}

inline Matrix3x3 Matrix3x3::operator*( const Matrix3x3& m ) const
{
	Matrix3x3 dst;
	Matrix3x3::mul( dst, *this, m );
	return dst;
}

inline Matrix3x3& Matrix3x3::operator+=( float a )
{
	Matrix3x3::addScalar( *this, *this, a );
	return *this;
}

inline Matrix3x3& Matrix3x3::operator+=( const Matrix3x3& m )
{
	Matrix3x3::add( *this, *this, m );
	return *this;
}

inline Matrix3x3& Matrix3x3::operator-=( float a )
{
	Matrix3x3::subScalar( *this, *this, a );
	return *this;
}

inline Matrix3x3& Matrix3x3::operator-=( const Matrix3x3& m )
{
	Matrix3x3::sub( *this, *this, m );
	return *this;
}

inline Matrix3x3& Matrix3x3::operator*=( float a )
{
	Matrix3x3::mulScalar( *this, *this, a );
	return *this;
}

inline Matrix3x3& Matrix3x3::operator*=( const Matrix3x3& m )
{
	Matrix3x3::mul( *this, *this, m );
	return *this;
}

inline void Matrix3x3::add( Matrix3x3& out, const Matrix3x3& m1, const Matrix3x3& m2 )
{
	out.m11 = m1.m11 + m2.m11; out.m12 = m1.m12 + m2.m12; out.m13 = m1.m13 + m2.m13;
	out.m21 = m1.m21 + m2.m21; out.m22 = m1.m22 + m2.m22; out.m23 = m1.m23 + m2.m23;
	out.m31 = m1.m31 + m2.m31; out.m32 = m1.m32 + m2.m32; out.m33 = m1.m33 + m2.m33;
}

inline void Matrix3x3::sub( Matrix3x3& out, const Matrix3x3& m1, const Matrix3x3& m2 )
{
	out.m11 = m1.m11 - m2.m11; out.m12 = m1.m12 - m2.m12; out.m13 = m1.m13 - m2.m13;
	out.m21 = m1.m21 - m2.m21; out.m22 = m1.m22 - m2.m22; out.m23 = m1.m23 - m2.m23;
	out.m31 = m1.m31 - m2.m31; out.m32 = m1.m32 - m2.m32; out.m33 = m1.m33 - m2.m33;
}

inline void Matrix3x3::addScalar( Matrix3x3& out, const Matrix3x3& m, float a )
{
	out.m11 = m.m11 + a; out.m12 = m.m12 + a; out.m13 = m.m13 + a;
	out.m21 = m.m21 + a; out.m22 = m.m22 + a; out.m23 = m.m23 + a;
	out.m31 = m.m31 + a; out.m32 = m.m32 + a; out.m33 = m.m33 + a;
}

inline void Matrix3x3::subScalar( Matrix3x3& out, const Matrix3x3& m, float a )
{
	out.m11 = m.m11 - a; out.m12 = m.m12 - a; out.m13 = m.m13 - a;
	out.m21 = m.m21 - a; out.m22 = m.m22 - a; out.m23 = m.m23 - a;
	out.m31 = m.m31 - a; out.m32 = m.m32 - a; out.m33 = m.m33 - a;
}

inline void Matrix3x3::mulScalar( Matrix3x3& out, const Matrix3x3& m, float a )
{
	out.m11 = m.m11 * a; out.m12 = m.m12 * a; out.m13 = m.m13 * a;
	out.m21 = m.m21 * a; out.m22 = m.m22 * a; out.m23 = m.m23 * a;
	out.m31 = m.m31 * a; out.m32 = m.m32 * a; out.m33 = m.m33 * a;
}

inline Matrix3x3 Matrix3x3::add( const Matrix3x3& m1, const Matrix3x3& m2 )
{
	Matrix3x3 dst;
	Matrix3x3::add( dst, m1, m2 );
	return dst;
}

inline Matrix3x3 Matrix3x3::sub( const Matrix3x3& m1, const Matrix3x3& m2 )
{
	Matrix3x3 dst;
	Matrix3x3::sub( dst, m1, m2 );
	return dst;
}

inline Matrix3x3 Matrix3x3::mul( const Matrix3x3& m1, const Matrix3x3& m2 )
{
	Matrix3x3 dst;
	Matrix3x3::mul( dst, m1, m2 );
	return dst;
}

inline Matrix3x3 Matrix3x3::addScalar( const Matrix3x3& m, float a )
{
	Matrix3x3 dst;
	Matrix3x3::addScalar( dst, m, a );
	return dst;
}

inline Matrix3x3 Matrix3x3::subScalar( const Matrix3x3& m, float a )
{
	Matrix3x3 dst;
	Matrix3x3::subScalar( dst, m, a );
	return dst;
}

inline Matrix3x3 Matrix3x3::mulScalar( const Matrix3x3& m, float a )
{
	Matrix3x3 dst;
	Matrix3x3::mulScalar( dst, m, a );
	return dst;
}

inline void Matrix3x3::add( const Matrix3x3& m )
{
	Matrix3x3::add( *this, *this, m );
}

inline void Matrix3x3::sub( const Matrix3x3& m )
{
	Matrix3x3::sub( *this, *this, m );
}

inline void Matrix3x3::mul( const Matrix3x3& m )
{
	Matrix3x3::mul( *this, *this, m );
}

inline void Matrix3x3::addScalar( float a )
{
	Matrix3x3::addScalar( *this, *this, a );
}

inline void Matrix3x3::subScalar( float a )
{
	Matrix3x3::subScalar( *this, *this, a );
}

inline void Matrix3x3::mulScalar( float a )
{
	Matrix3x3::mulScalar( *this, *this, a );
}

inline void Matrix3x3::setZero( void )
{
	m11 = 0.0f; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = 0.0f; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 0.0f;
}

inline void Matrix3x3::setIdentity( void )
{
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
}

inline void Matrix3x3::set( const Matrix3x3& m )
{
	m11 = m.m11; m12 = m.m12; m13 = m.m13;
	m21 = m.m21; m22 = m.m22; m23 = m.m23;
	m31 = m.m31; m32 = m.m32; m33 = m.m33;
}

inline void Matrix3x3::set( float m )
{
	m11 =    m; m12 = 0.0f; m13 = 0.0f;
	m21 = 0.0f; m22 =    m; m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 =    m;
}

inline Matrix3x3 Matrix3x3::createLookAt( const Vector3& eye, const Vector3& target, const Vector3& up )
{
	Matrix3x3 dst;
	dst.setLookAt( eye, target, up );
	return dst;
}

inline Matrix3x3 Matrix3x3::createRotation( const Vector3& axis, float angle )
{
	Matrix3x3 dst;
	dst.setRotation( axis, angle );
	return dst;
}

inline Matrix3x3 Matrix3x3::createRotation( const Rotater& ea )
{
	Matrix3x3 dst;
	dst.setRotation( ea );
	return dst;
}

inline Matrix3x3 Matrix3x3::createRotation( const Quaternion& q )
{
	Matrix3x3 dst;
	dst.setRotation( q );
	return dst;
}

inline Matrix3x3 Matrix3x3::createRotationX( float a )
{
	Matrix3x3 dst;
	dst.setRotationX( a );
	return dst;
}

inline Matrix3x3 Matrix3x3::createRotationY( float a )
{
	Matrix3x3 dst;
	dst.setRotationY( a );
	return dst;
}

inline Matrix3x3 Matrix3x3::createRotationZ( float a )
{
	Matrix3x3 dst;
	dst.setRotationZ( a );
	return dst;
}

inline Matrix3x3 Matrix3x3::inverse( const Matrix3x3& m )
{
	Matrix3x3 dst;
	Matrix3x3::inverse( dst, m );
	return dst;
}

inline Matrix3x3 Matrix3x3::transpose( const Matrix3x3& m )
{
	Matrix3x3 dst;
	Matrix3x3::transpose( dst, m );
	return dst;
}

inline Matrix3x3 Matrix3x3::negate( const Matrix3x3& m )
{
	Matrix3x3 dst;
	Matrix3x3::negate( dst, m );
	return dst;
}

inline void Matrix3x3::inverse( void )
{
	Matrix3x3::inverse( *this, *this );
}

inline void Matrix3x3::transpose( void )
{
	Matrix3x3::transpose( *this, *this );
}

inline void Matrix3x3::negate( void )
{
	Matrix3x3::negate( *this, *this );
}