#include "Rigidbody.hpp"

namespace Unity
{
	bool CRigidbody::GetDetectCollisions()
	{
		return reinterpret_cast<bool(UNITY_CALLING_CONVENTION)(void*)>(m_RigidbodyFunctions.m_GetDetectCollisions)(this);
	}

	void CRigidbody::SetDetectCollisions(bool m_bDetect)
	{
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, bool)>(m_RigidbodyFunctions.m_SetDetectCollisions)(this, m_bDetect);
	}

	Vector3 CRigidbody::GetVelocity()
	{
		Vector3 vRet;
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3&)>(m_RigidbodyFunctions.m_GetVelocity)(this, vRet);
		return vRet;
	}

	void CRigidbody::SetVelocity(Vector3 m_vVector)
	{
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3)>(m_RigidbodyFunctions.m_SetVelocity)(this, m_vVector);
	}

	namespace RigidBody
	{
		void Initialize()
		{
			IL2CPP::SystemTypeCache::Initializer::Add(UNITY_RIGIDBODY_CLASS);

			m_RigidbodyFunctions.m_GetDetectCollisions	= IL2CPP::ResolveCall(UNITY_RIGIDBODY_GETDETECTCOLLISIONS);
			m_RigidbodyFunctions.m_GetVelocity			= IL2CPP::ResolveCall(UNITY_RIGIDBODY_GETVELOCITY);
			m_RigidbodyFunctions.m_SetDetectCollisions	= IL2CPP::ResolveCall(UNITY_RIGIDBODY_SETDETECTCOLLISIONS);
			m_RigidbodyFunctions.m_SetVelocity			= IL2CPP::ResolveCall(UNITY_RIGIDBODY_SETVELOCITY);
		}
	}
}