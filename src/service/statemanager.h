#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <QObject>
#include <QVector>
#include "container/domain/tree.h"

class StateManager : public QObject
{
    Q_OBJECT

private:
    QVector<Tree> trees;

public:
    explicit StateManager(QObject *parent = nullptr);
    ~StateManager();
    QVector<Tree> getTrees() const;
    void restoreTrees();

signals:
    void treeCreated(Tree tree);

public slots:
    void createTree(const QString &name);

};

#endif // STATEMANAGER_H
