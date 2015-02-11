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
#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__

#include "magical-macros.h"
#include "Common.h"
#include "Reference.h"
#include "magical-math.h"
#include "SceneElement.h"
#include <vector>

NS_MAGICAL_BEGIN

using ::std::string;
using ::std::vector;

enum class Space
{
	Self,
	Parent,
	World,
};

enum class NodeEvent
{
	Add,
	Remove,
};

class SceneObject : public Reference
{
public:
	friend class Scene;
	friend class Engine;
	typedef vector<SceneObject*> Children;
	declare_class_hash_code;
	
public:
	SceneObject( void );
	virtual ~SceneObject( void );
	static Ptr<SceneObject> create( void );
	static Ptr<SceneObject> create( const char* name );

protected:
	virtual void visit( void );
	virtual void start( void );
	virtual void stop( void );

public:
	void setName( const char* name );
	const string& getName( void ) const { return m_name; }
	void setVisible( bool visible );
	bool isVisible( void ) const { return m_is_visible; }
	bool isRunning( void ) const { return m_is_running; }
	SceneElement getElementId( void ) const { return m_element_id; }

public:
	bool isChildOf( const Ptr<SceneObject>& parent ) const;
	size_t childCount( void ) const { return m_children.size(); }
	SceneObject* getParent( void ) const { return m_parent; }
	SceneObject* findChild( const char* name ) const;
	SceneObject* childAtIndex( size_t i ) const;
	void addChild( const Ptr<SceneObject>& child );
	void setParent( const Ptr<SceneObject>& parent );
	void removeChild( const Ptr<SceneObject>& child );
	void removeAllChildren( void );
	void removeSelf( void );

public:
	void translate( const Vector2& t, Space relative_to = Space::Parent );
	void translate( const Vector3& t, Space relative_to = Space::Parent );
	void translate( float x, float y, Space relative_to = Space::Parent );
	void translate( float x, float y, float z, Space relative_to = Space::Parent );
	void setPosition( const Vector2& t );
	void setPosition( const Vector3& t );
	void setPosition( float x, float y );
	void setPosition( float x, float y, float z );
	const Vector3& getPosition( void ) const;

public:
	void yaw( float yaw, Space relative_to = Space::Self );
	void pitch( float pitch, Space relative_to = Space::Self );
	void roll( float roll, Space relative_to = Space::Self );
	void lookAt( const Vector3& target, const Vector3& up = Vector3::Up );
	void lookAt( float x, float y, float z, const Vector3& up = Vector3::Up );
	void rotate( const EulerAngles& r, Space relative_to = Space::Self );
	void rotate( const Quaternion& r, Space relative_to = Space::Self );
	void rotate( float yaw, float pitch, float roll, Space relative_to = Space::Self );
	void setRotation( const EulerAngles& r );
	void setRotation( const Quaternion& r );
	void setRotation( float yaw, float pitch, float roll );
	const Quaternion& getRotation( void ) const;

public:
	void scale( const Vector2& s );
	void scale( const Vector3& s );
	void scale( float x, float y );
	void scale( float x, float y, float z );
	void scale( float s );
	void setScale( const Vector2& s );
	void setScale( const Vector3& s );
	void setScale( float x, float y );
	void setScale( float x, float y, float z );
	const Vector3& getScale( void ) const;

protected:
	void transformDirty( int info );
	const Vector3& getDerivedPosition( void ) const;
	const Quaternion& getDerivedRotation( void ) const;
	const Vector3& getDerivedScale( void ) const;
	virtual void childEvent( NodeEvent evt, SceneObject* child );
	virtual void childEvent( NodeEvent evt, const Children& children );

protected:
	string m_name;
	SceneElement m_element_id;
	bool m_is_visible = false;
	bool m_is_running = false;
	Children m_children;
	SceneObject* m_parent = nullptr;
	bool m_inherit_scale = true;
	bool m_inherit_rotation = true;
	mutable int m_ts_dirty_info;
	bool m_ts_dirty = false;
	Vector3 m_local_position;
	Quaternion m_local_rotation;
	Vector3 m_local_scale = Vector3::One;
	Matrix4 m_local_to_world_matrix;
	mutable Vector3 m_derived_position;
	mutable Quaternion m_derived_rotation;
	mutable Vector3 m_derived_scale = Vector3::One;
};

NS_MAGICAL_END

#endif //__SCENE_OBJECT_H__