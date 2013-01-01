/*********************************************************\
 *  File: SensorRaycast.h                                *
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


#ifndef __PLPHYSICSNEWTON_SENSORRAYCAST_H__
#define __PLPHYSICSNEWTON_SENSORRAYCAST_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLPhysics/SensorRaycast.h>
#include "PLPhysicsNewton/PLPhysicsNewton.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLPhysicsNewton {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Newton physics ray cast sensor
*/
class SensorRaycast : public PLPhysics::SensorRaycast {


	//[-------------------------------------------------------]
	//[ Friends                                               ]
	//[-------------------------------------------------------]
	friend class World;


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Destructor
		*/
		PLPHYSICSNEWTON_API virtual ~SensorRaycast();


	//[-------------------------------------------------------]
	//[ Public Newton callback functions                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Newton function to be called for each body hit during the ray scan
		*
		*  @param[in] pPhysicsBody
		*    Newton body (always valid!)
		*  @param[in] pfNormal
		*    Normal (always valid!)
		*  @param[in] nCollisionID
		*    Collision ID
		*  @param[in] pUserData
		*    User data, can be a null pointer
		*  @param[in] fIntersectParam
		*    Intersection parameter
		*
		*  @return
		*    Intersection parameter: If 0 is returned the ray cast will terminate immediately!
		*/
		static PLPHYSICSNEWTON_API float RayFilterCallback(const Newton::NewtonBody *pPhysicsBody, const float *pfNormal,
														   int nCollisionID, void *pUserData, float fIntersectParam);


	//[-------------------------------------------------------]
	//[ Private functions                                     ]
	//[-------------------------------------------------------]
	private:
		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] cWorld
		*    World this sensor is in
		*  @param[in] vStart
		*    Beginning of the ray in global space
		*  @param[in] vEnd
		*    End of the ray in global space
		*  @param[in] nFlags
		*    Flags (see EFlags)
		*/
		SensorRaycast(PLPhysics::World &cWorld, const PLMath::Vector3 &vStart = PLMath::Vector3::Zero, const PLMath::Vector3 &vEnd = PLMath::Vector3::Zero, PLCore::uint32 nFlags = 0);


	//[-------------------------------------------------------]
	//[ Public virtual PLPhysics::Sensor functions            ]
	//[-------------------------------------------------------]
	public:
		PLPHYSICSNEWTON_API virtual PLCore::uint32 Check() override;


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLPhysicsNewton


#endif // __PLPHYSICSNEWTON_SENSORRAYCAST_H__
