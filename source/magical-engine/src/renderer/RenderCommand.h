﻿/******************************************************************************
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
#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "magical-macros.h"
#include "magical-math.h"
#include "Common.h"
#include "RenderCommon.h"
#include "Reference.h"

NAMESPACE_MAGICAL

class RenderCommand
{ 
public:
	enum
	{
		Invalid = -1,
		Triangle,
	};

public:
	RenderCommand( void );
	virtual ~RenderCommand( void );
};

enum class VertexInnerData
{
	iV3f_C4b_T2f
};

class TriangleCommand : public RenderCommand
{
public:
	TriangleCommand( void );
	virtual ~TriangleCommand( void );

public:
	void beginCopyData( size_t vertexes_size, size_t indices_size );
	void copyData( const Vector3& vertex, const Color4b& color, const Vector2& texcoord );
	void copyIndex( uint32_t index );
	void endCopyData( void );
	
protected:
	V3f_C4b_T2f* m_vertexes = nullptr;
	size_t m_vertexes_index = 0;
	size_t m_vertexes_size = 0;

protected:
	uint32_t* m_indices = nullptr;
	size_t m_indices_index = 0;
	size_t m_indices_size = 0;
};

NAMESPACE_END

#endif //__RENDERER_H__
