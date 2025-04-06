#pragma once

namespace Unity
{
	struct ObjectFunctions_t
	{
		void* m_Destroy = nullptr;
		void* m_FindObjectsOfType = nullptr;
		void* m_GetName = nullptr;
	};
	ObjectFunctions_t m_ObjectFunctions;

	class CObject : public IL2CPP::CClass
	{
	public:
		void Destroy(float fTimeDelay = 0.f);
		System_String* GetName();
	};

	namespace Object
	{
		void Initialize();
		static il2cppObject* New(il2cppClass* m_pClass);

		template<typename T>
		static il2cppArray<T*>* FindObjectsOfType(il2cppObject* m_pSystemType, bool m_bIncludeInactive = false);

		template<typename T>
		static il2cppArray<T*>* FindObjectsOfType(const char* m_pSystemTypeName, bool m_bIncludeInactive = false);

		template<typename T>
		static T* FindObjectOfType(il2cppObject* m_pSystemType, bool m_bIncludeInactive = false);

		template<typename T>
		static T* FindObjectOfType(const char* m_pSystemTypeName, bool m_bIncludeInactive = false);
	}
}
