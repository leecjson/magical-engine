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
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>
#include <memory>

#include "PlatformMacros.h"
#include "Common.h"

class Object_t;
typedef std::shared_ptr<Object_t> Object;
typedef std::shared_ptr<const Object_t> const_Object;

static inline Object newObject( void )
{
	Object_t* obj = new Object_t();
	magicalAssert( obj, "new Object_t();" );
	return std::move( Object(obj) );
}

static inline Object* newObject_LuaGC( void )
{
	Object_t* obj = new Object_t();
	magicalAssert( obj, "new Object_t();" );
	Object* ret = new Object( obj );
	magicalAssert( ret, "new Object( obj );" );
	return ret;
}

class Object_t : public std::enable_shared_from_this<Object_t>
{
public:
	Object_t( void );
	virtual ~Object_t( void );
	std::string toString( void ) const;
};



#endif //__OBJECT_H__