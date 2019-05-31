#ifndef LISTLINEWIDGET_H
#define LISTLINEWIDGET_H

#include <QWidget>
#include "container/domain/tree.h"
#include <QPushButton>

class ListLineWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ListLineWidget(Tree *tree, QWidget *parent = nullptr);
    ~ListLineWidget();

private:
    Tree* tree;
    QPushButton * editButton = nullptr;
    QPushButton * removeButton = nullptr;

signals:
    void editButtonClicked(Tree *tree);
    void removeButtonClicked(Tree *tree);

public slots:
    void handleEditButtonClick();
    void handleRemoveButtonClick();
};

#endif // LISTLINEWIDGET_H
