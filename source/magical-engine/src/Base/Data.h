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

#include "magical-macros.h"
#include "Common.h"
#include "Reference.h"

NS_MAGICAL_BEGIN
 
class Data : public Reference
{
public:
	member_method Data( void );
	member_method virtual ~Data( void );
	static_method Ptr<Data> Create( void );
	static_method Ptr<Data> Create( size_t size );
	static_method Ptr<Data> Create( char* data, size_t size );

public:
	member_method void Assign( char* data, size_t size );
	member_method void Malloc( size_t size );
	member_method void Realloc( size_t size );
	member_method void Free( void );
	member_method bool Empty( void ) const;
	member_method size_t Size( void ) const;
	member_method char* CPtr( void ) const;

private:
	char* m_data = nullptr;
	size_t m_size = 0;
};

NS_MAGICAL_END

#endif //__DATA_H__