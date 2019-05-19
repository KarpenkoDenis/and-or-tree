#include "listlinewidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

ListLineWidget::ListLineWidget(Tree tree, QWidget *parent) : QWidget(parent)
{
    this->tree = tree;

    auto layout = new QHBoxLayout();
    layout->addWidget(new QLabel(tree.getName()));
    layout->addWidget(new QPushButton("Редактировать"));
    layout->addWidget(new QPushButton("Удалить"));

    this->setLayout(layout);
}
