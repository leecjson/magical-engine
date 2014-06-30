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
#ifndef __MAT4_HPP__
#define __MAT4_HPP__

#include "Common.h"
#include "kazmath.h"

class mat4 : public kmMat4
{
public:
	mat4( const float* in )
	{
		kmMat4Fill( this, in );
	}

	mat4( void )
	{
		kmMat4Identity( this );
	}

	//inline void identity( void )
	//{
	//	kmMat4Identity( this );
	//}

	//inline mat4 inverse( void ) const
	//{
	//	mat4 result = *this;
	//	kmMat4Inverse( &result, &result );
	//	return result;
	//}

	//inline bool isIdentity( void ) const
	//{
	//	return kmMat4IsIdentity( this );
	//}

	//inline mat4 transpose() const
	//{
	//	mat4 result = *this;
	//	kmMat4Transpose(&result, &result);
	//	return result;
	//}

	//static const mat4 rotationAxis(const kmVec3& axis, const kmScalar radians)
	//{
	//	mat4 result;
	//	kmMat4RotationAxisAngle(&result, &axis, radians);
	//	return result;
	//}

	//static const mat4 rotationAxis(const kmScalar degrees, const kmScalar axis_x, const kmScalar axis_y, const kmScalar axis_z)
	//{
	//	mat4 result;
	//	vec3 axis(axis_x, axis_y, axis_z);
	//	kmMat4RotationAxisAngle(&result, &axis, kmDegreesToRadians(degrees));
	//	return result;
	//}

	//static const mat4 rotationX(const kmScalar radians)
	//{
	//	mat4 result;
	//	kmMat4RotationX(&result, radians);
	//	return result;
	//}

	//static const mat4 rotationY(const kmScalar radians)
	//{
	//	mat4 result;
	//	kmMat4RotationY(&result, radians);
	//	return result;
	//}

	//static const mat4 rotationZ(const kmScalar radians)
	//{
	//	mat4 result;
	//	kmMat4RotationZ(&result, radians);
	//	return result;
	//}

	//static const mat4 rotationPitchYawRoll(const kmScalar pitch, const kmScalar yaw, const kmScalar roll)
	//{
	//	mat4 result;
	//	kmMat4RotationPitchYawRoll(&result, pitch, yaw, roll);
	//	return result;
	//}

	//static const mat4 rotationQuaternion(const kmQuaternion& pQ)
	//{
	//	mat4 result;
	//	kmMat4RotationQuaternion(&result, &pQ);
	//	return result;
	//}

	//static const mat4 scaling(const kmScalar x, const kmScalar y, const kmScalar z)
	//{
	//	mat4 result;
	//	kmMat4Scaling(&result, x,y,z);
	//	return result;
	//}

	//static const mat4 translation(const kmScalar x, const kmScalar y, const kmScalar z)
	//{
	//	mat4 result;
	//	kmMat4Translation(&result, x,y,z);
	//	return result;
	//}

	//const vec3 getUpVec3() const
	//{
	//	vec3 result;
	//	kmMat4GetUpVec3(&result, this);
	//	return result;
	//}

	//const vec3 getRightVec3() const
	//{
	//	vec3 result;
	//	kmMat4GetRightVec3(&result, this);
	//	return result;
	//}

	//const vec3 getForwardVec3() const
	//{
	//	vec3 result;
	//	kmMat4GetForwardVec3(&result, this);
	//	return result;
	//}

	//static const mat4 perspectiveProjection(const kmScalar fovY, const kmScalar aspect, const kmScalar zNear, const kmScalar zFar)
	//{
	//	mat4 result;
	//	kmMat4PerspectiveProjection(&result, fovY, aspect, zNear, zFar);
	//	return result;
	//}

	//static const mat4 orthographicProjection(const kmScalar left, const kmScalar right, const kmScalar bottom, const kmScalar top, const kmScalar nearVal, const kmScalar farVal)
	//{
	//	mat4 result;
	//	kmMat4OrthographicProjection(&result, left, right, bottom, top, nearVal, farVal);
	//	return result;
	//}

	//static const mat4 lookAt(const kmVec3& pEye, const kmVec3& pCenter, const kmVec3& pUp)
	//{
	//	mat4 result;
	//	kmMat4LookAt(&result, &pEye, &pCenter, &pUp);
	//	return result;
	//}
};

///< Matrix multiplication
//inline const mat4 operator*(const mat4& lhs, const mat4& rhs)
//{
//	mat4 result;
//	kmMat4Multiply(&result, &lhs, &rhs);
//	return result;
//};
//
/////< Checks for equality (with a small threshold epsilon)
//inline const bool operator==(const mat4& lhs, const mat4& rhs)
//{
//	return kmMat4AreEqual(&lhs,&rhs);
//};

//// Transform through matrix	
//inline const vec3 operator*( const kmMat4& lhs, const vec3& rhs )
//{
//	vec3 result;
//	kmVec3Transform( (kmVec3*)(&result), (kmVec3*)(&rhs), &lhs);
//	return result;
//}

///< Transform through matrix	
//inline const vec4 operator*(const kmMat4& lhs, const vec4& rhs)
//{
//	vec4 result;
//	kmVec4Transform(&result, &rhs, &lhs);
//	return result;
//}



#endif //__MAT4_HPP__