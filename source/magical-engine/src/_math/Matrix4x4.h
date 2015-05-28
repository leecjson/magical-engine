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
#ifndef __MATRIX4X4_H__
#define __MATRIX4X4_H__

struct Matrix4x4
{
	union
	{
		float m[16];

		struct {
			float m11; float m12; float m13; float m14;
			float m21; float m22; float m23; float m24;
			float m31; float m32; float m33; float m34;
			float m41; float m42; float m43; float m44;
		};
		struct {
			Vector4 m11m12m13m14;
			Vector4 m21m22m23m24;
			Vector4 m31m32m33m34;
			Vector4 m41m42m43m44;
		};
		struct {
			Vector3 m11m12m13; float m14;
			Vector3 m21m22m23; float m24;
			Vector3 m31m32m33; float m34;
			Vector3 m41m42m43; float m44;
		};
	};

public:
	static const Matrix4x4 Identity;
	static const Matrix4x4 Zero;

public:
	inline explicit Matrix4x4( const Quaternion& q );
	inline explicit Matrix4x4( float m );
	inline Matrix4x4( float m11, float m22, float m33, float m44 );
	inline Matrix4x4( const Vector3& t, const Quaternion& r, const Vector3& s );
	inline Matrix4x4( const Matrix4x4& m );
	inline Matrix4x4( void );

public:
	inline bool operator==( const Matrix4x4& m ) const;
	inline bool operator!=( const Matrix4x4& m ) const;
	inline float& operator[]( size_t i ) const;
	inline Matrix4x4& operator=( float m );
	inline Matrix4x4& operator=( const Matrix4x4& m );

public:
	inline Matrix4x4 operator+( float a ) const;
	inline Matrix4x4 operator+( const Matrix4x4& m ) const;
	inline Matrix4x4 operator-( float a ) const;
	inline Matrix4x4 operator-( const Matrix4x4& m ) const;
	inline Matrix4x4 operator*( float a ) const;
	inline Matrix4x4 operator*( const Matrix4x4& m ) const;

public:
	inline Matrix4x4& operator+=( float a );
	inline Matrix4x4& operator+=( const Matrix4x4& m );
	inline Matrix4x4& operator-=( float a );
	inline Matrix4x4& operator-=( const Matrix4x4& m );
	inline Matrix4x4& operator*=( float a );
	inline Matrix4x4& operator*=( const Matrix4x4& m );

public:
	static inline void add( Matrix4x4& out, const Matrix4x4& m1, const Matrix4x4& m2 );
	static inline void sub( Matrix4x4& out, const Matrix4x4& m1, const Matrix4x4& m2 );
	static void mul( Matrix4x4& out, const Matrix4x4& m1, const Matrix4x4& m2 );
	static void mul3x4( Matrix4x4& out, const Matrix4x4& m1, const Matrix4x4& m2 );
	static inline void addScalar( Matrix4x4& out, const Matrix4x4& m, float a );
	static inline void subScalar( Matrix4x4& out, const Matrix4x4& m, float a );
	static inline void mulScalar( Matrix4x4& out, const Matrix4x4& m, float a );

public:           
	static inline Matrix4x4 add( const Matrix4x4& m1, const Matrix4x4& m2 );
	static inline Matrix4x4 sub( const Matrix4x4& m1, const Matrix4x4& m2 );
	static inline Matrix4x4 mul( const Matrix4x4& m1, const Matrix4x4& m2 );
	static inline Matrix4x4 mul3x4( const Matrix4x4& m1, const Matrix4x4& m2 );
	static inline Matrix4x4 addScalar( const Matrix4x4& m, float a );
	static inline Matrix4x4 subScalar( const Matrix4x4& m, float a );
	static inline Matrix4x4 mulScalar( const Matrix4x4& m, float a );

public:
	inline void add( const Matrix4x4& m );
	inline void sub( const Matrix4x4& m );
	inline void mul( const Matrix4x4& m );
	inline void mul3x4( const Matrix4x4& m ); 
	inline void addScalar( float a );
	inline void subScalar( float a );
	inline void mulScalar( float a );

public:
	bool equals( const Matrix4x4& m ) const;
	bool isZero( void ) const;
	bool isIdentity( void ) const;
	inline void setZero( void );
	inline void setIdentity( void );
	inline void set( const Matrix4x4& m );
	inline void set( float m );

public:
	static inline Matrix4x4 createLookAt( const Vector3& eye, const Vector3& target, const Vector3& up );
	static inline Matrix4x4 createPerspective( float fov, float aspect, float znear, float zfar );
	static inline Matrix4x4 createOrtho( float left, float right, float bottom, float top, float znear, float zfar );
	static inline Matrix4x4 createTrs( const Vector3& t, const Quaternion& r, const Vector3& s );
	static inline Matrix4x4 createTranslation( const Vector3& t );
	static inline Matrix4x4 createScale( const Vector3& s );
	static inline Matrix4x4 createRotation( const Quaternion& q );
	static inline Matrix4x4 createRotationX( float a );
	static inline Matrix4x4 createRotationY( float a );
	static inline Matrix4x4 createRotationZ( float a );

public:
	void setLookAt( const Vector3& eye, const Vector3& target, const Vector3& up );
	void setPerspective( float fov, float aspect, float znear, float zfar );
	void setOrtho( float left, float right, float bottom, float top, float znear, float zfar );
	void setTrs( const Vector3& t, const Quaternion& r, const Vector3& s );
	void setTranslation( const Vector3& t );
	void setScale( const Vector3& s );
	void setRotation( const Quaternion& q );
	void setRotationX( float a );
	void setRotationY( float a );
	void setRotationZ( float a );

public:
	static void inverse( Matrix4x4& out, const Matrix4x4& m );
	static void transpose( Matrix4x4& out, const Matrix4x4& m );
	static void negate( Matrix4x4& out, const Matrix4x4& m );
	static inline Matrix4x4 inverse( const Matrix4x4& m );
	static inline Matrix4x4 transpose( const Matrix4x4& m );
	static inline Matrix4x4 negate( const Matrix4x4& m );
	inline void inverse( void );
	inline void transpose( void );
	inline void negate( void );
};

#endif //__MATRIX4X4_H__