#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addtreepopup.h"
#include "container/statemanager.h"
#include "widget/nodeeditor.h"
#include "widget/nodetreegraph.h"
#include "widget/graphwidget.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    NodeTreeGraph *nodeTreeGraph = nullptr;

private:
    Ui::MainWindow *ui = nullptr;
    AddTreePopup *addTreePopup = nullptr;
    StateManager *stateManager = nullptr;
    NodeEditor *nodeEditor = nullptr;
    GraphWidget *graphWidget = nullptr;
    void defineConnects();
    void initializeUi();

public slots:
    void showAddTreePopup();
    void addListLine(Tree tree);
    void openEditor(Tree *tree);
    void addSearchCriteria();
};

#endif // MAINWINDOW_H
