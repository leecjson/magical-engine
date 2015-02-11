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

enum
{
	kTsScaleDirty
};

define_class_hash_code( Camera );

Camera::Camera( void )
{
	assign_class_hash_code();
	m_element_id = SceneElement::Camera;
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

NS_MAGICAL_END