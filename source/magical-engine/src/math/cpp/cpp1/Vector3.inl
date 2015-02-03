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

NS_MAGICAL_BEGIN

inline Vector3 Vector3::createZero( void )
{
	return Vector3::Zero;
}

inline Vector3 Vector3::createOne( void )
{
	return Vector3::One;
}

inline Vector3 Vector3::createFromVector2( const Vector2& v )
{
	return Vector3( v.x, v.y, 0.0f );
}

inline Vector3 Vector3::createFromVector4( const Vector4& v )
{
	return Vector3( v.x, v.y, v.z );
}

inline void Vector3::addScalar( Vector3& out, const Vector3& v, float a )
{
	magicalVector3AddScalar( &out, &v, a );
}

inline void Vector3::add( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3Add( &out, &v1, &v2 );
}

inline void Vector3::subScalar( Vector3& out, const Vector3& v, float a )
{
	magicalVector3SubScalar( &out, &v, a );
}

inline void Vector3::sub( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3Sub( &out, &v1, &v2 );
}

inline void Vector3::mulMatrix4( Vector3& out, const Vector3& v, const Matrix4& m )
{
	magicalVector3MulMatrix4( &out, &v, &m );
}

inline void Vector3::mulScalar( Vector3& out, const Vector3& v, float a )
{
	magicalVector3MulScalar( &out, &v, a );
}

inline void Vector3::mul( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3Mul( &out, &v1, &v2 );
}

inline void Vector3::divScalar( Vector3& out, const Vector3& v, float a )
{
	magicalVector3DivScalar( &out, &v, a );
}

inline void Vector3::div( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3Div( &out, &v1, &v2 );
}

inline void Vector3::cross( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3Cross( &out, &v1, &v2 );
}

inline void Vector3::clamp( Vector3& out, const Vector3& v, const Vector3& min, const Vector3& max )
{
	magicalVector3Clamp( &out, &v, &min, &max );
}

inline void Vector3::negate( Vector3& out, const Vector3& v )
{
	magicalVector3Negate( &out, &v );
}

inline void Vector3::normalize( Vector3& out, const Vector3& v )
{
	magicalVector3Normalize( &out, &v );
}

inline void Vector3::scale( Vector3& out, const Vector3& v, float s )
{
	magicalVector3Scale( &out, &v, s );
}

inline void Vector3::midPointBetween( Vector3& out, const Vector3& v1, const Vector3& v2 )
{
	magicalVector3MidPointBetween( &out, &v1, &v2 );
}

inline void Vector3::project( Vector3& out, const Vector3& v, const Vector3& n )
{
	magicalVector3Project( &out, &v, &n );
}

inline bool Vector3::equals( const Vector3& v ) const
{
	return magicalVector3Equals( this, &v );
}

inline bool Vector3::isZero( void ) const
{
	return magicalVector3IsZero( this );
}

inline bool Vector3::isOne( void ) const
{
	return magicalVector3IsOne( this );
}

inline bool Vector3::isNormalized( void ) const
{
	return magicalVector3IsNormalized( this );
}

inline bool Vector3::operator==( const Vector3& v ) const
{
	return magicalVector3Equals( this, &v );
}

inline bool Vector3::operator!=( const Vector3& v ) const
{
	return !magicalVector3Equals( this, &v );
}

inline float& Vector3::operator[]( const unsigned int i ) const
{
#ifdef MAGICAL_DEBUG
	assert( 0 <= i && i <= 2 && "index out of range" );
#endif
	return ((float*)this)[i];
}

inline Vector3 Vector3::operator+( void ) const
{
	return *this;
}

inline Vector3 Vector3::operator+( float a ) const
{
	return Vector3( x + a, y + a, z + a );
}

inline Vector3 Vector3::operator+( const Vector3& v ) const
{
	return Vector3( x + v.x, y + v.y, z + v.z );
}

inline Vector3 Vector3::operator-( void ) const
{
	return Vector3( -x, -y, -z );
}

inline Vector3 Vector3::operator-( float a ) const
{
	return Vector3( x - a, y - a, z - a );
}

inline Vector3 Vector3::operator-( const Vector3& v ) const
{
	return Vector3( x - v.x, y - v.y, z - v.z );
}

inline Vector3 Vector3::operator*( const Matrix4& m ) const
{
	Vector3 ret;
	magicalVector3MulMatrix4( &ret, this, &m );
	return ret;
}

inline Vector3 Vector3::operator*( float a ) const
{
	return Vector3( x * a, y * a, z * a );
}

