/*********************************************************\
 *  File: SPEffectPreview.h                              *
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


#ifndef __PLRENDERER_EFFECT_SURFACEPAINTER_H__
#define __PLRENDERER_EFFECT_SURFACEPAINTER_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLRenderer/SPPreview.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLRenderer {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Effect preview surface painter class
*/
class SPEffectPreview : public SPPreview {


	//[-------------------------------------------------------]
	//[ RTTI interface                                        ]
	//[-------------------------------------------------------]
	pl_class(PLRENDERER_RTTI_EXPORT, SPEffectPreview, "PLRenderer", PLRenderer::SPPreview, "Effect preview surface painter class")
		// Constructors
		pl_constructor_1(ParameterConstructor,	Renderer&,	"Parameter constructor",	"")
	pl_class_end


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] cRenderer
		*    Renderer to use
		*/
		PLRENDERER_API SPEffectPreview(Renderer &cRenderer);

		/**
		*  @brief
		*    Destructor
		*/
		PLRENDERER_API virtual ~SPEffectPreview();

		/**
		*  @brief
		*    Returns the name of the used effect
		*
		*  @return
		*    Name of the used effect
		*/
		inline PLCore::String GetEffect() const;

		/**
		*  @brief
		*    Sets the name of the used effect
		*
		*  @param[in] sName
		*    Name of the used effect
		*/
		inline void SetEffect(const PLCore::String &sName);


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		PLCore::String m_sEffect;	/**< Name of the used effect */


	//[-------------------------------------------------------]
	//[ Private virtual SurfacePainter functions              ]
	//[-------------------------------------------------------]
	private:
		virtual void OnPaint(Surface &cSurface) override;


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLRenderer


//[-------------------------------------------------------]
//[ Implementation                                        ]
//[-------------------------------------------------------]
#include "PLRenderer/Effect/SPEffectPreview.inl"


#endif // __PLRENDERER_EFFECT_SURFACEPAINTER_H__
