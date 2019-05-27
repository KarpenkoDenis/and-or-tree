#ifndef NODEEDITOR_H
#define NODEEDITOR_H

#include <QWidget>
#include "container/node.h"
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
    QPushButton *saveNodeButton = nullptr;

    void initializeLayout();
    void defineConnects();

signals:

public slots:
    void handleAddChildNodeButtonClick();
    void handleSaveNodeButtonClick();
    void configure(Node *node);
};

#endif // NODEEDITOR_H
