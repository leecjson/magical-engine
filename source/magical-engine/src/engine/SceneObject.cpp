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
#include "SceneObject.h"
#include "Scene.h"
#include "Camera.h"

NS_MAGICAL_BEGIN

define_class_hash_code( SceneObject );

SceneObject::SceneObject( void )
: m_ts_dirty_info( kTsClean )
, m_element_enum( Element::Object )
{
	assign_class_hash_code();
}

SceneObject::~SceneObject( void )
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

Ptr<SceneObject> SceneObject::create( void )
{ 
	SceneObject* ret = new SceneObject();
	magicalAssert( ret, "new SceneObject() failed" );
	return Ptr<SceneObject>( Initializer<SceneObject>( ret ) );
}

Ptr<SceneObject> SceneObject::create( const char* name )
{
	SceneObject* ret = new SceneObject();
	magicalAssert( ret, "new SceneObject() failed" );
	ret->setName( name );
	return Ptr<SceneObject>( Initializer<SceneObject>( ret ) );
}

void SceneObject::setName( const char* name )
{
	magicalAssert( name, "name should not be nullptr" );
	m_name = name;
}

void SceneObject::setVisible( bool visible )
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

bool SceneObject::isChildOf( const Ptr<SceneObject>& parent ) const
{
	SceneObject* rparent = parent.get();
	magicalAssert( rparent, "Invaild! should not be nullptr" );

	SceneObject* itr = m_parent;
	while( itr )
	{
		if( itr == rparent )
			return true;

		itr = itr->m_parent;
	}
	return false;
}

SceneObject* SceneObject::findChild( const char* name ) const
{
	magicalAssert( name && *name, "name should not be empty" );
	
	auto ritr = m_children.rbegin();
	for( ; ritr != m_children.rend(); ++ritr )
	{
		SceneObject* child = *ritr;
		if( child->getName() == name )
		{
			return child;
		}
	}
	return nullptr;
}

SceneObject* SceneObject::childAtIndex( size_t i ) const
{
	magicalAssert( i < m_children.size(), "Invaild index!" );
	return m_children[ i ];
}

void SceneObject::addChild( const Ptr<SceneObject>& child )
{
	SceneObject* rchild = child.get();
	magicalAssert( rchild, "Invaild! should not be nullptr" );
	magicalAssert( rchild != this, "Invaild! can't add self as a child" );
	magicalAssert( rchild->m_parent == nullptr, "Invaild! already has a parent" );

	rchild->m_parent = this;

	rchild->retain();
	m_children.push_back( rchild );
	rchild->setRootScene( m_root_scene );

	rchild->start();
	link( rchild );
}

void SceneObject::setParent( const Ptr<SceneObject>& parent )
{
	SceneObject* rparent = parent.get();
	magicalAssert( rparent, "Invaild! should not be nullptr" );
	magicalAssert( rparent != this && rparent != m_parent, "Invaild!" );
	magicalAssert( rparent->isChildOf( this ) == false, "Invaild! own child can't be parent" );

	if( m_parent )
	{
		auto itr = std::find( m_parent->m_children.begin(), m_parent->m_children.end(), this );
		magicalAssert( itr != m_parent->m_children.end(), "Invaild!" );

		SceneObject* lparent = m_parent;
		m_parent = nullptr;
		lparent->m_children.erase( itr );
		lparent->unlink( this );

		m_parent = rparent;
		rparent->m_children.push_back( this );
		setRootScene( rparent->m_root_scene );

		if( rparent->m_running )
		{
			this->start();
		}
		else
		{
			this->stop();
		}

		rparent->link( this );
	}
	else
	{
		m_parent = rparent;

		this->retain();
		rparent->m_children.push_back( this );
		setRootScene( rparent->m_root_scene );

		if( rparent->m_running )
			start();

		rparent->link( this );
	}
}

void SceneObject::removeChild( const Ptr<SceneObject>& child )
{
	SceneObject* rchild = child.get();
	magicalAssert( rchild, "Invaild! should not be nullptr" );

	auto itr = std::find( m_children.begin(), m_children.end(), rchild );
	if( itr != m_children.end() )
	{
		rchild->m_parent = nullptr;
		m_children.erase( itr );
		rchild->setRootScene( nullptr );

		rchild->stop();
		unlink( rchild );

		rchild->release();
	}
}

