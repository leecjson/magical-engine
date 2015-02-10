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

#include "magical-macros.h"
#include "Common.h"
#include "Reference.h"
#include "SceneElement.h"
#include "SceneNode.h"
#include "SceneObject.h"
#include "Camera.h"

#include <vector>
#include <unordered_set>
#include <unordered_map>

NS_MAGICAL_BEGIN

using ::std::string;
using ::std::unordered_set;

class Scene : public SceneNode
{
public:
	friend class Engine;
	declare_class_hash_code;

public:
	Scene( void );
	virtual ~Scene( void );
	static Ptr<Scene> create( void );

protected:
	virtual void update( void );
	
protected:
	virtual void childEvent( NodeEvent evt, SceneNode* child );
	virtual void childEvent( NodeEvent evt, const Children& children );
	void addCamera( Camera* camera );
	void removeCamera( Camera* camera );
	void addSceneObject( SceneObject* object );
	void removeSceneObject( SceneObject* object );
	
protected:
	unordered_set<SceneObject*> m_scene_objects;
	unordered_set<Camera*> m_cameras;

	unordered_set<SceneObject*> m_update_queue;
};

NS_MAGICAL_END

#endif //__SCENE_H__