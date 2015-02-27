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
#include "Entity.h"
#include "Scene.h"

#include "ShaderProgram.h"
#include "Renderer.h"
#include "win32/gl/glew/glew.h"

NS_MAGICAL_BEGIN

Entity::Entity( void )
{
	m_element_enum = Element::Entity;
}

Entity::~Entity( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onDestroy();
		itr.second->release();
	}
}

Ptr<Entity> Entity::create( void )
{
	Entity* ret = new Entity();
	magicalAssert( ret, "new Entity() failed" );
	return Ptr<Entity>( PtrCtor<Entity>( ret ) );
}

Ptr<Entity> Entity::create( const char* name )
{
	Entity* ret = new Entity();
	magicalAssert( ret, "new Entity() failed" );
	ret->setName( name );
	return Ptr<Entity>( PtrCtor<Entity>( ret ) );
}

void Entity::visit( Camera* camera )
{
	if( !m_visible )
		return;

	if( m_element_enum == Element::Camera )
	{
		if( !m_children.empty() )
		{
			for( auto child : m_children )
			{
				child->visit( camera );
			}
		}
		return;
	}

	glUseProgram( s_flat_program->getId() );

	Matrix4 mvp_matrix = getLocalToWorldMatrix() * camera->getViewProjectionMatrix();

	GLint u_mvp_matrix = s_flat_program->getUniformLocation( "u_mvp_matrix" );
	glUniformMatrix4fv( u_mvp_matrix, 1, GL_FALSE, (GLfloat*)&mvp_matrix );

	/*Color4f colors[4] = {
		Color4f::Pink,
		Color4f::Yello,
		Color4f::Green,
		Color4f::Red };

	glEnableVertexAttribArray( kAttrVertexIndex );
	glEnableVertexAttribArray( kAttrColorIndex );
	glVertexAttribPointer( kAttrVertexIndex, 3, GL_FLOAT, GL_FALSE, 0, &rect_triangle );
	glVertexAttribPointer( kAttrColorIndex, 4, GL_FLOAT, GL_FALSE, 0, colors );
	glDrawArrays( GL_TRIANGLE_STRIP, 0, 4 );*/

	Color4f colors[24] = { 
		Color4f::Red, Color4f::Red, Color4f::Red, Color4f::Red, //font
		Color4f::Black, Color4f::Black, Color4f::Black, Color4f::Black, //top
		Color4f::Pink, Color4f::Pink, Color4f::Pink, Color4f::Pink,  //back
		Color4f::Blue, Color4f::Blue, Color4f::Blue, Color4f::Blue, //bottom
		Color4f::Brown, Color4f::Brown, Color4f::Brown, Color4f::Brown, //left
		Color4f::Cyan, Color4f::Cyan, Color4f::Cyan, Color4f::Cyan //right
	};

	glEnableVertexAttribArray( kAttrVertexIndex );
	glEnableVertexAttribArray( kAttrColorIndex );
	glVertexAttribPointer( kAttrVertexIndex, 3, GL_FLOAT, GL_FALSE, 0, &cube );
	glVertexAttribPointer( kAttrColorIndex, 4, GL_FLOAT, GL_FALSE, 0, colors );
	glDrawArrays( GL_QUADS, 0, 24 );

	if( !m_children.empty() )
	{
		for( auto child : m_children )
		{
			child->visit( camera );
		}
	}
}

//void Entity::draw( void )
//{
//	glUseProgram( s_flat_program->getId() );
//}

void Entity::prepare( void )
{

}

void Entity::start( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onStart();
	}
	SceneObject::start();
}

void Entity::stop( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onStop();
	}
	SceneObject::stop();
}

void Entity::update( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onUpdate();
	}
}


NS_MAGICAL_END