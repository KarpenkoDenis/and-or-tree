#include "search.h"
#include <QDebug>
QVector<int> findTrees(QVector<Tree> trees, QMap<QString, QString> properties)
{
    QVector<int> resultTrees;
    int currNum=0;
    for(auto tree : trees)
    {
        for(auto iter = tree.begin(); iter!=tree.end(); ++iter)
        {
            bool goodTree = true;
            foreach (QString key, properties.keys())
            {
              QString childName=properties.value(key);
              if((*iter).getName() == key)
              {
                  if(!(*iter).findChildByName(childName))
                  {
                    goodTree = false;
                    break;
                  }
              }
            }
            if(goodTree)
            {
                resultTrees.append(currNum);
            }
        }
        currNum++;
    }
    return resultTrees;
}

QMap<QString, QList<QString>> findProperties(QVector<Tree> trees)
{
    QMap<QString, QList<QString>> resultProperties;
    for(auto tree : trees)
    {
        for(TreeIterator iter = tree.begin(); iter!=tree.end(); ++iter)
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
