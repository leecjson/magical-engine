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

class Node : public Reference
{
public:
	Node( void );
	virtual ~Node( void );

public:
	static Shared<Node> create( void );
	static Shared<Node> create( const char* name );
	static Shared<Node> create( const Vector3& t, const Quaternion& r, const Vector3& s );

public:
	void setName( const char* name );
	const std::string& getName( void ) const;
	void addChild( const Shared<Node>& child );
	void removeChild( const Shared<Node>& child );
	void removeAllChildren( void );
	void removeFromParent( void );
	Node* getChild( const char* name ) const;
	Node* getChild( uint32_t index ) const;
	uint32_t childrenCount( void ) const;
	Node* getParent( void ) const;
	bool isChildOf( const Shared<Node>& parent ) const;
	
	void updateTransform( void );
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
	void setScale( const Vector2& s );
	void setScale( const Vector3& s );
	void setScale( float x, float y );
	void setScale( float x, float y, float z );
	const Vector3& getScale( void ) const;
	void scale( const Vector2& s );
	void scale( const Vector3& s );
	void scale( float x, float y );
	void scale( float x, float y, float z );
	void scale( float s );
	void lookAt( const Vector3& target, const Vector3& up );

private:
	void setParent( Node* parent );
	const Vector3& getDerivedPosition( void ) const;
	const Quaternion& getDerivedRotation( void ) const;
	const Vector3& getDerivedScale( void ) const;

private:
	std::string _name;
	Node* _parent = nullptr;
	std::vector<Node*> _children;

	bool _inherit_scale = true;
	bool _inherit_rotation = true;
	int _ts_need_update = 0;

	Matrix4 _local_to_world_matrix;
	Vector3 _local_position;
	Quaternion _local_rotation;
	Vector3 _local_scale = Vector3::One;
	mutable Vector3 _derived_position;
	mutable Quaternion _derived_rotation;
	mutable Vector3 _derived_scale = Vector3::One;
};

#endif //__NODE_H__