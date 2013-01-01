/*********************************************************\
 *  File: ParamsParserXml.h                              *
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


#ifndef __PLCORE_TOOLS_PARAMSPARSERXML_H__
#define __PLCORE_TOOLS_PARAMSPARSERXML_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLCore/String/String.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Forward declarations                                  ]
//[-------------------------------------------------------]
class XmlElement;
class XmlAttribute;


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Class for parsing parameters from XML
*
*  @remarks
*    This class can parse parameter lists given as XML (e.g. "<Node Param0=\"Hello\" Param1=\"10\" />")
*/
class ParamsParserXml {


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Constructor
		*/
		inline ParamsParserXml();

		/**
		*  @brief
		*    Destructor
		*/
		inline ~ParamsParserXml();

		/**
		*  @brief
		*    Parse parameters from XML
		*
		*  @param[in] cElement
		*    XML element containing parameters
		*
		*  @return
		*    'true' if the element could be parsed, else 'false'
		*
		*  @remarks
		*    This will first check if the XML element has a valid parameter list
		*    and then parse the first parameter and value. If the parameter list
		*    is empty, the function will return 'false'.
		*/
		PLCORE_API bool ParseXml(const XmlElement &cElement);

		/**
		*  @brief
		*    Parse next parameter
		*
		*  @return
		*    'true' if the next name/value pair could be parsed, else 'false'
		*/
		PLCORE_API bool Next();

		/**
		*  @brief
		*    Check if the current (last parsed) parameter is valid
		*
		*  @return
		*    'true' if there is a current parameter, else 'false'
		*/
		inline bool HasParam() const;

		/**
		*  @brief
		*    Get name of currently parsed parameter
		*
		*  @return
		*    Parameter name
		*/
		inline String GetName() const;

		/**
		*  @brief
		*    Get value of currently parsed parameter
		*
		*  @return
		*    Parameter name
		*/
		inline String GetValue() const;


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		const XmlElement    *m_pElement;	/**< XML element */
		const XmlAttribute  *m_pAttribute;	/**< XML attribute */
		String				 m_sName;		/**< Name of next parameter */
		String				 m_sValue;		/**< Value of next parameter */


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore


//[-------------------------------------------------------]
//[ Implementation                                        ]
//[-------------------------------------------------------]
#include "PLCore/Base/Tools/ParamsParserXml.inl"


#endif // __PLCORE_TOOLS_PARAMSPARSERXML_H__
