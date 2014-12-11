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
#ifndef __AXISA_H__
#define __AXISA_H__

class Vector3;
class Quaternion;

class AxisA
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	static const AxisA Identity;
	static const AxisA Zero;
	static AxisA placeholder;
	static AxisA temp;

public:
	AxisA( const float x, const float y, const float z, const float w );
	AxisA( const Vector3& axis, const float angle );
	AxisA( const AxisA& aa );
	AxisA( void );

public:
	static inline AxisA fromIdentity( void );
	static inline AxisA fromZero( void );
	static inline AxisA fromQuaternion( const Quaternion& q );
	static inline void getAxis( Vector3& out, const AxisA& aa );

public:
	inline bool equals( const AxisA& aa ) const;
	inline bool isIdentity( void ) const;
	inline bool isZero( void ) const;
	inline void fill( const AxisA& aa );
	inline void fillScalars( const float x, const float y, const float z, const float w );
	inline void fillIdentity( void );
	inline void fillZero( void );
	inline void fillQuaternion( const Quaternion& q );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const AxisA& aa ) const;
	inline bool operator!=( const AxisA& aa ) const;
	inline AxisA& operator=( const AxisA& aa );

public:
	inline void setAxis( const Vector3& axis );
	inline void setAngle( const float angle );
	inline Vector3 getAxis( void ) const;
	inline float getAngle( void ) const;
};

#endif //__AXISA_H__