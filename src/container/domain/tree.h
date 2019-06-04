#ifndef TREE_H
#define TREE_H

#include <QObject>
#include "node.h"
#include "memory"
//#include "container/exception/treeexception.h"

template <class T>
class TreeIterator;


template<class T>
class Tree
{
public:
//    Tree();
    Node<QString> root;
    QString name;

//    void addNode( int parentID, QString name, Type t);
//    void deleteNode( int id);
//    void clear();
//    int size();
//    Node *find(QString name);
//    Node<QString> * findKLP_next_by(Node<QString> *);

    //for iterator
public:
    typedef TreeIterator<T> iterator;

//    iterator begin();
//    iterator end();


//    void setName(const QString &value);

//    QString getName() const;
//    Node<QString> getRoot() const;


    friend QDataStream& operator<<(QDataStream& os, const Tree<QString>& tree)
    {
        os << tree.name;
        os << tree.root;
        return os;
    }


    friend QDataStream& operator>>(QDataStream& is, Tree<QString>& tree)
    {
        is >> tree.name;
        is >> tree.root;
        return is;
    }


//    friend QDataStream& operator<<(QDataStream& os, const Tree<QString>& tree);
//    friend QDataStream& operator>>(QDataStream& is, Tree<QString>& tree);


    public:
Tree()
{
    this->root.setName("Авто");
    this->root.setType(And);
}

Node<QString> getRoot() const
{
    return root;
}

QString getName() const
{
    return name;
}

void setName(const QString &value)
{
    name = value;
}

void addNode(int parentID, QString name, Type type)
{
    root.addNode(parentID, name, type);
}

void deleteNode(int id)
{
    if(id == root.getId())
        this->clear();
    root.deleteNode(id);
    //Переместить к использованию Tree::deleteNode, т.к. здесь ловить исключение не надо
//    try
//    {
//    }
//    catch(TreeException& e)
//    {
//        QMessageBox::critical(nullptr, "Error", e.what(), QMessageBox::Ok);
//    }
}

void clear()
{
    root = Node<QString>();
}

qint32 size()
{
    return root.size();
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

iterator begin()
{
    return TreeIterator<T>(this, &root);
//    return iterator(data.get());
}

iterator end()
{
    Node<QString> * last = &this->root;
    while(last->children.size())
    {
        auto save = last->children.end();
        save--;
        last = &*(save);
    }
    return iterator(this, last);
}

};


//QDataStream& operator<<(QDataStream& os, const Tree<QString>& tree)
//{
//    os << tree.name;
//    os << tree.root;
//    return os;
//}


//QDataStream& operator>>(QDataStream& is, Tree<QString>& tree)
//{
//    is >> tree.name;
//    is >> tree.root;
//    return is;
//}



template<typename T>
class TreeIterator: public std::iterator<std::input_iterator_tag, Node<QString>, Tree<QString>>
{
    friend class Tree<T>;
private:
    Tree<T>* r;  //переделать на ссылку
    Node<T>* c;

    std::vector<Node<T> *> passed;
    TreeIterator<T>(Tree<T> *r, Node<T> *c) :
        r(r), c(c)
    {

    }
public:
//    TreeIterator(const TreeIterator<T> &it);

//    bool operator!=(TreeIterator<T> const& other) const;
//    bool operator==(TreeIterator<T> const& other) const;
//    typename TreeIterator<T>::reference operator*() const;
//    TreeIterator<T>& operator++();
//private:
//    Node<T> *findNext(Node<T> *curr, Node<T> finding);
//    void KLP(Node<T> * curr);



public:


TreeIterator<T>(const TreeIterator<T>& it) :
    r(it.r), c(it.c)
{

}


bool operator!=(TreeIterator<T> const& other) const
{
    return r != other.r || c != other.c;
}


bool operator==(TreeIterator<T> const& other) const
{
    return r == other.r && c == other.c;
}


reference operator*() const
{
    return *c;
}

TreeIterator<T> &operator++()
{
    auto save = c->findKLP_next();
    if(save)
    {
        c = save;
    }
    else {
         c = findNext(&(r->root), *c);
    }

    return *this;
}
private:
Node<T> *findNext(Node<T> *curr, Node<T> finding)
{
    KLP(&r->root);
    for(auto iter = passed.begin(); iter!=passed.end(); ++iter)
    {
        if(**iter == finding)
        {
            if(*(iter+1))
                return *(iter+1);
        }
    }
    return nullptr;
}

void KLP(Node<T> *curr)
{
    passed.push_back(curr);
    for(auto iter = curr->children.begin(); iter!=curr->children.end(); ++iter)
    {
        KLP(&*iter);
    }
}


};

#endif // TREE_H
