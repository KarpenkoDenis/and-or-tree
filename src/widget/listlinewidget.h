#ifndef LISTLINEWIDGET_H
#define LISTLINEWIDGET_H

#include <QWidget>
#include "container/tree.h"

class ListLineWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ListLineWidget(Tree tree, QWidget *parent = nullptr);

private:
    Tree tree;

signals:

public slots:
};

#endif // LISTLINEWIDGET_H
