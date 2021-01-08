#pragma once

#include <string>

using namespace std;

namespace multithread
{
	string get_current_time();
	void get_money(int id, double withdrawal);
	int get_random(int max);
	void exe_thread(int id);
};

