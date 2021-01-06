/* 
    BoostedCpp.cpp : This file contains the 'main' function. 
    - Will contain a mix of different libraries which will/will not include Boost.
*/
#include "multithread.h"
#include <thread>

using namespace std; 
using namespace multithread;


int main() {
    
    for (int i = 0; i < 5; i++) {
        thread th(multithread::exe_thread, i);
        th.join();
    }

    return 0;
}