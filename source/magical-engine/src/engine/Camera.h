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
#include "ViewChannel.h"

NS_MAGICAL_BEGIN

class Entity;
class ViewChannel;

enum class Projection : int
{
	Orth,
	Perspective
};

enum : int
{
	kCameraClean = 0x00,
	kCameraViewDirty = 0x01,
	kCameraProjectionDirty = 0x02,
	kCameraViewProjectionDirty = 0x04,
};

class Camera : public Entity
{
public:
	friend class ViewChannel;
	declare_class_hash_code;
	
public:
	Camera( void );
	virtual ~Camera( void );
	static Ptr<Camera> create( void );
	static Ptr<Camera> create( const char* name );

public:
	virtual void setVisible( bool visible ) override;
	void setActive( bool active );
	bool isActive( void ) const { return m_active; }
	void bindViewChannel( ViewChannel::Index index );
	ViewChannel::Index getBoundViewChannelIndex( void ) const { return m_view_channel_index; }

public:
	void setOrthWindow( float width, float height );
	float getOrthWindowWidth( void ) const { return m_right - m_left; }
	float getOrthWindowHeight( void ) const { return m_top - m_bottom; }
	void setOrth( float left, float right, float bottom, float top, float znear, float zfar );
	void setFieldOfView( float fov );
	float getFieldOfView( void ) const { return m_fov; }
	void setAutoAspectRatio( bool auto_aspect_ratio );
	bool isAutoAspectRatio( void ) const { return m_auto_aspect_ratio; }
	void setAspectRatio( float aspect );
	float getAspectRatio( void ) const { return m_aspect; }
	void setNearClipDistance( float znear );
	float getNearClipDistance( void ) const { return m_znear; }
	void setFarClipDistance( float zfar );
	float getFarClipDistance( void ) const { return m_zfar; }
	void setPerspective( float fov, float aspect, float znear, float zfar );

public:
	const Matrix4& getViewMatrix( void ) const;
	const Matrix4& getProjectionMatrix( void ) const;
	const Matrix4& getViewProjectionMatrix( void ) const;
	virtual void transform( void ) override;
	virtual void transformDirty( int info ) override;

protected:
	bool m_active = true;
	bool m_frustum_cull_enabled = true;
	Projection m_projection = Projection::Perspective;
	ViewChannel::Index m_view_channel_index;

protected:
	float m_left = 0.0f;
	float m_right = 0.0f;
	float m_bottom = 0.0f;
	float m_top = 0.0f;
	float m_fov = 60.0f;
	float m_aspect = 1.3333f;
	float m_znear = 0.3f;
	float m_zfar = 1000.0f;
	bool m_auto_aspect_ratio = true;
	mutable int m_camera_dirty_info;
	mutable Matrix4 m_view_matrix;
	mutable Matrix4 m_projection_matrix;
	mutable Matrix4 m_view_projection_matrix;
	Frustum m_frustum;
};

NS_MAGICAL_END

#endif //__CAMERA_H__