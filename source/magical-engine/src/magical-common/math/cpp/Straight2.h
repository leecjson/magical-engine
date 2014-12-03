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
#ifndef __STRAIGHT2_H__
#define __STRAIGHT2_H__

class Vec2;

enum class Straight2Classification
{
	InFrontOfStraight = 1,
	OnStraight = 0,
	BehindStraight = -1
};

class Straight2
{
public:
	float x;
	float y;
	float d;

public:
	Straight2( const float x, const float y, const float d );
	Straight2( const Straight2& st );
	Straight2( void );

public:
	static inline Straight2 fromNormalAndDistance( const Vec2& n, const float d );
	static inline Straight2 fromPointAndNormal( const Vec2& a, const Vec2& n );

public:
	static void* operator new( size_t s );
	static void operator delete( void* ptr );
	inline bool operator==( const Straight2& st ) const;
	inline bool operator!=( const Straight2& st ) const;
	inline Straight2& operator=( const Straight2& st );

public:
	inline bool isEquals( const Straight2& st ) const;
	inline void fill( const float x, const float y, const float d );
	inline void fill( const Straight2& st );
	inline void fillNormalAndDistance( const Vec2& n, const float d );
	inline void fillPointAndNormal( const Vec2& a, const Vec2& n );

	inline Straight2Classification classifyPoint( const Vec2& point ) const;
	inline bool intersects( const Straight2& st ) const;
	inline bool containsPoint( const Straight2& st ) const;
};

#include "../c/cStraight2.h"
#include "Vec2.h"
#include "Straight2.inl"

#endif //__STRAIGHT2_H__