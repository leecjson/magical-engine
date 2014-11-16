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

#include "MathMacros.h"
#include "Vec3.h"

struct Vec3;
class MathVec3;

struct Quaternion
{
public:
	static const Quaternion Identity;
	static const Quaternion Zero;

public:
	float x;
	float y;
	float z;
	float w;

	Quaternion( float x, float y, float z, float w );
	Quaternion( const Quaternion& r );
	Quaternion( const Vec3& axis, float angle );
	Quaternion( void );

	inline bool operator==( const Quaternion& rhs ) const;
	inline bool operator!=( const Quaternion& rhs ) const;
	inline bool isIdentity( void ) const;
	inline bool isZero( void ) const;
	inline bool isNormalize( void ) const;

	inline Quaternion operator*( const Quaternion& r ) const;
	inline Quaternion& operator*=( const Quaternion& r );
	inline Quaternion& operator=( const Quaternion& r );
	
	inline Quaternion mul( const Quaternion& r ) const;
	inline void fillmul( const Quaternion& r );
	inline Quaternion copy( void ) const;
	inline void fill( float x, float y, float z, float w );
	inline void fill( const Quaternion& r );
	inline void fillAxisAngle( const Vec3& axis, float angle );
	inline void fillIdentity( void );
	inline void fillZero( void );
	
public:
	inline void negate( void );
	inline void inverse( void );
	inline void normalize( void );
	inline float axisAngle( Vec3& axis ) const;
	void lerp( const Quaternion& rhs, float t );
	void slerp( const Quaternion& rhs, float t );
};

class MathQuaternion
{
public:
	static inline Quaternion negate( const Quaternion& lhs );
	static inline Quaternion inverse( const Quaternion& lhs );
	static inline Quaternion normalize( const Quaternion& lhs );
	static inline float axisAngle( const Quaternion& lhs, Vec3& axis );
	static inline Quaternion lerp( const Quaternion& lhs, const Quaternion& rhs, float t );
	static inline Quaternion slerp( const Quaternion& lhs, const Quaternion& rhs, float t );
};

#include "Quaternion.inl"
	
#endif //__QUATERNION_HPP__