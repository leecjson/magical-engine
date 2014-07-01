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
#include "magical-engine.h"
#include <windows.h>

#include <iostream> 
#include <chrono> 
#include <ctime> 
#include <time.h> 
#include <cstdint> 

const int microSecPerSec = 1000000; 

extern "C" int gettimeofday( struct timeval* tv, struct timezone* tz )
{
	LARGE_INTEGER time, freq;
	if( tv != NULL )
    {
        QueryPerformanceFrequency( &freq );
        QueryPerformanceCounter( &time );
        tv->tv_sec  = (long)( time.QuadPart / freq.QuadPart );
        tv->tv_usec = (long)( time.QuadPart * 1000000.0 / freq.QuadPart - tv->tv_sec * 1000000.0 );
    }
	return 0;
}

void onFinishLaunching( void )
{
	
	std::chrono::time_point<std::chrono::system_clock> p1, p2, p3; 
    struct timeval tv; 
    int64_t mSecond; 
  
    p2 = std::chrono::system_clock::now(); 
    p3 = p2 - std::chrono::hours(24); 
    gettimeofday(&tv,NULL); 
    mSecond = tv.tv_sec ; 
  
    std::time_t epoch_time = std::chrono::system_clock::to_time_t(p1); // seconds 
    std::cout << "epoch: " << std::ctime(&epoch_time); 
    std::time_t today_time = std::chrono::system_clock::to_time_t(p2); 
    std::cout << "today: " << std::ctime(&today_time); 
  
    std::cout << "hours since epoch: " 
                << std::chrono::duration_cast<std::chrono::hours>(  //hours 
                  p2.time_since_epoch()).count() 
                << std::endl; 
                
    std::cout << "yesterday, hours since epoch: " 
                << std::chrono::duration_cast<std::chrono::hours>( 
                  p3.time_since_epoch()).count() 
                << std::endl; 
              
    std::cout << "Microseconds since epoch: (chrono) : "  //microseconds 
                << std::chrono::duration_cast<std::chrono::microseconds>(p2.time_since_epoch()).count() // p2 - p1 == 
                <<std::endl; 
                
    std::cout << "Microseconds since epoch: (gettimeofday) :" << mSecond * microSecPerSec + tv.tv_usec 
                <<std::endl; 

	LuaState& L = LuaSystem::getLuaState();
	L->executeScriptFile("main.lua");
	L->executeGlobalFunction(kLuaOnCreate);
	magicalLuaStateDump(L->getState());
	L->clean();
}

int main(int argc, char* argv[])
{
	Application::setOnFinishLaunching(onFinishLaunching);
	Application::run();
	return 0;
}

