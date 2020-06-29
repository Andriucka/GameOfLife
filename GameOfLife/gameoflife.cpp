#include "gameoflife.h"
#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <omp.h>
#include <ctime>

using namespace std;

uint8_t GameOfLife::neighbour_cnt(int x, int y) {

    uint8_t count = 0;
#pragma omp parallel for
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
        {
            int tempX = (((x + i) >= 0) && ((x + i) < HEIGHT)) ? (x + i) : -1;
            int tempY = (((y + j) >= 0) && ((y + j) < LENGTH)) ? (y + j) : -1;
            if (tempX < 0 || tempY < 0 || (tempX == x && tempY == y))
                continue;
            else{
                if (theCells[tempX][tempY].alive)
                    count++;
            }
        }
    return count;
}

void GameOfLife::nextStep()
{
#pragma omp parallel for
    for(int i = 0; i< HEIGHT; i++)
        for (int j = 0; j < LENGTH; j++)
        {
            int temp = neighbour_cnt(i, j);
            if ((temp == 2 || temp == 3) && (theCells[i][j].alive == true))
                nextCells[i][j].alive = true;
            else if ((temp == 3) && (theCells[i][j].alive == false))
                nextCells[i][j].alive = true;
            else
                nextCells[i][j].alive = false;
        }
#pragma omp parallel for
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < LENGTH; j++)
            theCells[i][j] = nextCells[i][j];


}

void GameOfLife::drawGlider(int startX, int startY)
{
    theCells[startX + 0][startY + 1].alive = true;
    theCells[startX + 1][startY + 2].alive = true;
    theCells[startX + 2][startY + 0].alive = true;
    theCells[startX + 2][startY + 1].alive = true;
    theCells[startX + 2][startY + 2].alive = true;
}



