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
#ifndef __ROTATER_H__
#define __ROTATER_H__

#include "magical-macros.h"

NAMESPACE_MAGICAL

struct Rotater
{
	union 
	{
		struct {
			float y;
			float x;
			float z;
		};
		struct {
			float yaw;
			float pitch;
			float roll;
		};
	};

public:
	static const Rotater Zero;

public:
	inline explicit Rotater( const Matrix3x3& m );
	inline explicit Rotater( const Quaternion& q );
	inline Rotater( float yaw, float pitch, float roll );
	inline Rotater( const Rotater& ea );
	inline Rotater( void );

public:
	inline bool operator==( const Rotater& ea ) const;
	inline bool operator!=( const Rotater& ea ) const;
	inline Rotater& operator=( const Rotater& ea );

public:
	inline Rotater operator+( void ) const;
	inline Rotater operator+( float a ) const;
	inline Rotater operator+( const Rotater& ea ) const;
	inline Rotater operator-( void ) const;
	inline Rotater operator-( float a ) const;
	inline Rotater operator-( const Rotater& ea ) const;
	inline Rotater operator*( float a ) const;
	inline Rotater operator*( const Rotater& ea ) const;
	inline Rotater operator/( float a ) const;
	inline Rotater operator/( const Rotater& ea ) const;

public:
	inline Rotater& operator+=( float a );
	inline Rotater& operator+=( const Rotater& ea );
	inline Rotater& operator-=( float a );
	inline Rotater& operator-=( const Rotater& ea );
	inline Rotater& operator*=( float a );
	inline Rotater& operator*=( const Rotater& ea );
	inline Rotater& operator/=( float a );
	inline Rotater& operator/=( const Rotater& ea );

public:
	static inline void add( Rotater& dst, const Rotater& ea1, const Rotater& ea2 );
	static inline void sub( Rotater& dst, const Rotater& ea1, const Rotater& ea2 );
	static inline void mul( Rotater& dst, const Rotater& ea1, const Rotater& ea2 );
	static inline void div( Rotater& dst, const Rotater& ea1, const Rotater& ea2 );
	static inline void addScalar( Rotater& dst, const Rotater& ea, float a );
	static inline void subScalar( Rotater& dst, const Rotater& ea, float a );
	static inline void mulScalar( Rotater& dst, const Rotater& ea, float a );
	static inline void divScalar( Rotater& dst, const Rotater& ea, float a );

public:
	static inline Rotater add( const Rotater& ea1, const Rotater& ea2 );
	static inline Rotater sub( const Rotater& ea1, const Rotater& ea2 );
	static inline Rotater mul( const Rotater& ea1, const Rotater& ea2 );
	static inline Rotater div( const Rotater& ea1, const Rotater& ea2 );
	static inline Rotater addScalar( const Rotater& ea, float a );
	static inline Rotater subScalar( const Rotater& ea, float a );
	static inline Rotater mulScalar( const Rotater& ea, float a );
	static inline Rotater divScalar( const Rotater& ea, float a );

public:
	inline void add( const Rotater& ea );
	inline void sub( const Rotater& ea );
	inline void mul( const Rotater& ea );
	inline void div( const Rotater& ea );
	inline void addScalar( float a );
	inline void subScalar( float a );
	inline void mulScalar( float a );
	inline void divScalar( float a );

public:
	inline bool equals( const Rotater& ea ) const;
	inline bool isZero( void ) const;
	inline void setZero( void );
	inline void set( const Rotater& ea );
	inline void set( float yaw, float pitch, float roll );
	void fromQuaternion( const Quaternion& q );
	void fromMatrix3x3( const Matrix3x3& m );
	Quaternion toQuaternion( void ) const;
	Matrix3x3 toMatrix3x3( void ) const;
	static void limit( Rotater& dst, const Rotater& ea );
	inline void limit( void );
};

NAMESPACE_END

#endif //__ROTATER_H__