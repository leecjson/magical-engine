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

enum TransformDirtyInfo
{
	kDirtyTranslation = 0x01,
	kDirtyScale = 0x02,
	kDirtyRotation = 0x04,
};

Node::Node( void )
: _dirty_info( 0 )
//: _transform( nullptr )
{
	//_transform = new Transform();
}

Node::~Node( void )
{
	//_transform->release();
}

Shared<Node> Node::create( void )
{
	Node* ret = new Node();
	magicalAssert( ret, "New Node() failed" );
	return Shared<Node>( Initializer<Node>( ret ) );
}

const Mat4& Node::getMatrix() const
{
	if( _dirty_info )
	{
		bool has_translation = !_position.isZero();
		bool has_rotation = !_rotation.isIdentity();
		bool has_scale = !_scale.isOne();
		
		if( has_translation || ( _dirty_info & kDirtyTranslation ) == kDirtyTranslation )
		{
			_matrix.fillTranslation( _position );
			if( has_rotation || ( _dirty_info & kDirtyRotation ) == kDirtyRotation )
			{
				_matrix.rotate( _rotation );
			}
			if( has_scale || ( _dirty_info & kDirtyScale ) == kDirtyScale )
			{
				_matrix.scale( _scale );
			}
		}
		else if( has_rotation || ( _dirty_info & kDirtyRotation ) == kDirtyRotation )
		{
			_matrix.fillRotation( _rotation );
			if( has_scale || ( _dirty_info & kDirtyScale ) == kDirtyScale )
			{
				_matrix.scale( _scale );
			}
		}
		else if( has_scale || ( _dirty_info & kDirtyScale ) == kDirtyScale )
		{
			_matrix.fillScale( _scale );
		}

		_dirty_info = 0;
	}

	return _matrix;
}

Vec3 Node::getRightVector( void ) const
{
	if( _dirty_info == 0 )
	{
		return _matrix.getRightVector();
	}
	else
	{
		return getMatrix().getRightVector();
	}
}

Vec3 Node::getLeftVector( void ) const
{
	if( _dirty_info == 0 )
	{
		return _matrix.getLeftVector();
	}
	else
	{
		return getMatrix().getLeftVector();
	}
}

Vec3 Node::getUpVector( void ) const
{
	if( _dirty_info == 0 )
	{
		return _matrix.getUpVector();
	}
	else
	{
		return getMatrix().getUpVector();
	}
}

Vec3 Node::getDownVector( void ) const
{
	if( _dirty_info == 0 )
	{
		return _matrix.getDownVector();
	}
	else
	{
		return getMatrix().getDownVector();
	}
}

Vec3 Node::getForwardVector( void ) const
{
	if( _dirty_info == 0 )
	{
		return _matrix.getForwardVector();
	}
	else
	{
		return getMatrix().getForwardVector();
	}
}

Vec3 Node::getBackVector( void ) const
{
	if( _dirty_info == 0 )
	{
		return _matrix.getBackVector();
	}
	else
	{
		return getMatrix().getBackVector();
	}
}

const Vec3& Node::getPosition( void ) const
{
	return _position;
}

void Node::setPosition( const Vec3& translation )
{
	if( _position == translation )
		return;

	_position.fill( translation );
	setDirtyInfo( kDirtyTranslation );
}

void Node::setPosition( float tx, float ty, float tz )
{
	if( MathVec3::equals( _position, tx, ty, tz ) )
		return;

	_position.fill( tx, ty, tz );
	setDirtyInfo( kDirtyTranslation );
}

void Node::setPositionX( float tx )
{
	if( magicalFloatEquals( _position.x, tx ) )
		return;

	_position.x = tx;
	setDirtyInfo( kDirtyTranslation );
}

void Node::setPositionY( float ty )
{
	if( magicalFloatEquals( _position.y, ty ) )
		return;

	_position.y = ty;
	setDirtyInfo( kDirtyTranslation );
}

void Node::setPositionZ( float tz )
{
	if( magicalFloatEquals( _position.z, tz ) )
		return;

	_position.z = tz;
	setDirtyInfo( kDirtyTranslation );
}

void Node::translate( float tx, float ty, float tz )
{
	if( MathVec3::isZero( tx, ty, tz ) )
		return;

	_position.x += tx;
	_position.y += ty;
	_position.z += tz;
	setDirtyInfo( kDirtyTranslation );
}

void Node::translate( const Vec3& translation )
{
	if( translation.isZero() )
		return;

	_position += translation;
	setDirtyInfo( kDirtyTranslation );
}

void Node::translateX( float tx )
{
	if( magicalFloatIsZero( tx ) )
		return;

	_position.x += tx;
	setDirtyInfo( kDirtyTranslation );
}

void Node::translateY( float ty )
{
	if( magicalFloatIsZero( ty ) )
		return;

	_position.y += ty;
	setDirtyInfo( kDirtyTranslation );
}

