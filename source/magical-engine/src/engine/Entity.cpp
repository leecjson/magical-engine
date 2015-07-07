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
#include "Renderer.h"

NAMESPACE_MAGICAL

Entity::Entity( void )
{
	m_feature = Entity::Feature;

	m_vbo = Renderer::newVertexBufferObject();
	m_vbo->alloc( 24, VertexBufferObject::Separate );

	m_vbo->enable( Shader::Attribute::iVertex, 3, Shader::TFloat, false, nullptr, VboUsage::StaticDraw );
	m_vbo->edit();
	m_vbo->vertex3f( -0.5f, -0.5f, -0.5f ); m_vbo->vertex3f( 0.5f, -0.5f, -0.5f ); m_vbo->vertex3f( 0.5f, 0.5f, -0.5f ); m_vbo->vertex3f( -0.5f, 0.5f, -0.5f );
	m_vbo->vertex3f( -0.5f, 0.5f, -0.5f ); m_vbo->vertex3f( 0.5f, 0.5f, -0.5f ); m_vbo->vertex3f( 0.5f, 0.5f, 0.5f ); m_vbo->vertex3f( -0.5f, 0.5f, 0.5f );
	m_vbo->vertex3f( -0.5f, -0.5f, 0.5f ); m_vbo->vertex3f( -0.5f, 0.5f, 0.5f ); m_vbo->vertex3f( 0.5f, 0.5f, 0.5f ); m_vbo->vertex3f( 0.5f, -0.5f, 0.5f );
	m_vbo->vertex3f( -0.5f, -0.5f, -0.5f ); m_vbo->vertex3f( -0.5f, -0.5f, 0.5f ); m_vbo->vertex3f( 0.5f, -0.5f, 0.5f ); m_vbo->vertex3f( 0.5f, -0.5f, -0.5f );
	m_vbo->vertex3f( -0.5f, -0.5f, 0.5f ); m_vbo->vertex3f( -0.5f, -0.5f, -0.5f ); m_vbo->vertex3f( -0.5f, 0.5f, -0.5f ); m_vbo->vertex3f( -0.5f, 0.5f, 0.5f );
	m_vbo->vertex3f( 0.5f, -0.5f, 0.5f ); m_vbo->vertex3f( 0.5f, 0.5f, 0.5f ); m_vbo->vertex3f( 0.5f, 0.5f, -0.5f ); m_vbo->vertex3f( 0.5f, -0.5f, -0.5f );
	m_vbo->commit();

	Color4b colors[24] = {
		Color4b::Red, Color4b::Red, Color4b::Red, Color4b::Red, //font
		Color4b::Black, Color4b::Black, Color4b::Black, Color4b::Black, //top
		Color4b::Pink, Color4b::Pink, Color4b::Pink, Color4b::Pink,  //back
		Color4b::Blue, Color4b::Blue, Color4b::Blue, Color4b::Blue, //bottom
		Color4b::Brown, Color4b::Brown, Color4b::Brown, Color4b::Brown, //left
		Color4b::Cyan, Color4b::Cyan, Color4b::Cyan, Color4b::Cyan //right
	};
	m_vbo->enable( Shader::Attribute::iColor, 4, Shader::TUByte, true, colors, VboUsage::StaticDraw );

	m_command.setShape( Shapes::Quads );
	m_command.setProgram( Shader::Diffuse );
	m_command.setVertexBufferObject( m_vbo );
	m_command.setPreDrawProcess( MAGICAL_CALLBACK_1( &Entity::process, this ) );
}

Entity::~Entity( void )
{
	for( const auto& itr : m_behaviours )
	{
		itr.second->onDestroy();
		itr.second->release();
	}

	if( m_vbo )
		Renderer::deleteVertexBufferObject( m_vbo );
}

Ptr<Entity> Entity::create( void )
{
	Entity* ret = new Entity();
	MAGICAL_ASSERT( ret, "new Entity() failed" );
	return Ptr<Entity>( Ptrctor<Entity>( ret ) );
}

Ptr<Entity> Entity::create( const char* name )
{
	Entity* ret = new Entity();
	MAGICAL_ASSERT( ret, "new Entity() failed" );
	ret->setName( name );
	return Ptr<Entity>( Ptrctor<Entity>( ret ) );
}

void Entity::visit( void )
{
	if( m_visible == false )
		return;

	// frustum cull check
	/*if( camera->isFrustumCullEnabled() )
	{
		
	}*/

	Renderer::addCommand( &m_command );

	if( !m_children.empty() )
	{
		for( auto child : m_children )
		{
			child->visit();
		}
	}
}

void Entity::start( void ) 
{
	for( const auto& itr : m_behaviours )
		itr.second->onStart();

	Object::start();
}

void Entity::stop( void )
{
	for( const auto& itr : m_behaviours )
		itr.second->onStop();

	Object::stop();
}

void Entity::prepare( void )
{

}

void Entity::update( void )
{
	for( const auto& itr : m_behaviours )
		itr.second->onUpdate();
}

void Entity::process( ShaderProgram* program )
{
	Camera* camera = m_root_scene->getVisitingCamera();

	int location = program->getUniformLocation( Shader::Uniform::MvpMatrix );
	Matrix4x4 mvp = getLocalToWorldMatrix() * camera->getViewProjectionMatrix();
	program->uniform4x4f( location, 1, false, (Shader::float_t*)( &mvp ) );
}


NAMESPACE_END