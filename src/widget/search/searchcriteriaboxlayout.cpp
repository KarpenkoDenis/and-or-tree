#include "searchcriteriaboxlayout.h"

SearchCriteriaBoxLayout::SearchCriteriaBoxLayout() : QVBoxLayout ()
{

}

QMap<QString, QString> SearchCriteriaBoxLayout::getSearchCriteria()
{
    QMap<QString, QString> criteriaMap;

    for (auto widget : criteria) {
        QPair<QString, QString> pair = widget->getCriteria();
        criteriaMap[pair.first] = pair.second;
    }

    return criteriaMap;
}

void SearchCriteriaBoxLayout::addSearchCriteriaWidget(SearchCriteriaWidget *widget)
{
    criteria.push_back(widget);
    addWidget(widget);
}