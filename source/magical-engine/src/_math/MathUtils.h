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
#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <math.h>
#include <float.h>

#ifndef MAGICAL_DEBUG
#define debugassert( con, msg )
#else
#include <assert.h>
#define debugassert( con, msg )    \
	do { if( !( con ) ) {          \
		assert( ( con ) && msg );  \
	} } while( 0 )
#endif

class Math
{
public:
	static const float PI;
	static const float PIMul2;
	static const float PIDiv2;
	static const float PIDiv180;
	static const float N1DivPI;
	static const float N1Div2PI;
	static const float N180DivPI;

public:
	static const float NumberEpsilon;
	static const float QuaternionEpsilon;
	static const float VectorEpsilon;
	static const float RadianEpsilon;
	static const float DegreeEpsilon;

public:
	/**
	 * 弧度转为角度
	 *
	 * @radian 弧度参数
	 * @return 转换后的角度
	 */
	static inline float deg( float radian )
	{
		return radian * N180DivPI;
	}

	/**
	 * 弧度转为角度
	 *
	 * @radian 弧度参数
	 * @return 转换后的角度
	 */
	static inline double deg( double radian )
	{
		return radian * N180DivPI;
	}
	
	/**
	 * 角度转换为弧度
	 *
	 * @radian 角度参数
	 * @return 转换后的弧度
	 */
	static inline float rad( float degree )
	{
		return degree * PIDiv180;
	}

	/**
	 * 角度转换为弧度
	 *
	 * @radian 角度参数
	 * @return 转换后的弧度
	 */
	static inline double rad( double degree )
	{
		return degree * PIDiv180;
	}

	/**
	 * 数值开平方根
	 *
	 * @a 数值
	 * @return
	 */
	static inline float sqrt( float a )
	{
		return ::sqrtf( a );
	}

	/**
	 * 数值开平方根
	 *
	 * @a 数值
	 * @return
	 */
	static inline double sqrt( double a )
	{
		return ::sqrt( a );
	}

	/**
	 * 余弦函数
	 *
	 * @radian 弧度值
	 * @return 对应余弦值
	 */
	static inline float cos( float radian )
	{
		return ::cosf( radian );
	}

	/**
	 * 余弦函数
	 *
	 * @radian 弧度值
	 * @return 对应余弦值
	 */
	static inline double cos( double radian )
	{
		return ::cos( radian );
	}

	/**
	 * 正弦函数
	 *
	 * @radian 弧度值
	 * @return 对应正弦值
	 */
	static inline float sin( float radian )
	{
		return ::sinf( radian );	
	}

	/**
	 * 正弦函数
	 *
	 * @radian 弧度值
	 * @return 对应正弦值
	 */
	static inline double sin( double radian )
	{
		return ::sin( radian );
	}

	/**
	 * 反余弦函数
	 *
	 * @cos 余弦值
	 * @return 对应弧度值
	 */
	static inline float acos( float cos )
	{
		return ::acosf( cos );
	}

	/**
	 * 反余弦函数
	 *
	 * @cos 余弦值
	 * @return 对应弧度值
	 */
	static inline double acos( double cos )
	{
		return ::acos( cos );
	}

	/**
	 * 反正弦函数
	 *
	 * @sin 正弦值
	 * @return 对应弧度值
	 */
	static inline float asin( float sin )
	{
		return ::asinf( sin );
	}

	/**
	 * 反正弦函数
	 *
	 * @sin 正弦值
	 * @return 对应弧度值
	 */
	static inline double asin( double a )
	{
		return ::asin( a );
	}

	/**
	 * 安全的反余弦函数，限制余弦值从-1.0到+1.0之间
	 *
	 * @cos 余弦值
	 * @return 对应弧度值
	 */
	static inline float safeAcos( float cos )
	{
		if( cos <= -1.0f )
			return PI;

		if( cos >= +1.0f )
			return 0.0f;

		return ::acosf( cos );
	}

	/**
	 * 安全的反余弦函数，限制余弦值从-1.0到+1.0之间
	 *
	 * @cos 余弦值
	 * @return 对应弧度值
	 */
	static inline double safeAcos( double cos )
	{
		if( cos <= -1.0 ) 
			return PI;

		if( cos >= +1.0 ) 
			return 0.0; 

		return ::acos( cos );
	}

