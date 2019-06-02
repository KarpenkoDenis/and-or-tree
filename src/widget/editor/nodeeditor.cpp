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

void NodeEditor::configure(Node<QString> *node)
{
    currentNode = node;
    nodeNameLineEdit->setText(currentNode->getName());
    if(currentNode->getType() == And)
    {
        nodeTypeComboBox->setCurrentIndex(1);
    }
    else {
        nodeTypeComboBox->setCurrentIndex(0);
    }
    // TODO set value to combobox
}

void NodeEditor::handleNodeNameLineEditChange(QString name)
{
    if (currentNode) {
        currentNode->setName(name);
        emit shouldRefreshGraphWidget();
    }
}

void NodeEditor::handleNodeTypeComboBoxChange(int index)
{
    if (currentNode) {
        if (index) {
            currentNode->setType(And);
        } else {
            currentNode->setType(Or);
        }
        emit shouldRefreshGraphWidget();
    }

}

void NodeEditor::handleAddChildNodeButtonClick()
{
    if (currentNode) {
        qDebug() << "AddChildNodeButton handler";
        currentNode->addNode("Новый узел", Type::And);

        emit shouldRefreshGraphWidget();
    }
}

void NodeEditor::initializeLayout()
{
    nodeNameLineEdit = new QLineEdit();
    nodeTypeComboBox = new QComboBox();
    nodeTypeComboBox->addItem("Или");
    nodeTypeComboBox->addItem("И");
    addChildNodeButton = new QPushButton("Добавить дочерний узел");

    auto layout = new QVBoxLayout();

    layout->addWidget(new QLabel("Редакторовать узел"));
    layout->addWidget(nodeNameLineEdit);
    layout->addWidget(nodeTypeComboBox);
    layout->addWidget(addChildNodeButton);
    layout->addStretch(1);

    this->setLayout(layout);
}

void NodeEditor::defineConnects()
{
    QObject::connect(nodeNameLineEdit, SIGNAL(textChanged(QString)), this, SLOT(handleNodeNameLineEditChange(QString)));
    QObject::connect(nodeTypeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(handleNodeTypeComboBoxChange(int)));
    QObject::connect(addChildNodeButton, SIGNAL(clicked()), this, SLOT(handleAddChildNodeButtonClick()));

}

