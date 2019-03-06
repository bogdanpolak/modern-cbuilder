//---------------------------------------------------------------------------

#pragma hdrstop

#include "DemoAtomics.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<bool> ready (false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void taskCountTo1Milion (int threadId) {
	// wait for the ready signal
	while (!ready)
		std::this_thread::yield();
	// count to 1 million
	for (volatile int i=0; i<1000000; ++i) {
	}
	// first one will set the flag
	if (!winner.test_and_set())
		std::cout << "  The winner is: thread #" << threadId << std::endl;
};

void demo_atomics () {
	std::vector<std::thread> threads;
	std::cout << "  Create 10 threads (count to million) ..." << std::endl;
	for (int i=1; i<=10; ++i) {
		threads.push_back( std::thread (taskCountTo1Milion,i) );
	}
	ready = true;
	// for (auto& th : threads)
	for (std::thread& th : threads)
		th.join();
}
