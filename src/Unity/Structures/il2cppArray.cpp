#include "il2cppArray.h"
#include <cstring>

namespace Unity
{
	template<typename T>
	uintptr_t il2cppArray<T>::GetData()
	{
		return reinterpret_cast<uintptr_t>(&m_pValues);
	}

	template<typename T>
	T& il2cppArray<T>::operator[](unsigned int m_uIndex)
	{
		return *reinterpret_cast<T*>(GetData() + sizeof(T) * m_uIndex);
	}

	template<typename T>
	T& il2cppArray<T>::At(unsigned int m_uIndex)
	{
		return operator[](m_uIndex);
	}

	template<typename T>
	void il2cppArray<T>::Insert(T* m_pArray, uintptr_t m_uSize, uintptr_t m_uIndex)
	{
		if ((m_uSize + m_uIndex) >= m_uMaxLength)
		{
			if (m_uIndex >= m_uMaxLength)
				return;

			m_uSize = m_uMaxLength - m_uIndex;
		}

		for (uintptr_t u = 0; m_uSize > u; ++u)
			operator[](u + m_uIndex) = m_pArray[u];
	}

	template<typename T>
	void il2cppArray<T>::Fill(T m_tValue)
	{
		for (uintptr_t u = 0; m_uMaxLength > u; ++u)
			operator[](u) = m_tValue;
	}

	template<typename T>
	void il2cppArray<T>::RemoveAt(unsigned int m_uIndex)
	{
		if (m_uIndex >= m_uMaxLength)
			return;

		if (m_uMaxLength > (m_uIndex + 1))
		{
			for (unsigned int u = m_uIndex; (static_cast<unsigned int>(m_uMaxLength) - m_uIndex) > u; ++u)
				operator[](u) = operator[](u + 1);
		}

		--m_uMaxLength;
	}

	template<typename T>
	void il2cppArray<T>::RemoveRange(unsigned int m_uIndex, unsigned int m_uCount)
	{
		if (m_uCount == 0)
			m_uCount = 1;

		unsigned int m_uTotal = m_uIndex + m_uCount;
		if (m_uTotal >= m_uMaxLength)
			return;

		if (m_uMaxLength > (m_uTotal + 1))
		{
			for (unsigned int u = m_uIndex; (static_cast<unsigned int>(m_uMaxLength) - m_uTotal) >= u; ++u)
				operator[](u) = operator[](u + m_uCount);
		}

		m_uMaxLength -= m_uCount;
	}

	template<typename T>
	void il2cppArray<T>::RemoveAll()
	{
		if (m_uMaxLength > 0)
		{
			memset(GetData(), 0, sizeof(T) * m_uMaxLength);
			m_uMaxLength = 0;
		}
	}

	template<typename T>
	il2cppArray<T>* il2cppList<T>::ToArray()
	{
		return m_pListArray;
	}
}