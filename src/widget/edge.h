#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>


class TreeNode;


class Edge : public QGraphicsItem
{
public:
    Edge(TreeNode *sourceNode, TreeNode *destNode);

    TreeNode *sourceNode() const;
    TreeNode *destNode() const;

    void adjust();

    enum { Type = UserType + 2 };
    int type() const override { return Type; }

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    TreeNode *source, *dest;

    QPointF sourcePoint;
    QPointF destPoint;
};

#endif // EDGE_H
