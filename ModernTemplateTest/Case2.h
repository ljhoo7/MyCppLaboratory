#pragma once

#include <iostream>

void Test(const char* separator, int test)
{
	std::cout << separator << std::endl;
	std::cout << test << std::endl;
}

template<typename... PACK>
void Test(const char* separator, int test, PACK... pack)
{
	Test(separator, test);

	Test(pack...);

	//if constexpr (0 < sizeof...(pack))
	//{
	//	Test(pack...);
	//}
}

void Case2Run()
{
	Test("Apple", 3, "Banana", 2, "Orange", 1);
}