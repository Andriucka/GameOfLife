#ifndef CELL_H
#define CELL_H

class Cell
{
public:
    Cell();
    bool getState() const;
    void setDead();
    void setAlive();

private:
    bool alive;
};

#endif // CELL_H
