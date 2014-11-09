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
	return memcmp( mat.m, m, kMatrix4x4Size ) == 0;
}

inline bool Mat4::operator!=( const Mat4& mat ) const
{
	return !( operator==( mat ) );
}

inline bool Mat4::isIdentity( void ) const
{
	return memcmp( Identity.m, m, kMatrix4x4Size ) == 0;
}

inline bool Mat4::isEquals( const Mat4& mat ) const
{
	return memcmp( mat.m, m, kMatrix4x4Size ) == 0;
}

inline Mat4 Mat4::operator+( float a ) const
{
	return Mat4(
		m11 + a, m12 + a, m13 + a, m14 + a,
		m21 + a, m22 + a, m23 + a, m24 + a,
		m31 + a, m32 + a, m33 + a, m34 + a,
		m41 + a, m42 + a, m43 + a, m44 + a
	);
}

inline Mat4 Mat4::operator+( const Mat4& mat ) const
{
	return Mat4(
		m11 + mat.m11, m12 + mat.m12, m13 + mat.m13, m14 + mat.m14,
		m21 + mat.m21, m22 + mat.m22, m23 + mat.m23, m24 + mat.m24,
		m31 + mat.m31, m32 + mat.m32, m33 + mat.m33, m34 + mat.m34,
		m41 + mat.m41, m42 + mat.m42, m43 + mat.m43, m44 + mat.m44
	);
}

inline Mat4 Mat4::operator-( float a ) const
{
	return Mat4(
		m11 - a, m12 - a, m13 - a, m14 - a,
		m21 - a, m22 - a, m23 - a, m24 - a,
		m31 - a, m32 - a, m33 - a, m34 - a,
		m41 - a, m42 - a, m43 - a, m44 - a
	);
}

inline Mat4 Mat4::operator-( const Mat4& mat ) const
{
	return Mat4(
		m11 - mat.m11, m12 - mat.m12, m13 - mat.m13, m14 - mat.m14,
		m21 - mat.m21, m22 - mat.m22, m23 - mat.m23, m24 - mat.m24,
		m31 - mat.m31, m32 - mat.m32, m33 - mat.m33, m34 - mat.m34,
		m41 - mat.m41, m42 - mat.m42, m43 - mat.m43, m44 - mat.m44
	);
}

inline Mat4 Mat4::operator*( float a ) const
{
	return Mat4(
		m11 * a, m12 * a, m13 * a, m14 * a,
		m21 * a, m22 * a, m23 * a, m24 * a,
		m31 * a, m32 * a, m33 * a, m34 * a,
		m41 * a, m42 * a, m43 * a, m44 * a
	);
}

inline Mat4 Mat4::operator*( const Mat4& mat ) const
{
	/*
                                mat-> m11 , m12 , m13 , m14
                                      m21 , m22 , m23 , m24
                                      m31 , m32 , m33 , m34
                                      m41 , m42 , m43 , m44 
       this-> m11 , m12 , m13 , m14   d11 , d12 , d13 , d14
              m21 , m22 , m23 , m24   d21 , d22 , d23 , d24
              m31 , m32 , m33 , m34   d31 , d32 , d33 , d34
              m41 , m42 , m43 , m44   d41 , d42 , d43 , d44
	*/
	Mat4 dst;
	dst.m11 = m11 * mat.m11 + m12 * mat.m21 + m13 * mat.m31 + m14 * mat.m41;
	dst.m12 = m11 * mat.m12 + m12 * mat.m22 + m13 * mat.m32 + m14 * mat.m42;
	dst.m13 = m11 * mat.m13 + m12 * mat.m23 + m13 * mat.m33 + m14 * mat.m43;
	dst.m14 = m11 * mat.m14 + m12 * mat.m24 + m13 * mat.m34 + m14 * mat.m44;
	dst.m21 = m21 * mat.m11 + m22 * mat.m21 + m23 * mat.m31 + m24 * mat.m41;
	dst.m22 = m21 * mat.m12 + m22 * mat.m22 + m23 * mat.m32 + m24 * mat.m42;
	dst.m23 = m21 * mat.m13 + m22 * mat.m23 + m23 * mat.m33 + m24 * mat.m43;
	dst.m24 = m21 * mat.m14 + m22 * mat.m24 + m23 * mat.m34 + m24 * mat.m44;
	dst.m31 = m31 * mat.m11 + m32 * mat.m21 + m33 * mat.m31 + m34 * mat.m41;
	dst.m32 = m31 * mat.m12 + m32 * mat.m22 + m33 * mat.m32 + m34 * mat.m42;
	dst.m33 = m31 * mat.m13 + m32 * mat.m23 + m33 * mat.m33 + m34 * mat.m43;
	dst.m34 = m31 * mat.m14 + m32 * mat.m24 + m33 * mat.m34 + m34 * mat.m44;
	dst.m41 = m41 * mat.m11 + m42 * mat.m21 + m43 * mat.m31 + m44 * mat.m41;
	dst.m42 = m41 * mat.m12 + m42 * mat.m22 + m43 * mat.m32 + m44 * mat.m42;
	dst.m43 = m41 * mat.m13 + m42 * mat.m23 + m43 * mat.m33 + m44 * mat.m43;
	dst.m44 = m41 * mat.m14 + m42 * mat.m24 + m43 * mat.m34 + m44 * mat.m44;
	return dst;
}

