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

inline EulerA EulerA::createIdentity( void )
{
	return EulerA::Identity;
}

inline EulerA EulerA::createFromQuaternion( const Quaternion& q )
{
	EulerA ret;
	magicalEulerAFromQuaternion( &ret, &q );
	return ret;
}

inline void EulerA::add( EulerA& out, const EulerA& ea1, const EulerA& ea2 )
{
	magicalEulerAAdd( &out, &ea1, &ea2 );
}

inline void EulerA::sub( EulerA& out, const EulerA& ea1, const EulerA& ea2 )
{
	magicalEulerASub( &out, &ea1, &ea2 );
}

inline void EulerA::mulScalar( EulerA& out, const EulerA& ea, float a )
{
	magicalEulerAMulScalar( &out, &ea, a );
}

inline void EulerA::mul( EulerA& out, const EulerA& ea1, const EulerA& ea2 )
{
	magicalEulerAMul( &out, &ea1, &ea2 );
}

inline void EulerA::limit( EulerA& out, const EulerA& ea )
{
	magicalEulerALimit( &out, &ea );
}

inline bool EulerA::equals( const EulerA& ea ) const
{
	return magicalEulerAEqulas( this, &ea );
}

inline bool EulerA::isIdentity( void ) const
{
	return magicalEulerAIsIdentity( this );
}

inline bool EulerA::operator==( const EulerA& ea ) const
{
	return magicalEulerAEqulas( this, &ea );
}

inline bool EulerA::operator!=( const EulerA& ea ) const
{
	return !magicalEulerAEqulas( this, &ea );
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

inline EulerA EulerA::operator*( float a ) const
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

inline EulerA& EulerA::operator*=( float a )
{
	yaw *= a; pitch *= a; roll *= a;
	return *this;
}

inline EulerA& EulerA::operator=( const EulerA& ea )
{
	yaw = ea.yaw; pitch = ea.pitch; roll = ea.roll;
	return *this;
}

inline void EulerA::set( const EulerA& ea )
{
	yaw = ea.yaw; pitch = ea.pitch; roll = ea.roll;
}

inline void EulerA::setIdentity( void )
{
	magicalEulerASetIdentity( this );
}

inline void EulerA::setScalars( float yaw, float pitch, float roll )
{
	magicalEulerAFill( this, yaw, pitch, roll );
}

inline void EulerA::setQuaternion( const Quaternion& q )
{
	magicalEulerAFromQuaternion( this, &q );
}

inline void EulerA::limit( void )
{
	magicalEulerALimit( this, this );
}

inline EulerA EulerA::getLimited( void ) const
{
	EulerA ret;
	magicalEulerALimit( &ret, this );
	return ret;
}

inline Quaternion EulerA::toQuaternion( void ) const
{
	Quaternion ret;
	magicalEulerAToQuaternion( &ret, this );
	return ret;
}