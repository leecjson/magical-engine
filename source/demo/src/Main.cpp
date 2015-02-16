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

void MainCameraScript::onCreate( void )
{
	that->setPosition( Vector2::Zero );
	that->lookAt( 1, 1, 1 );

	magicalLog( "onCreate" );
}

void MainCameraScript::onStart( void )
{
	magicalLog( "onStart" );
}

void MainCameraScript::onUpdate( void )
{
	magicalLog( "onUpdate" );
}

void MainCameraScript::onStop( void )
{
	magicalLog( "onStop" );
}

void MainCameraScript::onDestroy( void )
{
	magicalLog( "onDestroy" );
}

void mainDelegate( void )
{
	Ptr<Scene> scene = Scene::create();
	scene->getViewChannel( ViewChannel::Default )->setEnabled( true );
	scene->getViewChannel( ViewChannel::Default )->setViewRect( 0, 0, 1, 1 );
	Engine::runScene( scene );

	Ptr<Camera> camera = Camera::create( "Main Camera" );
	camera->bindViewChannel( ViewChannel::Default );
	camera->setNearClipDistance( 0.3f );
	camera->addComponent<MainCameraScript>();
	camera->setParent( scene );

	/*Ptr<SceneObject> cube = SceneObject::create( "Cube" );
	cube->setPosition( Vector3::Zero );
	scene->addChild( cube );*/
}