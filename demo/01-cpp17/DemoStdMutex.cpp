//---------------------------------------------------------------------------

#pragma hdrstop

#include "DemoStdMutex.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <random>

std::random_device randomDevice; // obtain a random number from hardware
std::mt19937 generator(randomDevice()); // seed the generator
std::uniform_int_distribution<> distribution(200, 700);

std::mutex mutexDelayGenerator;

int generateResponseDelay () {
	std::lock_guard<std::mutex> guard(mutexDelayGenerator);
	return distribution(generator);
}


std::map<std::string, std::string> webPages;
std::mutex MutexWebPages;

void GetHttpPage(const std::string& url, const std::string& title)
{
	int delay = generateResponseDelay();
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	std::string result = "<html><head<title>"+title+"</title></head><body>"+
		"fake content... delay:" + std::to_string(delay) + " ms</body></html>";
	std::lock_guard<std::mutex> guard(MutexWebPages);
	webPages[url] = result;
}

struct UrlRequest {
	std::string title;
	std::string url;
};

void demo_webpage_mutex_thread()
{
	std::vector<UrlRequest> requests {
		{"foo","http://www.foo.com"},
		{"bar","http://www.bar.pl"},
		{"abc","http://www.abc.org"},
		{"xyz","http://www.xyz.eu"}
	};
	std::vector<std::thread> downloadThreads;
	for (auto& req : requests) {
		downloadThreads.push_back ( std::thread (GetHttpPage,  req.url, 
			req.title) );
	}
	for (auto &t : downloadThreads) {
		t.join();
	}

	// safe to access webPages without lock now, as the threads are joined
	for (const auto &page : webPages) {
		std::cout << "  "<< page.first << " => " << page.second << std::endl;
	}
}