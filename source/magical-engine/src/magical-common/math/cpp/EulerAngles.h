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
#ifndef __EULER_ANGLES_H__
#define __EULER_ANGLES_H__

class Quaternion;
class Matrix4;

class EulerAngles
{
public:
	float yaw;
	float pitch;
	float roll;

public:
	static const EulerAngles Identity;
	static EulerAngles placeholder;
	static EulerAngles temp;

public:
	EulerAngles( const Matrix4& m );
	EulerAngles( const Quaternion& q );
	EulerAngles( const EulerAngles& ea );
	EulerAngles( const float yaw, const float pitch, const float roll );
	EulerAngles( void );
	static inline EulerAngles fromMatrix4( const Matrix4& m );
	static inline EulerAngles fromQuaternion( const Quaternion& q );

public:
	inline bool equals( const EulerAngles& ea ) const;
	inline bool isIdentity( void ) const;
	inline void fill( const EulerAngles& ea );
	inline void fill( const float yaw, const float pitch, const float roll );
	inline void fillIdentity( void );
	inline void fillMatrix4( const Matrix4& m );
	inline void fillQuaternion( const Quaternion& q );

public:
	static inline void add( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 );
	static inline void sub( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 );
	static inline void mulScalar( EulerAngles& out, const EulerAngles& ea, const float a );
	static inline void mul( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 );

	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const EulerAngles& ea ) const;
	inline bool operator!=( const EulerAngles& ea ) const;
	inline EulerAngles operator+( const EulerAngles& ea ) const;
	inline EulerAngles operator-( const EulerAngles& ea ) const;
	inline EulerAngles operator*( const EulerAngles& ea ) const;
	inline EulerAngles operator*( const float a ) const;
	inline EulerAngles& operator+=( const EulerAngles& ea );
	inline EulerAngles& operator-=( const EulerAngles& ea );
	inline EulerAngles& operator*=( const EulerAngles& ea );
	inline EulerAngles& operator*=( const float a );
	inline EulerAngles& operator=( const EulerAngles& ea );
	
public:
	static inline void corrects( EulerAngles& out, const EulerAngles& ea );

public:
	inline void corrects( void );
	inline EulerAngles getCorrected( void ) const;
};

#include "../c/cEulerAngles.h"
#include "Quaternion.h"
#include "Matrix4.h"
#include "EulerAngles.inl"
	
#endif //__EULER_ANGLES_H__