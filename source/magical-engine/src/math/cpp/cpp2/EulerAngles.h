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

NS_MAGICAL_BEGIN

FORWARD_DECLARE

struct EulerAngles : public cEulerAngles
{
public:
	static const EulerAngles Zero;
	static EulerAngles var;

public:
	EulerAngles( float yaw, float pitch, float roll );
	EulerAngles( const EulerAngles& ea );
	EulerAngles( void );

public:
	static inline EulerAngles createZero( void );
	static inline EulerAngles createFromQuaternion( const Quaternion& q );

	static inline void add( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 );
	static inline void sub( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 );
	static inline void mulScalar( EulerAngles& out, const EulerAngles& ea, float a );
	static inline void mul( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 );
	static inline void limit( EulerAngles& out, const EulerAngles& ea );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool equals( const EulerAngles& ea ) const;
	inline bool isZero( void ) const;
	inline bool operator==( const EulerAngles& ea ) const;
	inline bool operator!=( const EulerAngles& ea ) const;
	inline EulerAngles operator+( const EulerAngles& ea ) const;
	inline EulerAngles operator-( const EulerAngles& ea ) const;
	inline EulerAngles operator*( const EulerAngles& ea ) const;
	inline EulerAngles operator*( float a ) const;
	inline EulerAngles& operator+=( const EulerAngles& ea );
	inline EulerAngles& operator-=( const EulerAngles& ea );
	inline EulerAngles& operator*=( const EulerAngles& ea );
	inline EulerAngles& operator*=( float a );
	inline EulerAngles& operator=( const EulerAngles& ea );
	inline void set( const EulerAngles& ea );
	inline void setZero( void );
	inline void setScalars( float yaw, float pitch, float roll );
	inline void fromQuaternion( const Quaternion& q );
	inline Quaternion toQuaternion( void ) const;
	inline void limit( void );
	inline EulerAngles getLimited( void ) const;
};
	
NS_MAGICAL_END

#endif //__EULER_ANGLES_H__