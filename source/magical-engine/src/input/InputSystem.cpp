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
#include "InputSystem.h"
#include <vector>
#include <unordered_set>
#include <unordered_map>

NS_MAGICAL_BEGIN

enum class OperateOnLocked
{
	Add = 1,
	Remove = 2,
};

//struct KeyEventObject
//{
//	DelegatePlatform platform;
//	KeyEventDelegate delegate;
//	Shared<Reference> reference;
//};
//
//static std::unordered_map<Behaviour*, KeyEventObject> _s_key_event_objects;
//static std::vector< std::pair<OperateOnLocked, KeyEventObject> > _s_temp_key_event_objects;
//static bool _s_key_event_dispatch_locked = false;

void Input::Init( void )
{

}

void Input::Delc( void )
{
	
}
//
//void Input::keyEvent( KeyCode key, KeyAction action )
//{
//	if( !_s_temp_key_event_objects.empty() )
//	{
//		for( auto& itr : _s_temp_key_event_objects )
//		{
//			if( itr.first == OperateOnLocked::Add )
//			{
//				
//			}
//			else if( itr.first == OperateOnLocked::Remove )
//			{
//				
//			}
//		}
//	}
//
//	_s_key_event_dispatch_locked = true;
//
//	KeyEvent keyevent;
//	keyevent.key = key;
//	keyevent.action = action;
//
//	for( auto& itr : _s_key_event_objects )
//	{
//		if( itr.second.platform == DelegatePlatform::Cpp )
//		{
//			itr.second.delegate( &keyevent );
//		}
//		/*else if( itr.second.platform == DelegatePlatform::Lua )
//		{
//
//		}*/
//	}
//
//	_s_key_event_dispatch_locked = false;
//}
//
//void Input::addKeyEventDelegate( Reference* reference, const KeyEventDelegate& eventdel )
//{
//	magicalAssert( reference != nullptr && eventdel != nullptr, "Input::addKeyEventDelegate" );
//
//	KeyEventObject obj;
//	obj.platform  = DelegatePlatform::Cpp;
//	obj.delegate  = eventdel; 
//	obj.reference = reference;
//
//	if( _s_key_event_dispatch_locked )
//	{
//		_s_temp_key_event_objects.push_back( std::make_pair( OperateOnLocked::Add, obj ) );
//	}
//	else
//	{
//		//_s_key_event_objects.insert( std::make_pair( reference, obj ) );
//	}
//}
//
//void Input::removeKeyEventDelegate( Reference* reference )
//{
//
//}
//
//void Input::removeAllKeyEventDelegates( void )
//{
//
//}

NS_MAGICAL_END