void SceneObject::removeChild( const char* name )
{
	magicalAssert( name && *name, "Invaild! should not be nullptr" );

	auto ritr = m_children.begin();
	for( ; ritr != m_children.end(); ++ritr )
	{
		SceneObject* child = *ritr;
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

void SceneObject::removeAllChildren( void )
{
	if( !m_children.empty() )
	{
		Children children = m_children;
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

void SceneObject::removeSelf( void )
{
	if( m_parent )
	{
		auto itr = std::find( m_parent->m_children.begin(), m_parent->m_children.end(), this );
		magicalAssert( itr != m_parent->m_children.end(), "Invaild!" );

		SceneObject* parent = m_parent;
		m_parent = nullptr;
		parent->m_children.erase( itr );
		setRootScene( nullptr );

		this->stop();
		parent->unlink( this );

		this->release();
	}
}

void SceneObject::translate( const Vector2& t, Space relative_to )
{
	translate( Vector3::createFromVector2( t ), relative_to );
}

void SceneObject::translate( const Vector3& t, Space relative_to )
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
			m_local_position += ( m_parent->getDerivedRotation().getInversed() * t ) / m_parent->getDerivedScale();
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

void SceneObject::translate( float x, float y, Space relative_to )
{
	translate( Vector3( x, y, 0.0f ), relative_to );
}

void SceneObject::translate( float x, float y, float z, Space relative_to )
{
	translate( Vector3( x, y, z ), relative_to );
}

void SceneObject::setPosition( const Vector2& t )
{
	setPosition( Vector3( t.x, t.y, m_local_position.z ) );
}

void SceneObject::setPosition( const Vector3& t )
{
	m_local_position = t;
	transformDirty( kTsTranslationDirty );
}

void SceneObject::setPosition( float x, float y )
{
	setPosition( Vector3( x, y, m_local_position.z ) );
}

void SceneObject::setPosition( float x, float y, float z )
{
	setPosition( Vector3( x, y, z ) );
}

const Vector3& SceneObject::getPosition( void ) const
{
	return m_local_position;
}

void SceneObject::yaw( float yaw, Space relative_to )
{
	rotate( Quaternion::createRotationY( yaw ), relative_to );
}

void SceneObject::pitch( float pitch, Space relative_to )
{
	rotate( Quaternion::createRotationX( pitch ), relative_to );
}

void SceneObject::roll( float roll, Space relative_to )
{
	rotate( Quaternion::createRotationZ( roll ), relative_to );
}

void SceneObject::lookAt( const Vector3& target, const Vector3& up )
{
	Matrix3 m = Matrix3::createLookAt( m_local_position, target, up );
	setRotation( m.toQuaternion() );
}

void SceneObject::lookAt( float x, float y, float z, const Vector3& up )
{
	lookAt( Vector3( x, y, z ), up );
}

void SceneObject::rotate( const EulerAngles& r, Space relative_to )
{
	rotate( r.toQuaternion(), relative_to );
}

void SceneObject::rotate( const Quaternion& r, Space relative_to )
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
		m_local_rotation = m_local_rotation * getDerivedRotation().getInversed() * r * getDerivedRotation();
		break;
	default:
		break;
	}

	transformDirty( kTsRotationDirty );
}

void SceneObject::rotate( float yaw, float pitch, float roll, Space relative_to )
{
	EulerAngles ea;
	ea.setScalars( yaw, pitch, roll );
	rotate( ea.toQuaternion(), relative_to );
}

void SceneObject::setRotation( const EulerAngles& r )
{
	setRotation( r.toQuaternion() );
}

void SceneObject::setRotation( const Quaternion& r )
{
	m_local_rotation = r;
	transformDirty( kTsRotationDirty );
}

void SceneObject::setRotation( float yaw, float pitch, float roll )
{
	setRotation( EulerAngles( yaw, pitch, roll ).toQuaternion() );
}

const Quaternion& SceneObject::getRotation( void ) const
{
	return m_local_rotation;
}

void SceneObject::scale( const Vector2& s )
{
	scale( Vector3( s.x, s.y, 1.0f ) );
}

void SceneObject::scale( const Vector3& s )
{
	m_local_scale *= s;
	transformDirty( kTsScaleDirty );
}

void SceneObject::scale( float x, float y )
{
	scale( Vector3( x, y, 1.0f ) );
}

void SceneObject::scale( float x, float y, float z )
{
	scale( Vector3( x, y, z ) );
}

void SceneObject::scale( float s )
{
	scale( Vector3( s, s, s ) );
}

void SceneObject::setScale( const Vector2& s )
{
	setScale( Vector3( s.x, s.y, m_local_scale.z ) );
}

void SceneObject::setScale( const Vector3& s )
{
	m_local_scale = s;
	transformDirty( kTsScaleDirty );
}

void SceneObject::setScale( float x, float y )
{
	setScale( Vector3( x, y, m_local_scale.z ) );
}

void SceneObject::setScale( float x, float y, float z )
{
	setScale( Vector3( x, y, z ) );
}

const Vector3& SceneObject::getScale( void ) const
{
	return m_local_scale;
}

void SceneObject::link( SceneObject* child )
{
	if( m_parent )
	{
		m_parent->link( child );
	}
}

void SceneObject::unlink( SceneObject* child )
{
	if( m_parent )
	{
		m_parent->unlink( child );
	}
}

void SceneObject::visit( Camera* camera )
{
	if( !m_visible )
		return;

	if( !m_children.empty() )
	{
		for( auto child : m_children )
		{
			child->visit( camera );
		}
	}
}

void SceneObject::start( void )
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

void SceneObject::stop( void )
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

void SceneObject::transform( void )
{
	if( !m_visible )
		return;

	int info = m_ts_dirty_info;

	if( m_ts_dirty != kTsClean )
	{
		const Quaternion& r = getDerivedRotation();
		const Vector3& s = getDerivedScale();
		const Vector3& t = getDerivedPosition();

		m_local_to_world_matrix.setTRS( t, r, s );
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

void SceneObject::setRootScene( Scene* scene )
{
	m_root_scene = scene;

	for( auto itr : m_children )
	{
		itr->setRootScene( scene );
	}
}

void SceneObject::transformDirty( int info )
{
	m_ts_dirty_info |= info;
	m_ts_dirty = true;
}

const Vector3& SceneObject::getDerivedPosition( void ) const
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

const Quaternion& SceneObject::getDerivedRotation( void ) const
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

const Vector3& SceneObject::getDerivedScale( void ) const
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

const Matrix4& SceneObject::getLocalToWorldMatrix( void ) const
{
	return m_local_to_world_matrix;
}

NS_MAGICAL_END