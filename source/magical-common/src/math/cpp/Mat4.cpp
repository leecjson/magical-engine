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
#include "Mat4.h"
#include <exception>

const Mat4 Mat4::Identity = Mat4(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
);

const Mat4 Mat4::Zero = Mat4(
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
);

Mat4::Mat4(
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

Mat4::Mat4( const float* mat )
{
	magicalMat4FillVector( m, mat );
}

Mat4::Mat4( const Mat4& mat )
{
	magicalMat4Fill( m, mat.m );
}

Mat4::Mat4( void )
{
	magicalMat4FillIdentity( m );
}

Mat4::~Mat4( void )
{
	
}

#if MAGICAL_MATH_CACHED_POOL_ENABLE
#include "CachedPool.h"
static CachedPool<Mat4> s_mat4_cached_pool( 32, 32 );
#endif

void* Mat4::operator new( size_t s )
{
	if( s != sizeof( Mat4 ) )
		return ::operator new( s );

#if MAGICAL_MATH_CACHED_POOL_ENABLE
	return s_mat4_cached_pool.take();
#else
	void* ptr = malloc( s );

	if( ptr == nullptr )
		throw std::bad_alloc();
	
	return ptr;
#endif
}

void Mat4::operator delete( void* ptr )
{
	if( ptr == nullptr )
		return;
	
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	s_mat4_cached_pool.add( ptr );
#else
	free( ptr );
#endif
}


//
//void Mat4::fillRotation( const Quaternion& r )
//{
//	float x2 = r.x + r.x;
//    float y2 = r.y + r.y;
//    float z2 = r.z + r.z;
//
//    float xx2 = r.x * x2;
//    float yy2 = r.y * y2;
//    float zz2 = r.z * z2;
//    float xy2 = r.x * y2;
//    float xz2 = r.x * z2;
//    float yz2 = r.y * z2;
//    float wx2 = r.w * x2;
//    float wy2 = r.w * y2;
//    float wz2 = r.w * z2;
//
//    m11 = 1.0f - yy2 - zz2;
//    m12 = xy2 + wz2;
//    m13 = xz2 - wy2;
//    m14 = 0.0f;
//    m21 = xy2 - wz2;
//    m22 = 1.0f - xx2 - zz2;
//    m23 = yz2 + wx2;
//    m24 = 0.0f;
//    m31 = xz2 + wy2;
//    m32 = yz2 - wx2;
//    m33 = 1.0f - xx2 - yy2;
//    m34 = 0.0f;
//    m41 = 0.0f;
//    m42 = 0.0f;
//    m43 = 0.0f;
//    m44 = 1.0f;
//}
//
//void Mat4::fillRotation( const Vec3& axis, float angle )
//{
//	float x = axis.x;
//	float y = axis.y;
//	float z = axis.z;
//
//	float n = x * x + y * y + z * z;
//	if( magicalFltEqual( n, 1.0f ) == false )
//	{
//		n = sqrt( n );
//		if( magicalFltIsZero( n ) == false )
//		{
//			n = 1.0f / n;
//			x *= n;
//			y *= n;
//			z *= n;
//		}
//	}
//
//	float c = cos( angle );
//	float s = sin( angle );
//
//	float t = 1.0f - c;
//	float tx = t * x;
//	float ty = t * y;
//	float tz = t * z;
//	float txy = tx * y;
//	float txz = tx * z;
//	float tyz = ty * z;
//	float sx = s * x;
//	float sy = s * y;
//	float sz = s * z;
//
//	m11 = c + tx*x;
//	m12 = txy + sz;
//	m13 = txz - sy;
//	m14 = 0.0f;
//	m21 = txy - sz;
//	m22 = c + ty*y;
//	m23 = tyz + sx;
//	m24 = 0.0f;
//	m31 = txz + sy;
//	m32 = tyz - sx;
//	m33 = c + tz*z;
//	m34 = 0.0f;
//	m41 = 0.0f;
//	m42 = 0.0f;
//	m43 = 0.0f;
//	m44 = 1.0f;
//}
//
//void Mat4::fillLookAt( const Vec3& eye, const Vec3& target, const Vec3& up )
//{
//	Vec3 up_v = up;
//	up_v.normalize();
//
//	Vec3 zaxis = eye - target;
//	zaxis.normalize();
//
//	Vec3 xaxis = up_v.cross( zaxis );
//	xaxis.normalize();
//
//	Vec3 yaxis = zaxis.cross( xaxis );
//	yaxis.normalize();
//
//	m11 = xaxis.x;
//	m12 = yaxis.x;
//	m13 = zaxis.x;
//	m14 = 0.0f;
//	m21 = xaxis.y;
//	m22 = yaxis.y;
//	m23 = zaxis.y;
//	m24 = 0.0f;
//	m31 = xaxis.z;
//	m32 = yaxis.z;
//	m33 = zaxis.z;
//	m34 = 0.0f;
//	m41 = - xaxis.dot( eye );
//	m42 = - yaxis.dot( eye );
//	m43 = - zaxis.dot( eye );
//	m44 = 1.0f;
//}
//
//void Mat4::fillPerspective( float fov, float aspect, float znear, float zfar )
//{
//	float r = magicalDegToRad( fov / 2 );
//	float delta_z = zfar - znear;
//	float s = sin( r );
//	float cotangent = 0;
//
//	magicalAssert( 
//		!magicalFltIsZero( delta_z ) &&
//		!magicalFltIsZero( s ) &&
//		!magicalFltIsZero( aspect ), "should not be 0.0f" );
//	cotangent = cos( r ) / s;
//
//	fillIdentity();
//	m[0]  = cotangent / aspect;
//	m[5]  = cotangent;
//	m[10] = -( zfar + znear ) / delta_z;
//	m[11] = -1;
//	m[14] = -2 * znear * zfar / delta_z;
//	m[15] = 0;
//}
//
//void Mat4::fillOrthographic( float left, float right, float bottom, float top, float near, float far )
//{
//	float tx = -( ( right + left ) / ( right - left ) );
//	float ty = -( ( top + bottom ) / ( top - bottom ) );
//	float tz = -( ( far + near ) / ( far - near ) );
//
//	fillIdentity();
//	m[0]  = 2 / ( right - left );
//	m[5]  = 2 / ( top - bottom );
//	m[10] = -2 / ( far - near );
//	m[12] = tx;
//	m[13] = ty;
//	m[14] = tz;
//}
//
//float Mat4::determinant( void ) const
//{
//	return 
//		( m11 * m22 - m12 * m21 ) *
//		( m33 * m44 - m34 * m43 ) -
//		( m11 * m23 - m13 * m21 ) *
//		( m32 * m44 - m34 * m42 ) +
//		( m11 * m24 - m14 * m21 ) *
//		( m32 * m43 - m33 * m42 ) +
//		( m12 * m23 - m13 * m22 ) *
//		( m31 * m44 - m34 * m41 ) -
//		( m12 * m24 - m14 * m22 ) *
//		( m31 * m43 - m33 * m41 ) +
//		( m13 * m24 - m14 * m23 ) *
//		( m31 * m42 - m32 * m41 );
//}
//
//void Mat4::transpose( void )
//{
//	float t[16] = {
//		m11, m21, m31, m41,
//		m12, m22, m32, m42,
//		m13, m23, m33, m43,
//		m14, m24, m34, m44
//	};
//	memcpy( m, t, MAGICAL_MAT4_SIZE );
//}
//
//void Mat4::negate( void )
//{
//	m11 = -m11; m12 = -m12; m13 = -m13; m14 = -m14;
//	m21 = -m21; m22 = -m22; m23 = -m23; m24 = -m24;
//	m31 = -m31; m32 = -m32; m33 = -m33; m34 = -m34;
//	m41 = -m41; m42 = -m42; m43 = -m43; m44 = -m44;
//}
//
//bool Mat4::getInverse( Mat4& out ) const
//{
//	float a0 = m11 * m22 - m12 * m21;
//    float a1 = m11 * m23 - m13 * m21;
//    float a2 = m11 * m24 - m14 * m21;
//    float a3 = m12 * m23 - m13 * m22;
//    float a4 = m12 * m24 - m14 * m22;
//    float a5 = m13 * m24 - m14 * m23;
//    float b0 = m31 * m42 - m32 * m41;
//    float b1 = m31 * m43 - m33 * m41;
//    float b2 = m31 * m44 - m34 * m41;
//    float b3 = m32 * m43 - m33 * m42;
//    float b4 = m32 * m44 - m34 * m42;
//    float b5 = m33 * m44 - m34 * m43;
//	float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
//
//	if( magicalFltIsZero( det ) )
//		return false;
//
//	Mat4 adj;
//	adj.m11 =   m22 * b5 - m23 * b4 + m24 * b3;
//	adj.m12 = - m12 * b5 + m13 * b4 - m14 * b3;
//	adj.m13 =   m42 * a5 - m43 * a4 + m44 * a3;
//	adj.m14 = - m32 * a5 + m33 * a4 - m34 * a3;
//	adj.m21 = - m21 * b5 + m23 * b2 - m24 * b1;
//	adj.m22 =   m11 * b5 - m13 * b2 + m14 * b1;
//	adj.m23 = - m41 * a5 + m43 * a2 - m44 * a1;
//	adj.m24 =   m31 * a5 - m33 * a2 + m34 * a1;
//	adj.m31 =   m21 * b4 - m22 * b2 + m24 * b0;
//	adj.m32 = - m11 * b4 + m12 * b2 - m14 * b0;
//	adj.m33 =   m41 * a4 - m42 * a2 + m44 * a0;
//	adj.m34 = - m31 * a4 + m32 * a2 - m34 * a0;
//	adj.m41 = - m21 * b3 + m22 * b1 - m23 * b0;
//	adj.m42 =   m11 * b3 - m12 * b1 + m13 * b0;
//	adj.m43 = - m41 * a3 + m42 * a1 - m43 * a0;
//	adj.m44 =   m31 * a3 - m32 * a1 + m33 * a0;
//
//	adj.mulfill( 1.0f / det );
//	out = adj;
//	return true;
//}


//bool Mat4::decompose( Vec3* translation, Quaternion* rotation, Vec3* scale ) const
//{
//	if( translation )
//	{
//		// Extract the translation.
//		translation->x = m[12];
//		translation->y = m[13];
//		translation->z = m[14];
//	}
//
//	// Nothing left to do.
//	if( scale == nullptr && rotation == nullptr )
//		return true;
//
//    // Extract the scale.
//    // This is simply the length of each axis (row/column) in the matrix.
//	Vec3 xaxis( m[0], m[1], m[2] );
//	Vec3 yaxis( m[4], m[5], m[6] );
//	Vec3 zaxis( m[8], m[9], m[10] );
//
//	float scale_x = xaxis.length();
//	float scale_y = yaxis.length();
//	float scale_z = zaxis.length();
//
//    // Determine if we have a negative scale (true if determinant is less than zero).
//    // In this case, we simply negate a single axis of the scale.
//	float det = determinant();
//	if( det < 0 )
//		scale_z = -scale_z;
//
//	if( scale )
//	{
//		scale->x = scale_x;
//		scale->y = scale_y;
//		scale->z = scale_z;
//	}
//
//	// Nothing left to do.
//	if( rotation == nullptr )
//		return true;
//
//	// Scale too close to zero, can't decompose rotation.
//	if( magicalFltIsZero( scale_x ) || 
//		magicalFltIsZero( scale_y ) || 
//		magicalFltIsZero( scale_z ) )
//		return false;
//
//    float rn;
//    // Factor the scale out of the matrix axes.
//    rn = 1.0f / scale_x;
//    xaxis.x *= rn;
//    xaxis.y *= rn;
//    xaxis.z *= rn;
//
//    rn = 1.0f / scale_y;
//    yaxis.x *= rn;
//    yaxis.y *= rn;
//    yaxis.z *= rn;
//
//    rn = 1.0f / scale_z;
//    zaxis.x *= rn;
//    zaxis.y *= rn;
//    zaxis.z *= rn;
//
//    // Now calculate the rotation from the resulting matrix (axes).
//    float trace = xaxis.x + yaxis.y + zaxis.z + 1.0f;
//
//	if( magicalFltIsZero( trace ) == false )
//	{
//		float s = 0.5f / sqrt( trace );
//		rotation->w = 0.25f / s;
//		rotation->x = ( yaxis.z - zaxis.y ) * s;
//		rotation->y = ( zaxis.x - xaxis.z ) * s;
//		rotation->z = ( xaxis.y - yaxis.x ) * s;
//	}
//	else
//	{
//		if( xaxis.x > yaxis.y && xaxis.x > zaxis.z )
//		{
//			float s = 2.0f * sqrt( 1.0f + xaxis.x - yaxis.y - zaxis.z );
//			rotation->w = ( yaxis.z - zaxis.y ) / s;
//			rotation->x = 0.25f * s;
//			rotation->y = ( yaxis.x + xaxis.y ) / s;
//			rotation->z = ( zaxis.x + xaxis.z ) / s;
//		}
//		else if( yaxis.y > zaxis.z )
//		{
//			float s = 2.0f * sqrt( 1.0f + yaxis.y - xaxis.x - zaxis.z );
//			rotation->w = ( zaxis.x - xaxis.z ) / s;
//			rotation->x = ( yaxis.x + xaxis.y ) / s;
//			rotation->y = 0.25f * s;
//			rotation->z = ( zaxis.y + yaxis.z ) / s;
//		}
//		else
//		{
//			float s = 2.0f * sqrt( 1.0f + zaxis.z - xaxis.x - yaxis.y );
//			rotation->w = ( xaxis.y - yaxis.x ) / s;
//			rotation->x = ( zaxis.x + xaxis.z ) / s;
//			rotation->y = ( zaxis.y + yaxis.z ) / s;
//			rotation->z = 0.25f * s;
//		}
//	}
//
//    return true;
//}