#include "Case3.h"

#define Method(PATH,CALLABLE) static const char test[]{ PATH };Test<test>(CALLABLE)

void Case3()
{
	Method("test/test2", []() {
		std::cout<<"hello"<<std::endl;
	});
}