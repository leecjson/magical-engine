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
#include "Object.h"
#include "Scene.h"
#include "Camera.h"

NAMESPACE_MAGICAL

Object::Object( void )
{
	
}

Object::~Object( void )
{
	if( !m_children.empty() )
	{
		for( auto child : m_children )
		{
			child->m_parent = nullptr;
			child->release();
		}
		m_children.clear();
	}
}

Ptr<Object> Object::create( void )
{ 
	Object* ret = new Object();
	MAGICAL_ASSERT( ret, "new Object() failed" );
	return Ptr<Object>( Ptrctor<Object>( ret ) );
}

Ptr<Object> Object::create( const char* name )
{
	Object* ret = new Object();
	MAGICAL_ASSERT( ret, "new Object() failed" );
	ret->setName( name );
	return Ptr<Object>( Ptrctor<Object>( ret ) );
}

void Object::setName( const char* name )
{
	MAGICAL_ASSERT( name, "name should not be nullptr" );
	m_name = name;
}

void Object::setVisible( bool visible )
{
	if( visible != m_visible )
	{
		m_visible = visible;
		for( auto child : m_children )
		{
			child->setVisible( visible );
		}
	}
}

bool Object::isChildOf( const Object* parent ) const
{
	MAGICAL_ASSERT( parent, "Invaild! should not be nullptr" );

	Object* itr = m_parent;
	while( itr )
	{
		if( itr == parent )
			return true;

		itr = itr->m_parent;
	}
	return false;
}

Object* Object::findChild( const char* name ) const
{
	MAGICAL_ASSERT( name && *name, "name should not be empty" );
	
	auto ritr = m_children.rbegin();
	for( ; ritr != m_children.rend(); ++ritr )
	{
		Object* child = *ritr;
		if( child->getName() == name )
		{
			return child;
		}
	}
	return nullptr;
}

Object* Object::childAtIndex( size_t i ) const
{
	MAGICAL_ASSERT( i < m_children.size(), "Invaild index!" );
	return m_children[ i ];
}

void Object::addChild( Object* child )
{
	MAGICAL_ASSERT( child, "Invaild! should not be nullptr" );
	MAGICAL_ASSERT( child != this, "Invaild! can't add self as a child" );
	MAGICAL_ASSERT( child->m_parent == nullptr, "Invaild! already has a parent" );

	child->m_parent = this;

	child->retain();
	m_children.push_back( child );
	child->setRootScene( m_root_scene );

	child->start();
	link( child );
}

void Object::setParent( Object* parent )
{
	MAGICAL_ASSERT( parent, "Invaild! should not be nullptr" );
	MAGICAL_ASSERT( parent != this && parent != m_parent, "Invaild!" );
	MAGICAL_ASSERT( parent->isChildOf( this ) == false, "Invaild! own child can't be parent" );

	if( m_parent )
	{
		auto itr = std::find( m_parent->m_children.begin(), m_parent->m_children.end(), this );
		MAGICAL_ASSERT( itr != m_parent->m_children.end(), "Invaild!" );

		Object* lparent = m_parent;
		m_parent = nullptr;
		lparent->m_children.erase( itr );
		lparent->unlink( this );

		m_parent = parent;
		parent->m_children.push_back( this );
		setRootScene( parent->m_root_scene );

		if( parent->m_running )
		{
			this->start();
		}
		else
		{
			this->stop();
		}

		parent->link( this );
	}
	else
	{
		m_parent = parent;

		this->retain();
		parent->m_children.push_back( this );
		setRootScene( parent->m_root_scene );

		if( parent->m_running )
			start();

		parent->link( this );
	}
}

void Object::removeChild( Object* child )
{
	MAGICAL_ASSERT( child, "Invaild! should not be nullptr" );

	auto itr = std::find( m_children.begin(), m_children.end(), child );
	if( itr != m_children.end() )
	{
		child->m_parent = nullptr;
		m_children.erase( itr );
		child->setRootScene( nullptr );

		child->stop();
		unlink( child );

		child->release();
	}
}

void Object::removeChild( const char* name )
{
	MAGICAL_ASSERT( name && *name, "Invaild! should not be nullptr" );

	auto ritr = m_children.begin();
	for( ; ritr != m_children.end(); ++ritr )
	{
		Object* child = *ritr;
		if( child->getName() == name )
		{
			child->m_parent = nullptr;
			m_children.erase( ritr );
			child->setRootScene( nullptr );

			child->stop();
			unlink( child );

			child->release();
			break;
		}
	}
}

