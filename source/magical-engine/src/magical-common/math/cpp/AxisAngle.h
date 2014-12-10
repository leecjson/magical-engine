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
#ifndef __AXIS_ANGLE_H__
#define __AXIS_ANGLE_H__

class Vector3;
class Quaternion;

class AxisAngle
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	static const AxisAngle Identity;
	static const AxisAngle Zero;
	static AxisAngle placeholder;
	static AxisAngle temp;

public:
	AxisAngle( const float x, const float y, const float z, const float w );
	AxisAngle( const Vector3& axis, const float angle );
	AxisAngle( const AxisAngle& aa );
	AxisAngle( void );

public:
	static inline AxisAngle fromIdentity( void );
	static inline AxisAngle fromZero( void );
	static inline AxisAngle fromQuaternion( const Quaternion& q );
	static inline void getAxis( Vector3& out, const AxisAngle& aa );

public:
	inline bool equals( const AxisAngle& aa ) const;
	inline bool isIdentity( void ) const;
	inline bool isZero( void ) const;
	inline void fill( const AxisAngle& aa );
	inline void fillScalars( const float x, const float y, const float z, const float w );
	inline void fillIdentity( void );
	inline void fillZero( void );
	inline void fillQuaternion( const Quaternion& q );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const AxisAngle& aa ) const;
	inline bool operator!=( const AxisAngle& aa ) const;
	inline AxisAngle& operator=( const AxisAngle& aa );

public:
	inline void setAxis( const Vector3& axis );
	inline void setAngle( const float angle );
	inline Vector3 getAxis( void ) const;
	inline float getAngle( void ) const;
};

#endif //__AXIS_ANGLE_H__