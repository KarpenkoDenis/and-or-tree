#ifndef SEARCHCRITERIAWIDGET_H
#define SEARCHCRITERIAWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>

class SearchCriteriaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SearchCriteriaWidget(QMap<QString, QList<QString>>, QWidget *parent = nullptr);
    ~SearchCriteriaWidget();

    QPair<QString, QString> getCriteria();

private:
    QComboBox *searchCriteriaTypeComboBox = nullptr;
    QComboBox *searchCriteriaValueComboBox = nullptr;
    QPushButton *removeSearchCriteriaButton = nullptr;

    QMap<QString, QList<QString>> possibleSearchCriteria;

    void initializeWidget(QMap<QString, QList<QString>> possibleSearchCriteria);
    void configureConnects();

public slots:
    void handleSearchCriteriaTypeSelect(QString);
};

#endif // SEARCHCRITERIAWIDGET_H
