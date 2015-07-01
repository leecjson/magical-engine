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
#include "Set.h"
#include "Object.h"
#include "Entity.h"
#include "Camera.h"
#include "ViewChannel.h"

NAMESPACE_MAGICAL

class Object;
class Camera;
class Entity;

class Scene : public Object
{
	friend class Director;

public:
	Scene( void );
	virtual ~Scene( void );
	static Ptr<Scene> create( void );

public:
	virtual void update( void );
	virtual void link( Object* child ) override;
	virtual void unlink( Object* child ) override;

public:
	Camera* getVisitingCamera( void ) const { return m_visiting_camera; }

protected:
	void addCamera( Camera* camera );
	void removeCamera( Camera* camera );
	void addEntity( Entity* entity );
	void removeEntity( Entity* entity );

protected:
	void setVisitingCamera( Camera* camera );

protected:
	Camera* m_visiting_camera = nullptr;
	
protected:
	UnorderedSet<Entity*> m_entities;
	UnorderedSet<Camera*> m_cameras;
	UnorderedSet<Entity*> m_update_queue;
};

NAMESPACE_END

#endif //__SCENE_H__