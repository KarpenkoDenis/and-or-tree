#include "container/domain/node.h"
#include "container/domain/tree.h"
#include "container/treeiterator.h"

#include <QVector>
#include <QMap>

QVector<Tree*> findTrees(QVector<Tree*> trees, QMap<QString, QString> properties);
QMap<QString, QList<QString>> findProperties(QVector<Tree*> trees);
