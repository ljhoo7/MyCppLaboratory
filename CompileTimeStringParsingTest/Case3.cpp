#include "Case3.h"

void Case3()
{
	PUT("test/test2", []() {
		std::cout<<"hello"<<std::endl;
	});

	PUT("test/test2", []() {
		std::cout << "hello" << std::endl;
		});
}