#ifndef SEARCHCRITERIAWIDGET_H
#define SEARCHCRITERIAWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>

class SearchCriteriaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SearchCriteriaWidget(QMap<QString, QSet<QString>>, QWidget *parent = nullptr);
    ~SearchCriteriaWidget();

    QPair<QString, QString> getCriteria();

private:
    QComboBox *searchCriteriaTypeComboBox = nullptr;
    QComboBox *searchCriteriaValueComboBox = nullptr;
    QPushButton *removeSearchCriteriaButton = nullptr;

    QMap<QString, QSet<QString>> possibleSearchCriteria;

    void initializeWidget(QMap<QString, QSet<QString>> possibleSearchCriteria);
    void configureConnects();
signals:
    void shouldRemoveSearchCriteria(SearchCriteriaWidget*);
public slots:
    void handleSearchCriteriaTypeSelect(QString);
    void handleRemoveSearchCriteriaButtonClick();
};

#endif // SEARCHCRITERIAWIDGET_H
