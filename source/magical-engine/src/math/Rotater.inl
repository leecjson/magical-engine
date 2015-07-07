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
NAMESPACE_MAGICAL

inline Rotater::Rotater( const Quaternion& q )
{
	fromQuaternion( q );
}

inline Rotater::Rotater( float yaw, float pitch, float roll ) 
: yaw( yaw ), pitch( pitch ), roll( roll )
{
	
}

inline Rotater::Rotater( const Rotater& ea ) 
: yaw( ea.yaw ), pitch( ea.pitch ), roll( ea.roll )
{
	
}

inline Rotater::Rotater( void )
{
	
}

inline bool Rotater::operator==( const Rotater& ea ) const
{
	return equals( ea );
}

inline bool Rotater::operator!=( const Rotater& ea ) const
{
	return equals( ea ) == false;
}

inline Rotater& Rotater::operator=( const Rotater& ea )
{
	yaw = ea.yaw;
	pitch = ea.pitch;
	roll = ea.roll;
	return *this;
}

inline Rotater Rotater::operator+( void ) const
{
	return *this;
}

inline Rotater Rotater::operator+( float a ) const
{
	return Rotater( yaw + a, pitch + a, roll + a );
}

inline Rotater Rotater::operator+( const Rotater& ea ) const
{
	return Rotater( yaw + ea.yaw, pitch + ea.pitch, roll + ea.roll );
}

inline Rotater Rotater::operator-( void ) const
{
	return Rotater( -yaw, -pitch, -roll );
}

inline Rotater Rotater::operator-( float a ) const
{
	return Rotater( yaw - a, pitch - a, roll - a );
}

inline Rotater Rotater::operator-( const Rotater& ea ) const
{
	return Rotater( yaw - ea.yaw, pitch - ea.pitch, roll - ea.roll );
}

inline Rotater Rotater::operator*( float a ) const
{
	return Rotater( yaw * a, pitch * a, roll * a );
}

inline Rotater Rotater::operator*( const Rotater& ea ) const
{
	return Rotater( yaw * ea.yaw, pitch * ea.pitch, roll * ea.roll );
}

inline Rotater Rotater::operator/( float a ) const
{
	return Rotater( yaw / a, pitch / a, roll / a );
}

inline Rotater Rotater::operator/( const Rotater& ea ) const
{
	return Rotater( yaw / ea.yaw, pitch / ea.pitch, roll / ea.roll );
}

inline Rotater& Rotater::operator+=( float a )
{
	yaw += a;
	pitch += a;
	roll += a;
	return *this;
}

inline Rotater& Rotater::operator+=( const Rotater& ea )
{
	yaw += ea.yaw;
	pitch += ea.pitch;
	roll += ea.roll;
	return *this;
}

inline Rotater& Rotater::operator-=( float a )
{
	yaw -= a;
	pitch -= a;
	roll -= a;
	return *this;
}

inline Rotater& Rotater::operator-=( const Rotater& ea )
{
	yaw -= ea.yaw;
	pitch -= ea.pitch;
	roll -= ea.roll;
	return *this;
}

inline Rotater& Rotater::operator*=( float a )
{
	yaw *= a;
	pitch *= a;
	roll *= a;
	return *this;
}

inline Rotater& Rotater::operator*=( const Rotater& ea )
{
	yaw *= ea.yaw;
	pitch *= ea.pitch;
	roll *= ea.roll;
	return *this;
}

inline Rotater& Rotater::operator/=( float a )
{
	yaw /= a;
	pitch /= a;
	roll /= a;
	return *this;
}

inline Rotater& Rotater::operator/=( const Rotater& ea )
{
	yaw /= ea.yaw;
	pitch /= ea.pitch;
	roll /= ea.roll;
	return *this;
}

inline void Rotater::add( Rotater& dst, const Rotater& ea1, const Rotater& ea2 )
{
	dst.yaw = ea1.yaw + ea2.yaw;
	dst.pitch = ea1.pitch + ea2.pitch;
	dst.roll = ea1.roll + ea2.roll;
}

inline void Rotater::sub( Rotater& dst, const Rotater& ea1, const Rotater& ea2 )
{
	dst.yaw = ea1.yaw - ea2.yaw;
	dst.pitch = ea1.pitch - ea2.pitch;
	dst.roll = ea1.roll - ea2.roll;
}

inline void Rotater::mul( Rotater& dst, const Rotater& ea1, const Rotater& ea2 )
{
	dst.yaw = ea1.yaw * ea2.yaw;
	dst.pitch = ea1.pitch * ea2.pitch;
	dst.roll = ea1.roll * ea2.roll;
}

inline void Rotater::div( Rotater& dst, const Rotater& ea1, const Rotater& ea2 )
{
	dst.yaw = ea1.yaw / ea2.yaw;
	dst.pitch = ea1.pitch / ea2.pitch;
	dst.roll = ea1.roll / ea2.roll;
}

