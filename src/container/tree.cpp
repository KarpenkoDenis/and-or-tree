#include "tree.h"

Tree::Tree()
{
    this->root.setName("Корневой узел");
}

Node Tree::getRoot() const
{
    return root;
}

QString Tree::getName() const
{
    return name;
}

void Tree::setName(const QString &value)
{
    name = value;
}

void Tree::addNode(int parentID, QString name, Type type)
{
    root.addNode(parentID, name, type);
}

void Tree::deleteNode(int id)
{
    if(id == root.getId())
        this->clear();
    root.deleteNode(id);
}

void Tree::clear()
{
    root = Node();
}

int Tree::size()
{
    return root.size();
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
    return TreeIterator(this, &root);
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
