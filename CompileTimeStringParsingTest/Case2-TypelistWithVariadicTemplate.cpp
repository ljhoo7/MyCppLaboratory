#include <iostream>

#include "Case2-TypelistWithVariadicTemplate.h"

void Case2()
{
	typedef typelist<int, short, long, float> tl;

	// Test 1 - Length of typelist
	{
		static_assert(4 == length<tl::type>::value);

		//// compile-error
		// static_assert(3 == length<tl::type>::value);
	}

	// Test 2 - TypeAt of typelist
	{
		static_assert(true == std::is_same_v<short, type_at<tl::type, 1>::type>);

		//// compile-error
		// static_assert(true == std::is_same_v<int, type_at<tl::type, 1>::type>);
	}
}