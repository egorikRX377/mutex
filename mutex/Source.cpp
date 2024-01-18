#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>


using namespace std;


void doWork1()
{
	cout << "WORK1" << endl;
}

void doWork2()
{
	cout << "WORK2" << endl;
}


mutex mut1;

int main()
{
	thread th1(doWork1);
	thread th2(doWork2);
	unique_lock<mutex> ul(mut1, std::defer_lock);
	ul.lock();
	ul.unlock();

	th1.join();
	th2.join();
	return 0;
}