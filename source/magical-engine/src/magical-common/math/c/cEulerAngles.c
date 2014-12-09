﻿/******************************************************************************
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
#include "cEulerAngles.h"
#include "cMathMacros.h"

cBool magicalEulerAnglesEqulas( const cEulerAngles ea1, const cEulerAngles ea2 )
{
	return
		magicalAlmostEqual( ea1 _yaw, ea2 _yaw ) &&
		magicalAlmostEqual( ea1 _pitch, ea2 _pitch ) &&
		magicalAlmostEqual( ea1 _roll, ea2 _roll );
}

cBool magicalEulerAnglesIsIdentity( const cEulerAngles ea )
{
	return
		magicalAlmostZero( ea _yaw ) &&
		magicalAlmostZero( ea _pitch ) &&
		magicalAlmostZero( ea _roll );
}

void magicalEulerAnglesFillYawPitchRoll( cEulerAngles out, const float yaw, const float pitch, const float roll )
{
	out _yaw   = yaw;
	out _pitch = pitch;
	out _roll  = roll;
}

void magicalEulerAnglesFill( cEulerAngles out, const cEulerAngles ea )
{
	out _yaw   = ea _yaw;
	out _pitch = ea _pitch;
	out _roll  = ea _roll;
}

void magicalEulerAnglesFillIdentity( cEulerAngles out )
{
	out _yaw   = 0.0f;
	out _pitch = 0.0f;
	out _roll  = 0.0f;
}

void magicalEulerAnglesAdd( cEulerAngles out, const cEulerAngles ea1, const cEulerAngles ea2 )
{
	out _yaw = ea1 _yaw + ea2 _yaw;
	out _pitch = ea1 _pitch + ea2 _pitch;
	out _roll = ea1 _roll + ea2 _roll;
}

void magicalEulerAnglesSub( cEulerAngles out, const cEulerAngles ea1, const cEulerAngles ea2 )
{
	out _yaw = ea1 _yaw - ea2 _yaw;
	out _pitch = ea1 _pitch - ea2 _pitch;
	out _roll = ea1 _roll - ea2 _roll;
}

void magicalEulerAnglesMul( cEulerAngles out, const cEulerAngles ea1, const cEulerAngles ea2 )
{
	out _yaw = ea1 _yaw * ea2 _yaw;
	out _pitch = ea1 _pitch * ea2 _pitch;
	out _roll = ea1 _roll * ea2 _roll;
}

void magicalEulerAnglesMulScalar( cEulerAngles out, const cEulerAngles ea, const float a )
{
	out _yaw = ea _yaw * a;
	out _pitch = ea _pitch * a;
	out _roll = ea _roll * a;
}

/*-----------------------------------------------------------------------------*\
 * 从四元数转换为欧拉角表示 done
 *
 * out q的欧拉角表示
 * q 源四元数
 *-----------------------------------------------------------------------------*/
void magicalEulerAnglesFromQuaternion( cEulerAngles out, const cQuaternion q )
{
	float sp = -2.0f * ( q _y * q _z + q _w * q _x );

	if( fabsf( sp ) > 0.9999f )
	{
		out _pitch = kPIOver2 * sp;
		out _yaw   = atan2f( -q _x * q _z - q _w * q _y, 0.5f - q _y * q _y - q _z * q _z );
		out _roll  = 0.0f;
	}
	else
	{
		out _pitch = asinf( sp );
		out _yaw   = atan2f( q _x * q _z - q _w * q _y, 0.5f - q _x * q _x - q _y * q _y );
		out _roll  = atan2f( q _x * q _y - q _w * q _z, 0.5f - q _x * q _x - q _z * q _z );
	}
}

/*-----------------------------------------------------------------------------*\
 * 从旋转矩阵转换为欧拉角表示
 *
 * out m的欧拉角表示
 * m 源旋转矩阵
 *-----------------------------------------------------------------------------*/
void magicalEulerAnglesFromMatrix4( cEulerAngles out, const cMatrix4 m )
{

}

void magicalEulerAnglesToQuaternion( cQuaternion out, const cEulerAngles ea )
{
	magicalQuaternionFromEulerAngles( out, ea );
}

void magicalEulerAnglesToMatrix4( cMatrix4 out, const cEulerAngles ea )
{
	
}

/*-----------------------------------------------------------------------------*\
 * 计算欧拉角的限制情况 done
 *
 * 限制欧拉角 
 * -180 <= Yaw   <= 180 
 * -90  <= Pitch <= 90
 * -180 <= Roll  <= 180
 *
 * 当Pitch等于90或-90时，由Yaw完成Roll的旋转，避免万向锁
 * 
 * out 返回限制欧拉角
 * ea 源欧拉角
 *-----------------------------------------------------------------------------*/
void magicalEulerAnglesCorrects( cEulerAngles out, const cEulerAngles ea )
{
	float yaw   = ea _yaw;
	float pitch = ea _pitch;
	float roll  = ea _roll;

	pitch = magicalCorrectToPI( pitch );
	if( pitch < - kPIOver2 )
	{
		pitch = - kPI - pitch;
		yaw  +=   kPI;
		roll +=   kPI;
	}
	else if( pitch > kPIOver2 )
	{
		pitch = kPI - pitch;
		yaw  += kPI;
		roll += kPI;
	}

	if( fabsf( pitch ) > ( kPIOver2 - 1e-4f ) )
	{
		yaw += roll;
		roll = 0.0f;
	}
	else
	{
		roll = magicalCorrectToPI( roll );
	}

	yaw = magicalCorrectToPI( yaw );

	out _yaw   = yaw;
	out _pitch = pitch;
	out _roll  = roll;
}