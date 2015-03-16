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
#include "Transform.h"

NS_MAGICAL_BEGIN

enum
{
	kTsClean = 0x00,
	kTsTranslationDirty = 0x01,
	kTsRotationDirty = 0x02,
	kTsScaleDirty = 0x04,
};

bool Transform::isChildOf( const Ptr<Transform>& parent ) const
{
	magicalAssert( parent != nullptr, "Invaild! should not be nullptr" );
	return m_parent == parent.get();
}

size_t Transform::childrenCount( void ) const
{
	return m_children.size();
}

Transform* Transform::getParent( void ) const
{
	return m_parent;
}

Transform* Transform::findChild( const char* name ) const
{
	magicalAssert( name && *name, "name should not be empty" );
	
	auto ritr = m_children.rbegin();
	for( ; ritr != m_children.rend(); ++ritr )
	{
		Transform* child = *ritr;
		if( child->getName() == name )
		{
			return child;
		}
	}
	return nullptr;
}

Transform* Transform::childAtIndex( size_t i ) const
{
	magicalAssert( i < m_children.size(), "Invaild index!" );
	return m_children[ i ];
}

void Transform::addChild( const Ptr<Transform>& child )
{
	Transform* rchild = child.get();
	magicalAssert( rchild && rchild != this && !rchild->getParent(), "Invaild!" );

	rchild->setParent( this );

	rchild->retain();
	m_children.push_back( rchild );
}

void Transform::removeChild( const Ptr<Transform>& child )
{
	Transform* rchild = child.get();
	magicalAssert( rchild && rchild->getParent() == this, "Invaild!" );

	auto itr = std::find( m_children.begin(), m_children.end(), rchild );
	magicalAssert( itr != m_children.end(), "Invaild!" );

	rchild->setParent( nullptr );
	m_children.erase( itr );
	rchild->release();
}

void Transform::removeAllChildren( void )
{
	if( m_children.empty() )
		return;

	for( auto& child : m_children )
	{
		child->setParent( nullptr );
		child->release();
	}
	m_children.clear();
}

void Transform::removeFromParent( void )
{
	magicalAssert( getParent(), "Invaild! has no parent transform" );
	getParent()->removeChild( this );
}

void Transform::translate( const Vector2& t, Space relative_to )
{
	translate( Vector3::createFromVector2( t ), relative_to );
}

void Transform::translate( const Vector3& t, Space relative_to )
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

void Transform::translate( float x, float y, Space relative_to )
{
	translate( Vector3( x, y, 0.0f ), relative_to );
}

void Transform::translate( float x, float y, float z, Space relative_to )
{
	translate( Vector3( x, y, z ), relative_to );
}

void Transform::setPosition( const Vector2& t )
{
	setPosition( Vector3( t.x, t.y, m_local_position.z ) );
}

void Transform::setPosition( const Vector3& t )
{
	m_local_position = t;
	transformDirty( kTsTranslationDirty );
}

void Transform::setPosition( float x, float y )
{
	setPosition( Vector3( x, y, m_local_position.z ) );
}

void Transform::setPosition( float x, float y, float z )
{
	setPosition( Vector3( x, y, z ) );
}

const Vector3& Transform::getPosition( void ) const
{
	return m_local_position;
}

void Transform::yaw( float yaw, Space relative_to )
{
	rotate( Quaternion::createRotationY( yaw ), relative_to );
}

void Transform::pitch( float pitch, Space relative_to )
{
	rotate( Quaternion::createRotationX( pitch ), relative_to );
}

void Transform::roll( float roll, Space relative_to )
{
	rotate( Quaternion::createRotationZ( roll ), relative_to );
}

void Transform::lookAt( const Vector3& target, const Vector3& up )
{
	
}

void Transform::rotate( const EulerAngles& r, Space relative_to )
{
	rotate( r.toQuaternion(), relative_to );
}

void Transform::rotate( const Quaternion& r, Space relative_to )
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

void Transform::rotate( float yaw, float pitch, float roll, Space relative_to )
{
	EulerAngles ea;
	ea.setScalars( yaw, pitch, roll );
	rotate( ea.toQuaternion(), relative_to );
}

const Quaternion& Transform::getRotation( void ) const
{
	return m_local_rotation;
}

void Transform::scale( const Vector2& s )
{
	scale( Vector3( s.x, s.y, 1.0f ) );
}

void Transform::scale( const Vector3& s )
{
	m_local_scale *= s;
	transformDirty( kTsScaleDirty );
}

void Transform::scale( float x, float y )
{
	scale( Vector3( x, y, 1.0f ) );
}

void Transform::scale( float x, float y, float z )
{
	scale( Vector3( x, y, z ) );
}

void Transform::scale( float s )
{
	scale( Vector3( s, s, s ) );
}

void Transform::setScale( const Vector2& s )
{
	setScale( Vector3( s.x, s.y, m_local_scale.z ) );
}

void Transform::setScale( const Vector3& s )
{
	m_local_scale = s;
	transformDirty( kTsScaleDirty );
}

void Transform::setScale( float x, float y )
{
	setScale( Vector3( x, y, m_local_scale.z ) );
}

void Transform::setScale( float x, float y, float z )
{
	setScale( Vector3( x, y, z ) );
}

const Vector3& Transform::getScale( void ) const
{
	return m_local_scale;
}

void Transform::setParent( Transform* parent )
{
	magicalAssert( parent, "should not be nullptr." );
	magicalAssert( !getParent(), "Invaild! already has a parent transform." );
	m_parent = parent;
}

void Transform::transform( void )
{
	int dirty_info = kTsClean;

	if( m_ts_dirty && m_is_visible )
	{
		dirty_info = m_ts_dirty_info;

		const Quaternion& r = getDerivedRotation();
		const Vector3& s = getDerivedScale();
		const Vector3& t = getDerivedPosition();

		m_local_to_world_matrix.setTRS( t, r, s );
		m_ts_dirty = false;
	}

	if( m_is_visible )
	{
		for( auto child : m_children )
		{
			if( dirty_info != kTsClean )
				child->transformDirty( dirty_info );

			child->transform();
		}
	}
}

void Transform::transformDirty( int info )
{
	m_ts_dirty_info |= info;
	m_ts_dirty = true;
}

const Vector3& Transform::getDerivedPosition( void ) const
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

const Quaternion& Transform::getDerivedRotation( void ) const
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

const Vector3& Transform::getDerivedScale( void ) const
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

NS_MAGICAL_END