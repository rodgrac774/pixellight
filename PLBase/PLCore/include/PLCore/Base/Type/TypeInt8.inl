/*********************************************************\
 *  File: TypeInt8.inl                                   *
 *
 *  Copyright (C) 2002-2011 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  PixelLight is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PixelLight is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with PixelLight. If not, see <http://www.gnu.org/licenses/>.
\*********************************************************/


#ifndef __PLCORE_TYPE_INT8_INL__
#define __PLCORE_TYPE_INT8_INL__
#pragma once


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Type wrapper for 'int8'
*/
template <>
class Type<PLGeneral::int8> {


	//[-------------------------------------------------------]
	//[ Public static type information                        ]
	//[-------------------------------------------------------]
	public:
		// Type
		typedef PLGeneral::int8 _Type;			/**< Real type */
		typedef PLGeneral::int8 _StorageType;	/**< Storage type, for this type identical to the real type */

		// Type ID
		static const PLGeneral::uint32 TypeID = TypeInt8;

		// Get type name
		static PLGeneral::String GetTypeName()
		{
			return "int8";
		}

		// Convert var to int8
		static PLGeneral::int8 ConvertFromVar(const DynVar *pValue)
		{
			return pValue->GetInt8();
		}

		// Convert int8 to bool
		static bool ConvertToBool(PLGeneral::int8 nValue)
		{
			return static_cast<bool>(nValue != 0);
		}

		// Convert bool to int8
		static PLGeneral::int8 ConvertFromBool(bool bValue)
		{
			return static_cast<PLGeneral::int8>(bValue);
		}

		// Convert int8 to int
		static int ConvertToInt(PLGeneral::int8 nValue)
		{
			return static_cast<int>(nValue);
		}

		// Convert int to int8
		static PLGeneral::int8 ConvertFromInt(int nValue)
		{
			return static_cast<PLGeneral::int8>(nValue);
		}

		// Convert int8 to int8
		static PLGeneral::int8 ConvertToInt8(PLGeneral::int8 nValue)
		{
			return static_cast<PLGeneral::int8>(nValue);
		}

		// Convert int8 to int8
		static PLGeneral::int8 ConvertFromInt8(PLGeneral::int8 nValue)
		{
			return static_cast<PLGeneral::int8>(nValue);
		}

		// Convert int8 to int16
		static PLGeneral::int16 ConvertToInt16(PLGeneral::int8 nValue)
		{
			return static_cast<PLGeneral::int16>(nValue);
		}

		// Convert int16 to int8
		static PLGeneral::int8 ConvertFromInt16(PLGeneral::int16 nValue)
		{
			return static_cast<PLGeneral::int8>(nValue);
		}

		// Convert int8 to int32
		static PLGeneral::int32 ConvertToInt32(PLGeneral::int8 nValue)
		{
			return static_cast<PLGeneral::int32>(nValue);
		}

		// Convert int32 to int8
		static PLGeneral::int8 ConvertFromInt32(PLGeneral::int32 nValue)
		{
			return static_cast<PLGeneral::int8>(nValue);
		}

		// Convert int8 to int64
		static PLGeneral::int64 ConvertToInt64(PLGeneral::int8 nValue)
		{
			return static_cast<PLGeneral::int64>(nValue);
		}

		// Convert int64 to int8
		static PLGeneral::int8 ConvertFromInt64(PLGeneral::int64 nValue)
		{
			return static_cast<PLGeneral::int8>(nValue);
		}

		// Convert int8 to uint8
		static PLGeneral::uint8 ConvertToUInt8(PLGeneral::int8 nValue)
		{
			return static_cast<PLGeneral::uint8>(nValue);
		}

		// Convert uint8 to int8
		static PLGeneral::int8 ConvertFromUInt8(PLGeneral::uint8 nValue)
		{
			return static_cast<PLGeneral::int8>(nValue);
		}

		// Convert int8 to uint16
		static PLGeneral::uint16 ConvertToUInt16(PLGeneral::int8 nValue)
		{
			return static_cast<PLGeneral::uint16>(nValue);
		}

		// Convert uint16 to int8
		static PLGeneral::int8 ConvertFromUInt16(PLGeneral::uint16 nValue)
		{
			return static_cast<PLGeneral::int8>(nValue);
		}

		// Convert int8 to uint32
		static PLGeneral::uint32 ConvertToUInt32(PLGeneral::int8 nValue)
		{
			return static_cast<PLGeneral::uint32>(nValue);
		}

		// Convert uint32 to int8
		static PLGeneral::int8 ConvertFromUInt32(PLGeneral::uint32 nValue)
		{
			return static_cast<PLGeneral::int8>(nValue);
		}

		// Convert int8 to uint64
		static PLGeneral::uint64 ConvertToUInt64(PLGeneral::int8 nValue)
		{
			return static_cast<PLGeneral::uint64>(nValue);
		}

		// Convert uint64 to int8
		static PLGeneral::int8 ConvertFromUInt64(PLGeneral::uint64 nValue)
		{
			return static_cast<PLGeneral::int8>(nValue);
		}

		// Convert int8 to uint_ptr
		static PLGeneral::uint_ptr ConvertToUIntPtr(PLGeneral::int8 nValue)
		{
			return static_cast<PLGeneral::uint_ptr>(nValue);
		}

		// Convert uint_ptr to int8
		static PLGeneral::int8 ConvertFromUIntPtr(PLGeneral::uint_ptr nValue)
		{
			return static_cast<PLGeneral::int8>(nValue);
		}

		// Convert int8 to float
		static float ConvertToFloat(PLGeneral::int8 nValue)
		{
			return static_cast<float>(nValue);
		}

		// Convert float to int8
		static PLGeneral::int8 ConvertFromFloat(float fValue)
		{
			return static_cast<PLGeneral::int8>(fValue);
		}

		// Convert int8 to double
		static double ConvertToDouble(PLGeneral::int8 nValue)
		{
			return static_cast<double>(nValue);
		}

		// Convert double to int8
		static PLGeneral::int8 ConvertFromDouble(double dValue)
		{
			return static_cast<PLGeneral::int8>(dValue);
		}

		// Convert int8 to string
		static PLGeneral::String ConvertToString(PLGeneral::int8 nValue)
		{
			return PLGeneral::String() + static_cast<int>(nValue);
		}

		// Convert string to PLGeneral::int8
		static PLGeneral::int8 ConvertFromString(const PLGeneral::String &sString)
		{
			return static_cast<PLGeneral::int8>(sString.GetInt());
		}

		// Convert real to storage type
		static PLGeneral::int8 ConvertRealToStorage(PLGeneral::int8 nValue)
		{
			return nValue;
		}

		// Convert storage to real type
		static PLGeneral::int8 ConvertStorageToReal(PLGeneral::int8 nValue)
		{
			return nValue;
		}

};


#endif // __PLCORE_TYPE_INT8_INL__
