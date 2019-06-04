#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include "container/domain/tree.h"
#include "container/domain/node.h"

class TreeNode;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget(QWidget *parent = nullptr);
    void configure(Tree<QString>*);

private:
    TreeNode* drawTreeNode(Node<QString>*, int, int, int);
    Tree<QString>* tree = nullptr;

signals:
    void shouldChangeNodeEditor(Node<QString>*);

public slots:
    void handleTreeNodeClick(Node<QString>*);
    void refreshWidget();
};

#endif // GRAPHWIDGET_H
