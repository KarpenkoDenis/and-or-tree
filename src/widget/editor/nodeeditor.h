#ifndef NODEEDITOR_H
#define NODEEDITOR_H

#include <QWidget>
#include "container/domain/node.h"
#include "container/domain/tree.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>

//template <class T>
//class Node<T>;

using namespace TreeContainer;

class NodeEditor : public QWidget
{
    Q_OBJECT

public:
    explicit NodeEditor(QWidget *parent = nullptr);
    ~NodeEditor();

private:
    Node<QString> *currentNode = nullptr;
    Tree<QString>* currentTree = nullptr;
    QLineEdit *nodeNameLineEdit = nullptr;
    QComboBox *nodeTypeComboBox = nullptr;
    QPushButton *addChildNodeButton = nullptr;
    QPushButton *removeNodeButton = nullptr;

    void initializeLayout();
    void defineConnects();

signals:
    void shouldRefreshGraphWidget();

public slots:
    void handleAddChildNodeButtonClick();
    void handleRemoveNodeButtonClick();
    void configure(Tree<QString>*, Node<QString> *node, bool isRoot);
    void handleNodeNameLineEditChange(QString);
    void handleNodeTypeComboBoxChange(int);
};

#endif // NODEEDITOR_H
