#include "tree.h"

Tree::Tree()
{

}

void Tree::setName(const QString &value)
{
    name = value;
}

void Tree::addNode(int parentID, QString name, type t)
{
    parent.addNode(parentID, name, t);

}

void Tree::deleteNode(int id)
{
    if(id == parent.id)
        this->clear();
    parent.deleteNode(id);
}

void Tree::clear()
{
    parent = Node();

}

int Tree::size()
{
    return parent.size();

}

Node *Tree::findKLP_next_by(Node * el)
{

}

//Node *Tree::find(QString name)
//{
//    parent.find(name);

//}


//Tree::Tree(std::initializer_list<int> values)/* :
//    size(values.size()),
//    data(new int[size])*/
//{
//    std::copy(values.begin(), values.end(), data.get());
//}

Tree::iterator Tree::begin()
{
    return TreeIterator(this, &parent);
//    return iterator(data.get());
}

Tree::iterator Tree::end()
{
    return iterator(nullptr, nullptr);
}

//Tree::const_iterator Tree::begin() const
//{
//    return const_iterator(data.get());
//}

//Tree::const_iterator Tree::end() const
//{
//    return const_iterator(data.get() + size);
//}
