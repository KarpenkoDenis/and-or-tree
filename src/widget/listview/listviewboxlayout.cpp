#include "listviewboxlayout.h"

#include "widget/listview/listlinewidget.h"

ListViewBoxLayout::ListViewBoxLayout() : QVBoxLayout ()
{

}

void ListViewBoxLayout::configure(QVector<Tree *> trees)
{
    clearLayout(this);
    for(auto tree : trees){
        auto widget = new ListLineWidget(tree);
        QObject::connect(widget, SIGNAL(editButtonClicked(Tree*)), this, SLOT(handleEditButtonClick(Tree*)));
        QObject::connect(widget, SIGNAL(removeButtonClicked(Tree*)), this, SLOT(handleRemoveButtonClick(Tree*)));
        addWidget(widget);
    }
}

void ListViewBoxLayout::clearLayout(QLayout *)
{
    QLayoutItem *item;
    while((item = takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

void ListViewBoxLayout::handleEditButtonClick(Tree* tree)
{
    emit shouldOpenTreeEditor(tree);
}

void ListViewBoxLayout::handleRemoveButtonClick(Tree *tree)
{
    emit shouldRemoveTree(tree);
}
