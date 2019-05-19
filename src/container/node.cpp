#include "node.h"

Node::Node()
{

}

Node::Node(QString name, type t)
{
    this->name =name;
    this->t=t;


}

void Node::addNode(int parentID, QString name, type t)
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

int Node::size()
{
    int count = 0;
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
