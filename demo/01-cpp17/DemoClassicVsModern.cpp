//---------------------------------------------------------------------------

#pragma hdrstop

#include "DemoClassicVsModern.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

class TFoo {
public:
	int buzz;
};

void Test(TFoo& foo) {
}

void classic_cpp_code() {
	std::vector<int>items;
	items.push_back(1);
	items.push_back(2);
	items.push_back(5);

	std::map<int, std::wstring>map;
	map[1] = L"One";
	map[5] = L"Two";
	map[7] = L"Three";

	for (std::map<int, std::wstring>::iterator it = map.begin();
	it != map.end(); ++it) {
		std::pair<int, std::wstring>pair = *it;
		std::wcout << "  {" << pair.first << ", " <<
			pair.second.c_str() << "}" << std::endl;
	};

	std::cout << "  int vector items: ";
	for (std::vector<int>::const_iterator it = items.begin();
		it != items.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	TFoo* foo = new TFoo();
	try {
		Test(*foo);
	}
	__finally {
		delete foo;
	}
}

void modern_cpp_code() {
	std::vector<int> items { 1, 2, 5 };

	std::map<int, std::wstring> map { { 1, L"One" },
	   { 2, L"Two" }, { 3, L"Three" } };

	for (const auto&pair : map)
		std::wcout << "  {" << pair.first << ", " <<
			pair.second.c_str() << "}" << std::endl;

	std::cout << "  int vector items: ";
	for (const auto i : items)
		std::cout << i << " ";
	std::cout << std::endl;

	std::unique_ptr<TFoo> foo(new TFoo());
	Test(*foo);
}

void demo_classic_vs_modern_cpp_code() {
	classic_cpp_code();
	modern_cpp_code();
}