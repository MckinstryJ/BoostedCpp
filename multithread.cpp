/*
    An example of a cpu based multithreaded program 
           where information is isolated per thread.

    New topics covered:
    - defining no warnings
    - creating a class in VS
    - creating a namespace for cpp / header files
    
*/

#define _CRT_SECURE_NO_WARNINGS

#include "multithread.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

int multithread::get_random(int max) {
	srand(time(NULL));
	return rand() % max;
}

void multithread::exe_thread(int id) {
    auto nowTime = chrono::system_clock::now();
    time_t sleepTime = chrono::system_clock::to_time_t(nowTime);
    tm myLocalTime = *localtime(&sleepTime);

    cout << "Thread: " << id << " Sleep Time: " << ctime(&sleepTime) << endl;

    cout << "Date: " << myLocalTime.tm_mon << "/"
        << myLocalTime.tm_mday << "/"
        << myLocalTime.tm_year << " --- "
        << myLocalTime.tm_hour << ":"
        << myLocalTime.tm_min << ":"
        << myLocalTime.tm_sec << endl;

    this_thread::sleep_for(chrono::seconds(get_random(3)));
    nowTime = chrono::system_clock::now();
    sleepTime = chrono::system_clock::to_time_t(nowTime);
    cout << "Thread: " << id << " Awake Time: " << ctime(&sleepTime) << endl;
}