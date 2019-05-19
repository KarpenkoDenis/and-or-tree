#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addtreepopup.h"
#include "container/statemanager.h"

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
    Ui::MainWindow *ui;
    AddTreePopup *addTreePopup;
    StateManager *stateManager;

    void defineConnects();

public slots:
    void showAddTreePopup();
    void addListLine(Tree tree);
};

#endif // MAINWINDOW_H
