//---------------------------------------------------------------------------

#pragma hdrstop

#include "DemoCpp17Misc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <cmath>
#include <iostream>
#include <optional>
#include <algorithm>
#include <vector>

template<auto v>
struct constant {
	static constexpr auto value = v;
};

// Nested namespaces
namespace Foo::Bar::Z {
	class Something {};
}

// Inline variables - put this in header
// Behaves like an inline method: can be defined identically in multiple
// translation units; behaves as though there is just one
inline int i = 5;

// New attributes
// Can attach to structs/classes too, to make the type undiscardable
[[nodiscard]] int MustUseReturnValue(int a) {
	return a * 2;
}


constexpr int MethodCall(int a, int b) {
	return a * b;
}

constexpr auto degreesToRadians(const double deg) {
    return deg * (M_PI / 180.0);
}

constexpr int sum(int n) {
	if (n > 0) {
		return n + sum(n-1);
	} else {
        return n;
    }
}

// [[ Example from C++ blog ]]
// [[ 7 Features of C++17 that Will Simplify Your Code ]]
// * constexpr-if
// https://tech.io/playgrounds/2205/7-features-of-c17-that-will-simplify-your-code/constexpr-if
template <typename T>
auto get_value(T t) {
	if constexpr (std::is_pointer_v<T>)
		return *t;
	else
		return t;
}

void demo_cpp17_misc(){
	{
		auto v1 = constant<123>::value;
		auto v2 = constant<'z'>::value;

		Foo::Bar::Z::Something s;

		int j =
			MustUseReturnValue(5);

		// optional: may hold a value
		std::optional<int> a(5);
		std::optional<int> b;
		if (a.has_value()) {
			int z = *a + b.value_or(0); // *deref, or .value()
		}
		// also std::variant (a union) and std::any

		// Parallel STL algorithms
		std::vector<int> vec { 1, 10, 8, 7, 15, 4, 5, 3 };
		std::sort(std::execution::par, vec.begin(), vec.end());
	}

	// ----------------------------------------------------------
	{
		constexpr int i = 1 + 2;
		constexpr int j = MethodCall(5, 10);

		constexpr auto rad = degreesToRadians(90);

		constexpr auto SumOneToTen = sum(10);

		int a = 5;
		int* pa = &a;

		auto valueA = get_value(a);
		auto valuePA = get_value(pa);

		std::cout << "  " << valueA << std::endl;
		std::cout << "  " << valuePA << std::endl;
	}
}

