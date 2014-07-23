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
#include "kazmath/kazmath.h"
#include "Vec2.hpp"
#include "Mat3.hpp"
#include "Mat4.hpp"

struct Vec2;
struct Mat3;
struct Mat4;

struct Vec3 : public kmVec3
{
public:
	Vec3( const Vec2& v );
	Vec3( float rx, float ry, float rz );
	Vec3( void );

	inline Vec3 operator+( float rhs ) const;
	inline Vec3 operator+( const Vec3& rhs ) const;
	inline Vec3 operator-( float rhs ) const;
	inline Vec3 operator-( const Vec3& rhs ) const;
	inline Vec3 operator*( float rhs ) const;
	inline Vec3 operator*( const Vec3& rhs ) const;
	inline Vec3 operator/( float rhs ) const;
	inline Vec3 operator/( const Vec3& rhs ) const;

	inline Vec3& operator+=( const Vec3& rhs );
	inline Vec3& operator+=( float rhs );
	inline Vec3& operator-=( const Vec3& rhs );
	inline Vec3& operator-=( float rhs );
	inline Vec3& operator*=( const Vec3& rhs );
	inline Vec3& operator*=( float rhs  );
	inline Vec3& operator/=( const Vec3& rhs );
	inline Vec3& operator/=( float rhs  );

	inline bool operator==( const Vec3& rhs );
	inline bool operator!=( const Vec3& rhs );

	inline bool isZero( void );

public:
	static inline Vec3  fill( float x, float y, float z );
	static inline float length( const Vec3& v );
	static inline float lengthSq( const Vec3& v );
	static inline Vec3  lerp( const Vec3& v1, const Vec3& v2, const float t );
	static inline Vec3  normalize( const Vec3& v );
	static inline Vec3  cross( const Vec3& v1, const Vec3& v2 );
	static inline float dot( const Vec3& v1, const Vec3& v2 );
	static inline Vec3  multiplyMat3( const Vec3& v, const Mat3& m );
	static inline Vec3  multiplyMat4( const Vec3& v, const Mat4& m );
	static inline Vec3  transform( const Vec3& v, const Mat4& m );
	static inline Vec3  transformNormal( const Vec3& v, const Mat4& m );
	static inline Vec3  transformCoord( const Vec3& v, const Mat4& m );
	static inline Vec3  scale( const Vec3& v, const float s );
	static inline Vec3  inverseTransform( const Vec3& v, const Mat4& m );
	static inline Vec3  inverseTransformNormal( const Vec3& v, const Mat4& m );
	static inline Vec3  getHorizontalAngle( const Vec3& v );
	static inline Vec3  rotationToDirection( const Vec3& v, const Vec3& forwards );

	//static inline Vec3 projectOnToPlane( const Vec3& v,  )	

public:
	static const Vec3 ZERO;
};

#include "Vec3.inl"

#endif //__VEC3_HPP__