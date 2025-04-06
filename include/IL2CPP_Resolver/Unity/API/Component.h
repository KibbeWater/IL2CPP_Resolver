#pragma once

namespace Unity
{
	struct ComponentFunctions_t
	{
		void* m_GetGameObject = nullptr;
		void* m_GetTransform = nullptr;
	};
	ComponentFunctions_t m_ComponentFunctions;

	class CComponent : public CObject
	{
	public:
		CGameObject* GetGameObject();
		CTransform* GetTransform();
	};

	namespace Component
	{
		void Initialize();
	}
}