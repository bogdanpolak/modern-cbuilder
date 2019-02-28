// ---------------------------------------------------------------------------

#pragma hdrstop

#include "DemoSmartPointers.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <memory>

class Foo {
public:
	Foo() { std::cout << "  -> object constructed ... \n"; }
	~Foo() { std::cout << "  -> object destroyed ... \n"; }
	void dosomething() { std::cout << "  -> object is working ... \n"; }
};

void demo_SmartPointers() {
	// -------- -------- -------- --------
	std::cout << "begin \n";
	{
		Foo* foo = new Foo();
		foo->dosomething();
	}
	std::cout << "end \n";
	// -------- -------- -------- --------
	std::cout << "begin \n";
	{
		auto foo = std::make_unique<Foo>();
		foo->dosomething();
	}
	std::cout << "end \n";
	// -------- -------- -------- --------
}
