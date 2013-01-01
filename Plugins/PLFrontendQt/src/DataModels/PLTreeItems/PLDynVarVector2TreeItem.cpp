/*********************************************************\
 *  File: PLDynVarVector2TreeItem.cpp                    *
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
#include <PLMath/Vector2.h>
#include "PLFrontendQt/DataModels/PLTreeItems/PLDynVarVector2TreeItem.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLFrontendQt {
namespace DataModels {


PLDynVarVector2TreeItem::PLDynVarVector2TreeItem(PLCore::DynVar *dynVar, TreeItemBase *parent) : PLDynVarStringTreeItem(dynVar, PLDynVarTreeItemTypes::Vector2, parent)
{
	RemoveFlags(1,  Qt::ItemIsEditable);
	if (m_dynVar && m_dynVar->GetTypeID() == PLCore::Type<PLMath::Vector2>::TypeID) {
		new Vector2XValueTreeItem(this, this);
		new Vector2YValueTreeItem(this, this);
	}
}

QVariant PLDynVarVector2TreeItem::data(const int column, const int role)
{
	UpdateData();
	return PLDynVarStringTreeItem::data(column, role);
}

void PLDynVarVector2TreeItem::UpdateData()
{
	m_Vector2.FromString(m_dynVar->GetString());
}

void PLDynVarVector2TreeItem::UpdateDataToVar()
{
	m_dynVar->SetString(m_Vector2.ToString());
}

PLDynVarVector2TreeItem::Vector2ValueBaseTreeItem::Vector2ValueBaseTreeItem(const QString &name, TreeItemBase *parent, PLDynVarVector2TreeItem *parentItem) : TreeItemBase(2, parent),
	m_Name(name),
	m_parentItem(parentItem)
{
	SetFlags(1, Qt::ItemIsEditable);
}

QVariant PLDynVarVector2TreeItem::Vector2ValueBaseTreeItem::data(const int column, const int role)
{
// Don't show tooltip for Vector sub Items in column 0
	if (!m_parentItem->IsInStandardRole(role) || (role == Qt::ToolTipRole && column == 0))
		return QVariant();

	if(m_parentItem == nullptr)
		return QVariant();

	if (column == 0) {
		return m_Name;
	} else if (column == 1) {
		return (double)GetVectorData(m_parentItem->m_Vector2);
	}

	return QVariant();
}

bool PLDynVarVector2TreeItem::Vector2ValueBaseTreeItem::setData(const int column, const QVariant &value, const int role)
{
	if (role != Qt::EditRole || column != 1)
		return false;

	float floatVal = value.value<float>();
	SetVectorData(m_parentItem->m_Vector2, floatVal);
	m_parentItem->UpdateDataToVar();
	return true;
}

PLDynVarVector2TreeItem::Vector2XValueTreeItem::Vector2XValueTreeItem(TreeItemBase *parent, PLDynVarVector2TreeItem *parentItem) : Vector2ValueBaseTreeItem("X", parent, parentItem)
{
}

float PLDynVarVector2TreeItem::Vector2XValueTreeItem::GetVectorData(const PLMath::Vector2 &vector)
{
	return vector.x;
}

void PLDynVarVector2TreeItem::Vector2XValueTreeItem::SetVectorData(PLMath::Vector2 &vector, float newValue)
{
	vector.SetX(newValue);
}

PLDynVarVector2TreeItem::Vector2YValueTreeItem::Vector2YValueTreeItem(TreeItemBase *parent, PLDynVarVector2TreeItem *parentItem) : Vector2ValueBaseTreeItem("Y", parent, parentItem)
{
}

float PLDynVarVector2TreeItem::Vector2YValueTreeItem::GetVectorData(const PLMath::Vector2 &vector)
{
	return vector.y;
}

void PLDynVarVector2TreeItem::Vector2YValueTreeItem::SetVectorData(PLMath::Vector2 &vector, float newValue)
{
	vector.SetY(newValue);
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // DataModels
} // PLFrontendQt
