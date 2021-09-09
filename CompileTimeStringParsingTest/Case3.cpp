#include "Case3.h"

#define COMBINE_INTERNAL(X,Y) X##Y
#define COMBINE(X,Y) COMBINE_INTERNAL(X,Y)
#define PUT(PATH,CALLABLE) static const char COMBINE(PUT,__LINE__)[]{ PATH };Test<COMBINE(PUT,__LINE__)>(CALLABLE)

void Case3()
{
	PUT("test/test2", []() {
		std::cout<<"hello"<<std::endl;
	});

	PUT("test/test2", []() {
		std::cout << "hello" << std::endl;
		});
}