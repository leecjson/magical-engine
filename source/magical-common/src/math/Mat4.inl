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

inline Mat4 Mat4::operator+( float scalar ) const
{
	Mat4 dst;
	dst.mat[0]  = mat[0]  + scalar;
	dst.mat[1]  = mat[1]  + scalar;
	dst.mat[2]  = mat[2]  + scalar;
	dst.mat[3]  = mat[3]  + scalar;
	dst.mat[4]  = mat[4]  + scalar;
	dst.mat[5]  = mat[5]  + scalar;
	dst.mat[6]  = mat[6]  + scalar;
	dst.mat[7]  = mat[7]  + scalar;
	dst.mat[8]  = mat[8]  + scalar;
	dst.mat[9]  = mat[9]  + scalar;
	dst.mat[10] = mat[10] + scalar;
	dst.mat[11] = mat[11] + scalar;
	dst.mat[12] = mat[12] + scalar;
	dst.mat[13] = mat[13] + scalar;
	dst.mat[14] = mat[14] + scalar;
	dst.mat[15] = mat[15] + scalar;
	return dst;
}

inline Mat4 Mat4::operator+( const Mat4& rhs ) const
{
	Mat4 dst;
	dst.mat[0]  = mat[0]  + rhs.mat[0];
	dst.mat[1]  = mat[1]  + rhs.mat[1];
	dst.mat[2]  = mat[2]  + rhs.mat[2];
	dst.mat[3]  = mat[3]  + rhs.mat[3];
	dst.mat[4]  = mat[4]  + rhs.mat[4];
	dst.mat[5]  = mat[5]  + rhs.mat[5];
	dst.mat[6]  = mat[6]  + rhs.mat[6];
	dst.mat[7]  = mat[7]  + rhs.mat[7];
	dst.mat[8]  = mat[8]  + rhs.mat[8];
	dst.mat[9]  = mat[9]  + rhs.mat[9];
	dst.mat[10] = mat[10] + rhs.mat[10];
	dst.mat[11] = mat[11] + rhs.mat[11];
	dst.mat[12] = mat[12] + rhs.mat[12];
	dst.mat[13] = mat[13] + rhs.mat[13];
	dst.mat[14] = mat[14] + rhs.mat[14];
	dst.mat[15] = mat[15] + rhs.mat[15];
	return dst;
}

inline Mat4 Mat4::operator-( float scalar ) const
{
	Mat4 dst;
	dst.mat[0]  = mat[0]  - scalar;
	dst.mat[1]  = mat[1]  - scalar;
	dst.mat[2]  = mat[2]  - scalar;
	dst.mat[3]  = mat[3]  - scalar;
	dst.mat[4]  = mat[4]  - scalar;
	dst.mat[5]  = mat[5]  - scalar;
	dst.mat[6]  = mat[6]  - scalar;
	dst.mat[7]  = mat[7]  - scalar;
	dst.mat[8]  = mat[8]  - scalar;
	dst.mat[9]  = mat[9]  - scalar;
	dst.mat[10] = mat[10] - scalar;
	dst.mat[11] = mat[11] - scalar;
	dst.mat[12] = mat[12] - scalar;
	dst.mat[13] = mat[13] - scalar;
	dst.mat[14] = mat[14] - scalar;
	dst.mat[15] = mat[15] - scalar;
	return dst;
}

inline Mat4 Mat4::operator-( const Mat4& rhs ) const
{
	Mat4 dst;
	dst.mat[0]  = mat[0]  - rhs.mat[0];
	dst.mat[1]  = mat[1]  - rhs.mat[1];
	dst.mat[2]  = mat[2]  - rhs.mat[2];
	dst.mat[3]  = mat[3]  - rhs.mat[3];
	dst.mat[4]  = mat[4]  - rhs.mat[4];
	dst.mat[5]  = mat[5]  - rhs.mat[5];
	dst.mat[6]  = mat[6]  - rhs.mat[6];
	dst.mat[7]  = mat[7]  - rhs.mat[7];
	dst.mat[8]  = mat[8]  - rhs.mat[8];
	dst.mat[9]  = mat[9]  - rhs.mat[9];
	dst.mat[10] = mat[10] - rhs.mat[10];
	dst.mat[11] = mat[11] - rhs.mat[11];
	dst.mat[12] = mat[12] - rhs.mat[12];
	dst.mat[13] = mat[13] - rhs.mat[13];
	dst.mat[14] = mat[14] - rhs.mat[14];
	dst.mat[15] = mat[15] - rhs.mat[15];
	return dst;
}

