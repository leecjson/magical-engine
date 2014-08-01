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
#include "MatrixStack.h"
#include <vector>

static std::vector<Mat4> s_modelview_stack;
static std::vector<Mat4> s_projection_stack;
static std::vector<Mat4>* s_select_stack = nullptr;

void MatrixStack::init( void )
{
	s_modelview_stack.reserve(30);
	s_projection_stack.reserve(5);

	resetAll();
	use( kProjection );
}

void MatrixStack::delc( void )
{
	s_modelview_stack.clear();
	s_projection_stack.clear();
	s_select_stack = nullptr;
}

void MatrixStack::use( MatrixStackMode mode )
{
	switch( mode )
	{
	case kModelView:
		s_select_stack = &s_modelview_stack;
		break;
	case kProjection:
		s_select_stack = &s_projection_stack;
		break;
	}
}

void MatrixStack::reset( void )
{
	s_select_stack->clear();
	s_select_stack->push_back( Mat4::IDENTITY );
}

void MatrixStack::resetAll( void )
{
	s_modelview_stack.clear();
	s_modelview_stack.push_back( Mat4::IDENTITY );
	s_projection_stack.clear();
	s_projection_stack.push_back( Mat4::IDENTITY );
}

void MatrixStack::push( void )
{
	s_select_stack->push_back( s_select_stack->back() );
}

void MatrixStack::pop( void )
{
	s_select_stack->pop_back();
}

void MatrixStack::identity( void )
{
	s_select_stack->back() = Mat4::IDENTITY;
}

void MatrixStack::load( const Mat4& mat )
{
	s_select_stack->back() = mat;
}

void MatrixStack::multiply( const Mat4& mat )
{
	s_select_stack->back() *= mat;
}

Mat4 MatrixStack::get( void )
{
	return s_select_stack->back();
}