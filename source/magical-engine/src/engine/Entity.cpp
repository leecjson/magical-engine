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

NS_MAGICAL_BEGIN

define_class_hash_code( Entity );

Entity::Entity( void )
{
	assign_class_hash_code();
	m_element_id = SceneElement::Entity;
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
	magicalAssert( ret, "new Entity() failed" );
	return Ptr<Entity>( Initializer<Entity>( ret ) );
}

Ptr<Entity> Entity::create( const char* name )
{
	Entity* ret = new Entity();
	magicalAssert( ret, "new Entity() failed" );
	ret->setName( name );
	return Ptr<Entity>( Initializer<Entity>( ret ) );
}

void Entity::visit( void )
{
	SceneNode::visit();
}

void Entity::prepare( void )
{

}

void Entity::start( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onStart();
	}
	SceneNode::start();
}

void Entity::stop( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onStop();
	}
	SceneNode::stop();
}

void Entity::update( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onUpdate();
	}
}


NS_MAGICAL_END