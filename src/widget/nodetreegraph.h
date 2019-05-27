#ifndef NODETREEGRAPH_H
#define NODETREEGRAPH_H


#include <QWidget>
#include "container/node.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QGraphicsScene>
#include <QtCore>
#include <QtGui>


class NodeTreeGraph : public QWidget
{
    Q_OBJECT

public:
    explicit NodeTreeGraph(QWidget *parent = nullptr);
    ~NodeTreeGraph();
    QGraphicsScene *treeGraphScene = nullptr;
    QGraphicsRectItem *reactangle;


private:




signals:

public slots:

};

#endif // NODETREEGRAPH_H
