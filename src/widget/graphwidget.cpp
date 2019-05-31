#include "graphwidget.h"
#include "edge.h"
#include "treenode.h"

#include <math.h>

#include <QKeyEvent>
#include <QRandomGenerator>
#include <QDebug>

GraphWidget::GraphWidget(QWidget *parent)
    : QGraphicsView(parent), timerId(0)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 400, 400);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(400, 400);
    setWindowTitle(tr("Elastic Nodes"));

    //    TreeNode *node1 = new TreeNode(this);
    //    TreeNode *node2 = new TreeNode(this);
    //    TreeNode *node3 = new TreeNode(this);
    //    TreeNode *node4 = new TreeNode(this);
    //    centerNode = new TreeNode(this);
    //    TreeNode *node6 = new TreeNode(this);
    //    TreeNode *node7 = new TreeNode(this);
    //    TreeNode *node8 = new TreeNode(this);
    //    TreeNode *node9 = new TreeNode(this);
    //    TreeNode *node10 = new TreeNode(this);
    //    scene->addItem(node1);
    //    scene->addItem(node2);
    //    scene->addItem(node3);
    //    scene->addItem(node4);
    //    scene->addItem(centerNode);
    //    scene->addItem(node6);
    //    scene->addItem(node7);
    //    scene->addItem(node8);
    //    scene->addItem(node9);
    //    scene->addItem(node10);
    //    scene->addItem(new Edge(node2, centerNode));
    //    scene->addItem(new Edge(node3, node6));
    //    scene->addItem(new Edge(node4, node1));
    //    scene->addItem(new Edge(node4, centerNode));
    //    scene->addItem(new Edge(centerNode, node6));
    //    scene->addItem(new Edge(node6, node9));
    //    scene->addItem(new Edge(node7, node4));
    //    scene->addItem(new Edge(node8, node7));
    //    scene->addItem(new Edge(node9, node8));
    //    scene->addItem(new Edge(node9, node10));
    //    node1->setPos(-50, -50);
    //    node2->setPos(0, -50);
    //    node3->setPos(50, -50);
    //    node4->setPos(-50, 0);
    //    centerNode->setPos(0, 0);
    //    node6->setPos(50, 0);
    //    node7->setPos(-50, 50);
    //    node8->setPos(0, 50);
    //    node9->setPos(50, 50);
}

void GraphWidget::configure(Tree *tree)
{
    drawTreeNode(&(tree->root));
}

TreeNode* GraphWidget::drawTreeNode(Node *node)
{
    TreeNode *treeNode = new TreeNode(this);
    treeNode->setNode(node);
    treeNode->setPos(0,-500);
    this->scene()->addItem(treeNode);

    TreeNode* childTreeNode;
    for(auto iter = node->children.begin(); iter!=node->children.end(); ++iter)
    {
        childTreeNode = drawTreeNode(&(*iter));
        this->scene()->addItem(new Edge(treeNode, childTreeNode));

    }

    return treeNode;
}

void GraphWidget::itemMoved()
{
    if (!timerId)
        timerId = startTimer(1000 / 25);
}

void GraphWidget::handleNodeClick(Node *node)
{
    emit nodeClicked(node);
}

void GraphWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        centerNode->moveBy(0, -20);
        break;
    case Qt::Key_Down:
        centerNode->moveBy(0, 20);
        break;
    case Qt::Key_Left:
        centerNode->moveBy(-20, 0);
        break;
    case Qt::Key_Right:
        centerNode->moveBy(20, 0);
        break;
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    case Qt::Key_Space:
    case Qt::Key_Enter:
        shuffle();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

void GraphWidget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    QList<TreeNode *> nodes;
    foreach (QGraphicsItem *item, scene()->items()) {
        if (TreeNode *node = qgraphicsitem_cast<TreeNode *>(item))
            nodes << node;
    }

    foreach (TreeNode *node, nodes)
        node->calculateForces();

    bool itemsMoved = false;
    foreach (TreeNode *node, nodes) {
        if (node->advancePosition())
            itemsMoved = true;
    }

    if (!itemsMoved) {
        killTimer(timerId);
        timerId = 0;
    }
}

#if QT_CONFIG(wheelevent)
void GraphWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}
#endif

void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

    // Text
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
    QString message(tr("Click and drag the nodes around, and zoom with the mouse "
                       "wheel or the '+' and '-' keys"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
    painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);
}

void GraphWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void GraphWidget::shuffle()
{
    foreach (QGraphicsItem *item, scene()->items()) {
        if (qgraphicsitem_cast<TreeNode *>(item))
            item->setPos(-150 + QRandomGenerator::global()->bounded(300), -150 + QRandomGenerator::global()->bounded(300));
    }
}

void GraphWidget::zoomIn()
{
    scaleView(qreal(1.2));
}

void GraphWidget::zoomOut()
{
    scaleView(1 / qreal(1.2));
}
