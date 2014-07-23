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

inline Mat3 Mat3::operator*( const Mat3& m ) const
{
	Mat3 result;
	kmMat3Multiply( &result, this, &m );
	return result;
}

inline bool Mat3::operator==( const Mat3& m ) const
{
	return kmMat3AreEqual( this, &m ) != 0;
}

inline bool Mat3::operator!=( const Mat3& m ) const
{
	return kmMat3AreEqual( this, &m ) == 0;
}

inline Mat3 Mat3::fill( const float* in )
{
	Mat3 result;
	kmMat3Fill( &result, in );
	return result;
}

inline Mat3 Mat3::adjugate( const Mat3& m )
{
	Mat3 result;
	kmMat3Adjugate( &result, &m );
	return result;
}

inline void Mat3::identity( Mat3& m )
{
	kmMat3Identity( &m );
}

inline Mat3 Mat3::inverse( const Mat3& m )
{
	Mat3 result;
	kmMat3Inverse( &result, &m );
	return result;
}

inline bool Mat3::isIdentity( const Mat3& m )
{
	return kmMat3IsIdentity( &m );
}

inline Mat3 Mat3::transpose( const Mat3& m )
{
	Mat3 result;
	kmMat3Transpose( &result, &m );
	return result;
}

inline float Mat3::determinant( const Mat3& m )
{
	return kmMat3Determinant( &m );
}

inline Mat3 Mat3::scalarMultiply( const Mat3& m, const float f )
{
	Mat3 result;
	kmMat3ScalarMultiply( &result, &m, f );
	return result;
}

inline Vec3 Mat3::getUpVec3( const Mat3& m )
{
	Vec3 result;
	kmMat3GetUpVec3( &result, &m );
	return result;
}

inline Vec3 Mat3::getRightVec3( const Mat3& m )
{
	Vec3 result;
	kmMat3GetRightVec3( &result, &m );
	return result;
}

inline Vec3 Mat3::getForwardVec3( const Mat3& m )
{
	Vec3 result;
	kmMat3GetForwardVec3( &result, &m );
	return result;
}

inline Mat3 Mat3::rotationX( const float radians )
{
	Mat3 result;
	kmMat3RotationX( &result, radians );
	return result;
}

inline Mat3 Mat3::rotationY( const float radians )
{
	Mat3 result;
	kmMat3RotationY( &result, radians );
	return result;
}

inline Mat3 Mat3::rotationZ( const float radians )
{
	Mat3 result;
	kmMat3RotationZ( &result, radians );
	return result;
}

inline Mat3 Mat3::rotation( const float radians )
{
	Mat3 result;
	kmMat3Rotation( &result, radians );
	return result;
}

inline Mat3 Mat3::scaling( const float x, const float y )
{
	Mat3 result;
	kmMat3Scaling( &result, x, y );
	return result;
}

inline Mat3 Mat3::translation( const float x, const float y )
{
	Mat3 result;
	kmMat3Translation( &result, x, y );
	return result;
}

inline Mat3 Mat3::rotationAxisAngle( const Vec3& v, const float radians )
{
	Mat3 result;
	kmMat3RotationAxisAngle( &result, &v, radians );
	return result;
}

inline Vec3 Mat3::rotationToAxisAngle( float* radians, const Mat3& m )
{
	Vec3 result;
	kmMat3RotationToAxisAngle( &result, radians, &m );
	return result;
}