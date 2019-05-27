#include "listlinewidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QDebug>

ListLineWidget::ListLineWidget(Tree &tree, MainWindow *mainWindow, QWidget *parent) : QWidget(parent)
{
    this->tree = tree;

    auto layout = new QHBoxLayout();
    QPushButton * editButton = new QPushButton("Редактировать");

    layout->addWidget(new QLabel(tree.getName()));
    layout->addWidget(editButton);
    layout->addWidget(new QPushButton("Удалить"));

    this->setLayout(layout);
    QObject::connect(editButton, SIGNAL(clicked()), this, SLOT(handleEditButtonClick()));
    QObject::connect(this, SIGNAL(openEditor(Tree*)), mainWindow, SLOT(openEditor(Tree*)));
}

void ListLineWidget::handleEditButtonClick()
{
    emit openEditor(&(this->tree));
}