inline Mat4 Mat4::operator*( float scalar ) const
{
	Mat4 dst;
	dst.mat[0]  = mat[0]  * scalar;
	dst.mat[1]  = mat[1]  * scalar;
	dst.mat[2]  = mat[2]  * scalar;
	dst.mat[3]  = mat[3]  * scalar;
	dst.mat[4]  = mat[4]  * scalar;
	dst.mat[5]  = mat[5]  * scalar;	
	dst.mat[6]  = mat[6]  * scalar;
	dst.mat[7]  = mat[7]  * scalar;
	dst.mat[8]  = mat[8]  * scalar;
	dst.mat[9]  = mat[9]  * scalar;
	dst.mat[10] = mat[10] * scalar;
	dst.mat[11] = mat[11] * scalar;
	dst.mat[12] = mat[12] * scalar;
	dst.mat[13] = mat[13] * scalar;
	dst.mat[14] = mat[14] * scalar;
	dst.mat[15] = mat[15] * scalar;
	return dst;
}

inline Mat4 Mat4::operator*( const Mat4& rhs ) const
{
	Mat4 dst;
	dst.mat[0]  = mat[0] * rhs.mat[0]  + mat[4] * rhs.mat[1]  + mat[8]  * rhs.mat[2]  + mat[12] * rhs.mat[3];
	dst.mat[1]  = mat[1] * rhs.mat[0]  + mat[5] * rhs.mat[1]  + mat[9]  * rhs.mat[2]  + mat[13] * rhs.mat[3];
	dst.mat[2]  = mat[2] * rhs.mat[0]  + mat[6] * rhs.mat[1]  + mat[10] * rhs.mat[2]  + mat[14] * rhs.mat[3];
	dst.mat[3]  = mat[3] * rhs.mat[0]  + mat[7] * rhs.mat[1]  + mat[11] * rhs.mat[2]  + mat[15] * rhs.mat[3];

	dst.mat[4]  = mat[0] * rhs.mat[4]  + mat[4] * rhs.mat[5]  + mat[8]  * rhs.mat[6]  + mat[12] * rhs.mat[7];
	dst.mat[5]  = mat[1] * rhs.mat[4]  + mat[5] * rhs.mat[5]  + mat[9]  * rhs.mat[6]  + mat[13] * rhs.mat[7];
	dst.mat[6]  = mat[2] * rhs.mat[4]  + mat[6] * rhs.mat[5]  + mat[10] * rhs.mat[6]  + mat[14] * rhs.mat[7];
	dst.mat[7]  = mat[3] * rhs.mat[4]  + mat[7] * rhs.mat[5]  + mat[11] * rhs.mat[6]  + mat[15] * rhs.mat[7];
	 
	dst.mat[8]  = mat[0] * rhs.mat[8]  + mat[4] * rhs.mat[9]  + mat[8]  * rhs.mat[10] + mat[12] * rhs.mat[11];
	dst.mat[9]  = mat[1] * rhs.mat[8]  + mat[5] * rhs.mat[9]  + mat[9]  * rhs.mat[10] + mat[13] * rhs.mat[11];
	dst.mat[10] = mat[2] * rhs.mat[8]  + mat[6] * rhs.mat[9]  + mat[10] * rhs.mat[10] + mat[14] * rhs.mat[11];
	dst.mat[11] = mat[3] * rhs.mat[8]  + mat[7] * rhs.mat[9]  + mat[11] * rhs.mat[10] + mat[15] * rhs.mat[11];

	dst.mat[12] = mat[0] * rhs.mat[12] + mat[4] * rhs.mat[13] + mat[8]  * rhs.mat[14] + mat[12] * rhs.mat[15];
	dst.mat[13] = mat[1] * rhs.mat[12] + mat[5] * rhs.mat[13] + mat[9]  * rhs.mat[14] + mat[13] * rhs.mat[15];
	dst.mat[14] = mat[2] * rhs.mat[12] + mat[6] * rhs.mat[13] + mat[10] * rhs.mat[14] + mat[14] * rhs.mat[15];
	dst.mat[15] = mat[3] * rhs.mat[12] + mat[7] * rhs.mat[13] + mat[11] * rhs.mat[14] + mat[15] * rhs.mat[15];
	return dst;
}

inline Mat4& Mat4::operator=( const Mat4& rhs )
{
	memcpy( this, &rhs, kMat4Size );
	return *this;
}

inline Mat4& Mat4::operator+=( float scalar )
{
	mat[0]  = mat[0]  + scalar;
	mat[1]  = mat[1]  + scalar;
	mat[2]  = mat[2]  + scalar;
	mat[3]  = mat[3]  + scalar;
	mat[4]  = mat[4]  + scalar;
	mat[5]  = mat[5]  + scalar;
	mat[6]  = mat[6]  + scalar;
	mat[7]  = mat[7]  + scalar;
	mat[8]  = mat[8]  + scalar;
	mat[9]  = mat[9]  + scalar;
	mat[10] = mat[10] + scalar;
	mat[11] = mat[11] + scalar;
	mat[12] = mat[12] + scalar;
	mat[13] = mat[13] + scalar;
	mat[14] = mat[14] + scalar;
	mat[15] = mat[15] + scalar;
	return *this;
}

