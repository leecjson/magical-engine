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
#include "ViewChannel.h"
#include "Camera.h"

NS_MAGICAL_BEGIN

ViewChannel::ViewChannel( void )
{

}

ViewChannel::~ViewChannel( void )
{
	magicalSafeRelease( m_camera );
}

void ViewChannel::setViewRect( float x, float y, float w, float h )
{
	m_view_rect.x = x;
	m_view_rect.y = y;
	m_view_rect.w = w;
	m_view_rect.h = h;
}

void ViewChannel::setViewRect( const Rect& rect )
{
	m_view_rect = rect;
}

void ViewChannel::setEnabled( bool enabled )
{
	m_enabled = enabled;
}

void ViewChannel::removeCamera( void )
{
	magicalSafeReleaseNull( m_camera );
}

void ViewChannel::setCamera( const Ptr<Camera>& camera )
{
	Camera* rcamera = camera.get();
	magicalSafeAssign( m_camera, rcamera );
}

NS_MAGICAL_END