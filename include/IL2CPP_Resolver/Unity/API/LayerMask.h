#pragma once

namespace Unity
{
	struct LayerMaskFunctions_t
	{
		void* m_LayerToName = nullptr;
		void* m_NameToLayer = nullptr;
	};
	LayerMaskFunctions_t m_LayerMaskFunctions;

	namespace LayerMask
	{
		void Initialize();
		System_String* LayerToName(unsigned int m_uLayer);
		uint32_t NameToLayer(const char* m_pName);
	}
}