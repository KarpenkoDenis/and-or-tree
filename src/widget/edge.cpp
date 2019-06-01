#include "edge.h"
#include "treenode.h"

#include <qmath.h>
#include <QPainter>

Edge::Edge(TreeNode *sourceNode, TreeNode *destNode)
{
    setAcceptedMouseButtons(0);
    source = sourceNode;
    dest = destNode;
    adjust();
}

TreeNode *Edge::sourceNode() const
{
    return source;
}

TreeNode *Edge::destNode() const
{
    return dest;
}

void Edge::adjust()
{
    if (!source || !dest)
        return;

    QLineF line(mapFromItem(source, 0, 0), mapFromItem(dest, 0, 0));
    qreal length = line.length();

    prepareGeometryChange();

    if (length > qreal(20.)) {
        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
    } else {
        sourcePoint = destPoint = line.p1();
    }
}

QRectF Edge::boundingRect() const
{
    if (!source || !dest)
        return QRectF();


    return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized();
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (!source || !dest)
        return;

    QLineF line(sourcePoint, destPoint);
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;

    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);
}
