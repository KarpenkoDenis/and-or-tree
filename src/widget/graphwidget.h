#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include "container/domain/tree.h"

class TreeNode;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent = nullptr);
    void configure(Tree*);
    void itemMoved();
    void handleNodeClick(Node*);

public slots:
    void shuffle();
    void zoomIn();
    void zoomOut();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    void scaleView(qreal scaleFactor);

private:
    int timerId;
    TreeNode *centerNode;

signals:
    void nodeClicked(Node*);
};

#endif // GRAPHWIDGET_H
