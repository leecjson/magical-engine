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
#include "Main.h"
#include "magical-engine.h"

USING_NS_MAGICAL;

#define dcast( cls, exp ) dynamic_cast< cls >( exp )
#define scast( cls, exp ) static_cast< cls >( exp )

void MainCameraScript::onCreate( void )
{
	/*Object* player = dynamic_cast<Object*>( self->findChild( "haha" ) );
	
	Entity* player = self->findChild<Button>( "haha" )
		
	Article* article = 

	SceneArticle*/
}

void MainCameraScript::onStart( void )
{
	SceneObject* player = dynamic_cast< SceneObject* >( self->findChild( "haha" ) );

	SceneObject* pl2 = (SceneObject*) self->findChild( "haha" );
}

void MainCameraScript::onUpdate( void )
{
	
}

void MainCameraScript::onStop( void )
{

}

void MainCameraScript::onDestroy( void )
{

}

Ptr<Camera> m_main_camera;

void mainDelegate( void )
{
	Ptr<Scene> scene = Scene::create();
	scene->addComponent<MainCameraScript>();
	Engine::runScene( scene );

	m_main_camera = Camera::create();
	m_main_camera->setPosition( Vector3::Zero );
	m_main_camera->lookAt( 1, 1, 1 );
	m_main_camera->addComponent<MainCameraScript>();
	scene->addChild( m_main_camera );

	m_main_camera2 = Camera::create();
	scene->addChild( m_main_camera2 );
}