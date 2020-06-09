//*************************************************************
//*************************************************************
// Author: Robert Poenaru  ******** email: robert.poenaru@protonmail.ch
//***************** USEFUL-CPP-ALGORITHMS ******************
//*************************************************************
//*************************************************************

// C++ implementation for function pointers

#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>

//this program calculates different evaluations of mathematical functions using functions pointers.
//source contains multple mathematical methods, then user can generate a array of pairs (x,y), where y is the value of f(x), and using function pointers, f can be chosen at generatin time

//doubles the argument given
int function1(int arg)
{
    return arg * 2;
}

//squares the argument given
int function2(int arg)
{
    return arg * arg;
}

//sum of x+exp(x)
int function3(int arg)
{
    return arg + exp(arg);
}

struct pair
{
    int x, y;
};

std::vector<pair> generateDataPoints(int n, int (*f)(int arg))
{
    std::vector<pair> datapoints;
    for (auto id = 0; id < n; ++id)
    {
        auto fx = f(id);
        datapoints.emplace_back();
        datapoints.at(id).x = id;
        datapoints.at(id).y = fx;
    }
    return datapoints;
}

void runApp()
{
    auto now = std::chrono::system_clock::now();
    auto date = std::chrono::system_clock::to_time_t(now);
    std::cout << "App Ok @: " << std::ctime(&date) << "\n";
}

int main()
{
    std::ofstream out("out.dat");
    runApp();
    auto x = generateDataPoints(100, function3);
    for (auto &&n : x)
    {
        out << n.x << " , " << n.y << "\n";
    }
}