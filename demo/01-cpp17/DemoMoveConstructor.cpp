//---------------------------------------------------------------------------

#pragma hdrstop

#include "DemoMoveConstructor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <random>
#include <string>
#include <chrono>


#include <ostream>
#include <iomanip>
#include <utility>
 
class Foo {
public:
	std::string text;
	int value;
	Foo(int n = 0)
		: text{"default"}, value{n}
	{
		std::cout << " constructor default\n";
	}
	Foo(const Foo& foo)
		: text(foo.text+"."), value{foo.value+1}
	{
		std::cout << " constructor copy \n";
	}
	Foo(Foo&& foo)
		: text(std::move(foo.text)), value(std::exchange(foo.value, 0))
	{
		std::cout << " constructor move\n";
    }
    ~Foo() { 
        std::cout << " destructor\n";
    }
};
std::ostream& operator<<(std::ostream &strm, const Foo &foo) {
     return strm << "Foo(text:\"" << foo.text << "\", value:" << foo.value << ")";
}

Foo f(Foo a) {
    return a;
}

void demo_move_constructor () {
	Foo foo1 = f( Foo(10) );
	std::cout << "  [1] foo1 = " << foo1 << '\n';
	Foo foo2(foo1);
	std::cout << "  [1] foo1 = " << foo1 << '\n';
	std::cout << "  [1] foo2 = " << foo2 << '\n';
	Foo foo3 = std::move(foo1);
	std::cout << "  [1] foo1 = " << foo1 << '\n';
	std::cout << "  [1] foo3 = " << foo3 << '\n';
}
