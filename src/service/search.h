#include "container/domain/node.h"
#include "container/domain/tree.h"
#include "container/treeiterator.h"

#include <QVector>
#include <QMap>

using namespace TreeContainer;

QVector<Tree<QString>*> findTrees(QVector<Tree<QString>*> trees, QMap<QString, QString> properties);
QMap<QString, QList<QString>> findProperties(QVector<Tree<QString>*> trees);
