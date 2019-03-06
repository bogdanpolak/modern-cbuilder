// ---------------------------------------------------------------------------

#pragma hdrstop

#include "DemoSmartPointers.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <memory>

class Bar {
public:
	Bar() { std::cout << "constructed, "; }
	void dosomething() { std::cout << "working, "; }
	~Bar() { std::cout << "destroyed, "; }
};

void demo_SmartPointers() {
	// -------- -------- -------- --------
	std::cout << "  object bar: ";
	{
		Bar* bar = new Bar();
		bar->dosomething();
	}
	std::cout << std::endl;
	// -------- -------- -------- --------
	std::cout << "  object bar: ";
	{
		auto bar = std::make_unique<Bar>();
		bar->dosomething();
	}
	std::cout << std::endl;
	// -------- -------- -------- --------
}
