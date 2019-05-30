#include "mainwindow.h"
#include "addtreepopup.h"
#include "ui_mainwindow.h"
#include "widget/listlinewidget.h"
#include "widget/search/searchcriteriawidget.h"
#include "service/search.h"
#include <QLayoutItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    addTreePopup(new AddTreePopup),
    stateManager(new StateManager)
{
    initializeWidget();
    defineConnects();
    restoreState();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addTreePopup;
    delete nodeEditor;
    delete stateManager;
    delete searchCriteriaBoxLayout;
}

void MainWindow::handleAddTreeButtonClick()
{
    addTreePopup->show();
}

void MainWindow::addListLine(Tree tree){
    ui->listVBox->addWidget(new ListLineWidget(tree, this));
}

void MainWindow::openEditor(Tree *tree)
{
    ui->stackedWidget->setCurrentIndex(1);
    graphWidget->configure(tree);
}

void MainWindow::handleAddSearchCriteriaButtonClick()
{
    QVector<Tree> trees = stateManager->getTrees();
    QMap<QString, QList<QString>> possibleSearchCriteria = findProperties(trees);
    searchCriteriaBoxLayout->addSearchCriteriaWidget(new SearchCriteriaWidget(possibleSearchCriteria));
}

void MainWindow::handleSearchButtonClick()
{
    QMap<QString, QString> searchCriteria = searchCriteriaBoxLayout->getSearchCriteria();
    QVector<int> result = findTrees(stateManager->getTrees(), searchCriteria);
    qDebug() << "result";
    for(auto num: result)
    {
        qDebug() << "num" << num;
    }
    // tree list
    // populate trees to table
}

void MainWindow::handleCloseEditorButtonClick()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::initializeWidget(){
    ui->setupUi(this);

    nodeEditor = new NodeEditor();
    nodeTreeGraph = new NodeTreeGraph();
    graphWidget = new GraphWidget();
    searchCriteriaBoxLayout = new SearchCriteriaBoxLayout();

    ui->editorLayout->addWidget(nodeEditor);
    ui->graphicsView->setScene(graphWidget->scene());
    ui->searchCriteriaBoxLayoutWrapper->addLayout(searchCriteriaBoxLayout);
    ui->searchCriteriaBoxLayoutWrapper->addStretch(1);
}

void MainWindow::defineConnects(){
    QObject::connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(handleAddTreeButtonClick()));
    QObject::connect(ui->addSearchCriteriaButton, SIGNAL(clicked(bool)), this, SLOT(handleAddSearchCriteriaButtonClick()));
    QObject::connect(ui->searchButton, SIGNAL(clicked(bool)), this, SLOT(handleSearchButtonClick()));
    QObject::connect(ui->closeEditorButton, SIGNAL(clicked(bool)), this, SLOT(handleCloseEditorButtonClick()));

    QObject::connect(addTreePopup, SIGNAL(createTree(QString)), stateManager, SLOT(createTree(QString)));
    QObject::connect(stateManager, SIGNAL(treeCreated(Tree)), this, SLOT(addListLine(Tree)));
    QObject::connect(graphWidget, SIGNAL(nodeClicked(Node*)), nodeEditor, SLOT(configure(Node*)));
}

void MainWindow::restoreState()
{
//    stateManager->deserializeState();
}
