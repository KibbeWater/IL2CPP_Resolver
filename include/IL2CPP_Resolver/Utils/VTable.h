#pragma once

namespace IL2CPP
{
    namespace Utils
    {
        namespace VTable
        {
            void ReplaceFunction(void** m_VTableFunc, void* m_NewFunc, void** m_Original = nullptr);
            void** FindFunction(void** m_VTable, int m_Count, std::initializer_list<unsigned char> m_Opcodes);
        }
    }
}