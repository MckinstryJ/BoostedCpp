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

/*
    MULTI THREADING EXAMPLE WITH TRANSACTIONS
*/
// Global varaibles for threads
double acct_balance = 100;
mutex acct_lock;


string multithread::get_current_time() {
    auto now_time = chrono::system_clock::now();
    time_t sleep_time = chrono::system_clock::to_time_t(now_time);

    return ctime(&sleep_time);
}

void multithread::get_money(int id, double withdrawal) {
    lock_guard<mutex> lock(acct_lock);
    // this_thread::sleep_for(chrono::seconds(3));
    cout << id << " tries to withdrawal $" << withdrawal << " on " << get_current_time() << endl;

    if ((acct_balance - withdrawal) >= 0) {
        acct_balance -= withdrawal;
        cout << "===> New Account Balance is $" << acct_balance << endl;
    }
    else {
        cout << "===> Not Enough Money in Account" << endl;
        cout << "===> Current Balance is $" << acct_balance << endl;
    }
}

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

/*
    MULTITHREADING EXAMPLE WITH FINDING PRIMES
*/
mutex vectLock;
vector<unsigned int> primeVect;

// Function to actually find primes
void multithread::find_primes(unsigned int start, unsigned int end) {
    for (unsigned int x = start; x <= end; x += 2) {
        for (unsigned int y = 2; y < x; y++) {
            if (x % y == 0) {
                break;
            }
            else if (y + 1 == x) {
                vectLock.lock();
                primeVect.push_back(x);
                vectLock.unlock();
            }
        }
    }
}

// Similar to exe_threads above
void multithread::find_primes_with_threads(unsigned int start, unsigned int end, unsigned int numThreads) {
    vector<thread> threadVect;
    unsigned int threadSpread = end / numThreads;
    unsigned int newEnd = start + threadSpread - 1;

    int startTime = clock();
    for (unsigned int x = 0; x < numThreads; x++) {
        threadVect.emplace_back(multithread::find_primes, start, newEnd);
        start += threadSpread;
        newEnd += threadSpread;
    }

    for (auto& t : threadVect) {
        t.join();
    }
    int endTime = clock();
    
    for (auto i : primeVect) {
        cout << i << "\n";
    }

    cout << "Exe Time: " << (endTime - startTime) / double(CLOCKS_PER_SEC);
}