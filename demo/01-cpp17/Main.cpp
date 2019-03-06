#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

#include <iostream>

#include "DemoSmartPointers.h"
#include "DemoMoveConstructor.h"
#include "DemoCpp17Auto.h"
#include "DemoCpp17Misc.h"

#include "DemoClassicVsModern.h"

#include "DemoStdTasks.h"
#include "DemoStdMutex.h"
#include "DemoAtomics.h"

void block_cpp17_basics() {
	std::cout << "[demo] C++11 Smart Pointers \n";
	demo_SmartPointers();
	std::cout << "[demo] C++11 Move Constructor \n";
	demo_move_constructor ();
	std::cout << "[demo] C++17 auto type declaration... \n";
	demo_cpp17_auto();
	std::cout << "[demo] C++17 misc features... \n";
	demo_cpp17_misc();
}

void block_code_migration() {
	std::cout << "[demo] classic C++ Code vs modern C++ code... \n";
	demo_classic_vs_modern_cpp_code();
}

void block_parallel_code() {
	std::cout << "[demo] Use std::thread and std::mutex... \n";
	demo_std_thread_and_mutex();
	std::cout << "[demo] simulate WWW page get (std::mutex & std::thread) ... \n";
	demo_webpage_mutex_thread();
	std::cout << "[demo] atomics ... \n";
	demo_atomics();
}

int _tmain(int argc, _TCHAR* argv[]) {
	block_cpp17_basics();
	block_code_migration();
	block_parallel_code();
	// --------------------
	std::system("pause");
	return 0;
}



