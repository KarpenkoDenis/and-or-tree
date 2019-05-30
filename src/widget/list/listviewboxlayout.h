#ifndef LISTVIEWBOXLAYOUT_H
#define LISTVIEWBOXLAYOUT_H
#include "container/domain/tree.h"
#include <QVBoxLayout>

class ListViewBoxLayout : public QVBoxLayout
{
public:
    ListViewBoxLayout();
    void configure(QVector<Tree*>);
};

#endif // LISTVIEWBOXLAYOUT_H
