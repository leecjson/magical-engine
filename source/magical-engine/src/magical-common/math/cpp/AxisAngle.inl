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

inline AxisAngle AxisAngle::fromIdentity( void )
{
	return AxisAngle::Identity;
}

inline AxisAngle AxisAngle::fromZero( void )
{
	return AxisAngle::Zero;
}

inline AxisAngle AxisAngle::fromQuaternion( const Quaternion& q )
{
	AxisAngle ret;
	magicalAxisAngleFromQuaternion( tofpointer( &ret ), tofpointer( &q ) );
	return ret;
}

inline void AxisAngle::getAxis( Vector3& out, const AxisAngle& aa )
{
	magicalAxisAngleGetAxis( tofpointer( &out ), tofpointer( &aa ) );
}

inline bool AxisAngle::equals( const AxisAngle& aa ) const
{
	return magicalAxisAngleEquals( tofpointer( this ), tofpointer( &aa ) );
}

inline bool AxisAngle::isIdentity( void ) const
{
	return magicalAxisAngleIsIdentity( tofpointer( this ) );
}

inline bool AxisAngle::isZero( void ) const
{
	return magicalAxisAngleIsZero( tofpointer( this ) );
}

inline void AxisAngle::fill( const AxisAngle& aa )
{
	magicalAxisAngleFill( tofpointer( this ), tofpointer( &aa ) );
}

inline void AxisAngle::fillScalars( const float x, const float y, const float z, const float w )
{
	magicalAxisAngleFillScalars( tofpointer( this ), x, y, z, w );
}

inline void AxisAngle::fillIdentity( void )
{
	magicalAxisAngleFillIdentity( tofpointer( this ) );
}

inline void AxisAngle::fillZero( void )
{
	magicalAxisAngleFillZero( tofpointer( this ) );
}

inline void AxisAngle::fillQuaternion( const Quaternion& q )
{
	magicalAxisAngleFromQuaternion( tofpointer( this ), tofpointer( &q ) );
}

inline bool AxisAngle::operator==( const AxisAngle& aa ) const
{
	return magicalAxisAngleEquals( tofpointer( this ), tofpointer( &aa ) );
}

inline bool AxisAngle::operator!=( const AxisAngle& aa ) const
{
	return !magicalAxisAngleEquals( tofpointer( this ), tofpointer( &aa ) );
}

inline AxisAngle& AxisAngle::operator=( const AxisAngle& aa )
{
	magicalAxisAngleFill( tofpointer( this ), tofpointer( &aa ) );
}

inline void AxisAngle::setAxis( const Vector3& axis )
{
	magicalAxisAngleSetAxis( tofpointer( this ), tofpointer( &axis ) );
}

inline void AxisAngle::setAngle( const float angle )
{
	magicalAxisAngleSetAngle( tofpointer( this ), angle );
}

inline Vector3 AxisAngle::getAxis( void ) const
{
	Vector3 ret;
	magicalAxisAngleGetAxis( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline float AxisAngle::getAngle( void ) const
{
	return magicalAxisAngleGetAngle( tofpointer( this ) );
}