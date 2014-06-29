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
#ifndef __MAT3_HPP__
#define __MAT3_HPP__

#include "Common.h"
#include "kazmath.h"

class mat3 : public kmMat3
{
public:
	mat3( const float* in )
	{
		kmMat3Fill( this, in );
	}

	mat3( void )
	{
		kmMat3Identity( this );
	}

	inline void identity( void )
	{
		kmMat3Identity( this );
	}

	inline mat3 inverse( void ) const
	{
		mat3 result = *this;
		kmMat3Inverse( &result, &result );
		return result;
	}

	inline bool isIdentity( void ) const
	{
		return kmMat3IsIdentity( this );
	}

	inline mat3 transpose( void ) const
	{
		mat3 result = *this;
		kmMat3Transpose( &result, &result );
		return result;
	}

	/*static const mat3 rotation(const kmScalar radians)
	{
		mat3 result;
		kmMat3Rotation(&result, radians);
		return result;
	}

	static const mat3 scaling(const kmScalar x, const kmScalar y)
	{
		mat3 result;
		kmMat3Scaling(&result, x,y);
		return result;
	}

	static const mat3 translation(const kmScalar x, const kmScalar y)
	{
		mat3 result;
		kmMat3Translation(&result, x,y);
		return result;
	}*/

	/* still missing:
	kmMat3* kmMat3Adjugate(kmMat3* pOut, const kmMat3* pIn);
	kmScalar kmMat3Determinant(const kmMat3* pIn);
	kmMat3* kmMat3ScalarMultiply(kmMat3* pOut, const kmMat3* pM, const kmScalar pFactor);
	*/
};

//inline vec2 operator*( const kmMat3& lhs, const vec2& rhs )
//{
//	vec2 result;
//	kmVec2Transform(&result, &rhs, &lhs);
//	return result;
//};



#endif //__MAT3_HPP__