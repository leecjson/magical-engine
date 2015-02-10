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
#ifndef __BEHAVIOUR_H__
#define __BEHAVIOUR_H__

#include "magical-macros.h"
#include "Common.h"
#include "Reference.h"
#include "SceneNode.h"

NS_MAGICAL_BEGIN

class BehaviourBase : public Reference
{
public:
	friend class SceneObject;
	virtual void onCreate( void ){}
	virtual void onStart( void ){}
	virtual void onStop( void ){}
	virtual void onDestroy( void ){}
	virtual void onUpdate( void ){}
};

template< class T >
class Behaviour : public BehaviourBase
{
public:
	friend class SceneObject;
	declare_class_hash_code;
	Behaviour( void );

protected:
	T* that = nullptr;
};

template< class T >
Behaviour<T>::Behaviour( void )
{
	assign_class_hash_code();
}

template< class T >
define_class_hash_code( Behaviour<T> );

NS_MAGICAL_END

#endif //__BEHAVIOUR_H__