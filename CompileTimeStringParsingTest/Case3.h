#pragma once

#include <iostream>
#include <functional>
#include <sstream>

void Case3();

//#define COMBINE_INTERNAL(X,Y) X##Y
//#define COMBINE(X,Y) COMBINE_INTERNAL(X,Y)
//#define METHOD(PATH,CALLABLE) static const char COMBINE(METHOD,__LINE__)[]{ PATH };Put<COMBINE(METHOD,__LINE__)>(CALLABLE)

template<const char* PATH>
class METHOD
{
	static void ThrowAlreadyRegisterdException(const std::string_view methodName)
	{
		std::stringstream strstream;
		strstream << "A " << methodName << " method has already been registered at this " << PATH << "." << std::endl;
		throw new std::exception(strstream.str().c_str());
	}
public:
	static std::function<void()> g_put;
	static std::function<void()> g_get;
	static std::function<void()> g_post;
	static std::function<void()> g_head;

	template<typename CALLABLE>
	static void PUT(CALLABLE callable)
	{
		if (nullptr != g_put)
		{
			ThrowAlreadyRegisterdException("PUT");
		}

		g_put = callable;
	}

	template<typename CALLABLE>
	static void GET(CALLABLE callable)
	{
		if (nullptr != g_get)
		{
			ThrowAlreadyRegisterdException("GET");
		}

		g_get = callable;
	}

	template<typename CALLABLE>
	static void POST(CALLABLE callable)
	{
		if (nullptr != g_post)
		{
			ThrowAlreadyRegisterdException("POST");
		}

		g_post = callable;
	}

	template<typename CALLABLE>
	static void HEAD(CALLABLE callable)
	{
		if (nullptr != g_head)
		{
			ThrowAlreadyRegisterdException("HEAD");
		}

		g_head = callable;
	}
};