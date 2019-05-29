#include "container/node.h"
#include "container/tree.h"
#include "container/treeiterator.h"

#include <QVector>
#include <QMap>

QVector<int> findTrees(QVector<Tree> trees, QMap<QString, QString> properties);
QMap<QString, QVector<QString>> findProperties(QVector<Tree> trees);
