#include "listviewboxlayout.h"
#include "widget/list/listlinewidget.h"

ListViewBoxLayout::ListViewBoxLayout() : QVBoxLayout()
{

}

void ListViewBoxLayout::configure(QVector<Tree *> trees)
{
    for(auto tree : trees){
        addWidget(new ListLineWidget(tree, this));
    }
}
