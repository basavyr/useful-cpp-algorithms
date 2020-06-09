//*************************************************************
//*************************************************************
// Author: Robert Poenaru  ******** email: robert.poenaru@protonmail.ch
//***************** USEFUL-CPP-ALGORITHMS ******************
//*************************************************************
//*************************************************************

// C++ implementation that creates a container with integer numbers from a string-stream
//N string streams will be converted into vectors of integers

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

std::ifstream input;

static std::vector<std::vector<int>> integer_container;

inline void newline() { std::cout << '\n'; }

template <typename T>
void show(T &&arg)
{
    std::cout << arg;
    newline();
}

static void printArray(const std::vector<int> &v)
{
    for (auto &&n : v)
        std::cout << n << " ";
    newline();
}

int main()
{
    int n_streams;

    input.open("input.dat");
    input >> n_streams;

    std::string discarded_line;

    std::getline(input, discarded_line);

    const std::string space = " ";
    const std::string endline = "\n";

    for (int id = 0; id < n_streams; ++id)
    {
        std::string line;
        std::getline(input, line);
        std::string current_number_stream;
        std::vector<int> current_integer_container;
        for (auto line_id = 0; line_id < line.size(); ++line_id)
        {
            auto current_string_char = std::string{line.at(line_id)}; //get a string from the current character
            if (current_string_char == space)
            {
                current_integer_container.emplace_back(std::move((std::stoi(current_number_stream))));
                current_number_stream.clear();
            }
            current_number_stream.append(current_string_char);
            if (line_id == line.size() - 1)
            {
                current_integer_container.emplace_back(std::move(std::stoi(current_number_stream)));
                current_number_stream.clear();
            }
        }
        line.clear();
        integer_container.emplace_back(current_integer_container);
    }
    int id = 0;
    for (auto &&n : integer_container)
    {
        printArray(integer_container.at(id++));
    }
    return 0;
}