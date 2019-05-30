#ifndef TREENODE_H
#define TREENODE_H

#include <QGraphicsItem>
#include <QList>
#include "container/domain/node.h"

class Edge;
class GraphWidget;
class QGraphicsSceneMouseEvent;

class TreeNode : public QGraphicsItem
{
public:
    TreeNode(GraphWidget *graphWidget);

    void addEdge(Edge *edge);
    QList<Edge *> edges() const;

    enum { Type = UserType + 1 };
    int type() const override { return Type; }

    void calculateForces();
    bool advancePosition();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    Node *getNode() const;
    void setNode(Node *value);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QList<Edge *> edgeList;
    QPointF newPos;
    GraphWidget *graph;
    Node *node;
};
#endif // TREENODE_H
