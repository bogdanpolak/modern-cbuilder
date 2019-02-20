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

int _tmain(int argc, _TCHAR* argv[]) {

	// demo_classic_vs_modern_cpp_code();
	// demo_std_thread_and_mutex();
	demo_cppreference_mutex_thread();


	std::system("pause");
	return 0;
}



