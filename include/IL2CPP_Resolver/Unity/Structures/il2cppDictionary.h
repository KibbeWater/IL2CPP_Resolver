#pragma once

namespace Unity
{
	template<typename TKey,typename TValue>
	struct il2cppDictionary : il2cppObject
	{
		struct Entry
		{
			int m_iHashCode;
			int m_iNext;
			TKey m_tKey;
			TValue m_tValue;
		};
		il2cppArray<int>* m_pBuckets;
		il2cppArray<Entry*>* m_pEntries;
		int m_iCount;
		int m_iVersion;
		int m_iFreeList;
		int m_iFreeCount;
		void* m_pComparer;
		void* m_pKeys;
		void* m_pValues;

		Entry* GetEntry();

		TKey GetKeyByIndex(int iIndex);

		TValue GetValueByIndex(int iIndex);

		TValue GetValueByKey(TKey tKey);
	};
}
