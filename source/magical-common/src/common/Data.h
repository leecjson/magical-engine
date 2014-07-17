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
#ifndef __DATA_H__
#define __DATA_H__

#include "PlatformMacros.h"
<<<<<<< HEAD
#include "Object.h"

class Data_t;

typedef std::shared_ptr<Data_t> Data;
typedef std::shared_ptr<const Data_t> const_Data;
<<<<<<< HEAD
#define newObject() (std::move(Data(new Object_t())))
#define newObject_LuaGC() (new Data(new Object_t()))

class Data_t : public Object_t
{
public:
	Data_t( void );
	virtual ~Data_t( void );

public:
	void malloc( const size_t t );

private:
	char* _data;
};


=======

class Data_t : public Object_t
=======
#include "Common.h"
#include "Reference.h"

class Data : public Reference
>>>>>>> ec1b54020335b76df015817be9eeaa46104a0857
{
public:
	Data( void );
	virtual ~Data( void );

public:
	static Shared<Data> createShared( void );
	static Data* create( void );

public:
	void assign( char* data, const size_t size );
	void malloc( const size_t size );
	void realloc( const size_t size );
	bool empty( void ) const;
	size_t size( void ) const;
	char* ptr( void ) const;

private:
	char* _data = nullptr;
	size_t _size = 0;
};

<<<<<<< HEAD
static inline Data newData( void )
{
	Data_t* obj = new Data_t();
	magicalAssert( obj, "new Data_t();" );
	return std::move( Data(obj) );
}

static inline Data* newData_LuaGC( void )
{
	Data_t* obj = new Data_t();
	magicalAssert( obj, "new Data_t();" );
	Data* ret = new Data( obj );
	magicalAssert( ret, "new Data( obj );" );
	return ret;
}

>>>>>>> origin/master
=======
>>>>>>> ec1b54020335b76df015817be9eeaa46104a0857
#endif //__DATA_H__