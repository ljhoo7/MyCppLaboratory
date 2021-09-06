#include "Case3.h"

void Case3()
{
	/*Test<'T','E','S','T'>();
	Test<'T', 'E', 'S'>();
	Test<'T', 'E'>();
	Test<'T'>();*/

	static const char test[] = "Test1";
	Test<test>();
	Test<test>();

	static const char test2[] = "Test2";
	Test<test2>();
	Test<test2>();
}