#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

#include <iostream>
#include "DemoClassicVsModern.h"
#include "DemoStdTasks.h"
#include "DemoStdMutex.h"
#include "DemoCpp17Auto.h"
#include "DemoCpp17Misc.h"

int _tmain(int argc, _TCHAR* argv[]) {

	std::cout << "[demo] classic C++ Code vs modern C++ code... \n";
	demo_classic_vs_modern_cpp_code();
	std::cout << "[demo] Use std::thread and std::mutex... \n";
	demo_std_thread_and_mutex();
	std::cout << "[demo] from cppreference std::thread and std::mutex... \n";
	demo_cppreference_mutex_thread();
	std::cout << "[demo] C++17 auto type declaration... \n";
	demo_cpp17_auto();
	std::cout << "[demo] C++17 auto features... \n";
	demo_cpp17_misc();

	std::system("pause");
	return 0;
}



