#ifndef NODEEDITOR_H
#define NODEEDITOR_H

#include <QWidget>
#include "container/domain/node.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>

class NodeEditor : public QWidget
{
    Q_OBJECT

public:
    explicit NodeEditor(QWidget *parent = nullptr);
    ~NodeEditor();

private:
    Node *currentNode = nullptr;
    QLineEdit *nodeNameLineEdit = nullptr;
    QComboBox *nodeTypeComboBox = nullptr;
    QPushButton *addChildNodeButton = nullptr;

    void initializeLayout();
    void defineConnects();

signals:
    void shouldRefreshGraphWidget();

public slots:
    void handleAddChildNodeButtonClick();
    void configure(Node *node);
    void handleNodeNameLineEditChange(QString);
    void handleNodeTypeComboBoxChange(int);

};

#endif // NODEEDITOR_H
