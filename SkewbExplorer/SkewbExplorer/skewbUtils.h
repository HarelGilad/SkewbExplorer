#ifndef SKEWB
#define SKEWD

#include <array>

#define FACES 6
#define PIECES_PER_FACE 5
#define MAX_SEQUENCE 15

using skewbState = std::array<uint8_t, FACES * PIECES_PER_FACE>;
using sequence = std::array<uint8_t, MAX_SEQUENCE>;
 
// w   w | o   o | g   g | r   r | b   b | y   y
//   w	 |   o   |   g	 |   r   |   b	 |   y
// w   w | o   o | g   g | r   r | b   b | y   y
// 
// 1   2 | 6   7 | 11  12 | 16  17 | 21  22 | 26  27
//   0	 |   5   |   10   |   15   |   20   |   25
// 4   3 | 9   8 | 14  13 | 19  18 | 24  23 | 29  28

class Skewb
{
public:
	// Constructors
	Skewb();
	Skewb(const Skewb& other);

	// Methods
	bool isSolved();
	void performSequence(const sequence& moves);

private:
	// Helper Methods
	void R();
	void RPrime();
	void L();
	void LPrime();
	void U();
	void UPrime();
	void B();
	void BPrime();

	// Fields
	skewbState _skewb;
};

#endif
