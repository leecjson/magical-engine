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
#include "Object.h"
#include "Common.h"

class Data_t;
typedef std::shared_ptr<Data_t> Data;
typedef std::shared_ptr<const Data_t> const_Data;

class Data_t : public Object_t
{
public:
	Data_t( void );
	virtual ~Data_t( void );

public:
	void assign( char* data, const tsize size );
	void malloc( const tsize size );
	void realloc( const tsize size );
	char* data( void ) const;
	bool empty( void ) const;

private:
	char* _data;
	tsize _size;
};

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

#endif //__DATA_H__