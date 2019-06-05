#include "search.h"
#include <QDebug>
QVector<Tree<QString>*> findTrees(QVector<Tree<QString>*> trees, QMap<QString, QString> properties)
{
    if(properties.size() == 0)
        return trees;
    QVector<Tree<QString>*> resultTrees;
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

QMap<QString, QSet<QString>> findProperties(QVector<Tree<QString>*> trees)
{
    QMap<QString, QSet<QString>> resultProperties;
    for(auto tree : trees)
    {
        for(TreeIterator<QString> iter = tree->begin(); iter!=tree->end(); ++iter)
        {
            qDebug() << "(*iter).getName()"  << (*iter).getName();
            if((*iter).getType() == Or)
            {

                QSet<QString> childNames = resultProperties[(*iter).getName()];
                qDebug() << "(*iter).getType() == Or";
                for(auto child : (*iter).children)
                {
                    childNames.insert(child.getName());
                }
                resultProperties.insert((*iter).getName(), childNames);
            }
        }
    }
    return resultProperties;
}
