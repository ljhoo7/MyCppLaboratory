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

template<const char* PATH>
class Put
{
public:
	static std::function<void()> g_callable;

	//void 

	template<typename CALLABLE>
	void Enroll(CALLABLE callable)
	{
		if (nullptr != g_callable)
		{

			return;
		}

		g_callable = callable;
	}


};