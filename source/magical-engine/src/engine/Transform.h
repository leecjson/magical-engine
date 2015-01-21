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
#include "magical-math.h"
#include "Reference.h"

#include <vector>

NS_MAGICAL_BEGIN

enum class Space
{
	Self,
	Parent,
	World,
};

class Transform : public Reference
{
public:
	Transform( void );
	virtual ~Transform( void );

public:
	void setName( const char* name );
	const std::string& getName( void ) const;
	void addChild( const Ptr<Transform>& child );
	void removeChild( const Ptr<Transform>& child );
	void removeAllChildren( void );
	void removeFromParent( void );
	Transform* findChild( const char* name ) const;
	Transform* getChild( unsigned int index ) const;
	unsigned int childrenCount( void ) const;
	Transform* getParent( void ) const;
	bool isChildOf( const Ptr<Transform>& parent ) const;
	
public:
	void setPosition( const Vector2& t );
	void setPosition( const Vector3& t );
	void setPosition( float x, float y );
	void setPosition( float x, float y, float z );
	void translate( const Vector2& t, Space relative_to = Space::Parent );
	void translate( const Vector3& t, Space relative_to = Space::Parent );
	void translate( float x, float y, Space relative_to = Space::Parent );
	void translate( float x, float y, float z, Space relative_to = Space::Parent );
	const Vector3& getPosition( void ) const;

public:
	void setRotation( const EulerAngles& r );
	void setRotation( const Quaternion& r );
	void setRotation( float yaw, float pitch, float roll );
	void rotate( const EulerAngles& r, Space relative_to = Space::Self );
	void rotate( const Quaternion& r, Space relative_to = Space::Self );
	void rotate( float yaw, float pitch, float roll, Space relative_to = Space::Self );
	void yaw( float yaw, Space relative_to = Space::Self );
	void pitch( float pitch, Space relative_to = Space::Self );
	void roll( float roll, Space relative_to = Space::Self );
	const Quaternion& getRotation( void ) const;

public:
	void setScale( const Vector2& s );
	void setScale( const Vector3& s );
	void setScale( float x, float y );
	void setScale( float x, float y, float z );
	void scale( const Vector2& s );
	void scale( const Vector3& s );
	void scale( float x, float y );
	void scale( float x, float y, float z );
	void scale( float s );
	const Vector3& getScale( void ) const;

public:
	void lookAt( const Vector3& target, const Vector3& up );
	void resetTransform( void );
	const Vector3& getDerivedPosition( void ) const;
	const Quaternion& getDerivedRotation( void ) const;
	const Vector3& getDerivedScale( void ) const;

protected:
	void setParent( Transform* parent );
	void updateChildrenTransform( Transform* ts );
	void updateTransform( void );
	void onTransform( int f );

protected:
	std::string _name;
	Transform* _parent = nullptr;
	typedef std::vector< Transform* > ChildrenList;
	ChildrenList _children;

protected:
	bool _inherit_scale = true;
	bool _inherit_rotation = true;
	mutable int _ts_need_update = 0;
	bool _ts_dirty = false;
	Matrix4 _local_to_world_matrix;
	Vector3 _local_position;
	Quaternion _local_rotation;
	Vector3 _local_scale = Vector3::One;
	mutable Vector3 _derived_position;
	mutable Quaternion _derived_rotation;
	mutable Vector3 _derived_scale = Vector3::One;
};

NS_MAGICAL_END

#endif //__TRANSFORM_H__