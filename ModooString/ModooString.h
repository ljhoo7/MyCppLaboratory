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

		// 1. 문자(char)로 부터의 문자열 생성, C 문자열 (char *)로 부터의 생성
		ModooString(const char* value);
		ModooString(const char value);

		// 2. 문자열 길이를 구하는 함수
		size_t Length();

		// 3. 문자열 뒤에 다른 문자열 붙이기
		void Append(const ModooString& value);

		// 4. 문자열 내에 포함되어 있는 문자열 구하기
		size_t FindFirstOf(const char*);

		/*
		5. 문자열이 같은지 비교
		6. 문자열 크기 비교 (사전 순)
		*/
	};
}
