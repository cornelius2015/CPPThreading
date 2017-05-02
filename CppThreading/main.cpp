//
//  main.cpp
//  CppThreading
//
//  Created by Con Daly on 02/05/2017.
//  Copyright © 2017 Con Daly. All rights reserved.
//

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
std::mutex g_i_mutex;

void PrintLoop1(int x)
{
    
    for(int i=0;i<x;i++)
    {
        lock_guard<std::mutex> guard(g_i_mutex);
        cout<<"LoopA "<<i<<endl;
    }
}


void PrintLoop2(int x)
{
    
    for(int i=0;i<x;i++)
    {
        lock_guard<std::mutex> guard(g_i_mutex);
        cout<<"LoopB "<<i<<endl;
    }
}

int main(int argc, const char * argv[])
{
    // insert code here...
    thread A(PrintLoop1, 100);
    thread B(PrintLoop2, 100);
    
    A.join();
    B.join();
    std::cout << "Hello, World!\n";
    return 0;
}
