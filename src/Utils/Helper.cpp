// File: c:\Users\kibbe\Documents\VSC\IL2CPP_Resolver\src\Utils\Helper.cpp

#include "Helper.h"
#include "Object.h"
#include "GameObject.h"
#include "Component.h"
#include "il2cppArray.h"

namespace IL2CPP
{
    namespace Helper
    {
        Unity::CComponent* GetMonoBehaviour()
        {
            Unity::il2cppArray<Unity::CGameObject*>* m_Objects = Unity::Object::FindObjectsOfType<Unity::CGameObject>(UNITY_GAMEOBJECT_CLASS);
            for (uintptr_t u = 0U; m_Objects->m_uMaxLength > u; ++u)
            {
                Unity::CGameObject* m_Object = m_Objects->operator[](static_cast<unsigned int>(u));
                if (!m_Object) continue;

                Unity::CComponent* m_MonoBehaviour = m_Object->GetComponentByIndex(UNITY_MONOBEHAVIOUR_CLASS);
                if (m_MonoBehaviour)
                    return m_MonoBehaviour;
            }

            return nullptr;
        }
    }
}