#include <iostream>
#include <chrono>
#include <vector>
#include <memory>

#include "Case1.h"

int main()
{
	std::vector<std::shared_ptr<CaseBase>> vec;

	vec.emplace_back(std::make_shared<Case1>());

	for (auto& iCase : vec)
	{
		std::cout << " [ " << iCase->GetCaseName() << " ] " << std::endl;

		auto startTime = std::chrono::system_clock::now();
		iCase->Run();
		auto endTime = std::chrono::system_clock::now();

		auto elapsedTime = endTime - startTime;

		std::cout << "ElapsedTime (ms) : " << std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime).count() << std::endl;
	}
}