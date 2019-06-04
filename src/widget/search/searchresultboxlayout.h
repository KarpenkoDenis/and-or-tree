#ifndef SEARCHRESULTBOXLAYOUT_H
#define SEARCHRESULTBOXLAYOUT_H

#include <QVBoxLayout>
#include "container/domain/tree.h"

using namespace TreeContainer;

class SearchResultBoxLayout : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit SearchResultBoxLayout();
    ~SearchResultBoxLayout();

    void configure(QVector<Tree<QString>*>);
private:
    void clearLayout(QLayout *);
signals:

public slots:
};

#endif // SEARCHRESULTBOXLAYOUT_H
