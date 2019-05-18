#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_form.h"
#include "Windows/form.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    form(new Form())
{
    ui->setupUi(this);
//    form = new Ui::Form();
     QObject::connect(ui->addButton,SIGNAL(clicked(bool)),this,SLOT(showForm()));
     QObject::connect(form, SIGNAL(createTree(QString)), &st, SLOT(addTree(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showForm()
{
    form->show();
}
