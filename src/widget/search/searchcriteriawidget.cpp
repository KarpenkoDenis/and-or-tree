#include "searchcriteriawidget.h"
#include "search.h"
#include <QHBoxLayout>
#include <QMap>
#include <QSet>

SearchCriteriaWidget::SearchCriteriaWidget(QMap<QString, QSet<QString>> possibleSearchCriteria, QWidget *parent) : QWidget(parent)
{
    initializeWidget(possibleSearchCriteria);
    configureConnects();
}

SearchCriteriaWidget::~SearchCriteriaWidget(){
    delete searchCriteriaTypeComboBox;
    delete searchCriteriaValueComboBox;
    delete removeSearchCriteriaButton;
}

QPair<QString, QString> SearchCriteriaWidget::getCriteria()
{
    QString criteriaType = searchCriteriaTypeComboBox->currentText();
    QString criteriaValue = searchCriteriaValueComboBox->currentText();
    QPair<QString, QString> criteria(criteriaType, criteriaValue);

    return criteria;
}

void SearchCriteriaWidget::initializeWidget(QMap<QString, QSet<QString>> possibleSearchCriteria)
{
    this->possibleSearchCriteria = possibleSearchCriteria;

    QList<QString> criterias = possibleSearchCriteria.keys();

    searchCriteriaTypeComboBox = new QComboBox();
    searchCriteriaTypeComboBox->addItems(criterias);

    searchCriteriaValueComboBox = new QComboBox();
    handleSearchCriteriaTypeSelect(searchCriteriaTypeComboBox->currentText());

    removeSearchCriteriaButton = new QPushButton("Убрать");

    auto layout = new QHBoxLayout();
    layout->addWidget(searchCriteriaTypeComboBox);
    layout->addWidget(searchCriteriaValueComboBox);
    layout->addWidget(removeSearchCriteriaButton);

    this->setLayout(layout);
}

void SearchCriteriaWidget::configureConnects()
{
    QObject::connect(this->searchCriteriaTypeComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(handleSearchCriteriaTypeSelect(QString)));
    QObject::connect(this->removeSearchCriteriaButton, SIGNAL(clicked()), this, SLOT(handleRemoveSearchCriteriaButtonClick()));
}

void SearchCriteriaWidget::handleSearchCriteriaTypeSelect(QString typeName)
{
    searchCriteriaValueComboBox->clear();
    QList<QString> saveProperties;
    for(QString curr:possibleSearchCriteria[typeName])
    {
        saveProperties.append(curr);
    }
    searchCriteriaValueComboBox->addItems(saveProperties);
    searchCriteriaValueComboBox->setCurrentIndex(0);
}

void SearchCriteriaWidget::handleRemoveSearchCriteriaButtonClick()
{
    emit shouldRemoveSearchCriteria(this);
}
