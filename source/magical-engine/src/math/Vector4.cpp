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
#include "MathUtils.h"

struct Vector2;
struct Vector3;
struct Rotater;
struct Quaternion;
struct Matrix3x3;
struct Matrix4x4;

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Rotater.h"
#include "Quaternion.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"

#include "Vector2.inl"
#include "Vector3.inl"
#include "Vector4.inl"
#include "Rotater.inl"
#include "Quaternion.inl"
#include "Matrix3x3.inl"
#include "Matrix4x4.inl"

const Vector4 Vector4::Zero = Vector4( 0.0f, 0.0f, 0.0f, 0.0f );
const Vector4 Vector4::One = Vector4( 1.0f, 1.0f, 1.0f, 1.0f );
const Vector4 Vector4::UnitX = Vector4( 1.0f, 0.0f, 0.0f, 0.0f );
const Vector4 Vector4::UnitY = Vector4( 0.0f, 1.0f, 0.0f, 0.0f );
const Vector4 Vector4::UnitZ = Vector4( 0.0f, 0.0f, 1.0f, 0.0f );
const Vector4 Vector4::UnitW = Vector4( 0.0f, 0.0f, 0.0f, 1.0f );
const Vector4 Vector4::Up = Vector4( 0.0f, 1.0f, 0.0f, 0.0f );
const Vector4 Vector4::Down = Vector4( 0.0f, -1.0f, 0.0f, 0.0f );
const Vector4 Vector4::Right = Vector4( 1.0f, 0.0f, 0.0f, 0.0f );
const Vector4 Vector4::Left = Vector4( -1.0f, 0.0f, 0.0f, 0.0f );
const Vector4 Vector4::Forward = Vector4( 0.0f, 0.0f, 1.0f, 0.0f );
const Vector4 Vector4::Back = Vector4( 0.0f, 0.0f, -1.0f, 0.0f );
const Vector4 Vector4::Space0 = Vector4( 0.0f, 0.0f, 0.0f, 0.0f );
const Vector4 Vector4::Space1 = Vector4( 0.0f, 0.0f, 0.0f, 1.0f );
const Vector4 Vector4::Space2 = Vector4( 0.0f, 0.0f, 0.0f, 2.0f );

void Vector4::mul4x4( Vector4& out, const Vector4& v, const Matrix4x4& m )
{
	Vector4 dst;

	dst.x = v.x * m.m11 + v.y * m.m21 + v.z * m.m31 + v.w * m.m41;
	dst.y = v.x * m.m12 + v.y * m.m22 + v.z * m.m32 + v.w * m.m42;
	dst.z = v.x * m.m13 + v.y * m.m23 + v.z * m.m33 + v.w * m.m43;
	dst.w = v.x * m.m14 + v.y * m.m24 + v.z * m.m34 + v.w * m.m44;

	out.x = dst.x;
	out.y = dst.y;
	out.z = dst.z;
	out.w = dst.w;
}

//void Vector4::Clamp( Vector4& out, const Vector4& v, const Vector4& min, const Vector4& max )
//{
//
//}
//
//void Vector4::Negate( Vector4& out, const Vector4& v )
//{
//
//}
//
//void Vector4::Normalize( Vector4& out, const Vector4& v )
//{
//
//}
//
//void Vector4::Scale( Vector4& out, const Vector4& v, float s )
//{
//
//}
//
//void Vector4::MidPointBetween( Vector4& out, const Vector4& v1, const Vector4& v2 )
//{
//
//}
//
//void Vector4::Project( Vector4& out, const Vector4& v, const Vector4& n )
//{
//
//}
