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

NAMESPACE_MAGICAL

class Entity;
class ViewChannel;

enum : int
{
	kCameraClean = 0x00,
	kCameraViewDirty = 0x01,
	kCameraProjectionDirty = 0x02,
	kCameraViewProjectionDirty = 0x04,
};

enum class Projection : int
{
	Orth,
	Perspective
};

class Camera : public Entity
{
public:
	enum : int { Feature = 20 };

public:
	Camera( void );
	virtual ~Camera( void );
	static Ptr<Camera> create( void );
	static Ptr<Camera> create( const char* name );

public:
	bool isActive( void ) const { return m_active; }
	bool isFrustumCullEnabled( void ) { return m_frustum_cull_enabled; }
	virtual void setActive( bool active );
	virtual void setVisible( bool visible ) override;
	
public:
	void bindViewChannel( int index );
	unsigned int getBoundViewChannelIndex( void ) const { return m_view_channel_index; }

public:
	void setOrthWindow( float width, float height );
	void setOrth( float left, float right, float bottom, float top, float znear, float zfar );
	void setFieldOfView( float fov );
	void setAutoAspectRatio( bool auto_aspect_ratio );
	void setAspectRatio( float aspect );
	void setNearClipDistance( float znear );
	void setFarClipDistance( float zfar );
	void setPerspective( float fov, float aspect, float znear, float zfar );

	float getOrthWindowWidth( void ) const { return m_right - m_left; }
	float getOrthWindowHeight( void ) const { return m_top - m_bottom; }
	float getFieldOfView( void ) const { return m_fov; }
	bool isAutoAspectRatio( void ) const { return m_auto_aspect_ratio; }
	float getAspectRatio( void ) const { return m_aspect; }
	float getNearClipDistance( void ) const { return m_znear; }
	float getFarClipDistance( void ) const { return m_zfar; }
	
public:
	//virtual void start( void ) override;
	//virtual void stop( void ) override;
	virtual void transform( void ) override;

public:
	virtual void transformDirty( int info ) override;
	const Matrix4x4& getViewMatrix( void ) const;
	const Matrix4x4& getProjectionMatrix( void ) const;
	const Matrix4x4& getViewProjectionMatrix( void ) const;

protected:
	float m_left = 0.0f;
	float m_right = 0.0f;
	float m_bottom = 0.0f;
	float m_top = 0.0f;
	float m_fov = 60.0f;
	float m_aspect = 1.3333f;
	float m_znear = 0.3f;
	float m_zfar = 1000.0f;

protected:
	unsigned int m_view_channel_index = ViewChannel::None;
	bool m_active = true;
	bool m_frustum_cull_enabled = true;
	bool m_auto_aspect_ratio = true;
	mutable int m_camera_dirty_info = kCameraClean;
	Frustum m_frustum = Frustum::Invalid;
	mutable Matrix4x4 m_view_matrix = Matrix4x4::Identity;
	mutable Matrix4x4 m_projection_matrix = Matrix4x4::Identity;
	mutable Matrix4x4 m_view_projection_matrix = Matrix4x4::Identity;
	Projection m_projection = Projection::Perspective;
};

NAMESPACE_END

#endif //__CAMERA_H__