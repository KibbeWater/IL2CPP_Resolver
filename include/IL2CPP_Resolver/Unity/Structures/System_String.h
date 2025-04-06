#pragma once

namespace Unity
{
	struct System_String : il2cppObject
	{
		int m_iLength;
		wchar_t m_wString[1024];

		void Clear();

		std::string ToString();
	};
}
