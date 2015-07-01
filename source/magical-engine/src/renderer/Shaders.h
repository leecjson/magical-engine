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
#include "RenderDefine.h"

NAMESPACE_MAGICAL

class ShaderProgram;

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
			case TBool: return Shader::Sizeof_bool_t;
			case TByte: return Shader::Sizeof_byte_t;
			case TUByte: return Shader::Sizeof_ubyte_t;
			case TInt: return Shader::Sizeof_int_t;
			case TUInt: return Shader::Sizeof_uint_t;
			case TFloat: return Shader::Sizeof_float_t;
			case TNone: default: MAGICAL_ASSERT( false, "Invalid!" ); return 0;
		}
	}

public:
	struct Attribute
	{
		enum : unsigned int 
		{
			iVertex = 1,
			iColor = 2,
			iTexCoord = 3,
			iNormal = 4,
		};

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
	static ShaderProgram* Diffuse;

	struct Source
	{
		static const char* DiffuseVert;
		static const char* DiffuseFrag;
	};

public:
	static void init( void );
	static void delc( void );
};

NAMESPACE_END


#endif //__SHADERS_H__