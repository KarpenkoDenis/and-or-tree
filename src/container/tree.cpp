#include "tree.h"
#include <QMessageBox>

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
try
{
    root.addNode(parentID, name, type);
}
catch(CantFindValidParentException e)
{
    QMessageBox::critical(nullptr, "Error", e.what(), QMessageBox::Ok);
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

qint32 Tree::size()
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

QDataStream& operator<<(QDataStream& os, const Tree& tree)
{
    os << tree.name;
    os << tree.root;
    return os;
}

QDataStream& operator>>(QDataStream& is, Tree& tree)
{
    is >> tree.name;
    is >> tree.root;
    return is;
}
