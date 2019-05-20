#ifndef SEARCHCRITERIAWIDGET_H
#define SEARCHCRITERIAWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>

class SearchCriteriaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SearchCriteriaWidget(QWidget *parent = nullptr);
    ~SearchCriteriaWidget();

private:
    QComboBox *searchCriteriaTypeComboBox = nullptr;
    QComboBox *searchCriteriaValueComboBox = nullptr;
    QPushButton *removeSearchCriteriaButton = nullptr;

signals:

public slots:
};

#endif // SEARCHCRITERIAWIDGET_H
