#ifndef TST_GOLNEIGHBOURCNTCHECK_H
#define TST_GOLNEIGHBOURCNTCHECK_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "gameoflife.cpp"
#include "cell.h"

using namespace testing;

TEST(CellAliveTest, CellInitialisation) {
    Cell TestCell [10][10];

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            EXPECT_FALSE(TestCell[i][j].alive);
        }
}

TEST(GameOfLifeTest, TestNeighbourCount_T1) {
    GameOfLife TestNeighbours;
    TestNeighbours.drawGlider(0,0);
    EXPECT_EQ(1, TestNeighbours.neighbour_cnt(0, 0));
}

TEST(GameOfLifeTest, TestNeighbourCount_T2) {
    GameOfLife TestNeighbours;
    TestNeighbours.drawGlider(0,0);
    EXPECT_EQ(5, TestNeighbours.neighbour_cnt(1, 1));
}

TEST(GameOfLifeTest, TestNeighbourCount_T3) {
    GameOfLife TestNeighbours;
    TestNeighbours.drawGlider(0,0);
    EXPECT_EQ(0, TestNeighbours.neighbour_cnt(HEIGHT-1, LENGTH-1));
}

TEST(GameOfLifeTest, IterationTest) {
    int i = 0;
    GameOfLife TestNeighbours1;
    TestNeighbours1.drawGlider(0,0);
    while(i++ < 4)
        TestNeighbours1.nextStep();

    /*After 4 iterations Glider should be in exact same form moved by one (x an y) coordinate.*/
    GameOfLife TestNeighbours2;
    TestNeighbours2.drawGlider(1, 1);
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < LENGTH; j++)
            EXPECT_EQ(TestNeighbours2.theCells[i][j].alive, TestNeighbours1.theCells[i][j].alive);
}

#endif // TST_GOLNEIGHBOURCNTCHECK_H
