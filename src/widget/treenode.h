#ifndef TREENODE_H
#define TREENODE_H

#include <QGraphicsItem>
#include "container/domain/node.h"

using namespace TreeContainer;

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

    bool getIsRoot() const;
    void setIsRoot(bool value);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:

    QList<Edge *> edgeList;
    QPointF newPos;
    GraphWidget *graph;
    Node<QString> *node;
    bool isRoot;

signals:
    void treeNodeClicked(Node<QString>*, bool);

};
#endif // TREENODE_H
