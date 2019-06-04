#ifndef LISTLINEWIDGET_H
#define LISTLINEWIDGET_H

#include <QWidget>
#include "container/domain/tree.h"
#include <QPushButton>

using namespace TreeContainer;

class ListLineWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ListLineWidget(Tree<QString> *tree, QWidget *parent = nullptr);
    ~ListLineWidget();

private:
    Tree<QString>* tree;
    QPushButton * editButton = nullptr;
    QPushButton * removeButton = nullptr;

signals:
    void editButtonClicked(Tree<QString> *tree);
    void removeButtonClicked(Tree<QString> *tree);

public slots:
    void handleEditButtonClick();
    void handleRemoveButtonClick();
};

#endif // LISTLINEWIDGET_H
