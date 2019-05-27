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
