#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <cstdint>
#include <array>
#include "cell.h"

template <class T, size_t ROW, size_t COL >
using Matrix = std::array<std::array<T, COL>, ROW>;

const auto HEIGHT = 100;
const auto LENGTH = 100;

class GameOfLife
{
public:
    GameOfLife() = default;
    void nextStep();
    void drawGlider(int startX, int startY);
    uint8_t neighCnt(int x, int y);
    bool getState(int x, int y) const;
    void setAlive(int x, int y);
    void setDead(int x, int y);

private:
    Matrix<Cell,HEIGHT,LENGTH> theCells;
    Matrix<Cell, HEIGHT, LENGTH> nextCells;
};

#endif // GAMEOFLIFE_H
