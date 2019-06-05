//#include "node.h"
//#include "container/exception/treeexception.h"
//#include <QDebug>
//#include <QDataStream>

//qint32 Node<T>::getId() const
//{
//    return id;
//}

//void Node<T>::setId(qint32 value)
//{
//    id = value;
//}

//bool Node<T>::findChildByName(const T &name) const
//{
//    for(auto child: children)
//    {
//        if(child.getName() == name)
//            return true;
//    }
//    return false;
//}

//Type Node<T>::getType() const
//{
//    return type;
//}

//void Node<T>::setType(const Type &value)
//{
//    type = value;
//}

//Node<T>::Node<T>()
//{
    
//}

//Node<T>::Node<T>(QString name, Type type)
//{
//    this->name = name;
//    this->type = type;

//}


//void Node<T>::setName(const QString &value)
//{
//    name = value;
//}

//QString Node<T>::getName() const
//{
//    return name;
//}


//void Node<T>::addNode<T>(int parentID, T name, Type t)
//{
//    if(!addNode<T>Rec(parentID, name, t))
//    {
//        throw CantFindValidParentException(this, parentID, name, t);
//    }
//}

//void Node<T>::addNode<T>(T parentName, T name, Type type)
//{
//    if(!addNode<T>Rec(parentName, name, type))
//    {
//        throw CantFindValidParentException(this, parentName, name, type);
//    }
//}
//bool Node<T>::addNode<T>Rec(int parentID, T name, Type t)
//{
//    if(this->id == parentID)
//    {
//        children.push_back(Node<T>(name, t));
//        return true;
//    }else
//    {
//        for(auto iter = this->children.begin(); iter!=this->children.end(); ++iter)
//        {
//            if((*iter).addNode<T>Rec(parentID, name, t))
//            {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//bool Node<T>::addNode<T>Rec(T parentName, T name, Type t)
//{
//    if(this->name == parentName)
//    {
//        children.push_back(Node<T>(name, t));
//        return true;
//    }else
//    {
//        for(auto iter = this->children.begin(); iter!=this->children.end(); ++iter)
//        {
//            if((*iter).addNode<T>Rec(parentName, name, t))
//            {
//                return true;
//            }
//        }
//    }
//    return false;
//}

//void Node<T>::addNode<T>(QString name, Type t)
//{
//    children.push_back(Node<T>(name, t));
//}

//void Node<T>::deleteNode<T>(int id)
//{
//    if(!deleteNode<T>Rec(id))
//    {
//        throw CantFindNode<T>ToDeleteException(this, id);
//    }
//}

//bool Node<T>::deleteNode<T>Rec(int id)
//{
//    for (auto child = this->children.begin(); child != this->children.end(); child++)
//    {
//        if(child->id == id)
//        {
//            this->children.erase(child);
//            return true;
//        }
//        else {
//            if(child->deleteNode<T>Rec(id))
//            {
//                return true;
//            }
//        }
//    }
//    return false;
//}

//qint32 Node<T>::size()
//{
//    qint32 count = 0;
//    for(Node<T> child : children) {
//        count = child.size();
//    }
//    return 1 + count;
//}

////const Node<T> * Node<T>::find(QString name)
////{
//////    if(name == this->name)
//////    {
//////        return this;
//////    }
//////    foreach (Node<T> child, this->children)
//////    {
//////        auto res = child.find(name);
//////        if(res != nullptr)
//////            return res;
//////    }
//////    return nullptr;

////}

//Node<T> * Node<T>::findKLP_last()
//{
//    for(auto child: children)
//    {
//        if( child == *(children.end()) )
//        {
//            return child.findKLP_last();
//        }
//    }
//    return this;
//}

//Node<T> * Node<T>::findKLP_next()
//{
//    if(children.size() > 0)
//        return &(children.at(0));
//    return nullptr;
//}

//bool Node<T>::operator==(const Node<T> &right) const
//{
//    if(!this)
//        return false;
//    return (this->name == right.name);
//}

//bool Node<T>::operator<(const Node<T> &right) const
//{
//    return (this->name < right.name);
//}

//QDataStream& operator<<(QDataStream& os, const Node<T>& node)
//{
//    qDebug() << "store Node<T>" << node.id
//             << node.name
//             << getFriendlyName(node.type)
//             << node.children.size();
//    os << node.id
//       << node.name
//       << static_cast<qint32>(node.type)
//       << node.children.size();
//    for(auto child : node.children)
//    {
//        os << child;
//    }
//    return os;
//}

//QDataStream& operator>>(QDataStream& is, Node<T>& node)
//{
//    qint32 type;
//    size_t childrenCount;
//    is >> node.id
//       >> node.name
//       >> type
//       >> childrenCount;
//    for(unsigned int i = 0; i < childrenCount; i++)
//    {
//        Node<T> child;
//        is >> child;
//        node.children.push_back(child);
//    }
//    node.type = static_cast<Type>(type);
//    qDebug() << "restore Node<T>" << node.id
//             << node.name
//             << getFriendlyName(node.type)
//             << node.children.size();
//    return is;
//}

