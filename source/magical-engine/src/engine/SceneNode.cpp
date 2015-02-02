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
#include "SceneNode.h"

NS_MAGICAL_BEGIN

enum
{
	kTsClean = 0x00,
	kTsTranslationDirty = 0x01,
	kTsRotationDirty = 0x02,
	kTsScaleDirty = 0x04,
};

define_class_hash_code( SceneNode );

SceneNode::SceneNode( void )
: m_ts_dirty_info( kTsClean )
, m_element_id( SceneElement::Node )
{
	assign_class_hash_code();
}

SceneNode::~SceneNode( void )
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

Ptr<SceneNode> SceneNode::create( void )
{
	SceneNode* ret = new SceneNode();
	magicalAssert( ret, "new SceneNode() failed" );
	return Ptr<SceneNode>( Initializer<SceneNode>( ret ) );
}

Ptr<SceneNode> SceneNode::create( const char* name )
{
	SceneNode* ret = new SceneNode();
	magicalAssert( ret, "new SceneNode() failed" );
	ret->setName( name );
	return Ptr<SceneNode>( Initializer<SceneNode>( ret ) );
}

void SceneNode::visit( void )
{
	if( m_is_visible == false )
		return;

	int parent_ts_dirty_info = m_ts_dirty_info;

	if( m_ts_dirty )
	{
		const Quaternion& r = getDerivedRotation();
		const Vector3& s = getDerivedScale();
		const Vector3& t = getDerivedPosition();

		m_local_to_world_matrix.setTRS( t, r, s );
		m_ts_dirty = false;
	}

	if( m_children.empty() )
		return;

	for( auto child : m_children )
	{
		if( parent_ts_dirty_info != kTsClean )
			child->transformDirty( parent_ts_dirty_info );

		child->visit();
	}
}

void SceneNode::start( void )
{
	magicalAssert( m_is_running == false, "Invaild!" );
	if( m_is_running == false )
	{
		m_is_running = true;
		for( auto child : m_children )
		{
			child->start();
		}
	}
}

void SceneNode::stop( void )
{
	magicalAssert( m_is_running == true, "Invaild!" );
	if( m_is_running == true )
	{
		m_is_running = false;
		for( auto child : m_children )
		{
			child->stop();
		}
	}
}

void SceneNode::setName( const char* name )
{
	magicalAssert( name, "name should not be nullptr" );
	m_name = name;
}

void SceneNode::setVisible( bool visible )
{
	m_is_visible = visible;
}

bool SceneNode::isChildOf( const Ptr<SceneNode>& parent ) const
{
	SceneNode* rparent = parent.get();
	magicalAssert( rparent, "Invaild! should not be nullptr" );

	SceneNode* itr = m_parent;
	while( itr )
	{
		if( itr == rparent )
			return true;

		itr = itr->m_parent;
	}
	return false;
}

SceneNode* SceneNode::findChild( const char* name ) const
{
	magicalAssert( name && *name, "name should not be empty" );
	
	auto ritr = m_children.rbegin();
	for( ; ritr != m_children.rend(); ++ritr )
	{
		SceneNode* child = *ritr;
		if( child->getName() == name )
		{
			return child;
		}
	}
	return nullptr;
}

SceneNode* SceneNode::childAtIndex( size_t i ) const
{
	magicalAssert( i < m_children.size(), "Invaild index!" );
	return m_children[ i ];
}

void SceneNode::addChild( const Ptr<SceneNode>& child )
{
	SceneNode* rchild = child.get();
	magicalAssert( rchild, "Invaild! should not be nullptr" );
	magicalAssert( rchild != this, "Invaild! can't add self as a child" );
	magicalAssert( rchild->m_parent == nullptr, "Invaild! already has a parent" );

	rchild->m_parent = this;

	rchild->retain();
	m_children.push_back( rchild );

	if( m_is_running )
		rchild->start();

	childEvent( NodeEvent::Add, rchild );
}

void SceneNode::setParent( const Ptr<SceneNode>& parent )
{
	SceneNode* rparent = parent.get();
	magicalAssert( rparent, "Invaild! should not be nullptr" );
	magicalAssert( rparent != this && rparent != m_parent, "Invaild!" );
	magicalAssert( rparent->isChildOf( this ) == false, "Invaild! own child can't be parent" );

	if( m_parent )
	{
		auto itr = std::find( m_parent->m_children.begin(), m_parent->m_children.end(), this );
		magicalAssert( itr != m_parent->m_children.end(), "Invaild!" );

		SceneNode* lparent = m_parent;
		m_parent = nullptr;
		lparent->m_children.erase( itr );

		lparent->childEvent( NodeEvent::Remove, this );

		m_parent = rparent;
		rparent->m_children.push_back( this );

		if( rparent->m_is_running )
		{
			if( false == m_is_running )
			{
				start();
			}
		}
		else
		{
			if( m_is_running )
			{
				stop();
			}
		}
		rparent->childEvent( NodeEvent::Add, this );
	}
	else
	{
		m_parent = rparent;

		this->retain();
		rparent->m_children.push_back( this );

		if( rparent->m_is_running )
			start();

		rparent->childEvent( NodeEvent::Add, this );
	}
}

void SceneNode::removeChild( const Ptr<SceneNode>& child )
{
	SceneNode* rchild = child.get();
	magicalAssert( rchild, "Invaild! should not be nullptr" );

	auto itr = std::find( m_children.begin(), m_children.end(), rchild );
	if( itr != m_children.end() )
	{
		rchild->m_parent = nullptr;
		m_children.erase( itr );

		if( m_is_running )
			rchild->stop();

		childEvent( NodeEvent::Remove, rchild );
		rchild->release();
	}
}

