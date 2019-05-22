#ifndef TREEEXCEPTION_H
#define TREEEXCEPTION_H

#include <QString>
#include <QTime>
#include "node.h"

class TreeException
{
public:
    TreeException();
    explicit TreeException(QString functionName);
    QTime getTime();
    QString getFunctionName();
    virtual QString what();
private:
    QString functionName;
    QTime time;
};

class CantFindValidParentException : public TreeException
{
public:
    CantFindValidParentException();
    CantFindValidParentException(QString functionName, int parentID, QString name, Type type);
    QString what() override;
    int getParentID();
    QString getName();
    Type getType();
private:
    int parentID;
    QString name;
    Type type;
};

class CantFindNodeToDeleteException : public TreeException
{
public:
    CantFindNodeToDeleteException();
    CantFindNodeToDeleteException(QString functionName, int id);
    QString what() override;
    int getId();
private:
    int id;
};

#endif // TREEEXCEPTION_H
