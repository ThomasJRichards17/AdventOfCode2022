#include<iostream>
#include <sstream>
#include <fstream>

/*
    Paraphrased Description:
      - Calories on each line
      - Blank line means the end of what that elf is carrying

    Goal:
     - Find elf with most calories
*/

int main()
{
    std::ifstream input_file("..\\..\\..\\..\\Day1\\input.txt");

    std::stringstream buffer;
    buffer << input_file.rdbuf();

    std::string calories_per_elf = buffer.str();

    return 0;
}