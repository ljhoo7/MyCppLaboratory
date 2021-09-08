#pragma once

#include <iostream>
#include <functional>

void Case3();

template<const char* PATH, typename CALLABLE>
void Test(CALLABLE callable)
{
    callable();
}