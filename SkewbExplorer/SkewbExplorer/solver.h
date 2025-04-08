#ifndef SOLVER
#define SOLVER

#include "skewb.h"

class Solver
{
public:
	// Methods
	static void findSolution(const Skewb& skewb);

private:
	// Helper Methods
	static void getNextSequence(sequence& moves);
	static bool isValidSolution(const Skewb& skewb, const sequence& moves);
	static bool isInverseMove(const uint8_t last, const uint8_t curr);
	static void printSequence(const sequence& moves);

	// Fields
	static uint64_t _searchDepth;
	static uint64_t _currSequence;
};

#endif