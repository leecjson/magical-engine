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

inline AxisRotation AxisRotation::createIdentity( void )
{
	return AxisRotation::Identity;
}

inline AxisRotation AxisRotation::createZero( void )
{
	return AxisRotation::Zero;
}

inline AxisRotation AxisRotation::create( const Vector3& axis, float angle )
{
	AxisRotation ret;
	magicalAxisRotationFill( &ret, axis.x, axis.y, axis.z, angle );
	return ret;
}

inline AxisRotation AxisRotation::createFromQuaternion( const Quaternion& q )
{
	AxisRotation ret;
	magicalAxisRotationFromQuaternion( &ret, &q );
	return ret;
}

inline bool AxisRotation::equals( const AxisRotation& ar ) const
{
	return magicalAxisRotationEquals( this, &ar );
}

inline bool AxisRotation::isIdentity( void ) const
{
	return magicalAxisRotationIsIdentity( this );
}

inline bool AxisRotation::isZero( void ) const
{
	return magicalAxisRotationIsZero( this );
}

inline bool AxisRotation::operator==( const AxisRotation& ar ) const
{
	return magicalAxisRotationEquals( this, &ar );
}

inline bool AxisRotation::operator!=( const AxisRotation& ar ) const
{
	return !magicalAxisRotationEquals( this, &ar );
}

inline AxisRotation& AxisRotation::operator=( const AxisRotation& ar )
{
	magicalAxisRotationCopy( this, &ar );
}

inline void AxisRotation::set( const AxisRotation& ar )
{
	magicalAxisRotationCopy( this, &ar );
}

inline void AxisRotation::set( const Vector3& axis, float angle )
{
	magicalAxisRotationFill( this, axis.x, axis.y, axis.z, angle );
}

inline void AxisRotation::setIdentity( void )
{
	magicalAxisRotationSetIdentity( this );
}

inline void AxisRotation::setZero( void )
{
	magicalAxisRotationSetZero( this );
}

inline void AxisRotation::setScalars( float x, float y, float z, float w )
{
	magicalAxisRotationFill( this, x, y, z, w );
}

inline void AxisRotation::setQuaternion( const Quaternion& q )
{
	magicalAxisRotationFromQuaternion( this, &q );
}

inline Vector3 AxisRotation::axis( void ) const
{
	return Vector3( x, y, z );
}

inline Quaternion AxisRotation::toQuaternion( void ) const
{
	Quaternion ret;
	magicalAxisRotationToQuaternion( &ret, this );
	return ret;
}