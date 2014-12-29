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
	Local,
	World,
};

class Node : public Reference
{
public:
	Node( void );
	virtual ~Node( void );

public:
	static Shared<Node> create( void );

public:
	virtual void addChild( const Node* child );

public:
	void setPosition( const Vector3& v );
	void setPosition( const Vector2& v );
	void setPosition( float x, float y, float z );
	const Vector3& getPosition( void ) const;
	void setRotation( const Quaternion& q );
	void setRotation( const EulerAngles& ea );
	void setRotation( float yaw, float pitch, float roll );
	const Quaternion& getRotation( void ) const;
	void setScale( const Vector3& s );
	void setScale( float x, float y, float z );
	const Vector3& getScale( void ) const;

private:
	void transformChanged( int flag );

private:
	std::unordered_map<int, Shared<Node> > _children;

	bool _inherit_scale = true;
	bool _inherit_rotation = true;
	int _has_changed = true;
	Matrix4 _local_to_world_matrix;
	Vector3 _local_position;
	Quaternion _local_rotation;
	Vector3 _local_scale;
	Vector3 _world_position;
	Quaternion _world_rotation;
	Vector3 _world_scale;
};

#endif //__NODE_H__