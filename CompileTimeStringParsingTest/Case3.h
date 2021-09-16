#pragma once

#include <iostream>
#include <functional>

void Case3();

//#define COMBINE_INTERNAL(X,Y) X##Y
//#define COMBINE(X,Y) COMBINE_INTERNAL(X,Y)
//#define PUT(PATH,CALLABLE) static const char COMBINE(PUT,__LINE__)[]{ PATH };Put<COMBINE(PUT,__LINE__)>(CALLABLE)

template<const char* PATH>
class PUT
{
public:
	static std::function<void()> g_callable;

	template<typename CALLABLE>
	static void Register(CALLABLE callable)
	{
		if (nullptr != g_callable)
		{
			throw new std::exception("test");
			return;
		}

		g_callable = callable;
	}
};