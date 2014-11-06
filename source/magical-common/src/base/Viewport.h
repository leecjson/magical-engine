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
#ifndef __VIEWPORT_H__
#define __VIEWPORT_H__

#include "PlatformMacros.h"
#include "Common.h"
#include "Reference.h"

class Viewport : public Reference
{
public:
	Viewport( void );
	virtual ~Viewport( void );

public:
	static Shared<Viewport> create( void );
	
public:
	void set( int x, int y, int width, int height );
	void setX( int x );
	void setY( int y );
	void setWidth( int width );
	void setHeight( int height );
	int getX( void ) const;
	int getY( void ) const;
	int getWidth( void ) const;
	int getHeight( void ) const;

private:
	int _x = 0;
	int _y = 0;
	int _width = 0;
	int _height = 0;
};



#endif //__VIEWPORT_H__