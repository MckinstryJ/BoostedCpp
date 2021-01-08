/* 
    BoostedCpp.cpp : This file contains the 'main' function. 
    - Will contain a mix of different libraries which will/will not include Boost.
*/

#include "multithread.h"
#include <thread>
#include <string>
#include <thread>

using namespace std; 
using namespace multithread;


int main() {
    int start = 0;
    const int thread_size = 10;

    /* example of isolated thread use
    for (int i = 0; i < 5; i++) {
        thread th(multithread::exe_thread, i);
        th.join();
    }
    */

    /*
        Shared Global Variable - Bank Account Example
    */

    /* Using an array of threads for money example
    thread threads[thread_size];
    for (int i = start; i < thread_size; ++i) {
        threads[i] = thread(multithread::get_money, i, 15);
    }

    for (int i = start; i < thread_size; ++i) {
        threads[i].join();
    }
    */
    
    // Same money example but using previous thread / join method
    for (int i = start; i < thread_size; i++) {
        thread th(multithread::get_money, i, 15);
        th.join();
    }
    

    return 0;
}