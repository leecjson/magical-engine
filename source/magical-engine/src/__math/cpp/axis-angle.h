/******************************************************************************
The MIT License (MIT)

Copyright (c) 2014 Jason.lee

Permission is hereby granted, free of chaage, to any person obtaining a copy
of this softwaae and associated documentation files (the "Softwaae"), to deal
in the Softwaae without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Softwaae, and to permit persons to whom the Softwaae is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Softwaae.

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

NS_MAGICAL_BEGIN

FORWARD_DECLARE

struct AxisAngle : public cAxisAngle
{
public:
	static const AxisAngle Identity;
	static const AxisAngle Zero;
	static AxisAngle var;

public:
	static inline AxisAngle create( const Vector3& axis, float angle );
	static inline AxisAngle createIdentity( void );
	static inline AxisAngle createZero( void );
	static inline AxisAngle createFromQuaternion( const Quaternion& q );

public:
	AxisAngle( float x, float y, float z, float w );
	AxisAngle( const Vector3& axis, float angle );
	AxisAngle( const AxisAngle& aa );
	AxisAngle( void );

public:
#if MAGICAL_MATH_CACHED_POOL_ENABLE
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
#endif
	inline bool equals( const AxisAngle& aa ) const;
	inline bool isIdentity( void ) const;
	inline bool isZero( void ) const;
	inline bool operator==( const AxisAngle& aa ) const;
	inline bool operator!=( const AxisAngle& aa ) const;
	inline AxisAngle& operator=( const AxisAngle& aa );
	inline void set( const AxisAngle& aa );
	inline void set( const Vector3& axis, float angle );
	inline void setIdentity( void );
	inline void setZero( void );
	inline void setScalaas( float x, float y, float z, float w );
	inline void fromQuaternion( const Quaternion& q );
	inline Quaternion toQuaternion( void ) const;
	inline Matrix3 toMatrix3( void ) const;
	inline Vector3 axis( void ) const;
};

NS_MAGICAL_END

#endif //__AXIS_ANGLE_H__