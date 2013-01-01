/*********************************************************\
 *  File: SNMPostProcessSquisher.cpp                     *
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
#include <PLRenderer/Material/Parameter.h>
#include <PLCompositing/Shaders/PostProcessing/PostProcessManager.h>
#include "PLPostProcessEffects/SNMPostProcessSquisher.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLCore;
using namespace PLRenderer;
namespace PLPostProcessEffects {


//[-------------------------------------------------------]
//[ RTTI interface                                        ]
//[-------------------------------------------------------]
pl_implement_class(SNMPostProcessSquisher)


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
SNMPostProcessSquisher::SNMPostProcessSquisher(PLScene::SceneNode &cSceneNode) : SNMPostProcess(cSceneNode),
	MinColor(this),
	MaxColor(this),
	Filename(this)
{
	// Overwrite the default setting of the filename
	m_sFilename = "Data/PostProcesses/Squisher.pp";
}

/**
*  @brief
*    Destructor
*/
SNMPostProcessSquisher::~SNMPostProcessSquisher()
{
}


//[-------------------------------------------------------]
//[ Public virtual PLCompositing::SNMPostProcess functions ]
//[-------------------------------------------------------]
void SNMPostProcessSquisher::SetParameters()
{
	// Call base implementation
	SNMPostProcess::SetParameters();

	{ // MinColor
		Parameter *pParameter = GetParameter("MinColor");
		if (pParameter)
			pParameter->SetValue4fv(MinColor.Get());
	}

	{ // MaxColor
		Parameter *pParameter = GetParameter("MaxColor");
		if (pParameter)
			pParameter->SetValue4fv(MaxColor.Get());
	}
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLPostProcessEffects
