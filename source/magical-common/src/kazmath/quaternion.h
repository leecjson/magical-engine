/*
Copyright (c) 2008, Luke Benstead.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef QUATERNION_H_INCLUDED
#define QUATERNION_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "utility.h"

struct kmMat4;
struct kmMat3;
struct kmVec3;

typedef struct kmQuaternion {
	kmScalar x;
	kmScalar y;
	kmScalar z;
	kmScalar w;
} kmQuaternion;

KMAPI int kmQuaternionAreEqual(const kmQuaternion* p1, const kmQuaternion* p2);
KMAPI kmQuaternion* kmQuaternionFill(kmQuaternion* pOut, kmScalar x, kmScalar y, kmScalar z, kmScalar w);
KMAPI kmScalar 	kmQuaternionDot(const kmQuaternion* q1, const kmQuaternion* q2); ///< Returns the dot product of the 2 quaternions

KMAPI kmQuaternion* kmQuaternionExp(kmQuaternion* pOut, const kmQuaternion* pIn); ///< Returns the exponential of the quaternion

///< Makes the passed quaternion an identity quaternion

KMAPI kmQuaternion* kmQuaternionIdentity(kmQuaternion* pOut);

///< Returns the inverse of the passed Quaternion

KMAPI kmQuaternion* kmQuaternionInverse(kmQuaternion* pOut, const kmQuaternion* pIn);

///< Returns true if the quaternion is an identity quaternion

KMAPI int kmQuaternionIsIdentity(const kmQuaternion* pIn);

///< Returns the length of the quaternion

KMAPI kmScalar kmQuaternionLength(const kmQuaternion* pIn);

///< Returns the length of the quaternion squared (prevents a sqrt)

KMAPI kmScalar kmQuaternionLengthSq(const kmQuaternion* pIn);

///< Returns the natural logarithm

KMAPI kmQuaternion* kmQuaternionLn(kmQuaternion* pOut, const kmQuaternion* pIn);

///< Multiplies 2 quaternions together

KMAPI kmQuaternion* kmQuaternionMultiply(kmQuaternion* pOut, const kmQuaternion* q1, const kmQuaternion* q2);

///< Normalizes a quaternion

KMAPI kmQuaternion* kmQuaternionNormalize(kmQuaternion* pOut, const kmQuaternion* pIn);

///< Rotates a quaternion around an axis

KMAPI kmQuaternion* kmQuaternionRotationAxisAngle(kmQuaternion* pOut, const struct kmVec3* pV, kmScalar angle);

///< Creates a quaternion from a rotation matrix

KMAPI kmQuaternion* kmQuaternionRotationMatrix(kmQuaternion* pOut, const struct kmMat3* pIn);

///< Create a quaternion from yaw, pitch and roll

KMAPI kmQuaternion* kmQuaternionRotationPitchYawRoll(kmQuaternion* pOut, kmScalar pitch, kmScalar yaw, kmScalar roll);
///< Interpolate between 2 quaternions
KMAPI kmQuaternion* kmQuaternionSlerp(kmQuaternion* pOut, const kmQuaternion* q1, const kmQuaternion* q2, kmScalar t);

///< Get the axis and angle of rotation from a quaternion
KMAPI void kmQuaternionToAxisAngle(const kmQuaternion* pIn, struct kmVec3* pVector, kmScalar* pAngle);

///< Scale a quaternion
KMAPI kmQuaternion* kmQuaternionScale(kmQuaternion* pOut, const kmQuaternion* pIn, kmScalar s);
KMAPI kmQuaternion* kmQuaternionAssign(kmQuaternion* pOut, const kmQuaternion* pIn);
KMAPI kmQuaternion* kmQuaternionAdd(kmQuaternion* pOut, const kmQuaternion* pQ1, const kmQuaternion* pQ2);
KMAPI kmQuaternion* kmQuaternionSubtract(kmQuaternion* pOut, const kmQuaternion* pQ1, const kmQuaternion* pQ2);

KMAPI kmQuaternion* kmQuaternionRotationBetweenVec3(kmQuaternion* pOut, const struct kmVec3* vec1, const struct kmVec3* vec2, const struct kmVec3* fallback);
KMAPI struct kmVec3* kmQuaternionMultiplyVec3(struct kmVec3* pOut, const kmQuaternion* q, const struct kmVec3* v);

KMAPI kmVec3* kmQuaternionGetUpVec3(kmVec3* pOut, const kmQuaternion* pIn);
KMAPI kmVec3* kmQuaternionGetRightVec3(kmVec3* pOut, const kmQuaternion* pIn);
KMAPI kmVec3* kmQuaternionGetForwardVec3RH(kmVec3* pOut, const kmQuaternion* pIn);
KMAPI kmVec3* kmQuaternionGetForwardVec3LH(kmVec3* pOut, const kmQuaternion* pIn);

KMAPI kmScalar kmQuaternionGetPitch(const kmQuaternion* q);
KMAPI kmScalar kmQuaternionGetYaw(const kmQuaternion* q);
KMAPI kmScalar kmQuaternionGetRoll(const kmQuaternion* q);

KMAPI kmQuaternion* kmQuaternionLookRotation(kmQuaternion* pOut, const kmVec3* direction, const kmVec3* up);

#ifdef __cplusplus
}
#endif

#endif
