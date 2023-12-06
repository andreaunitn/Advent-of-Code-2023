#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>

int main()
{
    std::ifstream file("input.txt");

    std::string line = "";
    int result = 0;
    while(getline(file, line))
    {
        std::string partial_result = "";
        std::string tmp1 = "";
        std::string tmp2 = "";
        
        for(int i = 0; i < line.size(); i++)
        {
            if(isdigit(line.at(i)))
            {
                tmp1 = line.at(i);
                break;
            }
        }

        for(int i = line.size() - 1; i >= 0; i --)
        {
            if(isdigit(line.at(i)))
            {
                tmp2 = line.at(i);
                break;
            }
        }

        partial_result = tmp1 + tmp2;
        result += stoi(partial_result);
    }

    std::cout << result << std::endl;

    return 0;
}