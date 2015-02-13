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
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "magical-macros.h"
#include "Common.h"
#include "Entity.h"

NS_MAGICAL_BEGIN

enum class Projection
{
	None,
	Orth,
	Perspective
};

class Camera : public Entity
{
public:
	declare_class_hash_code;

public:
	Camera( void );
	virtual ~Camera( void );
	static Ptr<Camera> create( void );
	static Ptr<Camera> create( const char* name );

public:
	virtual void setVisible( bool visible ) override;
	void setActive( bool active, bool others_inactive = true );
	bool isActived( void ) const { return m_is_active; }

public:
	void setOrth( float left, float right, float bottom, float top, float znear, float zfar );
	void setPerspective( float fov, float aspect, float znear, float zfar );

	const Matrix4& getViewMatrix( void ) const;
	const Matrix4& getProjectionMatrix( void ) const;

public:
	virtual void transform( void );

protected:
	bool m_is_active = false;
	bool m_is_frustum_cull_enalbed = true;

	float m_left = 0.0f;
	float m_right = 0.0f;
	float m_bottom = 0.0f;
	float m_top = 0.0f;
	float m_fov = 60.0f;
	float m_aspect = 0.0f;
	float m_znear = 0.3f;
	float m_zfar = 1000.0f;
	
	Matrix4 m_view_matrix;
	Matrix4 m_projection_matrix;
	Matrix4 m_view_projection_matrix;
	Frustum m_frustum;
	Projection m_projection = Projection::Perspective;

public:
	void setViewport( int x, int y, int w, int h );
	void setViewport( const Rect& rect );

protected:
	int m_viewport_zorder = 0;
	int m_viewport_x = 0.0f;
	int m_viewport_y = 0.0f;
	int m_viewport_w = 0.0f;
	int m_viewport_h = 0.0f;
};

NS_MAGICAL_END

#endif //__CAMERA_H__