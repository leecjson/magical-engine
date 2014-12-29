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
#include "magical-math.h"

#include <unordered_map>
#include "Reference.h"

enum class Space
{
	Self,
	Parent,
	World,
};

enum
{
	kHasNotChanged = 0x00,
	kNeedToUpdateTranslation = 0x01,
	kNeedToUpdateRotation = 0x02,
	kNeedToUpdateScale = 0x04,
};

class Node : public Reference
{
public:
	Node( void );
	virtual ~Node( void );

public:
	static Shared<Node> create( void );

public:
	void addChild( Shared<Node>& child );
	void removeChild( Shared<Node>& child );
	void setParent( Shared<Node>& parent );
	void removeParent( Shared<Node>& parent );
	Node* getChild( void ) const;
	Node* getParent( void ) const;

public:
	void setPosition( const Vector2& t );
	void setPosition( const Vector3& t );
	void setPosition( float x, float y );
	void setPosition( float x, float y, float z );
	const Vector3& getPosition( void ) const;
	void translate( const Vector2& t, Space relative );
	void translate( const Vector3& t, Space relative );
	void translate( float x, float y, Space relative );
	void translate( float x, float y, float z, Space relative );
	
	void setRotation( const EulerAngles& r );
	void setRotation( const Quaternion& r );
	void setRotation( float yaw, float pitch, float roll );
	const Quaternion& getRotation( void ) const;
	void rotate( const EulerAngles& r, Space relative );
	void rotate( const Quaternion& r, Space relative );
	void rotate( float yaw, float pitch, float roll, Space relative );
	void yaw( float yaw, Space relative );
	void pitch( float pitch, Space relative );
	void roll( float roll, Space relative );

	void setScale( const Vector3& s );
	void setScale( float x, float y, float z );
	const Vector3& getScale( void ) const;
	void scale( const Vector2& s );
	void scale( const Vector3& s );
	void scale( float x, float y );
	void scale( float x, float y, float z );
	void scale( float s );

	void updateTransform( void );

private:
	const Vector3& getDerivedPosition( void ) const;
	const Quaternion& getDerivedRotation( void ) const;
	const Vector3& getDerivedScale( void ) const;

private:
	Node* _parent = nullptr;
	std::unordered_map<int, Node*> _children;

	bool _inherit_scale = true;
	bool _inherit_rotation = true;
	int _ts_need_update = kHasNotChanged;

	Matrix4 _local_to_world_matrix = Matrix4::Identity;
	Vector3 _local_position = Vector3::Zero;
	Quaternion _local_rotation = Quaternion::Identity;
	Vector3 _local_scale = Vector3::One;

	mutable Vector3 _derived_position = Vector3::Zero;
	mutable Quaternion _derived_rotation = Quaternion::Identity;
	mutable Vector3 _derived_scale = Vector3::One;
};

#endif //__NODE_H__