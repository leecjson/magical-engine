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
#ifndef __VEC3_HPP__
#define __VEC3_HPP__

#include "Common.h"
#include "kazmath.h"

class vec3 : public kmVec3
{
public:
	vec3( const vec2& v )
	{
		x = v.x;
		y = v.y;
		z = 0.0f;
	}

	vec3( const float rx, const float ry, const float rz )
	{
		x = rx;
		y = ry;
		z = rz;
	}

	vec3( void )
	{
		x = y = z = 0.0f;
	}

	inline vec3 operator+( float rhs ) const
	{
		return vec3( x + rhs, y + rhs, z + rhs );
	}

	inline vec3 operator+( const vec3& rhs ) const
	{
		return vec3( x + rhs.x, y + rhs.y, z + rhs.z );
	}

	inline vec3 operator-( float rhs ) const
	{
		return vec3( x - rhs, y - rhs, z - rhs );
	}

	inline vec3 operator-( const vec3& rhs ) const
	{
		return vec3( x - rhs.x, y - rhs.y, z - rhs.z );
	}

	inline vec3 operator*( float rhs ) const
	{
		return vec3( x * rhs, y * rhs, z * rhs );
	}

	inline vec3 operator*( const vec3& rhs ) const
	{
		return vec3( x * rhs.x, y * rhs.y, z * rhs.z);
	}

	inline vec3 operator/( float rhs ) const
	{
		magicalAssert( rhs, "division by 0.f" );
		return vec3( x / rhs, y / rhs, z / rhs );
	}

	inline vec3 operator/( const vec3& rhs ) const
	{
		magicalAssert( rhs.x && rhs.y && rhs.z, "division by 0.f" );
		return vec3( x / rhs.x, y / rhs.y, z / rhs.z );
	}


	inline vec3& operator+=( const vec3& rhs )
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	inline vec3& operator+=( float rhs )
	{
		x += rhs;
		y += rhs;
		z += rhs;
		return *this;
	}

	inline vec3& operator-=( const vec3& rhs )
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	inline vec3& operator-=( float rhs )
	{
		x -= rhs;
		y -= rhs;
		z -= rhs;
		return *this;
	}

	inline vec3& operator*=( const vec3& rhs )
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	inline vec3& operator*=( float rhs  )
	{
		x *= rhs;
		y *= rhs;
		z *= rhs;
		return *this;
	}

	inline vec3& operator/=( const vec3& rhs )
	{
		magicalAssert( rhs.x && rhs.y && rhs.z, "division by 0.f" );
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return *this;
	}

	inline vec3& operator/=( float rhs  )
	{
		magicalAssert( rhs, "division by 0.f" );
		x /= rhs;
		y /= rhs;
		z /= rhs;
		return *this;
	}

	inline bool operator==( const vec3& rhs )
	{
		return kmVec3AreEqual( this, &rhs ) != 0;
	}

	inline bool operator!=( const vec3& rhs )
	{
		return kmVec3AreEqual( this, &rhs ) == 0;
	}

public:
	static inline vec3 fill( const float x, const float y, const float z )
	{
		vec3 result;
		kmVec3Fill( &result, x, y, z );
		return result;
	}

	static inline float length( const vec3& v )
	{
		return kmVec3Length( &v );
	}

	static inline float lengthSq( const vec3& v )
	{
		return kmVec3LengthSq( &v );
	}

	static inline vec3 lerp( const vec3& v1, const vec3& v2, const float t )
	{
		vec3 result;
		kmVec3Lerp( &result, &v1, &v2, t );
		return result;
	}

	static inline vec3 normalize( const vec3& v )
	{
		vec3 result;
		kmVec3Normalize( &result, &v );
		return result;
	}

	static inline vec3 cross( const vec3& v1, const vec3& v2 )
	{
		vec3 result;
		kmVec3Cross( &result, &v1, &v2 );
		return result;
	}

	static inline float dot( const vec3& v1, const vec3& v2 )
	{
		return kmVec3Dot( &v1, &v2 );
	}

	static inline vec3 multiplyMat3( const vec3& v, const mat3& m )
	{
		vec3 result;
		kmVec3MultiplyMat3( &result, &v, &m );
		return result;
	}

	static inline vec3 multiplyMat4( const vec3& v, const mat4& m )
	{
		vec3 result;
		kmVec3MultiplyMat4( &result, &v, &m );
		return result;
	}

	static inline vec3 transform( const vec3& v, const mat4& m )
	{
		vec3 result;
		kmVec3Transform( &result, &v, &m );
		return result;
	}

	static inline vec3 transformNormal( const vec3& v, const mat4& m )
	{
		vec3 result;
		kmVec3TransformNormal( &result, &v, &m );
		return result;
	}

	static inline vec3 transformCoord( const vec3& v, const mat4& m )
	{
		vec3 result;
		kmVec3TransformCoord( &result, &v, &m );
		return result;
	}

	static inline vec3 scale( const vec3& v, const float s )
	{
		vec3 result;
		kmVec3Scale( &result, &v, s );
		return result;
	}

	static inline vec3 inverseTransform( const vec3& v, const mat4& m )
	{
		vec3 result;
		kmVec3InverseTransform( &result, &v, &m );
		return result;
	}

	static inline vec3 inverseTransformNormal( const vec3& v, const mat4& m )
	{
		vec3 result;
		kmVec3InverseTransformNormal( &result, &v, &m );
		return result;
	}

	static inline vec3 getHorizontalAngle( const vec3& v )
	{
		vec3 result;
		kmVec3GetHorizontalAngle( &result, &v );
		return result;
	}

	static inline vec3 rotationToDirection( const vec3& v, const vec3& forwards )
	{
		vec3 result;
		kmVec3RotationToDirection( &result, &v, &forwards );
		return result;
	}

	//static inline vec3 projectOnToPlane( const vec3& v,  )	
};

inline vec3 operator*( const float lhs, const vec3& rhs )
{
	return rhs * lhs;
}




#endif //__VEC3_HPP__