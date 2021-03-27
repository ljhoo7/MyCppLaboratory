#include "ModooString.h"

namespace GenericBoson
{
	// 1. 문자(char)로 부터의 문자열 생성, C 문자열 (char *)로 부터의 생성
	ModooString::ModooString(const char* value)
	{
		m_length = strlen(value);

		// append 한두번은 있을 확률이 크다. 떄문에 처음부터 문자열의 두배로 할당을 받아두자.
		size_t sizeToAllocate = m_length << 1;
		m_data.resize(sizeToAllocate);
		strncpy_s(&m_data[0], m_length + 1, value, sizeToAllocate);
	}

	ModooString::ModooString(const char value)
		: ModooString(&value) {}

	// 2. 문자열 길이를 구하는 함수
	size_t ModooString::Length()
	{
		return m_length;
	}

	// 3. 문자열 뒤에 다른 문자열 붙이기
	void ModooString::Append(const ModooString& value)
	{
		size_t newSize = m_length + value.m_length;
		if (m_data.size() < newSize + 1)
		{
			std::vector<char> backUp(m_data);
			m_data.resize(newSize << 1);

			strncpy_s(&m_data[0], m_length + 1, &backUp[0], newSize);
		}
		strncpy_s(&m_data[m_length], value.m_length + 1, &value.m_data[0], newSize);
		m_length = newSize;
	}

	// 4. 문자열 내에 포함되어 있는 문자열 구하기
	// 사실 strstr 함수 쓰면 된다.
	size_t ModooString::FindFirstOf(const char* target)
	{
		size_t targetLength = strlen(target);
		for (int k = 0; k < m_data.size(); ++k)
		{
			for (int m = 0; m < targetLength; ++m)
			{
				
			}
		}

		return 0;
	}
}