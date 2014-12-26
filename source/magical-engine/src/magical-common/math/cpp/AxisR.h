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
#ifndef __AXISR_H__
#define __AXISR_H__

struct Vector3;
struct Quaternion;

struct AxisRotation : public cAxisRotation
{
public:
	float x;
	float y;
	float z;
	float w;

public:
	static const float Epsilon;
	static const AxisRotation Identity;
	static const AxisRotation Zero;
	static AxisRotation var;

public:
	AxisRotation( float x, float y, float z, float w );
	AxisRotation( const Vector3& axis, float angle );
	AxisRotation( const AxisRotation& aa );
	AxisRotation( void );
	static inline AxisRotation createIdentity( void );
	static inline AxisRotation createZero( void );
	static inline AxisRotation create( const Vector3& axis, float angle );
	static inline AxisRotation createFromQuaternion( const Quaternion& q );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool equals( const AxisRotation& aa ) const;
	inline bool isIdentity( void ) const;
	inline bool isZero( void ) const;
	inline bool operator==( const AxisRotation& aa ) const;
	inline bool operator!=( const AxisRotation& aa ) const;
	inline AxisRotation& operator=( const AxisRotation& aa );
	inline void set( const AxisRotation& aa );
	inline void set( const Vector3& axis, float angle );
	inline void setIdentity( void );
	inline void setZero( void );
	inline void setScalars( float x, float y, float z, float w );
	inline void setQuaternion( const Quaternion& q );
	inline Vector3 axis( void ) const;
	inline Quaternion toQuaternion( void ) const;
};

#endif //__AXISR_H__