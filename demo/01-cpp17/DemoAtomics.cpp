//---------------------------------------------------------------------------

#pragma hdrstop

#include "DemoAtomics.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <atomic>

void demo_atomics () {
    // atomics are not supported yet
	struct Counters { int a; int b; };
	// Counters is trivially-copyable type
	// std::atomic<Counters> cnt;
}
