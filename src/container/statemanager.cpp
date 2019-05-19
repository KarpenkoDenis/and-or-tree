#include "statemanager.h"
#include <QDebug>


StateManager::StateManager(QObject *parent) : QObject(parent)
{
    //    trees.append(Tree());
}

QVector<Tree> StateManager::getTrees() const
{
    return trees;
}

void StateManager::createTree(const QString &name)
{
    Tree tree;
    tree.setName(name);
    trees.append(tree);
    qDebug() << "Tree with name '" + name + "' was created.";

    emit treeCreated(tree);
}
