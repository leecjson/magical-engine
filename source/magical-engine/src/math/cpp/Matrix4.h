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
#ifndef __MATRIX4_H__
#define __MATRIX4_H__

struct Vector3;
struct Vector4;
struct AxisAngle;
struct EulerAngles;
struct Quaternion;

struct Matrix4 : public cMatrix4
{
public:
	static const Matrix4 Identity;
	static const Matrix4 Zero;
	static Matrix4 var;

public:
	Matrix4( const float* m );
	Matrix4( float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44 );
	Matrix4( const Matrix4& m );
	Matrix4( void );

public:
	static inline Matrix4 createIdentity( void );
	static inline Matrix4 createZero( void );
	static inline Matrix4 createTRS( const Vector3& t, const Quaternion& r, const Vector3& s );

	static inline void MulScalar( Matrix4& out, const Matrix4& m, float a );
	static inline void Mul( Matrix4& out, const Matrix4& m1, const Matrix4& m2 );
	static inline void GetUpVector( Vector3& out, const Matrix4& m );
	static inline void GetDownVector( Vector3& out, const Matrix4& m );
	static inline void GetLeftVector( Vector3& out, const Matrix4& m );
	static inline void GetRightVector( Vector3& out, const Matrix4& m );
	static inline void GetForwardVector( Vector3& out, const Matrix4& m );
	static inline void GetBackVector( Vector3& out, const Matrix4& m );
	static inline void GetTranslation( Vector3& out, const Matrix4& m );
	static inline void GetScale( Vector3& out, const Matrix4& m );
	static inline void GetRotationQuaternion( Quaternion& out, const Matrix4& m );
	static inline bool Inverse( Matrix4& out, const Matrix4& m );
	static inline void Transpose( Matrix4& out, const Matrix4& m );
	static inline void Negate( Matrix4& out, const Matrix4& m );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool equals( const Matrix4& m ) const;
	inline bool IsZero( void ) const;
	inline bool IsIdentity( void ) const;
	inline bool operator==( const Matrix4& m ) const;
	inline bool operator!=( const Matrix4& m ) const;
	inline float& operator[]( const unsigned int i ) const;
	inline Matrix4 operator*( float a ) const;
	inline Matrix4 operator*( const Matrix4& m ) const;
	inline Matrix4& operator*=( float a );
	inline Matrix4& operator*=( const Matrix4& m );
	inline Matrix4& operator=( const Matrix4& m );

public:
	inline void Set( const float* m );
	inline void Set( const Matrix4& m );
	inline void SetIdentity( void );
	inline void SetZero( void );
	inline void SetLookAt( const Vector3& eye, const Vector3& target, const Vector3& up );
	inline void SetPerspective( float fov, float aspect, float znear, float zfar );
	inline void SetOrth( float left, float right, float bottom, float top, float near, float far );
	inline void SetTRS( const Vector3& t, const Quaternion& r, const Vector3& s );

	inline void MakeTranslation( float x, float y, float z );
	inline void MakeTranslation( const Vector3& t );
	inline void MakeScale( float x, float y, float z );
	inline void MakeScale( const Vector3& s );
	inline void MakeRotationX( float angle );
	inline void MakeRotationY( float angle );
	inline void MakeRotationZ( float angle );
	inline void MakeRotationAxisAngle( const Vector3& axis, float angle );
	inline void MakeRotationAxisAngle( const AxisAngle& aa );
	inline void MakeRotationEulerAngles( float yaw, float pitch, float roll );
	inline void MakeRotationEulerAngles( const EulerAngles& ea );
	inline void MakeRotationQuaternion( const Quaternion& q );

public:
	inline Vector3 GetUpVector( void ) const;
	inline Vector3 GetDownVector( void ) const;
	inline Vector3 GetLeftVector( void ) const;
	inline Vector3 GetRightVector( void ) const;
	inline Vector3 GetForwardVector( void ) const;
	inline Vector3 GetBackVector( void ) const;
	inline void SetTranslation( float x, float y, float z );
	inline void SetTranslation( const Vector3& t );
	inline Vector3 GetTranslation( void ) const;
	inline Vector3 GetScale( void ) const;
	inline Quaternion GetRotationQuaternion( void ) const;
	inline bool Inverse( void );
	inline void Transpose( void );
	inline void Negate( void );
	inline bool GetInversed( Matrix4& out ) const;
	inline Matrix4 GetTransposed( void ) const;
	inline Matrix4 GetNegated( void ) const;
	inline float Determinant( void ) const;
};

#endif //__MATRIX4_H__