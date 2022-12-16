#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>

/*
    Paraphrased Description:
      - Rock Paper Scissors on each line
      - First value is the opponent input
        - A for Rock
        - B for Paper
        - C for Scissors
      - Second value is what we should do
        - X for Rock
        - Y for Paper
        - Z for Scissors
      - Points per round = shape selected + round outcome
        - 1 for Rock
        - 2 for Paper
        - 3 for Scissors

        - 0 for Loss
        - 3 for Draw
        - 6 for Win

    Goal:
     - Find points we end up with if we follow the strategy
*/

int part_one()
{
    std::unordered_map<char, char> win_map = { {'X', 'C'}, {'Y', 'A'}, {'Z', 'B'} };
    std::unordered_map<char, char> draw_map = { {'X', 'A'}, {'Y', 'B'}, {'Z', 'C'} };
    std::unordered_map<char, int> score_map = { {'X', 1}, {'Y', 2}, {'Z', 3} };

    std::string line;
    int current_score = 0;

    std::ifstream input_file("..\\..\\..\\..\\Day2\\input.txt");

    while (std::getline(input_file, line))
    {
        auto in = line[0];
        auto choice = line[2];

        current_score += score_map[choice];

        if (win_map[choice] == in)
        {
            current_score += 6;
        }
        else if (draw_map[choice] == in)
        {
            current_score += 3;
        }
    }

    return current_score;
}

int part_two()
{
    std::unordered_map<char, char> win_map = { {'A', 'B'}, {'B', 'C'}, {'C', 'A'} };
    std::unordered_map<char, char> loss_map = { {'A', 'C'}, {'B', 'A'}, {'C', 'B'} };
    std::unordered_map<char, int> choice_score_map = { {'A', 1}, {'B', 2}, {'C', 3} };

    std::string line;
    int current_score = 0;

    std::ifstream input_file("..\\..\\..\\..\\Day2\\input.txt");

    while (std::getline(input_file, line))
    {
        auto in = line[0];
        auto desired = line[2];

        if (desired == 'X')
        {
            current_score += choice_score_map[loss_map[in]];
        }
        else if (desired == 'Y')
        {
            current_score += 3 + choice_score_map[in];
        }
        else
        {
            current_score += 6 + choice_score_map[win_map[in]];
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