#include "searchcriteriawidget.h"
#include <QHBoxLayout>
#include "search.h"

SearchCriteriaWidget::SearchCriteriaWidget(MainWindow *mainWindow, QWidget *parent) : QWidget(parent)
{
    this->mainWindow = mainWindow;
QVector<Tree> trees = this->mainWindow->stateManager->getTrees();
    this->properties = findProperties(trees);
//    QList<QString> criterias = properties.keys();

    searchCriteriaTypeComboBox = new QComboBox();
//    searchCriteriaTypeComboBox->addItems(criterias);
    searchCriteriaValueComboBox = new QComboBox();
    removeSearchCriteriaButton = new QPushButton("Убрать");

    auto layout = new QHBoxLayout();

    layout->addWidget(searchCriteriaTypeComboBox);
    layout->addWidget(searchCriteriaValueComboBox);
    layout->addWidget(removeSearchCriteriaButton);

    this->setLayout(layout);
}

SearchCriteriaWidget::~SearchCriteriaWidget(){
    delete searchCriteriaTypeComboBox;
    delete searchCriteriaValueComboBox;
    delete removeSearchCriteriaButton;
}
