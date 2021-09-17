#include "Case3.h"

void Case3()
{
	/*METHOD("test/test2", []() {
		std::cout << "hello" << std::endl;
		});*/

	static const char path[] = "test/test2";

	METHOD<path>::PUT([]()
		{
			std::cout << "put test" << std::endl;
		});

	METHOD<path>::GET([]()
		{
			std::cout << "get test" << std::endl;
		});

	METHOD<path>::g_put();
}

template<const char* PATH>
std::function<void()> METHOD<PATH>::g_put;
template<const char* PATH>
std::function<void()> METHOD<PATH>::g_get;
template<const char* PATH>
std::function<void()> METHOD<PATH>::g_post;
template<const char* PATH>
std::function<void()> METHOD<PATH>::g_head;