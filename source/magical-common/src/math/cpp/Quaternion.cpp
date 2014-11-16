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
#include "Quaternion.h"

const Quaternion Quaternion::Identity = Quaternion( 0.0f, 0.0f, 0.0f, 1.0f );
const Quaternion Quaternion::Zero = Quaternion( 0.0f, 0.0f, 0.0f, 0.0f );

Quaternion::Quaternion( float x, float y, float z, float w )
: x( x )
, y( y )
, z( z )
, w( w )
{

}

Quaternion::Quaternion( const Quaternion& r )
: x( r.x )
, y( r.y )
, z( r.z )
, w( r.w )
{

}

Quaternion::Quaternion( const Vec3& axis, float angle )
{
	fillAxisAngle( axis, angle );
}

Quaternion::Quaternion( void )
: x( 0.0f )
, y( 0.0f )
, z( 0.0f )
, w( 1.0f )
{

}

void Quaternion::slerp( const Quaternion& rhs, float t )
{
	float q1x = x;
	float q1y = y;
	float q1z = z;
	float q1w = w;

	float q2x = rhs.x;
	float q2y = rhs.y;
	float q2z = rhs.z;
	float q2w = rhs.w;

	// Fast slerp implementation by kwhatmough:
	// It contains no division operations, no trig, no inverse trig
	// and no sqrt. Not only does this code tolerate small constraint
	// errors in the input quaternions, it actually corrects for them.
	magicalAssert( !( t < 0.0f || t > 1.0f ), "Invaiid operate" );

	if( magicalFltIsZero( t ) )
	{
		x = q1x;
		y = q1y;
		z = q1z;
		w = q1w;
		return;
	}
	else if( magicalFltEqual( t, 1.0f ) )
	{
		x = q2x;
		y = q2y;
		z = q2z;
		w = q2w;
		return;
	}

	if( magicalFltEqual( q1x, q2x ) &&
		magicalFltEqual( q1y, q2y ) &&
		magicalFltEqual( q1z, q2z ) &&
		magicalFltEqual( q1w, q2w ) )
	{
		x = q1x;
		y = q1y;
		z = q1z;
		w = q1w;
		return;
	}

	float halfY, alpha, beta;
	float u, f1, f2a, f2b;
	float ratio1, ratio2;
	float halfSecHalfTheta, versHalfTheta;
	float sqNotU, sqU;

	float cosTheta = q1w * q2w + q1x * q2x + q1y * q2y + q1z * q2z;

	// As usual in all slerp implementations, we fold theta.
	alpha = cosTheta >= 0 ? 1.0f : -1.0f;
	halfY = 1.0f + alpha * cosTheta;

	// Here we bisect the interval, so we need to fold t as well.
	f2b = t - 0.5f;
	u = f2b >= 0 ? f2b : -f2b;
	f2a = u - f2b;
	f2b += u;
	u += u;
	f1 = 1.0f - u;

	// One iteration of Newton to get 1-cos(theta / 2) to good accuracy.
	halfSecHalfTheta = 1.09f - ( 0.476537f - 0.0903321f * halfY ) * halfY;
	halfSecHalfTheta *= 1.5f - halfY * halfSecHalfTheta * halfSecHalfTheta;
	versHalfTheta = 1.0f - halfY * halfSecHalfTheta;

	// Evaluate series expansions of the coefficients.
	sqNotU = f1 * f1;
	ratio2 = 0.0000440917108f * versHalfTheta;
	ratio1 = -0.00158730159f + ( sqNotU - 16.0f ) * ratio2;
	ratio1 = 0.0333333333f + ratio1 * ( sqNotU - 9.0f ) * versHalfTheta;
	ratio1 = -0.333333333f + ratio1 * ( sqNotU - 4.0f ) * versHalfTheta;
	ratio1 = 1.0f + ratio1 * ( sqNotU - 1.0f ) * versHalfTheta;

	sqU = u * u;
	ratio2 = -0.00158730159f + ( sqU - 16.0f ) * ratio2;
	ratio2 = 0.0333333333f + ratio2 * ( sqU - 9.0f ) * versHalfTheta;
	ratio2 = -0.333333333f + ratio2 * ( sqU - 4.0f ) * versHalfTheta;
	ratio2 = 1.0f + ratio2 * ( sqU - 1.0f ) * versHalfTheta;

	// Perform the bisection and resolve the folding done earlier.
	f1 *= ratio1 * halfSecHalfTheta;
	f2a *= ratio2;
	f2b *= ratio2;
	alpha *= f1 + f2a;
	beta = f1 + f2b;

	// Apply final coefficients to a and b as usual.
	float rw = alpha * q1w + beta * q2w;
	float rx = alpha * q1x + beta * q2x;
	float ry = alpha * q1y + beta * q2y;
	float rz = alpha * q1z + beta * q2z;

	// This final adjustment to the quaternion's length corrects for
	// any small constraint error in the inputs q1 and q2 But as you
	// can see, it comes at the cost of 9 additional multiplication
	// operations. If this error-correcting feature is not required,
	// the following code may be removed.
	f1 = 1.5f - 0.5f * ( rw * rw + rx * rx + ry * ry + rz * rz );
	x = rw * f1;
	y = rx * f1;
	z = ry * f1;
	w = rz * f1;
}