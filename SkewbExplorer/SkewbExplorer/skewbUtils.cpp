#include "skewbUtils.h"

Skewb::Skewb()
{
    for (size_t face = 0; face < FACES; face++)
    {
        for (size_t piece = 0; piece < PIECES_PER_FACE; piece++)
        {
            _skewb[face * PIECES_PER_FACE + piece] = (uint8_t)face;
        }
    }
}

Skewb::Skewb(const Skewb& other) :
    _skewb(other._skewb)
{
}

bool Skewb::isSolved()
{
    return _skewb[0] == _skewb[1] && _skewb[1] == _skewb[2] && _skewb[2] == _skewb[3] && _skewb[3] == _skewb[4]
        && _skewb[5] == _skewb[6] && _skewb[6] == _skewb[7] && _skewb[7] == _skewb[8] && _skewb[8] == _skewb[9]
        && _skewb[10] == _skewb[11] && _skewb[11] == _skewb[12] && _skewb[12] == _skewb[13] && _skewb[13] == _skewb[14]
        && _skewb[15] == _skewb[16] && _skewb[16] == _skewb[17] && _skewb[17] == _skewb[18] && _skewb[18] == _skewb[19]
        && _skewb[20] == _skewb[21] && _skewb[21] == _skewb[22] && _skewb[22] == _skewb[23] && _skewb[23] == _skewb[24];
}

void Skewb::performSequence(const sequence& moves)
{
    for (size_t i = 0; i < MAX_SEQUENCE && moves[i] != 0; i++)
    {
        makeMove(moves[i]);
    }
}

void Skewb::performSequence(const scramble& moves)
{
    for (size_t i = 0; i < moves.size(); i++)
    {
        makeMove(moves[i]);
    }
}

void Skewb::makeMove(const uint8_t move)
{
    switch (move)
    {
    case 1:
        R();
        break;

    case 2:
        RPrime();
        break;

    case 3:
        L();
        break;

    case 4:
        LPrime();
        break;

    case 5:
        U();
        break;

    case 6:
        UPrime();
        break;

    case 7:
        B();
        break;

    case 8:
        BPrime();
        break;

    default:
        break;
    }
}

void Skewb::R()
{
    uint8_t tempColor;

    tempColor = _skewb[15];
    _skewb[15] = _skewb[25];
    _skewb[25] = _skewb[20];
    _skewb[20] = tempColor;
    
    tempColor = _skewb[18];
    _skewb[18] = _skewb[28];
    _skewb[28] = _skewb[24];
    _skewb[24] = tempColor;

    tempColor = _skewb[2];
    _skewb[2] = _skewb[13];
    _skewb[13] = _skewb[9];
    _skewb[9] = tempColor;

    tempColor = _skewb[17];
    _skewb[17] = _skewb[27];
    _skewb[27] = _skewb[23];
    _skewb[23] = tempColor;

    tempColor = _skewb[21];
    _skewb[21] = _skewb[19];
    _skewb[19] = _skewb[29];
    _skewb[29] = tempColor;
}

void Skewb::RPrime()
{
    uint8_t tempColor;

    tempColor = _skewb[20];
    _skewb[20] = _skewb[25];
    _skewb[25] = _skewb[15];
    _skewb[15] = tempColor;

    tempColor = _skewb[24];
    _skewb[24] = _skewb[28];
    _skewb[28] = _skewb[18];
    _skewb[18] = tempColor;

    tempColor = _skewb[9];
    _skewb[9] = _skewb[13];
    _skewb[13] = _skewb[2];
    _skewb[2] = tempColor;

    tempColor = _skewb[23];
    _skewb[23] = _skewb[27];
    _skewb[27] = _skewb[17];
    _skewb[17] = tempColor;

    tempColor = _skewb[29];
    _skewb[29] = _skewb[19];
    _skewb[19] = _skewb[21];
    _skewb[21] = tempColor;
}

void Skewb::L()
{
    uint8_t tempColor;

    tempColor = _skewb[10];
    _skewb[10] = _skewb[5];
    _skewb[5] = _skewb[25];
    _skewb[25] = tempColor;

    tempColor = _skewb[14];
    _skewb[14] = _skewb[8];
    _skewb[8] = _skewb[26];
    _skewb[26] = tempColor;

    tempColor = _skewb[4];
    _skewb[4] = _skewb[23];
    _skewb[23] = _skewb[19];
    _skewb[19] = tempColor;

    tempColor = _skewb[11];
    _skewb[11] = _skewb[9];
    _skewb[9] = _skewb[27];
    _skewb[27] = tempColor;

    tempColor = _skewb[7];
    _skewb[7] = _skewb[29];
    _skewb[29] = _skewb[13];
    _skewb[13] = tempColor;
}

