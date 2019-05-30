#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addtreepopup.h"
#include "service/statemanager.h"
#include "widget/nodeeditor.h"
#include "widget/graphwidget.h"
#include "widget/nodetreegraph.h"
#include "widget/search/searchcriteriaboxlayout.h"
#include "widget/listview/listviewboxlayout.h"
#include "container/domain/tree.h"

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
    SearchCriteriaBoxLayout *searchCriteriaBoxLayout = nullptr;
    ListViewBoxLayout *listViewBoxLayout = nullptr;
    GraphWidget *graphWidget = nullptr;
    NodeTreeGraph *nodeTreeGraph = nullptr;

    void initializeWidget();
    void defineConnects();
    void restoreState();

public slots:
    void openEditor(Tree *tree);
    void handleAddTreeButtonClick();
    void handleAddSearchCriteriaButtonClick();
    void handleSearchButtonClick();
    void handleCloseEditorButtonClick();
    void refreshListView();
};

#endif // MAINWINDOW_H
