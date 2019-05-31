#ifndef LISTVIEWBOXLAYOUTONE_H
#define LISTVIEWBOXLAYOUTONE_H

#include <QVBoxLayout>
#include <QWidget>

#include "container/domain/tree.h"

class ListViewBoxLayout : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit ListViewBoxLayout();
    void configure(QVector<Tree*>);

private:
    void clearLayout(QLayout*);

signals:
    void shouldOpenTreeEditor(Tree* tree);
    void shouldRemoveTree(Tree* tree);

public slots:
    void handleEditButtonClick(Tree*);
    void handleRemoveButtonClick(Tree*);
};

#endif // LISTVIEWBOXLAYOUTONE_H
