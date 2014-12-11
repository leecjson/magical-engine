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

inline AxisA AxisA::fromIdentity( void )
{
	return AxisA::Identity;
}

inline AxisA AxisA::fromZero( void )
{
	return AxisA::Zero;
}

inline AxisA AxisA::fromQuaternion( const Quaternion& q )
{
	AxisA ret;
	magicalAxisAFromQuaternion( tofpointer( &ret ), tofpointer( &q ) );
	return ret;
}

inline void AxisA::getAxis( Vector3& out, const AxisA& aa )
{
	magicalAxisAGetAxis( tofpointer( &out ), tofpointer( &aa ) );
}

inline bool AxisA::equals( const AxisA& aa ) const
{
	return magicalAxisAEquals( tofpointer( this ), tofpointer( &aa ) );
}

inline bool AxisA::isIdentity( void ) const
{
	return magicalAxisAIsIdentity( tofpointer( this ) );
}

inline bool AxisA::isZero( void ) const
{
	return magicalAxisAIsZero( tofpointer( this ) );
}

inline void AxisA::fill( const AxisA& aa )
{
	magicalAxisAFill( tofpointer( this ), tofpointer( &aa ) );
}

inline void AxisA::fillScalars( const float x, const float y, const float z, const float w )
{
	magicalAxisAFillScalars( tofpointer( this ), x, y, z, w );
}

inline void AxisA::fillIdentity( void )
{
	magicalAxisAFillIdentity( tofpointer( this ) );
}

inline void AxisA::fillZero( void )
{
	magicalAxisAFillZero( tofpointer( this ) );
}

inline void AxisA::fillQuaternion( const Quaternion& q )
{
	magicalAxisAFromQuaternion( tofpointer( this ), tofpointer( &q ) );
}

inline bool AxisA::operator==( const AxisA& aa ) const
{
	return magicalAxisAEquals( tofpointer( this ), tofpointer( &aa ) );
}

inline bool AxisA::operator!=( const AxisA& aa ) const
{
	return !magicalAxisAEquals( tofpointer( this ), tofpointer( &aa ) );
}

inline AxisA& AxisA::operator=( const AxisA& aa )
{
	magicalAxisAFill( tofpointer( this ), tofpointer( &aa ) );
}

inline void AxisA::setAxis( const Vector3& axis )
{
	magicalAxisASetAxis( tofpointer( this ), tofpointer( &axis ) );
}

inline void AxisA::setAngle( const float angle )
{
	magicalAxisASetAngle( tofpointer( this ), angle );
}

inline Vector3 AxisA::getAxis( void ) const
{
	Vector3 ret;
	magicalAxisAGetAxis( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}

inline float AxisA::getAngle( void ) const
{
	return magicalAxisAGetAngle( tofpointer( this ) );
}