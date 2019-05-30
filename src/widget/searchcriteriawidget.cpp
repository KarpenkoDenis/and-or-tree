#include "searchcriteriawidget.h"
#include <QHBoxLayout>
#include "search.h"
#include <QMap>

SearchCriteriaWidget::SearchCriteriaWidget(MainWindow *mainWindow, QWidget *parent) : QWidget(parent)
{
    this->mainWindow = mainWindow;
    QVector<Tree> trees = this->mainWindow->stateManager->getTrees();
    this->properties = findProperties(trees);
    QList<QString> criterias = properties.keys();

    searchCriteriaTypeComboBox = new QComboBox();
    searchCriteriaTypeComboBox->addItems(criterias);
    searchCriteriaValueComboBox = new QComboBox();
    removeSearchCriteriaButton = new QPushButton("Убрать");

    auto layout = new QHBoxLayout();

    layout->addWidget(searchCriteriaTypeComboBox);
    layout->addWidget(searchCriteriaValueComboBox);
    layout->addWidget(removeSearchCriteriaButton);

    this->setLayout(layout);


    QObject::connect(this->searchCriteriaTypeComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(handleSearchCriteriaTypeSelect(QString)));
}

SearchCriteriaWidget::~SearchCriteriaWidget(){
    delete searchCriteriaTypeComboBox;
    delete searchCriteriaValueComboBox;
    delete removeSearchCriteriaButton;
}

QPair<QString, QString> SearchCriteriaWidget::getCriteria()
{
    QPair<QString, QString>  pair(searchCriteriaTypeComboBox->currentText(), searchCriteriaValueComboBox->currentText());
    return pair;
}

void SearchCriteriaWidget::handleSearchCriteriaTypeSelect(QString typeName)
{
//    QVector<QString> values = this->properties[typeName];
    QList<QString> values;
    for(auto el:this->properties[typeName])
    {
        values.push_back(el);
    }
    searchCriteriaValueComboBox->clear();
    searchCriteriaValueComboBox->addItems(values);
    searchCriteriaValueComboBox->setCurrentIndex(0);
}
