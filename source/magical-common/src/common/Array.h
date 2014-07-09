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
#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <vector>
#include <memory>

#include "PlatformMacros.h"
#include "Common.h"
#include "Object.h"

//template< __type >
//class Array_t< __type >;

//template< __type >
//typedef std::shared_ptr< Array_t< __type > > Array;
//template< __type >
//typedef std::shared_ptr<const Array_t< __type > > const_Array;


#define Array( __type ) std::shared_ptr< Array_t< __type > >

template< class __type >
class Array_t
{
public:
	Array_t()
	{
		Array(Object) sds = Array(Object);
		
	};
	virtual ~Array_t()
	{
	
	};

private:
	//std::vector< __type > _data;
};

//template<class T> struct Alloc { /* ... */ }; 
//template<class T>  using Vec = std::vector<T, Alloc<T>>;



//typedef std::shared_ptr< Array_t > Array;



#endif //__ARRAY_H__