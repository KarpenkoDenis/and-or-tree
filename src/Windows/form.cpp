#include "form.h"
#include "ui_form.h"


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QObject::connect(ui->addButton,SIGNAL(clicked(bool)),this,SLOT(makeTree()));
}

Form::~Form()
{
    delete ui;
}

void Form::makeTree()
{
    emit createTree( ui->textName->text());
}

