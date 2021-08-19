#include "Case1.h"

Case1::Case1()
{
	m_caseName = typeid(*this).name();
}

volatile bool g_keepLooping = true;
QueueT<int> g_queue;

void Case1::Run()
{
	srand(time(NULL));

	std::vector<std::thread> threadVector;

	for (int k = 0; k < 10; ++k)
	{
		threadVector.emplace_back([]()
		{
			int randNum = rand() % 1000;

			if (randNum % 2)
			{
				g_queue.Enqueue(randNum);
			}
			else
			{
				g_queue.Dequeue(randNum);
			}

			Sleep(randNum);
		});
	}
}
