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
#include "Engine.h"
#include "magical-math.h"
#include "Utils.h"
#include "Assets.h"
//#include "LuaSystem.h"
#include "Renderer.h"
#include "Application.h"
#include "Object.h"

NAMESPACE_MAGICAL

static int64_t _last_update_time = 0;
static double _delta_time = 0.0;

static Scene* _next_scene = nullptr;
static Scene* _running_scene = nullptr;

void Engine::init( void )
{
	_last_update_time = Time::currentMicroseconds();
}

void Engine::delc( void )
{
	if( _running_scene )
		_running_scene->stop();

	SAFE_RELEASE( _running_scene );
	SAFE_RELEASE( _next_scene );
}

void Engine::mainLoop( void )
{
	calcDeltaTime();

	Renderer::render();

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
		_running_scene->visit();
	}
}

void Engine::resize( int width, int height )
{
	if( _running_scene )
		_running_scene->resize( width, height );

	Renderer::resize( width, height );
}

float Engine::deltaTime( void )
{
	return _delta_time;
}

void Engine::runScene( Scene* scene )
{
	MAGICAL_ASSERT( scene, "should not be nullptr." );
	MAGICAL_ASSERT( scene != _running_scene, "Invaild!" );

	SAFE_ASSIGN( _next_scene, scene );
}

Scene* Engine::runningScene( void )
{
	return _running_scene;
}

void Engine::calcDeltaTime( void )
{
	int64_t now = Time::currentMicroseconds();
	_delta_time = Math::max( 0.0, ( now - _last_update_time ) / 1000000.0 );
	_last_update_time = now;
}

NAMESPACE_END