void Object::removeAllChildren( void )
{
	if( !m_children.empty() )
	{
		auto children = m_children;
		m_children.clear();

		for( auto child : children )
		{
			child->m_parent = nullptr;
			child->setRootScene( nullptr );
			child->stop();
			unlink( child );
		}

		for( auto child : children )
		{
			child->release();
		}
	}
}

void Object::removeSelf( void )
{
	if( m_parent )
	{
		auto itr = std::find( m_parent->m_children.begin(), m_parent->m_children.end(), this );
		MAGICAL_ASSERT( itr != m_parent->m_children.end(), "Invaild!" );

		Object* parent = m_parent;
		m_parent = nullptr;
		parent->m_children.erase( itr );
		setRootScene( nullptr );

		this->stop();
		parent->unlink( this );

		this->release();
	}
}

void Object::translate( const Vector2& t, Space relative_to )
{
	translate( Vector3( t ), relative_to );
}

void Object::translate( const Vector3& t, Space relative_to )
{
	switch( relative_to )
	{
	case Space::Self:
		m_local_position += m_local_rotation * t;
		break;
	case Space::Parent:
		m_local_position += t;
		break;
	case Space::World:
		if( m_parent )
		{
			m_local_position += ( Quaternion::inverse( m_parent->getDerivedRotation() ) * t ) / m_parent->getDerivedScale();
		}
		else
		{
			m_local_position += t;
		}
		break;
	default:
		break;
	}

	transformDirty( kTsTranslationDirty );
}

void Object::translate( float x, float y, Space relative_to )
{
	translate( Vector3( x, y, 0.0f ), relative_to );
}

void Object::translate( float x, float y, float z, Space relative_to )
{
	translate( Vector3( x, y, z ), relative_to );
}

void Object::setPosition( const Vector2& t )
{
	setPosition( Vector3( t.x, t.y, m_local_position.z ) );
}

void Object::setPosition( const Vector3& t )
{
	m_local_position = t;
	transformDirty( kTsTranslationDirty );
}

void Object::setPosition( float x, float y )
{
	setPosition( Vector3( x, y, m_local_position.z ) );
}

void Object::setPosition( float x, float y, float z )
{
	setPosition( Vector3( x, y, z ) );
}

const Vector3& Object::getPosition( void ) const
{
	return m_local_position;
}

void Object::yaw( float yaw, Space relative_to )
{
	rotate( Quaternion::createRotationY( yaw ), relative_to );
}

void Object::pitch( float pitch, Space relative_to )
{
	rotate( Quaternion::createRotationX( pitch ), relative_to );
}

void Object::roll( float roll, Space relative_to )
{
	rotate( Quaternion::createRotationZ( roll ), relative_to );
}

void Object::lookAt( const Vector3& target, const Vector3& up )
{
	Matrix3x3 matrix;
	matrix.setLookAt( m_local_position, target, up );
	setRotation( Quaternion( matrix ) );
}

void Object::lookAt( float x, float y, float z, const Vector3& up )
{
	lookAt( Vector3( x, y, z ), up );
}

void Object::rotate( const Rotater& r, Space relative_to )
{
	rotate( r.toQuaternion(), relative_to );
}

void Object::rotate( const Quaternion& r, Space relative_to )
{
	switch( relative_to )
	{
	case Space::Self:
		m_local_rotation = m_local_rotation * r;
		break;
	case Space::Parent:
		m_local_rotation = r * m_local_rotation;
		break;
	case Space::World:
		m_local_rotation = m_local_rotation * Quaternion::inverse( getDerivedRotation() ) * r * getDerivedRotation();
		break;
	default:
		break;
	}

	transformDirty( kTsRotationDirty );
}

void Object::rotate( float yaw, float pitch, float roll, Space relative_to )
{
	rotate( Rotater( yaw, pitch, roll ).toQuaternion(), relative_to );
}

void Object::setRotation( const Rotater& r )
{
	setRotation( r.toQuaternion() );
}

void Object::setRotation( const Quaternion& r )
{
	m_local_rotation = r;
	transformDirty( kTsRotationDirty );
}

void Object::setRotation( float yaw, float pitch, float roll )
{
	setRotation( Rotater( yaw, pitch, roll ).toQuaternion() );
}

