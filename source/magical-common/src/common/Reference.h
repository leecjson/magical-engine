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
#ifndef __REFERENCE_H__
#define __REFERENCE_H__

#include <string>

#include "PlatformMacros.h"
#include "Common.h"
#include "Shared.h"

<<<<<<< HEAD:source/magical-common/src/common/Object.h
class Object_t;

typedef std::shared_ptr<Object_t> Object;
typedef std::shared_ptr<const Object_t> const_Object;
<<<<<<< HEAD
#define newObject() (std::move(Object(new Object_t())))
#define newObject_LuaGC() (new Object(new Object_t()))
=======

class Object_t : public std::enable_shared_from_this<Object_t>
=======
class Reference
>>>>>>> ec1b54020335b76df015817be9eeaa46104a0857:source/magical-common/src/common/Reference.h
{
public:
	Reference( void );
	virtual ~Reference( void );

public:
	void retain( void );
	void release( void );

<<<<<<< HEAD:source/magical-common/src/common/Object.h
static inline Object* newObject_LuaGC( void )
{
	Object_t* obj = new Object_t();
	magicalAssert( obj, "new Object_t();" );
	Object* ret = new Object( obj );
	magicalAssert( ret, "new Object( obj );" );
	return ret;
}
>>>>>>> origin/master
=======
	int referenceCount( void ) const;

protected:
	template< class T >
	Shared<T> sharedFromThis( void )
	{
		return Shared<T>( this );
	}

protected:
	int _reference_count = 1;
};
>>>>>>> ec1b54020335b76df015817be9eeaa46104a0857:source/magical-common/src/common/Reference.h



#endif //__REFERENCE_H__
