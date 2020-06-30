#include <cell.h>

Cell::Cell()
{
    alive = false;
}

bool Cell::getState() const
{
    return alive;
}

void Cell::setDead()
{
    alive = false;
}

void Cell::setAlive()
{
    alive = true;
}
