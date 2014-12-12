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
#ifndef __EULERA_H__
#define __EULERA_H__

class Quaternion;
class Matrix4;

class EulerA
{
public:
	float yaw;
	float pitch;
	float roll;

public:
	static const EulerA Identity;
	static EulerA placeholder;
	static EulerA temp;

public:
	EulerA( const float yaw, const float pitch, const float roll );
	EulerA( const EulerA& ea );
	EulerA( void );

public:
	static inline EulerA fromIdentity( void );
	static inline EulerA fromMatrix4( const Matrix4& m );
	static inline EulerA fromQuaternion( const Quaternion& q );

	static inline void add( EulerA& out, const EulerA& ea1, const EulerA& ea2 );
	static inline void sub( EulerA& out, const EulerA& ea1, const EulerA& ea2 );
	static inline void mulScalar( EulerA& out, const EulerA& ea, const float a );
	static inline void mul( EulerA& out, const EulerA& ea1, const EulerA& ea2 );
	static inline void corrects( EulerA& out, const EulerA& ea );

public:
	inline bool equals( const EulerA& ea ) const;
	inline bool isIdentity( void ) const;
	inline void fill( const EulerA& ea );
	inline void fillScalars( const float yaw, const float pitch, const float roll );
	inline void fillIdentity( void );
	inline void fillMatrix4( const Matrix4& m );
	inline void fillQuaternion( const Quaternion& q );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const EulerA& ea ) const;
	inline bool operator!=( const EulerA& ea ) const;
	inline EulerA operator+( const EulerA& ea ) const;
	inline EulerA operator-( const EulerA& ea ) const;
	inline EulerA operator*( const EulerA& ea ) const;
	inline EulerA operator*( const float a ) const;
	inline EulerA& operator+=( const EulerA& ea );
	inline EulerA& operator-=( const EulerA& ea );
	inline EulerA& operator*=( const EulerA& ea );
	inline EulerA& operator*=( const float a );
	inline EulerA& operator=( const EulerA& ea );

public:
	inline void corrects( void );
	inline EulerA getCorrected( void ) const;
};
	
#endif //__EULERA_H__