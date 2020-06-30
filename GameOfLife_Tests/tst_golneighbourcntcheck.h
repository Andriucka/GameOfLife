#ifndef TST_GOLNEIGHBOURCNTCHECK_H
#define TST_GOLNEIGHBOURCNTCHECK_H

#include <gtest/gtest.h>
#include <gameoflife.h>

class GameOfLifeTest : public ::testing::Test
{
protected:
    GameOfLife test_neighbours;
    GameOfLife test_neighbours2;
    Cell test_cell [10][10];
};

#endif // TST_GOLNEIGHBOURCNTCHECK_H
