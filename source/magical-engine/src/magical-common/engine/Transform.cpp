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


enum
{
	kHasNotChanged = 0x00,
	kNeedToUpdateTranslation = 0x01,
	kNeedToUpdateRotation = 0x02,
	kNeedToUpdateScale = 0x04,
};

Transform::Transform( void )
{
	
}

Transform::~Transform( void )
{
	
}

Shared<Transform> Transform::create( void )
{
	Transform* ret = new Transform();
	magicalAssert( ret, "new Transform() failed" );
	return Shared<Transform>( Initializer<Transform>( ret ) );
}

void Transform::setName( const char* name )
{
	magicalAssert( name && strlen( name ) > 0, "Transform::setName" );

	if( _name == name )
		return;

	_name = name;
}

const std::string& Transform::getName( void ) const
{
	return _name;
}

void Transform::addChild( const Shared<Transform>& child )
{
	Transform* ts = child.get();
	magicalAssert( ts && ts != this && !ts->getParent(), "Transform::addChild" );

	ts->setParent( this );

	ts->retain();
	_children.push_back( ts );
}

void Transform::removeChild( const Shared<Transform>& child )
{
	Transform* ts = child.get();
	magicalAssert( ts && ts->getParent() == this, "Transform::removeChild" );

	auto itr = std::find( _children.begin(), _children.end(), ts );
	magicalAssert( itr != _children.end(), "Transform::removeChild" );

	ts->setParent( nullptr );
	_children.erase( itr );
	ts->release();
}

void Transform::removeAllChildren( void )
{
	if( _children.empty() )
		return;

	for( auto& child : _children )
	{
		child->setParent( nullptr );
		child->release();
	}
	_children.clear();
}

void Transform::removeFromParent( void )
{
	magicalAssert( getParent(), "Transform::removeFromParent" );
	getParent()->removeChild( this );
}

Transform* Transform::findChild( const char* name ) const
{
	magicalAssert( name && strlen( name ) > 0, "Transform::getChild" );
	
	auto ritr = _children.rbegin();
	for( ; ritr != _children.rend(); ++ritr )
	{
		Transform* child = *ritr;
		if( child->getName() == name )
		{
			return child;
		}
	}
	return nullptr;
}

Transform* Transform::getChild( unsigned int index ) const
{
	magicalAssert( index < _children.size(), "Transform::getChild" );
	return _children[index];
}

unsigned int Transform::childrenCount( void ) const
{
	return _children.size();
}

Transform* Transform::getParent( void ) const
{
	return _parent;
}

bool Transform::isChildOf( const Shared<Transform>& parent ) const
{
	Transform* ts = parent.get();
	return _parent == ts;
}

void Transform::setPosition( const Vector2& t )
{
	setPosition( Vector3( t.x, t.y, _local_position.z ) );
}

void Transform::setPosition( const Vector3& t )
{
	_local_position = t;
	_ts_need_update |= kNeedToUpdateTranslation;
}

void Transform::setPosition( float x, float y )
{
	setPosition( Vector3( x, y, _local_position.z ) );
}

void Transform::setPosition( float x, float y, float z )
{
	setPosition( Vector3( x, y, z ) );
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
		_local_position += _local_rotation * t;
		break;
	case Space::Parent:
		_local_position += t;
		break;
	case Space::World:
		if( _parent )
		{
			_local_position += ( _parent->getDerivedRotation().getInversed() * t ) / _parent->getDerivedScale();
		}
		else
		{
			_local_position += t;
		}
		break;
	default:
		break;
	}

	_ts_need_update |= kNeedToUpdateTranslation;
}

void Transform::translate( float x, float y, Space relative_to )
{
	translate( Vector3( x, y, 0.0f ), relative_to );
}

void Transform::translate( float x, float y, float z, Space relative_to )
{
	translate( Vector3( x, y, z ), relative_to );
}

void Transform::setRotation( const EulerAngles& r )
{
	setRotation( r.toQuaternion() );
}

const Vector3& Transform::getPosition( void ) const
{
	return _local_position;
}

void Transform::setRotation( const Quaternion& r )
{
	_local_rotation = r;
	_ts_need_update |= kNeedToUpdateRotation;
}

