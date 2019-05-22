#include "treeexception.h"

TreeException::TreeException():
    time(QTime::currentTime())
{
}

TreeException::TreeException(QString functionName) :
    functionName(functionName),
    time(QTime::currentTime())
{
}

QTime TreeException::getTime()
{
    return time;
}

QString TreeException::getFunctionName()
{
    return functionName;
}

QString TreeException::what()
{
    return "At " + time.toString() + " an error was occured in function " + functionName + "!";
}

CantFindValidParentException::CantFindValidParentException() :
    TreeException(),
    parentID(0),
    type(Type::And)
{
}

CantFindValidParentException::CantFindValidParentException(QString functionName, int parentID, QString name, Type type) :
    TreeException(functionName),
    parentID(parentID),
    name(name),
    type(type)
{
}

QString CantFindValidParentException::what()
{
    return TreeException::what()
            + " Can't find parent with ID = " + QString::number(parentID)
            + ". Name = " + name
            + " type = " + getFriendlyName(type) +  ".";
}

int CantFindValidParentException::getParentID()
{
    return parentID;
}

QString CantFindValidParentException::getName()
{
    return name;
}

Type CantFindValidParentException::getType()
{
    return type;
}
