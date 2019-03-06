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

void LowPriorityLock(){
	L.lock();
	N.lock();
	M.lock();
	N.unlock();
}

void LowPriorityUnlock(){
	M.unlock();
	L.unlock();
}

void HighPriorityLock(){
	N.lock();
	M.lock();
	N.unlock();
}

void HighPriorityUnlock(){
	M.unlock();
}

void HighPriorityTask(const char* s){
	HighPriorityLock();
	std::this_thread::sleep_for(std::chrono::milliseconds(2));
	std::cout << s << std::endl;
	HighPriorityUnlock();
}

void LowPriorityTask(const char* s){
	LowPriorityLock();
	std::this_thread::sleep_for(std::chrono::milliseconds(2));
	std::cout << s << std::endl;
	LowPriorityUnlock();
}

void demo_std_thread_and_mutex(){
	std::thread t0(LowPriorityTask,"  Low priority task: t0 working here");
	std::thread t1(LowPriorityTask,"  Low priority task: t1 working here");
	std::thread t2(LowPriorityTask,"  Low priority task: t2 working here");
	std::thread t3(LowPriorityTask,"  Low priority task: t3 working here");
	std::thread t4(HighPriorityTask,"  !!! High priority task: t4 working here");
	std::thread t5(LowPriorityTask,"  Low priority task: t5 working here");
	//std::cout << "All threads created" << std::endl;
	t0.join();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
}
