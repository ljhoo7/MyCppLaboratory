#include "Case3.h"

void Case3()
{
	/*PUT("test/test2", []() {
		std::cout << "hello" << std::endl;
		});*/

	static const char path[] = "test/test2";

	Put<path> tmp;

	tmp.Enroll([]()
		{
			std::cout << "test" << std::endl;
		});

	Put<path>::g_callable();
}

template<const char* PATH>
std::function<void()> Put<PATH>::g_callable;