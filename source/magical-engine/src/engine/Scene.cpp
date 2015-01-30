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
	
}

Ptr<Scene> Scene::create( void )
{
	Scene* ret = new Scene();
	magicalAssert( ret, "new Scene() failed" );
	return Ptr<Scene>( Initializer<Scene>( ret ) );
}

//Camera* Scene::createCamera( const char* name )
//{
//	Camera* camera = new Camera();
//	if( name && *name )
//		camera->setName( name );
//
//	m_cameras.insert( camera );
//	m_entities.insert( camera );
//	return camera;
//}
//
//Entity* Scene::createSceneNode( const char* name )
//{
//	Entity* entity = new Entity();
//	if( name && *name )
//		entity->setName( name );
//
//	m_entities.insert( entity );
//	return entity;
//}

//void Scene::setActiveCamera( const Ptr<Camera>& camera )
//{
//	
//}

void Scene::destory( SceneNode* child )
{
	SceneNode* rnode = node.get();
	magicalAssert( rnode, "should not be nullptr." );

	if( rnode->typeof<Entity>() )
	{
		m_entities.erase( (Entity*) rnode );
		rnode->release();
	}
	else if( node->typeof<Camera>() )
	{
		m_entities.erase( (Entity*) rnode );
		m_cameras.erase( (Camera*) rnode );
		rnode->release();
	}
}

void Scene::onNodeEvent( NodeEvent evt, SceneNode* child )
{
	switch( evt )
	{
	case NodeEvent::Add:
		switch( child->getElementID() )
		{
		case SceneElement::Node:
			addSceneNode( child );
			break;
		case SceneElement::Camera:
			addCamera( (Camera*) child );
			addSceneNode( child );
			break;
		case SceneElement::Light:
			break;
		default:
			magicalAssert( false, "Invaild!" );
			break;
		}
		break;
	case NodeEvent::Remove:
		switch( child->getElementID() )
		{
		case SceneElement::Node:
			removeSceneNode( child );
			break;
		case SceneElement::Camera:
			removeCamera( (Camera*) child );
			removeSceneNode( child );
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
		onNodeEvent( evt, itr );
	}
}

void Scene::onNodeEvent( NodeEvent evt, vector<SceneNode*> children )
{
	for( auto itr : children )
	{
		onNodeEvent( evt, itr );
	}
}

void Scene::addSceneNode( SceneNode* node )
{
	auto itr = m_scene_nodes.find( node );
	if( itr == m_scene_nodes.end() )
	{
		node->retain();
		m_scene_nodes.insert( node );
	}
}

void Scene::addCamera( Camera* camera )
{
	auto itr = m_cameras.find( camera );
	if( itr == m_cameras.end() )
	{
		camera->retain();
		m_cameras.insert( camera );
	}
}

void Scene::removeSceneNode( SceneNode* node )
{
	auto itr = m_scene_nodes.find( node );
	if( itr == m_scene_nodes.end() )
	{
		m_scene_nodes.erase( itr );
		node->release();
	}
}

void Scene::removeCamera( Camera* camera )
{
	auto itr = m_cameras.find( camera );
	if( itr == m_cameras.end() )
	{
		m_cameras.erase( itr );
		camera->release();
	}
}

NS_MAGICAL_END