#include "searchcriteriaboxlayout.h"

SearchCriteriaBoxLayout::SearchCriteriaBoxLayout() : QVBoxLayout ()
{

}

QList<QPair<QString, QString>> SearchCriteriaBoxLayout::getSearchCriteria()
{
    QList<QPair<QString, QString>> criteriaList;

    for (auto widget : criteria) {
        criteriaList.push_back(widget->getCriteria());
    }

    return criteriaList;
}

void SearchCriteriaBoxLayout::addSearchCriteriaWidget(SearchCriteriaWidget *widget)
{
    criteria.push_back(widget);
    addWidget(widget);
}
