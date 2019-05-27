#include "nodeeditor.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QDebug>

NodeEditor::NodeEditor(QWidget *parent) : QWidget(parent)
{
    initializeLayout();
    defineConnects();
}

NodeEditor::~NodeEditor()
{
    delete addChildNodeButton;
    delete nodeNameLineEdit;
    delete nodeTypeComboBox;
}

void NodeEditor::configure(Node *node)
{
    currentNode = node;
    nodeNameLineEdit->setText(currentNode->getName());
    // TODO set value to combobox
}

void NodeEditor::handleAddChildNodeButtonClick()
{
    qDebug() << "AddChildNodeButton handler";
    currentNode->addNode("default", Type::And);
}

void NodeEditor::handleSaveNodeButtonClick()
{
    // TODO implement saving
    qDebug() << "SaveNodeButton handler";
}

void NodeEditor::initializeLayout()
{
    nodeNameLineEdit = new QLineEdit();
    nodeTypeComboBox = new QComboBox();
    nodeTypeComboBox->addItem("Или");
    nodeTypeComboBox->addItem("И");
    addChildNodeButton = new QPushButton("Добавить дочерний узел");
    saveNodeButton = new QPushButton("Сохранить узел");


    auto layout = new QVBoxLayout();

    layout->addWidget(new QLabel("Редакторовать узел"));
    layout->addWidget(nodeNameLineEdit);
    layout->addWidget(nodeTypeComboBox);
    layout->addWidget(addChildNodeButton);
    layout->addWidget(saveNodeButton);
    layout->addStretch(1);


    this->setLayout(layout);
}

void NodeEditor::defineConnects()
{
    QObject::connect(addChildNodeButton, SIGNAL(clicked()), this, SLOT(handleAddChildNodeButtonClick()));
    QObject::connect(saveNodeButton, SIGNAL(clicked()), this, SLOT(handleSaveNodeButtonClick()));
}

