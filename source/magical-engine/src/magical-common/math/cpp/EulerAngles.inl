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

inline EulerAngles EulerAngles::fromMatrix4( const Matrix4& m )
{
	EulerAngles ret;
	magicalEulerAnglesFromMatrix4( tofpointer( &ret ), tofpointer( &m ) );
	return ret;
}

inline EulerAngles EulerAngles::fromQuaternion( const Quaternion& q )
{
	EulerAngles ret;
	magicalEulerAnglesFromQuaternion( tofpointer( &ret ), tofpointer( &q ) );
	return ret;
}

inline bool EulerAngles::equals( const EulerAngles& ea ) const
{
	return magicalEulerAnglesEqulas( tofpointer( this ), tofpointer( &ea ) );
}

inline bool EulerAngles::isIdentity( void ) const
{
	return magicalEulerAnglesIsIdentity( tofpointer( this ) );
}

inline void EulerAngles::fill( const EulerAngles& ea )
{
	magicalEulerAnglesFill( tofpointer( this ), tofpointer( &ea ) );
}

inline void EulerAngles::fill( const float yaw, const float pitch, const float roll )
{
	magicalEulerAnglesFillYawPitchRoll( tofpointer( this ), yaw, pitch, roll );
}

inline void EulerAngles::fillIdentity( void )
{
	magicalEulerAnglesFillIdentity( tofpointer( this ) );
}

inline void EulerAngles::fillMatrix4( const Matrix4& m )
{
	magicalEulerAnglesFromMatrix4( tofpointer( this ), tofpointer( &m ) );
}

inline void EulerAngles::fillQuaternion( const Quaternion& q )
{
	magicalEulerAnglesFromQuaternion( tofpointer( this ), tofpointer( &q ) );
}

inline void EulerAngles::add( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 )
{
	magicalEulerAnglesAdd( tofpointer( &out ), tofpointer( &ea1 ), tofpointer( &ea2 ) );
}

inline void EulerAngles::sub( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 )
{
	magicalEulerAnglesSub( tofpointer( &out ), tofpointer( &ea1 ), tofpointer( &ea2 ) );
}

inline void EulerAngles::mulScalar( EulerAngles& out, const EulerAngles& ea, const float a )
{
	magicalEulerAnglesMulScalar( tofpointer( &out ), tofpointer( &ea ), a );
}

inline void EulerAngles::mul( EulerAngles& out, const EulerAngles& ea1, const EulerAngles& ea2 )
{
	magicalEulerAnglesMul( tofpointer( &out ), tofpointer( &ea1 ), tofpointer( &ea2 ) );
}

inline bool EulerAngles::operator==( const EulerAngles& ea ) const
{
	return magicalEulerAnglesEqulas( tofpointer( this ), tofpointer( &ea ) );
}

inline bool EulerAngles::operator!=( const EulerAngles& ea ) const
{
	return !magicalEulerAnglesEqulas( tofpointer( this ), tofpointer( &ea ) );
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

inline EulerAngles EulerAngles::operator*( const float a ) const
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

inline EulerAngles& EulerAngles::operator*=( const float a )
{
	yaw *= a; pitch *= a; roll *= a;
	return *this;
}

inline EulerAngles& EulerAngles::operator=( const EulerAngles& ea )
{
	magicalEulerAnglesFill( tofpointer( this ), tofpointer( &ea ) );
	return *this;
}

inline void EulerAngles::corrects( EulerAngles& out, const EulerAngles& ea )
{
	magicalEulerAnglesCorrects( tofpointer( &out ), tofpointer( &ea ) );
}

inline void EulerAngles::corrects( void )
{
	magicalEulerAnglesCorrects( tofpointer( this ), tofpointer( this ) );
}

inline EulerAngles EulerAngles::getCorrected( void ) const
{
	EulerAngles ret;
	magicalEulerAnglesCorrects( tofpointer( &ret ), tofpointer( this ) );
	return ret;
}