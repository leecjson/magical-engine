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

	camera_list_.push_back( camera );
	return camera;
}

SceneObject* Scene::createSceneObject( const char* name )
{
	SceneObject* scene_object = new SceneObject();
	if( name && *name )
	{
		scene_object->setName( name );
	}
	
	scene_object_list_.push_back( scene_object );
	return scene_object;
}

void Scene::visit( void )
{
	for( auto itr : scene_object_list_ )
	{
		itr->visit();
	}
}

NS_MAGICAL_END