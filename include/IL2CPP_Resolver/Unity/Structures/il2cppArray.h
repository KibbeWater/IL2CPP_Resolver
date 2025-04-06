#pragma once

namespace Unity
{
	template<typename T>
	struct il2cppArray : il2cppObject
	{
		il2cppArrayBounds* m_pBounds = nullptr;
		uintptr_t m_uMaxLength = 0;
		T* m_pValues = nullptr;

		uintptr_t GetData();
		T& operator[](unsigned int m_uIndex);
		T& At(unsigned int m_uIndex);
		void Insert(T* m_pArray, uintptr_t m_uSize, uintptr_t m_uIndex = 0);
		void Fill(T m_tValue);
		void RemoveAt(unsigned int m_uIndex);
		void RemoveRange(unsigned int m_uIndex, unsigned int m_uCount);
		void RemoveAll();
	};

	// Defined here because its basically same shit
	template<typename T>
	struct il2cppList : il2cppObject
	{
		il2cppArray<T>* m_pListArray;

		il2cppArray<T>* ToArray();
	};
}