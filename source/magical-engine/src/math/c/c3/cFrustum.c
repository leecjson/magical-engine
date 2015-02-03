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
#include "cFrustum.h"

void magicalFrustumFill( cFrustum* out, const cMatrix4* m )
{
	cPlane3 setter;

	// left
	setter.x = m->m14 + m->m11;
	setter.y = m->m24 + m->m21;
	setter.z = m->m34 + m->m31;
	setter.d = m->m44 + m->m41;
	magicalPlane3Nor

	AABBFill(  )

	_plane[0].initPlane(-C3DVector3(mat.m[3] + mat.m[0], mat.m[7] + mat.m[4], mat.m[11] + mat.m[8]), (mat.m[15] + mat.m[12]));//left

	magicalFrustumSetPlane( out, &setter, cFrustumLeft );
}

void magicalFrustumSetPlane( cFrustum* out, const cPlane3* p, int which )
{
	out->frustum[which + 0] = p->x;
	out->frustum[which + 1] = p->y;
	out->frustum[which + 2] = p->z;
	out->frustum[which + 3] = p->d;
}