#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <cstdint>
#include <array>
#include "cell.h"

template <class T, size_t ROW, size_t COL >
using Matrix = std::array<std::array<T, COL>, ROW>;

constexpr auto HEIGHT = 100;
constexpr auto LENGTH = 100;

class GameOfLife
{
public:


    GameOfLife() = default;
    Matrix<Cell,HEIGHT,LENGTH> theCells;

    void nextStep();
    void drawGlider(int startX, int startY);
    uint8_t neighbour_cnt(int x, int y);


private:

    Matrix<Cell, HEIGHT, LENGTH> nextCells;
};

#endif // GAMEOFLIFE_H
