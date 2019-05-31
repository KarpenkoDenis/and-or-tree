#include "treeexception.h"

TreeException::TreeException(const Node* root) :
    root(root)
{
}

const Node* TreeException::getRoot() const
{
    return root;
}

TreeException::~TreeException()
{
}

QString TreeException::what() const
{
    return "An error has occured in Tree class!";
}

CantFindValidParentException::CantFindValidParentException(const Node* root, const int parentID, const QString& name, const Type& type) :
    TreeException(root),
    parentID(parentID),
    nodeName(name),
    type(type)
{
}

CantFindValidParentException::CantFindValidParentException(const Node* root, const QString& parentName, const QString& name, const Type& type):
    TreeException(root),
    parentName(parentName),
    nodeName(name),
    type(type)
{

}

QString CantFindValidParentException::what() const
{
    return TreeException::what()
            + " Can't find parent with ID = " + QString::number(parentID)
            + ". Name = " + nodeName
            + " type = " + getFriendlyName(type) +  ".";
}

int CantFindValidParentException::getParentID() const
{
    return parentID;
}

QString CantFindValidParentException::getNodeName() const
{
    return nodeName;
}

Type CantFindValidParentException::getType() const
{
    return type;
}

CantFindValidParentException::~CantFindValidParentException()
{
}

CantFindNodeToDeleteException::CantFindNodeToDeleteException(const Node* root, const int id) :
    TreeException(root),
    id(id)
{
}

QString CantFindNodeToDeleteException::what() const
{
    return TreeException::what()
            + " Can't find node with ID = " + QString::number(id)
            + " to delete.";
}

int CantFindNodeToDeleteException::getId() const
{
    return id;
}

CantFindNodeToDeleteException::~CantFindNodeToDeleteException()
{
}
