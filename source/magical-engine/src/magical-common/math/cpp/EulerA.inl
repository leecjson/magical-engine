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

inline EulerA EulerA::fromIdentity( void )
{
	return EulerA::Identity;
}

inline EulerA EulerA::fromMatrix4( const Matrix4& m )
{
	EulerA ret;
	magicalEulerAFromMatrix4( tofpointer( &ret ), tofpointer( &m ) );
	return ret;
}

inline EulerA EulerA::fromQuaternion( const Quaternion& q )
{
	EulerA ret;
	magicalEulerAFromQuaternion( tofpointer( &ret ), tofpointer( &q ) );
	return ret;
}

inline void EulerA::add( EulerA& out, const EulerA& ea1, const EulerA& ea2 )
{
	magicalEulerAAdd( tofpointer( &out ), tofpointer( &ea1 ), tofpointer( &ea2 ) );
}

inline void EulerA::sub( EulerA& out, const EulerA& ea1, const EulerA& ea2 )
{
	magicalEulerASub( tofpointer( &out ), tofpointer( &ea1 ), tofpointer( &ea2 ) );
}

inline void EulerA::mulScalar( EulerA& out, const EulerA& ea, const float a )
{
	magicalEulerAMulScalar( tofpointer( &out ), tofpointer( &ea ), a );
}

inline void EulerA::mul( EulerA& out, const EulerA& ea1, const EulerA& ea2 )
{
	magicalEulerAMul( tofpointer( &out ), tofpointer( &ea1 ), tofpointer( &ea2 ) );
}

inline void EulerA::corrects( EulerA& out, const EulerA& ea )
{
	magicalEulerACorrects( tofpointer( &out ), tofpointer( &ea ) );
}

inline bool EulerA::equals( const EulerA& ea ) const
{
	return magicalEulerAEqulas( tofpointer( this ), tofpointer( &ea ) );
}

inline bool EulerA::isIdentity( void ) const
{
	return magicalEulerAIsIdentity( tofpointer( this ) );
}

inline void EulerA::fill( const EulerA& ea )
{
	magicalEulerAFill( tofpointer( this ), tofpointer( &ea ) );
}

inline void EulerA::fill( const float yaw, const float pitch, const float roll )
{
	magicalEulerAFillYawPitchRoll( tofpointer( this ), yaw, pitch, roll );
}

inline void EulerA::fillIdentity( void )
{
	magicalEulerAFillIdentity( tofpointer( this ) );
}

inline void EulerA::fillMatrix4( const Matrix4& m )
{
	magicalEulerAFromMatrix4( tofpointer( this ), tofpointer( &m ) );
}

inline void EulerA::fillQuaternion( const Quaternion& q )
{
	magicalEulerAFromQuaternion( tofpointer( this ), tofpointer( &q ) );
}

inline bool EulerA::operator==( const EulerA& ea ) const
{
	return magicalEulerAEqulas( tofpointer( this ), tofpointer( &ea ) );
}

inline bool EulerA::operator!=( const EulerA& ea ) const
{
	return !magicalEulerAEqulas( tofpointer( this ), tofpointer( &ea ) );
}

inline EulerA EulerA::operator+( const EulerA& ea ) const
{
	return EulerA( yaw + ea.yaw, pitch + ea.pitch, roll + ea.roll );
}

inline EulerA EulerA::operator-( const EulerA& ea ) const
{
	return EulerA( yaw - ea.yaw, pitch - ea.pitch, roll - ea.roll );
}

inline EulerA EulerA::operator*( const EulerA& ea ) const
{
	return EulerA( yaw * ea.yaw, pitch * ea.pitch, roll * ea.roll );
}

inline EulerA EulerA::operator*( const float a ) const
{
	return EulerA( yaw * a, pitch * a, roll * a );
}

inline EulerA& EulerA::operator+=( const EulerA& ea )
{
	yaw += ea.yaw; pitch += ea.pitch; roll += ea.roll;
	return *this;
}

inline EulerA& EulerA::operator-=( const EulerA& ea )
{
	yaw -= ea.yaw; pitch -= ea.pitch; roll -= ea.roll;
	return *this;
}

inline EulerA& EulerA::operator*=( const EulerA& ea )
{
	yaw *= ea.yaw; pitch *= ea.pitch; roll *= ea.roll;
	return *this;
}

inline EulerA& EulerA::operator*=( const float a )
{
	yaw *= a; pitch *= a; roll *= a;
	return *this;
}

inline EulerA& EulerA::operator=( const EulerA& ea )
{
	magicalEulerAFill( tofpointer( this ), tofpointer( &ea ) );
	return *this;
}

inline void EulerA::corrects( void )
{
	magicalEulerACorrects( tofpointer( this ), tofpointer( this ) );
}

inline EulerA EulerA::getCorrected( void ) const
{
	EulerA ret;
	magicalEulerACorrects( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}