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
	declare_class_hash_code;

public:
	Entity( void );
	virtual ~Entity( void );
	static Ptr<Entity> create( void );
	static Ptr<Entity> create( const char* name );

public:
	template< class TBehaviour >
	void addComponent( void );
	template< class TBehaviour >
	void removeComponent( void );

public:
	virtual void visit( Camera* camera ) override;
	virtual void prepare( void );
	virtual void start( void ) override;
	virtual void stop( void ) override;
	virtual void update( void );

protected:
	unordered_map<size_t, BehaviourBase*> m_behaviours;

protected:
	AABB3 m_aabb;
};

#include "Entity.inl"

NS_MAGICAL_END

#endif //__ENTITY_H__