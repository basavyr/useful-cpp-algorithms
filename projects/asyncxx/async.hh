#include <thread>
#include <future>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
namespace async
{
    class asyncxx
    {
    private:
        /* data */
    public:
        asyncxx(/* args */);
        ~asyncxx();
        static std::string fetchDataFromFile(const std::string &file_data);
        static std::string fetchDataFromDatabase(const std::string &db_data);
        static std::vector<int> generateVector(const int n);
    };
} // namespace async
