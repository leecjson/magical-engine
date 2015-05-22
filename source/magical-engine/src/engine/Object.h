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
#include "magical-math.h"
#include <vector>

NAMESPACE_MAGICAL

class Scene;
class Camera;

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

class Object : public Reference
{
public:
	friend class Scene;
	enum : int { Feature = 1 };

public:
	Object( void );
	virtual ~Object( void );
	static Ptr<Object> create( void );
	static Ptr<Object> create( const char* name );

public:
	bool isRunning( void ) const { return m_running; }
	bool isVisiable( void ) const { return m_visible; }
	virtual void setName( const char* name );
	virtual void setVisible( bool visible );
	const string& getName( void ) const { return m_name; }
	int getFeature( void ) const { return m_feature; }

public:
	bool isChildOf( const Object* parent ) const;
	size_t childCount( void ) const { return m_children.size(); }
	Object* getParent( void ) const { return m_parent; }
	Object* findChild( const char* name ) const;
	Object* childAtIndex( size_t i ) const;
	virtual void addChild( Object* child );
	virtual void setParent( Object* parent );
	virtual void removeChild( Object* child );
	virtual void removeChild( const char* name );
	virtual void removeAllChildren( void );
	virtual void removeSelf( void );

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
	void rotate( const Rotater& r, Space relative_to = Space::Self );
	void rotate( const Quaternion& r, Space relative_to = Space::Self ); 
	void rotate( float yaw, float pitch, float roll, Space relative_to = Space::Self );
	void setRotation( const Rotater& r );
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

public:
	virtual void link( Object* child );
	virtual void unlink( Object* child );
	virtual void visit( Camera* camera );
	//virtual void draw( void );
	virtual void start( void );
	virtual void stop( void );
	virtual void transform( void );

public:
	virtual void setRootScene( Scene* scene );
	virtual void transformDirty( int info );
	const Vector3& getDerivedPosition( void ) const;
	const Quaternion& getDerivedRotation( void ) const;
	const Vector3& getDerivedScale( void ) const;
	const Matrix4x4& getLocalToWorldMatrix( void ) const;

public:
	typedef std::vector<Object*> Children;

protected:
	string m_name;
	Scene* m_root_scene = nullptr;
	int m_feature = Object::Feature;
	bool m_visible = true;
	bool m_running = false;
	Object* m_parent = nullptr;
	Children m_children;
	bool m_inherit_scale = true;
	bool m_inherit_rotation = true;
	mutable int m_ts_dirty_info = kTsClean;
	bool m_ts_dirty = false;
	Vector3 m_local_position;
	Quaternion m_local_rotation;
	Vector3 m_local_scale = Vector3::One;
	Matrix4x4 m_local_to_world_matrix;
	mutable Vector3 m_derived_position;
	mutable Quaternion m_derived_rotation;
	mutable Vector3 m_derived_scale = Vector3::One;
};

NAMESPACE_END

#endif //__OBJECT_H__