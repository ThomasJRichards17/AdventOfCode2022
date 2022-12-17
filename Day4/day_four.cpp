#include <iostream>
#include <sstream>
#include <fstream>

/*
    Paraphrased Description:
      - Each section has an ID number
      - Each elf is assigned to a range of section IDs
      - Elves are paired up
        - Each line has the ranges each elf in the pair has been assigned
      - Some assignments overlap

    Goal:
     - Find how many pairs have one range fully containing the other
*/

int part_one()
{
    std::string line;
    std::ifstream input_file("..\\..\\..\\..\\Day4\\input.txt");

    while (std::getline(input_file, line))
    {
    }

    return 0;
}

int part_two()
{
    std::string line;
    std::ifstream input_file("..\\..\\..\\..\\Day4\\input.txt");

    while (std::getline(input_file, line))
    {
    }

    return 0;
}

int main()
{
    std::cout << "---------- PART ONE ----------\n";
    std::cout << part_one() << "\n";
    std::cout << "---------- PART TWO ----------\n";
    std::cout << part_two() << "\n";

    return 0;
}