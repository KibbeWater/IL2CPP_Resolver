#include "Camera.h"

namespace Unity
{
	float CCamera::GetDepth()
	{
		return reinterpret_cast<float(UNITY_CALLING_CONVENTION)(void*)>(m_CameraFunctions.m_GetDepth)(this);
	}

	void CCamera::SetDepth(float m_fValue)
	{
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, float)>(m_CameraFunctions.m_SetDepth)(this, m_fValue);
	}

	float CCamera::GetFieldOfView()
	{
		return reinterpret_cast<float(UNITY_CALLING_CONVENTION)(void*)>(m_CameraFunctions.m_GetFieldOfView)(this);
	}

	void CCamera::SetFieldOfView(float m_fValue)
	{
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, float)>(m_CameraFunctions.m_SetFieldOfView)(this, m_fValue);
	}

	void CCamera::WorldToScreen(Vector3& m_vWorld, Vector3& m_vScreen, int m_iEye)
	{
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3&, int, Vector3&)>(m_CameraFunctions.m_WorldToScreen)(this, m_vWorld, m_iEye, m_vScreen);
	}

	namespace Camera
	{
		void Initialize()
		{
			IL2CPP::SystemTypeCache::Initializer::Add(UNITY_CAMERA_CLASS);

			m_CameraFunctions.m_GetCurrent		= IL2CPP::ResolveCall(UNITY_CAMERA_GETCURRENT);
			m_CameraFunctions.m_GetMain			= IL2CPP::ResolveCall(UNITY_CAMERA_GETMAIN);
			m_CameraFunctions.m_GetDepth		= IL2CPP::ResolveCall(UNITY_CAMERA_GETDEPTH);
			m_CameraFunctions.m_SetDepth		= IL2CPP::ResolveCall(UNITY_CAMERA_SETDEPTH);
			m_CameraFunctions.m_GetFieldOfView	= IL2CPP::ResolveCall(UNITY_CAMERA_GETFIELDOFVIEW);
			m_CameraFunctions.m_SetFieldOfView	= IL2CPP::ResolveCall(UNITY_CAMERA_SETFIELDOFVIEW);
			m_CameraFunctions.m_WorldToScreen	= IL2CPP::ResolveCall(UNITY_CAMERA_WORLDTOSCREEN);
		}

		CCamera* GetCurrent()
		{
			return reinterpret_cast<CCCamera*(UNITY_CALLING_CONVENTION)()>(m_CameraFunctions.m_GetCurrent)();
		}

		CCamera* GetMain()
		{
			return reinterpret_cast<CCCamera*(UNITY_CALLING_CONVENTION)()>(m_CameraFunctions.m_GetMain)();
		}
	}
}