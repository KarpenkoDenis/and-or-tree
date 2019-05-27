#include "container/node.h"
#include "container/tree.h"
#include "container/treeiterator.h"

#include <QVector>
#include <QMap>

QVector<int> findTrees(QVector<Tree> trees, QMap<QString, QString> properties)
{
    QVector<int> resultTrees;
    int currNum=0;
    for(auto tree : trees)
    {
        for(auto iter = tree.begin(); iter!=tree.end(); ++iter)
        {
            foreach (QString key, properties.keys())
            {

              QString childName=properties.value(key);
              if((*iter).getName() == key)
              {
                  if((*iter).findChildByName(childName))
                  resultTrees.append(currNum);
              }
            }
        }
        currNum++;
    }
    return resultTrees;
}

QMap<QString, QVector<QString>> findProperties(QVector<Tree> trees)
{
    QMap<QString, QVector<QString>> resultProperties;
    for(auto tree : trees)
    {
        for(auto iter = tree.begin(); iter!=tree.end(); ++iter)
        {
            if((*iter).getType() == Or)
            {
                QVector<QString> childNames = resultProperties[(*iter).getName()];
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
