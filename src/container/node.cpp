#include "node.h"
#include <QDebug>
#include <QDataStream>

qint32 Node::getId() const
{
    return id;
}

void Node::setId(qint32 value)
{
    id = value;
}

Node::Node()
{
    
}

Node::Node(QString name, Type type)
{
    this->name = name;
    this->type = type;


}


void Node::setName(const QString &value)
{
    name = value;
}

QString Node::getName() const
{
    return name;
}

void Node::addNode(int parentID, QString name, Type t)
{
    if(this->id == parentID)
    {
        children.push_back(Node(name, t));
    }else
    {
        foreach (Node child, this->children)
        {
            child.addNode(parentID, name, t);
        }

    }
}

void Node::addNode(QString name, Type t)
{
    children.push_back(Node(name, t));
}

void Node::deleteNode(int id)
{
    for (auto child = this->children.begin(); child != this->children.end();)
    {
        if(child->id == id)
        {
            children.clear();
            this->children.erase(child);
            return;
        }
        else {
            child->deleteNode(id);
        }

    }
}

qint32 Node::size()
{
    qint32 count = 0;
    for(Node child : children) {
        count = child.size();
    }
    return 1 + count;
}

//const Node * Node::find(QString name)
//{
////    if(name == this->name)
////    {
////        return this;
////    }
////    foreach (Node child, this->children)
////    {
////        auto res = child.find(name);
////        if(res != nullptr)
////            return res;
////    }
////    return nullptr;

//}

Node * Node::findKLP_last()
{
    for(auto child: children)
    {
        if( child == *(children.end()) )
        {
            return child.findKLP_last();
        }
    }
    return this;
}

Node * Node::findKLP_next()
{
    if(children.size() > 0)
        return &(children.at(0));
    return nullptr;
}

bool Node::operator==(const Node &right) const
{
    return (this->name == right.name);
}

bool Node::operator<(const Node &right) const
{
    return (this->name < right.name);
}

QDataStream& operator<<(QDataStream& os, const Node& node)
{
    qDebug() << "store Node" << node.id
             << node.name
             << static_cast<qint32>(node.type)
             << node.children.size();
    os << node.id
       << node.name
       << static_cast<qint32>(node.type)
       << node.children.size();
    for(auto child : node.children)
    {
        os << child;
    }
    return os;
}

QDataStream& operator>>(QDataStream& is, Node& node)
{
    qint32 type;
    size_t childrenCount;
    is >> node.id
       >> node.name
       >> type
       >> childrenCount;
    for(int i = 0; i < childrenCount; i++)
    {
        Node child;
        is >> child;
        node.children.push_back(child);
    }
    node.type = static_cast<Type>(type);
    qDebug() << "restore Node" << node.id
             << node.name
             << static_cast<qint32>(node.type)
             << node.children.size();
    return is;
}