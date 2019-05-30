#ifndef LISTLINEWIDGET_H
#define LISTLINEWIDGET_H

#include <QWidget>
#include "container/domain/tree.h"

class ListLineWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ListLineWidget(Tree *tree, QWidget *parent = nullptr);

private:
    Tree* tree;

signals:
    void editButtonClicked(Tree *tree);
    void removeButtonClicked(Tree *tree);

public slots:
    void handleEditButtonClick();
};

#endif // LISTLINEWIDGET_H
