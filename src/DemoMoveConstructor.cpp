//---------------------------------------------------------------------------

#pragma hdrstop

#include "DemoMoveConstructor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <random>
#include <string>
#include <chrono>

class BigVector {
	int size_;
	double* arr_;
public:
	// Copy Constructor
	BigVector () {
		std::random_device rnddev;
		std::mt19937 gen(rnddev());
		std::uniform_int_distribution<> dis(0, 1000000);
		size_ = 10000 + (dis(gen) % 10) * 100;
		arr_ = new double[size_];
		for (int i = 0; i<size_; ++i)
			arr_[i] = (double)dis(gen) / 1000;
	}
	BigVector (const BigVector& rhs) {
		size_ = rhs.size_;
		arr_ = new double[size_];
		for (int i=0; i<size_; ++i)
			arr_[i] = rhs.arr_[i];
	}
	// Move Constructor
	BigVector (BigVector&& rhs) {
	   size_ = rhs.size_;
	   arr_ = rhs.arr_;
       rhs.arr_ = nullptr;
	}
	std::string to_string() {
		std::string s = "  vector size: " + std::to_string(size_);
		if (size_>0) {
			s += " v[0]=" + std::to_string(arr_[0]);
			int i2 = size_-1;
			s += " v["+std::to_string(i2)+"]="+std::to_string(arr_[i2]);
		}
		return s;
	}
	~BigVector() { delete [] arr_; }
};

BigVector createVector () {
	return BigVector();
}

void processVector (BigVector big) {
	std::cout << "  "<< big.to_string() << '\n';
}

void reportDurationMs (std::chrono::steady_clock::time_point begin) {
	using namespace std::chrono;
	auto end = steady_clock::now();
	int ms = duration_cast<microseconds>(end - begin).count();
	std::cout << "  Duration: " << std::to_string(ms) << " ms.\n";
}


void demo_move_constructor () {
	/*
	 * Sample copied form YouTube C++ course by Bo Qian
	 * Rvalue Reference - Move Semantics
	 *   https://youtu.be/IOkgBrXCtfo
	 */
	// ----
	// check: https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html

	std::cout << "Passing object using copy constructor.\n";
	auto begin = std::chrono::steady_clock::now();
	BigVector big1 = createVector();
	processVector (big1);
	reportDurationMs (begin);
	std::cout << "Passing object using move constructor.\n";
	begin = std::chrono::steady_clock::now();
	processVector (createVector());
	reportDurationMs (begin);
}
