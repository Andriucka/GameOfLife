#include "gamemodel.h"


GameModel::GameModel(QObject *parent) : QAbstractTableModel(parent)
{

}


int GameModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return HEIGHT;
}

int GameModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return LENGTH;
}

QVariant GameModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != CellRole)
        return QVariant();

    return QVariant(model.theCells[index.column()][index.row()].alive);
}

bool GameModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) == value)
            return false;

        model.theCells[index.column()][index.row()].alive = value.toBool();
        emit dataChanged(index, index, {role});

        return true;
}


void GameModel::iterate()
{
    model.nextStep();
    emit dataChanged(index(0, 0), index(HEIGHT - 1, LENGTH - 1), {CellRole});
}
