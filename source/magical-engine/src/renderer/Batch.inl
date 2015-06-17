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
NAMESPACE_MAGICAL

inline void Batch::copyBool( const Shader::Inner::bool_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_bool_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) &data, Shader::Inner::Sizeof_bool_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_bool_t;
}

inline void Batch::copyBool2( const Shader::Inner::bool2_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_bool2_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) data, Shader::Inner::Sizeof_bool2_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_bool2_t;
}

inline void Batch::copyBool3( const Shader::Inner::bool3_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_bool3_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) data, Shader::Inner::Sizeof_bool3_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_bool3_t;
}

inline void Batch::copyBool4( const Shader::Inner::bool4_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_bool4_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) data, Shader::Inner::Sizeof_bool4_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_bool4_t;
}

inline void Batch::copyInt( const Shader::Inner::int_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_int_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) &data, Shader::Inner::Sizeof_int_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_int_t;
}

inline void Batch::copyInt2( const Shader::Inner::int2_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_int2_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) data, Shader::Inner::Sizeof_int2_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_int2_t;
}

inline void Batch::copyInt3( const Shader::Inner::int3_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_int3_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) data, Shader::Inner::Sizeof_int3_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_int3_t;
}

inline void Batch::copyInt4( const Shader::Inner::int4_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_int4_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) data, Shader::Inner::Sizeof_int4_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_int4_t;
}

inline void Batch::copyFloat( const Shader::Inner::float_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_float_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) &data, Shader::Inner::Sizeof_float_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_float_t;
}

inline void Batch::copyFloat2( const Shader::Inner::float2_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_float2_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) data, Shader::Inner::Sizeof_float2_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_float2_t;
}

inline void Batch::copyFloat3( const Shader::Inner::float3_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_float3_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) data, Shader::Inner::Sizeof_float3_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_float3_t;
}

inline void Batch::copyFloat4( const Shader::Inner::float4_t data )
{
	MAGICAL_ASSERT( m_vertexes, "Invalid! call beginCopyData first!" );
	MAGICAL_ASSERT( m_vertexes_cursor + Shader::Inner::Sizeof_float4_t < m_vertexes_count, "Invalid! out of range" );

	memcpy( m_vertexes + m_vertexes_cursor, (char*) data, Shader::Inner::Sizeof_float4_t );
	m_vertexes_cursor += Shader::Inner::Sizeof_float4_t;
}

inline void Batch::copyIndex( unsigned int index )
{
	MAGICAL_ASSERT( m_indices, "Invalid!" );
	MAGICAL_ASSERT( m_indices_cursor + 1 < m_indices_count, "Invalid! out of range" );

	m_indices[ m_indices_cursor ] = index;
	m_indices_cursor ++;
}

NAMESPACE_END