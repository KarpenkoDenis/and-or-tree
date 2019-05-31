#include "search.h"
#include <QDebug>
QVector<Tree*> findTrees(QVector<Tree*> trees, QMap<QString, QString> properties)
{
    QVector<Tree*> resultTrees;
    int currNum=0;
    for(auto tree : trees)
    {
        bool goodTree = false;
        foreach (QString key, properties.keys())
        {
            goodTree = false;
            for(auto iter = tree->begin(); iter!=tree->end(); ++iter)
            {
                QString childName=properties.value(key);
                if((*iter).getName() == key)
                {
                    if((*iter).findChildByName(childName))
                    {
                        goodTree = true;
                        break;
                    }
                }
            }
            if(!goodTree)
                break;
        }
        if(goodTree)
        {
            resultTrees.append(trees[currNum]);
        }
        currNum++;
    }

    return resultTrees;
}

QMap<QString, QList<QString>> findProperties(QVector<Tree*> trees)
{
    QMap<QString, QList<QString>> resultProperties;
    for(auto tree : trees)
    {
        for(TreeIterator iter = tree->begin(); iter!=tree->end(); ++iter)
        {
            qDebug() << "(*iter).getName()"  << (*iter).getName();
            if((*iter).getType() == Or)
            {

                QList<QString> childNames = resultProperties[(*iter).getName()];
                qDebug() << "(*iter).getType() == Or";
                for(auto child : (*iter).children)
                {
                    childNames.append(child.getName());
                }
                resultProperties.insert((*iter).getName(), childNames);
            }
        }
    }
    return resultProperties;
}
