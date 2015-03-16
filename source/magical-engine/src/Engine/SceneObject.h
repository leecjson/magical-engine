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
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "magical-macros.h"
#include "Common.h"
#include "Reference.h"
#include "Element.h"
#include "magical-math.h"
#include <vector>

NS_MAGICAL_BEGIN

class Scene;
class Camera;

using ::std::string;
using ::std::vector;

enum : int
{
	kTsClean = 0x00,
	kTsTranslationDirty = 0x01,
	kTsRotationDirty = 0x02,
	kTsScaleDirty = 0x04,
};

enum class Space : int
{
	Self,
	Parent,
	World,
};

class SceneObject : public Reference
{
public:
	friend class Scene;
	typedef vector<SceneObject*> Children;
	
public:
	member_method SceneObject( void );
	member_method virtual ~SceneObject( void );
	static_method Ptr<SceneObject> Create( void );
	static_method Ptr<SceneObject> Create( const char* name );

public:
	member_method void SetName( const char* name );
	member_method const string& GetName( void ) const { return m_name; }
	member_method virtual void SetVisible( bool visible );
	member_method bool IsVisiable( void ) const { return m_visible; }
	member_method bool IsRunning( void ) const { return m_running; }
	member_method Element ElementEnum( void ) const { return m_element_enum; }

public:
	member_method bool IsChildOf( const Ptr<SceneObject>& parent ) const;
	member_method size_t ChildCount( void ) const { return m_children.size(); }
	member_method SceneObject* GetParent( void ) const { return m_parent; }
	member_method SceneObject* FindChild( const char* name ) const;
	member_method SceneObject* ChildAtIndex( size_t i ) const;
	member_method virtual void AddChild( const Ptr<SceneObject>& child );
	member_method virtual void SetParent( const Ptr<SceneObject>& parent );
	member_method virtual void RemoveChild( const Ptr<SceneObject>& child );
	member_method virtual void RemoveChild( const char* name );
	member_method virtual void RemoveAllChildren( void );
	member_method virtual void RemoveSelf( void );

public:
	member_method void Translate( const Vector2& t, Space relative_to = Space::Parent );
	member_method void Translate( const Vector3& t, Space relative_to = Space::Parent );
	member_method void Translate( float x, float y, Space relative_to = Space::Parent );
	member_method void Translate( float x, float y, float z, Space relative_to = Space::Parent );
	member_method void SetPosition( const Vector2& t );
	member_method void SetPosition( const Vector3& t );
	member_method void SetPosition( float x, float y );
	member_method void SetPosition( float x, float y, float z );
	member_method const Vector3& GetPosition( void ) const;

public:
	member_method void Yaw( float yaw, Space relative_to = Space::Self );
	member_method void Pitch( float pitch, Space relative_to = Space::Self );
	member_method void Roll( float roll, Space relative_to = Space::Self );
	member_method void LookAt( const Vector3& target, const Vector3& up = Vector3::Up );
	member_method void LookAt( float x, float y, float z, const Vector3& up = Vector3::Up );
	member_method void Rotate( const EulerAngles& r, Space relative_to = Space::Self );
	member_method void Rotate( const Quaternion& r, Space relative_to = Space::Self );
	member_method void Rotate( float yaw, float pitch, float roll, Space relative_to = Space::Self );
	member_method void SetRotation( const EulerAngles& r );
	member_method void SetRotation( const Quaternion& r );
	member_method void SetRotation( float yaw, float pitch, float roll );
	member_method const Quaternion& GetRotation( void ) const;

public:
	member_method void Scale( const Vector2& s );
	member_method void Scale( const Vector3& s );
	member_method void Scale( float x, float y );
	member_method void Scale( float x, float y, float z );
	member_method void Scale( float s );
	member_method void SetScale( const Vector2& s );
	member_method void SetScale( const Vector3& s );
	member_method void SetScale( float x, float y );
	member_method void SetScale( float x, float y, float z );
	member_method const Vector3& GetScale( void ) const;

public:
	member_method virtual void Link( SceneObject* child );
	member_method virtual void Unlink( SceneObject* child );
	member_method virtual void Visit( Camera* camera );
	member_method virtual void Draw( void );
	member_method virtual void Start( void );
	member_method virtual void Stop( void );
	member_method virtual void Transform( void );

public:
	member_method void SetRootScene( Scene* scene );
	member_method virtual void TransformDirty( int info );
	member_method const Vector3& GetDerivedPosition( void ) const;
	member_method const Quaternion& GetDerivedRotation( void ) const;
	member_method const Vector3& GetDerivedScale( void ) const;
	member_method const Matrix4& GetLocalToWorldMatrix( void ) const;
	
protected:
	string m_name;
	Scene* m_root_scene = nullptr;
	Element m_element_enum;
	bool m_visible = true;
	bool m_running = false;
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

#endif //__OBJECT_H__