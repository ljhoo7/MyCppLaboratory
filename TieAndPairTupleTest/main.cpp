#include <iostream>

using namespace std;

struct Temp
{
	int m_temp = 999;

	Temp() = default;
};

pair<int, Temp> Test()
{
	Temp tmp;
	return { 3, tmp };
}

int main()
{
	int a;
	Temp b;

	tie(a, b) = Test();

	cout << a << "," << b.m_temp << endl;

	return 0;
}