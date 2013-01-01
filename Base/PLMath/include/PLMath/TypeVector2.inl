/*********************************************************\
 *  File: TypeVector2.inl                                *
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


#ifndef __PLMATH_TYPE_VECTOR2_INL__
#define __PLMATH_TYPE_VECTOR2_INL__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLCore/Base/Var/Var.h>


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Type wrapper for 'PLMath::Vector2'
*/
template <>
class Type<PLMath::Vector2> {


	//[-------------------------------------------------------]
	//[ Public static type information                        ]
	//[-------------------------------------------------------]
	public:
		// Type
		typedef PLMath::Vector2 _Type;			/**< Real type */
		typedef PLMath::Vector2 _StorageType;	/**< Storage type, for this type identical to the real type */

		// Type ID
		static const int TypeID = 1000;

		// Get type name
		static String GetTypeName()
		{
			return "vector2";
		}

		// Convert dynamic variable to PLMath::Vector2
		static PLMath::Vector2 ConvertFromVar(const DynVar &cDynVar)
		{
			return (cDynVar.GetTypeID() == TypeID) ? static_cast<const Var<PLMath::Vector2>&>(cDynVar).Get() : cDynVar.GetString();
		}

		// Convert PLMath::Vector2 to bool
		static bool ConvertToBool(const PLMath::Vector2 &vVector)
		{
			return vVector.IsNull();
		}

		// Convert bool to PLMath::Vector2
		static PLMath::Vector2 ConvertFromBool(bool bValue)
		{
			const float fValue = bValue ? 1.0f : 0.0f;
			return PLMath::Vector2(fValue, fValue);
		}

		// Convert PLMath::Vector2 to int
		static int ConvertToInt(const PLMath::Vector2 &vVector)
		{
			return vVector.IsNull();
		}

		// Convert int to PLMath::Vector2
		static PLMath::Vector2 ConvertFromInt(int nValue)
		{
			return PLMath::Vector2(static_cast<float>(nValue), static_cast<float>(nValue));
		}

		// Convert PLMath::Vector2 to int8
		static int8 ConvertToInt8(const PLMath::Vector2 &vVector)
		{
			return static_cast<int8>(ConvertToInt(vVector));
		}

		// Convert int8 to PLMath::Vector2
		static PLMath::Vector2 ConvertFromInt8(int8 nValue)
		{
			return PLMath::Vector2(static_cast<float>(nValue), static_cast<float>(nValue));
		}

		// Convert PLMath::Vector2 to int16
		static int16 ConvertToInt16(const PLMath::Vector2 &vVector)
		{
			return static_cast<int16>(ConvertToInt(vVector));
		}

		// Convert int16 to PLMath::Vector2
		static PLMath::Vector2 ConvertFromInt16(int16 nValue)
		{
			return PLMath::Vector2(static_cast<float>(nValue), static_cast<float>(nValue));
		}

		// Convert PLMath::Vector2 to int32
		static int32 ConvertToInt32(const PLMath::Vector2 &vVector)
		{
			return static_cast<int32>(ConvertToInt(vVector));
		}

		// Convert int32 to PLMath::Vector2
		static PLMath::Vector2 ConvertFromInt32(int32 nValue)
		{
			return PLMath::Vector2(static_cast<float>(nValue), static_cast<float>(nValue));
		}

		// Convert PLMath::Vector2 to int64
		static int64 ConvertToInt64(const PLMath::Vector2 &vVector)
		{
			return static_cast<int64>(ConvertToInt(vVector));
		}

		// Convert int64 to PLMath::Vector2
		static PLMath::Vector2 ConvertFromInt64(int64 nValue)
		{
			return PLMath::Vector2(static_cast<float>(nValue), static_cast<float>(nValue));
		}

		// Convert PLMath::Vector2 to uint8
		static uint8 ConvertToUInt8(const PLMath::Vector2 &vVector)
		{
			return static_cast<uint8>(ConvertToInt(vVector));
		}

		// Convert uint8 to PLMath::Vector2
		static PLMath::Vector2 ConvertFromUInt8(uint8 nValue)
		{
			return PLMath::Vector2(static_cast<float>(nValue), static_cast<float>(nValue));
		}

		// Convert PLMath::Vector2 to uint16
		static uint16 ConvertToUInt16(const PLMath::Vector2 &vVector)
		{
			return static_cast<uint16>(ConvertToInt(vVector));
		}

		// Convert uint16 to PLMath::Vector2
		static PLMath::Vector2 ConvertFromUInt16(uint16 nValue)
		{
			return PLMath::Vector2(static_cast<float>(nValue), static_cast<float>(nValue));
		}

		// Convert PLMath::Vector2 to uint32
		static uint32 ConvertToUInt32(const PLMath::Vector2 &vVector)
		{
			return static_cast<uint32>(ConvertToInt(vVector));
		}

		// Convert uint32 to PLMath::Vector2
		static PLMath::Vector2 ConvertFromUInt32(uint32 nValue)
		{
			return PLMath::Vector2(static_cast<float>(nValue), static_cast<float>(nValue));
		}

		// Convert PLMath::Vector2 to uint64
		static uint64 ConvertToUInt64(const PLMath::Vector2 &vVector)
		{
			return static_cast<uint64>(ConvertToInt(vVector));
		}

		// Convert uint64 to PLMath::Vector2
		static PLMath::Vector2 ConvertFromUInt64(uint64 nValue)
		{
			return PLMath::Vector2(static_cast<float>(nValue), static_cast<float>(nValue));
		}

		// Convert PLMath::Vector2 to uint_ptr
		static uint_ptr ConvertToUIntPtr(const PLMath::Vector2 &vVector)
		{
			return static_cast<uint_ptr>(ConvertToInt(vVector));
		}

		// Convert uint_ptr to PLMath::Vector2
		static PLMath::Vector2 ConvertFromUIntPtr(uint_ptr nValue)
		{
			return PLMath::Vector2(static_cast<float>(nValue), static_cast<float>(nValue));
		}

		// Convert PLMath::Vector2 to float
		static float ConvertToFloat(const PLMath::Vector2 &vVector)
		{
			return static_cast<float>(ConvertToInt(vVector));
		}

		// Convert float to PLMath::Vector2
		static PLMath::Vector2 ConvertFromFloat(float fValue)
		{
			return PLMath::Vector2(fValue, fValue);
		}

		// Convert PLMath::Vector2 to double
		static double ConvertToDouble(const PLMath::Vector2 &vVector)
		{
			return static_cast<double>(ConvertToInt(vVector));
		}

		// Convert double to PLMath::Vector2
		static PLMath::Vector2 ConvertFromDouble(double dValue)
		{
			return PLMath::Vector2(static_cast<float>(dValue), static_cast<float>(dValue));
		}

		// Convert PLMath::Vector2 to string
		static String ConvertToString(const PLMath::Vector2 &vVector)
		{
			return vVector.ToString();
		}

		// Convert string to PLMath::Vector2
		static PLMath::Vector2 ConvertFromString(const String &sString)
		{
			PLMath::Vector2 vVector;
			vVector.FromString(sString);
			return vVector;
		}

		// Convert real to storage type (reference is enough in here)
		static PLMath::Vector2 &ConvertRealToStorage(PLMath::Vector2 &vValue)
		{
			return vValue;
		}

		// Convert storage to real type (reference is enough in here)
		static PLMath::Vector2 &ConvertStorageToReal(PLMath::Vector2 &vValue)
		{
			return vValue;
		}


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore


#endif // __PLMATH_TYPE_VECTOR2_INL__
