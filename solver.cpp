#include "solver.h"
#include <iostream>

uint64_t Solver::_searchDepth = 0;
uint64_t Solver::_currSequence = 0;

void Solver::findSolution(const Skewb& skewb)
{
    sequence moves{};
    moves.fill(Moves::EMPTY);

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
    uint8_t move = Moves::EMPTY, lastMove = Moves::EMPTY;

    for (size_t i = 0; i < MAX_SEQUENCE && value; i++)
    {
        // Update depth indicator if needed
        if (i + 1 > _searchDepth)
        {
            std::cout << "\rSearching Depth: " << i + 1 << std::flush;
            _searchDepth = i + 1;
        }

        // Extract base-8 digit
        move = (value & 7) + 1; 
        value >>= 3;

        // If the sequence has following moves which cancel
        if (isInverseMove(lastMove, move) || move == lastMove)
        {
            moves.fill(Moves::EMPTY);
            return;
        }

        // Insert next move into the sequence
        moves[i] = move;
        lastMove = move;
    }
}

bool Solver::isValidSolution(const Skewb& skewb, const sequence& moves)
{
    Skewb temp(skewb);

    temp.performSequence(moves);
    return temp.isSolved();
}

bool Solver::isInverseMove(const uint8_t last, const uint8_t curr)
{
    switch (last)
    {
    case Moves::R:
        return curr == Moves::RPrime;

    case Moves::RPrime:
        return curr == R;

    case Moves::L:
        return curr == Moves::LPrime;

    case Moves::LPrime:
        return curr == Moves::L;

    case Moves::U:
        return curr == Moves::UPrime;

    case Moves::UPrime:
        return curr == Moves::U;

    case Moves::B:
        return curr == Moves::BPrime;

    case Moves::BPrime:
        return curr == Moves::B;

    default:
        return false;
    }
}

void Solver::printSequence(const sequence& moves)
{
    for (size_t i = 0; i < MAX_SEQUENCE; i++)
    {
        std::string moveStr = (moves[i] == Moves::R) ? "R" :
                              (moves[i] == Moves::RPrime) ? "R'" :
                              (moves[i] == Moves::L) ? "L" :
                              (moves[i] == Moves::LPrime) ? "L'" :
                              (moves[i] == Moves::U) ? "U" :
                              (moves[i] == Moves::UPrime) ? "U'" :
                              (moves[i] == Moves::B) ? "B" :
                              (moves[i] == Moves::BPrime) ? "B'" : "";
        std::cout << moveStr << " ";
    }
    std::cout << std::endl;
}
