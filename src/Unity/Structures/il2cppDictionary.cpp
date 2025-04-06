// File: c:\Users\kibbe\Documents\VSC\IL2CPP_Resolver\src\Unity\Structures\il2cppDictionary.cpp

#include "../include/IL2CPP_Resolver/Unity/Structures/il2cppDictionary.hpp"

namespace Unity
{
    template<typename TKey, typename TValue>
    typename il2cppDictionary<TKey, TValue>::Entry* il2cppDictionary<TKey, TValue>::GetEntry()
    {
        return (Entry*)m_pEntries->GetData();
    }

    template<typename TKey, typename TValue>
    TKey il2cppDictionary<TKey, TValue>::GetKeyByIndex(int iIndex)
    {
        TKey tKey = { 0 };

        Entry* pEntry = GetEntry();
        if (pEntry)
            tKey = pEntry[iIndex].m_tKey;

        return tKey;
    }

    template<typename TKey, typename TValue>
    TValue il2cppDictionary<TKey, TValue>::GetValueByIndex(int iIndex)
    {
        TValue tValue = { 0 };

        Entry* pEntry = GetEntry();
        if (pEntry)
            tValue = pEntry[iIndex].m_tValue;

        return tValue;
    }

    template<typename TKey, typename TValue>
    TValue il2cppDictionary<TKey, TValue>::GetValueByKey(TKey tKey)
    {
        TValue tValue = { 0 };
        for (int i = 0; i < m_iCount; i++) {
            if (GetEntry()[i].m_tKey == tKey)
                tValue = GetEntry()[i].m_tValue;
        }
        return tValue;
    }
}