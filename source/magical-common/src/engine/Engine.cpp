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
#include "Utils.h"
#include "AssetsSystem.h"
#include "LuaSystem.h"
#include "RendererSystem.h"

#include "Node.h"

static int64_t s_last_update_time;
static float s_delta_time;

static void calcDeltaTime( void );

void Engine::init( void )
{
	s_delta_time = 0.0f;
	s_last_update_time = TimeUtils::currentMicrosecondsTime();
}

void Engine::delc( void )
{
	
}

void Engine::initSystems( void )
{
	Assets::init();
	magicalReturnIfError();

	Lua::init();
	magicalReturnIfError();

	Renderer::init();
	magicalReturnIfError();
}

void Engine::delcSystems( void )
{
	Renderer::delc();
	magicalReturnIfError();

	Lua::delc();
	magicalReturnIfError();

	Assets::delc();
	magicalReturnIfError();
}

void Engine::mainLoop( void )
{
	calcDeltaTime();

	Renderer::render();

	Lua::state()->executeGlobalFunction("go");
}

void Engine::reshape( int w, int h )
{
	Renderer::reshape( w, h );
}

float Engine::getDeltaTime( void )
{
	return s_delta_time;
}

static void calcDeltaTime( void )
{
	int64_t now = TimeUtils::currentMicrosecondsTime();
	s_delta_time = std::max<float>( 0, ( now - s_last_update_time ) / 1000000.0f );
	s_last_update_time = now;
}