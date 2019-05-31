#ifndef SEARCHRESULTBOXLAYOUT_H
#define SEARCHRESULTBOXLAYOUT_H

#include <QVBoxLayout>
#include "container/domain/tree.h"

class SearchResultBoxLayout : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit SearchResultBoxLayout();
    ~SearchResultBoxLayout();

    void configure(QVector<Tree*>);
private:
    void clearLayout(QLayout *);
signals:

public slots:
};

#endif // SEARCHRESULTBOXLAYOUT_H