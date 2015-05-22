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

#include "../Com/Utility.h"

struct Vector3;
struct Matrix3x3;
struct Quaternion;

struct AxisAngle
{
public:
	union 
	{
		struct {
			float x;
			float y;
			float z;
			float a;
		};
		struct {
			Vector3 axis;
			float a;
		};
	};

	static const AxisAngle Identity;
	static const AxisAngle Zero;

public:
	member_inline AxisAngle( const Matrix3x3& m );
	member_inline AxisAngle( const Quaternion& q );
	member_inline AxisAngle( float x, float y, float z, float a );
	member_inline AxisAngle( const Vector3& axis, float a );
	member_inline AxisAngle( const AxisAngle& aa );

public:
	member_inline bool operator==( const AxisAngle& aa ) const;
	member_inline bool operator!=( const AxisAngle& aa ) const;
	member_inline AxisAngle& operator=( const AxisAngle& aa );
	
public:
	member_inline bool IsZero( void ) const;
	member_inline bool IsIdentity( void ) const;
	member_inline bool Equals( const AxisAngle& aa ) const;
	member_inline void Assign( const AxisAngle& aa );
	member_inline void SetZero( void );
	member_inline void SetIdentity( void );
	member_inline void Set( float x, float y, float z, float a );
	member_inline void Set( const Vector3& axis, float a );

public:
	static_inline void FromQuaternion( AxisAngle& out, const Quaternion& q );
	static_inline void FromMatrix3x3( AxisAngle& out, const Matrix3x3& m );
	static_inline void ToQuaternion( Quaternion& out, const AxisAngle& aa );
	static_inline void ToMatrix3x3( Matrix3x3& out, const AxisAngle& aa );
	static_inline Quaternion ToQuaternion( const AxisAngle& aa );
	static_inline Matrix3x3 ToMatrix3x3( const AxisAngle& aa );

	member_inline void FromQuaternion( const Quaternion& q );
	member_inline void FromMatrix3x3( const Matrix3x3& m );
	member_inline Quaternion ToQuaternion( void );
	member_inline Matrix3x3 ToMatrix3x3( void );
};

#endif //__AXIS_ANGLE_H__