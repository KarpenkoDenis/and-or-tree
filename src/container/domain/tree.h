#ifndef TREE_H
#define TREE_H

#include <QObject>
#include "node.h"
#include "memory"
#include "container/exception/treeexception.h"

class TreeIterator;

#include "container/treeiterator.h"

class Tree
{
public:
    Tree();
    Node root;
    QString name;

    void addNode( int parentID, QString name, Type t);
    void deleteNode( int id);
    void clear();
    int size();
//    Node *find(QString name);
    Node * findKLP_next_by(Node *);

    //for iterator
public:
    typedef TreeIterator iterator;
//    typedef TreeIterator<const Tree> const_iterator;

//    Tree(std::initializer_list<int> values);

    iterator begin();
    iterator end();

//    const_iterator begin() const;
//    const_iterator end() const;
//private:
//    const size_t size;
//    std::unique_ptr<int[]> data;
//    std::unique_ptr<int[]> data;

    void setName(const QString &value);

    QString getName() const;
    Node getRoot() const;

    friend QDataStream& operator<<(QDataStream& os, const Tree& tree);
    friend QDataStream& operator>>(QDataStream& is, Tree& tree);
};

#endif // TREE_H
