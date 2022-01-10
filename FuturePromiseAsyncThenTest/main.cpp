#include <iostream>
#include <string>
#include <future>
#include <thread>

void Test(std::promise<std::string>* param)
{
	std::this_thread::sleep_for(std::chrono::seconds(3));

	param->set_value("test");
}

int main()
{
	std::promise<std::string> test;

	std::future<std::string> data = test.get_future();
	
	std::thread task(Test, &test);

	std::cout << data.get() << std::endl;

	if (true == task.joinable())
	{
		task.join();
	}

	return 0;
}