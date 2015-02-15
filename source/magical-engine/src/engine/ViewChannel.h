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
#ifndef __VIEW_CHANNEL_H__
#define __VIEW_CHANNEL_H__

#include "magical-macros.h"
#include "Common.h"
#include "Reference.h"
#include "Camera.h"

NS_MAGICAL_BEGIN

class ViewChannel : public Reference
{
public:
	declare_class_hash_code;
	enum Instance {
		C0 = 0,
		Default = C0,
		C1 = 1,
		C2 = 2,
		C3 = 3,
		C4 = 4,
		Count,
		All = Count,
	};

public:
	ViewChannel( void );
	virtual ~ViewChannel( void );
	static Ptr<ViewChannel> create( void );
	static Ptr<ViewChannel> create( float x, float y, float w, float h );

public:
	void setVisible( bool visible );
	bool isVisible( void ) const;
	void setActiveCamera( const Ptr<Camera>& camera );
	Camera* getActiveCamera( void ) const { return m_camera; }
	void removeActiveCamera( void );

public:
	void set( float x, float y, float w, float h );

protected:
	bool m_is_visible = false;
	Camera* m_camera = nullptr;
	float x = 0.0f;
	float y = 0.0f;
	float h = 0.0f;
	float w = 0.0f;
};

NS_MAGICAL_END

#endif //__VIEW_CHANNEL_H__