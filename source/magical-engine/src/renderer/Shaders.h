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
	struct AttribLocation 
	{
		enum : int
		{
			iVertex,
			iColor,
			iTextureCoord,
			iNormal,
		};

		static const char* Vertex;
		static const char* Color;
		static const char* TextureCoord;
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