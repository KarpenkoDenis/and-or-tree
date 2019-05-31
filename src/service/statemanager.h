#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <QObject>
#include <QVector>
#include "container/domain/tree.h"

class StateManager : public QObject
{
    Q_OBJECT

private:
    QVector<Tree*> trees;

public:
    explicit StateManager(QObject *parent = nullptr);
    ~StateManager();

    QVector<Tree*> getTrees();
    void serializeState();
    void deserializeState();


signals:
    void treeCreated();
    void treeRemoved();

public slots:
    void createTree(const QString &name);
    void removeTree(Tree *);
};

#endif // STATEMANAGER_H
