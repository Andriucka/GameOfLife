#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QObject>
#include <qqml.h>
#include <QAbstractTableModel>
#include "gameoflife.h"

class GameModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    GameOfLife model;
    enum Roles {
        CellRole
    };

    QHash<int, QByteArray> roleNames() const override {
        return {
            { CellRole, "value" }
        };
    }
    explicit GameModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE void iterate();
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole) override;

};

#endif // GAMEMODEL_H
