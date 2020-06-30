#include "tst_golneighbourcntcheck.h"

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <gameoflife.h>
#include <cell.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

using namespace testing;

TEST_F(GameOfLifeTest, CellInitialisation)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            EXPECT_FALSE(test_cell[i][j].getState());
        }
}

TEST_F(GameOfLifeTest, NeighbourCountTest1) {
    GameOfLife test_neighbours;
    test_neighbours.drawGlider(0,0);
    EXPECT_EQ(1, test_neighbours.neighCount(0, 0));
}

TEST_F(GameOfLifeTest, NeighbourCountTest2) {
    test_neighbours.drawGlider(0,0);
    EXPECT_EQ(5, test_neighbours.neighCount(1, 1));
}

TEST_F(GameOfLifeTest, NeighbourCountTest3) {
    test_neighbours.drawGlider(0,0);
    EXPECT_EQ(0, test_neighbours.neighCount(HEIGHT-1, LENGTH-1));
}

TEST_F(GameOfLifeTest, IterationTest) {
    int i = 0;
    test_neighbours.drawGlider(0,0);
    while(i++ < 4)
        test_neighbours.nextStep();

    /*After 4 iterations Glider should be in exact same form moved by one (x an y) coordinate.*/
    test_neighbours2.drawGlider(1, 1);
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < LENGTH; j++)
        {
            EXPECT_EQ(test_neighbours2.getState(i, j), test_neighbours.getState(i, j)) << "Iteration fail when x = " << i << "and y = " << j << std::endl;;
        }
}

