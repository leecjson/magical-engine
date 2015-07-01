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

inline void VertexBufferObject::vertex1b( Shader::byte_t x )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TByte && m_bound_vertex_buf->size == 1, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 1 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::byte_t* data = (Shader::byte_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = x;
				m_bound_vertex_buf->cursor += 1;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + Shader::Sizeof_byte_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, &x, Shader::Sizeof_byte_t );
				m_combine_vertex_buf->bytecursor += Shader::Sizeof_byte_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex2b( Shader::byte_t x, Shader::byte_t y )
{
	const Shader::byte_t v[2] = { x, y }; vertex2bv( v );
}

inline void VertexBufferObject::vertex3b( Shader::byte_t x, Shader::byte_t y, Shader::byte_t z )
{
	const Shader::byte_t v[3] = { x, y, z }; vertex3bv( v );
}

inline void VertexBufferObject::vertex4b( Shader::byte_t x, Shader::byte_t y, Shader::byte_t z, Shader::byte_t w )
{
	const Shader::byte_t v[4] = { x, y, z, w }; vertex4bv( v );
}

inline void VertexBufferObject::vertex2bv( const Shader::byte_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TByte && m_bound_vertex_buf->size == 2, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 2 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::byte_t* data = (Shader::byte_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				m_bound_vertex_buf->cursor += 2;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 2 * Shader::Sizeof_byte_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 2 * Shader::Sizeof_byte_t );
				m_combine_vertex_buf->bytecursor += 2 * Shader::Sizeof_byte_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex3bv( const Shader::byte_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TByte && m_bound_vertex_buf->size == 3, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 3 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::byte_t* data = (Shader::byte_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				data[ m_bound_vertex_buf->cursor + 2 ] = v[2];
				m_bound_vertex_buf->cursor += 3;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 3 * Shader::Sizeof_byte_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 3 * Shader::Sizeof_byte_t );
				m_combine_vertex_buf->bytecursor += 3 * Shader::Sizeof_byte_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex4bv( const Shader::byte_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TByte && m_bound_vertex_buf->size == 4, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 4 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::byte_t* data = (Shader::byte_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				data[ m_bound_vertex_buf->cursor + 2 ] = v[2];
				data[ m_bound_vertex_buf->cursor + 3 ] = v[3];
				m_bound_vertex_buf->cursor += 4;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 4 * Shader::Sizeof_byte_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 4 * Shader::Sizeof_byte_t );
				m_combine_vertex_buf->bytecursor += 4 * Shader::Sizeof_byte_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex1ub( Shader::ubyte_t x )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TUByte && m_bound_vertex_buf->size == 1, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 1 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::ubyte_t* data = (Shader::ubyte_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = x;
				m_bound_vertex_buf->cursor += 1;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + Shader::Sizeof_ubyte_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, &x, Shader::Sizeof_ubyte_t );
				m_combine_vertex_buf->bytecursor += Shader::Sizeof_ubyte_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex2ub( Shader::ubyte_t x, Shader::ubyte_t y )
{
	const Shader::ubyte_t v[2] = { x, y }; vertex2ubv( v );
}

inline void VertexBufferObject::vertex3ub( Shader::ubyte_t x, Shader::ubyte_t y, Shader::ubyte_t z )
{
	const Shader::ubyte_t v[3] = { x, y, z }; vertex3ubv( v );
}

inline void VertexBufferObject::vertex4ub( Shader::ubyte_t x, Shader::ubyte_t y, Shader::ubyte_t z, Shader::ubyte_t w )
{
	const Shader::ubyte_t v[4] = { x, y, z, w }; vertex4ubv( v );
}

inline void VertexBufferObject::vertex2ubv( const Shader::ubyte_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TUByte && m_bound_vertex_buf->size == 2, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 2 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::ubyte_t* data = (Shader::ubyte_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				m_bound_vertex_buf->cursor += 2;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 2 * Shader::Sizeof_ubyte_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 2 * Shader::Sizeof_ubyte_t );
				m_combine_vertex_buf->bytecursor += 2 * Shader::Sizeof_ubyte_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex3ubv( const Shader::ubyte_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TUByte && m_bound_vertex_buf->size == 3, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 3 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::ubyte_t* data = (Shader::ubyte_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				data[ m_bound_vertex_buf->cursor + 2 ] = v[2];
				m_bound_vertex_buf->cursor += 3;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 3 * Shader::Sizeof_ubyte_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 3 * Shader::Sizeof_ubyte_t );
				m_combine_vertex_buf->bytecursor += 3 * Shader::Sizeof_ubyte_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex4ubv( const Shader::ubyte_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TUByte && m_bound_vertex_buf->size == 4, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 4 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::ubyte_t* data = (Shader::ubyte_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				data[ m_bound_vertex_buf->cursor + 2 ] = v[2];
				data[ m_bound_vertex_buf->cursor + 3 ] = v[3];
				m_bound_vertex_buf->cursor += 4;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 4 * Shader::Sizeof_ubyte_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 4 * Shader::Sizeof_ubyte_t );
				m_combine_vertex_buf->bytecursor += 4 * Shader::Sizeof_ubyte_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex1i( Shader::int_t x )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TInt && m_bound_vertex_buf->size == 1, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 1 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::int_t* data = (Shader::int_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = x;
				m_bound_vertex_buf->cursor += 1;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + Shader::Sizeof_int_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, &x, Shader::Sizeof_int_t );
				m_combine_vertex_buf->bytecursor += Shader::Sizeof_int_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex2i( Shader::int_t x, Shader::int_t y )
{
	const Shader::int_t v[2] = { x, y }; vertex2iv( v );
}

inline void VertexBufferObject::vertex3i( Shader::int_t x, Shader::int_t y, Shader::int_t z )
{
	const Shader::int_t v[3] = { x, y, z }; vertex3iv( v );
}

inline void VertexBufferObject::vertex4i( Shader::int_t x, Shader::int_t y, Shader::int_t z, Shader::int_t w )
{
	const Shader::int_t v[4] = { x, y, z, w }; vertex4iv( v );
}

inline void VertexBufferObject::vertex2iv( const Shader::int_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TInt && m_bound_vertex_buf->size == 2, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 2 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::int_t* data = (Shader::int_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				m_bound_vertex_buf->cursor += 2;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 2 * Shader::Sizeof_int_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 2 * Shader::Sizeof_int_t );
				m_combine_vertex_buf->bytecursor += 2 * Shader::Sizeof_int_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex3iv( const Shader::int_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TInt && m_bound_vertex_buf->size == 3, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 3 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::int_t* data = (Shader::int_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				data[ m_bound_vertex_buf->cursor + 2 ] = v[2];
				m_bound_vertex_buf->cursor += 3;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 3 * Shader::Sizeof_int_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 3 * Shader::Sizeof_int_t );
				m_combine_vertex_buf->bytecursor += 3 * Shader::Sizeof_int_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex4iv( const Shader::int_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TInt && m_bound_vertex_buf->size == 4, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 4 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::int_t* data = (Shader::int_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				data[ m_bound_vertex_buf->cursor + 2 ] = v[2];
				data[ m_bound_vertex_buf->cursor + 3 ] = v[3];
				m_bound_vertex_buf->cursor += 4;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 4 * Shader::Sizeof_int_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 4 * Shader::Sizeof_int_t );
				m_combine_vertex_buf->bytecursor += 4 * Shader::Sizeof_int_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex1ui( Shader::uint_t x )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TUInt && m_bound_vertex_buf->size == 1, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 1 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::uint_t* data = (Shader::uint_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = x;
				m_bound_vertex_buf->cursor += 1;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + Shader::Sizeof_uint_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, &x, Shader::Sizeof_uint_t );
				m_combine_vertex_buf->bytecursor += Shader::Sizeof_uint_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex2ui( Shader::uint_t x, Shader::uint_t y )
{
	const Shader::uint_t v[2] = { x, y }; vertex2uiv( v );
}

inline void VertexBufferObject::vertex3ui( Shader::uint_t x, Shader::uint_t y, Shader::uint_t z )
{
	const Shader::uint_t v[3] = { x, y, z }; vertex3uiv( v );
}

inline void VertexBufferObject::vertex4ui( Shader::uint_t x, Shader::uint_t y, Shader::uint_t z, Shader::uint_t w )
{
	const Shader::uint_t v[4] = { x, y, z, w }; vertex4uiv( v );
}

inline void VertexBufferObject::vertex2uiv( const Shader::uint_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TUInt && m_bound_vertex_buf->size == 2, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 2 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::uint_t* data = (Shader::uint_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				m_bound_vertex_buf->cursor += 2;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 2 * Shader::Sizeof_uint_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 2 * Shader::Sizeof_uint_t );
				m_combine_vertex_buf->bytecursor += 2 * Shader::Sizeof_uint_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex3uiv( const Shader::uint_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TUInt && m_bound_vertex_buf->size == 3, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 3 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::uint_t* data = (Shader::uint_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				data[ m_bound_vertex_buf->cursor + 2 ] = v[2];
				m_bound_vertex_buf->cursor += 3;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 3 * Shader::Sizeof_uint_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 3 * Shader::Sizeof_uint_t );
				m_combine_vertex_buf->bytecursor += 3 * Shader::Sizeof_uint_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex4uiv( const Shader::uint_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TUInt && m_bound_vertex_buf->size == 4, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 4 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::uint_t* data = (Shader::uint_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				data[ m_bound_vertex_buf->cursor + 2 ] = v[2];
				data[ m_bound_vertex_buf->cursor + 3 ] = v[3];
				m_bound_vertex_buf->cursor += 4;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 4 * Shader::Sizeof_uint_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 4 * Shader::Sizeof_uint_t );
				m_combine_vertex_buf->bytecursor += 4 * Shader::Sizeof_uint_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex1f( Shader::float_t x )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TFloat && m_bound_vertex_buf->size == 1, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 1 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::float_t* data = (Shader::float_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = x;
				m_bound_vertex_buf->cursor += 1;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + Shader::Sizeof_float_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, &x, Shader::Sizeof_float_t );
				m_combine_vertex_buf->bytecursor += Shader::Sizeof_float_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex2f( Shader::float_t x, Shader::float_t y )
{
	const Shader::float_t v[2] = { x, y }; vertex2fv( v );
}

inline void VertexBufferObject::vertex3f( Shader::float_t x, Shader::float_t y, Shader::float_t z )
{
	const Shader::float_t v[3] = { x, y, z }; vertex3fv( v );
}

inline void VertexBufferObject::vertex4f( Shader::float_t x, Shader::float_t y, Shader::float_t z, Shader::float_t w )
{
	const Shader::float_t v[4] = { x, y, z, w }; vertex4fv( v );
}

inline void VertexBufferObject::vertex2fv( const Shader::float_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TFloat && m_bound_vertex_buf->size == 2, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 2 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::float_t* data = (Shader::float_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				m_bound_vertex_buf->cursor += 2;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 2 * Shader::Sizeof_float_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 2 * Shader::Sizeof_float_t );
				m_combine_vertex_buf->bytecursor += 2 * Shader::Sizeof_float_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex3fv( const Shader::float_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TFloat && m_bound_vertex_buf->size == 3, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 3 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::float_t* data = (Shader::float_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				data[ m_bound_vertex_buf->cursor + 2 ] = v[2];
				m_bound_vertex_buf->cursor += 3;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 3 * Shader::Sizeof_float_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 3 * Shader::Sizeof_float_t );
				m_combine_vertex_buf->bytecursor += 3 * Shader::Sizeof_float_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

inline void VertexBufferObject::vertex4fv( const Shader::float_t* v )
{
	switch( m_structure )
	{
		case Separate:
			{
				MAGICAL_ASSERT( m_bound_vertex_buf, "Invalid bind!" );
				MAGICAL_ASSERT( m_bound_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_bound_vertex_buf->type == Shader::TFloat && m_bound_vertex_buf->size == 4, "Invalid! type are not equal" );
				MAGICAL_ASSERT( m_bound_vertex_buf->cursor + 4 <= m_bound_vertex_buf->total_size, "Invalid! out of range" );

				Shader::float_t* data = (Shader::float_t*) m_bound_vertex_buf->data;
				data[ m_bound_vertex_buf->cursor ] = v[0];
				data[ m_bound_vertex_buf->cursor + 1 ] = v[1];
				data[ m_bound_vertex_buf->cursor + 2 ] = v[2];
				data[ m_bound_vertex_buf->cursor + 3 ] = v[3];
				m_bound_vertex_buf->cursor += 4;
			}
			break;
		case Combine:
			{
				MAGICAL_ASSERT( m_combine_vertex_buf, "Invalid!" );
				MAGICAL_ASSERT( m_combine_vertex_buf->edit, "Invalid! call edit first" );
				MAGICAL_ASSERT( m_combine_vertex_buf->bytecursor + 4 * Shader::Sizeof_float_t <= m_bound_vertex_buf->total_bytesize, "Invalid! out of range" );

				memcpy( m_combine_vertex_buf->data, v, 4 * Shader::Sizeof_float_t );
				m_combine_vertex_buf->bytecursor += 4 * Shader::Sizeof_float_t;
			}
			break;
		default:
			MAGICAL_ASSERT( false, "Invalid!" );
			break;
	}
}

NAMESPACE_END