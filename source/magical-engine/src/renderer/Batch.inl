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

inline void Batch::copy1b( Shader::bool_t x )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_bool_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_bool_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor, (char*) &x, Shader::Sizeof_bool_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_bool_t;
}

inline void Batch::copy2b( Shader::bool_t x, Shader::bool_t y )
{
	const Shader::bool2_t v = { x, y };
	copy2bv( v );
}

inline void Batch::copy3b( Shader::bool_t x, Shader::bool_t y, Shader::bool_t z )
{
	const Shader::bool3_t v = { x, y, z };
	copy3bv( v );
}

inline void Batch::copy4b( Shader::bool_t x, Shader::bool_t y, Shader::bool_t z, Shader::bool_t w )
{
	const Shader::bool4_t v = { x, y, z, w };
	copy4bv( v );
}

inline void Batch::copy2bv( const Shader::bool2_t v )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_bool2_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_bool2_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor * Shader::Sizeof_bool2_t, (char*) v, Shader::Sizeof_bool2_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_bool2_t;
}

inline void Batch::copy3bv( const Shader::bool3_t v )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_bool3_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_bool3_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor * Shader::Sizeof_bool3_t, (char*) v, Shader::Sizeof_bool3_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_bool3_t;
}

inline void Batch::copy4bv( const Shader::bool4_t v )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_bool4_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_bool4_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor * Shader::Sizeof_bool4_t, (char*) v, Shader::Sizeof_bool4_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_bool4_t;
}

inline void Batch::copy1i( Shader::int_t x )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_int_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_int_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor, (char*) &x, Shader::Sizeof_int_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_int_t;
}

inline void Batch::copy2i( Shader::int_t x, Shader::int_t y )
{
	const Shader::int2_t v = { x, y };
	copy2iv( v );
}

inline void Batch::copy3i( Shader::int_t x, Shader::int_t y, Shader::int_t z )
{
	const Shader::int3_t v = { x, y, z };
	copy3iv( v );
}

inline void Batch::copy4i( Shader::int_t x, Shader::int_t y, Shader::int_t z, Shader::int_t w )
{
	const Shader::int4_t v = { x, y, z, w };
	copy4iv( v );
}

inline void Batch::copy2iv( const Shader::int2_t v )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_int2_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_int2_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor, (char*) v, Shader::Sizeof_int2_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_int2_t;
}

inline void Batch::copy3iv( const Shader::int3_t v )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_int3_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_int3_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor, (char*) v, Shader::Sizeof_int3_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_int3_t;
}

inline void Batch::copy4iv( const Shader::int4_t v )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_int4_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_int4_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor, (char*) v, Shader::Sizeof_int4_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_int4_t;
}

inline void Batch::copy1f( Shader::float_t x )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_float_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_float_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor, (char*) &x, Shader::Sizeof_float_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_float_t;
}

inline void Batch::copy2f( Shader::float_t x, Shader::float_t y )
{
	const Shader::float2_t v = { x, y };
	copy2fv( v );
}

inline void Batch::copy3f( Shader::float_t x, Shader::float_t y, Shader::float_t z )
{
	const Shader::float3_t v = { x, y, z };
	copy3fv( v );
}

inline void Batch::copy4f( Shader::float_t x, Shader::float_t y, Shader::float_t z, Shader::float_t w )
{
	const Shader::float4_t v = { x, y, z, w };
	copy4fv( v );
}

inline void Batch::copy2fv( const Shader::float2_t v )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_float2_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_float2_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor, (char*) v, Shader::Sizeof_float2_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_float2_t;
}

inline void Batch::copy3fv( const Shader::float3_t v )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_float3_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_float3_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor, (char*) v, Shader::Sizeof_float3_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_float3_t;
}

inline void Batch::copy4fv( const Shader::float4_t v )
{
	MAGICAL_ASSERT( 0 <= m_bind_vertex_index && m_bind_vertex_index < Shader::Attribute::Count && m_bind_vertex_array, "Invalid! bind vertex index" );
	MAGICAL_ASSERT( m_bind_vertex_array->sizeof_vertex == Shader::Sizeof_float4_t, "Invalid! size not equals" );
	MAGICAL_ASSERT( m_bind_vertex_array->cursor + Shader::Sizeof_float4_t <= m_bind_vertex_array->capacity, "Invalid! out of range" );

	memcpy( m_bind_vertex_array->data + m_bind_vertex_array->cursor, (char*) v, Shader::Sizeof_float4_t );
	m_bind_vertex_array->cursor += Shader::Sizeof_float4_t;
}

inline void Batch::copyIndex( unsigned int index )
{
	MAGICAL_ASSERT( m_indices, "Invalid!" );
	MAGICAL_ASSERT( m_indices_cursor + sizeof( unsigned int ) <= m_indices_capacity, "Invalid! out of range" );

	m_indices[ m_indices_cursor / sizeof( unsigned int ) ] = index;
	m_indices_cursor += sizeof( unsigned int );
}

NAMESPACE_END