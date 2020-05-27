//*************************************************************
//*************************************************************
// Author: Robert Poenaru  ******** email: robert.poenaru@protonmail.ch
//***************** USEFUL-CPP-ALGORITHMS ******************
//*************************************************************
//*************************************************************

// C++ implementation that shows the current time and date

#include <iostream>
#include <chrono>

void showDate(std::chrono::system_clock::time_point tp)
{
    auto current_time = std::chrono::system_clock::to_time_t(tp);
    std::cout << ctime(&current_time);
}

int main()
{
    std::cout << "Current time is..." << '\n';
    auto now = std::chrono::system_clock::now();
    showDate(now);
}