#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>

/*
    Paraphrased Description:
      - Calories on each line
      - Blank line means the end of what that elf is carrying

    Goal:
      - Part One
        - Find most calories carried
      - Part Two
        - Find sum of top 3 calories carried 
*/

int part_one()
{
    int max = 0;
    int currentCount = 0;
    std::string line;

    std::ifstream input_file("..\\..\\..\\..\\Day1\\input.txt");

    while (std::getline(input_file, line))
    {
        if (line.empty())
        {
            max = std::max(max, currentCount);
            currentCount = 0;
        }
        else
        {
            currentCount += std::stoi(line);
        }
    }

    return std::max(max, currentCount);
}

int part_two()
{
    std::priority_queue<int> ordered_calories;
    std::string line;
    int currentCount = 0;

    std::ifstream input_file("..\\..\\..\\..\\Day1\\input.txt");

    while (std::getline(input_file, line))
    {
        if (line.empty())
        {
            ordered_calories.emplace(currentCount);
            currentCount = 0;
        }
        else
        {
            currentCount += std::stoi(line);
        }
    }

    int max = 0;
    for (auto i = 0; i < 3; i++)
    {
        if (!ordered_calories.empty())
        {
            max += ordered_calories.top();
            ordered_calories.pop();
        }
    }
    return max;
}

int main()
{
    std::cout << "---------- PART ONE ----------\n";
    std::cout << part_one() << "\n";
    std::cout << "---------- PART TWO ----------\n";
    std::cout << part_two() << "\n";

    return 0;
}