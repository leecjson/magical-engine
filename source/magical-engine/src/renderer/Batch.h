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
#ifndef __BATCH_H__
#define __BATCH_H__

#include "magical-macros.h"
#include "magical-math.h"
#include "Common.h"

NAMESPACE_MAGICAL

class Batch
{
public:
	Batch( void );
	~Batch( void );

public:
	void beginCopyData( unsigned short attr, size_t size );
	void copyVector2( const Vector2& v );
	void copyVector3( const Vector3& v );
	void copyVector4( const Vector4& v );
	void copyIndex( uint32_t index );
	void endCopyData( void );

protected:
	unsigned short m_attr = 0;
	char* m_vertexes = nullptr;
	size_t m_vertexes_size = 0;
	unsigned int* m_indices = nullptr;
	size_t m_indices_size = 0;
};

NAMESPACE_END

#endif //__BATCH_H__