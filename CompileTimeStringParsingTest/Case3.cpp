#include "Case3.h"

void Case3()
{
	/*PUT("test/test2", []() {
		std::cout << "hello" << std::endl;
		});*/

	static const char path[] = "test/test2";

	PUT<path>::Register([]()
		{
			std::cout << "test" << std::endl;
		});

	PUT<path>::g_callable();
}

template<const char* PATH>
std::function<void()> PUT<PATH>::g_callable;