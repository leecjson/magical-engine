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
#include "Entity.h"
#include "Scene.h"
#include "Renderer.h"

NAMESPACE_MAGICAL

Entity::Entity( void )
{
	m_feature = Entity::Feature;
}

Entity::~Entity( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onDestroy();
		itr.second->release();
	}
}

Ptr<Entity> Entity::create( void )
{
	Entity* ret = new Entity();
	MAGICAL_ASSERT( ret, "new Entity() failed" );
	return Ptr<Entity>( Ptrctor<Entity>( ret ) );
}

Ptr<Entity> Entity::create( const char* name )
{
	Entity* ret = new Entity();
	MAGICAL_ASSERT( ret, "new Entity() failed" );
	ret->setName( name );
	return Ptr<Entity>( Ptrctor<Entity>( ret ) );
}

void Entity::visit( Camera* camera )
{
	if( !m_visible )
		return;

	// frustum cull check
	if( camera->isFrustumCullEnabled() )
	{
		
	}

	Renderer::addCommand( getLocalToWorldMatrix(), camera->getViewProjectionMatrix() );

	if( !m_children.empty() )
	{
		for( auto child : m_children )
		{
			child->visit( camera );
		}
	}
}

void Entity::start( void ) 
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onStart();
	}
	Object::start();
}

void Entity::stop( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onStop();
	}
	Object::stop();
}

void Entity::prepare( void )
{

}

void Entity::update( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onUpdate();
	}
}


NAMESPACE_END