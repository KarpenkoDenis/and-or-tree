#include "listlinewidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QDebug>

ListLineWidget::ListLineWidget(Tree *tree, QWidget *parent) : QWidget(parent)
{
    this->tree = tree;

    auto layout = new QHBoxLayout();
    QPushButton * editButton = new QPushButton("Редактировать");

    layout->addWidget(new QLabel(tree->getName()));
    layout->addWidget(editButton);
    layout->addWidget(new QPushButton("Удалить"));

    this->setLayout(layout);
    QObject::connect(editButton, SIGNAL(clicked()), this, SLOT(handleEditButtonClick()));
}

void ListLineWidget::handleEditButtonClick()
{
    emit editButtonClicked(tree);
}
