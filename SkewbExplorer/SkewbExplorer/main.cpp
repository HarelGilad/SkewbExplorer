#include "solver.h"

int main()
{
    Skewb skewb = Skewb::getScrambledSkewb();
    Solver::findSolution(skewb);

    return 0;
}