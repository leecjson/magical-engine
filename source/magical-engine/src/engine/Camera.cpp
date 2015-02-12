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
#include "Camera.h"

NS_MAGICAL_BEGIN

define_class_hash_code( Camera );

Camera::Camera( void )
{
	assign_class_hash_code();
	m_element_enum = Element::Camera;
}

Camera::~Camera( void )
{

}

Ptr<Camera> Camera::create( void )
{
	Camera* ret = new Camera();
	magicalAssert( ret, "new Camera() failed" );
	return Ptr<Camera>( Initializer<Camera>( ret ) );
}

Ptr<Camera> Camera::create( const char* name )
{
	Camera* ret = new Camera();
	magicalAssert( ret, "new Camera() failed" );
	ret->setName( name );
	return Ptr<Camera>( Initializer<Camera>( ret ) );
}

void Camera::setActive( bool active, bool others_inactive )
{
	if( m_is_active == active )
}

void Camera::setOrth( float left, float right, float bottom, float top, float znear, float zfar )
{
	m_left = left;
	m_right = right;
	m_bottom = bottom;
	m_top = top;
	m_znear = znear;
	m_zfar = zfar;

	m_projection = Projection::Orth;

	//m_projection_matrix.setOrth( left, right, bottom, top, znear, zfar );
}

void Camera::setPerspective( float fov, float aspect, float znear, float zfar )
{
	m_fov = fov;
	m_aspect = aspect;
	m_znear = znear;
	m_zfar = zfar;

	m_projection = Projection::Perspective;

	//m_projection_matrix.setPerspective( fov, aspect, znear, zfar );
}

const Matrix4& Camera::getViewMatrix( void ) const
{
	return Matrix4();
}

const Matrix4& Camera::getProjectionMatrix( void ) const
{
	return m_projection_matrix;
}

void Camera::transform( void )
{
	if( !m_is_visible )
		return;

	int info = m_ts_dirty_info;

	if( m_ts_dirty != kTsClean )
	{
		const Quaternion& r = getDerivedRotation();
		const Vector3& s = getDerivedScale();
		const Vector3& t = getDerivedPosition();

		m_local_to_world_matrix.setTRS( t, r, s );
		m_ts_dirty = false;
	}

	if( !m_children.empty() )
	{
		for( auto child : m_children )
		{
			if( info != kTsClean )
				child->transformDirty( info );

			child->transform();
		}
	}
}

void Camera::setViewport( int x, int y, int w, int h )
{
	m_viewport_x = x;
	m_viewport_y = y;
	m_viewport_w = w;
	m_viewport_h = h;
}

void Camera::setViewport( const Rect& rect )
{
	m_viewport_x = rect.x;
	m_viewport_y = rect.y;
	m_viewport_w = rect.w;
	m_viewport_h = rect.h;
}

NS_MAGICAL_END