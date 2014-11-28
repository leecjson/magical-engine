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

inline bool Quaternion::operator==( const Quaternion& q ) const
{
	return magicalQuaternionEquals( tofpointer( this ), tofpointer( &q ) );
}

inline bool Quaternion::operator!=( const Quaternion& q ) const
{
	return !magicalQuaternionEquals( tofpointer( this ), tofpointer( &q ) );
}

inline Quaternion Quaternion::operator+( const Quaternion& q ) const
{
	return Quaternion( x + q.x, y + q.y, z + q.z, w + q.w );
}

inline Quaternion Quaternion::operator-( const Quaternion& q ) const
{
	return Quaternion( x - q.x, y - q.y, z - q.z, w - q.w );
}

inline Quaternion Quaternion::operator*( const float a ) const
{
	return Quaternion( x * a, y * a, z * a, w * a );
}

inline Quaternion Quaternion::operator*( const Quaternion& r ) const
{
	Quaternion ret;
	magicalQuaternionMul( tofpointer( &ret ), tofpointer( this ), tofpointer( &r ) );
	return ret;
}

inline Quaternion& Quaternion::operator*=( const Quaternion& r )
{
	magicalQuaternionMul( tofpointer( this ), tofpointer( this ), tofpointer( &r ) );
	return *this;
}

inline Quaternion& Quaternion::operator=( const Quaternion& r )
{
	x = r.x; y = r.y; z = r.z; w = r.w;
	return *this;
}

inline bool Quaternion::isIdentity( void ) const
{
	return magicalQuaternionIsIdentity( tofpointer( this ) );
}

inline bool Quaternion::isZero( void ) const
{
	return magicalQuaternionIsZero( tofpointer( this ) );
}

inline bool Quaternion::isNormalize( void ) const
{
	return magicalQuaternionIsNormalize( tofpointer( this ) );
}

inline void Quaternion::fill( const Quaternion& r )
{
	x = r.x;
	y = r.y;
	z = r.z;
	w = r.w;
}

inline void Quaternion::fill( float x, float y, float z, float w )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

inline void Quaternion::fillIdentity( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 1.0f;
}

inline void Quaternion::fillZero( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

inline void Quaternion::fillAxisAngle( const Vec3& axis, const float angle )
{
	magicalQuaternionFromAxisAngle( tofpointer( this ), tofpointer( &axis ), angle );
}

inline void Quaternion::fillEulerAngles( const EulerAngles& ea )
{
	magicalQuaternionFromEulerAngles( tofpointer( this ), tofpointer( &ea ) );
}

inline void Quaternion::fillYawPitchRoll( const float yaw, const float pitch, const float roll )
{
	magicalQuaternionFromEulerYawPitchRoll( tofpointer( this ), yaw, pitch, roll );
}

inline void Quaternion::fillMat4( const Mat4& m )
{
	magicalQuaternionFromMat4( tofpointer( this ), tofpointer( &m ) );
}

inline void Quaternion::fillRotationX( const float angle )
{
	magicalQuaternionFillRotationX( tofpointer( this ), angle );
}

inline void Quaternion::fillRotationY( const float angle )
{
	magicalQuaternionFillRotationY( tofpointer( this ), angle );
}

inline void Quaternion::fillRotationZ( const float angle )
{
	magicalQuaternionFillRotationZ( tofpointer( this ), angle );
}

inline void Quaternion::negate( void )
{

}

inline void Quaternion::inverse( void )
{
	float n = x * x + y * y + z * z + w * w;
	if( magicalAlmostEqual( n, 1.0f ) )
	{
		x = -x;
		y = -y;
		z = -z;
		return;
	}

	if( magicalAlmostZero( n ) )
		return;

	n = 1.0f / n;
	x = -x * n;
	y = -y * n;
	z = -z * n;
	w = w * n;
}

inline void Quaternion::normalize( void )
{
	float n = x * x + y * y + z * z + w * w;
	if( magicalAlmostEqual( n, 1.0f ) )
		return;

	n = sqrt( n );
	if( magicalAlmostZero( n ) )
		return;

	n = 1.0f / n;
	x *= n;
	y *= n;
	z *= n;
	w *= n;
}

inline float Quaternion::axisAngle( Vec3& axis ) const
{
	Quaternion q( x, y, z, w );
	q.normalize();

	axis.x = q.x;
	axis.y = q.y;
	axis.z = q.z;
	axis.normalize();

	return 2.0f * acos( q.w );
}

inline void Quaternion::lerp( const Quaternion& rhs, float t )
{
	//magicalAssert( !( t < 0.0f || t > 1.0f ), "Invaiid operate" );

	if( magicalAlmostZero( t ) )
	{
		return;
	}	
	else if( magicalAlmostEqual( t, 1.0f ) )
	{
		memcpy( this, &rhs, sizeof(float) * 4 );
		return;
	}

	float t1 = 1.0f - t;

	x = t1 * x + t * rhs.x;
	y = t1 * y + t * rhs.y;
	z = t1 * z + t * rhs.z;
	w = t1 * w + t * rhs.w;
}

inline Quaternion MathQuaternion::negate( const Quaternion& lhs )
{
	Quaternion ret( lhs );
	ret.negate();
	return ret;
}

inline Quaternion MathQuaternion::inverse( const Quaternion& lhs )
{
	Quaternion ret( lhs );
	ret.inverse();
	return ret;
}

inline Quaternion MathQuaternion::normalize( const Quaternion& lhs )
{
	Quaternion ret( lhs );
	ret.normalize();
	return ret;
}

inline float MathQuaternion::axisAngle( const Quaternion& lhs, Vec3& axis )
{
	return lhs.axisAngle( axis );
}

inline Quaternion MathQuaternion::lerp( const Quaternion& lhs, const Quaternion& rhs, float t )
{
	Quaternion ret( lhs );
	ret.lerp( rhs, t );
	return ret;
}

inline Quaternion MathQuaternion::slerp( const Quaternion& lhs, const Quaternion& rhs, float t )
{
	Quaternion ret( lhs );
	ret.slerp( rhs, t );
	return ret;
}