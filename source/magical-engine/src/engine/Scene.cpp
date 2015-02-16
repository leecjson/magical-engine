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

	for( int i = 0; i < ViewChannel::Count; i ++ )
		m_view_channels[i] = new ViewChannel();

	m_view_channels[0]->setEnabled( true );
}

Scene::~Scene( void )
{
	for( int i = 0; i < ViewChannel::Count; i ++ )
	{
		m_view_channels[i]->release();
	}

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

ViewChannel* Scene::getViewChannel( ViewChannel::Index index ) const
{
	magicalAssert( 0 <= index && index <= ViewChannel::Count, "Invalid Index!" );
	return m_view_channels[ index ];
}

void Scene::visit( void )
{
	if( !m_visible )
		return;

	if( m_children.empty() )
		return;

	for( int i = 0; i < ViewChannel::Count; i ++ )
	{
		if( m_view_channels[i]->isChannelOpened() )
		{
			Camera* camera = m_view_channels[i]->getCamera();
			for( auto child : m_children )
			{
				child->visit( camera );
			}
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
		magicalAssert( false, "Invalid!" );
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
		magicalAssert( false, "Invalid!" );
		break;
	}

	for( auto itr : child->m_children )
	{
		unlink( itr );
	}
}

void Scene::bindCameraToViewChannel( Camera* camera )
{
	ViewChannel* channel = m_view_channels[ camera->getBoundViewChannelIndex() ];

	Camera* lcamera = channel->getCamera();
	magicalAssert( lcamera != camera, "Invalid!" );
	if( lcamera != nullptr )
	{
		magicalAssert( lcamera->isActive(), "Invalid!" );
		lcamera->setActive( false );
	}

	channel->setCamera( camera );
}

void Scene::unbindCameraFromViewChannel( Camera* camera )
{
	ViewChannel* channel = m_view_channels[ camera->getBoundViewChannelIndex() ];

	Camera* lcamera = channel->getCamera();
	magicalAssert( lcamera == camera, "Invalid!" );

	channel->removeCamera();
}

void Scene::addCamera( Camera* camera )
{
	auto itr = m_cameras.find( camera );
	magicalAssert( itr == m_cameras.end(), "Invalid! already in scene" );

	camera->retain();
	m_cameras.insert( camera );

	if( camera->isActive() )
	{
		bindCameraToViewChannel( camera );
	}
}

void Scene::removeCamera( Camera* camera )
{
	auto itr = m_cameras.find( camera );
	magicalAssert( itr != m_cameras.end(), "Invalid! isn't exists in scene" );

	m_cameras.erase( itr );
	camera->release();

	if( camera->isActive() )
	{
		unbindCameraFromViewChannel( camera );
	}
}

void Scene::addEntity( Entity* object )
{
	auto itr = m_entities.find( object );
	magicalAssert( itr == m_entities.end(), "Invalid! already in scene" );

	object->retain();
	m_entities.insert( object );
}

void Scene::removeEntity( Entity* object )
{
	auto itr = m_entities.find( object );
	magicalAssert( itr != m_entities.end(), "Invalid! isn't exists in scene" );

	m_entities.erase( itr );
	object->release();
}

NS_MAGICAL_END