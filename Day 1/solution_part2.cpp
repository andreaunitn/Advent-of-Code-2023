#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

bool ascending(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
    return a.second < b.second;
}

int main()
{
    std::vector<std::string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::map<std::string, std::string> numbers_map = {{"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};

    std::ifstream file("input.txt");

    std::string line;
    int result = 0;
    while (getline(file, line))
    {   
        std::vector<std::pair<std::string, int> > number_pos;

        for (const auto& number : numbers)
        {
            size_t pos = line.find(number);
            while (pos != std::string::npos)
            {
                number_pos.emplace_back(number, pos);
                pos = line.find(number, pos + 1);
            }
        }

        for (size_t i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i]))
            {
                number_pos.emplace_back(std::string(1, line[i]), i);
            }
        }

        if (number_pos.empty()) continue;

        std::sort(number_pos.begin(), number_pos.end(), ascending);

        std::string first = number_pos.front().first;
        std::string last = number_pos.back().first;

        std::string first_digit = isdigit(first[0]) ? first : numbers_map[first];
        std::string last_digit = isdigit(last[0]) ? last : numbers_map[last];

        result += std::stoi(first_digit + last_digit);
    }

    std::cout << result << std::endl;

    return 0;
}
