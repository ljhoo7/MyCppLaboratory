#pragma once

#include <iostream>

void Case3();

template<char CHAR1, char... REST>
void Test()
{
    std::cout << CHAR1;

    if constexpr (0 < sizeof...(REST))
    {
        Test<REST...>();
    }
    else
    {
        std::cout << std::endl;
    }
}

template<const char* STRING>
void Test()
{
    static int tmp = 0;

    std::cout << tmp++ << ' ';
    std::cout << STRING << std::endl;
}