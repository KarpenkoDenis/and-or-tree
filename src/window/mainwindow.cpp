#include "mainwindow.h"
#include "addtreepopup.h"
#include "ui_mainwindow.h"
#include "widget/listlinewidget.h"
#include <QDebug>
#include "widget/searchcriteriawidget.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    addTreePopup(new AddTreePopup),
    stateManager(new StateManager)
{
    initializeUi();
    defineConnects();
    // We can restore the trees only after the signals/slots are initialized
    stateManager->restoreTrees();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addTreePopup;
    delete nodeEditor;
    delete stateManager;
}

void MainWindow::showAddTreePopup()
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

void MainWindow::addSearchCriteria()
{
    ui->searchCriteriaVBox->addWidget(new SearchCriteriaWidget(this));
}

void MainWindow::searchForCriteria()
{
    ui->listVBox->children();
    //loop and get selected criteria from each via getCriteria
}


void MainWindow::initializeUi(){
    ui->setupUi(this);

    nodeEditor = new NodeEditor();
    ui->editorLayout->addWidget(nodeEditor);

    nodeTreeGraph = new NodeTreeGraph();
    graphWidget = new GraphWidget();

    ui->graphicsView->setScene(graphWidget->scene());
}

void MainWindow::defineConnects(){
    // main window
    QObject::connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(showAddTreePopup()));
    QObject::connect(stateManager, SIGNAL(treeCreated(Tree)), this, SLOT(addListLine(Tree)));
    QObject::connect(ui->addSearchCriteriaButton, SIGNAL(clicked(bool)), this, SLOT(addSearchCriteria()));

    QObject::connect(ui->searchButton, SIGNAL(clicked(bool)), this, SLOT(searchForCriteria()));

    // add tree popup
    QObject::connect(addTreePopup, SIGNAL(createTree(QString)), stateManager, SLOT(createTree(QString)));
    QObject::connect(graphWidget, SIGNAL(nodeClicked(Node*)), nodeEditor, SLOT(configure(Node*)));
}
