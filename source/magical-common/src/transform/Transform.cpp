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
	kLocalNotChanged = 0x00,
	kLocalTranslationChanged = 0x01,
	kLocalRotationChanged = 0x02,
	kLocalScaleChanged = 0x04,
};

Transform::Transform( void )
: _local_has_changed( kLocalNotChanged )
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

const Mat4& Transform::getLocalToWorldMatrix() const
{
	if( _local_has_changed )
	{
		bool has_translation = !_local_position.isZero();
		bool has_rotation = !_local_rotation.isIdentity();
		bool has_scale = !_local_scale.isOne();
		
		if( has_translation || _local_has_changed & kLocalTranslationChanged )
		{
			_local_to_world_matrix.fillTranslation( _local_position );
			if( has_rotation || _local_has_changed & kLocalRotationChanged )
			{

				_local_to_world_matrix.rotateQuaternion( _local_rotation );
			}
			if( has_scale || _local_has_changed & kLocalScaleChanged )
			{
				_local_to_world_matrix.scale( _local_scale );
			}
		}
		else if( has_rotation || _local_has_changed & kLocalRotationChanged )
		{
			_local_to_world_matrix.fillRotationQuaternion( _local_rotation );
			if( has_scale || _local_has_changed & kLocalScaleChanged )
			{
				_local_to_world_matrix.scale( _local_scale );
			}
		}
		else if( has_scale || _local_has_changed & kLocalScaleChanged )
		{
			_local_to_world_matrix.fillScaling( _local_scale );
		}

		_local_has_changed = kLocalNotChanged;
	}

	return _local_to_world_matrix;
}

Vec3 Transform::getRightVector( void ) const
{
	if( _local_has_changed == kLocalNotChanged )
	{
		return _local_to_world_matrix.getRightVector();
	}
	else
	{
		return getLocalToWorldMatrix().getRightVector();
	}
}

Vec3 Transform::getLeftVector( void ) const
{
	if( _local_has_changed == kLocalNotChanged )
	{
		return _local_to_world_matrix.getLeftVector();
	}
	else
	{
		return getLocalToWorldMatrix().getLeftVector();
	}
}

Vec3 Transform::getUpVector( void ) const
{
	if( _local_has_changed == kLocalNotChanged )
	{
		return _local_to_world_matrix.getUpVector();
	}
	else
	{
		return getLocalToWorldMatrix().getUpVector();
	}
}

Vec3 Transform::getDownVector( void ) const
{
	if( _local_has_changed == kLocalNotChanged )
	{
		return _local_to_world_matrix.getDownVector();
	}
	else
	{
		return getLocalToWorldMatrix().getDownVector();
	}
}

Vec3 Transform::getForwardVector( void ) const
{
	if( _local_has_changed == kLocalNotChanged )
	{
		return _local_to_world_matrix.getForwardVector();
	}
	else
	{
		return getLocalToWorldMatrix().getForwardVector();
	}
}

Vec3 Transform::getBackVector( void ) const
{
	if( _local_has_changed == kLocalNotChanged )
	{
		return _local_to_world_matrix.getBackVector();
	}
	else
	{
		return getLocalToWorldMatrix().getBackVector();
	}
}

const Vec3& Transform::getPosition( void ) const
{
	return _local_position;
}

void Transform::setPosition( const Vec3& translation )
{
	if( _local_position == translation )
		return;

	_local_position.fill( translation );
	transformChanged( kLocalTranslationChanged );
}

void Transform::setPosition( float x, float y, float z )
{
	//if( MathVec3::equals( _local_position, x, y, z ) )
	//	return;

	_local_position.fill( x, y, z );
	transformChanged( kLocalTranslationChanged );
}

void Transform::setPositionX( float x )
{
	if( magicalFltEqual( _local_position.x, x ) )
		return;

	_local_position.x = x;
	transformChanged( kLocalTranslationChanged );
}

void Transform::setPositionY( float y )
{
	if( magicalFltEqual( _local_position.y, y ) )
		return;

	_local_position.y = y;
	transformChanged( kLocalTranslationChanged );
}

void Transform::setPositionZ( float z )
{
	if( magicalFltEqual( _local_position.z, z ) )
		return;

	_local_position.z = z;
	transformChanged( kLocalTranslationChanged );
}

