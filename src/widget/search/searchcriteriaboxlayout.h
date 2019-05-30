#ifndef SEARCHCRITERIABOXLAYOUT_H
#define SEARCHCRITERIABOXLAYOUT_H

#include <QWidget>
#include <QVBoxLayout>
#include "searchcriteriawidget.h"

class SearchCriteriaBoxLayout : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit SearchCriteriaBoxLayout();
    ~SearchCriteriaBoxLayout();

    QMap<QString, QString> getSearchCriteria();
    void addSearchCriteriaWidget(SearchCriteriaWidget*);

private:
    QList<SearchCriteriaWidget*> criteria;
};

#endif // SEARCHCRITERIABOXLAYOUT_H