inline Mat4& Mat4::operator+=( const Mat4& rhs )
{
	mat[0]  = mat[0]  + rhs.mat[0];
	mat[1]  = mat[1]  + rhs.mat[1];
	mat[2]  = mat[2]  + rhs.mat[2];
	mat[3]  = mat[3]  + rhs.mat[3];
	mat[4]  = mat[4]  + rhs.mat[4];
	mat[5]  = mat[5]  + rhs.mat[5];
	mat[6]  = mat[6]  + rhs.mat[6];
	mat[7]  = mat[7]  + rhs.mat[7];
	mat[8]  = mat[8]  + rhs.mat[8];
	mat[9]  = mat[9]  + rhs.mat[9];
	mat[10] = mat[10] + rhs.mat[10];
	mat[11] = mat[11] + rhs.mat[11];
	mat[12] = mat[12] + rhs.mat[12];
	mat[13] = mat[13] + rhs.mat[13];
	mat[14] = mat[14] + rhs.mat[14];
	mat[15] = mat[15] + rhs.mat[15];
	return *this;
}

inline Mat4& Mat4::operator-=( float scalar )
{
	mat[0]  = mat[0]  - scalar;
	mat[1]  = mat[1]  - scalar;
	mat[2]  = mat[2]  - scalar;
	mat[3]  = mat[3]  - scalar;
	mat[4]  = mat[4]  - scalar;
	mat[5]  = mat[5]  - scalar;
	mat[6]  = mat[6]  - scalar;
	mat[7]  = mat[7]  - scalar;
	mat[8]  = mat[8]  - scalar;
	mat[9]  = mat[9]  - scalar;
	mat[10] = mat[10] - scalar;
	mat[11] = mat[11] - scalar;
	mat[12] = mat[12] - scalar;
	mat[13] = mat[13] - scalar;
	mat[14] = mat[14] - scalar;
	mat[15] = mat[15] - scalar;
	return *this;
}

inline Mat4& Mat4::operator-=( const Mat4& rhs )
{
	mat[0]  = mat[0]  - rhs.mat[0];
	mat[1]  = mat[1]  - rhs.mat[1];
	mat[2]  = mat[2]  - rhs.mat[2];
	mat[3]  = mat[3]  - rhs.mat[3];
	mat[4]  = mat[4]  - rhs.mat[4];
	mat[5]  = mat[5]  - rhs.mat[5];
	mat[6]  = mat[6]  - rhs.mat[6];
	mat[7]  = mat[7]  - rhs.mat[7];
	mat[8]  = mat[8]  - rhs.mat[8];
	mat[9]  = mat[9]  - rhs.mat[9];
	mat[10] = mat[10] - rhs.mat[10];
	mat[11] = mat[11] - rhs.mat[11];
	mat[12] = mat[12] - rhs.mat[12];
	mat[13] = mat[13] - rhs.mat[13];
	mat[14] = mat[14] - rhs.mat[14];
	mat[15] = mat[15] - rhs.mat[15];
	return *this;
}

inline Mat4& Mat4::operator*=( float scalar )
{
	mat[0]  = mat[0]  * scalar;
	mat[1]  = mat[1]  * scalar;
	mat[2]  = mat[2]  * scalar;
	mat[3]  = mat[3]  * scalar;
	mat[4]  = mat[4]  * scalar;
	mat[5]  = mat[5]  * scalar;
	mat[6]  = mat[6]  * scalar;
	mat[7]  = mat[7]  * scalar;
	mat[8]  = mat[8]  * scalar;
	mat[9]  = mat[9]  * scalar;
	mat[10] = mat[10] * scalar;
	mat[11] = mat[11] * scalar;
	mat[12] = mat[12] * scalar;
	mat[13] = mat[13] * scalar;
	mat[14] = mat[14] * scalar;
	mat[15] = mat[15] * scalar;
	return *this;
}

