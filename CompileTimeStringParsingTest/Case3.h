#pragma once

#include <iostream>

void Case3();

template<char CHAR1, char CHAR2 = ' ', char CHAR3 = ' ', char CHAR4 = ' '>
void Test()
{
	std::cout << CHAR1 << CHAR2 << CHAR3 << CHAR4 << std::endl;
}