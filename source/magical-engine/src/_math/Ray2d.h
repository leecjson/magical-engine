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
#ifndef __RAY2D_H__
#define __RAY2D_H__

struct Ray2d
{
	union
	{
		struct {
			float ox;
			float oy;
			float dx;
			float dy;
		};
		struct {
			Vector2 origin;
			Vector2 direction;
		};
	};

public:
	static const Ray2d Invalid;

public:
	inline Ray2d( const Vector2& origin, const Vector2& direction );
	inline Ray2d( const Ray2d& ray );
	inline Ray2d( void );

public:
	inline bool operator==( const Ray2d& ray ) const;
	inline bool operator!=( const Ray2d& ray ) const;
	inline Ray2d& operator=( const Ray2d& ray );

public:
	inline bool equals( const Ray2d& ray ) const;
	inline bool isValid( void ) const;
	inline void set( const Vector2& origin, const Vector2& direction );
	inline void set( const Ray2d& ray );
	inline void setOriginToEnd( const Vector2& origin, const Vector2& end );
	static inline Ray2d createOriginToEnd( const Vector2& origin, const Vector2& end );
};

#endif //__RAY2D_H__
