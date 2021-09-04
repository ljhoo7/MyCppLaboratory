#pragma once

// Test 1 - compile time
template<unsigned N>
consteval char nth_char_compile(const char(&arr)[N], unsigned i)
{
	return arr[i];
}

template<unsigned N>
consteval bool has_s_compile(const char(&arr)[N])
{
	for (int k = 0; k < N; ++k)
	{
		if (arr[k] == 's')
		{
			return true;
		}
	}

	return false;
}

// Test 2 - runtime
char nth_char_runtime(const char(&arr)[6], unsigned i);

int Case1();