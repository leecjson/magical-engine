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
#include "cEulerAngles.h"

cBool magicalEulerAnglesEqulas( const cEulerAngles* ea1, const cEulerAngles* ea2 )
{
	return
		magicalAlmostEqual( ea1->yaw, ea2->yaw, kDegreeEpsilon ) &&
		magicalAlmostEqual( ea1->pitch, ea2->pitch, kDegreeEpsilon ) &&
		magicalAlmostEqual( ea1->roll, ea2->roll, kDegreeEpsilon );
}

cBool magicalEulerAnglesIsZero( const cEulerAngles* ea )
{
	return
		magicalAlmostZero( ea->yaw, kDegreeEpsilon ) &&
		magicalAlmostZero( ea->pitch, kDegreeEpsilon ) &&
		magicalAlmostZero( ea->roll, kDegreeEpsilon );
}

void magicalEulerAnglesFill( cEulerAngles* out, float yaw, float pitch, float roll )
{
	out->yaw = yaw;
	out->pitch = pitch;
	out->roll = roll;
}

void magicalEulerAnglesCopy( cEulerAngles* out, const cEulerAngles* ea )
{
	out->yaw = ea->yaw;
	out->pitch = ea->pitch;
	out->roll = ea->roll;
}

void magicalEulerAnglesSetZero( cEulerAngles* out )
{
	out->yaw = 0.0f;
	out->pitch = 0.0f;
	out->roll = 0.0f;
}

void magicalEulerAnglesSetLookAt( cEulerAngles* out, const cVector3* eye, const cVector3* target, const cVector3* up )
{
	
}

/*-----------------------------------------------------------------------------*\
 * 从四元数转换为欧拉角表示 done
 *
 * out q的欧拉角表示
 * q 源四元数
 *-----------------------------------------------------------------------------*/
void magicalEulerAnglesFromQuaternion( cEulerAngles* out, const cQuaternion* q )
{
	float sp = -2.0f * ( q->y * q->z + q->w * q->x );

	if( fabsf( sp ) > 0.9999f )
	{
		out->pitch = kPIOver2 * sp;
		out->yaw = atan2f( -q->x * q->z - q->w * q->y, 0.5f - q->y * q->y - q->z * q->z );
		out->roll = 0.0f;
	}
	else
	{
		out->pitch = asinf( sp );
		out->yaw = atan2f( q->x * q->z - q->w * q->y, 0.5f - q->x * q->x - q->y * q->y );
		out->roll = atan2f( q->x * q->y - q->w * q->z, 0.5f - q->x * q->x - q->z * q->z );
	}
}

void magicalEulerAnglesToQuaternion( cQuaternion* out, const cEulerAngles* ea )
{
	magicalQuaternionFromEulerAngles( out, ea );
}

void magicalEulerAnglesToMatrix3( cMatrix3* out, const cEulerAngles* ea )
{
	magicalMatrix3FromEulerAngles( out, ea );
}

void magicalEulerAnglesAdd( cEulerAngles* out, const cEulerAngles* ea1, const cEulerAngles* ea2 )
{
	out->yaw = ea1->yaw + ea2->yaw;
	out->pitch = ea1->pitch + ea2->pitch;
	out->roll = ea1->roll + ea2->roll;
}

void magicalEulerAnglesSub( cEulerAngles* out, const cEulerAngles* ea1, const cEulerAngles* ea2 )
{
	out->yaw = ea1->yaw - ea2->yaw;
	out->pitch = ea1->pitch - ea2->pitch;
	out->roll = ea1->roll - ea2->roll;
}

void magicalEulerAnglesMul( cEulerAngles* out, const cEulerAngles* ea1, const cEulerAngles* ea2 )
{
	out->yaw = ea1->yaw * ea2->yaw;
	out->pitch = ea1->pitch * ea2->pitch;
	out->roll = ea1->roll * ea2->roll;
}

void magicalEulerAnglesMulScalar( cEulerAngles* out, const cEulerAngles* ea, float a )
{
	out->yaw = ea->yaw * a;
	out->pitch = ea->pitch * a;
	out->roll = ea->roll * a;
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
void magicalEulerAnglesLimit( cEulerAngles* out, const cEulerAngles* ea )
{
	float yaw = ea->yaw;
	float pitch = ea->pitch;
	float roll = ea->roll;

	pitch = magicalCorrectToPI( pitch );
	if( pitch < - kPIOver2 )
	{
		pitch = - kPI - pitch;
		yaw  += kPI;
		roll += kPI;
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
	
	out->yaw = magicalCorrectToPI( yaw );
	out->pitch = pitch;
	out->roll = roll;
}