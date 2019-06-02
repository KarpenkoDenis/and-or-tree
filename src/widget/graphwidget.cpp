#include "graphwidget.h"
#include "edge.h"
#include "treenode.h"
#include <QDebug>

GraphWidget::GraphWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 400, 400);

    setScene(scene);
    setMinimumSize(400, 400);
}

void GraphWidget::configure(Tree *tree)
{
    TreeNode *node1 = new TreeNode(this);
    node1->setNode(&(tree->root));
    this->scene()->addItem(node1);
}

void GraphWidget::itemMoved()
{
    if (!timerId)
        timerId = startTimer(1000 / 25);
}

void GraphWidget::handleNodeClick(Node<QString> *node)
{
    emit nodeClicked(node);
}

TreeNode* GraphWidget::drawTreeNode(Node *node, int level, int w1, int w2)
{
    TreeNode *treeNode = new TreeNode();
    treeNode->setNode(node);
    this->scene()->addItem(treeNode);
    treeNode->setPos(w1 + (w2-w1)/2,-200 + level*100);

    TreeNode* childTreeNode;
    int sectorCounter = 0;

    for(auto iter = node->children.begin(); iter!=node->children.end(); ++iter)
    {
        int sectorWidth = (w2 - w1) / node->children.size();
        childTreeNode = drawTreeNode(&(*iter), level + 1, w1 + sectorCounter*sectorWidth, w1 + (sectorCounter+1)*sectorWidth);
        this->scene()->addItem(new Edge(treeNode, childTreeNode));
        sectorCounter++;
    }

    QObject::connect(treeNode, SIGNAL(treeNodeClicked(Node*)), this, SLOT(handleTreeNodeClick(Node*)));
    return treeNode;
}

void GraphWidget::handleTreeNodeClick(Node *node)
{
    emit shouldChangeNodeEditor(node);
}

void GraphWidget::refreshWidget()
{
    configure(tree);
}
