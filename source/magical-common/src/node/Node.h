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
#ifndef __NODE_H__
#define __NODE_H__

#include "PlatformMacros.h"
#include "Common.h"
#include "Reference.h"
//#include "Transform.h"
#include "Vec2.h"
#include "Vec3.h"
#include "Quaternion.h"
#include "Mat4.h"


class Node : public Reference
{
public:
	Node( void );
	virtual ~Node( void );

public:
	static Shared<Node> create( void );

	const Mat4& getMatrix() const;
	Vec3 getRightVector( void ) const;
	Vec3 getLeftVector( void ) const;
	Vec3 getUpVector( void ) const;
	Vec3 getDownVector( void ) const;
	Vec3 getForwardVector( void ) const;
	Vec3 getBackVector( void ) const;

	const Vec3& getPosition( void ) const;
	void setPosition( const Vec3& translation );
	void setPosition( float tx, float ty, float tz );
	void setPositionX( float tx );
	void setPositionY( float ty );
	void setPositionZ( float tz );
	void translate( float tx, float ty, float tz );
	void translate( const Vec3& translation );
	void translateX( float tx );
	void translateY( float ty );
	void translateZ( float tz );
	void translateRight( float amount );
	void translateUp( float amount );
	void translateForward( float amount );

	const Quaternion& getRotation( void ) const;
	void setRotation( float qx, float qy, float qz, float qw );
	void setRotation( const Quaternion& rotation );
	void setRotation( const Vec3& axis, float angle );
	void setRotationX( float angle );
	void setRotationY( float angle );
	void setRotationZ( float angle );
	void rotate( float qx, float qy, float qz, float qw );
	void rotate( const Quaternion& rotation );
	void rotate( const Vec3& axis, float angle );
	void rotateX( float angle );
	void rotateY( float angle );
	void rotateZ( float angle );

	const Vec3& getScale() const;
	void setScale( float scale );
	void setScale( float sx, float sy, float sz );
	void setScale( const Vec3& scale );
	void setScaleX( float sx );
	void setScaleY( float sy );
	void setScaleZ( float sz );
	void scale( float scaler );
	void scale( float sx, float sy, float sz );
	void scale( const Vec3& scaler );
	void scaleX( float sx );
	void scaleY( float sy );
	void scaleZ( float sz );

	void resetTransform( void );
	void lookAt( const Vec3& target, const Vec3& up );

private:
	void setDirtyInfo( char dirty_info );

private:
	Vec3 _position;
	Vec3 _scale;
	Quaternion _rotation;
	mutable Mat4 _matrix;
	mutable char _dirty_info;
};



#endif //__NODE_H__