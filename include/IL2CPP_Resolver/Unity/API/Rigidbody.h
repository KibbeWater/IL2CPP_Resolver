#pragma once

namespace Unity
{
	struct RigidbodyFunctions_t
	{
		void* m_GetDetectCollisions = nullptr;
		void* m_GetVelocity = nullptr;
		void* m_SetDetectCollisions = nullptr;
		void* m_SetVelocity = nullptr;
	};
	RigidbodyFunctions_t m_RigidbodyFunctions;

	class CRigidbody : public IL2CPP::CClass
	{
	public:
		bool GetDetectCollisions();
		void SetDetectCollisions(bool m_bDetect);
		Vector3 GetVelocity();
		void SetVelocity(Vector3 m_vVector);
	};

	namespace RigidBody
	{
		void Initialize();
	}
}