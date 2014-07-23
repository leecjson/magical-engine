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

inline Mat4 Mat4::operator*( const Mat4& rhs ) const
{
	Mat4 result;
	kmMat4Multiply( &result, this, &rhs );
	return result;
}

inline bool Mat4::operator==( const Mat4& rhs ) const
{
	return kmMat4AreEqual( this, &rhs ) != 0;
}

inline bool Mat4::operator!=( const Mat4& rhs ) const
{
	return kmMat4AreEqual( this, &rhs ) == 0;
}

inline void Mat4::fill( const float* mat )
{
	kmMat4Fill( this, mat );
}

inline void Mat4::fill( float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44 )
{
	float mat[16] = {
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44
	};
	kmMat4Fill( this, mat );
}

inline void Mat4::identity( void )
{
	kmMat4Identity( this );
}

inline Mat4 Mat4::copy( void ) const
{
	Mat4 result;
	kmMat4Assign( &result, this );
	return result;
}

inline bool Mat4::isIdentity( void ) const
{
	return kmMat4IsIdentity( this ) == 0;
}

inline Mat4 Mat4::inverse( void ) const
{
	Mat4 result;
	kmMat4Inverse( &result, this );
	return result;
}

inline Mat4 Mat4::transpose( void ) const
{
	Mat4 result;
	kmMat4Transpose( &result, this );
	return result;
}

inline void Mat4::rotationX( float radians )
{
	kmMat4RotationX( this, radians );
}

inline void Mat4::rotationY( float radians )
{
	kmMat4RotationY( this, radians );
}

inline void Mat4::rotationZ( float radians )
{
	kmMat4RotationZ( this, radians );
}

inline void Mat4::rotationYawPitchRoll( float pitch, float yaw, float roll )
{
	kmMat4RotationYawPitchRoll( this, pitch, yaw, roll );
}

inline void Mat4::rotationQuaternion( const Quaternion& q )
{
	kmMat4RotationQuaternion( this, &q );
}

inline void Mat4::rotationTranslation( const Mat3& rotation, const Vec3& translation )
{
	kmMat4RotationTranslation( this, &rotation, &translation );
}

inline void Mat4::rotationAxisAngle( const Vec3& axis, float radians )
{
	kmMat4RotationAxisAngle( this, &axis, radians );
}

inline void Mat4::rotationToAxisAngle( Vec3& out_vec, float& out_radians ) const
{
	kmMat4RotationToAxisAngle( &out_vec, &out_radians, this );
}

inline void Mat4::scaling( float x, float y, float z )
{
	kmMat4Scaling( this, x, y, z );
}

inline void Mat4::translation( float x, float y, float z )
{
	kmMat4Translation( this, x, y, z );
}

inline Vec3 Mat4::getUpVec3( void ) const
{
	Vec3 result;
	kmMat4GetUpVec3( &result, this );
	return result;
}

inline Vec3 Mat4::getRightVec3( void ) const
{
	Vec3 result;
	kmMat4GetRightVec3( &result, this );
	return result;
}

inline Vec3 Mat4::getForwardVec3RH( void ) const
{
	Vec3 result;
	kmMat4GetForwardVec3RH( &result, this );
	return result;
}

inline Vec3 Mat4::getForwardVec3LH( void ) const
{
	Vec3 result;
	kmMat4GetForwardVec3LH( &result, this );
	return result;
}

inline void Mat4::setPerspectiveProjection( float foxy, float aspect, float znear, float zfar )
{
	kmMat4PerspectiveProjection( this, foxy, aspect, znear, zfar );
}

inline void Mat4::setOrthographicProjection( float left, float right, float bottom, float top, float znear, float zfar )
{
	kmMat4OrthographicProjection( this, left, right, bottom, top, znear, zfar );
}

inline void Mat4::setLookAt( const Vec3& eye, const Vec3& center, const Vec3& up )
{
	kmMat4LookAt( this, &eye, &center, &up );
}

inline Mat4 Mat4::create( void )
{
	Mat4 result;
	result.identity();
	return result;
}

static inline Vec3 operator*( const Mat4& lhs, const Vec3& rhs )
{
	Vec3 result;
	kmVec3Transform( &result, &rhs, &lhs );
	return result;
}

static inline Vec4 operator*( const Mat4& lhs, const Vec4& rhs )
{
	Vec4 result;
	kmVec4Transform( &result, &rhs, &lhs );
	return result;
}