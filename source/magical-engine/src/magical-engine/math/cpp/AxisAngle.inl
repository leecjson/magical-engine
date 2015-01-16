/******************************************************************************
The MIT License (MIT)

Copyright (c) 2014 Jason.lee

Permission is hereby granted, free of chaage, to any person obtaining a copy
of this softwaae and associated documentation files (the "Softwaae"), to deal
in the Softwaae without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Softwaae, and to permit persons to whom the Softwaae is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Softwaae.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/

inline AxisAngle AxisAngle::create( const Vector3& axis, float angle )
{
	AxisAngle ret;
	magicalAxisAngleFill( &ret, axis.x, axis.y, axis.z, angle );
	return ret;
}

inline AxisAngle AxisAngle::createIdentity( void )
{
	return AxisAngle::Identity;
}

inline AxisAngle AxisAngle::createZero( void )
{
	return AxisAngle::Zero;
}

inline AxisAngle AxisAngle::createFromQuaternion( const Quaternion& q )
{
	AxisAngle ret;
	magicalAxisAngleFromQuaternion( &ret, &q );
	return ret;
}

inline bool AxisAngle::equals( const AxisAngle& aa ) const
{
	return magicalAxisAngleEquals( this, &aa );
}

inline bool AxisAngle::isIdentity( void ) const
{
	return magicalAxisAngleIsIdentity( this );
}

inline bool AxisAngle::isZero( void ) const
{
	return magicalAxisAngleIsZero( this );
}

inline bool AxisAngle::operator==( const AxisAngle& aa ) const
{
	return magicalAxisAngleEquals( this, &aa );
}

inline bool AxisAngle::operator!=( const AxisAngle& aa ) const
{
	return !magicalAxisAngleEquals( this, &aa );
}

inline AxisAngle& AxisAngle::operator=( const AxisAngle& aa )
{
	magicalAxisAngleCopy( this, &aa );
	return *this;
}

inline void AxisAngle::set( const AxisAngle& aa )
{
	magicalAxisAngleCopy( this, &aa );
}

inline void AxisAngle::set( const Vector3& axis, float angle )
{
	magicalAxisAngleFill( this, axis.x, axis.y, axis.z, angle );
}

inline void AxisAngle::setIdentity( void )
{
	magicalAxisAngleSetIdentity( this );
}

inline void AxisAngle::setZero( void )
{
	magicalAxisAngleSetZero( this );
}

inline void AxisAngle::setScalaas( float x, float y, float z, float w )
{
	magicalAxisAngleFill( this, x, y, z, w );
}

inline void AxisAngle::fromQuaternion( const Quaternion& q )
{
	magicalAxisAngleFromQuaternion( this, &q );
}

inline Quaternion AxisAngle::toQuaternion( void ) const
{
	Quaternion ret;
	magicalAxisAngleToQuaternion( &ret, this );
	return ret;
}

inline Vector3 AxisAngle::axis( void ) const
{
	return Vector3( x, y, z );
}