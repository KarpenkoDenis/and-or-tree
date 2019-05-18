#include "statemanager.h"
#include <QDebug>

QVector<Tree> StateManager::getTrees() const
{
    return trees;
}

void StateManager::addTree(const QString &name)
{
    Tree tree;
    tree.setName(name);
    trees.append(tree);
    qDebug() << "123";
}

StateManager::StateManager(QObject *parent) : QObject(parent)
{
//    trees.append(Tree());
}
