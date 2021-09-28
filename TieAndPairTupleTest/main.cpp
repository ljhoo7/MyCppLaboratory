#include <iostream>

using namespace std;

struct Temp
{
	int m_temp = 3;

	Temp() = default;
	Temp(const Temp&&) = default;
};

pair<int, Temp> Test()
{
	Temp tmp;
	return { 3, tmp};
}

int main()
{
	int a, b;

	tie(a, b) = Test();

	cout << a << "," << b << endl;

	return 0;
}