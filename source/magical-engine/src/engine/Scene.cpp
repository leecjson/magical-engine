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
#include "Application.h"
#include "Renderer.h"

NAMESPACE_MAGICAL

Scene::Scene( void )
{
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
	MAGICAL_ASSERT( ret, "new Scene() failed" );
	return Ptr<Scene>( Ptrctor<Scene>( ret ) );
}

ViewChannel* Scene::getViewChannel( int index ) const
{
	MAGICAL_ASSERT( 0 <= index && index <= ViewChannel::Count, "Invalid Index!" );

	return m_view_channels[ index ];
}

void Scene::resize( int width, int height )
{
	for( auto camera : m_cameras )
	{
		if( camera->isAutoAspectRatio() )
		{
			camera->setAspectRatio( (float)width / (float)height );
		}
	}
}

void Scene::visit( void )
{
	if( !m_visible )
		return;

	if( m_children.empty() )
		return;

	for( int i = 0; i < ViewChannel::Count; i ++ )
	{
		ViewChannel* channel = m_view_channels[i];
		if( channel->isAvailable() )
		{
			Camera* camera = channel->getCamera();
			if( camera->isActive() && camera->isVisiable() )
			{
				for( auto child : m_children )
				{
					child->visit( camera );
				}
				Renderer::render( channel );
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

void Scene::link( Object* child )
{
	switch( child->m_feature )
	{
	case Object::Feature:
		break;
	case Entity::Feature:
		addEntity( (Entity*)child );
		break;
	case Camera::Feature:
		addCamera( (Camera*)child );
		addEntity( (Entity*)child );
		break;
	/*case Element::Light:
		break;*/
	default:
		MAGICAL_ASSERT( false, "Invalid!" );
		break;
	}

	for( auto itr : child->m_children )
	{
		link( itr );
	}
}

void Scene::unlink( Object* child )
{
	switch( child->m_feature )
	{
	case Object::Feature:
		break;
	case Entity::Feature:
		removeEntity( (Entity*)child );
		break;
	case Camera::Feature:
		removeEntity( (Entity*)child );
		removeCamera( (Camera*)child );
		break;
	/*case Element::Light:
		break;*/
	default:
		MAGICAL_ASSERT( false, "Invalid!" );
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
	MAGICAL_ASSERT( lcamera != camera, "Invalid!" );
	if( lcamera != nullptr )
	{
		MAGICAL_ASSERT( lcamera->isActive(), "Invalid!" );
		lcamera->setActive( false );
	}

	channel->setCamera( camera );
}

void Scene::unbindCameraFromViewChannel( Camera* camera )
{
	ViewChannel* channel = m_view_channels[ camera->getBoundViewChannelIndex() ];

	Camera* lcamera = channel->getCamera();
	MAGICAL_ASSERT( lcamera == camera, "Invalid!" );

	channel->removeCamera();
}

void Scene::addCamera( Camera* camera )
{
	auto itr = m_cameras.find( camera );
	MAGICAL_ASSERT( itr == m_cameras.end(), "Invalid! already in scene" );

	camera->retain();
	m_cameras.insert( camera );

	if( camera->isActive() )
	{
		bindCameraToViewChannel( camera );
	}

	if( camera->isAutoAspectRatio() )
	{
		const Size& size = Application::getWindowSize();
		camera->setAspectRatio( size.w / size.h );
	}
}

void Scene::removeCamera( Camera* camera )
{
	auto itr = m_cameras.find( camera );
	MAGICAL_ASSERT( itr != m_cameras.end(), "Invalid! isn't exists in scene" );

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
	MAGICAL_ASSERT( itr == m_entities.end(), "Invalid! already in scene" );

	object->retain();
	m_entities.insert( object );
}

void Scene::removeEntity( Entity* object )
{
	auto itr = m_entities.find( object );
	MAGICAL_ASSERT( itr != m_entities.end(), "Invalid! isn't exists in scene" );

	m_entities.erase( itr );
	object->release();
}

NAMESPACE_END