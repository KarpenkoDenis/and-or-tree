#include "statemanager.h"
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>

StateManager::StateManager(QObject *parent) : QObject(parent)
{

}

StateManager::~StateManager()
{
    serializeState();
    for(auto tree : trees) {
        delete tree;
    }
}

QVector<Tree<QString>*> StateManager::getTrees()
{
    return trees;
}

void StateManager::serializeState()
{
    QFile file("data.trees");
    file.open(QIODevice::WriteOnly);

    QDataStream out(&file);
    out << (qint32)trees.count();


    for(auto tree : trees)
    {
        out << *tree;
    }
}

void StateManager::deserializeState()
{
    QFile file("data.trees");
    file.open(QIODevice::ReadOnly);

    if(file.isOpen())
    {
        QDataStream in(&file);
        qint32 treeCount;
        in >> treeCount;
        for(int i = 0; i < treeCount; i++)
        {
            Tree<QString>* tree = new Tree<QString>();
            in >> *tree;
            trees.append(tree);
            qDebug() << "Tree with name '" + tree->getName() + "' was restored.";
            emit treeCreated();
        }
    }
}

void StateManager::createTree(const QString &name)
{
    Tree<QString>* tree = new Tree<QString>();
    tree->setName(name);
    trees.append(tree);
    qDebug() << "Tree with name '" + name + "' was created.";

    emit treeCreated();
}

void StateManager::removeTree(Tree<QString> *tree)
{
    trees.removeAt(trees.indexOf(tree));
    emit treeRemoved();
}
