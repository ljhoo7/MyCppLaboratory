#include <iostream>

#include "Case1-NthCharComparison.h"

int Case1()
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

	// Test 3 - compile time
	{
		static_assert(has_s_compile("test") == true, "It hasn't 's'.");

		//// compile error
		//static_assert(has_s_compile("tett") == true, "It hasn't 's'.");
	}

	return 0;
}

char nth_char_runtime(const char(&arr)[6], unsigned i)
{
	return arr[i];
}