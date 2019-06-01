#ifndef TREENODE_H
#define TREENODE_H

#include <QGraphicsItem>
#include "container/domain/node.h"

class Edge;
class GraphWidget;
class QGraphicsSceneMouseEvent;

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

    Node *getNode() const;
    void setNode(Node *value);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    Node *node;

signals:
    void treeNodeClicked(Node*);
};
#endif // TREENODE_H
