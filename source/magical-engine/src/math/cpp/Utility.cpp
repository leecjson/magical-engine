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
#include "Utility.h"
//
//#include "c/cAABB.h"
//#include "c/cAxisAngle.h"
//#include "c/cEulerAngles.h"
//#include "c/cFrustum.h"
//#include "c/cLine2.h"
//#include "c/cMatrix3.h"
//#include "c/cMatrix4.h"
//#include "c/cOBB.h"
//#include "c/cPlane.h"
//#include "c/cQuaternion.h"
//#include "c/cRay2.h"
//#include "c/cRay3.h"
//#include "c/cRect.h"
//#include "c/cSphere.h"
//#include "c/cVector2.h"
//#include "c/cVector3.h"
//#include "c/cVector4.h"
//
//#include "AxisAngle.h"
//#include "EulerAngles.h"
//#include "Matrix3.h"
//#include "Matrix4.h"
//#include "Quaternion.h"
//#include "Vector2.h"
//#include "Vector3.h"
//#include "Vector4.h"
//
//#include "AxisAngle.inl"
//#include "EulerAngles.inl"
//#include "Matrix3.inl"
//#include "Matrix4.inl"
//#include "Quaternion.inl"
//#include "Vector2.inl"
//#include "Vector3.inl"
//#include "Vector4.inl"
//
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//#include "CachePool.h"
//#endif
//
//NS_MAGICAL_BEGIN
//
//const AxisAngle AxisAngle::Identity = AxisAngle( 0.0f, 0.0f, 1.0f, 0.0f );
//const AxisAngle AxisAngle::Zero = AxisAngle( 0.0f, 0.0f, 0.0f, 0.0f );
//AxisAngle AxisAngle::var = AxisAngle::Identity;
//
//const EulerAngles EulerAngles::Zero = EulerAngles( 0.0f, 0.0f, 0.0f );
//EulerAngles EulerAngles::var = EulerAngles::Zero;
//
//const Matrix3 Matrix3::Identity = Matrix3(
//	1.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, 1.0f );
//const Matrix3 Matrix3::Zero = Matrix3(
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f );
//Matrix3 Matrix3::var = Matrix3::Identity;
//
//const Matrix4 Matrix4::Identity = Matrix4(
//	1.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 1.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 1.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 1.0f );
//const Matrix4 Matrix4::Zero = Matrix4(
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f,
//	0.0f, 0.0f, 0.0f, 0.0f );
//Matrix4 Matrix4::var = Matrix4::Identity;
//
//const Quaternion Quaternion::Identity = Quaternion( 0.0f, 0.0f, 0.0f, 1.0f );
//const Quaternion Quaternion::Zero = Quaternion( 0.0f, 0.0f, 0.0f, 0.0f );
//Quaternion Quaternion::var = Quaternion::Identity;
//
//const Vector2 Vector2::Zero = Vector2( 0.0f, 0.0f );
//const Vector2 Vector2::One = Vector2( 1.0f, 1.0f );
//const Vector2 Vector2::Right = Vector2( 1.0f, 0.0f );
//const Vector2 Vector2::Left = Vector2( -1.0f, 0.0f );
//const Vector2 Vector2::Up = Vector2( 0.0f, 1.0f );
//const Vector2 Vector2::Down = Vector2( 0.0f, -1.0f );
//Vector2 Vector2::var = Vector2::Zero;
//
//const Vector3 Vector3::Zero = Vector3( 0.0f, 0.0f, 0.0f );
//const Vector3 Vector3::One = Vector3( 1.0f, 1.0f, 1.0f );
//const Vector3 Vector3::Up = Vector3( 0.0f, 1.0f, 0.0f );
//const Vector3 Vector3::Down = Vector3( 0.0f, -1.0f, 0.0f );
//const Vector3 Vector3::Right = Vector3( 1.0f, 0.0f, 0.0f );
//const Vector3 Vector3::Left = Vector3( -1.0f, 0.0f, 0.0f );
//const Vector3 Vector3::Forward = Vector3( 0.0f, 0.0f, 1.0f );
//const Vector3 Vector3::Back = Vector3( 0.0f, 0.0f, -1.0f );
//Vector3 Vector3::var = Vector3::Zero;
//
//const Vector4 Vector4::Zero = Vector4( 0.0f, 0.0f, 0.0f, 0.0f );
//const Vector4 Vector4::One = Vector4( 1.0f, 1.0f, 1.0f, 1.0f );
//const Vector4 Vector4::Up = Vector4( 0.0f, 1.0f, 0.0f, 0.0f );
//const Vector4 Vector4::Down = Vector4( 0.0f, -1.0f, 0.0f, 0.0f );
//const Vector4 Vector4::Right = Vector4( 1.0f, 0.0f, 0.0f, 0.0f );
//const Vector4 Vector4::Left = Vector4( -1.0f, 0.0f, 0.0f, 0.0f );
//const Vector4 Vector4::Forward = Vector4( 0.0f, 0.0f, 1.0f, 0.0f );
//const Vector4 Vector4::Back = Vector4( 0.0f, 0.0f, -1.0f, 0.0f );
//const Vector4 Vector4::Space0 = Vector4( 0.0f, 0.0f, 0.0f, 0.0f );
//const Vector4 Vector4::Space1 = Vector4( 0.0f, 0.0f, 0.0f, 1.0f );
//const Vector4 Vector4::Space2 = Vector4( 0.0f, 0.0f, 0.0f, 2.0f );
//Vector4 Vector4::var = Vector4::Zero;
//
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//static CachePool<AxisAngle> s_axisangle_cache_pool( 32, 32 );
//static CachePool<EulerAngles> s_eulerangles_cache_pool( 64, 64 );
//static CachePool<Matrix3> s_matrix3_cache_pool( 8, 8 );
//static CachePool<Matrix4> s_matrix4_cache_pool( 8, 8 );
//static CachePool<Quaternion> s_quaternion_cache_pool( 64, 64 );
//static CachePool<Vector2> s_vector2_cache_pool( 128, 128 );
//static CachePool<Vector3> s_vector3_cache_pool( 128, 128 );
//static CachePool<Vector4> s_vector4_cache_pool( 32, 32 );
//#endif
//
//void* AxisAngle::operator new( size_t s )
//{
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	if( s != sizeof( AxisAngle ) )
//		return ::operator new( s );
//
//	return s_axisangle_cache_pool.take();
//#else
//	return ::operator new( s );
//#endif
//}
//
//void AxisAngle::operator delete( void* ptr )
//{
//	if( ptr == nullptr )
//		return;
//	
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	s_axisangle_cache_pool.push( ptr );
//#else
//	return ::operator delete( ptr );
//#endif
//}
//
//void* EulerAngles::operator new( size_t s )
//{
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	if( s != sizeof( EulerAngles ) )
//		return ::operator new( s );
//
//	return s_eulerangles_cache_pool.take();
//#else
//	return ::operator new( s );
//#endif
//}
//
//void EulerAngles::operator delete( void* ptr )
//{
//	if( ptr == nullptr )
//		return;
//	
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	s_eulerangles_cache_pool.push( ptr );
//#else
//	return ::operator delete( ptr );
//#endif
//}
//
//void* Matrix3::operator new( size_t s )
//{
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	if( s != sizeof( Matrix3 ) )
//		return ::operator new( s );
//
//	return s_matrix3_cache_pool.take();
//#else
//	return ::operator new( s );
//#endif
//}
//
//void Matrix3::operator delete( void* ptr )
//{
//	if( ptr == nullptr )
//		return;
//
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	s_matrix3_cache_pool.push( ptr );
//#else
//	return ::operator delete( ptr );
//#endif
//}
//
//void* Matrix4::operator new( size_t s )
//{
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	if( s != sizeof( Matrix4 ) )
//		return ::operator new( s );
//
//	return s_matrix4_cache_pool.take();
//#else
//	return ::operator new( s );
//#endif
//}
//
//void Matrix4::operator delete( void* ptr )
//{
//	if( ptr == nullptr )
//		return;
//	
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	s_matrix4_cache_pool.push( ptr );
//#else
//	return ::operator delete( ptr );
//#endif
//}
//
//void* Quaternion::operator new( size_t s )
//{
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	if( s != sizeof( Quaternion ) )
//		return ::operator new( s );
//
//	return s_quaternion_cache_pool.take();
//#else
//	return ::operator new( s );
//#endif
//}
//
//void Quaternion::operator delete( void* ptr )
//{
//	if( ptr == nullptr )
//		return;
//	
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	s_quaternion_cache_pool.push( ptr );
//#else
//	return ::operator delete( ptr );
//#endif
//}
//
//void* Vector2::operator new( size_t s )
//{
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	if( s != sizeof( Vector2 ) )
//		return ::operator new( s );
//
//	return s_vector2_cache_pool.take();
//#else
//	return ::operator new( s );
//#endif
//}
//
//void Vector2::operator delete( void* ptr )
//{
//	if( ptr == nullptr )
//		return;
//	
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	s_vector2_cache_pool.push( ptr );
//#else
//	return ::operator delete( ptr );
//#endif
//}
//
//void* Vector3::operator new( size_t s )
//{
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	if( s != sizeof( Vector3 ) )
//		return ::operator new( s );
//
//	return s_vector3_cache_pool.take();
//#else
//	return ::operator new( s );
//#endif
//}
//
//void Vector3::operator delete( void* ptr )
//{
//	if( ptr == nullptr )
//		return;
//	
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	s_vector3_cache_pool.push( ptr );
//#else
//	return ::operator delete( ptr );
//#endif
//}
//
//void* Vector4::operator new( size_t s )
//{
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	if( s != sizeof( Vector4 ) )
//		return ::operator new( s );
//
//	return s_vector4_cache_pool.take();
//#else
//	return ::operator new( s );
//#endif
//}
//
//void Vector4::operator delete( void* ptr )
//{
//	if( ptr == nullptr )
//		return;
//	
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//	s_vector4_cache_pool.push( ptr );
//#else
//	return ::operator delete( ptr );
//#endif
//}
//
//NS_MAGICAL_END
//
//
//
//
//
//
