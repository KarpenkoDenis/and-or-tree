#include "mainwindow.h"
#include "addtreepopup.h"
#include "ui_mainwindow.h"
#include "widget/listlinewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    addTreePopup(new AddTreePopup),
    stateManager(new StateManager)
{
    ui->setupUi(this);
    defineConnects();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete stateManager;
}

void MainWindow::showAddTreePopup()
{
    addTreePopup->show();
}

void MainWindow::addListLine(Tree tree){
    ui->listVBox->addWidget(new ListLineWidget(tree));
}

void MainWindow::defineConnects(){
    // main window
    QObject::connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(showAddTreePopup()));
    QObject::connect(stateManager, SIGNAL(treeCreated(Tree)), this, SLOT(addListLine(Tree)));

    // add tree popup
    QObject::connect(addTreePopup, SIGNAL(createTree(QString)), stateManager, SLOT(createTree(QString)));
}
