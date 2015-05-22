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
#ifndef __MATRIX3X3_H__
#define __MATRIX3X3_H__

struct Matrix3x3
{
	union
	{
		float m[9];
		
		struct {
			float m11; float m12; float m13;
			float m21; float m22; float m23;
			float m31; float m32; float m33;
		};
		struct {
			Vector3 m11m12m13;
			Vector3 m21m22m23;
			Vector3 m31m32m33;
		};
	};

public:
	static const Matrix3x3 Identity;
	static const Matrix3x3 Zero;

public:
	inline Matrix3x3( float m11, float m22, float m33 );
	inline explicit Matrix3x3( Rotater ea );
	inline Matrix3x3( const Vector3& axis, float angle );
	inline explicit Matrix3x3( float m );
	inline explicit Matrix3x3( const Quaternion& q );
	inline Matrix3x3( const Matrix3x3& m );
	inline Matrix3x3( void );

public:
	inline bool operator==( const Matrix3x3& m ) const;
	inline bool operator!=( const Matrix3x3& m ) const;
	inline float& operator[]( size_t i ) const;
	inline Matrix3x3& operator=( float m );
	inline Matrix3x3& operator=( const Matrix3x3& m );

public:
	inline Matrix3x3 operator+( float a ) const;
	inline Matrix3x3 operator+( const Matrix3x3& m ) const;
	inline Matrix3x3 operator-( float a ) const;
	inline Matrix3x3 operator-( const Matrix3x3& m ) const;
	inline Matrix3x3 operator*( float a ) const;
	inline Matrix3x3 operator*( const Matrix3x3& m ) const;

public:
	inline Matrix3x3& operator+=( float a );
	inline Matrix3x3& operator+=( const Matrix3x3& m );
	inline Matrix3x3& operator-=( float a );
	inline Matrix3x3& operator-=( const Matrix3x3& m );
	inline Matrix3x3& operator*=( float a );
	inline Matrix3x3& operator*=( const Matrix3x3& m );

public:
	static inline void add( Matrix3x3& out, const Matrix3x3& m1, const Matrix3x3& m2 );
	static inline void sub( Matrix3x3& out, const Matrix3x3& m1, const Matrix3x3& m2 );
	static void mul( Matrix3x3& out, const Matrix3x3& m1, const Matrix3x3& m2 );
	static inline void addScalar( Matrix3x3& out, const Matrix3x3& m, float a );
	static inline void subScalar( Matrix3x3& out, const Matrix3x3& m, float a );
	static inline void mulScalar( Matrix3x3& out, const Matrix3x3& m, float a );

public:
	static inline Matrix3x3 add( const Matrix3x3& m1, const Matrix3x3& m2 );
	static inline Matrix3x3 sub( const Matrix3x3& m1, const Matrix3x3& m2 );
	static inline Matrix3x3 mul( const Matrix3x3& m1, const Matrix3x3& m2 );
	static inline Matrix3x3 addScalar( const Matrix3x3& m, float a );
	static inline Matrix3x3 subScalar( const Matrix3x3& m, float a );
	static inline Matrix3x3 mulScalar( const Matrix3x3& m, float a );

public:
	inline void add( const Matrix3x3& m );
	inline void sub( const Matrix3x3& m );
	inline void mul( const Matrix3x3& m );
	inline void addScalar( float a );
	inline void subScalar( float a );
	inline void mulScalar( float a );

public:
	bool equals( const Matrix3x3& m ) const;
	bool isZero( void ) const;
	bool isIdentity( void ) const;
	inline void setZero( void );
	inline void setIdentity( void );
	inline void set( const Matrix3x3& m );
	inline void set( float m );

public:
	static inline Matrix3x3 createLookAt( const Vector3& eye, const Vector3& target, const Vector3& up );
	static inline Matrix3x3 createRotation( const Vector3& axis, float angle );
	static inline Matrix3x3 createRotation( const Rotater& ea );
	static inline Matrix3x3 createRotation( const Quaternion& q );
	static inline Matrix3x3 createRotationX( float a );
	static inline Matrix3x3 createRotationY( float a );
	static inline Matrix3x3 createRotationZ( float a );
	 
public:
	void setLookAt( const Vector3& eye, const Vector3& target, const Vector3& up );
	void setRotation( const Vector3& axis, float angle );
	void setRotation( const Rotater& ea );
	void setRotation( const Quaternion& q );
	void setRotationX( float a );
	void setRotationY( float a );
	void setRotationZ( float a );

public:
	static void inverse( Matrix3x3& out, const Matrix3x3& m );
	static void transpose( Matrix3x3& out, const Matrix3x3& m );
	static void negate( Matrix3x3& out, const Matrix3x3& m );
	static inline Matrix3x3 inverse( const Matrix3x3& m );
	static inline Matrix3x3 transpose( const Matrix3x3& m );
	static inline Matrix3x3 negate( const Matrix3x3& m );
	inline void inverse( void );
	inline void transpose( void );
	inline void negate( void );
};

#endif //__MATRIX3X3_H__