inline Mat4& Mat4::operator+=( float a )
{
	m11 += a; m12 += a; m13 += a; m14 += a;
	m21 += a; m22 += a; m23 += a; m24 += a;
	m31 += a; m32 += a; m33 += a; m34 += a;
	m41 += a; m42 += a; m43 += a; m44 += a;
	return *this;
}

inline Mat4& Mat4::operator+=( const Mat4& mat )
{
	m11 += mat.m11; m12 += mat.m12; m13 += mat.m13; m14 += mat.m14;
	m21 += mat.m21; m22 += mat.m22; m23 += mat.m23; m24 += mat.m24;
	m31 += mat.m31; m32 += mat.m32; m33 += mat.m33; m34 += mat.m34;
	m41 += mat.m41; m42 += mat.m42; m43 += mat.m43; m44 += mat.m44;
	return *this;
}

inline Mat4& Mat4::operator-=( float a )
{
	m11 -= a; m12 -= a; m13 -= a; m14 -= a;
	m21 -= a; m22 -= a; m23 -= a; m24 -= a;
	m31 -= a; m32 -= a; m33 -= a; m34 -= a;
	m41 -= a; m42 -= a; m43 -= a; m44 -= a;
	return *this;
}

inline Mat4& Mat4::operator-=( const Mat4& mat )
{
	m11 -= mat.m11; m12 -= mat.m12; m13 -= mat.m13; m14 -= mat.m14;
	m21 -= mat.m21; m22 -= mat.m22; m23 -= mat.m23; m24 -= mat.m24;
	m31 -= mat.m31; m32 -= mat.m32; m33 -= mat.m33; m34 -= mat.m34;
	m41 -= mat.m41; m42 -= mat.m42; m43 -= mat.m43; m44 -= mat.m44;
	return *this;
}

inline Mat4& Mat4::operator*=( float a )
{
	m11 *= a; m12 *= a; m13 *= a; m14 *= a;
	m21 *= a; m22 *= a; m23 *= a; m24 *= a;
	m31 *= a; m32 *= a; m33 *= a; m34 *= a;
	m41 *= a; m42 *= a; m43 *= a; m44 *= a;
	return *this;
}

inline Mat4& Mat4::operator*=( const Mat4& mat )
{
	Mat4 dst;
	dst.m11 = m11 * mat.m11 + m12 * mat.m21 + m13 * mat.m31 + m14 * mat.m41;
	dst.m12 = m11 * mat.m12 + m12 * mat.m22 + m13 * mat.m32 + m14 * mat.m42;
	dst.m13 = m11 * mat.m13 + m12 * mat.m23 + m13 * mat.m33 + m14 * mat.m43;
	dst.m14 = m11 * mat.m14 + m12 * mat.m24 + m13 * mat.m34 + m14 * mat.m44;
	dst.m21 = m21 * mat.m11 + m22 * mat.m21 + m23 * mat.m31 + m24 * mat.m41;
	dst.m22 = m21 * mat.m12 + m22 * mat.m22 + m23 * mat.m32 + m24 * mat.m42;
	dst.m23 = m21 * mat.m13 + m22 * mat.m23 + m23 * mat.m33 + m24 * mat.m43;
	dst.m24 = m21 * mat.m14 + m22 * mat.m24 + m23 * mat.m34 + m24 * mat.m44;
	dst.m31 = m31 * mat.m11 + m32 * mat.m21 + m33 * mat.m31 + m34 * mat.m41;
	dst.m32 = m31 * mat.m12 + m32 * mat.m22 + m33 * mat.m32 + m34 * mat.m42;
	dst.m33 = m31 * mat.m13 + m32 * mat.m23 + m33 * mat.m33 + m34 * mat.m43;
	dst.m34 = m31 * mat.m14 + m32 * mat.m24 + m33 * mat.m34 + m34 * mat.m44;
	dst.m41 = m41 * mat.m11 + m42 * mat.m21 + m43 * mat.m31 + m44 * mat.m41;
	dst.m42 = m41 * mat.m12 + m42 * mat.m22 + m43 * mat.m32 + m44 * mat.m42;
	dst.m43 = m41 * mat.m13 + m42 * mat.m23 + m43 * mat.m33 + m44 * mat.m43;
	dst.m44 = m41 * mat.m14 + m42 * mat.m24 + m43 * mat.m34 + m44 * mat.m44;

	memcpy( m, dst.m, kMatrix4x4Size );
	return *this;
}

inline Mat4& Mat4::operator=( const Mat4& mat )
{
	memcpy( m, mat.m, kMatrix4x4Size );
	return *this;
}

inline Mat4 Mat4::add( float a ) const
{
	return Mat4(
		m11 + a, m12 + a, m13 + a, m14 + a,
		m21 + a, m22 + a, m23 + a, m24 + a,
		m31 + a, m32 + a, m33 + a, m34 + a,
		m41 + a, m42 + a, m43 + a, m44 + a
	);
}

inline Mat4 Mat4::add( const Mat4& mat ) const
{
	return Mat4(
		m11 + mat.m11, m12 + mat.m12, m13 + mat.m13, m14 + mat.m14,
		m21 + mat.m21, m22 + mat.m22, m23 + mat.m23, m24 + mat.m24,
		m31 + mat.m31, m32 + mat.m32, m33 + mat.m33, m34 + mat.m34,
		m41 + mat.m41, m42 + mat.m42, m43 + mat.m43, m44 + mat.m44
	);
}

