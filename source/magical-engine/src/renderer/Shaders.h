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
		Simple,
		Flat,
		Count
	};

public:
	struct Inner
	{
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
	};

public:
	struct Attribute
	{
		enum : unsigned short
		{
			iVertex    = 1 << 0x0,
			iColor     = 1 << 0x1,
			iNormal    = 1 << 0x2,
			iTexCoord  = 1 << 0x3,
			iUnused1   = 1 << 0x4,
			iUnused2   = 1 << 0x5,
			iUnused3   = 1 << 0x6,
			iUnused4   = 1 << 0x7,
			iAttrib1   = 1 << 0x8,
			iAttrib2   = 1 << 0x9,
			iAttrib3   = 1 << 0xA,
			iAttrib4   = 1 << 0xB,
			iAttrib5   = 1 << 0xC,
			iAttrib6   = 1 << 0xD,
			iAttrib7   = 1 << 0xE,
			iAttrib8   = 1 << 0xF,
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
	struct Source
	{
		static const char* SimpleVertex;
		static const char* SimplePiexl;
		static const char* FlatVertex;
		static const char* FlatPiexl;
	};

public:
	static void init( void );
	static void delc( void );

public:
	static ShaderProgram* getProgram( int index );
};

NAMESPACE_END


#endif //__SHADERS_H__