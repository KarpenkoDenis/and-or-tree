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
    void serializeState();
    void deserializeState();

signals:
    void treeCreated();

public slots:
    void createTree(const QString &name);

};

#endif // STATEMANAGER_H
