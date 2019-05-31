#include "statemanager.h"
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>

StateManager::StateManager(QObject *parent) : QObject(parent)
{

    try
    {
        //
        Tree tr1;
        tr1.setName("Bmw");
        tr1.root.addNode("Колёса", Or);
        tr1.root.addNode("Фары", Or);
        tr1.root.addNode("Окна", Or);
        tr1.root.addNode("Фары", "Фары1", And);
        tr1.root.addNode("Фары", "Фары2", And);
        tr1.root.addNode("Фары", "Фары3", And);
        tr1.root.addNode("Фары", "Фары4", And);

        tr1.root.addNode("Окна", "Окна1", And);
        tr1.root.addNode("Окна", "Окна2", And);
        tr1.root.addNode("Окна", "Окна3", And);
        tr1.root.addNode("Окна", "Окна4", And);
        tr1.root.addNode("Колёса", "Колёса1", And);
        tr1.root.addNode("Колёса", "Колёса2", And);
        tr1.root.addNode("Колёса", "Колёса3", And);
        tr1.root.addNode("Колёса", "Колёса4", And);
        Tree tr2;
        tr2.setName("Ваз");
        Tree tr3;
        tr3.setName("Копейка");
        trees.append(tr1);
        trees.append(tr2);
        trees.append(tr3);

    }
    catch(TreeException& e)
    {
        QMessageBox::critical(nullptr, "Error", e.what(), QMessageBox::Ok);
    }
}

StateManager::~StateManager()
{
    serializeState();
    for(auto tree : trees) {
        delete tree;
    }
}

QVector<Tree*> StateManager::getTrees()
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
        out << tree;
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
            Tree* tree = new Tree();
            in >> *tree;
            trees.append(tree);
            qDebug() << "Tree with name '" + tree->getName() + "' was restored.";
            emit treeCreated();
        }
    }
}

void StateManager::createTree(const QString &name)
{
    Tree* tree = new Tree();
    tree->setName(name);
    trees.append(tree);
    qDebug() << "Tree with name '" + name + "' was created.";

    emit treeCreated();
}

void StateManager::removeTree(Tree *tree)
{
    trees.removeAt(trees.indexOf(tree));
    emit treeRemoved();
}