inline Mat4 Mat4::sub( float a ) const
{
	return Mat4(
		m11 - a, m12 - a, m13 - a, m14 - a,
		m21 - a, m22 - a, m23 - a, m24 - a,
		m31 - a, m32 - a, m33 - a, m34 - a,
		m41 - a, m42 - a, m43 - a, m44 - a
	);
}

inline Mat4 Mat4::sub( const Mat4& mat ) const
{
	return Mat4(
		m11 - mat.m11, m12 - mat.m12, m13 - mat.m13, m14 - mat.m14,
		m21 - mat.m21, m22 - mat.m22, m23 - mat.m23, m24 - mat.m24,
		m31 - mat.m31, m32 - mat.m32, m33 - mat.m33, m34 - mat.m34,
		m41 - mat.m41, m42 - mat.m42, m43 - mat.m43, m44 - mat.m44
	);
}

inline Mat4 Mat4::mul( float a ) const
{
	return Mat4(
		m11 * a, m12 * a, m13 * a, m14 * a,
		m21 * a, m22 * a, m23 * a, m24 * a,
		m31 * a, m32 * a, m33 * a, m34 * a,
		m41 * a, m42 * a, m43 * a, m44 * a
	);
}

inline Mat4 Mat4::mul( const Mat4& mat ) const
{
	/*
                                mat-> m11 , m12 , m13 , m14
                                      m21 , m22 , m23 , m24
                                      m31 , m32 , m33 , m34
                                      m41 , m42 , m43 , m44 
       this-> m11 , m12 , m13 , m14   d11 , d12 , d13 , d14
              m21 , m22 , m23 , m24   d21 , d22 , d23 , d24
              m31 , m32 , m33 , m34   d31 , d32 , d33 , d34
              m41 , m42 , m43 , m44   d41 , d42 , d43 , d44
	*/
	Mat4 dst;
	dst.m11 = m11 * mat.m11 + m12 * mat.m21 + m13 * mat.m31 + m14 * mat.m41;
	dst.m12 = m11 * mat.m12 + m12 * mat.m22 + m13 * mat.m32 + m14 * mat.m42;
	dst.m13 = m11 * mat.m13 + m12 * mat.m23 + m13 * mat.m33 + m14 * mat.m43;
	dst.m14 = m11 * mat.m14 + m12 * mat.m24 + m13 * mat.m34 + m14 * mat.m44;
	dst.m21 = m21 * mat.m11 + m22 * mat.m21 + m23 * mat.m31 + m24 * mat.m41;
	dst.m22 = m21 * mat.m12 + m22 * mat.m22 + m23 * mat.m32 + m24 * mat.m42;
	dst.m23 = m21 * mat.m13 + m22 * mat.m23 + m23 * mat.m33 + m24 * mat.m43;
	dst.m24 = m21 * mat.m14 + m22 * mat.m24 + m23 * mat.m34 + m24 * mat.m44;
	dst.m31 = m31 * mat.m11 + m32 * mat.m21 + m33 * mat.m31 + m34 * mat.m41;
	dst.m32 = m31 * mat.m12 + m32 * mat.m22 + m33 * mat.m32 + m34 * mat.m42;
	dst.m33 = m31 * mat.m13 + m32 * mat.m23 + m33 * mat.m33 + m34 * mat.m43;
	dst.m34 = m31 * mat.m14 + m32 * mat.m24 + m33 * mat.m34 + m34 * mat.m44;
	dst.m41 = m41 * mat.m11 + m42 * mat.m21 + m43 * mat.m31 + m44 * mat.m41;
	dst.m42 = m41 * mat.m12 + m42 * mat.m22 + m43 * mat.m32 + m44 * mat.m42;
	dst.m43 = m41 * mat.m13 + m42 * mat.m23 + m43 * mat.m33 + m44 * mat.m43;
	dst.m44 = m41 * mat.m14 + m42 * mat.m24 + m43 * mat.m34 + m44 * mat.m44;
	return dst;
}

inline void Mat4::addfill( float a )
{
	m11 += a; m12 += a; m13 += a; m14 += a;
	m21 += a; m22 += a; m23 += a; m24 += a;
	m31 += a; m32 += a; m33 += a; m34 += a;
	m41 += a; m42 += a; m43 += a; m44 += a;
}

inline void Mat4::addfill( const Mat4& mat )
{
	m11 += mat.m11; m12 += mat.m12; m13 += mat.m13; m14 += mat.m14;
	m21 += mat.m21; m22 += mat.m22; m23 += mat.m23; m24 += mat.m24;
	m31 += mat.m31; m32 += mat.m32; m33 += mat.m33; m34 += mat.m34;
	m41 += mat.m41; m42 += mat.m42; m43 += mat.m43; m44 += mat.m44;
}

inline void Mat4::subfill( float a )
{
	m11 -= a; m12 -= a; m13 -= a; m14 -= a;
	m21 -= a; m22 -= a; m23 -= a; m24 -= a;
	m31 -= a; m32 -= a; m33 -= a; m34 -= a;
	m41 -= a; m42 -= a; m43 -= a; m44 -= a;
}