const Quaternion& Object::getRotation( void ) const
{
	return m_local_rotation;
}

void Object::scale( const Vector2& s )
{
	scale( Vector3( s.x, s.y, 1.0f ) );
}

void Object::scale( const Vector3& s )
{
	m_local_scale *= s;
	transformDirty( kTsScaleDirty );
}

void Object::scale( float x, float y )
{
	scale( Vector3( x, y, 1.0f ) );
}

void Object::scale( float x, float y, float z )
{
	scale( Vector3( x, y, z ) );
}

void Object::scale( float s )
{
	scale( Vector3( s, s, s ) );
}

void Object::setScale( const Vector2& s )
{
	setScale( Vector3( s.x, s.y, m_local_scale.z ) );
}

void Object::setScale( const Vector3& s )
{
	m_local_scale = s;
	transformDirty( kTsScaleDirty );
}

void Object::setScale( float x, float y )
{
	setScale( Vector3( x, y, m_local_scale.z ) );
}

void Object::setScale( float x, float y, float z )
{
	setScale( Vector3( x, y, z ) );
}

const Vector3& Object::getScale( void ) const
{
	return m_local_scale;
}

void Object::link( Object* child )
{
	if( m_parent )
	{
		m_parent->link( child );
	}
}

void Object::unlink( Object* child )
{
	if( m_parent )
	{
		m_parent->unlink( child );
	}
}

void Object::visit( void )
{
	if( !m_visible )
		return;

	if( !m_children.empty() )
	{
		for( auto child : m_children )
		{
			child->visit();
		}
	}
}

void Object::start( void )
{
	if( m_running == false )
	{
		m_running = true;
		for( auto child : m_children )
		{
			child->start();
		}
	}
}

void Object::stop( void )
{
	if( m_running == true )
	{
		m_running = false;
		for( auto child : m_children )
		{
			child->stop();
		}
	}
}

void Object::transform( void )
{
	if( m_visible == false )
		return;

	int info = m_ts_dirty_info;
	if( m_ts_dirty )
	{
		const Quaternion& r = getDerivedRotation();
		const Vector3& s = getDerivedScale();
		const Vector3& t = getDerivedPosition();

		m_local_to_world_matrix.setTrs( t, r, s );
		m_ts_dirty = false;
	}

	if( !m_children.empty() )
	{
		for( auto child : m_children )
		{
			if( info != kTsClean )
				child->transformDirty( info );

			child->transform();
		}
	}
}

void Object::setRootScene( Scene* scene )
{
	m_root_scene = scene;

	for( auto child : m_children )
	{
		child->setRootScene( scene );
	}
}

void Object::transformDirty( int info )
{
	m_ts_dirty_info |= info;
	m_ts_dirty = true;
}

const Vector3& Object::getDerivedPosition( void ) const
{
	if( m_ts_dirty_info & kTsTranslationDirty )
	{
		if( m_parent )
		{
			m_derived_position = m_parent->getDerivedRotation() * 
				( m_parent->getDerivedScale() * m_local_position ) + m_parent->getDerivedPosition();
		}
		else
		{
			m_derived_position = m_local_position;
		}

		m_ts_dirty_info = m_ts_dirty_info & ( ~kTsTranslationDirty );
	}

	return m_derived_position;
}

const Quaternion& Object::getDerivedRotation( void ) const
{
	if( m_ts_dirty_info & kTsRotationDirty )
	{
		if( m_parent )
		{
			m_derived_rotation = m_parent->getDerivedRotation() * m_local_rotation;
		}
		else
		{
			m_derived_rotation = m_local_rotation;
		}

		m_ts_dirty_info = m_ts_dirty_info & ( ~kTsRotationDirty );
	}

	return m_derived_rotation;
}

const Vector3& Object::getDerivedScale( void ) const
{
	if( m_ts_dirty_info & kTsScaleDirty )
	{
		if( m_parent )
		{
			m_derived_scale = m_parent->getDerivedScale() * m_local_scale;
		}
		else
		{
			m_derived_scale = m_local_scale;
		}

		m_ts_dirty_info = m_ts_dirty_info & ( ~kTsScaleDirty );
	}

	return m_derived_scale;
}

const Matrix4x4& Object::getLocalToWorldMatrix( void ) const
{
	return m_local_to_world_matrix;
}

NAMESPACE_END