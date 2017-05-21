/*
 *  Copyright (c) 2008-2017 SLIBIO. All Rights Reserved.
 *
 *  This file is part of the SLib.io project.
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

namespace slib
{
	
	struct _priv_String_Const
	{
		StringContainer* container;
		sl_int32 lock;
	};
	
	extern const _priv_String_Const _priv_String_Null;
	extern const _priv_String_Const _priv_String_Empty;

	template <>
	struct StringTypeFromCharType<sl_char8> { typedef String Type; };

	
	SLIB_INLINE String::String(String&& src)
	{
		m_container = src.m_container;
		src.m_container = sl_null;
	}
	
	SLIB_INLINE String::String(AtomicString&& src)
	{
		m_container = src.m_container;
		src.m_container = sl_null;
	}
	
	SLIB_INLINE const String& String::null()
	{
		return *(reinterpret_cast<String const*>(&_priv_String_Null));
	}
	
	SLIB_INLINE const String& String::getEmpty()
	{
		return *(reinterpret_cast<String const*>(&_priv_String_Empty));
	}

	SLIB_INLINE const String& String::getNotNull() const
	{
		if (!m_container) {
			return *(reinterpret_cast<String const*>(&_priv_String_Empty));
		}
		return *this;
	}
	
	SLIB_INLINE sl_bool String::isNull() const
	{
		return m_container == sl_null;
	}

	SLIB_INLINE sl_bool String::isNotNull() const
	{
		return m_container != sl_null;
	}
	
	SLIB_INLINE sl_bool String::isEmpty() const
	{
		if (m_container) {
			return (m_container->len == 0);
		} else {
			return sl_true;
		}
	}
	
	SLIB_INLINE sl_bool String::isNotEmpty() const
	{
		if (m_container) {
			return (m_container->len != 0);
		} else {
			return sl_false;
		}
	}
	
	SLIB_INLINE sl_char8* String::getData() const
	{
		if (m_container) {
			return m_container->sz;
		} else {
			return (sl_char8*)((void*)(""));
		}
	}
	
	SLIB_INLINE sl_size String::getLength() const
	{
		if (m_container) {
			return m_container->len;
		} else {
			return 0;
		}
	}
	
	
	SLIB_INLINE AtomicString::Atomic(AtomicString&& src)
	{
		m_container = src.m_container;
		src.m_container = sl_null;
	}

	SLIB_INLINE AtomicString::Atomic(String&& src)
	{
		m_container = src.m_container;
		src.m_container = sl_null;
	}

	SLIB_INLINE const AtomicString& AtomicString::null()
	{
		return *(reinterpret_cast<AtomicString const*>(&_priv_String_Null));
	}
	
	SLIB_INLINE const AtomicString& AtomicString::getEmpty()
	{
		return *(reinterpret_cast<AtomicString const*>(&_priv_String_Empty));
	}

	SLIB_INLINE sl_bool AtomicString::isNull() const
	{
		return m_container == sl_null;
	}

	SLIB_INLINE sl_bool AtomicString::isNotNull() const
	{
		return m_container != sl_null;
	}


	extern const char* _priv_StringConv_radixPatternUpper;
	extern const char* _priv_StringConv_radixPatternLower;
	extern const sl_uint8* _priv_StringConv_radixInversePatternBig;
	extern const sl_uint8* _priv_StringConv_radixInversePatternSmall;

}