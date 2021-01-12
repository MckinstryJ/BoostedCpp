#pragma once

#include <string>
#include <vector>

using namespace std;

namespace multithread
{
	string get_current_time();
	void get_money(int id, double withdrawal);
	int get_random(int max);
	void exe_thread(int id);
	void find_primes(unsigned int start, unsigned int end);
	void find_primes_with_threads(unsigned int start, unsigned int end, unsigned int numThreads);
};