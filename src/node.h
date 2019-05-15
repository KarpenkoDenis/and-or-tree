#ifndef NODE_H
#define NODE_H

//#include <QObject>
#include <iostream>
#include <QString>
#include <vector>

enum  type {typeAnd = 1, typeOr = 2};


class Node
{

public:
    Node();
    Node(QString name, type t);
    std::vector<Node> children;
    type t;         // и/или
    QString name;
    int id;


    void addNode( int parentID, QString name, type t);
    void deleteNode(int id);
    int size();
//    Node * find(QString name);
    Node * findKLP_last();
    Node * findKLP_next();

    bool operator==(const Node& ) const;
    bool operator<(const Node& ) const;

};

#endif // NODE_H