inline void Mat4::subfill( const Mat4& mat )
{
	m11 -= mat.m11; m12 -= mat.m12; m13 -= mat.m13; m14 -= mat.m14;
	m21 -= mat.m21; m22 -= mat.m22; m23 -= mat.m23; m24 -= mat.m24;
	m31 -= mat.m31; m32 -= mat.m32; m33 -= mat.m33; m34 -= mat.m34;
	m41 -= mat.m41; m42 -= mat.m42; m43 -= mat.m43; m44 -= mat.m44;
}

inline void Mat4::mulfill( float a )
{
	m11 *= a; m12 *= a; m13 *= a; m14 *= a;
	m21 *= a; m22 *= a; m23 *= a; m24 *= a;
	m31 *= a; m32 *= a; m33 *= a; m34 *= a;
	m41 *= a; m42 *= a; m43 *= a; m44 *= a;
}

inline void Mat4::mulfill( const Mat4& mat )
{
	Mat4 dst;
	dst.m11 = m11 * mat.m11 + m12 * mat.m21 + m13 * mat.m31 + m14 * mat.m41;
	dst.m12 = m11 * mat.m12 + m12 * mat.m22 + m13 * mat.m32 + m14 * mat.m42;
	dst.m13 = m11 * mat.m13 + m12 * mat.m23 + m13 * mat.m33 + m14 * mat.m43;
	dst.m14 = m11 * mat.m14 + m12 * mat.m24 + m13 * mat.m34 + m14 * mat.m44;
	dst.m21 = m21 * mat.m11 + m22 * mat.m21 + m23 * mat.m31 + m24 * mat.m41;
	dst.m22 = m21 * mat.m12 + m22 * mat.m22 + m23 * mat.m32 + m24 * mat.m42;
	dst.m23 = m21 * mat.m13 + m22 * mat.m23 + m23 * mat.m33 + m24 * mat.m43;
	dst.m24 = m21 * mat.m14 + m22 * mat.m24 + m23 * mat.m34 + m24 * mat.m44;
	dst.m31 = m31 * mat.m11 + m32 * mat.m21 + m33 * mat.m31 + m34 * mat.m41;
	dst.m32 = m31 * mat.m12 + m32 * mat.m22 + m33 * mat.m32 + m34 * mat.m42;
	dst.m33 = m31 * mat.m13 + m32 * mat.m23 + m33 * mat.m33 + m34 * mat.m43;
	dst.m34 = m31 * mat.m14 + m32 * mat.m24 + m33 * mat.m34 + m34 * mat.m44;
	dst.m41 = m41 * mat.m11 + m42 * mat.m21 + m43 * mat.m31 + m44 * mat.m41;
	dst.m42 = m41 * mat.m12 + m42 * mat.m22 + m43 * mat.m32 + m44 * mat.m42;
	dst.m43 = m41 * mat.m13 + m42 * mat.m23 + m43 * mat.m33 + m44 * mat.m43;
	dst.m44 = m41 * mat.m14 + m42 * mat.m24 + m43 * mat.m34 + m44 * mat.m44;

	memcpy( m, dst.m, kMatrix4x4Size );
}

inline void Mat4::fill( const float* m )
{
	magicalAssert( m, "should not be nullptr" );
	memcpy( this->m, m, kMatrix4x4Size );
}

inline void Mat4::fill( const Mat4& mat )
{
	memcpy( m, mat.m, kMatrix4x4Size );
}

inline void Mat4::fillZero( void )
{
	memset( m, 0, kMatrix4x4Size );
}

inline void Mat4::fillIdentity( void )
{
	memcpy( m, Identity.m, kMatrix4x4Size );
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

	float c = cos( rad );
	float s = sin( rad );

	m22 = c;
	m23 = s;
	m32 = -s;
	m33 = c;
}

inline void Mat4::fillRotationY( float rad )
{
	fillIdentity();

	float c = cos( rad );
	float s = sin( rad );

	m11 = c;
	m13 = -s;
	m31 = s;
	m33 = c;
}

inline void Mat4::fillRotationZ( float rad )
{
	fillIdentity();

	float c = cos( rad );
	float s = sin( rad );

	m11 = c;
	m12 = s;
	m21 = -s;
	m22 = c;
}

inline void Mat4::fillRotation( const Quaternion& r )
{
	float x2 = r.x + r.x;
    float y2 = r.y + r.y;
    float z2 = r.z + r.z;

    float xx2 = r.x * x2;
    float yy2 = r.y * y2;
    float zz2 = r.z * z2;
    float xy2 = r.x * y2;
    float xz2 = r.x * z2;
    float yz2 = r.y * z2;
    float wx2 = r.w * x2;
    float wy2 = r.w * y2;
    float wz2 = r.w * z2;

    m11 = 1.0f - yy2 - zz2;
    m12 = xy2 + wz2;
    m13 = xz2 - wy2;
    m14 = 0.0f;
    m21 = xy2 - wz2;
    m22 = 1.0f - xx2 - zz2;
    m23 = yz2 + wx2;
    m24 = 0.0f;
    m31 = xz2 + wy2;
    m32 = yz2 - wx2;
    m33 = 1.0f - xx2 - yy2;
    m34 = 0.0f;
    m41 = 0.0f;
    m42 = 0.0f;
    m43 = 0.0f;
    m44 = 1.0f;
}

