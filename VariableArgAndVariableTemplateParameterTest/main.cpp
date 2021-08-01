#include <cstdarg>
#include <iostream>

struct TestClass
{
	int m_age;
	double m_pie = 3.141592;
	int m_tmp;
};

std::ostream& operator<<(std::ostream& stream, const TestClass& test)
{
	return stream << test.m_tmp;
}

void TestFuncWithVariableArg(int argc, ...)
{
	va_list args;
	va_start(args, argc);

	TestClass tt1 = va_arg(args, TestClass);
	int tt2 = va_arg(args, int);

	va_end(args);

	std::cout << tt1 << std::endl;
	std::cout << tt2 << std::endl;
}

template<typename T>
void TestFuncWithVariableTemplateArg(T arg)
{
	std::cout << arg << std::endl;
}

template<typename T, typename... Typelist>
void TestFuncWithVariableTemplateArg(T arg, Typelist... argList)
{
	TestFuncWithVariableTemplateArg(arg);
	TestFuncWithVariableTemplateArg(argList...);
}

int main()
{
	TestClass test;
	test.m_tmp = 14;

	//TestFuncWithVariableArg(13, test, 15);

	TestFuncWithVariableTemplateArg(13, test, 15);
}