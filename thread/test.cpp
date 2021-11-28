/*#include <thread>
#include<future>
#include<string>
#include<stdexcept>
#include<functional>
#include<utility>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>

using namespace std;

void doSomething(int num, char c) {
	try {
		default_random_engine dre(42*c);
		uniform_int_distribution<int> id(10, 1000);

		for (int i = 0; i < num; ++i) {
			this_thread::sleep_for(chrono::milliseconds(id(dre)));
			cout.put(c).flush();
		}
	}
	catch (const exception & e) {
		cerr << "THREAD_EXCEPTION (tread " << this_thread::get_id()
			<< "): " << e.what() << endl;
	}
	catch (...) {
		cerr << "THREAD_EXCEPTION (tread " << this_thread::get_id()
			<< "): " << endl;
	}
}
int main() {
	try {
		thread t1(doSomething, 5, ',');
		cout << "- start fg thread" << t1.get_id() << endl;

		for (int i = 0; i < 5; ++i) {
			thread t(doSomething, 10, 'a' + i);
			cout<< "- detach start bg thread" << t.get_id() << endl;
			t.detach();
		}
		cin.get();
		cout<< "- join fg thread" << t1.get_id() << endl;
		t1.join();
	}
	catch (const exception & e) {
		cerr << "EXCEPTION: " << e.what() << endl;
	}
	thread t1(doSomething, 5, ',');
	thread t2(doSomething, 5, '+');
	thread t3(doSomething, 5, '-');
	cout << "t3 ID:       " << t3.get_id() << endl;
	cout << "main ID:     " << this_thread::get_id() << endl;
	cout << "nothread ID: " << thread::id() << endl;
	t1.detach();
	t2.detach();
	t3.detach();
	return 0;
}*/

#include <condition_variable>
#include <mutex>
#include <future>
#include <thread>
#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
mutex queueMutex;
condition_variable queueCondVar;

void provider(int val) {
	for (int i = 0; i < 6; ++i) {
		{
			lock_guard<mutex> lg(queueMutex);
			q.push(val + i);
		}
		queueCondVar.notify_one();
		this_thread::sleep_for(chrono::microseconds(10*val));
	}
}

void consumer(int num) {
	while (true) {
		int val;
		{
			unique_lock<mutex> ul(queueMutex);
			queueCondVar.wait(ul, [] {return !q.empty(); });
			val = q.front();
			q.pop();
		}
		cout << "consumer " << num << ": " << val << endl;
	}
}

int main() {
	auto p1 = async(launch::async, provider, 100);
	auto p2 = async(launch::async, provider, 300);
	auto p3 = async(launch::async, provider, 500);

	auto c1=  async(launch::async, consumer, 1);
	auto c2 = async(launch::async, consumer, 2);
}