#include "skewbUtils.h"
#include <iostream>

void decimalToOctal(unsigned int value, sequence& moves);
bool isValidSolution(const Skewb& skewb, const sequence& moves);
void printSequence(const sequence& moves);

int main()
{
    sequence moves = { 0 };
    int curr = 0;

    Skewb skewb;

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
        moves[i] = (value & 0b00000111); // base-8 digit
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
        std::string move = ((moves[i] == 1) ? "R" :
                            (moves[i] == 2) ? "R'" :
                            (moves[i] == 3) ? "L" :
                            (moves[i] == 4) ? "L'" :
                            (moves[i] == 5) ? "U" :
                            (moves[i] == 6) ? "U'" :
                            (moves[i] == 7) ? "B" :
                            (moves[i] == 8) ? "B'" : "");
        std::cout << move << " ";
    }
    std::cout << std::endl;
}