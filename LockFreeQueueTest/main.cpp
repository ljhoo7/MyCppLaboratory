#include <iostream>
#include <chrono>
#include <vector>
#include <memory>

#include "Case1.h"
#include "Case2.h"

volatile bool g_keepLooping = true;

void Test(CaseBase* pCaseBase);

int main()
{
	std::vector<std::shared_ptr<CaseBase>> vec;

	vec.emplace_back(std::make_shared<Case1>());
	vec.emplace_back(std::make_shared<Case2>());

	for (auto& iCase : vec)
	{
		std::cout << " [ " << iCase->GetCaseName() << " ] " << std::endl;

		auto startTime = std::chrono::system_clock::now();
		Test(iCase.get());
		auto endTime = std::chrono::system_clock::now();

		auto elapsedTime = endTime - startTime;

		std::cout << "ElapsedTime (ms) : " << std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime).count() << std::endl;
	}
}

void Test(CaseBase* pCaseBase)
{
	srand(time(NULL));

	std::vector<std::thread> threadVector;

	for (int k = 0; k < 10; ++k)
	{
		threadVector.emplace_back([pCaseBase]()
		{
			for (int m = 0; m < 100 * 10000; ++m)
			{
				int randNum = rand() % 1000;

				if (randNum % 2)
				{
					pCaseBase->EnqueueWrap(randNum);
				}
				else
				{
					int tmp;
					pCaseBase->DequeueWrap(tmp);
				}
			}
		});
	}

	for (int k = 0; k < 10; ++k)
	{
		if (true == threadVector[k].joinable())
		{
			threadVector[k].join();
		}
	}
}