void Skewb::LPrime()
{
    uint8_t tempColor;

    tempColor = _skewb[10];
    _skewb[10] = _skewb[25];
    _skewb[25] = _skewb[5];
    _skewb[5] = tempColor;

    tempColor = _skewb[14];
    _skewb[14] = _skewb[26];
    _skewb[26] = _skewb[8];
    _skewb[8] = tempColor;

    tempColor = _skewb[4];
    _skewb[4] = _skewb[19];
    _skewb[19] = _skewb[23];
    _skewb[23] = tempColor;

    tempColor = _skewb[11];
    _skewb[11] = _skewb[27];
    _skewb[27] = _skewb[9];
    _skewb[9] = tempColor;

    tempColor = _skewb[7];
    _skewb[7] = _skewb[13];
    _skewb[13] = _skewb[29];
    _skewb[29] = tempColor;
}

void Skewb::U()
{
    uint8_t tempColor;

    tempColor = _skewb[0];
    _skewb[0] = _skewb[20];
    _skewb[20] = _skewb[5];
    _skewb[5] = tempColor;

    tempColor = _skewb[1];
    _skewb[1] = _skewb[22];
    _skewb[22] = _skewb[6];
    _skewb[6] = tempColor;

    tempColor = _skewb[2];
    _skewb[2] = _skewb[23];
    _skewb[23] = _skewb[7];
    _skewb[7] = tempColor;

    tempColor = _skewb[17];
    _skewb[17] = _skewb[29];
    _skewb[29] = _skewb[11];
    _skewb[11] = tempColor;

    tempColor = _skewb[21];
    _skewb[21] = _skewb[9];
    _skewb[9] = _skewb[4];
    _skewb[4] = tempColor;
}

void Skewb::UPrime()
{
    uint8_t tempColor;

    tempColor = _skewb[0];
    _skewb[0] = _skewb[5];
    _skewb[5] = _skewb[20];
    _skewb[20] = tempColor;

    tempColor = _skewb[1];
    _skewb[1] = _skewb[6];
    _skewb[6] = _skewb[22];
    _skewb[22] = tempColor;

    tempColor = _skewb[2];
    _skewb[2] = _skewb[7];
    _skewb[7] = _skewb[23];
    _skewb[23] = tempColor;

    tempColor = _skewb[17];
    _skewb[17] = _skewb[11];
    _skewb[11] = _skewb[29];
    _skewb[29] = tempColor;

    tempColor = _skewb[21];
    _skewb[21] = _skewb[4];
    _skewb[4] = _skewb[9];
    _skewb[9] = tempColor;
}

void Skewb::B()
{
    uint8_t tempColor;

    tempColor = _skewb[5];
    _skewb[5] = _skewb[20];
    _skewb[20] = _skewb[25];
    _skewb[25] = tempColor;

    tempColor = _skewb[23];
    _skewb[23] = _skewb[29];
    _skewb[29] = _skewb[9];
    _skewb[9] = tempColor;

    tempColor = _skewb[1];
    _skewb[1] = _skewb[18];
    _skewb[18] = _skewb[14];
    _skewb[14] = tempColor;

    tempColor = _skewb[22];
    _skewb[22] = _skewb[28];
    _skewb[28] = _skewb[8];
    _skewb[8] = tempColor;

    tempColor = _skewb[6];
    _skewb[6] = _skewb[24];
    _skewb[24] = _skewb[26];
    _skewb[26] = tempColor;
}

void Skewb::BPrime()
{
    uint8_t tempColor;

    tempColor = _skewb[5];
    _skewb[5] = _skewb[25];
    _skewb[25] = _skewb[20];
    _skewb[20] = tempColor;

    tempColor = _skewb[23];
    _skewb[23] = _skewb[9];
    _skewb[9] = _skewb[29];
    _skewb[29] = tempColor;

    tempColor = _skewb[1];
    _skewb[1] = _skewb[14];
    _skewb[14] = _skewb[18];
    _skewb[18] = tempColor;

    tempColor = _skewb[22];
    _skewb[22] = _skewb[8];
    _skewb[8] = _skewb[28];
    _skewb[28] = tempColor;

    tempColor = _skewb[6];
    _skewb[6] = _skewb[26];
    _skewb[26] = _skewb[24];
    _skewb[24] = tempColor;
}