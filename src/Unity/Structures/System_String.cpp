// File: c:\Users\kibbe\Documents\VSC\IL2CPP_Resolver\src\Unity\Structures\System_String.cpp

#include "System_String.h"
#include <Windows.h>
#include <cstring>
#include <string>

namespace Unity
{
    void System_String::Clear()
    {
        if (!this) return;

        memset(m_wString, 0, static_cast<size_t>(m_iLength) * 2);
        m_iLength = 0;
    }

    std::string System_String::ToString()
    {
        if (!this) return "";

        std::string sRet(static_cast<size_t>(m_iLength + 1) * 4, '\0');
        WideCharToMultiByte(CP_UTF8, 0, m_wString, m_iLength, &sRet[0], static_cast<int>(sRet.size()), 0, 0);
        return sRet;
    }
}