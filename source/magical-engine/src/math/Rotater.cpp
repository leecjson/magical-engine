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

NAMESPACE_MAGICAL

struct Vector2;
struct Vector3;
struct Vector4;
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

const Rotater Rotater::Zero = Rotater( 0.0f, 0.0f, 0.0f );

void Rotater::fromQuaternion( const Quaternion& q )
{
	float sp = -2.0f * ( q.y * q.z + q.w * q.x );

	if( fabsf( sp ) > 0.9999f )
	{
		pitch = Math::PIDiv2 * sp;
		yaw = atan2f( -q.x * q.z - q.w * q.y, 0.5f - q.y * q.y - q.z * q.z );
		roll = 0.0f;
	}
	else
	{
		pitch = asinf( sp );
		yaw = atan2f( q.x * q.z - q.w * q.y, 0.5f - q.x * q.x - q.y * q.y );
		roll = atan2f( q.x * q.y - q.w * q.z, 0.5f - q.x * q.x - q.z * q.z );
	}
}

void Rotater::fromMatrix3x3( const Matrix3x3& m )
{

}

Quaternion Rotater::toQuaternion( void ) const
{
	return Quaternion( *this );
}

Matrix3x3 Rotater::toMatrix3x3( void ) const
{
	return Matrix3x3( *this );
}

void Rotater::limit( Rotater& dst, const Rotater& ea )
{
	float yaw = ea.yaw;
	float pitch = ea.pitch;
	float roll = ea.roll;

	pitch = Math::toPI( pitch );
	if( pitch < -Math::PIDiv2 )
	{
		pitch = - Math::PI - pitch;
		yaw  += Math::PI;
		roll += Math::PI;
	}
	else if( pitch > Math::PIDiv2 )
	{
		pitch = Math::PI - pitch;
		yaw  += Math::PI;
		roll += Math::PI;
	}

	if( fabsf( pitch ) > ( Math::PIDiv2 - 1e-4f ) )
	{
		yaw += roll;
		roll = 0.0f;
	}
	else
	{
		roll = Math::toPI( roll );
	}
	
	dst.yaw = Math::toPI( yaw );
	dst.pitch = pitch;
	dst.roll = roll;
}

NAMESPACE_END