void Transform::translate( float x, float y, float z )
{
	//if( MathVec3::isZero( x, y, z ) )
	//	return;

	_local_position.x += x;
	_local_position.y += y;
	_local_position.z += z;
	transformChanged( kLocalTranslationChanged );
}

void Transform::translate( const Vec3& translation )
{
	if( translation.isZero() )
		return;

	_local_position += translation;
	transformChanged( kLocalTranslationChanged );
}

void Transform::translateX( float x )
{
	if( magicalFltIsZero( x ) )
		return;

	_local_position.x += x;
	transformChanged( kLocalTranslationChanged );
}

void Transform::translateY( float y )
{
	if( magicalFltIsZero( y ) )
		return;

	_local_position.y += y;
	transformChanged( kLocalTranslationChanged );
}

void Transform::translateZ( float z )
{
	if( magicalFltIsZero( z ) )
		return;

	_local_position.z += z;
	transformChanged( kLocalTranslationChanged );
}

void Transform::translateRight( float amount )
{
	if( magicalFltIsZero( amount ) )
		return;

	if( _local_has_changed != kLocalNotChanged )
		getLocalToWorldMatrix();

	Vec3 right = _local_to_world_matrix.getRightVector();
	right.normalize();
	//right.scale( amount );

	translate( right );
}

void Transform::translateUp( float amount )
{
	if( magicalFltIsZero( amount ) )
		return;

	if( _local_has_changed != kLocalNotChanged )
		getLocalToWorldMatrix();

	Vec3 up = _local_to_world_matrix.getUpVector();
	up.normalize();
	//up.scale( amount );

	translate( up );
}

void Transform::translateForward( float amount )
{
	if( magicalFltIsZero( amount ) )
		return;

	if( _local_has_changed != kLocalNotChanged )
		getLocalToWorldMatrix();

	Vec3 forward = _local_to_world_matrix.getForwardVector();
	forward.normalize();
	//forward.scale( amount );

	translate( forward );
}

const Quaternion& Transform::getRotation( void ) const
{
	return _local_rotation;
}

void Transform::setRotation( float qx, float qy, float qz, float qw )
{
	//if( MathQuaternion::equals( _local_rotation, qx, qy, qz, qw ) )
	//	return;

	_local_rotation.fill( qx, qy, qz, qw );
	transformChanged( kLocalRotationChanged );
}

void Transform::setRotation( const Quaternion& rotation )
{
	if( rotation == _local_rotation )
		return;

	_local_rotation.fill( rotation );
	transformChanged( kLocalRotationChanged );
}

void Transform::setRotation( const Vec3& axis, float angle )
{
	_local_rotation.fillAxisAngle( axis, angle );
	transformChanged( kLocalRotationChanged );
}

void Transform::setRotationX( float angle )
{
	Quaternion rot( Vec3::Right, angle );
	if( rot == _local_rotation )
		return;

	_local_rotation = rot;
	transformChanged( kLocalRotationChanged );
}

void Transform::setRotationY( float angle )
{
	Quaternion rot( Vec3::Up, angle );
	if( rot == _local_rotation )
		return;

	_local_rotation = rot;
	transformChanged( kLocalRotationChanged );
}

void Transform::setRotationZ( float angle )
{
	Quaternion rot( Vec3::Forward, angle );
	if( rot == _local_rotation )
		return;

	_local_rotation = rot;
	transformChanged( kLocalRotationChanged );
}

void Transform::rotate( float qx, float qy, float qz, float qw )
{
	Quaternion rot( qx, qy, qz, qw );
	_local_rotation *= rot;
	transformChanged( kLocalRotationChanged );
}

void Transform::rotate( const Quaternion& rotation )
{
	_local_rotation *= rotation;
	transformChanged( kLocalRotationChanged );
}

void Transform::rotate( const Vec3& axis, float angle )
{
	Quaternion rot( axis, angle );
	_local_rotation *= rot;
	_local_rotation.normalize();
	transformChanged( kLocalRotationChanged );
}

void Transform::rotateX( float angle )
{
	Quaternion rot( Vec3::Right, angle );
	_local_rotation *= rot;
	transformChanged( kLocalRotationChanged );
}

void Transform::rotateY( float angle )
{
	Quaternion rot( Vec3::Up, angle );
	_local_rotation *= rot;
	transformChanged( kLocalRotationChanged );
}

