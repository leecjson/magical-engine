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
#include "Shaders.h"

NAMESPACE_MAGICAL

class Batch
{
public:
	Batch( void );
	~Batch( void );

public:
	void beginCopyData( unsigned short location, size_t sizeof_vertex, size_t vertex_count, size_t indices_count = 0 );
	void endCopyData( void );

public:
	inline void copyBool( const Shader::Inner::bool_t data );
	inline void copyBool2( const Shader::Inner::bool2_t data );
	inline void copyBool3( const Shader::Inner::bool3_t data );
	inline void copyBool4( const Shader::Inner::bool4_t data );

public:
	inline void copyInt( const Shader::Inner::int_t data );
	inline void copyInt2( const Shader::Inner::int2_t data );
	inline void copyInt3( const Shader::Inner::int3_t data );
	inline void copyInt4( const Shader::Inner::int4_t data );

public:
	inline void copyFloat( const Shader::Inner::float_t data );
	inline void copyFloat2( const Shader::Inner::float2_t data );
	inline void copyFloat3( const Shader::Inner::float3_t data );
	inline void copyFloat4( const Shader::Inner::float4_t data );

public:
	inline void copyIndex( unsigned int index );
	
protected:
	unsigned short m_location = 0;
	char* m_vertexes = nullptr;
	size_t m_vertexes_count = 0;
	size_t m_vertexes_cursor = 0;
	unsigned int* m_indices = nullptr;
	size_t m_indices_count = 0;
	size_t m_indices_cursor = 0;
};

NAMESPACE_END

#include "Batch.inl"

#endif //__BATCH_H__