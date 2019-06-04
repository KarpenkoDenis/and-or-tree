#include "listlinewidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QDebug>

ListLineWidget::ListLineWidget(Tree<QString> *tree, QWidget *parent) : QWidget(parent)
{
    this->tree = tree;

    auto layout = new QHBoxLayout();
    editButton = new QPushButton("Редактировать");
    removeButton = new QPushButton("Удалить");

    layout->addWidget(new QLabel(tree->getName()));
    layout->addWidget(editButton);
    layout->addWidget(removeButton);

    this->setLayout(layout);
    QObject::connect(editButton, SIGNAL(clicked()), this, SLOT(handleEditButtonClick()));
    QObject::connect(removeButton, SIGNAL(clicked()), this, SLOT(handleRemoveButtonClick()));
}

ListLineWidget::~ListLineWidget()
{
    delete editButton;
    delete removeButton;
}

void ListLineWidget::handleEditButtonClick()
{
    emit editButtonClicked(tree);
}

void ListLineWidget::handleRemoveButtonClick()
{
    emit removeButtonClicked(tree);
}
