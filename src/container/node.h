#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <QString>
#include <vector>

enum  Type {And, Or};


class Node
{
    Type type;
    QString name;
    int id;

public:
    Node();
    Node(QString name, Type type);
    std::vector<Node> children;

    void addNode( int parentID, QString name, Type type);
    void addNode(QString name, Type type);
    void deleteNode(int id);
    int size();
    //    Node * find(QString name);
    Node * findKLP_last();
    Node * findKLP_next();

    bool operator==(const Node& ) const;
    bool operator<(const Node& ) const;

    QString getName() const;
    void setName(const QString &value);

    int getId() const;
    void setId(int value);
};

#endif // NODE_H