inline Mat4& Mat4::operator*=( const Mat4& rhs )
{
	Mat4 dst;
	dst.mat[0]  = mat[0] * rhs.mat[0]  + mat[4] * rhs.mat[1]  + mat[8]  * rhs.mat[2]  + mat[12] * rhs.mat[3];
	dst.mat[1]  = mat[1] * rhs.mat[0]  + mat[5] * rhs.mat[1]  + mat[9]  * rhs.mat[2]  + mat[13] * rhs.mat[3];
	dst.mat[2]  = mat[2] * rhs.mat[0]  + mat[6] * rhs.mat[1]  + mat[10] * rhs.mat[2]  + mat[14] * rhs.mat[3];
	dst.mat[3]  = mat[3] * rhs.mat[0]  + mat[7] * rhs.mat[1]  + mat[11] * rhs.mat[2]  + mat[15] * rhs.mat[3];

	dst.mat[4]  = mat[0] * rhs.mat[4]  + mat[4] * rhs.mat[5]  + mat[8]  * rhs.mat[6]  + mat[12] * rhs.mat[7];
	dst.mat[5]  = mat[1] * rhs.mat[4]  + mat[5] * rhs.mat[5]  + mat[9]  * rhs.mat[6]  + mat[13] * rhs.mat[7];
	dst.mat[6]  = mat[2] * rhs.mat[4]  + mat[6] * rhs.mat[5]  + mat[10] * rhs.mat[6]  + mat[14] * rhs.mat[7];
	dst.mat[7]  = mat[3] * rhs.mat[4]  + mat[7] * rhs.mat[5]  + mat[11] * rhs.mat[6]  + mat[15] * rhs.mat[7];

	dst.mat[8]  = mat[0] * rhs.mat[8]  + mat[4] * rhs.mat[9]  + mat[8]  * rhs.mat[10] + mat[12] * rhs.mat[11];
	dst.mat[9]  = mat[1] * rhs.mat[8]  + mat[5] * rhs.mat[9]  + mat[9]  * rhs.mat[10] + mat[13] * rhs.mat[11];
	dst.mat[10] = mat[2] * rhs.mat[8]  + mat[6] * rhs.mat[9]  + mat[10] * rhs.mat[10] + mat[14] * rhs.mat[11];
	dst.mat[11] = mat[3] * rhs.mat[8]  + mat[7] * rhs.mat[9]  + mat[11] * rhs.mat[10] + mat[15] * rhs.mat[11];

	dst.mat[12] = mat[0] * rhs.mat[12] + mat[4] * rhs.mat[13] + mat[8]  * rhs.mat[14] + mat[12] * rhs.mat[15];
	dst.mat[13] = mat[1] * rhs.mat[12] + mat[5] * rhs.mat[13] + mat[9]  * rhs.mat[14] + mat[13] * rhs.mat[15];
	dst.mat[14] = mat[2] * rhs.mat[12] + mat[6] * rhs.mat[13] + mat[10] * rhs.mat[14] + mat[14] * rhs.mat[15];
	dst.mat[15] = mat[3] * rhs.mat[12] + mat[7] * rhs.mat[13] + mat[11] * rhs.mat[14] + mat[15] * rhs.mat[15];

	memcpy( this, &dst, kMat4Size );
	return *this;
}

inline bool Mat4::isIdentity( void ) const
{
	return memcmp( &Identity, this, kMat4Size ) == 0;
}

inline Mat4 Mat4::copy( void )
{
	return Mat4( *this );
}

inline void Mat4::fill(
	float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44 )
{
	mat[0]  = m11; mat[1]  = m12; mat[2]  = m13; mat[3]  = m14;
	mat[4]  = m21; mat[5]  = m22; mat[6]  = m23; mat[7]  = m24;
	mat[8]  = m31; mat[9]  = m32; mat[10] = m33; mat[11] = m34;
	mat[12] = m41; mat[13] = m42; mat[14] = m43; mat[15] = m44;
}

inline void Mat4::fill( const float* m )
{
	magicalAssert( m, "should not be nullptr" );
	memcpy( this->mat, m, kMat4Size );
}

inline void Mat4::fill( const Mat4& m )
{
	memcpy( this, &m, kMat4Size );
}

inline void Mat4::fillZero( void )
{
	memset( mat, 0, kMat4Size );
}

inline void Mat4::fillIdentity( void )
{
	memset( mat, 0, kMat4Size );

	this->mat[0]  = 1.0f;
	this->mat[5]  = 1.0f;
	this->mat[10] = 1.0f;
	this->mat[15] = 1.0f;
}

inline void Mat4::fillLookAt( const Vec3& eye, const Vec3& target, const Vec3& up )
{
	Vec3 up_v = up;
	up_v.normalize();

	Vec3 zaxis = MathVec3::sub( eye, target );
	zaxis.normalize();

	Vec3 xaxis = MathVec3::cross( up_v, zaxis );
	xaxis.normalize();

	Vec3 yaxis = MathVec3::cross( zaxis, xaxis );
	yaxis.normalize();

	mat[0] = xaxis.x;
	mat[1] = yaxis.x;
	mat[2] = zaxis.x;
	mat[3] = 0.0f;

	mat[4] = xaxis.y;
	mat[5] = yaxis.y;
	mat[6] = zaxis.y;
	mat[7] = 0.0f;

	mat[8] = xaxis.z;
	mat[9] = yaxis.z;
	mat[10] = zaxis.z;
	mat[11] = 0.0f;

	mat[12] = - MathVec3::dot( xaxis, eye );
	mat[13] = - MathVec3::dot( yaxis, eye );
	mat[14] = - MathVec3::dot( zaxis, eye );
	mat[15] = 1.0f;
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

	memcpy( this, &Identity, kMat4Size );
	mat[0]  = cotangent / aspect;
	mat[5]  = cotangent;
	mat[10] = -( zfar + znear ) / delta_z;
	mat[11] = -1;
	mat[14] = -2 * znear * zfar / delta_z;
	mat[15] = 0;
}

inline void Mat4::fillOrthographic( float left, float right, float bottom, float top, float near, float far )
{
	float tx = -( ( right + left ) / ( right - left ) );
	float ty = -( ( top + bottom ) / ( top - bottom ) );
	float tz = -( ( far + near ) / ( far - near ) );

	memcpy( this, &Identity, kMat4Size );
	mat[0]  = 2 / ( right - left );
	mat[5]  = 2 / ( top - bottom );
	mat[10] = -2 / ( far - near );
	mat[12] = tx;
	mat[13] = ty;
	mat[14] = tz;
}

