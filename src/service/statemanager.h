#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <QObject>
#include <QVector>
#include "container/domain/tree.h"

#include "container/allocator.h"

//template<typename Alloc = Allocator<Tree<QString>>>
class StateManager : public QObject
{
    Q_OBJECT

private:
    QVector<Tree<QString>*> trees;
    Allocator<Tree<QString>> alloc;

public:
    explicit StateManager(QObject *parent = nullptr);
    ~StateManager();

    QVector<Tree<QString>*> getTrees();
    void serializeState();
    void deserializeState();

signals:
    void treeCreated();
    void treeRemoved();

public slots:
    void createTree(const QString &name);
    void removeTree(Tree<QString> *);
};

#endif // STATEMANAGER_H
