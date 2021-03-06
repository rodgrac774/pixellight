/*********************************************************\
 *  File: SimpleListIterator.inl                         *
 *      Simple list iterator template implementation
 *
 *  Copyright (C) 2002-2013 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 *  and associated documentation files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or
 *  substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
\*********************************************************/


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLCore/Container/SimpleList.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Private functions                                     ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
template <class ValueType>
SimpleListIterator<ValueType>::SimpleListIterator(const SimpleList<ValueType> &lstSimpleList, uint32 nIndex) :
	m_plstSimpleList(&lstSimpleList)
{
	// Start at first element?
	if (!nIndex) {
		m_pNextElement     = m_plstSimpleList->pFirstElement;
		m_pPreviousElement = nullptr;

	// Ok, we start somewhere between the start/end element
	} else {
		// Start with the first element
		m_pPreviousElement = m_plstSimpleList->pFirstElement;
		m_pNextElement     = m_pPreviousElement->pNextElement;
		uint32 nCurrent = 1;
		while (m_pNextElement && nCurrent != nIndex) {
			m_pPreviousElement = m_pNextElement;
			m_pNextElement     = m_pNextElement->pNextElement;
			nCurrent++;
		}
	}
}

/**
*  @brief
*    Constructor
*/
template <class ValueType>
SimpleListIterator<ValueType>::SimpleListIterator(const SimpleList<ValueType> &lstSimpleList) :
	m_plstSimpleList(&lstSimpleList),
	m_pNextElement(nullptr),
	m_pPreviousElement(nullptr)
{
	// Start with the first element
	typename SimpleList<ValueType>::ListElement *pElement = lstSimpleList.pFirstElement;
	while (pElement) {
		// Next, please
		m_pPreviousElement = pElement;
		pElement		   = pElement->pNextElement;
	}
}

/**
*  @brief
*    Copy constructor
*/
template <class ValueType>
SimpleListIterator<ValueType>::SimpleListIterator(const SimpleListIterator<ValueType> &cSource) :
	m_plstSimpleList(cSource.m_plstSimpleList),
	m_pNextElement(cSource.m_pNextElement),
	m_pPreviousElement(cSource.m_pPreviousElement)
{
}

/**
*  @brief
*    Destructor
*/
template <class ValueType>
SimpleListIterator<ValueType>::~SimpleListIterator()
{
}


//[-------------------------------------------------------]
//[ Private virtual IteratorImpl functions                ]
//[-------------------------------------------------------]
template <class ValueType>
IteratorImpl<ValueType> *SimpleListIterator<ValueType>::Clone() const
{
	return new SimpleListIterator<ValueType>(*this);
}

template <class ValueType>
bool SimpleListIterator<ValueType>::HasNext() const
{
	return (m_pNextElement != nullptr);
}

template <class ValueType>
ValueType &SimpleListIterator<ValueType>::Next()
{
	if (!m_pNextElement)
		return SimpleList<ValueType>::Null; // There's no next element
	m_pPreviousElement = m_pNextElement;
	m_pNextElement     = m_pNextElement->pNextElement;
	return m_pPreviousElement->Data;
}

template <class ValueType>
bool SimpleListIterator<ValueType>::HasPrevious() const
{
	return (m_pPreviousElement != nullptr);
}

template <class ValueType>
ValueType &SimpleListIterator<ValueType>::Previous()
{
	if (!m_pPreviousElement)
		return SimpleList<ValueType>::Null; // There's no previous element

	// Set next element
	m_pNextElement = m_pPreviousElement;

	// Start with the first element
	typename SimpleList<ValueType>::ListElement *pElement = m_plstSimpleList->pFirstElement;
	m_pPreviousElement = nullptr;
	while (pElement && m_pNextElement != pElement) {
		// Next, please
		m_pPreviousElement = pElement;
		pElement		   = pElement->pNextElement;
	}

	// Return data
	return m_pNextElement->Data;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore
