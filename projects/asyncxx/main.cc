
#include "async.hh"

static void showdate()
{
    auto now = std::chrono::system_clock::now();
    time_t date = std::chrono::system_clock::to_time_t(now);
    std::cout << ctime(&date) << '\n';
}

inline auto duration = [](auto start, auto end) {
    return static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() * 0.001);
};

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

void sync_generation(const int size)
{
    auto start = std::chrono::system_clock::now();
    auto task1 = async::asyncxx::generateVector(size);
    auto task2 = async::asyncxx::generateVector(size);
    auto task3 = async::asyncxx::generateVector(size);
    auto task4 = async::asyncxx::generateVector(size);
    auto task5 = async::asyncxx::generateVector(size);
    auto stop = std::chrono::system_clock::now();
    auto duration_s = duration(start, stop);
    std::cout << "T_sync= " << duration_s << " s\n";
}

void async_generation(const int arr_size)
{
    std::vector<std::future<std::vector<int>>> futures;
    auto start = std::chrono::system_clock::now();
    for (int id = 0; id < 5; ++id)
    {
        // auto task_id = std::async(std::launch::async, async::asyncxx::generateVector, arr_size);
        // the async task (launched in async mode) will only live in the present scope, and the default destructor requires the task to me moved into a future, or bound to a reference
        //the task id must be moved, since it is bound to a variable, and once the compiler reaches the end of the scope, it must get destroyed.
        // futures.emplace_back(task_id));  gives error
        // futures.emplace_back(std::move(task_id)); //works
        futures.emplace_back(std::async(std::launch::async, async::asyncxx::generateVector, arr_size)); //this works since the async function is passed to the array as soon as it finishes
    }
    for (auto &&e : futures)
    {
        e.get();
    }
    auto stop = std::chrono::system_clock::now();
    auto duration_s = duration(start, stop);
    std::cout << "T_async= " << duration_s << " s\n";
}

static void future_generator(std::vector<std::future<int>> &future_v, int n, int (*function)(int), int arg)
{
    for (int id = 0; id < n; ++id)
    {
        auto task = std::async(std::launch::async, function, arg);
        future_v.emplace_back(std::move(task));
    }
}

//add some math functions for testing purposes
int math_fct1(int arg)
{
    return std::forward<int>(arg * 2);
}

int math_fct2(int arg)
{
    return std::forward<int>(arg - 1);
}

template <typename T>
inline size_t check_size(std::vector<T> &v)
{
    return v.size();
}

int main()
{
    // do_async_test();

    //for this particular size, the process of generating an array with randoms is around one second.
    const int size = 6000000;
    // sync_generation(size);
    // async_generation(size);
    std::vector<std::future<int>> futures;
    std::cout << check_size<std::future<int>>(futures) << "\n";
    future_generator(futures, 100, math_fct1, 2);
    std::cout << check_size<std::future<int>>(futures) << "\n";

    //don't show the array of future
    // for (auto &&n : futures)
    //     std::cout << n.get() << "\n";
}