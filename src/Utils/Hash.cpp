// File: c:\Users\kibbe\Documents\VSC\IL2CPP_Resolver\src\Utils\Hash.cpp

#include "../include/IL2CPP_Resolver/Utils/Hash.hpp"

namespace IL2CPP
{
    namespace Utils
    {
        namespace Hash
        {
            uint32_t Get(const char* m_String)
            {
                uint32_t m_Hash = 0;

                for (; *m_String; ++m_String)
                {
                    m_Hash += *m_String;
                    m_Hash += m_Hash << 10;
                    m_Hash ^= m_Hash >> 6;
                }

                m_Hash += m_Hash << 3;
                m_Hash ^= m_Hash >> 11;
                m_Hash += m_Hash << 15;

                return m_Hash;
            }

            constexpr uint32_t GetCompileTime(const char* m_String)
            {
                uint32_t m_Hash = 0;

                for (; *m_String; ++m_String)
                {
                    m_Hash += *m_String;
                    m_Hash += m_Hash << 10;
                    m_Hash ^= m_Hash >> 6;
                }

                m_Hash += m_Hash << 3;
                m_Hash ^= m_Hash >> 11;
                m_Hash += m_Hash << 15;

                return m_Hash;
            }
        }
    }
}