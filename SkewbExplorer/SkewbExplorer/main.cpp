#include "skewbUtils.h"
#include <iostream>
#include <string>
#include <sstream>

void decimalToOctal(uint64_t value, sequence& moves);
bool isValidSolution(const Skewb& skewb, const sequence& moves);
void printSequence(const sequence& moves);
Skewb getScrambledSkewb();

size_t searchDepth = 0;

int main()
{
    Skewb skewb;
    sequence moves = { 0 };
    uint64_t curr = 0;

    std::cout << "Enter Skewb Scramble (R/R'/L/L'/U/U'/B/B'):" << std::endl;
    skewb = getScrambledSkewb();

    std::cout << std::endl;

    while (true)
    {
        moves = { 0 };
        decimalToOctal(curr, moves);
        if (isValidSolution(skewb, moves))
            break;

        curr++;
    }

    std::cout << std::endl << "Solution Found:" << std::endl;
    printSequence(moves);

    return 0;
}

void decimalToOctal(uint64_t value, sequence& moves)
{
    for (size_t i = 0; i < MAX_SEQUENCE && value; i++)
    {
        if (i + 1 > searchDepth)
        {
            std::cout << "\rSearching Depth: " << i + 1 << std::flush;
            searchDepth = i + 1;
        }

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
        std::string moveStr = (moves[i] == 1) ? "R" :
                              (moves[i] == 2) ? "R'" :
                              (moves[i] == 3) ? "L" :
                              (moves[i] == 4) ? "L'" :
                              (moves[i] == 5) ? "U" :
                              (moves[i] == 6) ? "U'" :
                              (moves[i] == 7) ? "B" :
                              (moves[i] == 8) ? "B'" : "";
        std::cout << moveStr << " ";
    }
    std::cout << std::endl;
}

Skewb getScrambledSkewb()
{
    Skewb skewb;
    scramble scramble;
    std::string scrambleStr, moveStr;
    size_t index = 0;

    std::getline(std::cin, scrambleStr);
    std::stringstream scrambleStrStream(scrambleStr);

    while (scrambleStrStream >> moveStr)
    {
        uint8_t move = (moveStr == "R") ? 1 :
                       (moveStr == "R'") ? 2 :
                       (moveStr == "L") ? 3 :
                       (moveStr == "L'") ? 4 :
                       (moveStr == "U") ? 5 :
                       (moveStr == "U'") ? 6 :
                       (moveStr == "B") ? 7 :
                       (moveStr == "B'") ? 8 : 0;
        scramble.push_back(move);

        index++;
    }

    skewb.performSequence(scramble);

    return skewb;
}