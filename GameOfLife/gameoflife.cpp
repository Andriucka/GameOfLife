#include <gameoflife.h>
#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <omp.h>
//#include <ctime>

using namespace std;

uint8_t GameOfLife::neighCount(int x, int y)
{

    uint8_t count = 0;
#pragma omp parallel for
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int tempX = checkBoundaries(i, x);
            int tempY = checkBoundaries(j, y);

            if (tempX == x && tempY == y)
            {
                continue;
            }
            else if (theCells[tempX][tempY].getState())
            {
                count++;
            }
        }
    }
    return count;
}

bool GameOfLife::getState(int x, int y) const
{
    return theCells[x][y].getState();
}

void GameOfLife::setAlive(int x, int y)
{
    theCells[x][y].setAlive();
}

void GameOfLife::setDead(int x, int y)
{
    theCells[x][y].setDead();
}

int GameOfLife::checkBoundaries(int iterationNum, int coord)
{
    if (((coord + iterationNum) < 0))
        return LENGTH - 1;
    else if ((coord + iterationNum) >= LENGTH)
        return 0;
    else
        return coord + iterationNum;
}

bool GameOfLife::checkRuleTwo(uint8_t neighCount, int x, int y)
{
    if ((neighCount == 2 || neighCount == 3) && (theCells[x][y].getState() == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GameOfLife::checkRuleFour(uint8_t neighCount, int x, int y)
{
    if ((neighCount == 3) && (theCells[x][y].getState() == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GameOfLife::nextStep()
{
#pragma omp parallel for
    for(int i = 0; i< HEIGHT; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            int temp = neighCount(i, j);
            /*We only need to check two rules to determine whether the cell has to survive or not */
            if (checkRuleTwo(temp, i, j))
                nextCells[i][j].setAlive();
            else if (checkRuleFour(temp, i, j))
                nextCells[i][j].setAlive();
            else
                nextCells[i][j].setDead();
        }
    }
#pragma omp parallel for
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            theCells[i][j] = nextCells[i][j];
        }
    }
}

void GameOfLife::drawGlider(int startX, int startY)
{
    theCells[startX + 0][startY + 1].setAlive();
    theCells[startX + 1][startY + 2].setAlive();
    theCells[startX + 2][startY + 0].setAlive();
    theCells[startX + 2][startY + 1].setAlive();
    theCells[startX + 2][startY + 2].setAlive();
}



