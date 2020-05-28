//*************************************************************
//*************************************************************
// Author: Robert Poenaru  ******** email: robert.poenaru@protonmail.ch
//***************** USEFUL-CPP-ALGORITHMS ******************
//*************************************************************
//*************************************************************

// Write data to an array & compute the bandwidth
// Calculate the size of the array in MB - total memory occupied by the created vector

#include <vector>
#include <iostream>
#include <cmath>
#include <functional>
#include <chrono>
#include <utility>

//get the size of any vector
//it is the sum of the container itself + the number of elements
template <typename T>
size_t vector_size(const std::vector<T> &v)
{
    auto container_size = v.size() * sizeof(T);
    auto core_size = sizeof(std::vector<T>);
    return container_size + core_size;
}

template <typename T>
T math_fct(T arg)
{
    return arg * sqrt(arg) - log(arg) + sin(arg);
}

template <typename T>
void write_to_vector(std::vector<T> &v, size_t SIZE)
{
    for (auto id = 0; id < SIZE; ++id)
    {
        v.emplace_back(std::forward<T>(math_fct<T>(sqrt(id))));
    }
}

void run_test()
{
    std::vector<double> v;
    const size_t size = 10000000;

    auto start = std::chrono::high_resolution_clock::now();
    write_to_vector(v, size);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    auto array_mb = static_cast<double>(vector_size<double>(v) * 0.000001);
    auto bandwidth = static_cast<double>(array_mb / (duration_ms * 0.000001));

    std::cout << "size[v]= " << array_mb << " MB" << '\n';
    std::cout << "Data generation took " << duration_ms * 0.000001 << " s" << '\n';
    std::cout << "The program wrote the data with the bandwidth= " << bandwidth << " MB/s" << '\n';
}

int main()
{
    const int n_tests = 10;
    for (auto test = n_tests; test > 0; test--)
    {
        std::cout << "*********Test " << n_tests - test << "*********" << '\n';
        run_test();
    }
}