void Transform::setRotation( float yaw, float pitch, float roll )
{
	EulerAngles ea;
	ea.setScalars( yaw, pitch, roll );
	setRotation( ea.toQuaternion() );
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
		_local_rotation = _local_rotation * r;
		break;
	case Space::Parent:
		_local_rotation = r * _local_rotation;
		break;
	case Space::World:
		_local_rotation = _local_rotation * getDerivedRotation().getInversed() * r * getDerivedRotation();
		break;
	default:
		break;
	}

	_ts_need_update |= kNeedToUpdateRotation;
}

void Transform::rotate( float yaw, float pitch, float roll, Space relative_to )
{
	EulerAngles ea;
	ea.setScalars( yaw, pitch, roll );
	rotate( ea.toQuaternion(), relative_to );
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

const Quaternion& Transform::getRotation( void ) const
{
	return _local_rotation;
}

void Transform::setScale( const Vector2& s )
{
	setScale( Vector3( s.x, s.y, _local_scale.z ) );
}

void Transform::setScale( const Vector3& s )
{
	_local_scale = s;
	_ts_need_update |= kNeedToUpdateScale;
}

void Transform::setScale( float x, float y )
{
	setScale( Vector3( x, y, _local_scale.z ) );
}

void Transform::setScale( float x, float y, float z )
{
	setScale( Vector3( x, y, z ) );
}

void Transform::scale( const Vector2& s )
{
	scale( Vector3( s.x, s.y, 1.0f ) );
}

void Transform::scale( const Vector3& s )
{
	_local_scale *= s;
	_ts_need_update |= kNeedToUpdateScale;
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

const Vector3& Transform::getScale( void ) const
{
	return _local_scale;
}

void Transform::lookAt( const Vector3& target, const Vector3& up )
{
	
}

void Transform::resetTransform( void )
{
	_local_position.setZero();
	_local_rotation.setIdentity();
	_local_scale.setOne();

	_ts_need_update = kNeedToUpdateTranslation | kNeedToUpdateRotation | kNeedToUpdateScale;
}

void Transform::setParent( Transform* parent )
{
	magicalAssert( parent && !getParent(), "Transform::setParent" );
	_parent = parent;
}

void Transform::updateTransformTree( Transform* node )
{
	if( _children.empty() )
		return;

	for( auto& child : _children )
	{
		child->needToUpdate( _ts_need_update );
		updateTransformTree( child );
	}
}

void Transform::updateTransform( void )
{
	if( !_ts_dirty )
		return;

	updateTransformTree( this );

	const Quaternion& r = getDerivedRotation();
	const Vector3& s = getDerivedScale();
	const Vector3& t = getDerivedPosition();

	_local_to_world_matrix.setTRS( t, r, s );
	_ts_dirty = false;
}

void Transform::needToUpdate( int flag )
{
	_ts_need_update |= flag;
	_ts_dirty = true;
}

const Vector3& Transform::getDerivedPosition( void ) const
{
	if( _ts_need_update & ( kNeedToUpdateTranslation | kNeedToUpdateRotation | kNeedToUpdateScale ) )
	{
		if( _parent )
		{
			_derived_position = _parent->getDerivedRotation() * 
				( _parent->getDerivedScale() * _local_position ) + _parent->getDerivedPosition();
		}
		else
		{
			_derived_position = _local_position;
		}
	}

	_ts_need_update = _ts_need_update & ( kNeedToUpdateRotation | kNeedToUpdateScale );
	return _derived_position;
}

const Quaternion& Transform::getDerivedRotation( void ) const
{
	if( _ts_need_update & kNeedToUpdateRotation )
	{
		if( _parent )
		{
			_derived_rotation = _parent->getDerivedRotation() * _local_rotation;
		}
		else
		{
			_derived_rotation = _local_rotation;
		}
	}

	_ts_need_update = _ts_need_update & ( kNeedToUpdateTranslation | kNeedToUpdateScale );
	return _derived_rotation;
}

const Vector3& Transform::getDerivedScale( void ) const
{
	if( _ts_need_update & kNeedToUpdateScale )
	{
		if( _parent )
		{
			_derived_scale = _parent->getDerivedScale() * _local_scale;
		}
		else
		{
			_derived_scale = _local_scale;
		}
	}

	_ts_need_update = _ts_need_update & ( kNeedToUpdateTranslation | kNeedToUpdateRotation );
	return _derived_scale;
}