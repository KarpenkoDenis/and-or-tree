#include "listviewboxlayout.h"

#include "widget/listview/listlinewidget.h"

ListViewBoxLayout::ListViewBoxLayout() : QVBoxLayout ()
{

}

void ListViewBoxLayout::configure(QVector<Tree *> trees)
{
    for(auto tree : trees){
        auto widget = new ListLineWidget(tree);
        QObject::connect(widget, SIGNAL(editButtonClicked(Tree*)), this, SLOT(handleEditButtonClick(Tree*)));
        addWidget(widget);
    }
}

void ListViewBoxLayout::handleEditButtonClick(Tree* tree)
{
    emit shouldOpenTreeEditor(tree);
}
