//---------------------------------------------------------------------------

#pragma hdrstop

#include "DemoStdTasks.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>

std::mutex M;
std::mutex N;
std::mutex L;

void lowpriolock(){
	L.lock();
	N.lock();
	M.lock();
	N.unlock();
}

void lowpriounlock(){
	M.unlock();
	L.unlock();
}

void highpriolock(){
	N.lock();
	M.lock();
	N.unlock();
}

void highpriounlock(){
	M.unlock();
}

void hpt(const char* s){
	//cout << "hpt trying to get lock here" << endl;
	highpriolock();
	std::cout << s << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2));
	highpriounlock();
}

void lpt(const char* s){
	//cout << "lpt trying to get lock here" << endl;
	lowpriolock();
	std::cout << s << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2));
	lowpriounlock();
}

void demo_std_thread_and_mutex(){
	std::thread t0(lpt,"low prio t0 working here");
	std::thread t1(lpt,"low prio t1 working here");
	std::thread t2(hpt,"high prio t2 working here");
	std::thread t3(lpt,"low prio t3 working here");
	std::thread t4(lpt,"low prio t4 working here");
	std::thread t5(lpt,"low prio t5 working here");
	std::thread t6(lpt,"low prio t6 working here");
	std::thread t7(lpt,"low prio t7 working here");
	//std::cout << "All threads created" << std::endl;
	t0.join();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
}
