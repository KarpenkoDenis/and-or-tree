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

private:
    TreeNode* drawTreeNode(Node*, int, int, int);
    Tree* tree = nullptr;

signals:
    void shouldChangeNodeEditor(Node*);

public slots:
    void handleTreeNodeClick(Node*);
    void refreshWidget();
};

#endif // GRAPHWIDGET_H