inline void Mat4::fillScale( const Vec3& scale )
{
    memcpy( this, &Identity, kMat4Size );

    mat[0]  = scale.x;
    mat[5]  = scale.y;
    mat[10] = scale.z;
}

inline void Mat4::fillScale( float x, float y, float z )
{
	memcpy( this, &Identity, kMat4Size );

    mat[0]  = x;
    mat[5]  = y;
    mat[10] = z;
}

inline void Mat4::fillRotation( const Quaternion& q )
{
	float x2 = q.x + q.x;
    float y2 = q.y + q.y;
    float z2 = q.z + q.z;

    float xx2 = q.x * x2;
    float yy2 = q.y * y2;
    float zz2 = q.z * z2;
    float xy2 = q.x * y2;
    float xz2 = q.x * z2;
    float yz2 = q.y * z2;
    float wx2 = q.w * x2;
    float wy2 = q.w * y2;
    float wz2 = q.w * z2;

    mat[0] = 1.0f - yy2 - zz2;
    mat[1] = xy2 + wz2;
    mat[2] = xz2 - wy2;
    mat[3] = 0.0f;

    mat[4] = xy2 - wz2;
    mat[5] = 1.0f - xx2 - zz2;
    mat[6] = yz2 + wx2;
    mat[7] = 0.0f;

    mat[8] = xz2 + wy2;
    mat[9] = yz2 - wx2;
    mat[10] = 1.0f - xx2 - yy2;
    mat[11] = 0.0f;

    mat[12] = 0.0f;
    mat[13] = 0.0f;
    mat[14] = 0.0f;
    mat[15] = 1.0f;
}

