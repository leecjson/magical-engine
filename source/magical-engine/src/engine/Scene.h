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
#ifndef __SCENE_H__
#define __SCENE_H__

#include "PlatformMacros.h"
#include "Common.h"
#include "Reference.h"
#include "Camera.h"
#include "SceneObject.h"

#include <unordered_map>

NS_MAGICAL_BEGIN

class Scene : public Reference
{
public:
	Scene( void );
	virtual ~Scene( void );

public:
	static Ptr<Scene> create( void );

public:
	Camera* createCamera( const char* name = "" );
	SceneObject* createSceneObject( const char* name = "" );

public:
	void visit( void );

protected:
	typedef std::vector< Camera* > CameraList;
	typedef std::vector< SceneObject* > SceneObjectList;

protected:
	CameraList camera_list_;
	SceneObjectList scene_object_list_;

};

NS_MAGICAL_END

#endif //__SCENE_H__