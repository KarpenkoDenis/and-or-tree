#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addtreepopup.h"
#include "container/statemanager.h"
#include "widget/nodeeditor.h"
#include "widget/graphwidget.h"
#include "widget/nodetreegraph.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    StateManager *stateManager = nullptr;

private:
    Ui::MainWindow *ui = nullptr;
    AddTreePopup *addTreePopup = nullptr;

    NodeEditor *nodeEditor = nullptr;

    GraphWidget *graphWidget = nullptr;
    NodeTreeGraph *nodeTreeGraph = nullptr;

    void defineConnects();
    void initializeUi();

public slots:
    void showAddTreePopup();
    void addListLine(Tree tree);
    void openEditor(Tree *tree);
    void addSearchCriteria();
    void searchForCriteria();
};

#endif // MAINWINDOW_H
