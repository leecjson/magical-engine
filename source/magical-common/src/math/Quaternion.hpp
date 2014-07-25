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

#include "PlatformMacros.h"
#include "Common.h"
#include "kazmath/kazmath.h"
#include "Vec3.hpp"

struct Vec3;
class Mathv3;

struct Quaternion
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	Quaternion( float rx, float ry, float rz, float rw );
	Quaternion( const Quaternion& rhs );
	Quaternion( const float* rhs );
	Quaternion( const Vec3& axis, float angle );
	Quaternion( void );

	inline Quaternion operator*( const Quaternion& rhs ) const;
	inline Quaternion& operator=( const Quaternion& rhs );
	inline Quaternion& operator*=( const Quaternion& rhs );

	inline void fill( float rx, float ry, float rz, float rw );
	inline void fill( const Quaternion& rhs );
	inline void fill( const float* rhs );
	inline void fillAxisAngle( const Vec3& axis, float angle );
	inline void fillIdentity( void );
	inline void fillZero( void );

	inline bool isIdentity( void ) const;
	inline bool isZero( void ) const;
	inline void negate( void );
	inline void inverse( void );
	inline void normalize( void );
	inline Vec3 axis( void ) const;
	inline float angle( void ) const;
	inline void lerp( const Quaternion& rhs, float t );
	inline void slerp( const Quaternion& rhs, float t );

public:
	static const Quaternion IDENTITY;
	static const Quaternion ZERO;
};

class Mathq4
{
public:
	static inline Quaternion mul( const Quaternion& lhs, const Quaternion& rhs );

	static inline Quaternion fill( float rx, float ry, float rz, float rw );
	static inline Quaternion fill( const Quaternion& rhs );
	static inline Quaternion fill( const float* rhs );
	static inline Quaternion fillAxisAngle( const Vec3& axis, float angle );
	static inline Quaternion fillIdentity( void );
	static inline Quaternion fillZero( void );

	static inline bool isIdentity( const Quaternion& lhs );
	static inline bool isZero( const Quaternion& lhs );
	static inline Quaternion negate( const Quaternion& lhs );
	static inline Quaternion inverse( const Quaternion& lhs );
	static inline Quaternion normalize( const Quaternion& lhs );
	static inline Vec3 axis( const Quaternion& lhs );
	static inline float angle( const Quaternion& lhs );
	static inline Quaternion lerp( const Quaternion& lhs, const Quaternion& rhs, float t );
	static inline Quaternion slerp( const Quaternion& lhs, const Quaternion& rhs, float t );
};

#include "Quaternion.inl"
	
#endif //__QUATERNION_HPP__