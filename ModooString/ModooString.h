#pragma once

#include <vector>
#include <cstring>

namespace GenericBoson
{
	class ModooString
	{
		size_t m_length;
		std::vector<char> m_data;
	public:

		// 1. ����(char)�� ������ ���ڿ� ����, C ���ڿ� (char *)�� ������ ����
		ModooString(const char* value);
		ModooString(const char value);

		// 2. ���ڿ� ���̸� ���ϴ� �Լ�
		size_t Length();

		// 3. ���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�
		void Append(const ModooString& value);

		// 4. ���ڿ� ���� ���ԵǾ� �ִ� ���ڿ� ���ϱ�
		// \ret -1 not exists, 0 < ret found index
		int FindFirstOf(const char*);

		// 5. ���ڿ��� ������ ��
		static bool IsSame(const char* src, const char* target);
		bool IsSame(const char* target);

		// 6. ���ڿ� ũ�� �� (���� ��)
		static char DictionaryCompare(const char* src, const char* target);
		char DictionaryCompare(const char* target);
	};
}
