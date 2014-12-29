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

inline EulerAngles EulerAngles::createZero( void )
{
	return EulerAngles::Zero;
}

inline EulerAngles EulerAngles::createFromQuaternion( const Quaternion& q )
{
	EulerAngles ret;
	magicalEulerAnglesFromQuaternion( &ret, &q );
	return ret;
}

inline void EulerAngles::add( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 )
{
	magicalEulerAnglesAdd( &out, &ea1, &ea2 );
}

inline void EulerAngles::sub( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 )
{
	magicalEulerAnglesSub( &out, &ea1, &ea2 );
}

inline void EulerAngles::mulScalar( EulerAngles& out, const EulerAngles& ea, float a )
{
	magicalEulerAnglesMulScalar( &out, &ea, a );
}

inline void EulerAngles::mul( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 )
{
	magicalEulerAnglesMul( &out, &ea1, &ea2 );
}

inline void EulerAngles::limit( EulerAngles& out, const EulerAngles& ea )
{
	magicalEulerAnglesLimit( &out, &ea );
}

inline bool EulerAngles::equals( const EulerAngles& ea ) const
{
	return magicalEulerAnglesEqulas( this, &ea );
}

inline bool EulerAngles::isZero( void ) const
{
	return magicalEulerAnglesIsZero( this );
}

inline bool EulerAngles::operator==( const EulerAngles& ea ) const
{
	return magicalEulerAnglesEqulas( this, &ea );
}

inline bool EulerAngles::operator!=( const EulerAngles& ea ) const
{
	return !magicalEulerAnglesEqulas( this, &ea );
}

inline EulerAngles EulerAngles::operator+( const EulerAngles& ea ) const
{
	return EulerAngles( yaw + ea.yaw, pitch + ea.pitch, roll + ea.roll );
}

inline EulerAngles EulerAngles::operator-( const EulerAngles& ea ) const
{
	return EulerAngles( yaw - ea.yaw, pitch - ea.pitch, roll - ea.roll );
}

inline EulerAngles EulerAngles::operator*( const EulerAngles& ea ) const
{
	return EulerAngles( yaw * ea.yaw, pitch * ea.pitch, roll * ea.roll );
}

inline EulerAngles EulerAngles::operator*( float a ) const
{
	return EulerAngles( yaw * a, pitch * a, roll * a );
}

inline EulerAngles& EulerAngles::operator+=( const EulerAngles& ea )
{
	yaw += ea.yaw; pitch += ea.pitch; roll += ea.roll;
	return *this;
}

inline EulerAngles& EulerAngles::operator-=( const EulerAngles& ea )
{
	yaw -= ea.yaw; pitch -= ea.pitch; roll -= ea.roll;
	return *this;
}

inline EulerAngles& EulerAngles::operator*=( const EulerAngles& ea )
{
	yaw *= ea.yaw; pitch *= ea.pitch; roll *= ea.roll;
	return *this;
}

inline EulerAngles& EulerAngles::operator*=( float a )
{
	yaw *= a; pitch *= a; roll *= a;
	return *this;
}

inline EulerAngles& EulerAngles::operator=( const EulerAngles& ea )
{
	yaw = ea.yaw; pitch = ea.pitch; roll = ea.roll;
	return *this;
}

inline void EulerAngles::set( const EulerAngles& ea )
{
	yaw = ea.yaw; pitch = ea.pitch; roll = ea.roll;
}

inline void EulerAngles::setZero( void )
{
	magicalEulerAnglesSetZero( this );
}

inline void EulerAngles::setScalars( float yaw, float pitch, float roll )
{
	magicalEulerAnglesFill( this, yaw, pitch, roll );
}

inline void EulerAngles::fromQuaternion( const Quaternion& q )
{
	magicalEulerAnglesFromQuaternion( this, &q );
}

inline Quaternion EulerAngles::toQuaternion( void ) const
{
	Quaternion ret;
	magicalEulerAnglesToQuaternion( &ret, this );
	return ret;
}

inline void EulerAngles::limit( void )
{
	magicalEulerAnglesLimit( this, this );
}

inline EulerAngles EulerAngles::getLimited( void ) const
{
	EulerAngles ret;
	magicalEulerAnglesLimit( &ret, this );
	return ret;
}