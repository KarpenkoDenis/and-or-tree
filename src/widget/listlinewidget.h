#ifndef LISTLINEWIDGET_H
#define LISTLINEWIDGET_H

#include <QWidget>
#include "container/domain/tree.h"
#include "window/mainwindow.h"
class ListLineWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ListLineWidget(Tree &tree, MainWindow *mainWindow, QWidget *parent = nullptr);

private:
    Tree tree;

signals:
    void openEditor(Tree *tree);

public slots:
    void handleEditButtonClick();
};

#endif // LISTLINEWIDGET_H
