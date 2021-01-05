// BoostedCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/asio.hpp>
#include <iostream>

using namespace std;

int main()
{
    boost::asio::io_context io;
    boost::asio::steady_timer timer = boost::asio::steady_timer(io, boost::asio::chrono::seconds(1));
    
    cout << "Start" << endl;
    
    timer.wait();
    io.run();

    cout << "Stop" << endl;

    system("Pause");

    return 0;
}