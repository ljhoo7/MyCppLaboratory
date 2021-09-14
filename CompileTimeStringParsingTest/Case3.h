#pragma once

#include <iostream>
#include <functional>

void Case3();

template<const char* PATH, typename CALLABLE>
void Test(CALLABLE callable)
{
    callable();
}

#define COMBINE_INTERNAL(X,Y) X##Y
#define COMBINE(X,Y) COMBINE_INTERNAL(X,Y)
#define PUT(PATH,CALLABLE) static const char COMBINE(PUT,__LINE__)[]{ PATH };Put<COMBINE(PUT,__LINE__)>(CALLABLE)