inline void Mat4::fillRotation( const Vec3& axis, float angle )
{
	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	// Make sure the input axis is normalized.
	float n = x * x + y * y + z * z;
	if( magicalFloatEquals( n, 1.0f ) == false )
	{
		// Not normalized.
		n = sqrt( n );
		// Prevent divide too close to zero.
		if( n > FLT_EPSILON )
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

	mat[0] = c + tx*x;
	mat[1] = txy + sz;
	mat[2] = txz - sy;
	mat[3] = 0.0f;

	mat[4] = txy - sz;
	mat[5] = c + ty*y;
	mat[6] = tyz + sx;
	mat[7] = 0.0f;

	mat[8] = txz + sy;
	mat[9] = tyz - sx;
	mat[10] = c + tz*z;
	mat[11] = 0.0f;

	mat[12] = 0.0f;
	mat[13] = 0.0f;
	mat[14] = 0.0f;
	mat[15] = 1.0f;
}

inline void Mat4::fillRotationX( float angle )
{
	memcpy( this, &Identity, kMat4Size );

	float c = cos( angle );
	float s = sin( angle );

	mat[5] = c;
	mat[6] = s;
	mat[9] = -s;
	mat[10] = c;
}

inline void Mat4::fillRotationY( float angle )
{
	memcpy( this, &Identity, kMat4Size );

	float c = cos( angle );
	float s = sin( angle );

	mat[0] = c;
	mat[2] = -s;
	mat[8] = s;
	mat[10] = c;
}

inline void Mat4::fillRotationZ( float angle )
{
	memcpy( this, &Identity, kMat4Size );

    float c = cos(angle);
    float s = sin(angle);

    mat[0] = c;
    mat[1] = s;
    mat[4] = -s;
    mat[5] = c;
}

inline void Mat4::fillTranslation( const Vec3& translation )
{
	memcpy( this, &Identity, kMat4Size );

    mat[12] = translation.x;
    mat[13] = translation.y;
    mat[14] = translation.z;
}

inline void Mat4::fillTranslation( float x, float y, float z )
{
	memcpy( this, &Identity, kMat4Size );

    mat[12] = x;
    mat[13] = y;
    mat[14] = z;
}


inline Vec3 Mat4::getUpVector( void ) const
{
	return Vec3( mat[4], mat[5], mat[6] );
}

inline Vec3 Mat4::getDownVector( void ) const
{
	return Vec3( -mat[4], -mat[5], -mat[6] );
}

inline Vec3 Mat4::getLeftVector( void ) const
{
	return Vec3( -mat[0], -mat[1], -mat[2] );
}

inline Vec3 Mat4::getRightVector( void ) const
{
	return Vec3( mat[0], mat[1], mat[2] );
}

inline Vec3 Mat4::getForwardVector( void ) const
{
	return Vec3( -mat[8], -mat[9], -mat[10] );
}

inline Vec3 Mat4::getBackVector( void ) const
{
	return Vec3( mat[8], mat[9], mat[10] );
}

inline void Mat4::inverse( void )
{
	float a0 = mat[0] * mat[5] - mat[1] * mat[4];
	float a1 = mat[0] * mat[6] - mat[2] * mat[4];
	float a2 = mat[0] * mat[7] - mat[3] * mat[4];
	float a3 = mat[1] * mat[6] - mat[2] * mat[5];
	float a4 = mat[1] * mat[7] - mat[3] * mat[5];
	float a5 = mat[2] * mat[7] - mat[3] * mat[6];
	float b0 = mat[8] * mat[13] - mat[9] * mat[12];
	float b1 = mat[8] * mat[14] - mat[10] * mat[12];
	float b2 = mat[8] * mat[15] - mat[11] * mat[12];
	float b3 = mat[9] * mat[14] - mat[10] * mat[13];
	float b4 = mat[9] * mat[15] - mat[11] * mat[13];
	float b5 = mat[10] * mat[15] - mat[11] * mat[14];

	// Calculate the determinant.
	float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

	// Close to zero, can't invert.
	if( magicalFloatIsZero( det ) )
		return;

	// Support the case where m == dst.
	Mat4 inverse;
	inverse.mat[0] = mat[5] * b5 - mat[6] * b4 + mat[7] * b3;
	inverse.mat[1] = -mat[1] * b5 + mat[2] * b4 - mat[3] * b3;
	inverse.mat[2] = mat[13] * a5 - mat[14] * a4 + mat[15] * a3;
	inverse.mat[3] = -mat[9] * a5 + mat[10] * a4 - mat[11] * a3;

	inverse.mat[4] = -mat[4] * b5 + mat[6] * b2 - mat[7] * b1;
	inverse.mat[5] = mat[0] * b5 - mat[2] * b2 + mat[3] * b1;
	inverse.mat[6] = -mat[12] * a5 + mat[14] * a2 - mat[15] * a1;
	inverse.mat[7] = mat[8] * a5 - mat[10] * a2 + mat[11] * a1;

	inverse.mat[8] = mat[4] * b4 - mat[5] * b2 + mat[7] * b0;
	inverse.mat[9] = -mat[0] * b4 + mat[1] * b2 - mat[3] * b0;
	inverse.mat[10] = mat[12] * a4 - mat[13] * a2 + mat[15] * a0;
	inverse.mat[11] = -mat[8] * a4 + mat[9] * a2 - mat[11] * a0;

	inverse.mat[12] = -mat[4] * b3 + mat[5] * b1 - mat[6] * b0;
	inverse.mat[13] = mat[0] * b3 - mat[1] * b1 + mat[2] * b0;
	inverse.mat[14] = -mat[12] * a3 + mat[13] * a1 - mat[14] * a0;
	inverse.mat[15] = mat[8] * a3 - mat[9] * a1 + mat[10] * a0;

	*this = inverse * ( 1.0f / det );
}

inline void Mat4::negate( void )
{
	mat[0]  = -mat[0];
	mat[1]  = -mat[1];
	mat[2]  = -mat[2];
	mat[3]  = -mat[3];
	mat[4]  = -mat[4];
	mat[5]  = -mat[5];
	mat[6]  = -mat[6];
	mat[7]  = -mat[7];
	mat[8]  = -mat[8];
	mat[9]  = -mat[9];
	mat[10] = -mat[10];
	mat[11] = -mat[11];
	mat[12] = -mat[12];
	mat[13] = -mat[13];
	mat[14] = -mat[14];
	mat[15] = -mat[15];
}

inline void Mat4::rotate( const Quaternion& q )
{
	Mat4 dst;
	dst.fillRotation( q );
	*this *= dst;
}

inline void Mat4::rotate( const Vec3& axis, float angle )
{
	Mat4 dst;
	dst.fillRotation( axis, angle );
	*this *= dst;
}

inline void Mat4::rotateX( float angle )
{
	Mat4 dst;
	dst.fillRotationX( angle );
	*this *= dst;
}

inline void Mat4::rotateY( float angle )
{
	Mat4 dst;
	dst.fillRotationY( angle );
	*this *= dst;
}

inline void Mat4::rotateZ( float angle )
{
	Mat4 dst;
	dst.fillRotationZ( angle );
	*this *= dst;
}

inline void Mat4::scale( float scale )
{
	Mat4 dst;
	dst.fillScale( scale, scale, scale );
	*this *= dst;
}

inline void Mat4::scale( float x, float y, float z )
{
	Mat4 dst;
	dst.fillScale( x, y, z );
	*this *= dst;
}

inline void Mat4::scale( const Vec3& scale )
{
	Mat4 dst;
	dst.fillScale( scale );
	*this *= dst;
}

inline void Mat4::translate( float x, float y, float z )
{
	Mat4 dst;
	dst.fillTranslation( x, y, z );
	*this *= dst;
}

inline void Mat4::translate( const Vec3& t )
{
	Mat4 dst;
	dst.fillTranslation( t );
	*this *= dst;
}

inline void Mat4::transpose( void )
{
	float t[16] = {
		mat[0], mat[4], mat[8], mat[12],
		mat[1], mat[5], mat[9], mat[13],
		mat[2], mat[6], mat[10], mat[14],
		mat[3], mat[7], mat[11], mat[15]
	};
	memcpy( this, t, kMat4Size );
}

inline Vec3 Mat4::transformPoint( const Vec3& point ) const
{
	return transformVec3( point );
}

inline Vec3 Mat4::transformVec3( const Vec3& vec ) const
{
    float x = vec.x * mat[0] + vec.y * mat[4] + vec.z * mat[8]  + mat[12];
    float y = vec.x * mat[1] + vec.y * mat[5] + vec.z * mat[9]  + mat[13];
    float z = vec.x * mat[2] + vec.y * mat[6] + vec.z * mat[10] + mat[14];

	return Vec3( x, y, z );
}

inline Vec4 Mat4::transformVec4( const Vec4& vec ) const
{
	float x = vec.x * mat[0] + vec.y * mat[4] + vec.z * mat[8]  + vec.w * mat[12];
    float y = vec.x * mat[1] + vec.y * mat[5] + vec.z * mat[9]  + vec.w * mat[13];
    float z = vec.x * mat[2] + vec.y * mat[6] + vec.z * mat[10] + vec.w * mat[14];
    float w = vec.x * mat[3] + vec.y * mat[7] + vec.z * mat[11] + vec.w * mat[15];
	
	return Vec4( x, y, z, w );
}

inline float Mat4::determinant( void ) const
{
	float a0 = mat[0] * mat[5] - mat[1] * mat[4];
	float a1 = mat[0] * mat[6] - mat[2] * mat[4];
	float a2 = mat[0] * mat[7] - mat[3] * mat[4];
	float a3 = mat[1] * mat[6] - mat[2] * mat[5];
	float a4 = mat[1] * mat[7] - mat[3] * mat[5];
	float a5 = mat[2] * mat[7] - mat[3] * mat[6];
	float b0 = mat[8] * mat[13] - mat[9] * mat[12];
	float b1 = mat[8] * mat[14] - mat[10] * mat[12];
	float b2 = mat[8] * mat[15] - mat[11] * mat[12];
	float b3 = mat[9] * mat[14] - mat[10] * mat[13];
	float b4 = mat[9] * mat[15] - mat[11] * mat[13];
	float b5 = mat[10] * mat[15] - mat[11] * mat[14];

	return ( a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0 );
}

inline bool Mat4::decompose( Vec3* translation, Quaternion* rotation, Vec3* scale ) const
{
	if( translation )
	{
		// Extract the translation.
		translation->x = mat[12];
		translation->y = mat[13];
		translation->z = mat[14];
	}

	// Nothing left to do.
	if( scale == nullptr && rotation == nullptr )
		return true;

    // Extract the scale.
    // This is simply the length of each axis (row/column) in the matrix.
	Vec3 xaxis( mat[0], mat[1], mat[2] );
	Vec3 yaxis( mat[4], mat[5], mat[6] );
	Vec3 zaxis( mat[8], mat[9], mat[10] );

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

inline Mat4 MathMat4::add( const Mat4& lhs, float scalar )
{
	return lhs + scalar;
}

inline Mat4 MathMat4::add( const Mat4& lhs, const Mat4& rhs )
{
	return lhs + rhs;
}

inline Mat4 MathMat4::sub( const Mat4& lhs, float scalar )
{
	return lhs - scalar;
}

inline Mat4 MathMat4::sub( const Mat4& lhs, const Mat4& rhs )
{
	return lhs - rhs;
}

inline Mat4 MathMat4::mul( const Mat4& lhs, float scalar )
{
	return lhs * scalar;
}

inline Mat4 MathMat4::mul( const Mat4& lhs, const Mat4& rhs )
{
	return lhs * rhs;
}

inline bool MathMat4::isIdentity( const Mat4& m )
{
	return m.isIdentity();
}

inline Mat4 MathMat4::copy( const Mat4& m )
{
	return Mat4( m );
}

inline Mat4 MathMat4::fill(
	float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44 )
{
	return Mat4(
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44
		);
}

inline Mat4 MathMat4::fill( const float* m )
{
	return Mat4( m );
}

inline Mat4 MathMat4::fill( const Mat4& m )
{
	return Mat4( m );
}

inline Mat4 MathMat4::fillIdentity( void )
{
	return Mat4();
}

inline Mat4 MathMat4::fillZero( void )
{
	Mat4 ret;
	ret.fillZero();
	return ret;
}

inline Mat4 MathMat4::fillLookAt( const Vec3& eye, const Vec3& target, const Vec3& up )
{
	Mat4 ret;
	ret.fillLookAt( eye, target, up );
	return ret;
}

inline Mat4 MathMat4::fillPerspective( float fov, float aspect, float znear, float zfar )
{
	Mat4 ret;
	ret.fillPerspective( fov, aspect, znear, zfar );
	return ret;
}

inline Mat4 MathMat4::fillOrthographic( float left, float right, float bottom, float top, float near, float far )
{
	Mat4 ret;
	ret.fillOrthographic( left, right, bottom, top, near, far );
	return ret;
}

inline Mat4 MathMat4::fillScale( const Vec3& scale )
{
	Mat4 ret;
	ret.fillScale( scale );
	return ret;
}

inline Mat4 MathMat4::fillScale( float x, float y, float z )
{
	Mat4 ret;
	ret.fillScale( x, y, z );
	return ret;
}

inline Mat4 MathMat4::fillRotation( const Quaternion& q )
{
	Mat4 ret;
	ret.fillRotation( q );
	return ret;
}

inline Mat4 MathMat4::fillRotation( const Vec3& axis, float angle )
{
	Mat4 ret;
	ret.fillRotation( axis, angle );
	return ret;
}

inline Mat4 MathMat4::fillRotationX( float angle )
{
	Mat4 ret;
	ret.fillRotationX( angle );
	return ret;
}

inline Mat4 MathMat4::fillRotationY( float angle )
{
	Mat4 ret;
	ret.fillRotationY( angle );
	return ret;
}

inline Mat4 MathMat4::fillRotationZ( float angle )
{
	Mat4 ret;
	ret.fillRotationZ( angle );
	return ret;
}

inline Mat4 MathMat4::fillTranslation( const Vec3& translation )
{
	Mat4 ret;
	ret.fillTranslation( translation );
	return ret;
}

inline Mat4 MathMat4::fillTranslation( float x, float y, float z )
{
	Mat4 ret;
	ret.fillTranslation( x, y, z );
	return ret;
}

inline Vec3 MathMat4::getUpVector( const Mat4& m )
{
	return m.getUpVector();
}

inline Vec3 MathMat4::getDownVector( const Mat4& m )
{
	return m.getDownVector();
}

inline Vec3 MathMat4::getLeftVector( const Mat4& m )
{
	return m.getLeftVector();
}

inline Vec3 MathMat4::getRightVector( const Mat4& m )
{
	return m.getRightVector();
}

inline Vec3 MathMat4::getForwardVector( const Mat4& m )
{
	return m.getForwardVector();
}

inline Vec3 MathMat4::getBackVector( const Mat4& m )
{
	return m.getBackVector();
}

inline Mat4 MathMat4::inverse( const Mat4& m )
{
	Mat4 ret( m );
	ret.inverse();
	return ret;
}

inline Mat4 MathMat4::negate( const Mat4& m )
{
	Mat4 ret( m );
	ret.negate();
	return ret;
}

inline Mat4 MathMat4::rotate( const Mat4& m, const Quaternion& q )
{
	Mat4 ret( m );
	ret.rotate( q );
	return ret;
}

inline Mat4 MathMat4::rotate( const Mat4& m, const Vec3& axis, float angle )
{
	Mat4 ret( m );
	ret.rotate( axis, angle );
	return ret;
}

inline Mat4 MathMat4::rotateX( const Mat4& m, float angle )
{
	Mat4 ret( m );
	ret.rotateX( angle );
	return ret;
}

inline Mat4 MathMat4::rotateY( const Mat4& m, float angle )
{
	Mat4 ret( m );
	ret.rotateY( angle );
	return ret;
}

inline Mat4 MathMat4::rotateZ( const Mat4& m, float angle )
{
	Mat4 ret( m );
	ret.rotateZ( angle );
	return ret;
}

inline Mat4 MathMat4::scale( const Mat4& m, float scale )
{
	Mat4 ret( m );
	ret.scale( scale );
	return ret;
}

inline Mat4 MathMat4::scale( const Mat4& m, float x, float y, float z )
{
	Mat4 ret( m );
	ret.scale( x, y, z );
	return ret;
}

inline Mat4 MathMat4::scale( const Mat4& m, const Vec3& scale )
{
	Mat4 ret( m );
	ret.scale( scale );
	return ret;
}

inline Mat4 MathMat4::translate( const Mat4& m, float x, float y, float z )
{
	Mat4 ret( m );
	ret.translate( x, y, z );
	return ret;
}

inline Mat4 MathMat4::translate( const Mat4& m, const Vec3& t )
{
	Mat4 ret( m );
	ret.translate( t );
	return ret;
}

inline Mat4 MathMat4::transpose( const Mat4& m )
{
	Mat4 ret( m );
	ret.transpose();
	return ret;
}

inline Vec3 MathMat4::transformPoint( const Mat4& m, const Vec3& point )
{
	return m.transformPoint( point );
}

inline Vec3 MathMat4::transformVec3( const Mat4& m, const Vec3& vec )
{
	return m.transformVec3( vec );
}

inline Vec4 MathMat4::transformVec4( const Mat4& m, const Vec4& vec )
{
	return m.transformVec4( vec );
}

inline float MathMat4::determinant( const Mat4& m )
{
	return m.determinant();
}

inline bool MathMat4::decompose( const Mat4& m, Vec3* translation, Quaternion* rotation, Vec3* scale )
{
	return m.decompose( translation, rotation, scale );
}

inline Vec3 MathMat4::getTranslation( const Mat4& m )
{
	return m.getTranslation();
}

inline Quaternion MathMat4::getRotation( const Mat4& m )
{
	return m.getRotation();
}

inline Vec3 MathMat4::getScale( const Mat4& m )
{
	return m.getScale();
}