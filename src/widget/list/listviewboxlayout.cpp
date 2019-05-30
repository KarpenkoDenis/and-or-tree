#include "listviewboxlayout.h"
#include <QVBoxLayout>

ListViewBoxLayout::ListViewBoxLayout() : QVBoxLayout()
{

}

void ListViewBoxLayout::configure(QVector<Tree *> trees)
{
    for(auto tree : trees){
        addWidget(new ListLineWidget(tree, this));
    }
}
