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
	Input::addKeyEventFunction(
		this, std::bind( &MainCameraScript::onKeyEvent, this, std::placeholders::_1 ) );
	Input::addMouseButtonEventFunction(
		this, std::bind( &MainCameraScript::onMouseButtonEvent, this, std::placeholders::_1 ) );
	Input::addMouseMoveEventFunction( 
		this, std::bind( &MainCameraScript::onMouseMoveEvent, this, std::placeholders::_1 ) );

	MAGICAL_LOGD( "onCreate" );
}

void MainCameraScript::onStart( void )
{
	entity1 = (Entity*) Engine::runningScene()->findChild( "Cube Entity1" );

	MAGICAL_LOGD( "onStart" );
}

void MainCameraScript::onUpdate( void )
{
	//magicalLog( "onUpdate" );

	static float a = 1.0f;
	a += 20.0f * Engine::deltaTime();
	
	entity1->setRotation( 
		Quaternion::createRotationZ( Math::rad( a ) ) );

	if( m_w_pressed )
	{
		object->translate( 0, 0, 0.1f, Space::Self );
	}

	if( m_s_pressed )
	{
		object->translate( 0, 0, -0.1f, Space::Self );
	}

	if( m_a_pressed )
	{
		object->translate( -0.1f, 0, 0, Space::Self );
	}

	if( m_d_pressed )
	{
		object->translate( 0.1f, 0, 0, Space::Self );
	}
}	

void MainCameraScript::onStop( void )
{
	MAGICAL_LOGD( "onStop" );
}

void MainCameraScript::onDestroy( void )
{
	MAGICAL_LOGD( "onDestroy" );
}

void MainCameraScript::onKeyEvent( KeyEvent* keyevent )
{
	switch( keyevent->key )
	{
	case KeyCode::W:
		if( keyevent->action == KeyAction::Down )
			m_w_pressed = true;
		if( keyevent->action == KeyAction::Up )
			m_w_pressed = false;
		break;
	case KeyCode::S:
		if( keyevent->action == KeyAction::Down )
			m_s_pressed = true;
		if( keyevent->action == KeyAction::Up )
			m_s_pressed = false;
		break;
	case KeyCode::A:
		if( keyevent->action == KeyAction::Down )
			m_a_pressed = true;
		if( keyevent->action == KeyAction::Up )
			m_a_pressed = false;
		break;
	case KeyCode::D:
		if( keyevent->action == KeyAction::Down )
			m_d_pressed = true;
		if( keyevent->action == KeyAction::Up )
			m_d_pressed = false;
		break;
	case KeyCode::Space:
		if( keyevent->action == KeyAction::Down )
		{
			object->setPosition( 0, 0, -10 );
		}
		break;
	default:
		break;
	}
}

void MainCameraScript::onMouseButtonEvent( MouseButtonEvent* mousebtnevnet )
{
	if( mousebtnevnet->button == 1 )
	{
		if( mousebtnevnet->action == 1 )
		{
			m_right_button_down = true;
		}
		else
		{
			m_right_button_down = false;
		}
	}
}

void MainCameraScript::onMouseMoveEvent( MouseMoveEvent* mousemoveevent )
{
	if( m_right_button_down )
	{
		double delta_x = mousemoveevent->x - m_last_x;
		delta_x *= 0.2f;
		double delta_y = mousemoveevent->y - m_last_y;
		delta_y *= 0.2f;

		/*EulerAngles ea;
		ea.yaw = magicalDegToRad( -delta_x );
		ea.pitch = magicalDegToRad( -delta_y );
		ea.roll = 0.0f;
		that->rotate( ea.toQuaternion(), Space::World );*/
		object->rotate( Quaternion::createRotationY( Math::rad( delta_x ) ), Space::Parent );
		object->rotate( Quaternion::createRotationX( Math::rad( delta_y ) ), Space::Self );
	}

	m_last_x = mousemoveevent->x;
	m_last_y = mousemoveevent->y;
}

void mainDelegate( void )
{
	MAGICAL_LOGD( "哈哈" );

	Application::setInterval( 1.0 / 60.0 );
	Application::setWindowSize( Size( 960, 640 ) );

	Ptr<Scene> scene = Scene::create();
	scene->getViewChannel( ViewChannel::Default )->setEnabled( true );
	scene->getViewChannel( ViewChannel::Default )->setArea( 0, 0, 1, 1 );
	Engine::runScene( scene );

	Ptr<Camera> camera = Camera::create( "Main Camera" );
	//camera->setOrth( -1.0f, 1.0f, -1.0f, 1.0f, 0.3, 1000 );
	camera->bindViewChannel( ViewChannel::Default );
	camera->setNearClipDistance( 0.3f );
	camera->setOrth( 0, 100, 0, 100, 5, 1000 );
	camera->setPosition( 0, 0, -5 );
	camera->lookAt( 0, 0, -10 );
	camera->addComponent<MainCameraScript>();
	camera->setParent( scene );

	Ptr<Entity> entity = Entity::create( "Cube Entity1" );
	entity->setPosition( 0, 0, 0 );
	//entity->addComponent( RenderComponent::HashCode );
	scene->addChild( entity );

	/*Ptr<SceneObject> cube = SceneObject::create( "Cube" );
	cube->setPosition( Vector3::Zero );
	scene->addChild( cube );*/
}