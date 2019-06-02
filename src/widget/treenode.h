#ifndef TREENODE_H
#define TREENODE_H

#include <QGraphicsItem>
#include "container/domain/node.h"

class Edge;
class GraphWidget;
class QGraphicsSceneMouseEvent;
//template <class T>
//class Node<T>;

class TreeNode : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    TreeNode();

    enum { Type = UserType + 1 };
    int type() const override { return Type; }
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    Node<QString> *getNode() const;
    void setNode(Node<QString> *value);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:

    QList<Edge *> edgeList;
    QPointF newPos;
    GraphWidget *graph;
    Node<QString> *node;

signals:
    void treeNodeClicked(Node<QString>*);

};
#endif // TREENODE_H
