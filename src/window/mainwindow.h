#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addtreepopup.h"
#include "service/statemanager.h"
#include "widget/editor/nodeeditor.h"
#include "widget/graphwidget.h"
#include "widget/search/searchcriteriaboxlayout.h"
#include "widget/search/searchresultboxlayout.h"
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


private:
    Ui::MainWindow *ui = nullptr;
    AddTreePopup *addTreePopup = nullptr;
    StateManager *stateManager = nullptr;
    NodeEditor *nodeEditor = nullptr;
    SearchCriteriaBoxLayout *searchCriteriaBoxLayout = nullptr;
    SearchResultBoxLayout *searchResultBoxLayout = nullptr;
    ListViewBoxLayout *listViewBoxLayout = nullptr;
    GraphWidget *graphWidget = nullptr;

    void initializeWidget();
    void defineConnects();
    void restoreState();

public slots:
    void openEditor(Tree<QString> *tree);
    void handleAddTreeButtonClick();
    void handleAddSearchCriteriaButtonClick();
    void handleSearchButtonClick();
    void handleCloseEditorButtonClick();
    void refreshListView();
};

#endif // MAINWINDOW_H
