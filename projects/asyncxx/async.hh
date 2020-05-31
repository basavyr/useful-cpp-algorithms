#include <thread>
#include <future>
#include <iostream>
#include <fstream>
#include <string>
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
    };
} // namespace async
