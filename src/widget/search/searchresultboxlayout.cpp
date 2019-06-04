#include "searchresultboxlayout.h"
#include <QVector>
#include <QPushButton>
#include <QDebug>
#include <QLabel>

SearchResultBoxLayout::SearchResultBoxLayout() : QVBoxLayout()
{
}

SearchResultBoxLayout::~SearchResultBoxLayout()
{

}

void SearchResultBoxLayout::configure(QVector<Tree<QString>*> trees)
{
    clearLayout(this);
    if (trees.size() == 0) {
        addWidget(new QLabel("Комплектаций не найдено"));
    } else {
        for(auto tree : trees){
            addWidget(new QLabel(tree->getName()));
        }
    }
}

void SearchResultBoxLayout::clearLayout(QLayout *layout)
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
