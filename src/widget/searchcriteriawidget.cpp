#include "searchcriteriawidget.h"
#include <QHBoxLayout>

SearchCriteriaWidget::SearchCriteriaWidget(QWidget *parent) : QWidget(parent)
{
    searchCriteriaTypeComboBox = new QComboBox();
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
