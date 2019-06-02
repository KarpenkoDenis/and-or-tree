#include "edge.h"
#include "treenode.h"
#include "graphwidget.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>

TreeNode::TreeNode()
{
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
}

QRectF TreeNode::boundingRect() const
{
    return QRectF( -60, -60, 120, 120);
}

QPainterPath TreeNode::shape() const
{
    QPainterPath path;
    path.addEllipse(-10, -10, 20, 20);
    return path;
}

void TreeNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-10, -10, 20, 20);
    painter->drawText(-10, -10, node->getName());

    if(node->getType() == Or) {
        QRectF rectangle(-10,-5,20,20);
        painter->drawArc(rectangle, -30*16, -120*16);
    }
}

void TreeNode::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
    emit treeNodeClicked(node);
}

Node<QString> *TreeNode::getNode() const
{
    return node;
}


void TreeNode::setNode(Node<QString> *value)
{
    this->node = node;
}
