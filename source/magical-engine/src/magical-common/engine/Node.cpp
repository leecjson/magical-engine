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
	kNotChanged = 0x00,
	kTranslationChanged = 0x01,
	kRotationChanged = 0x02,
	kScaleChanged = 0x04,
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

void Node::transformChanged( int flag )
{
	_has_changed |= flag;
}

void Node::setPosition( const Vector3& v )
{
	_local_position.set( v );
	transformChanged( kTranslationChanged );
}

void Node::setPosition( const Vector2& v )
{
	_local_position.fromVector2( v );
	transformChanged( kTranslationChanged );
}

void Node::setPosition( const float x, const float y, const float z )
{
	_local_position.setScalars( x, y, z );
	transformChanged( kTranslationChanged );
}

const Vector3& Node::getPosition( void ) const
{
	return _local_position;
}

void Node::setRotation( const Quaternion& q )
{
	_local_rotation.set( q );
	transformChanged( kRotationChanged );
}

void Node::setRotation( const EulerAngles& ea )
{
	_local_rotation.fromEulerAngles( ea );
	transformChanged( kRotationChanged );
}

void Node::setRotation( float yaw, float pitch, float roll )
{
	_local_rotation.fromEulerAngles( yaw, pitch, roll );
	transformChanged( kRotationChanged );
}

const Quaternion& Node::getRotation( void ) const
{
	return _local_rotation;
}

void Node::setScale( const Vector3& s )
{
	_local_scale.set( s );
	transformChanged( kScaleChanged );
}

void Node::setScale( float x, float y, float z )
{
	_local_scale.setScalars( x, y, z );
	transformChanged( kScaleChanged );
}

const Vector3& Node::getScale( void ) const
{
	return _local_scale;
}