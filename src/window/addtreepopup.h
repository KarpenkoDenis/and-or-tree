#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QCloseEvent>
#include <QDebug>


namespace Ui {
class AddTreePopup;
}

class AddTreePopup : public QWidget
{
    Q_OBJECT

public:
    explicit AddTreePopup(QWidget *parent = 0);
    ~AddTreePopup();

private:
    Ui::AddTreePopup *ui;

public slots:
    void makeTree();

signals:
    void createTree(QString name);
};

#endif // FORM_H
