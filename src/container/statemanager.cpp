#include "statemanager.h"
#include <QDebug>
#include <QFile>
#include <QDataStream>


StateManager::StateManager(QObject *parent) : QObject(parent)
{
}

StateManager::~StateManager()
{
    // Serialization
    QFile file("data.trees");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << (qint32)trees.count();
    for(const Tree& tree : trees)
    {
        out << tree;
    }
}

QVector<Tree> StateManager::getTrees() const
{
    return trees;
}
void StateManager::restoreTrees()
{
    // Deserialization
    QFile file("data.trees");
    file.open(QIODevice::ReadOnly);
    if(file.isOpen())
    {
        QDataStream in(&file);
        qint32 treeCount;
        in >> treeCount;
        for(int i = 0; i < treeCount; i++)
        {
            Tree tree;
            in >> tree;
            trees.append(tree);
            qDebug() << "Tree with name '" + tree.getName() + "' was restored.";
            emit treeCreated(tree);
        }
    }
}

void StateManager::createTree(const QString &name)
{
    Tree tree;
    tree.setName(name);
    trees.append(tree);
    qDebug() << "Tree with name '" + name + "' was created.";

    emit treeCreated(tree);
}
