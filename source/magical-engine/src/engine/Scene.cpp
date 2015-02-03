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
#include "Scene.h"

NS_MAGICAL_BEGIN

define_class_hash_code( Scene );

Scene::Scene( void )
{
	assign_class_hash_code();
}

Scene::~Scene( void )
{
	for( auto itr : m_scene_objects )
	{
		itr->release();
	}

	for( auto itr : m_cameras )
	{
		itr->release();
	}
}

Ptr<Scene> Scene::create( void )
{
	Scene* ret = new Scene();
	magicalAssert( ret, "new Scene() failed" );
	return Ptr<Scene>( Initializer<Scene>( ret ) );
}

void Scene::update( void )
{
	m_update_queue = m_scene_objects;
	for( auto itr : m_update_queue )
	{
		itr->update();
	}
}

void Scene::childEvent( NodeEvent evt, SceneNode* child )
{
	switch( evt )
	{
	case NodeEvent::Add:
		switch( child->getElementId() )
		{
		case SceneElement::Node:
			break;
		case SceneElement::Object:
			addSceneObject( (SceneObject*) child );
			break;
		case SceneElement::Camera:
			addCamera( (Camera*) child );
			addSceneObject( (SceneObject*) child );
			break;
		case SceneElement::Light:
			break;
		default:
			magicalAssert( false, "Invaild!" );
			break;
		}
		break;
	case NodeEvent::Remove:
		switch( child->getElementId() )
		{
		case SceneElement::Node:
			break;
		case SceneElement::Object:
			removeSceneObject( (SceneObject*) child );
			break;
		case SceneElement::Camera:
			removeSceneObject( (SceneObject*) child );
			removeCamera( (Camera*) child );
			break;
		case SceneElement::Light:
			break;
		default:
			magicalAssert( false, "Invaild!" );
			break;
		}
		break;
	default:
		magicalAssert( false, "Invaild!" );
		break;
	}

	for( auto itr : child->m_children )
	{
		childEvent( evt, itr );
	}
}

void Scene::childEvent( NodeEvent evt, const Children& children )
{
	for( auto itr : children )
	{
		childEvent( evt, itr );
	}
}

//void Scene::addSceneNode( SceneNode* node )
//{
//	auto itr = m_scene_nodes.find( node );
//	if( itr == m_scene_nodes.end() )
//	{
//		node->retain();
//		m_scene_nodes.insert( node );
//	}
//}
//
//void Scene::removeSceneNode( SceneNode* node )
//{
//	auto itr = m_scene_nodes.find( node );
//	if( itr == m_scene_nodes.end() )
//	{
//		m_scene_nodes.erase( itr );
//		node->release();
//	}
//}

void Scene::addCamera( Camera* camera )
{
	auto itr = m_cameras.find( camera );
	if( itr == m_cameras.end() )
	{
		camera->retain();
		m_cameras.insert( camera );
	}
}

void Scene::removeCamera( Camera* camera )
{
	auto itr = m_cameras.find( camera );
	if( itr != m_cameras.end() )
	{
		m_cameras.erase( itr );
		camera->release();
	}
}

void Scene::addSceneObject( SceneObject* object )
{
	auto itr = m_scene_objects.find( object );
	if( itr == m_scene_objects.end() )
	{
		object->retain();
		m_scene_objects.insert( object );
	}
}

void Scene::removeSceneObject( SceneObject* object )
{
	auto itr = m_scene_objects.find( object );
	if( itr != m_scene_objects.end() )
	{
		m_scene_objects.erase( itr );
		object->release();
	}
}

NS_MAGICAL_END