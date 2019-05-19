#include "addtreepopup.h"
#include "ui_addtreepopup.h"


AddTreePopup::AddTreePopup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTreePopup)
{
    ui->setupUi(this);
    QObject::connect(ui->addButton,SIGNAL(clicked(bool)),this,SLOT(makeTree()));
}

AddTreePopup::~AddTreePopup()
{
    delete ui;
}

void AddTreePopup::makeTree()
{
    QString treeName = ui->treeNameLineEdit->text();

    if (treeName.length() > 0){
        emit createTree(treeName);
        close();
    }
}

