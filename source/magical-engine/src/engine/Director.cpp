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
#include "Director.h"
#include "magical-math.h"
#include "Utils.h"
#include "Assets.h"
#include "Renderer.h"
#include "Application.h"
#include "Object.h"

NAMESPACE_MAGICAL

static Scene* _next_scene = nullptr;
static Scene* _running_scene = nullptr;
static long long _last_update_time = 0;
static double _delta_time = 0.0;
static ViewChannel* _view_channels[ ViewChannel::Count ];

void Director::init( void )
{
	_last_update_time = Time::currentMicroseconds();

	for( unsigned int i = 0; i < ViewChannel::Count; ++ i )
	{
		_view_channels[i] = new ViewChannel();
		_view_channels[i]->setOriginalSize( Application::getWindowSize() );
	}
	_view_channels[ ViewChannel::Default ]->setEnabled( true );
}

void Director::delc( void )
{
	if( _running_scene )
		_running_scene->stop();

	SAFE_RELEASE( _running_scene );
	SAFE_RELEASE( _next_scene );

	for( unsigned int i = 0; i < ViewChannel::Count; ++ i )
		_view_channels[i]->release();
}

void Director::mainLoop( void )
{
	calcDeltaTime();

	if( _next_scene )
	{
		if( _running_scene )
			_running_scene->stop();

		SAFE_MOVE_NULL( _running_scene, _next_scene );
		_running_scene->start();
	}

	if( _running_scene )
	{
		_running_scene->update();
		_running_scene->transform();

		for( unsigned int i = 0; i < ViewChannel::Count; ++ i )
		{
			ViewChannel* channel = _view_channels[ i ];
			if( !channel->isOpened() )
				continue;

			Camera* camera = channel->getCamera();
			if( camera->isActive() && camera->isVisible() )
			{
				_running_scene->setVisitingCamera( camera );
				_running_scene->visit();
				Renderer::render( i, channel );
				_running_scene->setVisitingCamera( nullptr );
			}
		}
	}
}

void Director::resize( int w, int h )
{
	for( auto itr : _view_channels )
	{
		itr->setOriginalSize( Size( w, h ) );
		Camera* camera = itr->getCamera();
		if( camera != nullptr && camera->isAutoAspectRatio() )
		{
			auto area = itr->calcRealArea();
			camera->setAspectRatio( area.w / area.h );
		}
	}
}

void Director::runScene( Scene* scene )
{
	MAGICAL_ASSERT( scene, "should not be nullptr." );
	MAGICAL_ASSERT( scene != _running_scene, "Invaild!" );

	SAFE_ASSIGN( _next_scene, scene );
}

Scene* Director::getRunningScene( void )
{
	return _running_scene;
}

ViewChannel* Director::getViewChannel( unsigned int index )
{
	MAGICAL_ASSERT( 0 <= index && index < ViewChannel::Count, "Invalid Index!" );

	return _view_channels[ index ];
}

float Director::getDeltaTime( void )
{
	return _delta_time;
}

void Director::bindCameraToViewChannel( Camera* camera )
{
	ViewChannel* channel = _view_channels[ camera->getBoundViewChannelIndex() ];

	Camera* lcamera = channel->getCamera();
	MAGICAL_ASSERT( lcamera != camera, "Invalid!" );
	if( lcamera != nullptr )
	{
		MAGICAL_ASSERT( lcamera->isActive(), "Invalid!" );
		lcamera->setActive( false );
	}

	if( camera->isAutoAspectRatio() )
	{
		auto area = channel->calcRealArea();
		camera->setAspectRatio( area.w / area.h );
	}

	channel->setCamera( camera );
}

void Director::unbindCameraFromViewChannel( Camera* camera )
{
	ViewChannel* channel = _view_channels[ camera->getBoundViewChannelIndex() ];

	Camera* lcamera = channel->getCamera();
	MAGICAL_ASSERT( lcamera == camera, "Invalid!" );

	channel->removeCamera();
}

void Director::calcDeltaTime( void )
{
	long long now = Time::currentMicroseconds();
	_delta_time = Math::max( 0.0, ( now - _last_update_time ) / 1000000.0 );
	_last_update_time = now;
}

NAMESPACE_END