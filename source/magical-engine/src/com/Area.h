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
#ifndef __AREA_H__
#define __AREA_H__

#include "magical-macros.h"
#include "magical-math.h"
#include "Size.h"

NAMESPACE_MAGICAL



struct Area
{
	union
	{
		struct {
			float x;
			float y;
			float w;
			float h;
		};
		struct {
			Vector2 origin;
			Size size;
		};
	};
	
public:
	static const Area Invalid;

public:
	inline Area( const Vector2& origin, const Size& size ) : origin( origin ), size( size ) { }
	inline Area( float x, float y, float w, float h ) : x ( x ), y( y ), w( w ), h( h ) { }
	inline Area( const Area& area ) : x( area.x ), y( area.y ), w( area.w ), h( area.h ) { }
	inline Area( void ) { }

public:
	inline bool isValid( void ) const
	{
		return w > Math::VectorEpsilon && h > Math::VectorEpsilon;
	}
};

NAMESPACE_END

#endif //__AREA_H__