inline void Mat4::fillRotation( const Vec3& axis, float angle )
{
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	float n = x * x + y * y + z * z;
	if( magicalFloatEquals( n, 1.0f ) == false )
	{
		n = sqrt( n );
		if( magicalFloatIsZero( n ) == false )
		{
			n = 1.0f / n;
			x *= n;
			y *= n;
			z *= n;
		}
	}

	float c = cos( angle );
	float s = sin( angle );

	float t = 1.0f - c;
	float tx = t * x;
	float ty = t * y;
	float tz = t * z;
	float txy = tx * y;
	float txz = tx * z;
	float tyz = ty * z;
	float sx = s * x;
	float sy = s * y;
	float sz = s * z;

	m11 = c + tx*x;
	m12 = txy + sz;
	m13 = txz - sy;
	m14 = 0.0f;
	m21 = txy - sz;
	m22 = c + ty*y;
	m23 = tyz + sx;
	m24 = 0.0f;
	m31 = txz + sy;
	m32 = tyz - sx;
	m33 = c + tz*z;
	m34 = 0.0f;
	m41 = 0.0f;
	m42 = 0.0f;
	m43 = 0.0f;
	m44 = 1.0f;
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

inline void Mat4::fillLookAt( const Vec3& eye, const Vec3& target, const Vec3& up )
{
	Vec3 up_v = up;
	up_v.normalize();

	Vec3 zaxis = eye - target;
	zaxis.normalize();

	Vec3 xaxis =  up_v.getCross( zaxis );
	xaxis.normalize();

	Vec3 yaxis =  zaxis.getCross( xaxis );
	yaxis.normalize();

	m11 = xaxis.x;
	m12 = yaxis.x;
	m13 = zaxis.x;
	m14 = 0.0f;
	m21 = xaxis.y;
	m22 = yaxis.y;
	m23 = zaxis.y;
	m24 = 0.0f;
	m31 = xaxis.z;
	m32 = yaxis.z;
	m33 = zaxis.z;
	m34 = 0.0f;
	m41 = - xaxis.dot( eye );
	m42 = - yaxis.dot( eye );
	m43 = - zaxis.dot( eye );
	m44 = 1.0f;
}

inline void Mat4::fillPerspective( float fov, float aspect, float znear, float zfar )
{
	float r = magicalDegToRad( fov / 2 );
	float delta_z = zfar - znear;
	float s = sin( r );
	float cotangent = 0;

	magicalAssert( 
		!magicalFloatIsZero( delta_z ) &&
		!magicalFloatIsZero( s ) &&
		!magicalFloatIsZero( aspect ), "should not be 0.0f" );
	cotangent = cos( r ) / s;

	fillIdentity();
	m[0]  = cotangent / aspect;
	m[5]  = cotangent;
	m[10] = -( zfar + znear ) / delta_z;
	m[11] = -1;
	m[14] = -2 * znear * zfar / delta_z;
	m[15] = 0;
}

inline void Mat4::fillOrthographic( float left, float right, float bottom, float top, float near, float far )
{
	float tx = -( ( right + left ) / ( right - left ) );
	float ty = -( ( top + bottom ) / ( top - bottom ) );
	float tz = -( ( far + near ) / ( far - near ) );

	fillIdentity();
	m[0]  = 2 / ( right - left );
	m[5]  = 2 / ( top - bottom );
	m[10] = -2 / ( far - near );
	m[12] = tx;
	m[13] = ty;
	m[14] = tz;
}

inline float Mat4::determinant( void ) const
{
	return 
		( m11 * m22 - m12 * m21 ) *
		( m33 * m44 - m34 * m43 ) -
		( m11 * m23 - m13 * m21 ) *
		( m32 * m44 - m34 * m42 ) +
		( m11 * m24 - m14 * m21 ) *
		( m32 * m43 - m33 * m42 ) +
		( m12 * m23 - m13 * m22 ) *
		( m31 * m44 - m34 * m41 ) -
		( m12 * m24 - m14 * m22 ) *
		( m31 * m43 - m33 * m41 ) +
		( m13 * m24 - m14 * m23 ) *
		( m31 * m42 - m32 * m41 );
}

inline void Mat4::transpose( void )
{
	float t[16] = {
		m11, m21, m31, m41,
		m12, m22, m32, m42,
		m13, m23, m33, m43,
		m14, m24, m34, m44
	};
	memcpy( m, t, kMatrix4x4Size );
}

inline void Mat4::negate( void )
{
	m11 = -m11; m12 = -m12; m13 = -m13; m14 = -m14;
	m21 = -m21; m22 = -m22; m23 = -m23; m24 = -m24;
	m31 = -m31; m32 = -m32; m33 = -m33; m34 = -m34;
	m41 = -m41; m42 = -m42; m43 = -m43; m44 = -m44;
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

inline bool Mat4::getInverse( Mat4& out ) const
{
	float a0 = m11 * m22 - m12 * m21;
    float a1 = m11 * m23 - m13 * m21;
    float a2 = m11 * m24 - m14 * m21;
    float a3 = m12 * m23 - m13 * m22;
    float a4 = m12 * m24 - m14 * m22;
    float a5 = m13 * m24 - m14 * m23;
    float b0 = m31 * m42 - m32 * m41;
    float b1 = m31 * m43 - m33 * m41;
    float b2 = m31 * m44 - m34 * m41;
    float b3 = m32 * m43 - m33 * m42;
    float b4 = m32 * m44 - m34 * m42;
    float b5 = m33 * m44 - m34 * m43;
	float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

	if( magicalFloatIsZero( det ) )
		return false;

	Mat4 adj;
	adj.m11 =   m22 * b5 - m23 * b4 + m24 * b3;
	adj.m12 = - m12 * b5 + m13 * b4 - m14 * b3;
	adj.m13 =   m42 * a5 - m43 * a4 + m44 * a3;
	adj.m14 = - m32 * a5 + m33 * a4 - m34 * a3;
	adj.m21 = - m21 * b5 + m23 * b2 - m24 * b1;
	adj.m22 =   m11 * b5 - m13 * b2 + m14 * b1;
	adj.m23 = - m41 * a5 + m43 * a2 - m44 * a1;
	adj.m24 =   m31 * a5 - m33 * a2 + m34 * a1;
	adj.m31 =   m21 * b4 - m22 * b2 + m24 * b0;
	adj.m32 = - m11 * b4 + m12 * b2 - m14 * b0;
	adj.m33 =   m41 * a4 - m42 * a2 + m44 * a0;
	adj.m34 = - m31 * a4 + m32 * a2 - m34 * a0;
	adj.m41 = - m21 * b3 + m22 * b1 - m23 * b0;
	adj.m42 =   m11 * b3 - m12 * b1 + m13 * b0;
	adj.m43 = - m41 * a3 + m42 * a1 - m43 * a0;
	adj.m44 =   m31 * a3 - m32 * a1 + m33 * a0;

	adj.mulfill( 1.0f / det );
	out = adj;
	return true;
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

inline Vec3 Mat4::transformVec3( const Vec3& v ) const
{
	/*
                      this-> m11 , m12 , m13 , m14
                             m21 , m22 , m23 , m24
                             m31 , m32 , m33 , m34
                             m41 , m42 , m43 , m44 
          v-> x , y , z , 1  dx  , dy  , dz 
	*/
	return Vec3(
		v.x * m11 + v.y * m21 + v.z * m31 + m41,
		v.x * m12 + v.y * m22 + v.z * m32 + m42,
		v.x * m13 + v.y * m23 + v.z * m33 + m43 );
}

inline Vec4 Mat4::transformVec4( const Vec4& v ) const
{
	/*
                      this-> m11 , m12 , m13 , m14
                             m21 , m22 , m23 , m24
                             m31 , m32 , m33 , m34
                             m41 , m42 , m43 , m44 
          v-> x , y , z , w  dx  , dy  , dz  , dw
	*/
	return Vec4(
		v.x * m11 + v.y * m21 + v.z * m31 + v.w * m41,
		v.x * m12 + v.y * m22 + v.z * m32 + v.w * m42,
		v.x * m13 + v.y * m23 + v.z * m33 + v.w * m43,
		v.x * m14 + v.y * m24 + v.z * m34 + v.w * m44 );
}

inline bool Mat4::decompose( Vec3* translation, Quaternion* rotation, Vec3* scale ) const
{
	if( translation )
	{
		// Extract the translation.
		translation->x = m[12];
		translation->y = m[13];
		translation->z = m[14];
	}

	// Nothing left to do.
	if( scale == nullptr && rotation == nullptr )
		return true;

    // Extract the scale.
    // This is simply the length of each axis (row/column) in the matrix.
	Vec3 xaxis( m[0], m[1], m[2] );
	Vec3 yaxis( m[4], m[5], m[6] );
	Vec3 zaxis( m[8], m[9], m[10] );

	float scale_x = xaxis.length();
	float scale_y = yaxis.length();
	float scale_z = zaxis.length();

    // Determine if we have a negative scale (true if determinant is less than zero).
    // In this case, we simply negate a single axis of the scale.
	float det = determinant();
	if( det < 0 )
		scale_z = -scale_z;

	if( scale )
	{
		scale->x = scale_x;
		scale->y = scale_y;
		scale->z = scale_z;
	}

	// Nothing left to do.
	if( rotation == nullptr )
		return true;

	// Scale too close to zero, can't decompose rotation.
	if( magicalFloatIsZero( scale_x ) || 
		magicalFloatIsZero( scale_y ) || 
		magicalFloatIsZero( scale_z ) )
		return false;

    float rn;
    // Factor the scale out of the matrix axes.
    rn = 1.0f / scale_x;
    xaxis.x *= rn;
    xaxis.y *= rn;
    xaxis.z *= rn;

    rn = 1.0f / scale_y;
    yaxis.x *= rn;
    yaxis.y *= rn;
    yaxis.z *= rn;

    rn = 1.0f / scale_z;
    zaxis.x *= rn;
    zaxis.y *= rn;
    zaxis.z *= rn;

    // Now calculate the rotation from the resulting matrix (axes).
    float trace = xaxis.x + yaxis.y + zaxis.z + 1.0f;

	if( magicalFloatIsZero( trace ) == false )
	{
		float s = 0.5f / sqrt( trace );
		rotation->w = 0.25f / s;
		rotation->x = ( yaxis.z - zaxis.y ) * s;
		rotation->y = ( zaxis.x - xaxis.z ) * s;
		rotation->z = ( xaxis.y - yaxis.x ) * s;
	}
	else
	{
		if( xaxis.x > yaxis.y && xaxis.x > zaxis.z )
		{
			float s = 2.0f * sqrt( 1.0f + xaxis.x - yaxis.y - zaxis.z );
			rotation->w = ( yaxis.z - zaxis.y ) / s;
			rotation->x = 0.25f * s;
			rotation->y = ( yaxis.x + xaxis.y ) / s;
			rotation->z = ( zaxis.x + xaxis.z ) / s;
		}
		else if( yaxis.y > zaxis.z )
		{
			float s = 2.0f * sqrt( 1.0f + yaxis.y - xaxis.x - zaxis.z );
			rotation->w = ( zaxis.x - xaxis.z ) / s;
			rotation->x = ( yaxis.x + xaxis.y ) / s;
			rotation->y = 0.25f * s;
			rotation->z = ( zaxis.y + yaxis.z ) / s;
		}
		else
		{
			float s = 2.0f * sqrt( 1.0f + zaxis.z - xaxis.x - yaxis.y );
			rotation->w = ( xaxis.y - yaxis.x ) / s;
			rotation->x = ( zaxis.x + xaxis.z ) / s;
			rotation->y = ( zaxis.y + yaxis.z ) / s;
			rotation->z = 0.25f * s;
		}
	}

    return true;
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

inline void MathMat4::add( Mat4& out, const Mat4& mat, float a )
{
	out.m11 = mat.m11 + a;
	out.m12 = mat.m12 + a;
	out.m13 = mat.m13 + a;
	out.m14 = mat.m14 + a;
	out.m21 = mat.m21 + a;
	out.m22 = mat.m22 + a;
	out.m23 = mat.m23 + a;
	out.m24 = mat.m24 + a;
	out.m31 = mat.m31 + a;
	out.m32 = mat.m32 + a;
	out.m33 = mat.m33 + a;
	out.m34 = mat.m34 + a;
	out.m41 = mat.m41 + a;
	out.m42 = mat.m42 + a;
	out.m43 = mat.m43 + a;
	out.m44 = mat.m44 + a;
}

inline void MathMat4::add( Mat4& out, const Mat4& mat1, const Mat4& mat2 )
{
	out.m11 = mat1.m11 + mat2.m11;
	out.m12 = mat1.m12 + mat2.m12;
	out.m13 = mat1.m13 + mat2.m13;
	out.m14 = mat1.m14 + mat2.m14;
	out.m21 = mat1.m21 + mat2.m21;
	out.m22 = mat1.m22 + mat2.m22;
	out.m23 = mat1.m23 + mat2.m23;
	out.m24 = mat1.m24 + mat2.m24;
	out.m31 = mat1.m31 + mat2.m31;
	out.m32 = mat1.m32 + mat2.m32;
	out.m33 = mat1.m33 + mat2.m33;
	out.m34 = mat1.m34 + mat2.m34;
	out.m41 = mat1.m41 + mat2.m41;
	out.m42 = mat1.m42 + mat2.m42;
	out.m43 = mat1.m43 + mat2.m43;
	out.m44 = mat1.m44 + mat2.m44;
}

inline void MathMat4::sub( Mat4& out, const Mat4& mat, float a )
{
	out.m11 = mat.m11 - a;
	out.m12 = mat.m12 - a;
	out.m13 = mat.m13 - a;
	out.m14 = mat.m14 - a;
	out.m21 = mat.m21 - a;
	out.m22 = mat.m22 - a;
	out.m23 = mat.m23 - a;
	out.m24 = mat.m24 - a;
	out.m31 = mat.m31 - a;
	out.m32 = mat.m32 - a;
	out.m33 = mat.m33 - a;
	out.m34 = mat.m34 - a;
	out.m41 = mat.m41 - a;
	out.m42 = mat.m42 - a;
	out.m43 = mat.m43 - a;
	out.m44 = mat.m44 - a;
}

inline void MathMat4::sub( Mat4& out, const Mat4& mat1, const Mat4& mat2 )
{
	out.m11 = mat1.m11 - mat2.m11;
	out.m12 = mat1.m12 - mat2.m12;
	out.m13 = mat1.m13 - mat2.m13;
	out.m14 = mat1.m14 - mat2.m14;
	out.m21 = mat1.m21 - mat2.m21;
	out.m22 = mat1.m22 - mat2.m22;
	out.m23 = mat1.m23 - mat2.m23;
	out.m24 = mat1.m24 - mat2.m24;
	out.m31 = mat1.m31 - mat2.m31;
	out.m32 = mat1.m32 - mat2.m32;
	out.m33 = mat1.m33 - mat2.m33;
	out.m34 = mat1.m34 - mat2.m34;
	out.m41 = mat1.m41 - mat2.m41;
	out.m42 = mat1.m42 - mat2.m42;
	out.m43 = mat1.m43 - mat2.m43;
	out.m44 = mat1.m44 - mat2.m44;
}

inline void MathMat4::mul( Mat4& out, const Mat4& mat, float a )
{
	out.m11 = mat.m11 * a;
	out.m12 = mat.m12 * a;
	out.m13 = mat.m13 * a;
	out.m14 = mat.m14 * a;
	out.m21 = mat.m21 * a;
	out.m22 = mat.m22 * a;
	out.m23 = mat.m23 * a;
	out.m24 = mat.m24 * a;
	out.m31 = mat.m31 * a;
	out.m32 = mat.m32 * a;
	out.m33 = mat.m33 * a;
	out.m34 = mat.m34 * a;
	out.m41 = mat.m41 * a;
	out.m42 = mat.m42 * a;
	out.m43 = mat.m43 * a;
	out.m44 = mat.m44 * a;
}

inline void MathMat4::mul( Mat4& out, const Mat4& mat1, const Mat4& mat2 )
{
	/*
                               mat2-> m11 , m12 , m13 , m14
                                      m21 , m22 , m23 , m24
                                      m31 , m32 , m33 , m34
                                      m41 , m42 , m43 , m44 
       mat1-> m11 , m12 , m13 , m14   d11 , d12 , d13 , d14
              m21 , m22 , m23 , m24   d21 , d22 , d23 , d24
              m31 , m32 , m33 , m34   d31 , d32 , d33 , d34
              m41 , m42 , m43 , m44   d41 , d42 , d43 , d44
	*/
	Mat4 dst;
	dst.m11 = mat1.m11 * mat2.m11 + mat1.m12 * mat2.m21 + mat1.m13 * mat2.m31 + mat1.m14 * mat2.m41;
	dst.m12 = mat1.m11 * mat2.m12 + mat1.m12 * mat2.m22 + mat1.m13 * mat2.m32 + mat1.m14 * mat2.m42;
	dst.m13 = mat1.m11 * mat2.m13 + mat1.m12 * mat2.m23 + mat1.m13 * mat2.m33 + mat1.m14 * mat2.m43;
	dst.m14 = mat1.m11 * mat2.m14 + mat1.m12 * mat2.m24 + mat1.m13 * mat2.m34 + mat1.m14 * mat2.m44;
	dst.m21 = mat1.m21 * mat2.m11 + mat1.m22 * mat2.m21 + mat1.m23 * mat2.m31 + mat1.m24 * mat2.m41;
	dst.m22 = mat1.m21 * mat2.m12 + mat1.m22 * mat2.m22 + mat1.m23 * mat2.m32 + mat1.m24 * mat2.m42;
	dst.m23 = mat1.m21 * mat2.m13 + mat1.m22 * mat2.m23 + mat1.m23 * mat2.m33 + mat1.m24 * mat2.m43;
	dst.m24 = mat1.m21 * mat2.m14 + mat1.m22 * mat2.m24 + mat1.m23 * mat2.m34 + mat1.m24 * mat2.m44;
	dst.m31 = mat1.m31 * mat2.m11 + mat1.m32 * mat2.m21 + mat1.m33 * mat2.m31 + mat1.m34 * mat2.m41;
	dst.m32 = mat1.m31 * mat2.m12 + mat1.m32 * mat2.m22 + mat1.m33 * mat2.m32 + mat1.m34 * mat2.m42;
	dst.m33 = mat1.m31 * mat2.m13 + mat1.m32 * mat2.m23 + mat1.m33 * mat2.m33 + mat1.m34 * mat2.m43;
	dst.m34 = mat1.m31 * mat2.m14 + mat1.m32 * mat2.m24 + mat1.m33 * mat2.m34 + mat1.m34 * mat2.m44;
	dst.m41 = mat1.m41 * mat2.m11 + mat1.m42 * mat2.m21 + mat1.m43 * mat2.m31 + mat1.m44 * mat2.m41;
	dst.m42 = mat1.m41 * mat2.m12 + mat1.m42 * mat2.m22 + mat1.m43 * mat2.m32 + mat1.m44 * mat2.m42;
	dst.m43 = mat1.m41 * mat2.m13 + mat1.m42 * mat2.m23 + mat1.m43 * mat2.m33 + mat1.m44 * mat2.m43;
	dst.m44 = mat1.m41 * mat2.m14 + mat1.m42 * mat2.m24 + mat1.m43 * mat2.m34 + mat1.m44 * mat2.m44;

	memcpy( out.m, dst.m, kMatrix4x4Size );
}

inline void MathMat4::transpose( Mat4& out, const Mat4& mat )
{
	float t[16] = {
		mat.m11, mat.m21, mat.m31, mat.m41,
		mat.m12, mat.m22, mat.m32, mat.m42,
		mat.m13, mat.m23, mat.m33, mat.m43,
		mat.m14, mat.m24, mat.m34, mat.m44
	};
	memcpy( out.m, t, kMatrix4x4Size );
}

inline void MathMat4::negate( Mat4& out, const Mat4& mat )
{
	out.m11 = -mat.m11; out.m12 = -mat.m12; out.m13 = -mat.m13; out.m14 = -mat.m14;
	out.m21 = -mat.m21; out.m22 = -mat.m22; out.m23 = -mat.m23; out.m24 = -mat.m24;
	out.m31 = -mat.m31; out.m32 = -mat.m32; out.m33 = -mat.m33; out.m34 = -mat.m34;
	out.m41 = -mat.m41; out.m42 = -mat.m42; out.m43 = -mat.m43; out.m44 = -mat.m44;
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