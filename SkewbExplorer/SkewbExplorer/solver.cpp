#include "solver.h"
#include <iostream>

size_t Solver::_searchDepth = 0;
size_t Solver::_currSequence = 0;

void Solver::findSolution(const Skewb& skewb)
{
	sequence moves = { 0 };

    while (true)
    {
        getNextSequence(moves);
        if (isValidSolution(skewb, moves))
            break;
    }

    std::cout << std::endl << "Solution Found:" << std::endl;
    printSequence(moves);
}

void Solver::getNextSequence(sequence& moves)
{
    uint64_t value = _currSequence++;

    for (size_t i = 0; i < MAX_SEQUENCE && value; i++)
    {
        // Update depth indicator if needed
        if (i + 1 > _searchDepth)
        {
            std::cout << "\rSearching Depth: " << i + 1 << std::flush;
            _searchDepth = i + 1;
        }

        // Extract base-8 digit
        moves[i] = (value & 7) + 1; 
        value >>= 3;
    }
}

bool Solver::isValidSolution(const Skewb& skewb, const sequence& moves)
{
    Skewb temp(skewb);

    temp.performSequence(moves);
    return temp.isSolved();
}

void Solver::printSequence(const sequence& moves)
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
