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
#include "magical-math.h"
#include <vector>

NS_MAGICAL_BEGIN

enum class Space
{
	Self,
	Parent,
	World,
};

template< class T >
class Transform : public Reference
{
public:
	Transform( void )
	: m_ts_dirty_info( kTsClean )
	{
		
	}

	virtual ~Transform( void )
	{
		
	}

public:
	bool isChildOf( const Ptr<T>& parent ) const
	{
		magicalAssert( parent != nullptr, "Invaild! should not be nullptr" );
		return m_parent == parent.get();
	}

	size_t childrenCount( void ) const
	{
		return m_children.size();
	}

	T* getParent( void ) const
	{
		return m_parent;
	}

	T* findChild( const char* name ) const
	{
		magicalAssert( name && *name, "name should not be empty" );
	
		auto ritr = m_children.rbegin();
		for( ; ritr != m_children.rend(); ++ritr )
		{
			T* child = *ritr;
			if( child->getName() == name )
			{
				return child;
			}
		}
		return nullptr;
	}

	T* childAtIndex( size_t i ) const
	{
		magicalAssert( i < m_children.size(), "Invaild index!" );
		return m_children[ i ];
	}

	void addChild( const Ptr<T>& child )
	{
		T* rchild = child.get();
		magicalAssert( rchild && rchild != this && !rchild->getParent(), "Invaild!" );

		rchild->setParent( this );

		rchild->retain();
		m_children.push_back( rchild );
	}

	void removeChild( const Ptr<T>& child )
	{
		T* rchild = child.get();
		magicalAssert( rchild && rchild->getParent() == this, "Invaild!" );

		auto itr = std::find( m_children.begin(), m_children.end(), rchild );
		magicalAssert( itr != m_children.end(), "Invaild!" );

		rchild->setParent( nullptr );
		m_children.erase( itr );
		rchild->release();
	}

	void removeAllChildren( void );
	void removeFromParent( void );

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
	void lookAt( const Vector3& target, const Vector3& up );
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
	void setParent( Transform* parent );
	void transform( void );
	void transformDirty( int info );
	const Vector3& getDerivedPosition( void ) const;
	const Quaternion& getDerivedRotation( void ) const;
	const Vector3& getDerivedScale( void ) const;

protected:
	friend class Scene;
	T* m_parent = nullptr;
	vector<T*> m_children;
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

#endif //__TRANSFORM_H__