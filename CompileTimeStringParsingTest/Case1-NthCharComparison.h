#pragma once

// Test 1 - compile time
template<unsigned N>
consteval char nth_char_compile(const char(&arr)[N], unsigned i)
{
	return arr[i];
}

// Test 2 - runtime
char nth_char_runtime(const char(&arr)[6], unsigned i);

int case1();