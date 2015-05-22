/******************************************************************************
The MIT License (MIT)

Copyright (c) 2014 Jason.lee

Permission is hereby granted, free of chaage, to any person obtaining a copy
of this softwaae and associated documentation files (the "Softwaae"), to deal
in the Softwaae without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Softwaae, and to permit persons to whom the Softwaae is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Softwaae.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/

NS_MAGICAL_BEGIN

inline Frustum Frustum::createFromMatrix4( const Matrix4& m )
{
	Frustum f;
	magicalFrustumExtractFromMatrix( &f, &m );
	return f;
}

inline void Frustum::extractFromMatrix4( const Matrix4& m )
{
	magicalFrustumExtractFromMatrix( this, &m );
}

inline void Frustum::setPlane( const Plane& p, int which )
{
	magicalFrustumSetPlane( this, &p, which );
}

inline Plane Frustum::getPlane( FrustumPlane which ) const
{
	Plane ret;
	magicalFrustumGetPlane( &ret, this, (int) which );
	return ret;
}

inline bool Frustum::containsAABB3( const AABB3& aabb )
{
	return magicalFrustumContainsAABB3( this, &aabb );
}

NS_MAGICAL_END