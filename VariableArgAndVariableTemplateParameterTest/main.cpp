#include <cstdarg>
#include <iostream>
#include <functional>
#include <vector>
#include <any>

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

template<typename FUNC>
void Wrapped(const FUNC& func)
{
	TestClass test;
	test.m_tmp = 14;

	//TestFuncWithVariableArg(13, test, 15);

	func(13, test, 15);
}

std::vector<std::function<void(const std::vector<std::any>&)>> g_variableParameterFunctionVector;

int main()
{
	g_variableParameterFunctionVector.emplace_back([](const std::vector<std::any>& paramList) {
		std::cout << paramList[0].type().name() << std::endl;
		std::cout << paramList[1].type().name() << std::endl;
		std::cout << paramList[2].type().name() << std::endl;
	});

	g_variableParameterFunctionVector.emplace_back([](const std::vector<std::any>& paramList) {
	});

	g_variableParameterFunctionVector.emplace_back([](const std::vector<std::any>& paramList) {
	});

	g_variableParameterFunctionVector.emplace_back([](const std::vector<std::any>& paramList) {
	});

	std::vector<std::any> tmpVector;
	tmpVector.push_back(1);
	tmpVector.push_back(3.14);
	tmpVector.push_back(TestClass());

	g_variableParameterFunctionVector[0](tmpVector);

	system("pause");
}
