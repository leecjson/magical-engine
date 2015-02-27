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
#include "RendererCommon.h"

MAGICALAPI bool magicalGetShaderInfoLog( GLuint shader )
{
	char* info_log;
	GLint info_length;
	glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &info_length );

	info_log = (char*) malloc( info_length );
	glGetShaderInfoLog( shader, info_length, &info_length, info_log );

	if( info_log == nullptr )
		return false;

	magicalFormat( "%s", info_log );
	free( info_log );
	return true;
}

MAGICALAPI bool magicalGetProgramInfoLog( GLuint program )
{
	char* info_log;
	GLint info_length;
	glGetProgramiv( program, GL_INFO_LOG_LENGTH, &info_length );

	info_log = (char*) malloc( info_length );
	glGetProgramInfoLog( program, info_length, &info_length, info_log );

	if( info_log == nullptr )
		return false;

	magicalFormat( "%s", info_log );
	free( info_log );
	return true;
}