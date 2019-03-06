//---------------------------------------------------------------------------

#pragma hdrstop

#include "DemoCpp17Auto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <initializer_list>
#include <algorithm>


class Employee {
	// Lots of code here
};

struct PersonID {
	std::string firstName;
	std::string lastName;
};

class Employees {
public:
	auto findEmployee(const std::string Name) { return 1; }
};

int returnAnInt() {
	return 1;
}

auto returnSomething() {
	return 1;
}

// Compiler error, because function could return int and float
auto returnConfusion() {
	std::srand(std::time(0));
	if (std::rand() %2 == 0) {
		// return -1;
		return -1.0;   // to compile change literal to float value: 1.0
	} else {
		return M_PI;
	}
}
std::string intVectorJoin (std::vector<int> v, std::string separator)
{
	auto it = v.begin();
	std::string res = std::to_string(*it);
	for (it = ++it; it != v.end(); ++it)
		res += separator+std::to_string(*it);
	return res;
}



void demo_cpp17_auto() {
	auto i = returnAnInt();
	auto j = returnSomething();
	auto k = returnConfusion();
	auto al = {10, 11, 12}; // initializer list
	auto employeeList = std::make_unique<Employees>();
	auto person = employeeList->findEmployee("Jane Smith");

	// -----------------------------------------------------
	std::cout << "  i: " << i  << std::endl;
	std::cout << "  j: " << j  << std::endl;
	std::cout << "  k: " << k  << std::endl;
	std::cout << "  list size() = " << al.size() << "  | list: ";
	for (auto elem: al) {
		std::cout << std::to_string(elem) << ' ';
	}
	std::cout << '\n';
	std::vector<int> vi {al};
	std::cout << "  list 1: {" << intVectorJoin(vi,", ") << "}\n";
	std::vector<int> vi2(20);
	std::generate(vi2.begin(), vi2.end(), [](){ return std::rand() % 99; });
	std::cout << "  list 2 : {" << intVectorJoin(vi2,", ") << "}\n";
}
