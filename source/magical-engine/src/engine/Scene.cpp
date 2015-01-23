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

Scene::Scene( void )
{
	
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

Camera* Scene::createCamera( const char* name )
{
	Camera* camera = new Camera();
	if( name && *name )
	{
		camera->setName( name );
	}

	m_cameras.push_back( camera );
	return camera;
}

void Scene::removeCamera( const Ptr<Camera>& camera )
{
	Camera* rcamera = camera.get();
	magicalAssert( rcamera, "should not be nullptr." );

	auto itr = std::find( m_cameras.begin(), m_cameras.end(), rcamera );
	if( itr != m_cameras.end() )
	{
		m_cameras.erase( itr );
		rcamera->release();
	}
}

void Scene::removeCamera( const char* name )
{
	magicalAssert( name && *name, "should not empty." );

	Camera* camera;
	auto itr = m_cameras.begin();
	auto end = m_cameras.end();

	for( ; itr != end; ++ itr )
	{
		camera = *itr;
		if( camera->getName() == name )
		{
			m_cameras.erase( itr );
			break;
		}
	}
}

SceneObject* Scene::createSceneObject( const char* name )
{
	SceneObject* scene_object = new SceneObject();
	if( name && *name )
	{
		scene_object->setName( name );
	}

	m_scene_objects.push_back( scene_object );
	return scene_object;
}

void Scene::removeSceneObject( const Ptr<SceneObject>& sceneobj )
{

}

void Scene::removeSceneObject( const char* name )
{

}

void Scene::visit( void )
{
	transform();

}

NS_MAGICAL_END