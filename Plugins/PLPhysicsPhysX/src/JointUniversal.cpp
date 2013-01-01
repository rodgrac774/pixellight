/*********************************************************\
 *  File: JointUniversal.cpp                             *
 *
 *  Copyright (C) 2002-2013 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 *  and associated documentation files (the �Software�), to deal in the Software without
 *  restriction, including without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or
 *  substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED �AS IS�, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
\*********************************************************/


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLPhysics/Body.h>
#include "PLPhysicsPhysX/BodyImpl.h"
#include "PLPhysicsPhysX/JointImpl.h"
#include "PLPhysicsPhysX/World.h"
#include "PLPhysicsPhysX/JointUniversal.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLMath;
namespace PLPhysicsPhysX {


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Destructor
*/
JointUniversal::~JointUniversal()
{
}


//[-------------------------------------------------------]
//[ Private functions                                     ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
JointUniversal::JointUniversal(PLPhysics::World &cWorld, PLPhysics::Body *pParentBody, PLPhysics::Body *pChildBody,
							   const Vector3 &vPivotPoint, const Vector3 &vPinDir1, const Vector3 &vPinDir2) :
	PLPhysics::JointUniversal(cWorld, ((World&)cWorld).CreateJointImpl(), pParentBody, pChildBody, vPivotPoint, vPinDir1, vPinDir2)
{
	// Get the PhysX physics scene
	NxScene *pPhysXScene = ((World&)cWorld).GetPhysXScene();
	if (pPhysXScene) {
		// Create the PhysX physics joint
		NxD6JointDesc sJointDesc;
		sJointDesc.actor[0] = pParentBody ? ((BodyImpl&)pParentBody->GetBodyImpl()).GetPhysXActor() : nullptr;
		sJointDesc.actor[1] = pChildBody  ? ((BodyImpl&)pChildBody ->GetBodyImpl()).GetPhysXActor() : nullptr;
		sJointDesc.setGlobalAnchor(NxVec3(m_vPivotPoint.x, m_vPivotPoint.y, m_vPivotPoint.z));
		sJointDesc.setGlobalAxis(NxVec3(m_vPinDir1.x, m_vPinDir1.y, m_vPinDir1.z));
		NxJoint *pPhysXJoint = pPhysXScene->createJoint(sJointDesc);

		// Initialize the PhysX physics joint
		((JointImpl&)GetJointImpl()).InitializePhysXJoint(*this, *pPhysXJoint);
	}
}


//[-------------------------------------------------------]
//[ Public virtual PLPhysics::JointUniversal functions    ]
//[-------------------------------------------------------]
void JointUniversal::AddOmega(float fOmega1, float fOmega2)
{
	// [TODO] Implement me
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLPhysicsPhysX
