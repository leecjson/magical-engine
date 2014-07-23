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
#ifndef __QUATERNION_HPP__
#define __QUATERNION_HPP__

#include "Common.h"
#include "kazmath/kazmath.h"
#include "Vec3.hpp"
#include "Mat4.hpp"

struct Quaternion : public kmQuaternion
{
public:
	Quaternion( void )
	{
		x = y = z = w = 0.0f;
	}

	inline bool operator==( const Quaternion& rhs )
	{
		return kmQuaternionAreEqual( this, &rhs ) != 0;
	}

	inline Quaternion operator*( const Quaternion& rhs )
	{
		Quaternion result;
		kmQuaternionMultiply( &result, this, &rhs );
		return result;
	}

	inline Quaternion operator+( const Quaternion& rhs )
	{
		Quaternion result;
		kmQuaternionAdd( &result, this, &rhs );
		return result;
	}

	inline Quaternion operator-( const Quaternion& rhs )
	{
		Quaternion result;
		kmQuaternionSubtract( &result, this, &rhs );
		return result;
	}

public:
	static inline Quaternion fill( float x, float y, float z, float w )
	{
		Quaternion result;
		kmQuaternionFill( &result, x, y, z, w );
		return result;
	}

	static inline float dot( const Quaternion& q1, const Quaternion& q2 )
	{
		return kmQuaternionDot( &q1, &q2 );
	}

	static inline Quaternion exp( const Quaternion& q )
	{
		Quaternion result;
		kmQuaternionExp( &result, &q );
		return result;
	}

	static inline Quaternion identity( void )
	{
		Quaternion result;
		kmQuaternionIdentity( &result );
		return result;
	}

	static inline Quaternion inverse( const Quaternion& q )
	{
		Quaternion result;
		kmQuaternionInverse( &result, &q );
		return result;
	}

	static inline bool isIdentity( const Quaternion& q )
	{
		return kmQuaternionIsIdentity( &q ) != 0;
	}

	static inline float length( const Quaternion& q )
	{
		return kmQuaternionLength( &q );
	}

	static inline float lengthSq( const Quaternion& q )
	{
		return kmQuaternionLengthSq( &q );
	}

	static inline Quaternion ln( const Quaternion& q )
	{
		Quaternion result;
		kmQuaternionLn( &result, &q );
		return result;
	}

	static inline Quaternion normalize( const Quaternion& q )
	{
		Quaternion result;
		kmQuaternionNormalize( &result, &q );
		return result;
	}

	static inline Quaternion rotationAxisAngle( const Vec3& v, float angle )
	{
		Quaternion result;
		kmQuaternionRotationAxisAngle( &result, &v, angle );
		return result;
	}

	static inline Quaternion rotationMatrix( const Mat3& m )
	{
		Quaternion result;
		kmQuaternionRotationMatrix( &result, &m );
		return result;
	}

	static inline Quaternion rotationPitchYawRoll( float pitch, float yaw, float roll )
	{
		Quaternion result;
		kmQuaternionRotationPitchYawRoll( &result, pitch, yaw, roll );
		return result;
	}

	static inline Quaternion slerp( const Quaternion& q1, const Quaternion& q2, float t )
	{
		Quaternion result;
		kmQuaternionSlerp( &result, &q1, &q2, t );
		return result;
	}
	
	//static inline void toAxisAngle( const Quaternion& q, const Vec3& v, float  )

	static inline Quaternion scale( const Quaternion& q, float s )
	{
		Quaternion result;
		kmQuaternionScale( &result, &q, s );
		return result;
	}

	static inline Quaternion assign( const Quaternion& q )
	{
		Quaternion result;
		kmQuaternionAssign( &result, &q );
		return result;
	}

	static inline Quaternion rotationBetweenVec3( const Vec3& v1, const Vec3& v2, const Vec3& fallback )
	{
		Quaternion result;
		kmQuaternionRotationBetweenVec3( &result, &v1, &v2, &fallback );
		return result;
	}

	static inline Vec3 getUpVec3( const Quaternion& q )
	{
		Vec3 result;
		kmQuaternionGetUpVec3( &result, &q );
		return result;
	}

	static inline Vec3 getRightVec3( const Quaternion& q )
	{
		Vec3 result;
		kmQuaternionGetRightVec3( &result, &q );
		return result;
	}

	static inline Vec3 getForwardVec3RH( const Quaternion& q )
	{
		Vec3 result;
		kmQuaternionGetForwardVec3RH( &result, &q );
		return result;
	}

	static inline Vec3 getForwardVec3LH( const Quaternion& q )
	{
		Vec3 result;
		kmQuaternionGetForwardVec3LH( &result, &q );
		return result;
	}

	static inline float getPitch( const Quaternion& q )
	{
		return kmQuaternionGetPitch( &q );
	}

	static inline float getYaw( const Quaternion& q )
	{
		return kmQuaternionGetYaw( &q );
	}

	static inline float getRoll( const Quaternion& q )
	{
		return kmQuaternionGetRoll( &q );
	}

	static inline Quaternion lookRotation( const Vec3& direction, const Vec3& up )
	{
		Quaternion result;
		kmQuaternionLookRotation( &result, &direction, &up );
		return result;
	}


};
	
#endif //__QUATERNION_HPP__