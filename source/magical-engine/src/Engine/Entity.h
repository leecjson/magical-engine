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
#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "magical-macros.h"
#include "Common.h"
#include "Behaviour.h"
#include "SceneObject.h"
#include <unordered_map>

NS_MAGICAL_BEGIN

using ::std::unordered_map;

class Entity : public SceneObject
{
public:
	member_method Entity( void );
	member_method virtual ~Entity( void );
	member_method static Ptr<Entity> Create( void );
	member_method static Ptr<Entity> Create( const char* name );

public:
	template< class TBehaviour >
	member_method void AddComponent( void );
	template< class TBehaviour >
	member_method void RemoveComponent( void );

public:
	member_method virtual void Visit( Camera* camera ) override;
	//virtual void draw( void ) override;
	member_method virtual void Prepare( void );
	member_method virtual void Start( void ) override;
	member_method virtual void Stop( void ) override;
	member_method virtual void Update( void );

protected:
	unordered_map<size_t, BehaviourBase*> m_behaviours;

protected:
	//AABB3 m_aabb;
};

//class RenderComponent
//{
//
//};

#include "Entity.inl"

NS_MAGICAL_END

#endif //__ENTITY_H__