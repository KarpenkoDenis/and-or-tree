#include "statemanager.h"
#include <QDebug>
#include <QFile>
#include <QDataStream>


StateManager::StateManager(QObject *parent) : QObject(parent)
{
    //
    Tree tr1;
    tr1.setName("Bmw");
    tr1.root.addNode("Колёса", Or);
    tr1.root.addNode("Фары", Or);
    tr1.root.addNode("Окна", Or);
    for(auto child : tr1.root.children)
    {
        if(child.getName() == "Фары")
        {
            child.addNode("Фары1", And);
            child.addNode("Фары2", And);
            child.addNode("Фары3", And);
            child.addNode("Фары4", And);
        }
        if(child.getName() == "Фары")
        {
            child.addNode("Фары1", And);
            child.addNode("Фары2", And);
            child.addNode("Фары3", And);
            child.addNode("Фары4", And);
        }
        if(child.getName() == "Окна")
        {
            child.addNode("Окна1", And);
            child.addNode("Окна2", And);
            child.addNode("Окна3", And);
            child.addNode("Окна4", And);
        }
    }
    Tree tr2;
    tr2.setName("Ваз");
    Tree tr3;
    tr3.setName("Копейка");
    trees.append(tr1);
    trees.append(tr2);
    trees.append(tr3);
    //

}

StateManager::~StateManager()
{


    // Serialization
//    QFile file("data.trees");
//    file.open(QIODevice::WriteOnly);
//    QDataStream out(&file);
//    out << (qint32)trees.count();
//    for(const Tree& tree : trees)
//    {
//        out << tree;
//    }
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
