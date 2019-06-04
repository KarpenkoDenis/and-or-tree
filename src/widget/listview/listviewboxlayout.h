#ifndef LISTVIEWBOXLAYOUTONE_H
#define LISTVIEWBOXLAYOUTONE_H

#include <QVBoxLayout>
#include <QWidget>

#include "container/domain/tree.h"

using namespace TreeContainer;

class ListViewBoxLayout : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit ListViewBoxLayout();
    void configure(QVector<Tree<QString>*>);

private:
    void clearLayout(QLayout*);

signals:
    void shouldOpenTreeEditor(Tree<QString>* tree);
    void shouldRemoveTree(Tree<QString>* tree);

public slots:
    void handleEditButtonClick(Tree<QString>*);
    void handleRemoveButtonClick(Tree<QString>*);
};

#endif // LISTVIEWBOXLAYOUTONE_H
