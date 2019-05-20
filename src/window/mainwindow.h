#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addtreepopup.h"
#include "container/statemanager.h"
#include "widget/nodeeditor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui = nullptr;
    AddTreePopup *addTreePopup = nullptr;
    StateManager *stateManager = nullptr;
    NodeEditor *nodeEditor = nullptr;

    void defineConnects();
    void initializeUi();

public slots:
    void showAddTreePopup();
    void addListLine(Tree tree);
    void openEditor(Tree *tree);
    void addSearchCriteria();
};

#endif // MAINWINDOW_H
