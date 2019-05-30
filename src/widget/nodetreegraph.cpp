#include "nodetreegraph.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QDebug>

NodeTreeGraph::NodeTreeGraph(QWidget *parent) : QWidget(parent)
{
    treeGraphScene = new QGraphicsScene();
}

NodeTreeGraph::~NodeTreeGraph()
{
    delete treeGraphScene;
}






