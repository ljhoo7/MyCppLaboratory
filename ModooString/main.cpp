#include <iostream>
#include "ModooString.h"

using namespace GenericBoson;

int main()
{
	// test 1
	/*ModooString modooString("test");
	ModooString modooString2("OfAll");

	modooString.Append(modooString2);*/

	// test 2
	ModooString targetStr("It's my test string.");
	std::cout << targetStr.FindFirstOf("test") << std::endl;
	std::cout << targetStr.FindFirstOf("ljh") << std::endl;

	return 0;
}