void SceneNode::removeAllChildren( void )
{
	if( !m_children.empty() )
	{
		Children children = m_children;
		m_children.clear();

		for( auto child : children )
		{
			child->m_parent = nullptr;
			if( m_is_running )
			{
				child->stop();
			}
		}

		childEvent( NodeEvent::Remove, children );
		for( auto child : children )
		{
			child->release();
		}
	}
}

void SceneNode::removeSelf( void )
{
	if( m_parent )
	{
		auto itr = std::find( m_parent->m_children.begin(), m_parent->m_children.end(), this );
		magicalAssert( itr != m_parent->m_children.end(), "Invaild!" );

		SceneNode* parent = m_parent;
		m_parent = nullptr;
		parent->m_children.erase( itr );

		if( parent->m_is_running )
			stop();
		
		parent->childEvent( NodeEvent::Remove, this );
		this->release();
	}
}

void SceneNode::translate( const Vector2& t, Space relative_to )
{
	translate( Vector3::createFromVector2( t ), relative_to );
}

void SceneNode::translate( const Vector3& t, Space relative_to )
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

void SceneNode::translate( float x, float y, Space relative_to )
{
	translate( Vector3( x, y, 0.0f ), relative_to );
}

void SceneNode::translate( float x, float y, float z, Space relative_to )
{
	translate( Vector3( x, y, z ), relative_to );
}

void SceneNode::setPosition( const Vector2& t )
{
	setPosition( Vector3( t.x, t.y, m_local_position.z ) );
}

void SceneNode::setPosition( const Vector3& t )
{
	m_local_position = t;
	transformDirty( kTsTranslationDirty );
}

void SceneNode::setPosition( float x, float y )
{
	setPosition( Vector3( x, y, m_local_position.z ) );
}

void SceneNode::setPosition( float x, float y, float z )
{
	setPosition( Vector3( x, y, z ) );
}

const Vector3& SceneNode::getPosition( void ) const
{
	return m_local_position;
}

void SceneNode::yaw( float yaw, Space relative_to )
{
	rotate( Quaternion::createRotationY( magicalDegToRad( yaw ) ), relative_to );
}

void SceneNode::pitch( float pitch, Space relative_to )
{
	rotate( Quaternion::createRotationX( magicalDegToRad( pitch ) ), relative_to );
}

void SceneNode::roll( float roll, Space relative_to )
{
	rotate( Quaternion::createRotationZ( magicalDegToRad( roll ) ), relative_to );
}

void SceneNode::lookAt( const Vector3& target, const Vector3& up )
{
	
}

void SceneNode::lookAt( float x, float y, float z, const Vector3& up )
{

}

void SceneNode::rotate( const EulerAngles& r, Space relative_to )
{
	rotate( r.toQuaternion(), relative_to );
}

void SceneNode::rotate( const Quaternion& r, Space relative_to )
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

void SceneNode::rotate( float yaw, float pitch, float roll, Space relative_to )
{
	EulerAngles ea;
	ea.setScalars( yaw, pitch, roll );
	rotate( ea.toQuaternion(), relative_to );
}

void SceneNode::setRotation( const EulerAngles& r )
{
	setRotation( r.toQuaternion() );
}

void SceneNode::setRotation( const Quaternion& r )
{
	m_local_rotation = r;
	transformDirty( kTsRotationDirty );
}

void SceneNode::setRotation( float yaw, float pitch, float roll )
{
	setRotation( EulerAngles( yaw, pitch, roll ).toQuaternion() );
}

const Quaternion& SceneNode::getRotation( void ) const
{
	return m_local_rotation;
}

void SceneNode::scale( const Vector2& s )
{
	scale( Vector3( s.x, s.y, 1.0f ) );
}

void SceneNode::scale( const Vector3& s )
{
	m_local_scale *= s;
	transformDirty( kTsScaleDirty );
}

void SceneNode::scale( float x, float y )
{
	scale( Vector3( x, y, 1.0f ) );
}

void SceneNode::scale( float x, float y, float z )
{
	scale( Vector3( x, y, z ) );
}

void SceneNode::scale( float s )
{
	scale( Vector3( s, s, s ) );
}

void SceneNode::setScale( const Vector2& s )
{
	setScale( Vector3( s.x, s.y, m_local_scale.z ) );
}

void SceneNode::setScale( const Vector3& s )
{
	m_local_scale = s;
	transformDirty( kTsScaleDirty );
}

void SceneNode::setScale( float x, float y )
{
	setScale( Vector3( x, y, m_local_scale.z ) );
}

void SceneNode::setScale( float x, float y, float z )
{
	setScale( Vector3( x, y, z ) );
}

const Vector3& SceneNode::getScale( void ) const
{
	return m_local_scale;
}

void SceneNode::transformDirty( int info )
{
	m_ts_dirty_info |= info;
	m_ts_dirty = true;
}

const Vector3& SceneNode::getDerivedPosition( void ) const
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

const Quaternion& SceneNode::getDerivedRotation( void ) const
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

const Vector3& SceneNode::getDerivedScale( void ) const
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

void SceneNode::childEvent( NodeEvent evt, SceneNode* child )
{
	if( m_parent )
	{
		m_parent->childEvent( evt, child );
	}
}

void SceneNode::childEvent( NodeEvent evt, const Children& children )
{
	if( m_parent )
	{
		m_parent->childEvent( evt, children );
	}
}

NS_MAGICAL_END