inline Vector3 Vector3::operator*( const Vector3& v ) const
{
	return Vector3( x * v.x, y * v.y, z * v.z );
}

inline Vector3 Vector3::operator/( float a ) const
{
	Vector3 ret;
	magicalVector3DivScalar( &ret, this, a );
	return ret;
}

inline Vector3 Vector3::operator/( const Vector3& v ) const
{
	Vector3 ret;
	magicalVector3Div( &ret, this, &v );
	return ret;
}

inline Vector3& Vector3::operator+=( float a )
{
	x += a; y += a; z += a;
	return *this;
}

inline Vector3& Vector3::operator+=( const Vector3& v )
{
	x += v.x; y += v.y; z += v.z;
	return *this;
}

inline Vector3& Vector3::operator-=( float a )
{
	x -= a; y -= a; z -= a;
	return *this;
}

inline Vector3& Vector3::operator-=( const Vector3& v )
{
	x -= v.x; y -= v.y; z -= v.z;
	return *this;
}

inline Vector3& Vector3::operator*=( const Matrix4& m )
{
	magicalVector3MulMatrix4( this, this, &m );
	return *this;
}

inline Vector3& Vector3::operator*=( float a )
{
	x *= a; y *= a; z *= a;
	return *this;
}

inline Vector3& Vector3::operator*=( const Vector3& v )
{
	x *= v.x; y *= v.y; z *= v.z;
	return *this;
}

inline Vector3& Vector3::operator/=( float a )
{
	magicalVector3DivScalar( this, this, a );
	return *this;
}

inline Vector3& Vector3::operator/=( const Vector3& v )
{
	magicalVector3Div( this, this, &v );
	return *this;
}

inline Vector3& Vector3::operator=( const Vector3& v )
{
	x = v.x; y = v.y; z = v.z;
	return *this;
}

inline void Vector3::set( const Vector3& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
}

inline void Vector3::setZero( void )
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

inline void Vector3::setOne( void )
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
}

inline void Vector3::setScalars( float x, float y, float z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

inline void Vector3::fromVector2( const Vector2& v )
{
	x = v.x;
	y = v.y;
	z = 0.0f;
}

inline void Vector3::fromVector4( const Vector4& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
}

inline void Vector3::clamp( const Vector3& min, const Vector3& max )
{
	magicalVector3Clamp( this, this, &min, &max );
}

inline void Vector3::negate( void )
{
	magicalVector3Negate( this, this );
}

inline void Vector3::normalize( void )
{
	magicalVector3Normalize( this, this );
}

inline void Vector3::scale( float s )
{
	magicalVector3Scale( this, this, s );
}

inline Vector3 Vector3::getClamped( const Vector3& min, const Vector3& max ) const
{
	Vector3 ret;
	magicalVector3Clamp( &ret, this, &min, &max );
	return ret;
}

inline Vector3 Vector3::getNegated( void ) const
{
	Vector3 ret;
	magicalVector3Negate( &ret, this );
	return ret;
}

inline Vector3 Vector3::getNormalized( void ) const
{
	Vector3 ret;
	magicalVector3Normalize( &ret, this );
	return ret;
}

inline Vector3 Vector3::getScaled( float s ) const
{
	Vector3 ret;
	magicalVector3Scale( &ret, this, s );
	return ret;
}

inline float Vector3::dot( const Vector3& v ) const
{
	return magicalVector3Dot( this, &v );
}

inline float Vector3::distanceBetween( const Vector3& v ) const
{
	return magicalVector3DistanceBetween( this, &v );
}

inline float Vector3::distanceBetweenSq( const Vector3& v ) const
{
	return magicalVector3DistanceBetweenSq( this, &v );
}

inline float Vector3::length( void ) const
{
	return magicalVector3Length( this );
}

inline float Vector3::lengthSq( void ) const
{
	return magicalVector3LengthSq( this );
}

inline float Vector3::angleBetween( const Vector3& v ) const
{
	return magicalVector3AngleBetween( this, &v );
}

inline Vector3 Vector3::cross( const Vector3& v ) const
{
	Vector3 ret;
	magicalVector3Cross( &ret, this, &v );
	return ret;
}

inline Vector3 Vector3::midPointBetween( const Vector3& v ) const
{
	Vector3 ret;
	magicalVector3MidPointBetween( &ret, this, &v );
	return ret;
}

inline Vector3 Vector3::project( const Vector3& n ) const
{
	Vector3 ret;
	magicalVector3Project( &ret, this, ( &n ) );
	return ret;
}

NS_MAGICAL_END