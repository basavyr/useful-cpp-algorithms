#include "async.hh"

static std::chrono::seconds t = std::chrono::seconds(3);

async::asyncxx::asyncxx()
{
}

async::asyncxx::~asyncxx()
{
}

std::string async::asyncxx::fetchDataFromDatabase(const std::string &db_data)
{
    std::cout << "started to fetch from the database"
              << "\n";
    std::this_thread::sleep_for(t);
    std::cout << "finished to fetch the data from db"
              << "\n";
    return "Fetched db +" + db_data;
}

std::string async::asyncxx::fetchDataFromFile(const std::string &file_data)
{
    std::cout << "started to fetch data from file"
              << "\n";
    std::this_thread::sleep_for(t);
    std::cout << "started to fetch data from the file"
              << "\n";
    return "Fetched file +" + file_data;
}

std::vector<int> async::asyncxx::generateVector(const int n)
{
    std::vector<int> int_vector;
    std::random_device rd;
    std::mt19937 twister{rd()};
    std::uniform_int_distribution<int> int_dist(0, n);

    for (auto id = 0; id < n; ++id)
    {
        int_vector.emplace_back(int_dist(twister));
    }
    return int_vector;
}