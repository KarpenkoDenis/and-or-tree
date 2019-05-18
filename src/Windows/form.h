#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QCloseEvent>
#include <QDebug>


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();


private:
    Ui::Form *ui;

public slots:
    void makeTree();

signals:
    void createTree(QString name);

};

#endif // FORM_H
