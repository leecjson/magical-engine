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

#include "PlatformMacros.h"
#include "Common.h"
#include "Ptr.h"

/*
hash code macros
*/
#define define_class_hash_code( cls ) \
	const size_t cls::HashCode = typeid( cls ).hash_code()
#define declare_class_hash_code \
	static const size_t HashCode
#define assign_class_hash_code() \
	m_class_hash_code = HashCode

NS_MAGICAL_BEGIN

class Reference
{
public:
	Reference( void );
	virtual ~Reference( void );

public:
	void retain( void );
	void release( void );
	unsigned int retainCount( void ) const;
	
	size_t hashCodeOfClass( void ) const;
	template< class Tz >
	inline bool typeof( void ) const
	{
		return m_class_hash_code == Tz::HashCode;
	}

protected:
	unsigned int m_reference = 1;
	size_t m_class_hash_code = 0;
};

NS_MAGICAL_END

#endif //__REFERENCE_H__