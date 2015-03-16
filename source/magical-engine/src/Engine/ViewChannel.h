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

NS_MAGICAL_BEGIN

class Camera;

class ViewChannel : public Reference
{
public:
	enum Index : int 
	{
		C0 = 0,
		C1 = 1,
		C2 = 2,
		C3 = 3,
		C4 = 4,
		Count,
		Default = C0,
	};

public:
	ViewChannel( void );
	virtual ~ViewChannel( void );

public:
	void setViewRect( float x, float y, float w, float h );
	void setViewRect( const Rect& rect );
	const Rect& getViewRect( void ) const { return m_view_rect; }
	void setEnabled( bool enabled );
	bool isEnabled( void ) const { return m_enabled; }
	Camera* getCamera( void ) const { return m_camera; }
	void removeCamera( void );
	bool isDrawable( void ) const { return isEnabled() && m_camera; }

public:
	void setCamera( const Ptr<Camera>& camera );

protected:
	Rect m_view_rect = Rect( 0.0f, 0.0f, 1.0f, 1.0f );
	bool m_enabled = false;
	Camera* m_camera = nullptr;
};

//typedef ViewChannel::Index ViewChannelIndex;

NS_MAGICAL_END

#endif //__VIEW_CHANNEL_H__