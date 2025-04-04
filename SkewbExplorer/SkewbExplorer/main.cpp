#include "skewbUtils.h"
#include <iostream>
#include <string>
#include <sstream>

void decimalToOctal(unsigned int value, sequence& moves);
bool isValidSolution(const Skewb& skewb, const sequence& moves);
void printSequence(const sequence& moves);
Skewb getScrambledSkewb();

int main()
{
    Skewb skewb;
    sequence moves = { 0 };
    int curr = 0;

    std::cout << "Enter Skewb Scramble (R/R'/L/L'/U/U'/B/B'):" << std::endl;
    skewb = getScrambledSkewb();

    while (true)
    {
        moves = { 0 };
        decimalToOctal(curr, moves);
        if (isValidSolution(skewb, moves))
            break;

        curr++;
    }

    std::cout << "Solution Found:" << std::endl;
    printSequence(moves);

    return 0;
}

void decimalToOctal(unsigned int value, sequence& moves)
{
    for (size_t i = 0; i < MAX_SEQUENCE && value; i++)
    {
        moves[i] = (value & 7) + 1; // base-8 digit
        value >>= 3;
    }
}

bool isValidSolution(const Skewb& skewb, const sequence& moves)
{
    Skewb temp(skewb);

    temp.performSequence(moves);
    return temp.isSolved();
}

void printSequence(const sequence& moves)
{
    for (size_t i = 0; i < MAX_SEQUENCE; i++)
    {
        std::string move = (moves[i] == 1) ? "R" :
                           (moves[i] == 2) ? "R'" :
                           (moves[i] == 3) ? "L" :
                           (moves[i] == 4) ? "L'" :
                           (moves[i] == 5) ? "U" :
                           (moves[i] == 6) ? "U'" :
                           (moves[i] == 7) ? "B" :
                           (moves[i] == 8) ? "B'" : "";
        std::cout << move << " ";
    }
    std::cout << std::endl;
}

Skewb getScrambledSkewb()
{
    Skewb skewb;
    sequence moves = { 0 };
    std::string scramble, move;
    size_t index = 0;

    std::getline(std::cin, scramble);
    std::stringstream ss(scramble);

    while (ss >> move && index < MAX_SEQUENCE)
    {
        moves[index] = (move == "R") ? 1 :
                       (move == "R'") ? 2 :
                       (move == "L") ? 3 :
                       (move == "L'") ? 4 :
                       (move == "U") ? 5 :
                       (move == "U'") ? 6 :
                       (move == "B") ? 7 :
                       (move == "B'") ? 8 : 0;

        index++;
    }

    skewb.performSequence(moves);

    return skewb;
}