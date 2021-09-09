#include "Case3.h"

#define Method(NAME, PATH,CALLABLE) static const char NAME[]{ PATH };Test<NAME>(CALLABLE)

void Case3()
{
	Method(a, "test/test2", []() {
		std::cout<<"hello"<<std::endl;
	});
}