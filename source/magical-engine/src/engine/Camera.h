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
#include "SceneElement.h"
#include "SceneObject.h"

NS_MAGICAL_BEGIN

class Camera : public SceneObject
{
public:
	declare_class_hash_code;

public:
	Camera( void );
	virtual ~Camera( void );
	static Ptr<Camera> create( void );
	static Ptr<Camera> create( const char* name );

public:
	void setPerspective( float fov, float aspect, float znear, float zfar );
	const Matrix4& getProjectionMatrix( void ) const;

protected:
	bool m_is_active = false;
	Matrix4 m_projection_matrix;
};

NS_MAGICAL_END



#endif //__CAMERA_H__