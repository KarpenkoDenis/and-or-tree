#include "mainwindow.h"
#include "addtreepopup.h"
#include "ui_mainwindow.h"
#include "widget/listlinewidget.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    addTreePopup(new AddTreePopup),
    stateManager(new StateManager)
{
    initializeUi();
    defineConnects();
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
    nodeEditor->configure(&(tree->root));
}

void MainWindow::initializeUi(){
    ui->setupUi(this);

    nodeEditor = new NodeEditor();
    ui->editorLayout->addWidget(nodeEditor);
}

void MainWindow::defineConnects(){
    // main window
    QObject::connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(showAddTreePopup()));
    QObject::connect(stateManager, SIGNAL(treeCreated(Tree)), this, SLOT(addListLine(Tree)));

    // add tree popup
    QObject::connect(addTreePopup, SIGNAL(createTree(QString)), stateManager, SLOT(createTree(QString)));
}
