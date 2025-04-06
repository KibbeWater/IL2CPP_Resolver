#include "Transform.hpp"

namespace Unity
{
	CTransform* CTransform::GetParent()
	{
		return reinterpret_cast<CTransform*(UNITY_CALLING_CONVENTION)(void*)>(m_TransformFunctions.m_GetParent)(this);
	}

	CTransform* CTransform::GetRoot()
	{
		return reinterpret_cast<CTransform*(UNITY_CALLING_CONVENTION)(void*)>(m_TransformFunctions.m_GetRoot)(this);
	}

	CTransform* CTransform::GetChild(int m_iIndex)
	{
		return reinterpret_cast<CTransform*(UNITY_CALLING_CONVENTION)(void*, int)>(m_TransformFunctions.m_GetChild)(this, m_iIndex);
	}

	int CTransform::GetChildCount()
	{
		return reinterpret_cast<int(UNITY_CALLING_CONVENTION)(void*)>(m_TransformFunctions.m_GetChildCount)(this);
	}

	CTransform* CTransform::FindChild(const char* path, bool isActiveOnly)
	{
		return reinterpret_cast<CTransform * (UNITY_CALLING_CONVENTION)(void*, System_String*, bool)>(m_TransformFunctions.m_FindChild)(this, IL2CPP::String::New(path), isActiveOnly);
	}

	CTransform* CTransform::FindChild(const char* path)
	{
		if (path == NULL) {
			return nullptr;
		}
		return FindChild(path, false);
	}

	Vector3 CTransform::GetPosition()
	{
		Vector3 vRet;
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3&)>(m_TransformFunctions.m_GetPosition)(this, vRet);
		return vRet;
	}

	Quaternion CTransform::GetRotation()
	{
		Quaternion m_qRet;
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Quaternion&)>(m_TransformFunctions.m_GetRotation)(this, m_qRet);
		return m_qRet;
	}

	Vector3 CTransform::GetLocalPosition()
	{
		Vector3 vRet;
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3&)>(m_TransformFunctions.m_GetLocalPosition)(this, vRet);
		return vRet;
	}

	Vector3 CTransform::GetLocalScale()
	{
		Vector3 vRet;
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3&)>(m_TransformFunctions.m_GetLocalScale)(this, vRet);
		return vRet;
	}

	void CTransform::SetPosition(Vector3 m_vVector)
	{
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3)>(m_TransformFunctions.m_SetPosition)(this, m_vVector);
	}

	void CTransform::SetRotation(Quaternion m_qQuat)
	{
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Quaternion)>(m_TransformFunctions.m_SetRotation)(this, m_qQuat);
	}

	void CTransform::SetLocalPosition(Vector3 m_vVector)
	{
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3)>(m_TransformFunctions.m_SetLocalPosition)(this, m_vVector);
	}

	void CTransform::SetLocalScale(Vector3 m_vVector)
	{
		reinterpret_cast<void(UNITY_CALLING_CONVENTION)(void*, Vector3)>(m_TransformFunctions.m_SetLocalScale)(this, m_vVector);
	}

	namespace Transform
	{
		void Initialize()
		{
			IL2CPP::SystemTypeCache::Initializer::Add(UNITY_TRANSFORM_CLASS);

			m_TransformFunctions.m_GetParent		= IL2CPP::ResolveCall(UNITY_TRANSFORM_GETPARENT);
			m_TransformFunctions.m_GetRoot			= IL2CPP::ResolveCall(UNITY_TRANSFORM_GETROOT);
			m_TransformFunctions.m_GetChild			= IL2CPP::ResolveCall(UNITY_TRANSFORM_GETCHILD);
			m_TransformFunctions.m_GetChildCount	= IL2CPP::ResolveCall(UNITY_TRANSFORM_GETCHILDCOUNT);
			m_TransformFunctions.m_FindChild		= IL2CPP::ResolveCall(UNITY_TRANSFORM_FINDCHILD);
			m_TransformFunctions.m_GetPosition		= IL2CPP::ResolveCall(UNITY_TRANSFORM_GETPOSITION);
			m_TransformFunctions.m_GetRotation		= IL2CPP::ResolveCall(UNITY_TRANSFORM_GETROTATION);
			m_TransformFunctions.m_GetLocalPosition = IL2CPP::ResolveCall(UNITY_TRANSFORM_GETLOCALPOSITION);
			m_TransformFunctions.m_GetLocalScale	= IL2CPP::ResolveCall(UNITY_TRANSFORM_GETLOCALSCALE);
			m_TransformFunctions.m_SetPosition		= IL2CPP::ResolveCall(UNITY_TRANSFORM_SETPOSITION);
			m_TransformFunctions.m_SetRotation		= IL2CPP::ResolveCall(UNITY_TRANSFORM_SETROTATION);
			m_TransformFunctions.m_SetLocalPosition = IL2CPP::ResolveCall(UNITY_TRANSFORM_SETLOCALPOSITION);
			m_TransformFunctions.m_SetLocalScale	= IL2CPP::ResolveCall(UNITY_TRANSFORM_SETLOCALSCALE);
		}
	}
}