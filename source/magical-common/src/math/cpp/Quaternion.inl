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

inline bool Quaternion::operator==( const Quaternion& rhs ) const
{
	return
		magicalAlmostEqual( x, rhs.x ) &&
		magicalAlmostEqual( y, rhs.y ) &&
		magicalAlmostEqual( z, rhs.z ) &&
		magicalAlmostEqual( w, rhs.w );
}

inline bool Quaternion::operator!=( const Quaternion& rhs ) const
{
	return !( operator==( rhs ) );
}

inline bool Quaternion::isIdentity( void ) const
{
	return 
		magicalAlmostZero( x ) &&
		magicalAlmostZero( y ) &&
		magicalAlmostZero( z ) &&
		magicalAlmostEqual( w, 1.0f );
}

inline bool Quaternion::isZero( void ) const
{
	return 
		magicalAlmostZero( x ) &&
		magicalAlmostZero( y ) &&
		magicalAlmostZero( z ) &&
		magicalAlmostZero( w );
}

inline bool Quaternion::isNormalize( void ) const
{
	float n = x * x + y * y + z * z + w * w;
	return magicalAlmostEqual( n, 1.0f );
}

inline Quaternion Quaternion::operator*( const Quaternion& r ) const
{
	return Quaternion( 
		w * r.x + x * r.w + y * r.z - z * r.y,
		w * r.y - x * r.z + y * r.w + z * r.x,
		w * r.z + x * r.y - y * r.x + z * r.w,
		w * r.w - x * r.x - y * r.y - z * r.z  );
}

inline Quaternion& Quaternion::operator*=( const Quaternion& r )
{
	float rx = w * r.x + x * r.w + y * r.z - z * r.y;
	float ry = w * r.y - x * r.z + y * r.w + z * r.x;
	float rz = w * r.z + x * r.y - y * r.x + z * r.w;
	float rw = w * r.w - x * r.x - y * r.y - z * r.z;

	x = rx;
	y = ry;
	z = rz;
	w = rw;
	return *this;
}

inline Quaternion& Quaternion::operator=( const Quaternion& r )
{
	x = r.x;
	y = r.y;
	z = r.z;
	w = r.w;
	return *this;
}

inline Quaternion Quaternion::mul( const Quaternion& r ) const
{
	return Quaternion( 
		w * r.x + x * r.w + y * r.z - z * r.y,
		w * r.y - x * r.z + y * r.w + z * r.x,
		w * r.z + x * r.y - y * r.x + z * r.w,
		w * r.w - x * r.x - y * r.y - z * r.z  );
}

inline void Quaternion::fillmul( const Quaternion& r )
{
	float rx = w * r.x + x * r.w + y * r.z - z * r.y;
	float ry = w * r.y - x * r.z + y * r.w + z * r.x;
	float rz = w * r.z + x * r.y - y * r.x + z * r.w;
	float rw = w * r.w - x * r.x - y * r.y - z * r.z;

	x = rx;
	y = ry;
	z = rz;
	w = rw;
}

inline Quaternion Quaternion::copy( void ) const
{
	return *this;
}

inline void Quaternion::fill( float x, float y, float z, float w )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

inline void Quaternion::fill( const Quaternion& r )
{
	x = r.x;
	y = r.y;
	z = r.z;
	w = r.w;
}

inline void Quaternion::fillAxisAngle( const Vec3& axis, float angle )
{
	float half_angle = angle * 0.5f;
	float sin_half_angle = sinf( half_angle );

	Vec3 normal( axis );
	normal.normalize();
	x = normal.x * sin_half_angle;
	y = normal.y * sin_half_angle;
	z = normal.z * sin_half_angle;
	w = cosf( half_angle );
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

inline void Quaternion::negate( void )
{
	x = -x;
	y = -y;
	z = -z;
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