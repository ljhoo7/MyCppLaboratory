#include "ModooString.h"

namespace GenericBoson
{
	// 1. ����(char)�� ������ ���ڿ� ����, C ���ڿ� (char *)�� ������ ����
	ModooString::ModooString(const char* value)
	{
		m_length = strlen(value);

		// append �ѵι��� ���� Ȯ���� ũ��. ������ ó������ ���ڿ��� �ι�� �Ҵ��� �޾Ƶ���.
		size_t sizeToAllocate = m_length << 1;
		m_data.resize(sizeToAllocate);
		strncpy_s(&m_data[0], m_length + 1, value, sizeToAllocate);
	}

	ModooString::ModooString(const char value)
		: ModooString(&value) {}

	// 2. ���ڿ� ���̸� ���ϴ� �Լ�
	size_t ModooString::Length()
	{
		return m_length;
	}

	// 3. ���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�
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

	// 4. ���ڿ� ���� ���ԵǾ� �ִ� ���ڿ� ���ϱ�
	// ��� strstr �Լ� ���� �ȴ�.
	int ModooString::FindFirstOf(const char* target)
	{
		size_t targetLength = strlen(target);

		for (int k = 0; k < m_data.size(); ++k)
		{
			if (true == IsSame(&m_data[k], target))
			{
				return k;
			}
		}

		return -1;
	}

	// 5. ���ڿ��� ������ ��
	bool ModooString::IsSame(const char* src, const char* target)
	{
		if (0 != DictionaryCompare(src, target))
		{
			return false;
		}

		return true;
	}

	bool ModooString::IsSame(const char* target)
	{
		return IsSame(&m_data[0], target);
	}

	char ModooString::DictionaryCompare(const char* src, const char* target)
	{
		size_t targetLength = strlen(target);

		for (int m = 0; m < targetLength; ++m)
		{
			char comparisonResult = src[m] - target[m];
			if (0 != comparisonResult)
			{
				return comparisonResult;
			}
		}

		return 0;
	}

	char ModooString::DictionaryCompare(const char* target)
	{
		return DictionaryCompare(&m_data[0], target);
	}
}