void Node::translateZ( float tz )
{
	if( magicalFloatIsZero( tz ) )
		return;

	_position.z += tz;
	setDirtyInfo( kDirtyTranslation );
}

void Node::translateRight( float amount )
{
	if( magicalFloatIsZero( amount ) )
		return;

	if( _dirty_info != 0 )
		getMatrix();

	Vec3 right = _matrix.getRightVector();
	right.normalize();
	right.scale( amount );

	translate( right );
}

void Node::translateUp( float amount )
{
	if( magicalFloatIsZero( amount ) )
		return;

	if( _dirty_info != 0 )
		getMatrix();

	Vec3 up = _matrix.getUpVector();
	up.normalize();
	up.scale( amount );

	translate( up );
}

void Node::translateForward( float amount )
{
	if( magicalFloatIsZero( amount ) )
		return;

	if( _dirty_info != 0 )
		getMatrix();

	Vec3 forward = _matrix.getForwardVector();
	forward.normalize();
	forward.scale( amount );

	translate( forward );
}

const Quaternion& Node::getRotation( void ) const
{
	return _rotation;
}

void Node::setRotation( float qx, float qy, float qz, float qw )
{
	_rotation.fill( qx, qy, qz, qw );
}

void Node::setRotation( const Quaternion& rotation )
{
	_rotation.fill( rotation );
}

void Node::setRotation( const Vec3& axis, float angle )
{
	_rotation.fillAxisAngle( axis, angle );
}

void Node::setRotationX( float angle )
{
	_rotation = Quaternion( Vec3::RIGHT, angle );
}

void Node::setRotationY( float angle )
{
	_rotation = Quaternion( Vec3::UP, angle );
}

void Node::setRotationZ( float angle )
{
	_rotation = Quaternion( Vec3::FORWARD, angle );
}

void Node::rotate( float qx, float qy, float qz, float qw )
{
	Quaternion q( qx, qy, qz, qw );
	_rotation *= q;
}

void Node::rotate( const Quaternion& rotation )
{
	_rotation *= rotation;
}

void Node::rotate( const Vec3& axis, float angle )
{
	Quaternion q( axis, angle );
	_rotation *= q;
	_rotation.normalize();
}

void Node::rotateX( float angle )
{
	Quaternion q( Vec3::RIGHT, angle );
	_rotation *= q;
}

void Node::rotateY( float angle )
{
	Quaternion q( Vec3::UP, angle );
	_rotation *= q;
}

void Node::rotateZ( float angle )
{
	Quaternion q( Vec3::FORWARD, angle );
	_rotation *= q;
}

const Vec3& Node::getScale() const
{
	return _scale;
}

void Node::setScale( float scale )
{
	_scale.fill( scale, scale, scale );
}

void Node::setScale( float sx, float sy, float sz )
{
	_scale.fill( sx, sy, sz );
}

void Node::setScale( const Vec3& scale )
{
	_scale.fill( scale );
}

void Node::setScaleX( float sx )
{
	_scale.x = sx;
}

void Node::setScaleY( float sy )
{
	_scale.y = sy;
}

void Node::setScaleZ( float sz )
{
	_scale.z = sz;
}

void Node::scale( float scaler )
{
	_scale.scale( scaler );
}

void Node::scale( float sx, float sy, float sz )
{
	_scale.x *= sx;
	_scale.y *= sy;
	_scale.z *= sz;
}

void Node::scale( const Vec3& scaler )
{
	_scale.x *= scaler.x;
    _scale.y *= scaler.y;
    _scale.z *= scaler.z;
}

void Node::scaleX( float sx )
{
	_scale.x *= sx;
}

void Node::scaleY( float sy )
{
	_scale.y *= sy;
}

void Node::scaleZ( float sz )
{
	_scale.z *= sz;
}

void Node::resetTransform( void )
{
	_scale.fillOne();
	_rotation.fillIdentity();
	_position.fillZero();
}


void Node::lookAt( const Vec3& position, const Vec3& up, const Vec3& target )
{
	/*Mat4 mat;

	Vec3 upv = up;
	upv.normalize();

	Vec3 zaxis = Mathv3::sub( position, target );
	zaxis.normalize();

	Vec3 xaxis = Mathv3::cross( upv, zaxis );
	xaxis.normalize();

	Vec3 yaxis = Mathv3::cross( zaxis, xaxis );
	yaxis.normalize();

	mat.mat[0] = xaxis.x;
	mat.mat[1] = xaxis.y;
	mat.mat[2] = xaxis.z;
	mat.mat[3] = 0;

	mat.mat[4] = yaxis.x;
	mat.mat[5] = yaxis.y;
	mat.mat[6] = yaxis.z;
	mat.mat[7] = 0;

	mat.mat[8] = zaxis.x;
	mat.mat[9] = zaxis.y;
	mat.mat[10] = zaxis.z;
	mat.mat[11] = 0;

	setRotation( matRotate );
	setPosition( position );*/
}

void Node::setDirtyInfo( char dirty_info )
{
	_dirty_info |= dirty_info;
}
