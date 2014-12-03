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
#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "PlatformMacros.h"
#include "Common.h"
#include "Reference.h"
//#include "cpp/Vec2.h"
//#include "cpp/Vec3.h"
//#include "cpp/Quaternion.h"
//#include "cpp/Mat4.h"

class Transform : public Reference
{
public:
	Transform( void );
	virtual ~Transform( void );

public:
	static Shared<Transform> create( void );
//
//public:
//	const Mat4& getLocalToWorldMatrix() const;
//
//	Vec3 getRightVector( void ) const;
//	Vec3 getLeftVector( void ) const;
//	Vec3 getUpVector( void ) const;
//	Vec3 getDownVector( void ) const;
//	Vec3 getForwardVector( void ) const;
//	Vec3 getBackVector( void ) const;
//
//	const Vec3& getPosition( void ) const;
//	void setPosition( const Vec3& translation );
//	void setPosition( float x, float y, float z );
//	void setPositionX( float x );
//	void setPositionY( float y );
//	void setPositionZ( float z );
//	void translate( float x, float y, float z );
//	void translate( const Vec3& translation );
//	void translateX( float x );
//	void translateY( float y );
//	void translateZ( float z );
//	void translateRight( float amount );
//	void translateUp( float amount );
//	void translateForward( float amount );
//
//	const Quaternion& getRotation( void ) const;
//	void setRotation( float qx, float qy, float qz, float qw );
//	void setRotation( const Quaternion& rotation );
//	void setRotation( const Vec3& axis, float angle );
//	void setRotationX( float angle );
//	void setRotationY( float angle );
//	void setRotationZ( float angle );
//	void rotate( float qx, float qy, float qz, float qw );
//	void rotate( const Quaternion& rotation );
//	void rotate( const Vec3& axis, float angle );
//	void rotateX( float angle );
//	void rotateY( float angle );
//	void rotateZ( float angle );
//
//	const Vec3& getScale() const;
//	void setScale( float scale );
//	void setScale( float x, float y, float z );
//	void setScale( const Vec3& scale );
//	void setScaleX( float x );
//	void setScaleY( float y );
//	void setScaleZ( float z );
//	void scale( float scaler );
//	void scale( float x, float y, float z );
//	void scale( const Vec3& scaler );
//	void scaleX( float x );
//	void scaleY( float y );
//	void scaleZ( float z );
//
//	Vec3 transformPoint( const Vec3& point ) const;
//	Vec3 transformPoint( float x, float y, float z ) const;
//	Vec3 transformVector( const Vec3& vec ) const;
//	Vec3 transformVector( float x, float y, float z ) const;
//
//	void lookAt( const Vec3& target, const Vec3& up );
//	void resetTransform( void );
//
//private:
//	void transformChanged( char changed );
//
//private:
//	Vec3 _local_position;
//	Quaternion _local_rotation;
//	Vec3 _local_scale;
//	mutable Mat4 _local_to_world_matrix;
//	mutable char _local_has_changed;
};

#endif //__TRANSFORM_H__