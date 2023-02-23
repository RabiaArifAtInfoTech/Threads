#include<iostream>
#include<thread>
#include<mutex>

std::mutex mute;

void f1(int num)
{
	mute.lock();
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\n Running thread " << num << " for " << i << " th time.";
	}
	mute.unlock();
}

int main()
{
	std::thread t1(f1, 1);
	std::thread t2(f1, 2);

	/*t1.join();

	t2.join();*/

	/*t1.detach();

	t2.detach();*/

	std::cout << "foo: " << t1.joinable() << '\n';
	std::cout << "bar: " << t2.joinable() << '\n';

	if (t1.joinable()) t1.join();
	if (t2.joinable()) t2.join();

	/*std::cout << t1.get_id() << std::endl;
	std::cout << t2.get_id() << std::endl;*/


	std::cout << "\n\n\n";
	return 0;
}