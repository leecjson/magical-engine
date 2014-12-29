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

void Node::addChild( Shared<Node>& child )
{
	
}

void Node::removeChild( Shared<Node>& child )
{

}

void Node::setParent( Shared<Node>& parent )
{

}

void Node::removeParent( Shared<Node>& parent )
{

}

Node* Node::getChild( void ) const
{

}

Node* Node::getParent( void ) const
{

}

void Node::updateTransform( void )
{
	if( _ts_need_update != kHasNotChanged )
		return;

	const Vector3& t = getDerivedPosition();
	const Quaternion& r = getDerivedRotation();
	const Vector3& s = getDerivedScale();

	_local_to_world_matrix.setTRS( t, r, s );
	_ts_need_update = kHasNotChanged;
}

const Vector3& Node::getDerivedPosition( void ) const
{
	if( _ts_need_update & kNeedToUpdateTranslation || _ts_need_update & kNeedToUpdateRotation || _ts_need_update & kNeedToUpdateScale )
	{
		if( _parent )
		{
			_derived_position = _parent->getDerivedRotation() * _local_position * _parent->getDerivedScale();
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

void Node::setPosition( const Vector3& t )
{
	_local_position = t;
	_ts_need_update |= kNeedToUpdateTranslation;
}

void Node::setPosition( const Vector2& t )
{
	_local_position.fromVector2( t );
	_ts_need_update |= kNeedToUpdateTranslation;
}

void Node::setPosition( const float x, const float y, const float z )
{
	_local_position.setScalars( x, y, z );
	_ts_need_update |= kNeedToUpdateTranslation;
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
	if( relative == Space::Self )
	{
		_local_position += t;
	}
	else if( relative == Space::World )
	{
		_local_position += ( _parent->getDerivedRotation().getInversed() * t )
			/ _parent->getDerivedScale();
	}
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
	_local_rotation.fromEulerAngles( r );
	_ts_need_update |= kNeedToUpdateRotation;
}

void Node::setRotation( const Quaternion& r )
{
	_local_rotation = r;
	_ts_need_update |= kNeedToUpdateRotation;
}

void Node::setRotation( float yaw, float pitch, float roll )
{
	_local_rotation.fromEulerAngles( yaw, pitch, roll );
	_ts_need_update |= kNeedToUpdateRotation;
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
	if( relative == Space::Self )
	{
		_local_rotation = _local_rotation * r;
	}
	else if( relative == Space::World )
	{
		_local_rotation = _local_rotation * getDerivedRotation().getInversed() * r * getDerivedRotation();
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

void Node::setScale( const Vector3& s )
{
	_local_scale = s;
	_ts_need_update |= kNeedToUpdateScale;
}

void Node::setScale( float x, float y, float z )
{
	_local_scale.setScalars( x, y, z );
	_ts_need_update |= kNeedToUpdateScale;
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