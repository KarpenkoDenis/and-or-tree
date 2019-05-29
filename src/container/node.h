#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <QString>
#include <vector>

enum  Type {And, Or};

inline QString getFriendlyName(Type type)
{
    return (type == Type::And) ? "And" : "Or";
}

class Node
{
    Type type;
    QString name;
    qint32 id;

public:
    Node();
    Node(QString name, Type type);
    std::vector<Node> children;

    void addNode( int parentID, QString name, Type type);
    void addNode( QString parentName, QString name, Type type);
    void addNode(QString name, Type type);
    void deleteNode(int id);
    int size();

    bool findChildByName(const QString &name) const;

    //    Node * find(QString name);
    Node * findKLP_last();
    Node * findKLP_next();

    bool operator==(const Node& ) const;
    bool operator<(const Node& ) const;

    QString getName() const;
    void setName(const QString &value);


    qint32 getId() const;
    void setId(qint32 value);

    friend QDataStream& operator<<(QDataStream& os, const Node& node);
    friend QDataStream& operator>>(QDataStream& is, Node& node);

    Type getType() const;
    void setType(const Type &value);

private:
    bool addNodeRec(int parentID, QString name, Type type);
    bool addNodeRec(QString parentName, QString name, Type t);
    bool deleteNodeRec(int id);
};

#endif // NODE_H
