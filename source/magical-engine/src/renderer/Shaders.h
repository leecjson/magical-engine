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
	typedef bool bool_t;
	typedef bool bool2_t[2];
	typedef bool bool3_t[3];
	typedef bool bool4_t[4];

	enum : size_t
	{
		Sizeof_bool_t = sizeof( bool_t ),
		Sizeof_bool2_t = sizeof( bool2_t ),
		Sizeof_bool3_t = sizeof( bool3_t ),
		Sizeof_bool4_t = sizeof( bool4_t ),
	};

	typedef int int_t;
	typedef int int2_t[2];
	typedef int int3_t[3];
	typedef int int4_t[4];

	enum : size_t
	{
		Sizeof_int_t = sizeof( int_t ),
		Sizeof_int2_t = sizeof( int2_t ),
		Sizeof_int3_t = sizeof( int3_t ),
		Sizeof_int4_t = sizeof( int4_t ),
	};

	typedef float float_t;
	typedef float float2_t[2];
	typedef float float3_t[3];
	typedef float float4_t[4];

	enum : size_t
	{
		Sizeof_float_t = sizeof( float_t ),
		Sizeof_float2_t = sizeof( float2_t ),
		Sizeof_float3_t = sizeof( float3_t ),
		Sizeof_float4_t = sizeof( float4_t ),
	};

	typedef float float2x2_t[4];
	typedef float float3x3_t[9];
	typedef float float3x4_t[12];
	typedef float float4x3_t[12];
	typedef float float4x4_t[16];

	enum : size_t
	{
		Sizeof_float2x2_t = sizeof( float2x2_t ),
		Sizeof_float3x3_t = sizeof( float3x3_t ),
		Sizeof_float3x4_t = sizeof( float3x4_t ),
		Sizeof_float4x3_t = sizeof( float4x3_t ),
		Sizeof_float4x4_t = sizeof( float4x4_t ),
	};

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
			i_______   = 1 << 0x07,
			i_______   = 1 << 0x08,
			i_______   = 1 << 0x09,
			i_______   = 1 << 0x0A,
			i_______   = 1 << 0x0B,
			i_______   = 1 << 0x0C,
			i_______   = 1 << 0x0D,
			i_______   = 1 << 0x0E,
			i_______   = 1 << 0x0F,
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
		static const unsigned int findArrIndex( unsigned int index );

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