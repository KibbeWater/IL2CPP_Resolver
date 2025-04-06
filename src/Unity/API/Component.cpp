#include "Component.hpp"

namespace Unity
{
	CGameObject* CComponent::GetGameObject()
	{
		return reinterpret_cast<CGameObject*(UNITY_CALLING_CONVENTION)(void*)>(m_ComponentFunctions.m_GetGameObject)(this);
	}

	CTransform* CComponent::GetTransform()
	{
		return reinterpret_cast<CTransform*(UNITY_CALLING_CONVENTION)(void*)>(m_ComponentFunctions.m_GetTransform)(this);
	}

	namespace Component
	{
		void Initialize()
		{
			IL2CPP::SystemTypeCache::Initializer::Add(UNITY_COMPONENT_CLASS);

			m_ComponentFunctions.m_GetGameObject	= IL2CPP::ResolveCall(UNITY_COMPONENT_GETGAMEOBJECT);
			m_ComponentFunctions.m_GetTransform		= IL2CPP::ResolveCall(UNITY_COMPONENT_GETTRANSFORM);
		}
	}
}