#ifndef NODE_H
#define NODE_H


#include <iostream>
#include <QString>
#include <vector>
//#include "container/exception/treeexception.h"
#include <QDebug>
#include <QDataStream>



enum  Type {And, Or};

inline QString getFriendlyName(Type type)
{
    return (type == Type::And) ? "And" : "Or";
}


template<class T>
class Node
{
//    typedef T value_type;
    Type type;
    T name;
    qint32 id;

private:
    bool addNodeRec(T parentName, T name, Type t)
    {
        if(this->name == parentName)
        {
            children.push_back(Node<T>(name, t));
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

    bool addNodeRec(int parentID, T name, Type t)
    {
        if(this->id == parentID)
        {
            children.push_back(Node<T>(name, t));
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


    bool deleteNodeRec(int id)
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
public:
    //    Node();
    //    Node(T name, Type type);
    std::vector<Node<T>> children;

    //    void addNode( int parentID, T name, Type type);
    //    void addNode( T parentName, T name, Type type);
    //    void addNode( T name, Type type);
    //    void deleteNode(int id);
    //    int size();


    //    //    Node * find(QString name);
    //    Node * findKLP_last();
    //    Node * findKLP_next();

    //    bool operator==(const Node<T>& ) const;
    //    bool operator<(const Node<T>& ) const;

    //    T getName() const;
    //    void setName(const T &value);

    bool findChildByName(const T &name) const
    {
        for(auto child: children)
        {
            if(child.getName() == name)
                return true;
        }
        return false;
    }
    qint32 getId() const
    {
        return id;
    }

    void setId(qint32 value)
    {
        id = value;
    }


    //    friend QDataStream& operator<<(QDataStream& os, const Node<T>& node);
    //    friend QDataStream& operator>>(QDataStream& is, Node<T>& node);

    Type getType() const
    {
        return type;
    }
    void setType(const Type &value)
    {
        type = value;
    }




    Node()
    {

    }


    Node(T name, Type type)
    {
        this->name = name;
        this->type = type;

    }



    void setName(const T &value)
    {
        name = value;
    }


    T getName() const
    {
        return name;
    }



    void addNode(int parentID, T name, Type t)
    {
        if(!addNodeRec(parentID, name, t))
        {
//            throw CantFindValidParentException(this, parentID, name, t);
        }
    }


    void addNode(T parentName, T name, Type type)
    {
        if(!addNodeRec(parentName, name, type))
        {
//            throw CantFindValidParentException(this, parentName, name, type);
        }
    }





    void addNode(T name, Type t)
    {
        children.push_back(Node<T>(name, t));
    }


    void deleteNode(int id)
    {
        if(!deleteNodeRec(id))
        {
//            throw CantFindNodeToDeleteException(this, id);
        }
    }



    qint32 size()
    {
        qint32 count = 0;
        for(Node<T> child : children) {
            count = child.size();
        }
        return 1 + count;
    }



    Node<T> * findKLP_last()
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


    Node<T> * findKLP_next()
    {
        if(children.size() > 0)
            return &(children.at(0));
        return nullptr;
    }


    bool operator==(const Node<T> &right) const
    {
        if(!this)
            return false;
        return (this->name == right.name);
    }


    bool operator<(const Node<T> &right) const
    {
        return (this->name < right.name);
    }


    friend QDataStream& operator<<(QDataStream& os, const Node& node)
    {
        qDebug() << "store Node<T>" << node.id
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


    friend QDataStream& operator>>(QDataStream& is, Node& node)
    {
        qint32 type;
        size_t childrenCount;
        is >> node.id
                >> node.name
                >> type
                >> childrenCount;
        for(unsigned int i = 0; i < childrenCount; i++)
        {
            Node<T> child;
            is >> child;
            node.children.push_back(child);
        }
        node.type = static_cast<Type>(type);
        qDebug() << "restore Node<T>" << node.id
                 << node.name
                 << getFriendlyName(node.type)
                 << node.children.size();
        return is;
    }


};

#endif // NODE_H
