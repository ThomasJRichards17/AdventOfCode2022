#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

int get_score_from_char(const char &c)
{
    return c < 'a' ? c - 'A' + 27 : c - 'a' + 1;
}

int part_one()
{
    std::string line;
    int current_score = 0;

    std::ifstream input_file("..\\..\\..\\..\\Day3\\input.txt");

    while (std::getline(input_file, line))
    {
        std::unordered_set<char> left_set;
        std::unordered_set<char> right_set;

        auto left = 0;
        auto right = line.length() - 1;

        while (left < right)
        {
            left_set.insert(line[left]);
            right_set.insert(line[right]);

            if (left_set.contains(line[right]))
            {
                current_score += get_score_from_char(line[right]);
                break;
            }
            else if (right_set.contains(line[left]))
            {
                current_score += get_score_from_char(line[left]);
                break;
            }

            ++left;
            --right;
        }
    }

    return current_score;
}

int part_two()
{
    std::string line;
    int line_count = 0;
    std::unordered_map<char, int> char_map;
    int current_score = 0;

    std::ifstream input_file("..\\..\\..\\..\\Day3\\input.txt");

    while (std::getline(input_file, line))
    {
        std::unordered_set<char> line_set;
        for (auto c : line)
        {
            if (!line_set.contains(c))
            {
                line_set.insert(c);
                char_map[c]++;
            }
        }

        if (line_count == 2)
        {
            for (auto const& [c, count] : char_map)
            {
                if (count == 3)
                {
                    current_score += get_score_from_char(c);
                    line_count = 0;
                    char_map.clear();
                    break;
                }
            }
        }
        else
        {
            line_count++;
        }
    }

    return current_score;
}

int main()
{
    std::cout << "---------- PART ONE ----------\n";
    std::cout << part_one() << "\n";
    std::cout << "---------- PART TWO ----------\n";
    std::cout << part_two() << "\n";

    return 0;
}