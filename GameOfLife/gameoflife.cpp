#include "gameoflife.h"
#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <omp.h>
//#include <ctime>

using namespace std;

uint8_t GameOfLife::neighCnt(int x, int y)
{

    uint8_t count = 0;
#pragma omp parallel for
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int tempX;
            int tempY;
            if (((x + i) < 0))
                tempX = LENGTH - 1;
            else if ((x + i) >= LENGTH)
                tempX = 0;
            else
                tempX = x + i;

            if (((y + j) < 0))
                tempY = HEIGHT - 1;
            else if ((y + j) >= HEIGHT)
                tempY = 0;
            else
                tempY = y + j;

            if (tempX < 0 || tempY < 0 || (tempX == x && tempY == y))
                continue;
            else{
                if (theCells[tempX][tempY].getState())
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

void GameOfLife::nextStep()
{
#pragma omp parallel for
    for(int i = 0; i< HEIGHT; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            int temp = neighCnt(i, j);
            if ((temp == 2 || temp == 3) && (theCells[i][j].getState() == true))
                nextCells[i][j].setAlive();
            else if ((temp == 3) && (theCells[i][j].getState() == false))
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



