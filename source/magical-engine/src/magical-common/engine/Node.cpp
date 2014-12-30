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
#include "Node.h"

enum
{
	kHasNotChanged = 0x00,
	kNeedToUpdateTranslation = 0x01,
	kNeedToUpdateRotation = 0x02,
	kNeedToUpdateScale = 0x04,
};

Node::Node( void )
{
	
}

Node::~Node( void )
{
	
}

Shared<Node> Node::create( void )
{
	Node* ret = new Node();
	magicalAssert( ret, "new Node() failed" );
	return Shared<Node>( Initializer<Node>( ret ) );
}

Shared<Node> Node::create( const char* name )
{
	Shared<Node> ret = Node::create();
	ret->setName( name );
	return ret;
}

Shared<Node> Node::create( const Vector3& t, const Quaternion& r, const Vector3& s )
{
	Shared<Node> ret = Node::create();
	ret->setPosition( t );
	ret->setRotation( r );
	ret->setScale( s );
	return ret;
}

void Node::setName( const char* name )
{
	magicalAssert( name && strlen( name ) > 0, "Node::setName" );

	if( _name == name )
		return;

	_name = name;
}

const std::string& Node::getName( void ) const
{
	return _name;
}

void Node::addChild( const Shared<Node>& child )
{
	Node* node = child.get();
	magicalAssert( node && node != this && !node->getParent(), "Node::addChild" );

	node->setParent( this );

	node->retain();
	_children.push_back( node );
}

void Node::removeChild( const Shared<Node>& child )
{
	Node* node = child.get();
	magicalAssert( node && node->getParent() == this, "Node::removeChild" );

	auto itr = std::find( _children.begin(), _children.end(), node );
	magicalAssert( itr != _children.end(), "Node::removeChild" );

	Node* target = *itr;

	target->setParent( nullptr );
	_children.erase( itr );
	target->release();
}

void Node::removeAllChildren( void )
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

void Node::removeFromParent( void )
{
	magicalAssert( getParent(), "Node::removeFromParent" );
	getParent()->removeChild( this );
}

Node* Node::getChild( const char* name ) const
{
	magicalAssert( name && strlen( name ) > 0, "Node::getChild" );
	for( auto& child : _children )
	{
		if( child->getName() == name )
			return child;
	}
	return nullptr;
}

Node* Node::getChild( uint32_t index ) const
{
	magicalAssert( index < _children.size(), "Node::getChild" );
	return _children[index];
}

uint32_t Node::childrenCount( void ) const
{
	return _children.size();
}

Node* Node::getParent( void ) const
{
	return _parent;
}

bool Node::isChildOf( const Shared<Node>& parent ) const
{
	Node* node = parent.get();
	return _parent == node;
}

void Node::updateTransform( void )
{
	if( _ts_need_update == kHasNotChanged )
		return;

	const Vector3& t = getDerivedPosition();
	const Quaternion& r = getDerivedRotation();
	const Vector3& s = getDerivedScale();

	_local_to_world_matrix.setTRS( t, r, s );
	_ts_need_update = kHasNotChanged;
}

void Node::setPosition( const Vector2& t )
{
	setPosition( Vector3( t.x, t.y, _local_position.z ) );
}

void Node::setPosition( const Vector3& t )
{
	_local_position = t;
	_ts_need_update |= kNeedToUpdateTranslation;
}

void Node::setPosition( float x, float y )
{
	setPosition( Vector3( x, y, _local_position.z ) );
}

void Node::setPosition( float x, float y, float z )
{
	setPosition( Vector3( x, y, z ) );
}

const Vector3& Node::getPosition( void ) const
{
	return _local_position;
}

void Node::translate( const Vector2& t, Space relative )
{
	translate( Vector3::createFromVector2( t ), relative );
}

void Node::translate( const Vector3& t, Space relative )
{
	switch( relative )
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

void Node::translate( float x, float y, Space relative )
{
	translate( Vector3( x, y, 0.0f ), relative );
}

void Node::translate( float x, float y, float z, Space relative )
{
	translate( Vector3( x, y, z ), relative );
}

void Node::setRotation( const EulerAngles& r )
{
	setRotation( r.toQuaternion() );
}

void Node::setRotation( const Quaternion& r )
{
	_local_rotation = r;
	_ts_need_update |= kNeedToUpdateRotation;
}

void Node::setRotation( float yaw, float pitch, float roll )
{
	EulerAngles ea;
	ea.setScalars( yaw, pitch, roll );
	setRotation( ea.toQuaternion() );
}

const Quaternion& Node::getRotation( void ) const
{
	return _local_rotation;
}

void Node::rotate( const EulerAngles& r, Space relative )
{
	rotate( r.toQuaternion(), relative );
}

void Node::rotate( const Quaternion& r, Space relative )
{
	switch( relative )
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

void Node::rotate( float yaw, float pitch, float roll, Space relative )
{
	EulerAngles ea;
	ea.setScalars( yaw, pitch, roll );
	rotate( ea.toQuaternion(), relative );
}

void Node::yaw( float yaw, Space relative )
{
	rotate( Quaternion::createRotationY( yaw ), relative );
}

void Node::pitch( float pitch, Space relative )
{
	rotate( Quaternion::createRotationX( pitch ), relative );
}

void Node::roll( float roll, Space relative )
{
	rotate( Quaternion::createRotationZ( roll ), relative );
}

void Node::setScale( const Vector2& s )
{
	setScale( Vector3( s.x, s.y, _local_scale.z ) );
}

void Node::setScale( const Vector3& s )
{
	_local_scale = s;
	_ts_need_update |= kNeedToUpdateScale;
}

void Node::setScale( float x, float y )
{
	setScale( Vector3( x, y, _local_scale.z ) );
}

void Node::setScale( float x, float y, float z )
{
	setScale( Vector3( x, y, z ) );
}

const Vector3& Node::getScale( void ) const
{
	return _local_scale;
}

void Node::scale( const Vector2& s )
{
	scale( Vector3( s.x, s.y, 1.0f ) );
}

void Node::scale( const Vector3& s )
{
	_local_scale *= s;
	_ts_need_update |= kNeedToUpdateScale;
}

void Node::scale( float x, float y )
{
	scale( Vector3( x, y, 1.0f ) );
}

void Node::scale( float x, float y, float z )
{
	scale( Vector3( x, y, z ) );
}

void Node::scale( float s )
{
	scale( Vector3( s, s, s ) );
}

void Node::lookAt( const Vector3& target, const Vector3& up )
{

}

const Vector3& Node::getDerivedPosition( void ) const
{
	if( _ts_need_update & kNeedToUpdateTranslation || _ts_need_update & kNeedToUpdateRotation || _ts_need_update & kNeedToUpdateScale )
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
	
	return _derived_position;
}

const Quaternion& Node::getDerivedRotation( void ) const
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

	return _derived_rotation;
}

const Vector3& Node::getDerivedScale( void ) const
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

	return _derived_scale;
}

void Node::setParent( Node* parent )
{
	magicalAssert( parent && !getParent(), "Node::setParent" );
	_parent = parent;
}