#include <gamemodel.h>

GameModel::GameModel(QObject *parent) : QAbstractTableModel(parent)
{

}

QHash<int, QByteArray> GameModel::roleNames() const
{
    return
    {
        { CellRole, "value" }
    };
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

    return QVariant(model.getState(index.row(), index.column()));
}

bool GameModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) == value)
        return false;

    if(value.toBool())
    {
        model.setAlive(index.row(), index.column());
    }
    else
    {
        model.setDead(index.row(), index.column());
    }

    emit dataChanged(index, index, {role});

    return true;
}


void GameModel::iterate()
{
    model.nextStep();
    emit dataChanged(index(0, 0), index(HEIGHT - 1, LENGTH - 1), {CellRole});
}

void GameModel::drawGlider()
{
    model.drawGlider(HEIGHT/2, LENGTH/2);
    emit dataChanged(index(0, 0), index(HEIGHT - 1, LENGTH - 1), {CellRole});
}

void GameModel::drawRandom()
{
    model.drawRandom();
    emit dataChanged(index(0, 0), index(HEIGHT - 1, LENGTH - 1), {CellRole});
}
