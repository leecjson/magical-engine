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
#include "../c/cFrustum.h"
#include "../c/cMatrix4.h"
#include "../c/cPlane.h"

#include "Utility.h"
#include "Frustum.h"
#include "Matrix4.h"
#include "Plane.h"

#include "Frustum.inl"

NS_MAGICAL_BEGIN

Frustum::Frustum( const Frustum& frustum )
{
	magicalFrustumCopy( this, &frustum );
}

Frustum::Frustum( void )
{

}

NS_MAGICAL_END