inline void Rotater::addScalar( Rotater& dst, const Rotater& ea, float a )
{
	dst.yaw = ea.yaw + a;
	dst.pitch = ea.pitch + a;
	dst.roll = ea.roll + a;
}

inline void Rotater::subScalar( Rotater& dst, const Rotater& ea, float a )
{
	dst.yaw = ea.yaw - a;
	dst.pitch = ea.pitch - a;
	dst.roll = ea.roll - a;
}

inline void Rotater::mulScalar( Rotater& dst, const Rotater& ea, float a )
{
	dst.yaw = ea.yaw * a;
	dst.pitch = ea.pitch * a;
	dst.roll = ea.roll * a;
}

inline void Rotater::divScalar( Rotater& dst, const Rotater& ea, float a )
{
	dst.yaw = ea.yaw / a;
	dst.pitch = ea.pitch / a;
	dst.roll = ea.roll / a;
}

inline Rotater Rotater::add( const Rotater& ea1, const Rotater& ea2 )
{
	return Rotater( ea1.yaw + ea2.yaw, ea1.pitch + ea2.pitch, ea1.roll + ea2.roll );
}

inline Rotater Rotater::sub( const Rotater& ea1, const Rotater& ea2 )
{
	return Rotater( ea1.yaw - ea2.yaw, ea1.pitch - ea2.pitch, ea1.roll - ea2.roll );
}

inline Rotater Rotater::mul( const Rotater& ea1, const Rotater& ea2 )
{
	return Rotater( ea1.yaw * ea2.yaw, ea1.pitch * ea2.pitch, ea1.roll * ea2.roll );
}

inline Rotater Rotater::div( const Rotater& ea1, const Rotater& ea2 )
{
	return Rotater( ea1.yaw / ea2.yaw, ea1.pitch / ea2.pitch, ea1.roll / ea2.roll );
}

inline Rotater Rotater::addScalar( const Rotater& ea, float a )
{
	return Rotater( ea.yaw + a, ea.pitch + a, ea.roll + a );
}

inline Rotater Rotater::subScalar( const Rotater& ea, float a )
{
	return Rotater( ea.yaw - a, ea.pitch - a, ea.roll - a );
}

inline Rotater Rotater::mulScalar( const Rotater& ea, float a )
{
	return Rotater( ea.yaw * a, ea.pitch * a, ea.roll * a );
}

inline Rotater Rotater::divScalar( const Rotater& ea, float a )
{
	return Rotater( ea.yaw / a, ea.pitch / a, ea.roll / a );
}

inline void Rotater::add( const Rotater& ea )
{
	yaw += ea.yaw;
	pitch += ea.pitch;
	roll += ea.roll;
}

inline void Rotater::sub( const Rotater& ea )
{
	yaw -= ea.yaw;
	pitch -= ea.pitch;
	roll -= ea.roll;
}

inline void Rotater::mul( const Rotater& ea )
{
	yaw *= ea.yaw;
	pitch *= ea.pitch;
	roll *= ea.roll;
}

inline void Rotater::div( const Rotater& ea )
{
	yaw /= ea.yaw;
	pitch /= ea.pitch;
	roll /= ea.roll;
}

inline void Rotater::addScalar( float a )
{
	yaw += a;
	pitch += a;
	roll += a;
}

inline void Rotater::subScalar( float a )
{
	yaw -= a;
	pitch -= a;
	roll -= a;
}

inline void Rotater::mulScalar( float a )
{
	yaw *= a;
	pitch *= a;
	roll *= a;
}

inline void Rotater::divScalar( float a )
{
	yaw /= a;
	pitch /= a;
	roll /= a;
}

inline bool Rotater::equals( const Rotater& ea ) const
{
	return
		Math::isAlmostEqual( yaw, ea.yaw, Math::RadianEpsilon ) &&
		Math::isAlmostEqual( pitch, ea.pitch, Math::RadianEpsilon ) &&
		Math::isAlmostEqual( roll, ea.roll, Math::RadianEpsilon );
}

inline bool Rotater::isZero( void ) const
{
	return
		Math::isAlmostZero( yaw, Math::RadianEpsilon ) &&
		Math::isAlmostZero( pitch, Math::RadianEpsilon ) &&
		Math::isAlmostZero( roll, Math::RadianEpsilon );
}

inline void Rotater::setZero( void )
{
	yaw = 0.0f;
	pitch = 0.0f;
	roll = 0.0f;
}

inline void Rotater::set( const Rotater& ea )
{
	yaw = ea.yaw;
	pitch = ea.pitch;
	roll = ea.roll;
}

inline void Rotater::set( float yaw, float pitch, float roll )
{
	this->yaw = yaw;
	this->pitch = pitch;
	this->roll = roll;
}

inline void Rotater::limit( void )
{
	return Rotater::limit( *this, *this );
}

NAMESPACE_END