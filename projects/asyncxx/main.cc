
#include "async.hh"

static void showdate();

void do_async_test()
{
    showdate();

    //started the timer
    auto start_time = std::chrono::system_clock::now();

    // std::future<std::string> resultFromDb = std::async(std::launch::async, async::asyncxx::fetchDataFromDatabase, "DB_DATA_CXX");

    //the synchronous way
    auto db_data_sync = async::asyncxx::fetchDataFromDatabase("DB_DATA_CXX");
    auto file_data = async::asyncxx::fetchDataFromFile("FILE_DATA");

    //the blocking procedure (which will release the thread lock when the data comes in the future)
    // auto database_data = resultFromDb.get();

    //stops the timer
    auto end_time = std::chrono::system_clock::now();
    //calculates the process time
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count();

    std::cout << db_data_sync << " || " << file_data << '\n';
    std::cout << "program finished after " << duration << " seconds"
              << "\n";
}

void showdate()
{
    auto now = std::chrono::system_clock::now();
    time_t date = std::chrono::system_clock::to_time_t(now);
    std::cout << ctime(&date) << '\n';
}

int main()
{
    do_async_test();
}