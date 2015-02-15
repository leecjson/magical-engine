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
	m_root_scene = this;

	for( int i = 0; i < kViewChannelCount; ++ i )
	{
		m_active_cameras[i] = nullptr;
	}
}

Scene::~Scene( void )
{
	for( auto itr : m_cameras )
	{
		itr->release();
	}

	for( auto itr : m_entities )
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

void Scene::visit( void )
{
	if( !m_is_active )
		return;

	if( m_children.empty() )
		return;

	for( int i = 0; i < 1; ++i )
	{
		// setviewport
		for( auto child : m_children )
		{
			child->visit( camera );
		}
	}
}

void Scene::update( void )
{
	m_update_queue = m_entities;
	for( auto itr : m_update_queue )
	{
		itr->update();
	}
}

void Scene::link( SceneObject* child )
{
	switch( child->m_element_enum )
	{
	case Element::Object:
		break;
	case Element::Entity:
		addEntity( (Entity*)child );
		break;
	case Element::Camera:
		addCamera( (Camera*)child );
		addEntity( (Entity*)child );
		break;
	case Element::Light:
		break;
	default:
		magicalAssert( false, "Invaild!" );
		break;
	}

	for( auto itr : child->m_children )
	{
		link( itr );
	}
}

void Scene::unlink( SceneObject* child )
{
	switch( child->m_element_enum )
	{
	case Element::Object:
		break;
	case Element::Entity:
		removeEntity( (Entity*)child );
		break;
	case Element::Camera:
		removeEntity( (Entity*)child );
		removeCamera( (Camera*)child );
		break;
	case Element::Light:
		break;
	default:
		magicalAssert( false, "Invaild!" );
		break;
	}

	for( auto itr : child->m_children )
	{
		unlink( itr );
	}
}

void Scene::setActiveCamera( Camera* camera )
{
	if( camera->isActive() )
	{
		Camera* lcamera = m_active_cameras[ (int)camera->getViewChannel() ];
		if( lcamera )
		{
			
		}
	}
	else
	{
		
	}
}

void Scene::addCamera( Camera* camera )
{
	auto itr = m_cameras.find( camera );
	magicalAssert( itr == m_cameras.end(), "Invaild! already in scene" );
	if( itr == m_cameras.end() )
	{
		camera->retain();
		m_cameras.insert( camera );

		setActiveCamera( camera );
	}
}

void Scene::removeCamera( Camera* camera )
{
	auto itr = m_cameras.find( camera );
	magicalAssert( itr != m_cameras.end(), "Invaild! isn't exists in scene" );
	if( itr != m_cameras.end() )
	{
		m_cameras.erase( itr );
		camera->release();
	}
}

void Scene::addEntity( Entity* object )
{
	auto itr = m_entities.find( object );
	magicalAssert( itr == m_entities.end(), "Invaild! already in scene" );
	if( itr == m_entities.end() )
	{
		object->retain();
		m_entities.insert( object );
	}
}

void Scene::removeEntity( Entity* object )
{
	auto itr = m_entities.find( object );
	magicalAssert( itr != m_entities.end(), "Invaild! isn't exists in scene" );
	if( itr != m_entities.end() )
	{
		m_entities.erase( itr );
		object->release();
	}
}

NS_MAGICAL_END