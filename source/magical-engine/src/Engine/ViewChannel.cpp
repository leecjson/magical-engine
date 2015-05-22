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

NAMESPACE_MAGICAL

ViewChannel::ViewChannel( void )
{

}

ViewChannel::~ViewChannel( void )
{
	SAFE_RELEASE( m_camera );
}

void ViewChannel::setArea( float x, float y, float w, float h )
{
	m_area.x = x;
	m_area.y = y;
	m_area.w = w;
	m_area.h = h;

	MAGICAL_ASSERT( m_area.isValid(), "Invalid!" );
}

void ViewChannel::setArea( const Area& area )
{
	MAGICAL_ASSERT( area.isValid(), "Invalid!" );

	m_area = area;
}

void ViewChannel::setEnabled( bool enabled )
{
	m_enabled = enabled;
}

void ViewChannel::setCamera( Camera* camera )
{
	SAFE_ASSIGN( m_camera, camera );
}

void ViewChannel::removeCamera( void )
{
	SAFE_RELEASE_NULL( m_camera );
}

NAMESPACE_END