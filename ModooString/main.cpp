#include "ModooString.h"

using namespace GenericBoson;

int main()
{
	ModooString modooString("test");
	ModooString modooString2("OfAll");

	modooString.Append(modooString2);

	return 0;
}