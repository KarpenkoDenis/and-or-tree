#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <QObject>
#include <QVector>
#include "tree.h"

class StateManager : public QObject
{
    Q_OBJECT

private:
    QVector<Tree> trees;

public:
    explicit StateManager(QObject *parent = nullptr);
    QVector<Tree> getTrees() const;
//    void addTree(Tree);

signals:

public slots:
    void addTree(const QString &name);
};

#endif // STATEMANAGER_H
