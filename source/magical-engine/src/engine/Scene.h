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
#include "SceneNode.h"
#include "Camera.h"
#include "Entity.h"

#include <vector>
#include <unordered_set>
#include <unordered_map>

NS_MAGICAL_BEGIN

using ::std::string;
using ::std::unordered_set;

class Scene : public Reference
{
public:
	declare_class_hash_code;

public:
	Scene( void );
	virtual ~Scene( void );
	static Ptr<Scene> create( void );

public:
	virtual void visit( void );

public:
	Camera* createCamera( const char* name = nullptr );
	Entity* createEntity( const char* name = nullptr );
	void destory( const Ptr<SceneNode>& node );

public:
	SceneNode* getRoot( void ) const;
	size_t childCount( void ) const;
	SceneNode* findChild( const char* name ) const;
	SceneNode* childAtIndex( size_t i ) const;
	void addChild( const Ptr<SceneNode>& child );
	void removeChild( const Ptr<SceneNode>& child );
	void removeAllChildren( void );

public:
	void setActiveCamera( const Ptr<Camera>& camera );

protected:
	Camera* m_active_camera = nullptr;
	SceneNode* m_root = nullptr;
	unordered_set<Camera*> m_cameras;
	unordered_set<Entity*> m_entities;
};

NS_MAGICAL_END

#endif //__SCENE_H__