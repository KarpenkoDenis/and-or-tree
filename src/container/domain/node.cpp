#include "node.h"
#include "container/exception/treeexception.h"
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

bool Node::findChildByName(const QString &name) const
{
    for(auto child: children)
    {
        if(child.getName() == name)
            return true;
    }
    return false;
}

Type Node::getType() const
{
    return type;
}

void Node::setType(const Type &value)
{
    type = value;
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
    if(!addNodeRec(parentID, name, t))
    {
        throw CantFindValidParentException(this, parentID, name, t);
    }
}

void Node::addNode(QString parentName, QString name, Type type)
{
    if(!addNodeRec(parentName, name, type))
    {
        throw CantFindValidParentException(this, parentName, name, type);
    }
}
bool Node::addNodeRec(int parentID, QString name, Type t)
{
    if(this->id == parentID)
    {
        children.push_back(Node(name, t));
        return true;
    }else
    {
        for(auto iter = this->children.begin(); iter!=this->children.end(); ++iter)
        {
            if((*iter).addNodeRec(parentID, name, t))
            {
                return true;
            }
        }
    }
    return false;
}
bool Node::addNodeRec(QString parentName, QString name, Type t)
{
    if(this->name == parentName)
    {
        children.push_back(Node(name, t));
        return true;
    }else
    {
        for(auto iter = this->children.begin(); iter!=this->children.end(); ++iter)
        {
            if((*iter).addNodeRec(parentName, name, t))
            {
                return true;
            }
        }
    }
    return false;
}

void Node::addNode(QString name, Type t)
{
    children.push_back(Node(name, t));
}

void Node::deleteNode(int id)
{
    if(!deleteNodeRec(id))
    {
        throw CantFindNodeToDeleteException(this, id);
    }
}

bool Node::deleteNodeRec(int id)
{
    for (auto child = this->children.begin(); child != this->children.end(); child++)
    {
        if(child->id == id)
        {
            this->children.erase(child);
            return true;
        }
        else {
            if(child->deleteNodeRec(id))
            {
                return true;
            }
        }
    }
    return false;
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
    if(!this)
        return false;
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
             << getFriendlyName(node.type)
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
    for(unsigned int i = 0; i < childrenCount; i++)
    {
        Node child;
        is >> child;
        node.children.push_back(child);
    }
    node.type = static_cast<Type>(type);
    qDebug() << "restore Node" << node.id
             << node.name
             << getFriendlyName(node.type)
             << node.children.size();
    return is;
}
