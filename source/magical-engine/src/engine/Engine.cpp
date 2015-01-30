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
#include "AssetsSystem.h"
//#include "LuaSystem.h"
//#include "RendererSystem.h"
#include "Application.h"
#include "SceneNode.h"

NS_MAGICAL_BEGIN

static int64_t s_last_update_time = 0;
static double s_delta_time = 0.0;
static Scene* s_running_scene = nullptr;

void Engine::init( void )
{
	s_last_update_time = TimeUtils::currentMicrosecondsTime();
}

void Engine::delc( void )
{
	magicalSafeRelease( s_running_scene );
}

void Engine::mainLoop( void )
{
	calcDeltaTime();

	if( s_running_scene )
	{
		s_running_scene->visit();
	}
}

float Engine::deltaTime( void )
{
	return s_delta_time;
}

void Engine::runScene( Ptr<Scene>& scene )
{
	Scene* rscene = scene.get();
	magicalAssert( rscene, "should not be nullptr." );
	magicalSafeAssign( s_running_scene, rscene );
}

Scene* Engine::runningScene( void )
{
	return s_running_scene;
}

void Engine::calcDeltaTime( void )
{
	int64_t now = TimeUtils::currentMicrosecondsTime();
	s_delta_time = MAX( 0.0, ( now - s_last_update_time ) / 1000000.0 );
	s_last_update_time = now;
}

NS_MAGICAL_END