	/**
	 * 对弧度值模PI运算，变化到-PI到PI之间
	 *
	 * @radian 弧度值
	 * @return 变化后的弧度
	 */
	static inline float toPI( float radian )
	{
		radian += PI;
		radian -= ::floorf( radian * N1Div2PI ) * PIMul2;
		radian -= PI;
		return radian;
	}
	
	/**
	 * 对弧度值模PI运算，变化到-PI到PI之间
	 *
	 * @radian 弧度值
	 * @return 变化后的弧度
	 */
	static inline double toPI( double radian )
	{
		radian += PI;
		radian -= ::floor( radian * N1Div2PI ) * PIMul2;
		radian -= PI;
		return radian;
	}

	/**
	 * 同时计算正弦与余弦，在某些平台上更有效率
	 *
	 * @sin 输出的正弦参数
	 * @cos 输出的余弦参数
	 * @radian 弧度值
	 */
	static inline void sinCos( float& sin, float& cos, float radian )
	{
		sin = ::sinf( radian );
		cos = ::cosf( radian );
	}

	/**
	 * 同时计算正弦与余弦，在某些平台上更有效率
	 *
	 * @sin 输出的正弦参数
	 * @cos 输出的余弦参数
	 * @radian 弧度值
	 */
	static inline void sinCos( double& sin, double& cos, double radian )
	{
		sin = ::sin( radian ); 
		cos = ::cos( radian );
	}

	/**
	 * 返回两个值更大的那一个
     *
	 * @return 较大的值
	 */
	template<class T> static inline const T& max( const T& a, const T& b )
	{
		return a > b ? a : b;
	}

	/**
	 * 返回两个值更小的那一个
	 *
	 * @return 较小的值
	 */
	template<class T> static inline const T& min( const T& a, const T& b )
	{
		return a < b ? a : b;
	}
	
	/**
	 * 判断浮点数值是否接近于0
	 * 
	 * @a 浮点数
	 * @e 指定的浮点最小间隔
	 * @return 是否接近于0
	 */
	static inline bool isAlmostZero( float a, float e = NumberEpsilon )
	{
		return ::fabsf( a ) < e;
	}

	/**
	 * 判断浮点数值是否接近于0
	 * 
	 * @a 浮点数
	 * @e 指定的浮点最小间隔
	 * @return 是否接近于0
	 */
	static inline bool isAlmostZero( double a, double e = NumberEpsilon )
	{
		return ::fabs( a ) < e;
	}

	/**
	 * 判断浮点数值是否接近于相等
	 * 
	 * @a 浮点数1
	 * @b 浮点数2
	 * @e 指定的浮点最小间隔
	 * @return 是否相等
	 */
	static inline bool isAlmostEqual( float a, float b, float e = NumberEpsilon )
	{
		return ::fabsf( a - b ) < e;
	}

	/**
	 * 判断浮点数值是否接近于相等
	 * 
	 * @a 浮点数1
	 * @b 浮点数2
	 * @e 指定的浮点最小间隔
	 * @return 是否相等
	 */
	static inline bool isAlmostEqual( double a, double b, double e = NumberEpsilon )
	{
		return ::fabs( a - b ) < e;
	}
};

//#define RAD( a ) ( (a) * kPIOver180 )
//#define DEG( a ) ( (a) * k180OverPI )
//
//#if defined MAGICAL_ENGINE
//#ifndef MAGICAL_MATH_CACHED_POOL_ENABLE
//#define MAGICAL_MATH_CACHED_POOL_ENABLE 1
//#endif
//#else
//#ifndef MAGICAL_MATH_CACHED_POOL_ENABLE
//#define MAGICAL_MATH_CACHED_POOL_ENABLE 0
//#endif
//#endif
//
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//#define math_cached_pool_declare_operator_new_and_delete \
//	static void* operator new( size_t size );            \
//	static void  operator delete( void* ptr );
//#else
//#define math_cached_pool_declare_operator_new_and_delete
//#endif
//
//#if MAGICAL_MATH_CACHED_POOL_ENABLE
//#define math_cached_pool_define_operator_new_and_delete( cls, var, num ) \
//	static CachePool<cls> var( num, num );                               \
//	void* cls::operator new( size_t size ) {                             \
//		if( size != sizeof( cls ) ) return ::operator new( size );       \
//		return var.take();                                               \
//	}                                                                    \
//	void cls::operator delete( void* ptr ) {                             \
//		if( ptr == nullptr ) return; var.push( ptr );                    \
//	}
//#else
//#define math_cached_pool_define_operator_new_and_delete( cls, var, num )
//#endif
	
#endif //__UTILITY_H__