void Transform::rotateZ( float angle )
{
	Quaternion rot( Vec3::Forward, angle );
	_local_rotation *= rot;
	transformChanged( kLocalRotationChanged );
}

const Vec3& Transform::getScale() const
{
	return _local_scale;
}

void Transform::setScale( float scale )
{
	//if( MathVec3::equals( _local_scale, scale, scale, scale ) )
	//	return;

	_local_scale.fill( scale, scale, scale );
	transformChanged( kLocalScaleChanged );
}

void Transform::setScale( float x, float y, float z )
{
	//if( MathVec3::equals( _local_scale, x, y, z ) )
	//	return;

	_local_scale.fill( x, y, z );
	transformChanged( kLocalScaleChanged );
}

void Transform::setScale( const Vec3& scale )
{
	if( scale == _local_scale )
		return;

	_local_scale.fill( scale );
	transformChanged( kLocalScaleChanged );
}

void Transform::setScaleX( float x )
{
	if( magicalFltEqual( _local_scale.x, x ) )
		return;

	_local_scale.x = x;
	transformChanged( kLocalScaleChanged );
}

void Transform::setScaleY( float y )
{
	if( magicalFltEqual( _local_scale.y, y ) )
		return;

	_local_scale.y = y;
	transformChanged( kLocalScaleChanged );
}

void Transform::setScaleZ( float z )
{
	if( magicalFltEqual( _local_scale.z, z ) )
		return;

	_local_scale.z = z;
	transformChanged( kLocalScaleChanged );
}

void Transform::scale( float scaler )
{
	if( magicalFltEqual( scaler, 1.f ) )
		return;

	//_local_scale.scale( scaler );
	transformChanged( kLocalScaleChanged );
}

void Transform::scale( float x, float y, float z )
{
	if( magicalFltEqual( x, 1.f ) &&
		magicalFltEqual( y, 1.f ) && 
		magicalFltEqual( z, 1.f ) )
		return;

	_local_scale.x *= x;
	_local_scale.y *= y;
	_local_scale.z *= z;
	transformChanged( kLocalScaleChanged );
}

void Transform::scale( const Vec3& scaler )
{
	if( scaler.isOne() )
		return;

	_local_scale.x *= scaler.x;
    _local_scale.y *= scaler.y;
    _local_scale.z *= scaler.z;
	transformChanged( kLocalScaleChanged );
}

void Transform::scaleX( float x )
{
	if( magicalFltEqual( x, 1.f ) )
		return;

	_local_scale.x *= x;
	transformChanged( kLocalScaleChanged );
}

void Transform::scaleY( float y )
{
	if( magicalFltEqual( y, 1.f ) )
		return;

	_local_scale.y *= y;
	transformChanged( kLocalScaleChanged );
}

void Transform::scaleZ( float z )
{
	if( magicalFltEqual( z, 1.f ) )
		return;

	_local_scale.z *= z;
	transformChanged( kLocalScaleChanged );
}

Vec3 Transform::transformPoint( const Vec3& point ) const
{
	if( _local_has_changed != kLocalNotChanged )
		getLocalToWorldMatrix();
	
	return _local_to_world_matrix.transformVec3( point );
}

Vec3 Transform::transformPoint( float x, float y, float z ) const
{
	return transformPoint( Vec3( x, y, z ) );
}

Vec3 Transform::transformVector( const Vec3& vec ) const
{
	if( _local_has_changed != kLocalNotChanged )
		getLocalToWorldMatrix();

	return _local_to_world_matrix.transformVec3( vec );
}

Vec3 Transform::transformVector( float x, float y, float z ) const
{
	return transformVector( Vec3( x, y, z ) );
}

void Transform::lookAt( const Vec3& target, const Vec3& up )
{
	//Mat4 mat;
	//mat.fillLookAt( _local_position, target, up );
	
	//Quaternion rot = mat.getRotation();
	//if( rot == _local_rotation )
	//	return;

	//setRotation( rot );
}

void Transform::resetTransform( void )
{
	_local_scale.fillOne();
	_local_rotation.fillIdentity();
	_local_position.fillZero();
	transformChanged( kLocalScaleChanged | kLocalTranslationChanged | kLocalRotationChanged  );
}

void Transform::transformChanged( char changed )
{
	_local_has_changed |= changed;
}
