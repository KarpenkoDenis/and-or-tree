#ifndef TREEEXCEPTION_H
#define TREEEXCEPTION_H

#include <QString>
#include <QTime>
#include "container/domain/node.h"
//template <class T>
//class Node<T>;

class TreeException
{
public:
    explicit TreeException(const Node<QString>* root);
    virtual ~TreeException();
    const Node<QString>* getRoot() const;
    virtual QString what() const;
private:
    const Node<QString>* root;
};

class CantFindValidParentException : public TreeException
{
public:
    CantFindValidParentException(const Node<QString>* root, const int parentID, const QString& name, const Type& type);
    CantFindValidParentException(const Node<QString>* root, const QString& parentName, const QString& name, const Type& type);
    ~CantFindValidParentException() override;
    QString what() const override;
    int getParentID() const;
    QString getNodeName() const;
    Type getType() const;
private:
    int parentID;
    QString parentName;
    QString nodeName;
    Type type;
};

class CantFindNodeToDeleteException : public TreeException
{
public:
    CantFindNodeToDeleteException(const Node<QString>* root, const int id);
    ~CantFindNodeToDeleteException() override;
    QString what() const override;
    int getId() const;
private:
    int id;
};

#endif // TREEEXCEPTION_H
