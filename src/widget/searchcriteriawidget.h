#ifndef SEARCHCRITERIAWIDGET_H
#define SEARCHCRITERIAWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include "window/mainwindow.h"

class SearchCriteriaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SearchCriteriaWidget(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~SearchCriteriaWidget();

private:
    QComboBox *searchCriteriaTypeComboBox = nullptr;
    QComboBox *searchCriteriaValueComboBox = nullptr;
    QPushButton *removeSearchCriteriaButton = nullptr;
    MainWindow *mainWindow = nullptr;

    QMap<QString, QVector<QString>> properties;

signals:

public slots:
};

#endif // SEARCHCRITERIAWIDGET_H
