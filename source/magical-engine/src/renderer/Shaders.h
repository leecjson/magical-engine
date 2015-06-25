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
#ifndef __SHADERS_H__
#define __SHADERS_H__

#include "magical-macros.h"
#include "Common.h"
#include "Reference.h"
#include "ShaderProgram.h"

NAMESPACE_MAGICAL

class Shader
{
public:
	enum : int
	{
#ifdef MAGICAL_USING_GL
		TNone = GL_ZERO,
		TBool = GL_BOOL,
		TByte = GL_BYTE,
		TUByte = GL_UNSIGNED_BYTE,
		TInt = GL_INT,
		TUInt = GL_UNSIGNED_INT,
		TFloat = GL_FLOAT,
#endif
	};

	typedef bool bool_t;
	typedef char byte_t;
	typedef unsigned char ubyte_t;
	typedef int int_t;
	typedef unsigned uint_t;
	typedef float float_t;

	enum : size_t
	{
		Sizeof_bool_t = sizeof( bool_t ),
		Sizeof_byte_t = sizeof( byte_t ),
		Sizeof_ubyte_t = sizeof( ubyte_t ),
		Sizeof_int_t = sizeof( int_t ),
		Sizeof_uint_t = sizeof( uint_t ),
		Sizeof_float_t = sizeof( float_t ),
	};

	static inline size_t sizeof_id( int type )
	{
		switch( type )
		{
			case TBool:
				return Shader::Sizeof_bool_t;
			case TByte:
				return Shader::Sizeof_byte_t;
			case TUByte:
				return Shader::Sizeof_ubyte_t;
			case TInt:
				return Shader::Sizeof_int_t;
			case TUInt:
				return Shader::Sizeof_uint_t;
			case TFloat:
				return Shader::Sizeof_float_t;
			case TNone:
			default:
				MAGICAL_ASSERT( false, "Invalid!" ); return 0;
		}
	}

public:
	struct Attribute
	{
		enum : unsigned int
		{
			iColor3f   = 1 << 0x00,
			iColor4f   = 1 << 0x01,
			iVertex2f  = 1 << 0x02,
			iVertex3f  = 1 << 0x03,
			iVertex4f  = 1 << 0x04,
			iNormal3f  = 1 << 0x05,
			iTexCoord  = 1 << 0x06,
			i______0   = 1 << 0x07,
			i______1   = 1 << 0x08,
			i______2   = 1 << 0x09,
			i______3   = 1 << 0x0A,
			i______4   = 1 << 0x0B,
			i______5   = 1 << 0x0C,
			i______6   = 1 << 0x0D,
			i______7   = 1 << 0x0E,
			i______8   = 1 << 0x0F,
			iAttrib0   = 1 << 0x10,
			iAttrib1   = 1 << 0x11,
			iAttrib2   = 1 << 0x12,
			iAttrib3   = 1 << 0x13,
			iAttrib4   = 1 << 0x14,
			iAttrib5   = 1 << 0x15,
			iAttrib6   = 1 << 0x16,
			iAttrib7   = 1 << 0x17,
			iAttrib8   = 1 << 0x18,
			iAttrib9   = 1 << 0x19,
			iAttribA   = 1 << 0x1A,
			iAttribB   = 1 << 0x1B,
			iAttribC   = 1 << 0x1C,
			iAttribD   = 1 << 0x1D,
			iAttribE   = 1 << 0x1E,
			iAttribF   = 1 << 0x1F,
			Count = 32, Invalid = -1,
		};
		static unsigned int findArrIndex( unsigned int index );

		static const char* Vertex;
		static const char* Color;
		static const char* TexCoord;
		static const char* Normal;
	};

public:
	struct Uniform
	{
		static const char* Color;
		static const char* MvpMatrix;
		static const char* MvMatrix;
		static const char* PMatrix;
		static const char* TexUnit0;
	};

public:
	struct Simple
	{
		static const char* Vert;
		static const char* Frag;
		static const int Idx = 0;
	};

	struct Flat
	{
		static const char* Vert;
		static const char* Frag;
		static const int Idx = 1;
	};

	enum : int { Count = 2 };

public:
	static void init( void );
	static void delc( void );

public:
	static ShaderProgram* getProgram( int index );
};

NAMESPACE_END


#endif //__SHADERS_H__