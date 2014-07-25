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

#include "PlatformMacros.h"
#include "Common.h"
#include "Math3D.hpp"

struct Vec3
{
public:
	float x;
	float y;
	float z;

public:
	Vec3( float rx, float ry, float rz );
	Vec3( const Vec3& rhs );
	Vec3( const float* rhs );
	Vec3( void );
	~Vec3( void );

	inline Vec3  operator+( float rhs ) const;
	inline Vec3  operator+( const Vec3& rhs ) const;
	inline Vec3  operator-( float rhs ) const;
	inline Vec3  operator-( const Vec3& rhs ) const;
	inline Vec3  operator*( float rhs ) const;
	inline Vec3  operator*( const Vec3& rhs ) const;
	inline Vec3  operator/( float rhs ) const;
	inline Vec3  operator/( const Vec3& rhs ) const;
	inline Vec3& operator=( const Vec3& rhs );
	inline Vec3& operator+=( const Vec3& rhs );
	inline Vec3& operator+=( float rhs );
	inline Vec3& operator-=( const Vec3& rhs );
	inline Vec3& operator-=( float rhs );
	inline Vec3& operator*=( const Vec3& rhs );
	inline Vec3& operator*=( float rhs  );
	inline Vec3& operator/=( const Vec3& rhs );
	inline Vec3& operator/=( float rhs  );
	inline bool  operator==( const Vec3& rhs ) const;
	inline bool  operator!=( const Vec3& rhs ) const;
	inline bool  isZero( void ) const;

	inline void  fill( float rx, float ry, float rz );
	inline void  fill( const Vec3& rhs );
	inline void  fill( const float* rhs );
	inline void  fillZero( void );
	inline Vec3  copy( void ) const;
	inline void  clamp( const Vec3& min, const Vec3& max );
	inline void  cross( const Vec3& v );
	inline void  negate( void );
	inline void  normalize( void );
	inline void  scale( float scalar );
	inline float angle( const Vec3& v ) const; 
	inline float dot( const Vec3& v ) const;
	inline float distance( const Vec3& v ) const;
	inline float distanceSq( const Vec3& v ) const;
	inline float length( void ) const;
    inline float lengthSq( void ) const;

public:
	static const Vec3 ZERO;
};

class Mathv3
{
public:
	static inline Vec3 add( const Vec3& v1, const Vec3& v2 );
	static inline Vec3 add( const Vec3& v1, float rhs );
	static inline Vec3 sub( const Vec3& v1, const Vec3& v2 );
	static inline Vec3 sub( const Vec3& v1, float rhs );
	static inline Vec3 mul( const Vec3& v1, const Vec3& v2 );
	static inline Vec3 mul( const Vec3& v1, float rhs );
	static inline Vec3 div( const Vec3& v1, const Vec3& v2 );
	static inline Vec3 div( const Vec3& v1, float rhs );
	static inline bool equals( const Vec3& v1, const Vec3& v2 );

	static inline Vec3  fill( float rx, float ry, float rz );
	static inline Vec3  fill( const Vec3& rhs );
	static inline Vec3  fill( const float* rhs );
	static inline Vec3  fillZero( void );
	static inline Vec3  copy( const Vec3 rhs );
	static inline Vec3  clamp( const Vec3& v, const Vec3& min, const Vec3& max );
	static inline Vec3  cross( const Vec3& v1, const Vec3& v2 );
	static inline Vec3  negate( const Vec3& v );
	static inline Vec3  normalize( const Vec3& v );
	static inline Vec3  scale( const Vec3& v, float scalar );
	static inline float angle( const Vec3& v1, const Vec3& v2 );
	static inline float dot( const Vec3& v1, const Vec3& v2 );
	static inline float distance( const Vec3& v1, const Vec3& v2 );
	static inline float distanceSq( const Vec3& v1, const Vec3& v2 );
	static inline float length( const Vec3& v );
	static inline float lengthSq( const Vec3& v );
};

#include "Vec3.inl"

#endif //__VEC3_HPP__