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

#include <vector>
#include "Reference.h"

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
	static Shared<Transform> Create( void );

public:
	void SetName( const char* name );
	const std::string& GetName( void ) const;

public:
	void addChild( const Shared<Transform>& child );
	void removeChild( const Shared<Transform>& child );
	void removeAllChildren( void );
	void removeFromParent( void );
	Transform* findChild( const char* name ) const;
	Transform* getChild( unsigned int index ) const;
	unsigned int childrenCount( void ) const;
	Transform* getParent( void ) const;
	bool isChildOf( const Shared<Transform>& parent ) const;
	
public:
	void SetPosition( const Vector2& t );
	void SetPosition( const Vector3& t );
	void SetPosition( float x, float y );
	void SetPosition( float x, float y, float z );
	void Translate( const Vector2& t, Space relative_to );
	void Translate( const Vector3& t, Space relative_to );
	void Translate( float x, float y, Space relative_to );
	void Translate( float x, float y, float z, Space relative_to );
	const Vector3& GetPosition( void ) const;

public:
	void SetRotation( const EulerAngles& r );
	void SetRotation( const Quaternion& r );
	void SetRotation( float yaw, float pitch, float roll );
	void Rotate( const EulerAngles& r, Space relative_to );
	void Rotate( const Quaternion& r, Space relative_to );
	void Rotate( float yaw, float pitch, float roll, Space relative_to );
	void Yaw( float yaw, Space relative_to );
	void Pitch( float pitch, Space relative_to );
	void Roll( float roll, Space relative_to );
	const Quaternion& GetRotation( void ) const;

public:
	void SetScale( const Vector2& s );
	void SetScale( const Vector3& s );
	void SetScale( float x, float y );
	void SetScale( float x, float y, float z );
	void Scale( const Vector2& s );
	void Scale( const Vector3& s );
	void Scale( float x, float y );
	void Scale( float x, float y, float z );
	void Scale( float s );
	const Vector3& GetScale( void ) const;

public:
	void LookAt( const Vector3& target, const Vector3& up );
	void ResetTransform( void );

private:
	void SetParent( Transform* parent );
	void UpdateChildrenTransform( Transform* ts );
	void UpdateTransform( void );
	void NeedToUpdate( int flag );
	const Vector3& GetDerivedPosition( void ) const;
	const Quaternion& GetDerivedRotation( void ) const;
	const Vector3& GetDerivedScale( void ) const;

private:
	std::string name_;
	Transform* parent_ = nullptr;
	std::vector<Transform*> children_;

private:
	bool inherit_scale_ = true;
	bool inherit_rotation_ = true;
	mutable int ts_need_update_ = 0;
	bool ts_dirty_ = false;
	Matrix4 local_to_world_matrix_;
	Vector3 local_position_;
	Quaternion local_rotation_;
	Vector3 local_scale_ = Vector3::One;
	mutable Vector3 derived_position_;
	mutable Quaternion derived_rotation_;
	mutable Vector3 derived_scale_ = Vector3::One;
};

#endif //__TRANSFORM_H__