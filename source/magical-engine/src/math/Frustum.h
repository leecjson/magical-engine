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
#ifndef __FRUSTUM_H__
#define __FRUSTUM_H__

struct Frustum
{
	union
	{
		struct {
			Plane left;
			Plane right;
			Plane top;
			Plane bottom;
			Plane near;
			Plane far;
		};
	};

public:
	static const Frustum Invalid;

public:
	inline Frustum( const Plane& left, const Plane& right, const Plane& top, const Plane& bottom, const Plane& near, const Plane& far );
	inline Frustum( const Frustum& frustum );
	inline Frustum( const Matrix4x4& m );
	inline Frustum( void );

public:
	inline bool isValid( void ) const;

public:
	void extract( const Matrix4x4& m );
	bool containsBox( const Box& box ) const;
};

#endif //__FRUSTUM_H__