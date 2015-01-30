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
#include "SceneElement.h"
#include "SceneNode.h"
#include "Camera.h"

#include <vector>
#include <unordered_set>
#include <unordered_map>

NS_MAGICAL_BEGIN

using ::std::string;
using ::std::unordered_set;

class Scene : protected SceneNode
{
public:
	declare_class_hash_code;

public:
	Scene( void );
	virtual ~Scene( void );
	static Ptr<Scene> create( void );

//public:
//	void setActiveCamera( const Ptr<Camera>& camera );

public:
	using SceneNode::addChild;
	using SceneNode::removeChild;
	using SceneNode::removeAllChildren;

protected:
	void destory( SceneNode* child );
	virtual void onNodeEvent( NodeEvent evt, SceneNode* child );
	virtual void onNodeEvent( NodeEvent evt, vector<SceneNode*> children );

protected:
	void addSceneNode( SceneNode* node );
	void addCamera( Camera* camera );
	void removeSceneNode( SceneNode* node );
	void removeCamera( Camera* camera );

protected:
	//Camera* m_active_camera = nullptr;
	unordered_set<SceneNode*> m_scene_nodes;
	unordered_set<Camera*> m_cameras;
	
};

NS_MAGICAL_END

#endif //__SCENE_H__