#include "Object.hpp"

namespace Unity
{
	void CObject::Destroy(float fTimeDelay)
	{
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, float)>(m_ObjectFunctions.m_Destroy)(this, fTimeDelay);
	}

	System_String* CObject::GetName()
	{
		return reinterpret_cast<System_String*(UNITY_CALLING_CONVENTION)(void*)>(m_ObjectFunctions.m_GetName)(this);
	}

	namespace Object
	{
		void Initialize()
		{
			IL2CPP::SystemTypeCache::Initializer::Add(UNITY_OBJECT_CLASS);

			m_ObjectFunctions.m_Destroy			= IL2CPP::ResolveCall(UNITY_OBJECT_DESTROY);
			m_ObjectFunctions.m_FindObjectsOfType	= IL2CPP::ResolveCall(UNITY_OBJECT_FINDOBJECTSOFTYPE);
			m_ObjectFunctions.m_GetName			= IL2CPP::ResolveCall(UNITY_OBJECT_GETNAME);
		}

		il2cppObject* New(il2cppClass* m_pClass)
		{
			return reinterpret_cast<Unity::il2cppObject*(UNITY_CALLING_CONVENTION)(void*)>(IL2CPP::Functions.m_pObjectNew)(m_pClass);
		}
	}
}