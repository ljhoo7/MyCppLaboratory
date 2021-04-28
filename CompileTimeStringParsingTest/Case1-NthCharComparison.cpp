#include <iostream>

#include "Case1-NthCharComparison.h"

int case1()
{
// Test 1 - compile time
	{
		static_assert(nth_char_compile("tests", 2) == 's', "should be s");

		//// compile error
		// static_assert(nth_char_compile("tests", 2) == 's', "should be s");
	}

	// Test 2 - runtime
	{
		//// compile error
		//if (nth_char_compile("tests", 2) == 's')

		if (nth_char_runtime("tests", 2) == 's')
		{
			std::cout << "mathced" << std::endl;
		}
		std::cout << "not matched" << std::endl;
	}

	return 0;
}

char nth_char_runtime(const char(&arr)[6], unsigned i)
{
	return arr[i];
}