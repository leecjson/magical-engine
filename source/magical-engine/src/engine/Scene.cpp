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
: m_root( new SceneNode() )
{
	assign_class_hash_code();
}

Scene::~Scene( void )
{
	m_root->release();
}

Ptr<Scene> Scene::create( void )
{
	Scene* ret = new Scene();
	magicalAssert( ret, "new Scene() failed" );
	return Ptr<Scene>( Initializer<Scene>( ret ) );
}

void Scene::visit( void )
{
	m_root->transform();

	for( auto itr : m_entities )
	{
		itr->draw();
	}
}

Camera* Scene::createCamera( const char* name )
{
	Camera* camera = new Camera();
	if( name && *name )
		camera->setName( name );

	m_cameras.insert( camera );
	m_entities.insert( camera );
	return camera;
}

Entity* Scene::createEntity( const char* name )
{
	Entity* entity = new Entity();
	if( name && *name )
		entity->setName( name );

	m_entities.insert( entity );
	return entity;
}

void Scene::destory( const Ptr<SceneNode>& node )
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

SceneNode* Scene::getRoot( void ) const
{
	return m_root;
}

size_t Scene::childCount( void ) const
{
	return m_root->childCount();
}

SceneNode* Scene::findChild( const char* name ) const
{
	return m_root->findChild( name );
}

SceneNode* Scene::childAtIndex( size_t i ) const
{
	return m_root->childAtIndex( i );
}

void Scene::addChild( const Ptr<SceneNode>& child )
{
	return m_root->addChild( child );
}

void Scene::removeChild( const Ptr<SceneNode>& child )
{
	return m_root->removeChild( child );
}

void Scene::removeAllChildren( void )
{
	return m_root->removeAllChildren();
}

void Scene::setActiveCamera( const Ptr<Camera>& camera )
{
	
}

void Scene::onAdd( SceneNode* child )
{
	if( m_parent )
		m_parent->onAdd( child );
}

void Scene::onRemove( const vector<SceneNode*>& children )
{
	if( m_parent )
		m_parent->onRemove( children );
}

void Scene::onRemove( SceneNode* child )
{
	if( m_parent )
		m_parent->onRemove( child );
}

NS_MAGICAL_END