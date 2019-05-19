#include "mainwindow.h"
#include "addtreepopup.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    addTreePopup(new AddTreePopup())
{
    ui->setupUi(this);
//    form = new Ui::Form();
     QObject::connect(ui->addButton,SIGNAL(clicked(bool)),this,SLOT(showForm()));
     QObject::connect(addTreePopup, SIGNAL(createTree(QString)), &st, SLOT(addTree(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showForm()
{
    addTreePopup->show();
}
