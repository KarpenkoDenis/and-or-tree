#include "listviewboxlayout.h"

#include "widget/listview/listlinewidget.h"

ListViewBoxLayout::ListViewBoxLayout() : QVBoxLayout ()
{

}

void ListViewBoxLayout::configure(QVector<Tree<QString> *> trees)
{
    clearLayout(this);
    for(auto tree : trees){
        auto widget = new ListLineWidget(tree);
        QObject::connect(widget, SIGNAL(editButtonClicked(Tree<QString>*)), this, SLOT(handleEditButtonClick(Tree<QString>*)));
        QObject::connect(widget, SIGNAL(removeButtonClicked(Tree<QString>*)), this, SLOT(handleRemoveButtonClick(Tree<QString>*)));
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

void ListViewBoxLayout::handleEditButtonClick(Tree<QString>* tree)
{
    emit shouldOpenTreeEditor(tree);
}

void ListViewBoxLayout::handleRemoveButtonClick(Tree<QString> *tree)
{
    emit shouldRemoveTree(tree);
}
