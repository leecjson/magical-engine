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

	inline float length( void ) const
	{
		return kmVec3Length( this );
	}

	inline float lengthSq( void ) const
	{
		return kmVec3LengthSq( this );
	}

	inline vec3 normalize( void ) const
	{
		vec3 result;
		kmVec3Normalize( &result, this );
		return result;
	}

	//inline const vec3 transform( const kmMat4& mat ) const
	//{
	//	vec3 result;
	//	kmVec3Transform( &result, this, &mat );
	//	return result;
	//}

	//// Transforms a 3D vector by a given matrix, projecting the result back into w = 1.
	//inline const vec3 transformCoord( const kmMat4& mat ) const
	//{
	//	vec3 result;
	//	kmVec3TransformCoord( (kmVec3*)(&result), (kmVec3*)this, &mat);
	//	return result;
	//}

	//// Transforms the vector ignoring the translation part
	//inline const vec3 transformNormal( const kmMat4& mat ) const
	//{
	//	vec3 result;
	//	kmVec3TransformNormal( (kmVec3*)(&result), (kmVec3*)this, &mat);
	//	return result;
	//}

	inline vec3 cross( const vec3& vec ) const
	{
		vec3 result;
		kmVec3Cross( &result, this, &vec );
		return result;
	}

	inline float dot( const vec3& rhs ) const
	{
		return kmVec3Dot( this, &rhs );
	}

	/*inline vec3 inverseTransform( const kmMat4& mat ) const
	{
		vec3 result;
		kmVec3InverseTransform( &result, this, &mat );
		return result;
	}

	inline vec3 inverseTransformNormal( const kmMat4& mat ) const
	{
		vec3 result;
		kmVec3InverseTransformNormal( &result, this, &mat );
		return result;
	}*/

	inline vec3 operator+( float rhs ) const
	{
		return vec3( x + rhs, y + rhs, z + rhs );
	}

	inline vec3 operator+( const vec3& rhs ) const
	{
		return vec3( x + rhs.x, y + rhs.y, z + rhs.z );
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

	inline vec3 operator-( float rhs ) const
	{
		return vec3( x - rhs, y - rhs, z - rhs );
	}

	inline vec3 operator-( const vec3& rhs ) const
	{
		return vec3( x - rhs.x, y - rhs.y, z - rhs.z );
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

	inline vec3 operator*( float rhs ) const
	{
		return vec3( x * rhs, y * rhs, z * rhs );
	}

	inline vec3 operator*( const vec3& rhs ) const
	{
		return vec3( x * rhs.x, y * rhs.y, z * rhs.z);
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
};

inline vec3 operator*( const float lhs, const vec3& rhs )
{
	return rhs * lhs;
}

//// Transform through matrix	
//inline const vec3 operator*( const kmMat4& lhs, const vec3& rhs )
//{
//	vec3 result;
//	kmVec3Transform( (kmVec3*)(&result), (kmVec3*)(&rhs), &lhs);
//	return result;
//}




#endif //__VEC3_HPP__